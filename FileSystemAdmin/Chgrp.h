//
// Created by erick on 3/09/22.
//

#ifndef MIA_PROYECTO1_201901758_2S2022_CHGRP_H
#define MIA_PROYECTO1_201901758_2S2022_CHGRP_H


#include <string>

class Chgrp {
public:
    Chgrp(std::string user, std::string grp);

    std::string user;
    std::string grp;

    void executeChgrp();
};


#endif //MIA_PROYECTO1_201901758_2S2022_CHGRP_H
