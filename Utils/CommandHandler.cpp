#include <iostream>
#include <string>
#include "../Utils/Builder.h"

#include "../Disks/MkDisk.h"
#include "../Disks/RmDisk.h"

#include "../Partitions/FDisk.h"
#include "../Partitions/Mount.h"
#include "../Partitions/UnMount.h"

#include "../FileSystem/Mkfs.h"
#include "../FileSystem/Login.h"
#include "../FileSystem/Logout.h"
#include "../FileSystem/MkGrp.h"
#include "../FileSystem/RmGrp.h"
#include "../FileSystem/MkUsr.h"
#include "../FileSystem/RmUsr.h"
#include "../FileSystem/Recovery.h"
#include "../FileSystem/Loss.h"

#include "../FileSystemAdmin/Chmod.h"
#include "../FileSystemAdmin/MkFile.h"
#include "../FileSystemAdmin/Cat.h"
#include "../FileSystemAdmin/Remove.h"
#include "../FileSystemAdmin/Rename.h"
#include "../FileSystemAdmin/MkDir.h"
#include "../FileSystemAdmin/Copy.h"
#include "../FileSystemAdmin/Move.h"
#include "../FileSystemAdmin/Find.h"
#include "../FileSystemAdmin/Chown.h"
#include "../FileSystemAdmin/Chgrp.h"

#include "AdminStructure.h"

#include "../Reports/ReportHandler.h"
#include "../Reports/JournalingReport.h"


#include "Functions.h"

int CommandHandler(struct Command x) {
    if (x.keyword == "__MKFS" || x.keyword == "__MKGRP" || x.keyword == "__RMGRP" || x.keyword == "__MKUSR" ||
        x.keyword == "__RMUSR" ||
        x.keyword == "__CHMOD" || x.keyword == "__TOUCH" || x.keyword == "__RM" || x.keyword == "__EDIT" ||
        x.keyword == "__MKDIR" || x.keyword == "__CAT" ||
        x.keyword == "__MV" || x.keyword == "__CP" || x.keyword == "__REN" || x.keyword == "__CHOWN" ||
        x.keyword == "__CHGRP") {
        if (_user_logged.logged_in) {
            Superbloque sb;
            FILE *file = fopen(_user_logged.mounted.path.c_str(), "rb");
            int part_start = startByteSuperBloque(_user_logged.mounted);
            fseek(file, part_start,SEEK_SET);
            fread(&sb,sizeof(Superbloque), 1, file);
            if (sb.s_magic == -1) {
                coutError("El sistema de archivos se ha corrompido, intente recuperarlo usando Recovery.", file);
                return 0;
            }
            if (sb.s_filesystem_type == 3) {
                JournalingReport *journaling = new JournalingReport;
                journaling->addToReport(x);
            }
            fclose(file);
            file = NULL;
        }
    }


    if (x.keyword == "__MKDISK") {
        MkDisk *mkDisk = new MkDisk(x.path, x.size, x.fit, x.unit);
    } else if (x.keyword == "__RMDISK") {
        RmDisk *rmDisk = new RmDisk(x.path);
    } else if (x.keyword == "__FDISK") {
        FDisk *fdisk = new FDisk(x.size, x.unit, x.path, x.type, x.fit, x.delet,x.name, x.add);
    } else if (x.keyword == "__REP") {
        ReportHandler *rpHandler = new ReportHandler(x.name, x.path, x.id, x.ruta);
    } else if (x.keyword == "__MOUNT") {
        Mount *mount = new Mount(x.path, x.name);
    } else if (x.keyword == "__UMOUNT") {
        UnMount *unMount = new UnMount(x.id);
    } else if (x.keyword == "__MKFS") {
        Mkfs *mkfs = new Mkfs(x.id, x.type, x.fs);
    } else if (x.keyword == "__LOGIN") {
        Login *login = new Login(x.user, x.pwd, x.id);
    } else if (x.keyword == "__LOGOUT") {
        Logout *logout = new Logout();
    } else if (x.keyword == "__MKGRP") {
        MkGrp *mkGrp = new MkGrp(x.name);
    } else if (x.keyword == "__RMGRP") {
        RmGrp *rmGrp = new RmGrp(x.name);
    } else if (x.keyword == "__MKUSR") {
        MkUsr *mkUsr = new MkUsr(x.user, x.pwd, x.grp);
    } else if (x.keyword == "__RMUSR") {
        RmUsr *rmUsr = new RmUsr(x.user);
    } else if (x.keyword == "__CHMOD") {
        Chmod *chmod = new Chmod(x.path, x.ugo, x.r);
    } else if (x.keyword == "__MKFILE") {
        MkFile *mkFile = new MkFile(x.path, x.r, x.size, x.cont, x._stdin, false);
        int pre_t = mkFile->status;
        if (pre_t == 777) {
            MkDir *mkDir = new MkDir((x.path).substr(0, x.path.find_last_of('/')), "true");
            if (!mkDir->created) {
                return 0;
            }
            MkFile *reMkFile = new MkFile(x.path, x.r, x.size, x.cont, x._stdin, false);
        }
        return pre_t;
    } else if (x.keyword == "__CAT") {
        Cat *cat = new Cat(x.filen);
    } else if (x.keyword == "__RM") {
        Remove *remove = new Remove(x.path);
    } else if (x.keyword == "__EDIT") {
        MkFile *mkFile = new MkFile(x.path, x.r, x.size, x.cont, x._stdin, true);
    } else if (x.keyword == "__REN") {
        Rename *rename = new Rename(x.path, x.name);
    } else if (x.keyword == "__MKDIR") {
        MkDir *mkDir = new MkDir(x.path, x.r);
    } else if (x.keyword == "__CP") {
        Copy *copy = new Copy(x.path, x.dest);
    } else if (x.keyword == "__MV") {
        Move *move = new Move(x.path, x.dest);
    } else if (x.keyword == "__FIND") {
        Find *find = new Find(x.path, x.name);
    } else if (x.keyword == "__CHOWN") {
        Chown *chown = new Chown(x.path, x.user, x.r);
    } else if (x.keyword == "__CHGRP") {
        Chgrp *chgrp = new Chgrp(x.user, x.grp);
    }else if (x.keyword == "__LOSS"){
        Loss *loss = new Loss(x.id);
    }else if (x.keyword == "__RECOVERY") {
        Recovery *recovery = new Recovery(x.id);
    }
}


