

#ifndef MIA_PROYECTO1_201901758_2S2022_DISK_H
#define MIA_PROYECTO1_201901758_2S2022_DISK_H

#include <string>
#include "../Utils/Structures.h"
#include "../Utils/Functions.h"
#include "../Disks/DiskFunctions.h"



class DiskReport {
public:
    DiskReport(ParticionesMontadas _mounted);

    ParticionesMontadas _mounted;

    std::string getReport();

    std::string getDotPartitions(MBR _mbr, std::string _path, FILE *_file);

    std::string getDotLogics(EBR _ebr, int _mbr_tamano, FILE *_file, std::string _color, std::string _dot, int _free);

    std::string getPercentage(int _free, int _mbr_tamano);

    int getSizeBeforeFree(MBR _mbr, int _num);



    };


#endif //MIA_PROYECTO1_201901758_2S2022_DISK_H
