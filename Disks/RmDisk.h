
#ifndef MIA_PROYECTO1_201901758_2S2022_RMDISK_H
#define MIA_PROYECTO1_201901758_2S2022_RMDISK_H


#include <string>

class RmDisk {

public:
    RmDisk(std::string path);
    std::string path;
    std::string completedPath;

    void executeRmDisk();
};


#endif //MIA_PROYECTO1_201901758_2S2022_RMDISK_H
