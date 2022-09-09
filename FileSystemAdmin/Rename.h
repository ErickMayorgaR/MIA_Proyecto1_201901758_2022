//
// Created by erick on 3/09/22.
//

#ifndef MIA_PROYECTO1_201901758_2S2022_RENAME_H
#define MIA_PROYECTO1_201901758_2S2022_RENAME_H


#include <string>

class Rename {
public:
    Rename(std::string path, std::string name);

    std::string path;
    std::string name;

    void executeRename();

    void renameFile(std::string _path, std::string _name_to_edit);
};


#endif //MIA_PROYECTO1_201901758_2S2022_RENAME_H
