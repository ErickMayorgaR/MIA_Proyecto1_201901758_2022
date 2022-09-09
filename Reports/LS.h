#ifndef MIA_PROYECTO1_201901758_2S2022_LS_H
#define MIA_PROYECTO1_201901758_2S2022_LS_H

#include "../Utils/Structures.h"
#include "../Utils/Functions.h"
#include "../Disks/DiskFunctions.h"
#include "ReportFunctions.h"
#include <string>

class LS {
public:
    LS(ParticionesMontadas mounted);

    ParticionesMontadas mounted;

    std::string getReport();

    std::string getDotLS(FILE *_file, int _index_inode, int _start_inodes, int _start_blocks, std::string _dot,
                         std::string _name);

    };


#endif //MIA_PROYECTO1_201901758_2S2022_LS_H
