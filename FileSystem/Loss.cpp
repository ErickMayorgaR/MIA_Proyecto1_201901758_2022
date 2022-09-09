
#include <iostream>
#include <string.h>
#include "../Utils/Functions.h"
#include "Loss.h"
#include "../Disks/DiskFunctions.h"



Loss::Loss(std::string id) {
    this->id = id;
    executeLoss();

}

void Loss::executeLoss() {
    if (id == "")
        return coutError("Error: faltan parámetros obligatorios.", NULL);

    DiskId disk_id = buildID(id);

    int index = existMountedID(disk_id);
    if (index == -1)
        return coutError("No se encuentra ninguna partición montada con el id '" + _id + "'.", NULL);
    ParticionesMontadas mounted = particiones_montadas[index];

    return lossSystem(mounted);
}


void Loss::lossSystem(ParticionesMontadas _mounted) {
    int part_start;
    switch (_mounted.type) {
        case 'P':
            part_start = _mounted.particion.part_start;
            break;
        case 'L':
            part_start = _mounted.logica.part_start + sizeof(EBR);
            break;
        default:
            return coutError("Solamente se puede corromper un sistema de archivos en una partición primaria o lógica.",
                             NULL);
    }
    FILE *file = fopen(_mounted.path.c_str(), "rb+");
    Superbloque sb;
    fseek(file, part_start, SEEK_SET);
    fread(&sb, sizeof(Superbloque), 1, file);
    if (sb.s_mnt_count > 0) {
        if (sb.s_filesystem_type == 2) {
            char ans;
            std::cout
                    << "El sistema de archivos es EXT2, no podrá recuperar el sistema después. ¿Desea continuar? [Y/n]";
            std::cin >> ans;
            if (ans == 'N' || ans == 'n') {
                fclose(file);
                file = NULL;
                return;
            }
        }
        sb.s_magic = -1;
        fseek(file, part_start, SEEK_SET);
        fwrite(&sb, sizeof(Superbloque), 1, file);
    } else {
        return coutError("No se encuentra un sistema de archivos existente.", file);
    }
    fclose(file);
    file = NULL;
   }



