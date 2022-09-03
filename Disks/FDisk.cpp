//
// Created by erick on 26/08/22.
//
#include <iostream>
#include <string.h>
#include "../Utils/Structures.h"
#include "FDisk.h"
#include "../Utils/Functions.h"
#include "DiskFunctions.h"

FDisk::FDisk() =default;

void FDisk::executeFDisk(std::string _size, std::string _unit, std::string _path, std::string _type, std::string _fit,
                         std::string _delete, std::string _name, std::string _add) {
    if (_path == "" || _name == "")
        return coutError("Error: faltan parámetros obligatorios.", nullptr);

    std::string npath = getPath(_path);
    if (!isDir(npath))
        return coutError("Error: el disco no existe.", NULL);
    if (_name.length() > 16)
        return coutError("El nombre de la partición no puede exceder a 16 caracteres.", NULL);

    char nunit = getUnit(_unit, 'k');
    if (_add != "")
        return administrarEspacio(std::stoi(_add), nunit, npath, _name);

    if (_delete != "") {
        char ans;
        std::cout << "¿Desea eliminar la partición '" + _name + "' ubicada en el disco: '" + npath + "?' [Y/n] ";
        std::cin >> ans;
        if (ans == 'Y' || ans == 'y')
            return borrarParticion(charDelete(_delete), npath, _name);
        else
            return;
    }

    char ntype = charType(_type, 'P');
    char nfit = getFit(_fit, 'W');
    int nsize = (_size != "") ? intSize(_size) : intSize("-1");
    return createPartitions(nsize, nunit, npath, ntype, nfit, _name);
}


void FDisk::createPartitions(int _size, char _unit, std::string _path, char _type, char _fit, std::string _name) {
    FILE *pFile = fopen(_path.c_str(), "rb+");

    MBR mbr;
    fseek(pFile, 0, SEEK_SET);
    fread(&mbr, sizeof(MBR), 1, pFile);

    int tam = getSize(_unit, _size);
    int nstart = sizeof(MBR);
    if (_type == 'L') {
        return CrearLogica(mbr, tam, pFile, _fit, _name);
    } else {
        if (_type == 'E' && existeExtendida(mbr) > -1)
            return coutError("No puede existir más de una partición extendida dentro del disco.", pFile);

        if (existeNombreMBR(mbr, _name))
            return coutError("El nombre a asignar ya existe como partición.", pFile);

        int options[] = {-1, -1, -1, -1};
        for (int i = 0; i < 4; i++) {
            /* nstart += mbr.mbr_partition[i].part_start + mbr.mbr_partition[i].part_size; */
            nstart += mbr.mbr_partition[i].part_size;
            if (mbr.mbr_partition[i].part_status == '0') {
                if (!validations(mbr, i, nstart, tam))
                    continue; // Sigue buscando un espacio disponible
                if (i < 3) {
                    if (mbr.mbr_partition[i + 1].part_start != 0)
                        options[i] = mbr.mbr_partition[i + 1].part_start - mbr.mbr_partition[i].part_start - _size;
                    else
                        options[i] = 0;
                } else if (i == 3) {
                    if (mbr.mbr_partition[i].part_start != 0)
                        options[i] = mbr.mbr_tamano - mbr.mbr_partition[i].part_start - _size;
                    else
                        options[i] = 0;
                }
            }
        }

        int i = getPartitionByFit(options, _fit);
        if (i == -1)
            return coutError("No se encontró ningún espacio apto para crear la partición.", pFile);

        //Modificiación del MBR
        mbr.mbr_partition[i].part_fit = _fit;
        strcpy(mbr.mbr_partition[i].part_name, _name.c_str());
        mbr.mbr_partition[i].part_size = tam;
        mbr.mbr_partition[i].part_start = nstart;
        mbr.mbr_partition[i].part_status = '1';
        mbr.mbr_partition[i].part_type = _type;
        fseek(pFile, 0, SEEK_SET);
        fwrite(&mbr, sizeof(MBR), 1, pFile);

        if (_type == 'P') {
            CrearPrimaria(tam, nstart, pFile);
        } else if (_type == 'E') {
            CrearExtendida(tam, nstart, _fit, pFile);
        }
        fclose(pFile);
        pFile = NULL;
        return;
    }
    // return coutError("No se encontró ningún espacio apto para crear la partición.", pFile);
}


