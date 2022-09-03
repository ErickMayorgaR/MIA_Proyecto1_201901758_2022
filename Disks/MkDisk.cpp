#include <iostream>
#include <string.h>
#include <time.h>
#include "../Utils/Structures.h"
#include "MkDisk.h"
#include "Utils/Functions.h"

void createDisk(int _size, char _fit, char _unit, std::string _path) {
    char charPath[_path.size() + 1];
    strcpy(charPath, _path.c_str());
    FILE *file = NULL;
    file = fopen(charPath, "r");
    if (file != NULL)
        return coutError("Error: El disco ya existe.", file);

    //Tamaño para distintas unidades que se piden
    int tam = getSize(_unit, _size);

    file = fopen(charPath, "wb");
    fwrite("\0", 1, 1, file);
    fseek(file, tam, SEEK_SET);
    fwrite("\0", 1, 1, file);

    //////MBR//////
    MBR mbr;
    mbr.mbr_tamano = tam;
    mbr.mbr_fecha_creacion = getCurrentTime();
    mbr.mbr_disk_signature = rand() % 1000;
    mbr.disk_fit = _fit;
    for (int i = 0; i < 4; i++) {
        mbr.mbr_partition[i].part_status = '0';
        mbr.mbr_partition[i].part_type = 'P';
        mbr.mbr_partition[i].part_fit = _fit;
        mbr.mbr_partition[i].part_start = 0;
        mbr.mbr_partition[i].part_size = 0;
        strcpy(mbr.mbr_partition[i].part_name, "");
    }

    //Escritura del MBR
    fseek(file, 0, SEEK_SET);
    fwrite(&mbr, sizeof(MBR), 1, file);
    fclose(file);
    file = NULL;

    return;
}

void makeDisk(std::string _size, std::string _fit, std::string _unit, std::string _path) {
    try {
        //casting  variables
        int newSize = castSize(_size);
        char newFit = getFit(_fit, 'F');
        char newUnit = getUnit(_unit, 'm');
        std::string np = buildPath(_path);
        std::cout << "CREANDO DISCO EN LA RUTA: \"" + np + "\"" << std::endl;
        createDisk(newSize, newFit, newUnit, np);
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
        return coutError("ERROR!", NULL);
    }
}

MkDisk::MkDisk(std::string path, int size, char fit, char unit) {
    this->size = size;
    this->path = path;
    this->fit = fit;
    this->unit = unit;


}
