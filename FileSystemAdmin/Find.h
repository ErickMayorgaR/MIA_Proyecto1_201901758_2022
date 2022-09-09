//
// Created by erick on 3/09/22.
//

#ifndef MIA_PROYECTO1_201901758_2S2022_FIND_H
#define MIA_PROYECTO1_201901758_2S2022_FIND_H


#include <string>

class Find {
public:
    Find(std::string path, std::string name);

    std::string path;
    std::string name;


    void executeFind();

    void findFile(std::string _path, std::string _foldername, char _pattern);
};


#endif //MIA_PROYECTO1_201901758_2S2022_FIND_H
