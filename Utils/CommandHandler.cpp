#include <iostream>
#include <string>
#include "../Utils/Builder.h"
#include "../Disks/MkDisk.cpp"
#include "../Report/MBRReport.cpp"
#include "../Disks/FDisk.h"

/* Aquí se maneja qué acción ejecutar según lo que devuelve el analizador */

int CommandHandler(struct command x){

    if (x.keyword == "__MKDISK") {
        makeDisk(x.size, x.fit, x.unit, x.path);
    }else if(x.keyword =="__FDISK"){
        FDisk *fdisk = new FDisk();
        fdisk->executeFDisk(x.size, x.unit, x.path, x.type, x.fit, x.delet, x.name, x.add);
    }else if (x.keyword == "__REP") {
         ReportMBR(x.path);
    }
    return 0;
}
