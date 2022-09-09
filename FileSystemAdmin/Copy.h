//
// Created by erick on 5/09/22.
//

#ifndef MIA_PROYECTO1_201901758_2S2022_COPY_H
#define MIA_PROYECTO1_201901758_2S2022_COPY_H

#include <string>

class Copy {
public:
    Copy(std::string path, std::string dest);

    std::string path;
    std::string dest;

    void executeCopy();

    void copyFile(std::string _path_cut, std::string _name_cut, std::string _path_paste, std::string _name_paste);
};

#endif //MIA_PROYECTO1_201901758_2S2022_COPY_H
