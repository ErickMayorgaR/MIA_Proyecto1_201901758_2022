//
// Created by erick on 3/09/22.
//

#include <cstring>
#include "../Utils/Functions.h"
#include "Move.h"



Move::Move(std::string path, std::string dest) {
    this->path = path;
    this->dest = dest;
    executeMove();
}


void Move::executeMove() {
    if (path == "" || dest == "")
        return coutError("Error: faltan parámetros obligatorios.", NULL);
    if (!_user_logged.logged_in)
        return coutError("Error: No se encuentra ninguna sesión activa.", NULL);

    std::string npath1 = path.substr(0, path.find_last_of('/'));
    std::string name1 = path.substr(path.find_last_of('/') + 1);

    std::string npath2 = dest.substr(0, dest.find_last_of('/'));
    std::string name2 = dest.substr(dest.find_last_of('/') + 1);

    return moveFile(npath1, name1, npath2, name2);
}


void Move::moveFile(std::string _path_cut, std::string _name_cut, std::string _path_paste, std::string _name_paste) {
    /* MOVER UN ARCHIVO O CARPETA */

    FILE *file = fopen((_user_logged.mounted.path).c_str(), "rb+");
    int start_byte_sb = startByteSuperBloque(_user_logged.mounted);

    /* Lectura del superbloque */
    Superbloque super_bloque;
    fseek(file, start_byte_sb, SEEK_SET);
    fread(&super_bloque, sizeof(Superbloque), 1, file);

    /* Lectura de la última carpeta a cortar */
    FolderReference fr_cut;
    std::vector<std::string> folders_cut = SplitPath(_path_cut);
    for (int i = 0; i < folders_cut.size(); i++) {
        fr_cut = getFatherReference(fr_cut, folders_cut[i], file, super_bloque.s_inode_start,
                                    super_bloque.s_block_start);
        if (fr_cut.inode == -1) {
            // std::cout << "Not found: " + folders_cut[i] + "\n";
            return coutError("Error: la ruta del archivo o carpeta no se encuentra.", file);
        }
    }

    /* Lectura de la última carpeta padre a pegar */
    FolderReference fr_paste;
    std::vector<std::string> folders_paste = SplitPath(_path_paste);
    for (int i = 0; i < folders_paste.size(); i++) {
        fr_paste = getFatherReference(fr_paste, folders_paste[i], file, super_bloque.s_inode_start,
                                      super_bloque.s_block_start);
        if (fr_paste.inode == -1) {
            // std::cout << "Not found: " + folders_paste[i] + "\n";
            return coutError("Error: la ruta del archivo o carpeta no se encuentra.", file);
        }
    }

    /* Lectura del inodo de carpeta padre */
    InodosTable inode_father_cut;
    fseek(file, super_bloque.s_inode_start, SEEK_SET);
    fseek(file, fr_cut.inode * sizeof(InodosTable), SEEK_CUR);
    fread(&inode_father_cut, sizeof(InodosTable), 1, file);
    if (!fileExists(inode_father_cut, _name_cut, file, super_bloque.s_block_start))
        return coutError("El archivo o carpeta '" + _name_cut + "' no se encuentra en la ruta: " + _path_cut + ".",
                         file);

    /* Lectura del inodo de carpeta padre */
    InodosTable inode_father_paste;
    fseek(file, super_bloque.s_inode_start, SEEK_SET);
    fseek(file, fr_paste.inode * sizeof(InodosTable), SEEK_CUR);
    fread(&inode_father_paste, sizeof(InodosTable), 1, file);
    if (!fileExists(inode_father_paste, _name_paste, file, super_bloque.s_block_start) ||
        inode_father_paste.i_type == '1')
        return coutError("La carpeta '" + _name_paste + "' no se encuentra en la ruta: " + _path_paste + ".", file);

    /* Lectura del bloque de carpeta padre a cortar */
    CarpetasBlock file_block_tmp;
    bool x = false;
    FolderReference aux_cut;
    for (int i = 0; i < 15 && !x; i++) // falta indirectos
    {
        if (inode_father_cut.i_block[i] != -1) {
            fseek(file, super_bloque.s_block_start, SEEK_SET);
            fseek(file, inode_father_cut.i_block[i] * 64, SEEK_CUR);
            fread(&file_block_tmp, 64, 1, file);
            for (int j = 0; j < 4; j++) {
                if (std::string(file_block_tmp.b_content[j].b_name) == _name_cut) {
                    aux_cut.block = inode_father_cut.i_block[i];
                    aux_cut.inode = file_block_tmp.b_content[j].b_inodo;
                    strcpy(file_block_tmp.b_content[j].b_name, "");
                    file_block_tmp.b_content[j].b_inodo = -1;

                    fseek(file, super_bloque.s_block_start, SEEK_SET);
                    fseek(file, inode_father_cut.i_block[i] * 64, SEEK_CUR);
                    fwrite(&file_block_tmp, 64, 1, file);
                    x = true;
                    break;
                }
            }
        }
    }
    if (!x)
        return coutError("No se halló el inodo del archivo o carpeta a mover.", file);

    /* Lectura del bloque de carpeta padre a pegar */
    x = false;
    FolderReference aux_paste;
    for (int i = 0; i < 15 && !x; i++) // falta indirectos
    {
        if (inode_father_paste.i_block[i] != -1) {
            fseek(file, super_bloque.s_block_start, SEEK_SET);
            fseek(file, inode_father_paste.i_block[i] * 64, SEEK_CUR);
            fread(&file_block_tmp, 64, 1, file);
            for (int j = 0; j < 4; j++) {
                if (std::string(file_block_tmp.b_content[j].b_name) == _name_paste) {
                    aux_paste.block = inode_father_paste.i_block[i];
                    aux_paste.inode = file_block_tmp.b_content[j].b_inodo;
                    x = true;
                    break;
                }
            }
        }
    }
    if (!x)
        return coutError("No se halló el inodo del archivo o carpeta a colocar.", file);

    InodosTable inode_current_cut; // Leer el inodo de archivo que sólo posee bloques de contenido
    fseek(file, super_bloque.s_inode_start, SEEK_SET);
    fseek(file, aux_cut.inode * sizeof(InodosTable), SEEK_CUR);
    fread(&inode_current_cut, sizeof(InodosTable), 1, file);

    if (!HasPermission(_user_logged, inode_current_cut, 2)) {
        inode_current_cut.i_atime = getCurrentTime();
        fseek(file, super_bloque.s_inode_start, SEEK_SET);
        fseek(file, aux_cut.inode * sizeof(InodosTable), SEEK_CUR);
        fwrite(&inode_current_cut, sizeof(InodosTable), 1, file);
        return coutError("El usuario no posee los permisos de escritura sobre el archivo o carpeta.", file);
    }

    InodosTable inode_current_paste; // Leer el inodo de archivo que sólo posee bloques de contenido
    fseek(file, super_bloque.s_inode_start, SEEK_SET);
    fseek(file, aux_paste.inode * sizeof(InodosTable), SEEK_CUR);
    fread(&inode_current_paste, sizeof(InodosTable), 1, file);

    if (!HasPermission(_user_logged, inode_current_paste, 2)) {
        inode_current_paste.i_atime = getCurrentTime();
        fseek(file, super_bloque.s_inode_start, SEEK_SET);
        fseek(file, aux_paste.inode * sizeof(InodosTable), SEEK_CUR);
        fwrite(&inode_current_paste, sizeof(InodosTable), 1, file);
        return coutError("El usuario no posee los permisos de escritura sobre el archivo o carpeta.", file);
    }

    /* MOVER */
    CarpetasBlock file_block_move;
    fseek(file, super_bloque.s_block_start, SEEK_SET);
    fseek(file, aux_paste.block * 64, SEEK_CUR);
    fread(&file_block_move, 64, 1, file);
    x = false;
    int free_block = super_bloque.s_first_blo;
    for (int i = 0; i < 15 && !x; i++) {
        if (inode_current_paste.i_block[i] != -1) {
            for (int j = 0; j < 4; j++) {
                if (file_block_move.b_content[j].b_inodo == -1) {
                    file_block_move.b_content[j].b_inodo = aux_cut.inode;
                    strcpy(file_block_move.b_content[j].b_name, _name_cut.c_str());
                    x = true;
                    break;
                }
            }
        } else if (inode_current_paste.i_block[i] == -1 && !x) {
            CarpetasBlock new_block;
            new_block.b_content[0].b_inodo = aux_cut.inode;
            strcpy(new_block.b_content[0].b_name, _name_cut.c_str());
            fseek(file, super_bloque.s_block_start, SEEK_SET);
            fseek(file, free_block * 64, SEEK_CUR);
            fwrite(&new_block, 64, 1, file);

            inode_current_paste.i_block[i] = free_block;

            free_block++;
            super_bloque.s_first_blo = free_block;
            super_bloque.s_free_blocks_count--;
            x = true;
            break;
        }
    }
    if (!x)
        return coutError("No se halló el bloque disponible a colocar.", file);

    inode_current_cut.i_mtime = getCurrentTime();
    inode_current_paste.i_mtime = getCurrentTime();

    /* ESCRITURA */
    fseek(file, start_byte_sb, SEEK_SET);
    fwrite(&super_bloque, sizeof(Superbloque), 1, file);

    fseek(file, super_bloque.s_inode_start, SEEK_SET); // Mover el puntero al inicio de la tabla de inodos
    fseek(file, aux_cut.inode * sizeof(InodosTable), SEEK_CUR);
    fwrite(&inode_current_cut, sizeof(InodosTable), 1, file);

    fseek(file, super_bloque.s_inode_start, SEEK_SET); // Mover el puntero al inicio de la tabla de inodos
    fseek(file, aux_paste.inode * sizeof(InodosTable), SEEK_CUR);
    fwrite(&inode_current_paste, sizeof(InodosTable), 1, file);

    fclose(file);
    file = NULL;

    // std::cout << "Se movió el archivo: " + _path + "/" + _name + "\n";
}