void FDisk::CrearPrimaria(int _size, int _nstart, FILE *_file) {
    Superbloque sb;
    fseek(_file, _nstart, SEEK_SET);
    fwrite(&sb, sizeof(Superbloque), 1, _file);
    // fwrite("\0", _size, 1, _file);
}

void FDisk::CrearExtendida(int _size, int _nstart, char _fit,
                           FILE *_file) { // Configurando el EBR ..Utils/Structures.h"inicial con los datos de una partición lógica vacía
    EBR ebr;
    ebr.part_fit = _fit;
    strcpy(ebr.part_name, "");
    ebr.part_next = -1;
    ebr.part_size = 0;
    ebr.part_start = _nstart;
    ebr.part_status = '0';
    Superbloque sb;
    fseek(_file, _nstart, SEEK_SET);
    fwrite(&ebr, sizeof(EBR), 1, _file);
    fwrite(&sb, sizeof(Superbloque), 1, _file);
    // fwrite("\0", _size, 1, _file);
}

void FDisk::CrearLogica(MBR _mbr, int _size, FILE *_file, char _fit, std::string _name) {
    int index = existeExtendida(_mbr);
    if (index == -1)
        return coutError("No existe una partición extendida para crear la partición lógica.", _file);
    partition extendida = _mbr.mbr_partition[index];

    EBR ebr_inicial;
    fseek(_file, extendida.part_start, SEEK_SET);
    fread(&ebr_inicial, sizeof(EBR), 1, _file);

    if (existeNombreEBR(ebr_inicial, _name, _file))
        return coutError("El nombre a asignar ya existe como partición lógica.", _file);

    if (_size + getLogicsSize(ebr_inicial, 0, _file) > extendida.part_size)
        return coutError("El -size requerido de la partición lógica sobrepasa el tamaño de la partición extendida",
                         _file);

    if (ebr_inicial.part_size == 0) // Modifica el EBR inicial si no hay una partición lógica creada
    {
        ebr_inicial.part_fit = _fit;
        strcpy(ebr_inicial.part_name, _name.c_str());
        ebr_inicial.part_size = _size;
        ebr_inicial.part_status = '1';
        fseek(_file, extendida.part_start, SEEK_SET);
        fwrite(&ebr_inicial, sizeof(EBR), 1, _file);
        // fwrite("\0", _size, 1, _file);
    } else {
        fseek(_file, extendida.part_start, SEEK_SET);
        EBR ebr_to_update = getLogicByFit(ebr_inicial, _fit, _file, _size); // ebr_to_update
        if (ebr_to_update.part_status == '!')
            return coutError("No se pudo crear la partición lógica.", _file);
        EBR ebr_new;
        ebr_new.part_fit = _fit;
        strcpy(ebr_new.part_name, _name.c_str());
        ebr_new.part_next = ebr_to_update.part_next;
        ebr_new.part_size = _size;
        ebr_new.part_start = ebr_to_update.part_start + ebr_to_update.part_size; // + sizeof(EBR)
        ebr_new.part_status = '1';

        ebr_to_update.part_next = ebr_new.part_start;
        Superbloque sb;

        fseek(_file, ebr_to_update.part_start, SEEK_SET);
        fwrite(&ebr_to_update, sizeof(EBR), 1, _file);

        fseek(_file, ebr_new.part_start, SEEK_SET);
        fwrite(&ebr_new, sizeof(EBR), 1, _file);

        fwrite(&sb, sizeof(Superbloque), 1, _file);
        // fwrite("\0", _size, 1, _file);
    }
    fclose(_file);
    _file = NULL;
    return;
}


