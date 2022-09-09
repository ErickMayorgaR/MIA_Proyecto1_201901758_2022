
#ifndef MIA_PROYECTO1_201901758_2S2022_FILE_H
#define MIA_PROYECTO1_201901758_2S2022_FILE_H

#include "../Utils/Structures.h"
#include "../Utils/Functions.h"
#include "../Disks/DiskFunctions.h"
#include "ReportFunctions.h"
#include <string>


class FileReport {
public:
    FileReport(ParticionesMontadas mounted);
    ParticionesMontadas mounted;


    std::string getReport(std::string _ruta);
    std::string getDot_file_block(std::string _name, std::string _content);
};


#endif //MIA_PROYECTO1_201901758_2S2022_FILE_H
