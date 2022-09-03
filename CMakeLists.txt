cmake_minimum_required(VERSION 3.22)
project(MIA_Proyecto1_201901758_2s2022)

set(CMAKE_CXX_STANDARD 14)
set(Headers Utils/Handler.h Utils/Structures.h Utils/Builder.h Disks/MkDisk.h)
link_libraries(stdc++fs)
include_directories(.)

add_executable(MIA_Proyecto1_201901758_2s2022 main.cpp Analyzer/driver.cpp Analyzer/parser.tab.cc
        Analyzer/scanner.cpp Utils/Functions.cpp Disks/MkDisk.cpp Partitions/Mount.cpp Partitions/UnMount.cpp Utils/AdminStructure.h FileSystem/Mkfs.cpp FileSystem/Mkfs.h FileSystem/Login.cpp FileSystem/Login.h FileSystem/Logout.cpp FileSystem/Logout.h FileSystem/MkGrp.cpp FileSystem/MkGrp.h FileSystem/RmGrp.cpp FileSystem/RmGrp.h FileSystem/MkUsr.cpp FileSystem/MkUsr.h FileSystem/RmUsr.cpp FileSystem/RmUsr.h FileSystemAdmin/Chmod.cpp FileSystemAdmin/Chmod.h FileSystemAdmin/MkFile.cpp FileSystemAdmin/MkFile.h FileSystemAdmin/Cat.cpp FileSystemAdmin/Cat.h FileSystemAdmin/Remove.cpp FileSystemAdmin/Remove.h FileSystemAdmin/Edit.cpp FileSystemAdmin/Edit.h FileSystemAdmin/Rename.cpp FileSystemAdmin/Rename.h FileSystemAdmin/MkDir.cpp FileSystemAdmin/Copy.cpp FileSystemAdmin/Move.cpp FileSystemAdmin/Move.h FileSystemAdmin/Find.cpp FileSystemAdmin/Find.h FileSystemAdmin/Chown.cpp FileSystemAdmin/Chown.h FileSystemAdmin/Chgrp.cpp FileSystemAdmin/Chgrp.h)
