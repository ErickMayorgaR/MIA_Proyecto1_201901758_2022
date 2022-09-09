
#ifndef MIA_PROYECTO1_201901758_2S2022_SB_H
#define MIA_PROYECTO1_201901758_2S2022_SB_H

#include "../Utils/Structures.h"
#include "../Utils/Functions.h"
#include "../Disks/DiskFunctions.h"
#include "ReportFunctions.h"
#include <string>

class SB {
public:
    SB(ParticionesMontadas mounted);
    ParticionesMontadas mounted;

    std::string getReport();

};


#endif //MIA_PROYECTO1_201901758_2S2022_SB_H
