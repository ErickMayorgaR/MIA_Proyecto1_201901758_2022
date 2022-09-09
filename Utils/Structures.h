#ifndef STRUCTURES
#define STRUCTURES

#include <iostream>
#include <stdio.h>
#include <vector>


struct partition {
    char part_status;
    char part_type; // primaria, extendida, logica
    char part_fit;  // las opciones por default
    int part_start;
    int part_size;
    char part_name[16];
};


struct MBR {
    int mbr_tamano;
    time_t mbr_fecha_creacion;
    int mbr_disk_signature;
    char disk_fit;
    partition mbr_partition[4];
};


struct EBR {
    char part_status;
    char part_fit; //b,f,w
    int part_start;
    int part_size;
    int part_next; //próximo EBR || -1
    char part_name[16];
};


struct DiskId {
    std::string _carnet = "58";
    int _number_id = 1;
    char _letter_id = 'A';
};


struct ParticionesMontadas {
    std::string path;
    DiskId id;
    char type;
    partition particion;
    EBR logica;
};


static int number_id;
static std::vector<ParticionesMontadas> particiones_montadas;


struct FolderReference {
    int inode = 0;
    int block = 0;
};


struct Superbloque {
    int s_filesystem_type;   // Guarda el número que identifica el sistema de archivos utilizado
    int s_inodes_count;      // Guarda el número total de inodos
    int s_blocks_count;      // Guarda el número total de bloques
    int s_free_blocks_count; // Contiene el número de bloques libres
    int s_free_inodes_count; // Contiene el número de inodos libres
    time_t s_mtime;          // Última fecha en el que el sistema fue montado
    time_t s_umtime;         // Última fecha en que el sistema fue desmontado
    int s_mnt_count = 0;     // Indica cuantas veces se ha montado el sistema
    int s_magic;             // Valor que identifica al sistema de archivos, tendrá el valor 0xEF53
    int s_inode_size;        // Tamaño del inodo
    int s_block_size;        // Tamaño del bloque
    int s_first_ino;         // Primer inodo libre
    int s_first_blo;         // Primer bloque libre
    int s_bm_inode_start;    // Guardará el inicio del bitmap de inodos
    int s_bm_block_start;    // Guardará el inicio del bitmap de bloques
    int s_inode_start;       // Guardará el inicio de la tabla de inodos
    int s_block_start;       // Guardará el inicio de la tabla de bloques
};


struct InodosTable {
    int i_uid;      // UID del usuario propietario del archivo o carpeta
    int i_gid;      // GID del grupo al que pertenece el archivo o carpeta
    int i_size;     // Tamaño del archivo en bytes
    time_t i_atime; // Última fecha en que se leyó el inodo sin modificarlo
    time_t i_ctime; // Fecha en la que se creó el inodo
    time_t i_mtime; // Úlitma fecha en la que se modificó el inodo
    /* Array en los que los primeros 12 registros son bloques directos.
    El 13 será el número del bloque simple indirecto.
    El 14 será el número del bloque doble indirecto.
    El 15 será el número del bloque triple indirecto.
    Si no son utilizados tendrá el valor -1 */
    int i_block[15] = {1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}; // Hace referencia al bloque apunta
    char i_type;                                                                   // Indica si es archivo o carpeta. 1=archivo, 0=carpeta
    int i_perm;                                                                    // Guardará los permisos del archivo o carpeta a nivel de bits
};


struct Content {
    char b_name[12] = ""; // Nombre de la carpeta o archivo
    int b_inodo = -1;     // Apuntador hacia un inodo asociado al archivo o carpeta
};


struct CarpetasBlock {
    Content b_content[4]; // Array con el contenido de la carpeta
};


struct ArchivosBlock {
    char b_content[64] = ""; // Array con el contenido del archivo
};


struct ApuntadoresBlock {
    int b_pointers[16] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
};


struct Journaling {
    char command[100] = "-";
};


#endif