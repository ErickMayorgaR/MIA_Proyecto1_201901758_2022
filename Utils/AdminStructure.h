//
// Created by erick on 3/09/22.
//

#ifndef MIA_PROYECTO1_201901758_2S2022_ADMINSTRUCTURE_H
#define MIA_PROYECTO1_201901758_2S2022_ADMINSTRUCTURE_H
#include <iostream>
#include <stdio.h>
#include "Structures.h"

struct Group
{
    int GID = 1;
    char tipo = 'G';
    std::string nombre = "root";
};

struct User
{
    int UID = 1;
    int GID = 1;
    char tipo = 'U';
    std::string grupo = "root";
    std::string nombre = "root";
    std::string contrasena = "123";
    bool logged_in = false;
    ParticionesMontadas mounted;
};

std::string getData(Group _group, User _user)
{
    std::string data = std::to_string(_group.GID) + "," + _group.tipo + "," + _group.nombre + "\n" + std::to_string(_user.UID) + "," + _user.tipo + "," + _user.grupo + "," + _user.nombre + "," + _user.contrasena + "\n";
    return data;
}

User _user_logged;

#endif //MIA_PROYECTO1_201901758_2S2022_ADMINSTRUCTURE_H
