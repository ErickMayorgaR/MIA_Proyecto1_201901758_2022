

#include "../Utils/Functions.h"
#include "Chgrp.h"



Chgrp::Chgrp(std::string user, std::string grp) {
    this->user = user;
    this->grp = grp;
    executeChgrp();

}

void Chgrp::executeChgrp() {
    if (user == "" || grp == "")
        return coutError("Error: faltan parámetros obligatorios.", NULL);

    if (_user_logged.nombre != "root" || _user_logged.logged_in == false)
        return coutError("Error: solamente se puede ejecutar el comando chgrp con el usuario root.", NULL);

    User user_to_edit, user_tmp;
    user_to_edit.nombre = user;
    user_to_edit.grupo = grp;
    Group group_tmp;

    FILE *file = fopen(_user_logged.mounted.path.c_str(), "rb+");
    /* Lectura del superbloque */
    Superbloque super_bloque;
    fseek(file, startByteSuperBloque(_user_logged.mounted), SEEK_SET);
    fread(&super_bloque, sizeof(Superbloque), 1, file);

    InodosTable users_inode;
    fseek(file, super_bloque.s_inode_start, SEEK_SET); // Mover el puntero al inicio de la tabla de inodos
    fseek(file, sizeof(InodosTable),
          SEEK_CUR);        // Mover el puntero al segundo inodo que corresponde al archivo de users.txt
    fread(&users_inode, sizeof(InodosTable), 1, file); // Leer el inodo

    ArchivosBlock users_file;
    fseek(file, super_bloque.s_block_start, SEEK_SET);  // Mover el puntero al inicio de la tabla de bloques
    fseek(file, 64,
          SEEK_CUR);                          // Mover el puntero al segundo bloque que corresponde al archivo de users.txt
    fread(&users_file, sizeof(ArchivosBlock), 1, file); // Leer el bloque

    /* Obtener todo el archivo concatenado */
    std::string content_file = ReadFile(1, super_bloque.s_inode_start, super_bloque.s_block_start,
                                   _user_logged.mounted.path);

    /* LEER LÍNEA POR LÍNEA EL ARCHIVO USERS.TXT */
    // std::cout << content_file << std::endl;
    std::istringstream f(content_file);
    string line;
    int gid = 1;
    int uid = 1;
    bool existGroup, userFound = false;
    while (getline(f, line)) {
        int count = 0;
        for (int i = 0; (i = line.find(',', i)) != std::string::npos; i++)
            count++;
        switch (count) {
            case 2:
                if (!existGroup) {
                    gid++;
                    group_tmp.GID = std::stoi(line.substr(0, line.find_first_of(',')));
                    line = line.substr(line.find_first_of(',') + 1);

                    group_tmp.tipo = line.substr(0, line.find_first_of(','))[0];
                    line = line.substr(line.find_first_of(',') + 1);

                    group_tmp.nombre = line.substr(0, line.find_first_of('\n'));
                    if (user_to_edit.grupo == group_tmp.nombre && group_tmp.GID != 0)
                        existGroup = true;
                }
                break;
            case 4:
                if (!userFound) {
                    uid++;
                    user_tmp.UID = std::stoi(line.substr(0, line.find_first_of(',')));
                    line = line.substr(line.find_first_of(',') + 1);

                    user_tmp.tipo = line.substr(0, line.find_first_of(','))[0];
                    line = line.substr(line.find_first_of(',') + 1);

                    user_tmp.grupo = line.substr(0, line.find_first_of(','));
                    line = line.substr(line.find_first_of(',') + 1);

                    user_tmp.nombre = line.substr(0, line.find_first_of(','));
                    line = line.substr(line.find_first_of(',') + 1);

                    user_tmp.contrasena = line.substr(0, line.find_first_of('\n'));
                    if (user_tmp.nombre == user_to_edit.nombre && user_tmp.UID != 0)
                        userFound = true;
                }
                break;
        }
    }
    if (!existGroup)
        return coutError("Error: No existe ningún grupo activo con el nombre: '" + user_to_edit.grupo + "'.", file);

    if (!userFound)
        return coutError("Error: No existe ningún usuario activo con el nombre: '" + user_to_edit.nombre + "'.", file);

    string tmp =
            std::to_string(user_tmp.UID) + ",U," + user_tmp.grupo + "," + user_tmp.nombre + "," + user_tmp.contrasena +
            "\n";
    string edited = std::to_string(user_tmp.UID) + ",U," + user_to_edit.grupo + "," + user_tmp.nombre + "," +
                    user_tmp.contrasena + "\n";
    content_file.replace(content_file.find(tmp), tmp.length(), edited);
    // std::cout << content_file + "\n";

    fclose(file);
    file = NULL;
    return editarArchivo("/", "users.txt", content_file); // Llamar al método de editar archivo con el nuevo contenido
}


