
#ifndef MIA_PROYECTO1_201901758_2S2022_TREE_H
#define MIA_PROYECTO1_201901758_2S2022_TREE_H

#include "../Utils/Structures.h"
#include "../Utils/Functions.h"
#include "../Disks/DiskFunctions.h"
#include "ReportFunctions.h"
#include <string>

class Tree {
public:
    Tree(ParticionesMontadas mounted);

    ParticionesMontadas mounted;

    std::string getReport();

    std::string getDotTree(int _index_inode, int _start_inodes, int _start_blocks, std::string _path, int _index_root);

    std::string getDot_inode_tree(InodosTable _inode, int _index_inode);

    std::string getDot_folder_block_tree(int _start_blocks, int _index_block, std::string _path);

    std::string getDot_file_block_tree(int _start_blocks, int _index_block, std::string _path);

};


#endif //MIA_PROYECTO1_201901758_2S2022_TREE_H
