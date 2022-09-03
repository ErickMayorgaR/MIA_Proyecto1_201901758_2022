#include <iostream>
#include <fstream>
#include <string.h>
#include "../Utils/Structures.h"
#include "../Utils/Functions.h"
#include "../Disks/DiskFunctions.h"


using std::string;


string getDotMBR(MBR _mbr, string _path) {
    string mbr_fecha_creacion = ctime(&_mbr.mbr_fecha_creacion);
    string dot =
            string("\"MBR Report\" [ margin=\"0.5\" label = <\n") +
            "<TABLE BGCOLOR=\"#48D1CC\" BORDER=\"2\" COLOR=\"BLACK\" CELLBORDER=\"1\" CELLSPACING=\"0\">\n" +
            "<TR>\n" +
            "<TD BGCOLOR=\"#d23939\" COLSPAN=\"2\">MBR REPORT</TD>\n" +
            "</TR>\n\n" +

            "<TR>\n" +
            "<TD WIDTH=\"140\" BGCOLOR=\"#ff6363\"><B>Nombre</B></TD>\n" +
            "<TD BGCOLOR=\"#ff6363\"><B>Valor</B></TD>\n" +
            "</TR>\n\n" +

            "<TR>\n" +
            "<TD ALIGN=\"left\">mbr_tamaño</TD>\n" +
            "<TD>" + std::to_string(_mbr.mbr_tamano) + "</TD>\n" +
            "</TR>\n\n" +

            "<TR>\n" +
            "<TD ALIGN=\"left\">mbr_fecha_creacion</TD>\n" +
            "<TD>" + mbr_fecha_creacion + "</TD>\n" +
            "</TR>\n\n" +

            "<TR>\n" +
            "<TD ALIGN=\"left\">mbr_disk_signature</TD>\n" +
            "<TD>" + std::to_string(_mbr.mbr_disk_signature) + "</TD>\n" +
            "</TR>\n\n" +

            "<TR>\n" +
            "<TD ALIGN=\"left\">disk_fit</TD>\n" +
            "<TD>" + _mbr.disk_fit + "</TD>\n" +
            "</TR>\n\n" +

            "<TR>\n" +
            "<TD ALIGN=\"left\">disk_path</TD>\n" +
            "<TD>" + _path.substr(root.length()) + "</TD>\n" +
            "</TR>\n\n";

    for (int i = 0; i < 4; i++) {
        partition _particion = _mbr.mbr_partition[i];
        if (_particion.part_status == '0') {
            dot +=
                    string("<TR>\n") +
                    "<TD ALIGN=\"left\">part_status_" + std::to_string(i + 1) + "</TD>\n" +
                    "<TD>" + _particion.part_status + "</TD>\n" +
                    "</TR>\n\n" +

                    "<TR>\n" +
                    "<TD ALIGN=\"left\">part_type_" + std::to_string(i + 1) + "</TD>\n" +
                    "<TD>" + _particion.part_type + "</TD>\n" +
                    "</TR>\n\n" +

                    "<TR>\n" +
                    "<TD ALIGN=\"left\">part_fit_" + std::to_string(i + 1) + "</TD>\n" +
                    "<TD>" + _particion.part_fit + "</TD>\n" +
                    "</TR>\n\n" +

                    "<TR>\n" +
                    "<TD ALIGN=\"left\">part_start_" + std::to_string(i + 1) + "</TD>\n" +
                    "<TD>" + std::to_string(_particion.part_start) + "</TD>\n" +
                    "</TR>\n\n" +

                    "<TR>\n" +
                    "<TD ALIGN=\"left\">part_size_" + std::to_string(i + 1) + "</TD>\n" +
                    "<TD>" + std::to_string(_particion.part_size) + "</TD>\n" +
                    "</TR>\n\n" +

                    "<TR>\n" +
                    "<TD ALIGN=\"left\">part_name_" + std::to_string(i + 1) + "</TD>\n" +
                    "<TD>" + _particion.part_name + "</TD>\n" +
                    "</TR>\n\n";
        }
    }
    dot += "</TABLE>>];\n";
    return dot;
}

