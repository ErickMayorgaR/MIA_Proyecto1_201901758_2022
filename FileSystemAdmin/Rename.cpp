//
// Created by erick on 3/09/22.
//

#include <cstring>
#include "../Utils/Structures.h"
#include "../Utils/Functions.h"
#include "Rename.h"
#include "../Utils/Variables.h"


Rename::Rename(std::string path, std::string name) {
    this->path = path;
    this->name = name;
    executeRename();

}


void Rename::executeRename() {
    if (path == "" || name == "")
        return coutError("Error: faltan parámetros obligatorios.", NULL);
    if (!_user_logged.logged_in)
        return coutError("Error: No se encuentra ninguna sesión activa.", NULL);

    std::string npath = path.substr(0, path.find_last_of('/'));
    std::string filename = path.substr(path.find_last_of('/') + 1);
    if (filename.length() > 12)
        return coutError("La longitud del nombre del archivo no debe exceder los 12 caracteres.", NULL);
    return renameFile(npath, filename);
}


void Rename::renameFile(std::string _path, std::string _name_to_edit) {
    /* RENOMBRAMIENTO DE UN ARCHIVO O CARPETA */
    FILE *file = fopen((_user_logged.mounted.path).c_str(), "rb+");
    int start_byte_sb = startByteSuperBloque(_user_logged.mounted);

    /* Lectura del superbloque */
    Superbloque super_bloque;
    fseek(file, start_byte_sb, SEEK_SET);
    fread(&super_bloque, sizeof(Superbloque), 1, file);

    /* Lectura de la última carpeta padre */
    FolderReference fr;
    std::vector <std::string> folders = SplitPath(_path);
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
    if (!fileExists(inode_father, _name_to_edit, file, super_bloque.s_block_start))
        return coutError("El archivo o carpeta '" + _name_to_edit + "' no se encuentra en la ruta: '" + _path + "'.",
                         file);

    /* Lectura del bloque de carpeta padre */
    CarpetasBlock file_block_tmp;
    bool x = false;
    FolderReference aux;
    // falta indirectos
    for (int i = 0; i < 15 && !x; i++)
    {
        if (inode_father.i_block[i] != -1) {
            fseek(file, super_bloque.s_block_start, SEEK_SET);
            fseek(file, inode_father.i_block[i] * 64, SEEK_CUR);
            fread(&file_block_tmp, 64, 1, file);
            for (int j = 0; j < 4; j++) {
                if (std::string(file_block_tmp.b_content[j].b_name) == _name_to_edit) {
                    aux.block = inode_father.i_block[i];
                    aux.inode = file_block_tmp.b_content[j].b_inodo;
                    strcpy(file_block_tmp.b_content[j].b_name, name.c_str());
                    x = true;
                    break;
                }
            }
        }
    }
    if (!x)
        return coutError("No se halló el inodo del archivo o carpeta a renombrar.", file);

    InodosTable inode_current; // Leer el inodo de archivo que sólo posee bloques de contenido
    fseek(file, super_bloque.s_inode_start, SEEK_SET);
    fseek(file, aux.inode * sizeof(InodosTable), SEEK_CUR);
    fread(&inode_current, sizeof(InodosTable), 1, file);

    if (!HasPermission(_user_logged, inode_current, 2)) {
        inode_current.i_atime = getCurrentTime();
        fseek(file, super_bloque.s_inode_start, SEEK_SET);
        fseek(file, aux.inode * sizeof(InodosTable), SEEK_CUR);
        fwrite(&inode_current, sizeof(InodosTable), 1, file);
        return coutError("El usuario no posee los permisos de escritura sobre el archivo o carpeta.", file);
    }

    inode_current.i_mtime = getCurrentTime();

    /* ESCRITURA */
    fseek(file, super_bloque.s_inode_start, SEEK_SET); // Mover el puntero al inicio de la tabla de inodos
    fseek(file, aux.inode * sizeof(InodosTable), SEEK_CUR);
    fwrite(&inode_current, sizeof(InodosTable), 1, file);

    fseek(file, super_bloque.s_block_start, SEEK_SET); // Mover el puntero al inicio de la tabla de inodos
    fseek(file, aux.block * 64, SEEK_CUR);
    fwrite(&file_block_tmp, 64, 1, file);

    fclose(file);
    file = NULL;
    // std::cout << "Se renombró el archivo: " + _path + "/" + _name_to_edit + "\n";
}




