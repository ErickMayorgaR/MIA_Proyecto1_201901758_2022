//
// Created by erick on 3/09/22.
//

#ifndef MIA_PROYECTO1_201901758_2S2022_MOVE_H
#define MIA_PROYECTO1_201901758_2S2022_MOVE_H


#include <string>

class Move {
public:
    Move(std::string path, std::string dest);

    std::string path;
    std::string dest;

    void executeMove();
    void moveFile(std::string _path_cut, std::string _name_cut, std::string _path_paste, std::string _name_paste);
};


#endif //MIA_PROYECTO1_201901758_2S2022_MOVE_H
