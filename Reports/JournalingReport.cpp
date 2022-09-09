
#include "JournalingReport.h"
#include <iostream>
#include <fstream>
#include "../Utils/Functions.h"
#include "ReportFunctions.h"
#include "../Utils/Builder.h"


JournalingReport::JournalingReport() {

}

void JournalingReport::generateReport(std::string _path) {
    std::string dir = "../Results/journal.dot";
    std::ofstream f;
    f.open(dir, std::ios_base::app); // append instead of overwrite
    f << "</TABLE>>];\n}";
    f.close();
    std::string extension = _path.substr(_path.find_last_of('.') + 1);
    std::string syst = "dot -T" + extension + " " + dir + " -o " + _path;
    system(syst.c_str());

    remove(dir.c_str());
}


void JournalingReport::addToReport(Command _tmp) {
    std::string dir = "../Results/journal.dot";
    bool x = true;
    if (!isDir(dir)) {
        x = false;
        std::ofstream MyFile(dir);
        MyFile << "";
        MyFile.close();
    }
    std::ofstream f;
    f.open(dir, std::ios_base::app); // append instead of overwrite
    if (!x)
        f << getBaseHeader();

    f << getDot(_tmp);
    f.close();
}


std::string JournalingReport::getDot(Command tmp) {
    string dot =
            string("<TR>\n") +
            "<TD HEIGHT=\"60\">" + tmp.keyword + "</TD>\n" +
            "<TD>" + tmp.size + "</TD>\n" +
            "<TD>" + tmp.path + "</TD>\n" +
            "<TD>" + tmp.type + "</TD>\n" +
            "<TD>" + tmp.name + "</TD>\n" +
            "<TD>" + tmp.fs + "</TD>\n" +
            "<TD>" + tmp.user + "</TD>\n" +
            "<TD>" + tmp.pwd + "</TD>\n" +
            "<TD>" + tmp.grp + "</TD>\n" +
            "<TD>" + tmp.dest + "</TD>\n" +
            "<TD>" + tmp.ugo + "</TD>\n" +
            "<TD>" + ((tmp.r == "") ? ("") : ("true")) + "</TD>\n" +
            "<TD>" + tmp.cont + "</TD>\n" +
            "<TD>" + ((tmp._stdin == "") ? ("") : ("true")) + "</TD>\n" +
            "</TR>\n\n";
    return dot;
}

string getHeader() {
    string grafo = getBaseHeader();
    grafo +=
            string("\"Journaling\" [margin=\"1\" label = <\n") +
            "<TABLE BGCOLOR=\"#009999\" BORDER=\"2\" COLOR=\"BLACK\" CELLBORDER=\"1\" CELLSPACING=\"0\">\n" +
            "<TR>\n" +
            "<TD HEIGHT=\"30\" BGCOLOR=\"#B8860B\" COLSPAN=\"14\">JOURNAL REPORT</TD>\n" +
            "</TR>\n\n" +

            "<TR>\n" +
            "<TD HEIGHT=\"35\" WIDTH=\"100\" BGCOLOR=\"#708090\"><B>Acción</B></TD>\n" +
            "<TD BGCOLOR=\"#708090\"><B>Size</B></TD>\n" +
            "<TD BGCOLOR=\"#708090\"><B>Path</B></TD>\n" +
            "<TD BGCOLOR=\"#708090\"><B>Type</B></TD>\n" +
            "<TD BGCOLOR=\"#708090\"><B>Name</B></TD>\n" +
            "<TD BGCOLOR=\"#708090\"><B>Fs</B></TD>\n" +
            "<TD BGCOLOR=\"#708090\"><B>Usr</B></TD>\n" +
            "<TD BGCOLOR=\"#708090\"><B>Pwd</B></TD>\n" +
            "<TD BGCOLOR=\"#708090\"><B>Grp</B></TD>\n" +
            "<TD BGCOLOR=\"#708090\"><B>Dest</B></TD>\n" +
            "<TD BGCOLOR=\"#708090\"><B>Ugo</B></TD>\n" +
            "<TD BGCOLOR=\"#708090\"><B>Recursivo</B></TD>\n" +
            "<TD BGCOLOR=\"#708090\"><B>Cont</B></TD>\n" +
            "<TD BGCOLOR=\"#708090\"><B>stdin</B></TD>\n" +
            "</TR>\n\n";
    return grafo;
}