void FDisk::borrarParticion(char _delete, std::string _path, std::string _name) {
    char src[_path.size() + 1];
    strcpy(src, _path.c_str());
    MBR mbr;
    FILE *pFile;
    pFile = fopen(src, "rb+");
    fseek(pFile, 0, SEEK_SET);
    fread(&mbr, sizeof(MBR), 1, pFile);

    char type = existPartition(mbr, _name, pFile);
    if (type == '0')
        return coutError("No se encuentra ninguna partición con ese nombre asignado.", pFile);

    if (type == 'P' || type == 'E') {
        int i = getPartitionIndex(mbr, _name, pFile);
        mbr.mbr_partition[i].part_fit = mbr.disk_fit;
        strcpy(mbr.mbr_partition[i].part_name, "");
        // mbr.mbr_partition[i].part_size = 0;
        mbr.mbr_partition[i].part_status = '0';
        mbr.mbr_partition[i].part_type = 'P';
        fseek(pFile, 0, SEEK_SET);
        fwrite(&mbr, sizeof(MBR), 1, pFile);
        if (_delete == 'C') {
            fseek(pFile, mbr.mbr_partition[i].part_start + sizeof(partition), SEEK_SET);
            // fwrite("\0", mbr.mbr_partition[i].part_size - sizeof(partition), 1, pFile);
        }
    } else if (type == 'L') //borrar referencia del EBR anterior
    {
        partition extendida = mbr.mbr_partition[existeExtendida(mbr)];
        EBR _ebr_to_delete, _ebr_initial, _ebr_previous;
        fseek(pFile, extendida.part_start, SEEK_SET);
        fread(&_ebr_initial, sizeof(EBR), 1, pFile);
        _ebr_to_delete = getLogicPartition(_ebr_initial, _name, pFile);
        _ebr_previous = getEBRprevious(_ebr_initial, _ebr_to_delete.part_start, pFile);
        _ebr_previous.part_next = _ebr_to_delete.part_next;
        fseek(pFile, _ebr_to_delete.part_start, SEEK_SET);
        fseek(pFile, _ebr_previous.part_start, SEEK_SET);
        fwrite(&_ebr_previous, sizeof(EBR), 1, pFile);
        if (_delete == 'C') {
            fseek(pFile, _ebr_to_delete.part_start + sizeof(EBR), SEEK_SET);
            // fwrite("\0", _ebr_to_delete.part_size - sizeof(EBR), 1, pFile);
        }
    }
    fclose(pFile);
    pFile = NULL;
    return;
}


void FDisk::administrarEspacio(int _add, char _unit, std::string _path, std::string _name){
    char src[_path.size() + 1];
    strcpy(src, _path.c_str());
    MBR mbr;
    FILE *pFile;
    pFile = fopen(src, "rb+");
    fseek(pFile, 0, SEEK_SET);
    fread(&mbr, sizeof(MBR), 1, pFile);

    char type = existPartition(mbr, _name, pFile);
    if (type == '0')
        return coutError("No se encuentra ninguna partición con ese nombre asignado.", pFile);

    int size = getSize(_unit, _add);
    if (type == 'P' || type == 'E') {
        int i = getPartitionIndex(mbr, _name, pFile);
        partition _particion = mbr.mbr_partition[i];
        if (!validations(mbr, i, _particion.part_start, size)) {
            return coutError(
                    "El parámetro '-add' debe dejar espacio positivo y no exceder los límites de la partición.", pFile);
        }

        _particion.part_size = _particion.part_size + size;
        fseek(pFile, _particion.part_start, SEEK_SET);
        fwrite(&_particion, sizeof(partition), 1, pFile);
        // fwrite("\0", _particion.part_size, 1, pFile);
    } else if (type == 'L') {

        partition extendida = mbr.mbr_partition[existeExtendida(mbr)];
        EBR _ebr_to_update, _ebr_initial;
        fseek(pFile, extendida.part_start, SEEK_SET);
        fread(&_ebr_initial, sizeof(EBR), 1, pFile);
        _ebr_to_update = getLogicPartition(_ebr_initial, _name, pFile);

        if (_ebr_to_update.part_start + _ebr_to_update.part_size + size >= _ebr_to_update.part_next ||
            _ebr_to_update.part_start + _ebr_to_update.part_size + size < _ebr_to_update.part_start)
            return coutError(
                    "El parámetro '-add' debe sobrar espacio positivo y no exceder los límites de la partición.",
                    pFile);

        _ebr_to_update.part_size = _ebr_to_update.part_size + size;
        fseek(pFile, _ebr_to_update.part_start, SEEK_SET);
        fwrite(&_ebr_to_update, sizeof(EBR), 1, pFile);
        // fwrite("\0", _ebr_to_update.part_size, 1, pFile);
    }
    fclose(pFile);
    pFile = NULL;
    return;
}


