//
// Created by erick on 3/09/22.
//

#ifndef MIA_PROYECTO1_201901758_2S2022_CHMOD_H
#define MIA_PROYECTO1_201901758_2S2022_CHMOD_H


#include <string>

class Chmod {
public:
    Chmod(std::string path, std::string ugo, std::string r);

    std::string path;
    std::string ugo;
    std::string r;

    int _ugo;
    bool _r;

    void executeChmod();
    void changePermissions(std::string _name);
    int updatePermissions(int _index_inode, int _start_inodes, int _start_blocks, int _aux);
    int rewriteInode(int _index_inode, int _start_inodes, int _aux);
};



#endif //MIA_PROYECTO1_201901758_2S2022_CHMOD_H
