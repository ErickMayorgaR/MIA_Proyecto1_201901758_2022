
#include "../Utils/Functions.h"
#include "Find.h"
#include "../Utils/Variables.h"



Find::Find(std::string path, std::string name) {
    this->name = name;
    this->path = path;
    executeFind();

}


void Find::executeFind() {
    if (path == "" || name == "")
        return coutError("Error: faltan parámetros obligatorios.", NULL);
    if (!_user_logged.logged_in)
        return coutError("Error: No se encuentra ninguna sesión activa.", NULL);

    std::string npath = path.substr(0, path.find_last_of('/'));
    char pattern;
    if (name[0] == '*')
        pattern = '*';
    else if (name[0] == '?')
        pattern = '?';
    else
        pattern = '0';

    std::string filename = path.substr(path.find_last_of('/') + 1);

    return findFile(npath, filename, pattern);
}


void Find::findFile(std::string _path, std::string _foldername, char _pattern) {
    /* FIND */
    FILE *file = fopen((_user_logged.mounted.path).c_str(), "rb");
    int start_byte_sb = startByteSuperBloque(_user_logged.mounted);

    /* Lectura del superbloque */
    Superbloque super_bloque;
    fseek(file, start_byte_sb, SEEK_SET);
    fread(&super_bloque, sizeof(Superbloque), 1, file);

    /* Lectura de la última carpeta padre */
    FolderReference fr;
    std::vector<std::string> folders = SplitPath(_path);
    for (int i = 0; i < folders.size(); i++) {
        fr = getFatherReference(fr, folders[i], file, super_bloque.s_inode_start, super_bloque.s_block_start);
        if (fr.inode == -1) {
            // std::cout << "Not found: " + folders[i] + "\n";
            return coutError("Error: la ruta del archivo o carpeta no se encuentra.", file);
        }
    }

    /* Lectura del inodo de carpeta padre */
    InodosTable inode_father;
    fseek(file, super_bloque.s_inode_start, SEEK_SET);
    fseek(file, fr.inode * sizeof(InodosTable), SEEK_CUR);
    fread(&inode_father, sizeof(InodosTable), 1, file);
    if (_foldername != "" && !fileExists(inode_father, _foldername, file, super_bloque.s_block_start))
        return coutError("El archivo o carpeta '" + _foldername + "' no se encuentra en la ruta: " + _path + ".", file);

    /* Lectura del bloque de carpeta padre */
    CarpetasBlock file_block_tmp;
    bool x = false;
    FolderReference aux;
    if (_foldername == "" || _foldername == "/")
        x = true;
    for (int i = 0; i < 15 && !x; i++) // falta indirectos
    {
        if (inode_father.i_block[i] != -1) {
            fseek(file, super_bloque.s_block_start, SEEK_SET);
            fseek(file, inode_father.i_block[i] * 64, SEEK_CUR);
            fread(&file_block_tmp, 64, 1, file);
            for (int j = 0; j < 4; j++) {
                if (std::string(file_block_tmp.b_content[j].b_name) == _foldername) {
                    aux.block = inode_father.i_block[i];
                    aux.inode = file_block_tmp.b_content[j].b_inodo;
                    x = true;
                    break;
                }
            }
        }
    }
    if (!x)
        return coutError("No se halló el inodo de la carpeta a buscar.", file);

    InodosTable inode_current; // Leer el inodo de archivo que sólo posee bloques de contenido
    fseek(file, super_bloque.s_inode_start, SEEK_SET);
    fseek(file, aux.inode * sizeof(InodosTable), SEEK_CUR);
    fread(&inode_current, sizeof(InodosTable), 1, file);

    if (inode_current.i_type != '0')
        return coutError("No se halló el inodo de la carpeta a buscar.", file);

    inode_current.i_atime = getCurrentTime();
    std::string ext_pattern = name;
    if (name.find('.') != std::string::npos)
        ext_pattern = name.substr(name.find_last_of('.') + 1);
    for (int i = 0; i < 15; i++) {
        if (inode_current.i_block[i] != -1) {
            fseek(file, super_bloque.s_block_start, SEEK_SET);
            fseek(file, inode_current.i_block[i] * 64, SEEK_CUR);
            fread(&file_block_tmp, 64, 1, file);
            for (int j = 0; j < 4; j++) {
                if (file_block_tmp.b_content[j].b_inodo != -1 && std::string(file_block_tmp.b_content[j].b_name) != "." &&
                    std::string(file_block_tmp.b_content[j].b_name) != "..") {
                    // std::cout << file_block_tmp.b_content[j].b_name << std::endl;
                    std::string tmp = std::string(file_block_tmp.b_content[j].b_name);
                    std::string tipo;
                    if (tmp.find('.') != std::string::npos) {
                        tipo = "Archivo";
                        // std::cout << ext_pattern << std::endl;
                        // std::cout << tmp << std::endl;
                        // std::cout << tmp.find_last_of('.') << std::endl;
                        std::string ext_tmp = tmp.substr(tmp.find_last_of('.') + 1);
                        if (ext_tmp == ext_pattern || ext_pattern == "*") {
                            if (_pattern == '*') {
                                std::cout << (tmp + "|" + std::to_string(aux.inode) + "|" + tipo) << std::endl;
                                continue;
                            } else if (_pattern == '?' && tmp.find_last_of('.') == 1) {
                                std::cout << (tmp + "|" + std::to_string(aux.inode) + "|" + tipo) << std::endl;
                                continue;
                            }
                        }
                    } else {
                        tipo = "Folder";
                    }
                    if (tmp == name || name == "*") {
                        std::cout << (tmp + "|" + std::to_string(aux.inode) + "|" + tipo) << std::endl;
                    }
                }
            }
        }
    }

    fclose(file);
    file = NULL;
}