int FDisk::getPartitionByFit(int _options[], char _fit) {
    int n = _options[0];
    int ret = -1;
    for (int i = 0; i < 4; i++) {
        if (_options[i] != -1) {
            switch (_fit) {
                case 'F':
                    return i;
                case 'W':
                    if (_options[i] > n || ret == -1) {
                        n = _options[i];
                        ret = i;
                    }
                    break;
                case 'B':
                    if (_options[i] < n || ret == -1) {
                        n = _options[i];
                        ret = i;
                    }
                    break;
                default:
                    return -1;
            }
        }
    }
    return ret;
}


EBR FDisk::getLogicByFit(EBR _ebr_initial, char _fit, FILE *_file, int _size) {
    std::vector<EBR> _options = toRunLogicPartitions(_ebr_initial, _file, _size, std::vector<EBR>());
    if (_options.size() == 0)
        return {part_status : '!'};
    int n, aux = -1;
    EBR _ebr, ret = _options[0];
    for (int i = 0; i < _options.size(); i++) {
        _ebr = _options[i];
        aux = (_ebr.part_next == -1) ? 0 : _ebr.part_next - _ebr.part_start - _ebr.part_size;
        switch (_fit) {
            case 'F':
                return _ebr;
            case 'B':
                if (aux < n) {
                    n = aux;
                    ret = _ebr;
                }
                break;
            case 'W':
                if (aux > n) {
                    n = aux;
                    ret = _ebr;
                }
                break;
            default:
                return {part_status : '!'};
        }
    }
    return ret;
}


std::vector<EBR> FDisk::toRunLogicPartitions(EBR _ebr, FILE *_file, int _size, std::vector<EBR> _list) {
    if (_ebr.part_next - _ebr.part_start - _ebr.part_size > _size || _ebr.part_next == -1)
        _list.push_back(_ebr);
    if (_ebr.part_next != -1) {
        fseek(_file, _ebr.part_next, SEEK_SET);
        fread(&_ebr, sizeof(EBR), 1, _file);
        return toRunLogicPartitions(_ebr, _file, _size, _list);
    }
    return _list;
}


Disk_id buildID(std::string _id) {
    Disk_id disk_id;
    disk_id._carnet = _id.substr(0, 2);
    disk_id._number_id = std::stoi(_id.substr(2, 1));
    disk_id._letter_id = _id[_id.length() - 1];

    return disk_id;
}


int existMountedID(Disk_id _disk_id) {
    for (int i = 0; i < particiones_montadas.size(); i++) {
        MOUNTED mounted = particiones_montadas[i];
        if (mounted.id._carnet == _disk_id._carnet && mounted.id._number_id == _disk_id._number_id &&
            mounted.id._letter_id == _disk_id._letter_id)
            return i;
    }
    return -1;
}


bool FDisk::validations(MBR _mbr, int _index, int _ini, int _size) {
    if (_ini + _size < 0 || _ini + _size > _mbr.mbr_tamano || _ini + _size < _mbr.mbr_partition[_index].part_start)
        return false;
    if (_index < 3 && _mbr.mbr_partition[_index + 1].part_start > 0) {
        if (_ini + _size >= _mbr.mbr_partition[_index + 1].part_start)
            return false;
    }
    return true;
}




