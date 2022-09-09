//
// Created by erick on 8/09/22.
//

#ifndef MIA_PROYECTO1_201901758_2S2022_LOSS_H
#define MIA_PROYECTO1_201901758_2S2022_LOSS_H


#include <string>
#include "../Utils/Structures.h"


class Loss {
public:
    Loss(std::string id);

    std::string id;

    void executeLoss();

    void lossSystem(ParticionesMontadas _mounted);

};


#endif //MIA_PROYECTO1_201901758_2S2022_LOSS_H
