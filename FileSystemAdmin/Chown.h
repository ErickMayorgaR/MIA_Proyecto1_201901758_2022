//
// Created by erick on 3/09/22.
//

#ifndef MIA_PROYECTO1_201901758_2S2022_CHOWN_H
#define MIA_PROYECTO1_201901758_2S2022_CHOWN_H


#include <string>

class Chown {
public:
    Chown(std::string path, std::string user, std::string r);

    std::string path;
    std::string user;
    std::string r;

    void executeChown();

    void changeOwner(std::string _path, std::string _name, bool _r);

    int updateUid(int _index_inode, int _start_inodes, int _start_blocks, int _uid, int _aux);

    int rewriteUidInode(int _index_inode, int _start_inodes, int _uid, int _aux);
};


#endif //MIA_PROYECTO1_201901758_2S2022_CHOWN_H
