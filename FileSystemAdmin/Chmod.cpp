#include "Chmod.h"

#include <iostream>
#include <string.h>
#include "../Utils/Functions.h"
#include "../Utils/Variables.h"



Chmod::Chmod(std::string path, std::string ugo, std::string r) {
    this->path = path;
    this->ugo = ugo;
    this->r = r;
    executeChmod();

}


void Chmod::executeChmod() {
    if (path == "" || ugo == "")
        return coutError("Error: faltan parámetros obligatorios.", NULL);

    if (!_user_logged.logged_in)
        return coutError("Error: No se encuentra ninguna sesión activa.", NULL);

    if (ugo.length() != 3)
        return coutError("Error: parámetro 'ugo' no válido, deben ser tres números enteros.", NULL);

    for (int i = 0; i < 3; i++) {
        int bit = std::stoi(ugo.substr(i, 1));
        if (bit < 0 || bit > 7)
            return coutError("El bit de permiso debe ser un número entre 0 y 7.", NULL);
    }
    path = path.substr(0, path.find_last_of('/'));
    std::string name = path.substr(path.find_last_of('/') + 1);
    _ugo = std::stoi(ugo);
    bool _r = r != "";
    return changePermissions(name);
}

void Chmod::changePermissions(std::string _name) {
    FILE *file = fopen((_user_logged.mounted.path).c_str(), "rb");

    /* Lectura del superbloque */
    Superbloque super_bloque;
    int start_byte_sb = startByteSuperBloque(_user_logged.mounted);
    fseek(file, start_byte_sb, SEEK_SET);
    fread(&super_bloque, sizeof(Superbloque), 1, file);

    /* Lectura de la última carpeta padre */
    FolderReference fr;
    std::vector<std::string> folders = SplitPath(path);
    for (int i = 0; i < folders.size(); i++) {

        fr = getFatherReference(fr, folders[i], file, super_bloque.s_inode_start, super_bloque.s_block_start);
        if (fr.inode == -1) {
            return coutError("Error: la ruta del archivo o carpeta no existe.", file);
        }
    }
    /* Lectura del inodo de carpeta padre */
    InodosTable inode_father;
    fseek(file, super_bloque.s_inode_start, SEEK_SET);
    fseek(file, fr.inode * sizeof(InodosTable), SEEK_CUR);
    fread(&inode_father, sizeof(InodosTable), 1, file);
    CarpetasBlock file_block;
    InodosTable inode_current_tmp;
    bool x = false;
    // Obtener el inodo asociado directo
    for (int i = 0; i < 15 && !x; i++) {
        if (inode_father.i_block[i] != -1) {
            fseek(file, super_bloque.s_block_start, SEEK_SET);
            fseek(file, inode_father.i_block[i] * 64, SEEK_CUR);
            fread(&file_block, 64, 1, file);
            for (int j = 0; j < 4; j++) {
                if (std::string(file_block.b_content[j].b_name) == _name) {
                    fr.inode = file_block.b_content[j].b_inodo;
                    x = true;
                    fseek(file, super_bloque.s_inode_start, SEEK_SET);
                    fseek(file, file_block.b_content[j].b_inodo * sizeof(InodosTable), SEEK_CUR);
                    fread(&inode_current_tmp, sizeof(InodosTable), 1, file);
                    break;
                }
            }
        }
    }
    if (!x)
        return coutError(((_name.find('.') != std::string::npos) ? ("El archivo '") : ("La carpeta '")) + _name +
                         "' no se encuentra en la ruta: '/" + path + "'.", file);
    if (_user_logged.UID != inode_current_tmp.i_uid)
        return coutError("El usuario no es propietario del archivo o carpeta.", file);
    fclose(file);
    file = NULL;
    if (_r) {
        int err = updatePermissions(fr.inode, super_bloque.s_inode_start, super_bloque.s_block_start, 0);
        if (err > 0)
            std::cout << "\033[1;33mNo se pudieron actualizar los permisos de " + std::to_string(err) +
                         " subcarpetas y archivos.\033[0m\n";
        return;
    }
    rewriteInode(fr.inode, super_bloque.s_inode_start, -1);
}


int Chmod::updatePermissions(int _index_inode, int _start_inodes, int _start_blocks, int _aux) {
    if (rewriteInode(_index_inode, _start_inodes, _aux) > 0)
        _aux++;
    FILE *_file = fopen((_user_logged.mounted.path).c_str(), "rb");
    InodosTable inode_current;
    fseek(_file, _start_inodes, SEEK_SET);
    fseek(_file, _index_inode * sizeof(InodosTable), SEEK_CUR);
    fread(&inode_current, sizeof(InodosTable), 1, _file);
    if (inode_current.i_type == '0') { // Actualizar lo que está dentro de la carpeta
        CarpetasBlock file_block;
        for (int i = 0; i < 15; i++) // falta indirectos
        {
            if (inode_current.i_block[i] !=
                -1) { /* Leer el bloque y redireccionar al inodo y ver si de nuevo es otra carpeta */
                fseek(_file, _start_blocks, SEEK_SET);
                fseek(_file, inode_current.i_block[i] * 64, SEEK_CUR);
                fread(&file_block, 64, 1, _file);
                for (int j = 0; j < 4; j++) {
                    if (file_block.b_content[j].b_inodo != -1 && file_block.b_content[j].b_inodo != _index_inode &&
                        std::string(file_block.b_content[j].b_name) != ".." &&
                        std::string(file_block.b_content[j].b_name) != ".") {
                        // std::cout << file_block.b_content[j].b_name << std::endl;
                        _index_inode = file_block.b_content[j].b_inodo;
                        fclose(_file);
                        _aux = updatePermissions(_index_inode, _start_inodes, _start_blocks, _aux);
                    }
                }
            }
        }
    } else if (inode_current.i_type == '1') {
        fclose(_file);
        rewriteInode(_index_inode, _start_inodes, _aux);
    }
    return _aux;
}

int Chmod::rewriteInode(int _index_inode, int _start_inodes, int _aux) {
    FILE *_file = fopen((_user_logged.mounted.path).c_str(), "rb+");
    /* Lectura del inodo a cambiar permisos */
    InodosTable inode_current;
    fseek(_file, _start_inodes, SEEK_SET);
    fseek(_file, _index_inode * sizeof(InodosTable), SEEK_CUR);
    fread(&inode_current, sizeof(InodosTable), 1, _file);
    if (_user_logged.UID != inode_current.i_uid) {
        inode_current.i_atime = getCurrentTime();
        _aux++;
    } else {
        inode_current.i_perm = _ugo;
        inode_current.i_mtime = getCurrentTime();
    }
    fseek(_file, _start_inodes, SEEK_SET);
    fseek(_file, _index_inode * sizeof(InodosTable), SEEK_CUR);
    fwrite(&inode_current, sizeof(InodosTable), 1, _file);
    fclose(_file);
    _file = NULL;
    return _aux;
}



