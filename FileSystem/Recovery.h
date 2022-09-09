//
// Created by erick on 8/09/22.
//

#ifndef MIA_PROYECTO1_201901758_2S2022_RECOVERY_H
#define MIA_PROYECTO1_201901758_2S2022_RECOVERY_H


#include <string>
#include "../Utils/Structures.h"

class Recovery {
public:
    Recovery(std::string id);

    std::string id;

    void executeRecovery();

    void recoverySystem(ParticionesMontadas _mounted);


};


#endif //MIA_PROYECTO1_201901758_2S2022_RECOVERY_H
