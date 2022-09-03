//
// Created by erick on 26/08/22.
//

#ifndef _MIA_HT2_201901758_FDISK_H
#define _MIA_HT2_201901758_FDISK_H

#include <string>
#include "../Utils/Structures.h"

class FDisk{
public:
    FDisk();


    void createPartitions(int size, char unit, std::string path, char type, char fit, std::string name);


    void executeFDisk(std::string _size, std::string _unit, std::string _path, std::string _type, std::string _fit,
                      std::string _delete, std::string _name, std::string _add);

    void CrearPrimaria(int _size, int _nstart, FILE *_file);

    void CrearExtendida(int _size, int _nstart, char _fit, FILE *_file);

    void CrearLogica(MBR _mbr, int _size, FILE *_file, char _fit, std::string _name);

    bool validations(MBR _mbr, int _index, int _ini, int _size);

    void borrarParticion(char _delete, std::string _path, std::string _name);

    void administrarEspacio(int _add, char _unit, std::string _path, std::string _name);

    int getPartitionByFit(int *_options, char _fit);

    std::vector<EBR> toRunLogicPartitions(EBR _ebr, FILE *_file, int _size, std::vector<EBR> _list);

    EBR getLogicByFit(EBR _ebr_initial, char _fit, FILE *_file, int _size);
};

#endif //_MIA_HT2_201901758_FDISK_H
