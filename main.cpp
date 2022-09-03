#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <thread>
#include "Analyzer/driver.h"
#include <bits/stdc++.h>


void executeCommand(std::string path);
void executeAnalyzer(std::string fileName);

int main() {
    system("clear");
    std::string input, output;
    std::string filename = "command.txt";
    while (true) {
        std::cout<< "INICIO "<<std::endl;
        std::cout<<"Inserte un comando >> "<< std::endl;

        getline(std::cin, input);
        if (strstr(input.c_str(), std::string("exec").c_str())) {
            int size1 = input.length();
            int size2 = input.size();
            std::string path = input.substr(input.find("-path") + 8, (input.length()-2));
            path = path.substr(0,path.length()-1);

            executeCommand(path);
            continue;
        }
        if (input == "exit" || input == "quit")
            return 0;
        if (input == "cls" || input == "clear") {
            system("clear");
            continue;
        }
        if (input == "")
            continue;

        std::ofstream MyFile(filename);
        MyFile << input;
        MyFile.close();

        executeAnalyzer(filename);
    }
}


void executeAnalyzer(std::string filename){
    parser_driver driver;
    if (driver.parse(filename))
        std::cout << "\033[1;32mSuccessfully\033[0m\n";
}


void executeCommand(std::string _path) {
    std::ifstream file(_path);
    //std::string pathAux = "/home/erick/Desktop/PruebaCrearDiscos.mia";
    //std::ifstream file(pathAux);
    std::string line;
    std::string filename = "exec.txt";
    while (std::getline(file, line)) {
        if (line != "" && line[0] != '#') {
            std::cout << std::endl;
            std::cout << ">> " + line << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(350));
            std::ofstream MyFile(filename);
            MyFile << line;
            MyFile.close();
            executeAnalyzer(filename);
        }
    }
}


