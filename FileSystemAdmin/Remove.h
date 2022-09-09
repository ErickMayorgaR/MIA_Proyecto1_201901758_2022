//
// Created by erick on 3/09/22.
//

#ifndef MIA_PROYECTO1_201901758_2S2022_REMOVE_H
#define MIA_PROYECTO1_201901758_2S2022_REMOVE_H


#include <string>

class Remove {
public:
    Remove(std::string path);

    std::string path;


    void executeRemove();

    int toRemove(int _index_inode, int _seek_superbloque);

    void deleteFile(std::string _path, std::string _name);

    int rewriteInode(int _index_inode, int _seek_superbloque);
};


#endif //MIA_PROYECTO1_201901758_2S2022_REMOVE_H
