//
// Created by erick on 3/09/22.
//

#ifndef MIA_PROYECTO1_201901758_2S2022_CAT_H
#define MIA_PROYECTO1_201901758_2S2022_CAT_H


#include <string>

class Cat {
public:
    explicit Cat(std::vector<std::string> fileN);

    std::vector<std::string> fileN;

    void executeCat();
};


#endif //MIA_PROYECTO1_201901758_2S2022_CAT_H
