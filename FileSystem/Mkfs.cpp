#include "Mkfs.h"

#include <iostream>
#include <string.h>
#include "../Utils/Functions.h"
#include "../Disks/DiskFunctions.h"
#include "../Utils/Variables.h"




Mkfs::Mkfs(std::string id, std::string type, std::string fs) {
    this->id = id;
    this->_type = type;
    this->_fs= fs;
    executeMkfs();
}


void Mkfs::executeMkfs() {
    if (id == "") {
        coutError("Error: faltan parámetros obligatorios.", NULL);
    }
    DiskId disk_id = buildID(id);
    int index = existMountedID(disk_id);
    if (index == -1) {
        return coutError("No se encuentra ninguna partición montada con el id '" + id + "'.", NULL);
    }
    ParticionesMontadas mounted = particiones_montadas[index];
    type = charFormat(_type);
    fs = _2_or_3fs(_fs);
    crearSistemaArchivos(mounted);
}



void Mkfs::crearSistemaArchivos(ParticionesMontadas _mounted){
    int part_size;
    int part_start;
    switch (_mounted.type) {
        case 'P':
            part_size = _mounted.particion.part_size;
            part_start = _mounted.particion.part_start;
            break;
        case 'L':
            part_size = _mounted.logica.part_size;
            part_start = _mounted.logica.part_start + sizeof(EBR);
            break;
        default:
            coutError("Solamente se puede montar un sistema de archivos en una partición primaria o lógica.",
                             NULL);
            return;
    }
    int bm_start_inodes;
    switch (fs) {
        case 2:
            bm_start_inodes = part_start + sizeof(Superbloque);
            break;
        case 3:
            bm_start_inodes = part_start + sizeof(Superbloque) + 100 * 64;
            break;
        default:
            coutError("Error: parámetro -fs no válido: " + std::to_string(fs), NULL);
            return;
    }

    /* CREACIÓN DEL SUPERBLOQUE */
    Superbloque super_bloque;
    InodosTable inodo;
    int n = number_inodos(part_size, fs);
    std::string bm_content;

    super_bloque.s_filesystem_type = fs;
    super_bloque.s_inodes_count = n;
    super_bloque.s_blocks_count = 3 * n;
    super_bloque.s_free_inodes_count = super_bloque.s_inodes_count - 2;
    super_bloque.s_free_blocks_count = super_bloque.s_blocks_count - 2;
    super_bloque.s_mtime = getCurrentTime();
    super_bloque.s_mnt_count = 1;
    super_bloque.s_magic = 61267;
    super_bloque.s_inode_size = sizeof(InodosTable);
    super_bloque.s_block_size = 64;
    super_bloque.s_first_ino = 2;
    super_bloque.s_first_blo = 2;
    super_bloque.s_bm_inode_start = bm_start_inodes;
    super_bloque.s_bm_block_start = super_bloque.s_bm_inode_start + n;
    super_bloque.s_inode_start = super_bloque.s_bm_block_start + 3 * n;
    super_bloque.s_block_start = super_bloque.s_inode_start + n * sizeof(InodosTable);

    /* CREACIÓN DEL BITMAP DE INODOS */
    char bitmap_inodes[n];
    bm_content = "11";
    for (int i = 2; i < n; i++) {
        bm_content += "0";
    }
    strcpy(bitmap_inodes, bm_content.c_str());

    /* CREACIÓN DEL BITMAP DE BLOQUES */
    char bitmap_blocks[3 * n];
    bm_content = "11";
    for (int i = 2; i < 3 * n; i++) {
        bm_content += "0";
    }
    strcpy(bitmap_blocks, bm_content.c_str());

    /* CREACIÓN DE JOURNALING */
    Journaling journaling;

    /* ESCRITURA DEL SISTEMA DE ARCHIVOS */
    FILE *_file = fopen(_mounted.path.c_str(), "rb+");
    fseek(_file, part_start, SEEK_SET); // Mover el puntero al inicio de la partición (primaria o lógica)

    fwrite(&super_bloque, sizeof(Superbloque), 1, _file); // 1. Superbloque

    if (super_bloque.s_filesystem_type == 3) {
        for (int i = 0; i < 64; i++)
            fwrite(&journaling, sizeof(Journaling), 1, _file); // 2. Journaling
    }

    fwrite(&bitmap_inodes, n, 1, _file); // 3. Bitmap de inodos

    fwrite(&bitmap_blocks, 3 * n, 1, _file); // 4. Bitmap de bloques

    for (int i = 0; i < n; i++) {
        fwrite(&inodo, sizeof(InodosTable), 1, _file); // 5. Inodos
    }
    for (int i = 0; i < 3 * n; i++) {
        fwrite("\0", 64, 1, _file); // 6. Bloques (Hay distintos tipos de bloque, todos de 64 bytes)
    }
    /*
    CREACIÓN DE CARPETA RAÍZ
    */
    CarpetasBlock root_folder; // Nuevo bloque carpeta
    Content root_content;      // Nuevo bloque contenido
    InodosTable inode_folder;  // Nuevo inodo
    root_content.b_inodo = 0;

    strcpy(root_content.b_name, ".");
    root_folder.b_content[0] = root_content;

    strcpy(root_content.b_name, "..");
    root_folder.b_content[1] = root_content;

    Group group;
    User user;
    std::string txt = getData(group, user);

    inode_folder.i_block[0] = 0;
    inode_folder.i_size = txt.length();
    inode_folder.i_type = '0';
    inode_folder.i_gid = 1;
    inode_folder.i_uid = 1;
    inode_folder.i_perm = 777;
    inode_folder.i_ctime = getCurrentTime();
    inode_folder.i_mtime = inode_folder.i_ctime;
    inode_folder.i_atime = inode_folder.i_ctime;

    /* CREACIÓN DE ARCHIVO USERS.TXT */
    ArchivosBlock users_file;
    InodosTable users_inode;

    users_inode.i_uid = 1;
    users_inode.i_gid = 1;
    users_inode.i_size = txt.length();
    users_inode.i_type = '1';
    users_inode.i_perm = 700;
    users_inode.i_block[0] = 1;
    users_inode.i_ctime = getCurrentTime();
    users_inode.i_mtime = users_inode.i_ctime;
    users_inode.i_atime = users_inode.i_ctime;

    strcpy(root_content.b_name, "users.txt");
    root_content.b_inodo = 1;
    root_folder.b_content[2] = root_content;
    strcpy(users_file.b_content, txt.c_str());

    /* ESCRITURA */
    fseek(_file, super_bloque.s_inode_start, SEEK_SET); // Mover el puntero al inicio de la tabla de inodos
    fwrite(&inode_folder, sizeof(InodosTable), 1, _file);
    fwrite(&users_inode, sizeof(InodosTable), 1, _file);

    fseek(_file, super_bloque.s_block_start, SEEK_SET); // Mover el puntero al inicio de la tabla de bloques
    fwrite(&root_folder, 64, 1, _file);
    fwrite(&users_file, 64, 1, _file);

    fclose(_file);
    _file = nullptr;
}