string getDotEBR(EBR _ebr, int _index, string _node, string _dot, FILE *_file) {
    _index++;
    string new_node = "\"EBR_" + std::to_string(_index) + " Report\"";
    _dot += _node + " -> " + new_node + "\n";
    _dot +=
            string(new_node + " [ label = <\n") +
            "<TABLE BGCOLOR=\"#48D1CC\" BORDER=\"2\" COLOR=\"BLACK\" CELLBORDER=\"1\" CELLSPACING=\"0\">\n" +
            "<TR>\n" +
            "<TD BGCOLOR=\"#d23939\" COLSPAN=\"2\">EBR_" + std::to_string(_index) + " REPORT</TD>\n" +
            "</TR>\n\n" +

            "<TR>\n" +
            "<TD WIDTH=\"140\" BGCOLOR=\"#ff6363\"><B>Nombre</B></TD>\n" +
            "<TD BGCOLOR=\"#ff6363\"><B>Valor</B></TD>\n" +
            "</TR>\n\n" +

            "<TR>\n" +
            "<TD ALIGN=\"left\">part_name</TD>\n" +
            "<TD>" + _ebr.part_name + "</TD>\n" +
            "</TR>\n\n" +

            "<TR>\n" +
            "<TD ALIGN=\"left\">part_status</TD>\n" +
            "<TD>" + _ebr.part_status + "</TD>\n" +
            "</TR>\n\n" +

            "<TR>\n" +
            "<TD ALIGN=\"left\">part_fit</TD>\n" +
            "<TD>" + _ebr.part_fit + "</TD>\n" +
            "</TR>\n\n" +

            "<TR>\n" +
            "<TD ALIGN=\"left\">part_start</TD>\n" +
            "<TD>" + std::to_string(_ebr.part_start) + "</TD>\n" +
            "</TR>\n\n" +

            "<TR>\n" +
            "<TD ALIGN=\"left\">part_size</TD>\n" +
            "<TD>" + std::to_string(_ebr.part_size) + "</TD>\n" +
            "</TR>\n\n" +

            "<TR>\n" +
            "<TD ALIGN=\"left\">part_next</TD>\n" +
            "<TD>" + std::to_string(_ebr.part_next) + "</TD>\n" +
            "</TR>\n\n" + "</TABLE>>];\n";

    if (_ebr.part_next != -1) {
        fseek(_file, _ebr.part_next, SEEK_SET);
        fread(&_ebr, sizeof(EBR), 1, _file);
        return getDotEBR(_ebr, _index, new_node, _dot, _file);
    }
    return _dot;
}


void generateReport() {
    std::string syst = "dot -Tpng ../Report/report.dot -o ../Report/Reporte.png";
    system(syst.c_str());
    std::cout<<"Reporte Generado"<<std::endl;
}


void ReportMBR(std::string path) {
    std::string graph = ""
                        "digraph G {\n"
                        "graph[bgcolor=\"#141D26\" margin=0]\n"
                        "rankdir=\"TB\";\n"
                        "node [shape=plaintext fontname= \"Ubuntu\" fontsize=\"14\"];\n"
                        "edge [style=\"invis\"];\n\n";


    path = buildPath(path);
    FILE *_file = fopen(path.c_str(), "rb");

    MBR mbr;
    fseek(_file, 0, SEEK_SET);
    fread(&mbr, sizeof(MBR), 1, _file);


    graph += getDotMBR(mbr, path);

    int index = existeExtendida(mbr);
    if (index != -1) {
        EBR ebr;
        partition extendida = mbr.mbr_partition[index];
        fseek(_file, extendida.part_start, SEEK_SET);
        fread(&ebr, sizeof(EBR), 1, _file);
        if (ebr.part_size != 0)
            graph += getDotEBR(ebr, 0, "\"MBR Report\"", "", _file);
    }
    graph += "}";

    fclose(_file);
    _file = NULL;

    std::ofstream MyFile("../Report/report.dot");
    MyFile << graph;
    MyFile.close();

    generateReport();

}

