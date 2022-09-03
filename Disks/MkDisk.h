#ifndef MIA_PROYECTO1_201901758_2S2022_MKDISK_H
#define MIA_PROYECTO1_201901758_2S2022_MKDISK_H

#include <string>
#include "../Utils/Structures.h"

class MkDisk{
public:
    MkDisk(std::string path, int size, char fit, char unit);


    int size;
    std::string path;
    char fit;
    char unit;
};


#endif //MIA_PROYECTO1_201901758_2S2022_MKDISK_H
