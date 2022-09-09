#include <vector>
#include <iostream>

#include "../Utils/AdminStructure.h"
#include "../Utils/Functions.h"
#include <string>
#include "Cat.h"



Cat::Cat(std::vector<std::string> fileN) {
    this->fileN=fileN;
    executeCat();

}


void Cat::executeCat() {
    if (fileN.size() == 0)
        return coutError("Error: debe indicarse por lo menos un archivo para mostrar.", NULL);
    if (!_user_logged.logged_in)
        return coutError("Error: No se encuentra ninguna sesión activa.", NULL);

    FILE *file = fopen((_user_logged.mounted.path).c_str(), "rb");
    int start_byte_sb = startByteSuperBloque(_user_logged.mounted);
    /* Lectura del superbloque */
    Superbloque super_bloque;
    fseek(file, start_byte_sb, SEEK_SET);
    fread(&super_bloque, sizeof(Superbloque), 1, file);
    fclose(file);
    file = NULL;
    std::string content = "";
    for (int i = 0; i < fileN.size(); i++) {
        FILE *file = fopen((_user_logged.mounted.path).c_str(), "rb");
        std::string npath = fileN[i].substr(0, fileN[i].find_last_of('/'));
        std::string name = fileN[i].substr(fileN[i].find_last_of('/') + 1);
        /* Lectura del superbloque */
        Superbloque super_bloque;
        int start_byte_sb = startByteSuperBloque(_user_logged.mounted);
        fseek(file, start_byte_sb, SEEK_SET);
        fread(&super_bloque, sizeof(Superbloque), 1, file);

        /* Lectura de la última carpeta padre */
        FolderReference fr;
        std::vector <std::string> folders = SplitPath(npath);
        for (int j = 0; j < folders.size(); j++) {
            fr = getFatherReference(fr, folders[j], file, super_bloque.s_inode_start, super_bloque.s_block_start);
            if (fr.inode == -1) {
                // std::cout << "Not found: " + folders[j] + "\n";
                return coutError("Error: la ruta del archivo no se encuentra.", file);
            }
        }
        int _index_inode;
        /* Lectura del inodo de carpeta padre */
        InodosTable inode_father;
        fseek(file, super_bloque.s_inode_start, SEEK_SET);
        fseek(file, fr.inode * sizeof(InodosTable), SEEK_CUR);
        fread(&inode_father, sizeof(InodosTable), 1, file);
        CarpetasBlock file_block;
        InodosTable inode_current;
        bool x = false;
        for (int j = 0; j < 15 && !x; j++) // Obtener el inodo asociado directo
        {
            if (inode_father.i_block[j] != -1) {
                fseek(file, super_bloque.s_block_start, SEEK_SET);
                fseek(file, inode_father.i_block[j] * 64, SEEK_CUR);
                fread(&file_block, 64, 1, file);
                for (int k = 0; k < 4; k++) {
                    if (std::string(file_block.b_content[k].b_name) == name) {
                        // std::cout << file_block.b_content[k].b_inodo << std::endl;
                        _index_inode = file_block.b_content[k].b_inodo;
                        fseek(file, super_bloque.s_inode_start, SEEK_SET);
                        fseek(file, file_block.b_content[k].b_inodo * sizeof(InodosTable), SEEK_CUR);
                        fread(&inode_current, sizeof(InodosTable), 1, file);
                        x = true;
                        break;
                    }
                }
            }
        }
        if (!x)
            return coutError("El archivo '" + name + "' no se encuentra en la ruta: '" + npath + "'.", file);
        if (!HasPermission(_user_logged, inode_current, 4))
            return coutError(
                    "El usuario '" + _user_logged.nombre + "' no posee los permisos de lectura del archivo: '" + name +
                    "'.", file);
        fclose(file);
        file = NULL;

        content += (ReadFile(_index_inode, super_bloque.s_inode_start, super_bloque.s_block_start,
                             _user_logged.mounted.path) + "\n");
    }
    std::cout << content; // Imprime el archivo
}