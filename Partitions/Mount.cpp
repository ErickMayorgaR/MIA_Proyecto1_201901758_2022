
#include "Mount.h"

#include <iostream>

#include "../Utils/Functions.h"
#include "../Disks/DiskFunctions.h"

Mount::Mount(std::string path, std::string name) {
    this->name = name;
    this->path = path;
    executeMount();
}


void Mount::executeMount() {
    if (path == "" || name == "") {
        return coutError("Error: faltan parámetros obligatorios.", nullptr);
    }
    path = getPath(path);
    if (!isDir(path)) {
        return coutError("Error: el disco no existe.", nullptr);
    }
    mountPartition();
}


void Mount::mountPartition() {
    FILE *_file = fopen(path.c_str(), "rb+");

    MBR mbr;
    fseek(_file, 0, SEEK_SET);
    fread(&mbr, sizeof(MBR), 1, _file);

    char tipo = existPartition(mbr, name, _file);

    ParticionesMontadas _mounted;
    _mounted.id = assignID();
    _mounted.type = tipo;
    _mounted.path = path;

    int _part_start;

    if (tipo == 'P' || tipo == 'E') {
        partition _particion = getPartition(mbr, name, _file);
        _part_start = _particion.part_start;
        _mounted.particion = _particion;
    } else if (tipo == 'L') {
        partition _extendida = mbr.mbr_partition[existeExtendida(mbr)];
        EBR _ebr_to_mount, _ebr_initial;
        fseek(_file, _extendida.part_start, SEEK_SET);
        fread(&_ebr_initial, sizeof(EBR), 1, _file);
        _ebr_to_mount = getLogicPartition(_ebr_initial, name, _file);
        _part_start = _ebr_to_mount.part_start + sizeof(EBR);

        _mounted.logica = _ebr_to_mount;
    } else {
        return coutError("No se encuentra ninguna partición con ese nombre asignado.", _file);
    }

    particiones_montadas.push_back(_mounted);

    if (tipo != 'E') {
        Superbloque sb;
        fseek(_file, _part_start, SEEK_SET);
        fread(&sb, sizeof(Superbloque), 1, _file);
        if (sb.s_mnt_count > 0) {
            sb.s_mtime = getCurrentTime();
            sb.s_mnt_count++;
            fseek(_file, _part_start, SEEK_SET);
            fwrite(&sb, sizeof(Superbloque), 1, _file);
        }
    }

    fclose(_file);
    _file = nullptr;
    return printMOUNTED();
}



DiskId Mount::assignID() {
    ParticionesMontadas mounted;
    DiskId tmp;
    for (int i = particiones_montadas.size() - 1; i >= 0; i--) {
        mounted = particiones_montadas[i];
        if (mounted.path == path) {
            tmp._number_id = mounted.id._number_id;
            tmp._letter_id = char(int(mounted.id._letter_id) + 1);
            return tmp;
        }
    }
    number_id += 1;
    tmp._number_id = number_id;
    return tmp;
}

void Mount::printMOUNTED() {
    for (int i = 0; i < particiones_montadas.size(); i++) {
        ParticionesMontadas _mounted = particiones_montadas[i];
        std::string tmp = _mounted.id._carnet + std::to_string(_mounted.id._number_id) + _mounted.id._letter_id;
        std::string name = (_mounted.type == 'L') ? _mounted.logica.part_name : _mounted.particion.part_name;
        std::cout << "\033[1;33m" + _mounted.path + "|" + name + "|" + tmp + "\033[0m\n";
    }
}
