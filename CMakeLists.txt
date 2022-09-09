cmake_minimum_required(VERSION 3.22)
project(MIA_Proyecto1_201901758_2s2022)

set(CMAKE_CXX_STANDARD 14)
set(Headers Utils/Handler.h Utils/Structures.h Utils/Builder.h Disks/MkDisk.h Utils/AdminStructure.h FileSystem/Mkfs.h
        FileSystem/Login.h FileSystem/Logout.h FileSystem/MkGrp.h FileSystem/RmGrp.h FileSystem/RmUsr.h
        FileSystem/MkUsr.h FileSystemAdmin/Chmod.h FileSystemAdmin/Cat.h FileSystemAdmin/MkFile.h
        FileSystemAdmin/Remove.h FileSystemAdmin/Rename.h FileSystemAdmin/Move.h
        FileSystemAdmin/Chown.h FileSystemAdmin/Find.h FileSystemAdmin/Chgrp.h Disks/DiskFunctions.h Partitions/FDisk.h
        Disks/RmDisk.h  FileSystemAdmin/MkDir.h FileSystemAdmin/Copy.h Reports/ReportHandler.h Reports/Block.h
        Reports/BMBlock.h Reports/BMInode.h Reports/DiskReport.h Reports/Inode.h Reports/JournalingReport.h
        Reports/Tree.h Reports/SB.h Reports/FileReport.h Reports/LS.h FileSystem/Recovery.h FileSystem/Loss.h
        Reports/ReportFunctions.h Reports/MBRReport.h
        )
link_libraries(stdc++fs)
#include_directories(Disks FileSystem FileSystemAdmin Partitions Reports Utils)

add_executable(MIA_Proyecto1_201901758_2s2022 main.cpp Analyzer/driver.cpp Analyzer/parser.tab.cc
        Analyzer/scanner.cpp Utils/Functions.cpp Disks/MkDisk.cpp Partitions/Mount.cpp Partitions/UnMount.cpp
         FileSystem/Mkfs.cpp FileSystem/Login.cpp
        FileSystem/Logout.cpp  FileSystem/MkGrp.cpp  FileSystem/RmGrp.cpp
        FileSystem/MkUsr.cpp  FileSystem/RmUsr.cpp
        FileSystemAdmin/Chmod.cpp  FileSystemAdmin/MkFile.cpp
        FileSystemAdmin/Cat.cpp FileSystemAdmin/Remove.cpp
        FileSystemAdmin/Rename.cpp
        FileSystemAdmin/MkDir.cpp FileSystemAdmin/Copy.cpp FileSystemAdmin/Move.cpp
        FileSystemAdmin/Find.cpp  FileSystemAdmin/Chown.cpp
        FileSystemAdmin/Chgrp.cpp Disks/DiskFunctions.cpp Disks/RmDisk.cpp Partitions/FDisk.cpp
        Reports/ReportHandler.cpp  Reports/Block.cpp Reports/BMBlock.cpp  Reports/BMInode.cpp
        Reports/DiskReport.cpp  Reports/Inode.cpp  Reports/JournalingReport.cpp  Reports/Tree.cpp
        Reports/SB.cpp Reports/FileReport.cpp Reports/LS.cpp FileSystem/Recovery.cpp FileSystem/Loss.cpp
        Reports/ReportFunctions.cpp )