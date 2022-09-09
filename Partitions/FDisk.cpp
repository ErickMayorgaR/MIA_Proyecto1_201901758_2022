#include <iostream>
#include <string.h>
#include "../Utils/Structures.h"
#include "../Utils/Functions.h"
#include "../Disks/DiskFunctions.h"
#include "../Partitions/FDisk.h"

FDisk::FDisk(std::string size, std::string unit, std::string path, std::string type, std::string fit,
             std::string varDelete, std::string name, std::string add) {
    this->size = size;
    this->unit = unit;
    this->path = path;
    this->type = type;
    this->fit = fit;
    this->varDelete = varDelete;
    this->name = name;
    this->add = add;
    executeFDisk();

}


void FDisk::executeFDisk() {
    if (path == "" || name == "")
        return coutError("Error: faltan parámetros obligatorios.", nullptr);

    completedPath = getPath(path);
    if (!isDir(completedPath))
        return coutError("Error: el disco no existe.", NULL);
    if (name.length() > 16)
        return coutError("El nombre de la partición no puede exceder a 16 caracteres.", NULL);

    _unit = getUnit(unit, 'k');
    if (add != "")
        return manageSpace();

    if (varDelete != "") {
        char ans;
        std::cout << "¿Desea eliminar la partición '" + name + "' ubicada en el disco: '" + completedPath + "?' [Y/n] ";
        std::cin >> ans;
        if (ans == 'Y' || ans == 'y')
            return erasePartition(charDelete(varDelete));
        else
            return;
    }

    // casting variables to their types
    _type = charType(type, 'P');
    _fit = getFit(fit, 'W');
    _size = (size != "") ? castSize(size) : castSize("-1");
    return createPartitions();
}


