

#ifndef MIA_PROYECTO1_201901758_2S2022_JOURNALINGREPORT_H
#define MIA_PROYECTO1_201901758_2S2022_JOURNALINGREPORT_H


#include <string>
#include "../Utils/Builder.h"

class JournalingReport {
    public:
    JournalingReport();

    void generateReport(std::string _path);

    void addToReport(command _tmp);

    std::string getDot(command tmp);

    std::string getJournalingHeader();




    };


#endif //MIA_PROYECTO1_201901758_2S2022_JOURNALINGREPORT_H