void FDisk::createPartitions() {
    FILE *pFile = fopen(completedPath.c_str(), "rb+");

    MBR mbr;
    fseek(pFile, 0, SEEK_SET);
    fread(&mbr, sizeof(MBR), 1, pFile);

    int tam = getSize(_unit, _size);
    int nstart = sizeof(MBR);
    if (_type == 'L') {
        return createLogic(mbr, tam, pFile);
    } else {
        if (_type == 'E' && existeExtendida(mbr) > -1)
            return coutError("No puede existir más de una partición extendida dentro del disco.", pFile);

        if (existeNombreMBR(mbr, name))
            return coutError("El nombre a asignar ya existe como partición.", pFile);

        int options[] = {-1, -1, -1, -1};
        for (int i = 0; i < 4; i++) {
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
        int i = getPartitionByFit(options);
        if (i == -1)
            return coutError("No se encontró ningún espacio apto para crear la partición.", pFile);

        //Modificiación del MBR
        mbr.mbr_partition[i].part_fit = _fit;
        strcpy(mbr.mbr_partition[i].part_name, name.c_str());
        mbr.mbr_partition[i].part_size = tam;
        mbr.mbr_partition[i].part_start = nstart;
        mbr.mbr_partition[i].part_status = '1';
        mbr.mbr_partition[i].part_type = _type;
        fseek(pFile, 0, SEEK_SET);
        fwrite(&mbr, sizeof(MBR), 1, pFile);

        if (_type == 'P') {
            createPrimary(nstart, pFile);
        } else if (_type == 'E') {
            createExtended(nstart, pFile);
        }
        fclose(pFile);
        pFile = NULL;
        return;
    }
}


void FDisk::createPrimary(int _nstart, FILE *_file) {
    Superbloque sb;
    fseek(_file, _nstart, SEEK_SET);
    fwrite(&sb, sizeof(Superbloque), 1, _file);
}

void FDisk::createExtended(int _nstart, FILE *_file) {
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

void FDisk::createLogic(MBR _mbr, int sizeByte, FILE *_file) {
    int index = existeExtendida(_mbr);
    if (index == -1)
        return coutError("No existe una partición extendida para crear la partición lógica.", _file);
    partition extendida = _mbr.mbr_partition[index];

    EBR ebr_inicial;
    fseek(_file, extendida.part_start, SEEK_SET);
    fread(&ebr_inicial, sizeof(EBR), 1, _file);

    if (existeNombreEBR(ebr_inicial, name, _file))
        return coutError("El nombre a asignar ya existe como partición lógica.", _file);

    if (sizeByte + getLogicsSize(ebr_inicial, 0, _file) > extendida.part_size)
        return coutError("El -size requerido de la partición lógica sobrepasa el tamaño de la partición extendida",
                         _file);

    if (ebr_inicial.part_size == 0) // Modifica el EBR inicial si no hay una partición lógica creada
    {
        ebr_inicial.part_fit = _fit;
        strcpy(ebr_inicial.part_name, name.c_str());
        ebr_inicial.part_size = sizeByte;
        ebr_inicial.part_status = '1';
        fseek(_file, extendida.part_start, SEEK_SET);
        fwrite(&ebr_inicial, sizeof(EBR), 1, _file);
        // fwrite("\0", _size, 1, _file);
    } else {
        fseek(_file, extendida.part_start, SEEK_SET);
        EBR ebr_to_update = getLogicByFit(ebr_inicial, _fit, _file, sizeByte); // ebr_to_update
        if (ebr_to_update.part_status == '!')
            return coutError("No se pudo crear la partición lógica.", _file);
        EBR ebr_new;
        ebr_new.part_fit = _fit;
        strcpy(ebr_new.part_name, name.c_str());
        ebr_new.part_next = ebr_to_update.part_next;
        ebr_new.part_size = sizeByte;
        ebr_new.part_start = ebr_to_update.part_start + ebr_to_update.part_size; // + sizeof(EBR)
        ebr_new.part_status = '1';

        ebr_to_update.part_next = ebr_new.part_start;
        Superbloque sb;

        fseek(_file, ebr_to_update.part_start, SEEK_SET);
        fwrite(&ebr_to_update, sizeof(EBR), 1, _file);

        fseek(_file, ebr_new.part_start, SEEK_SET);
        fwrite(&ebr_new, sizeof(EBR), 1, _file);

        fwrite(&sb, sizeof(Superbloque), 1, _file);
    }
    fclose(_file);
    _file = NULL;
    return;
}


void FDisk::erasePartition(char deleteChar) {
    char src[completedPath.size() + 1];
    strcpy(src, completedPath.c_str());
    MBR mbr;
    FILE *pFile;
    pFile = fopen(src, "rb+");
    fseek(pFile, 0, SEEK_SET);
    fread(&mbr, sizeof(MBR), 1, pFile);

    char type = existPartition(mbr, name, pFile);
    if (type == '0')
        return coutError("No se encuentra ninguna partición con ese nombre asignado.", pFile);

    if (type == 'P' || type == 'E') {
        int i = getPartitionIndex(mbr, name, pFile);
        mbr.mbr_partition[i].part_fit = mbr.disk_fit;
        strcpy(mbr.mbr_partition[i].part_name, "");
        // mbr.mbr_partition[i].part_size = 0;
        mbr.mbr_partition[i].part_status = '0';
        mbr.mbr_partition[i].part_type = 'P';
        fseek(pFile, 0, SEEK_SET);
        fwrite(&mbr, sizeof(MBR), 1, pFile);
        if (deleteChar == 'C') {
            fseek(pFile, mbr.mbr_partition[i].part_start + sizeof(partition), SEEK_SET);
            // fwrite("\0", mbr.mbr_partition[i].part_size - sizeof(partition), 1, pFile);
        }
    } else if (type == 'L') //borrar referencia del EBR anterior
    {
        partition extendida = mbr.mbr_partition[existeExtendida(mbr)];
        EBR _ebr_to_delete, _ebr_initial, _ebr_previous;
        fseek(pFile, extendida.part_start, SEEK_SET);
        fread(&_ebr_initial, sizeof(EBR), 1, pFile);
        _ebr_to_delete = getLogicPartition(_ebr_initial, name, pFile);
        _ebr_previous = getEBRprevious(_ebr_initial, _ebr_to_delete.part_start, pFile);
        _ebr_previous.part_next = _ebr_to_delete.part_next;
        fseek(pFile, _ebr_to_delete.part_start, SEEK_SET);
        fseek(pFile, _ebr_previous.part_start, SEEK_SET);
        fwrite(&_ebr_previous, sizeof(EBR), 1, pFile);
        if (deleteChar == 'C') {
            fseek(pFile, _ebr_to_delete.part_start + sizeof(EBR), SEEK_SET);

        }
    }
    fclose(pFile);
    pFile = NULL;
    return;
}


void FDisk::manageSpace(){
    char src[completedPath.size() + 1];
    strcpy(src, completedPath.c_str());
    MBR mbr;
    FILE *pFile;
    pFile = fopen(src, "rb+");
    fseek(pFile, 0, SEEK_SET);
    fread(&mbr, sizeof(MBR), 1, pFile);

    char type = existPartition(mbr, name, pFile);
    if (type == '0')
        return coutError("No se encuentra ninguna partición con ese nombre asignado.", pFile);

    int size = getSize(_unit, std::stoi(add));
    if (type == 'P' || type == 'E') {
        int i = getPartitionIndex(mbr, name, pFile);
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
        _ebr_to_update = getLogicPartition(_ebr_initial, name, pFile);

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


int FDisk::getPartitionByFit(int _options[]) {
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


EBR FDisk::getLogicByFit(EBR _ebr_initial, char _fit, FILE *_file, int sizeByte) {
    std::vector<EBR> _options = toRunLogicPartitions(_ebr_initial, _file, sizeByte, std::vector<EBR>());
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


std::vector<EBR> FDisk::toRunLogicPartitions(EBR _ebr, FILE *_file, int sizeByte, std::vector<EBR> _list) {
    if (_ebr.part_next - _ebr.part_start - _ebr.part_size > sizeByte || _ebr.part_next == -1)
        _list.push_back(_ebr);
    if (_ebr.part_next != -1) {
        fseek(_file, _ebr.part_next, SEEK_SET);
        fread(&_ebr, sizeof(EBR), 1, _file);
        return toRunLogicPartitions(_ebr, _file, sizeByte, _list);
    }
    return _list;
}


bool FDisk::validations(MBR _mbr, int _index, int _ini, int sizeByte) {
    if (_ini + sizeByte < 0 || _ini + sizeByte > _mbr.mbr_tamano || _ini + sizeByte < _mbr.mbr_partition[_index].part_start)
        return false;
    if (_index < 3 && _mbr.mbr_partition[_index + 1].part_start > 0) {
        if (_ini + sizeByte >= _mbr.mbr_partition[_index + 1].part_start)
            return false;
    }
    return true;
}


