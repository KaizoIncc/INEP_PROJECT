#pragma once

#include <cppconn/driver.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <mysql_driver.h>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace sql;
using namespace sql::mysql;

class ConnexioBD {
private:
    // Atributos para la conexión
    MySQL_Driver* driver;
    Connection* con;

    // Constructor privado
    ConnexioBD(const string& cadenaConexion);

    // Destructor privado
    ~ConnexioBD();

    // Declaración de métodos prohibidos para evitar la copia
    ConnexioBD(const ConnexioBD&) = delete;
    ConnexioBD& operator=(const ConnexioBD&) = delete;

public:
    // Método estático para acceder a la instancia única
    static ConnexioBD& getInstance(const string& cadenaConexion);

    // Métodos para interactuar con la base de datos
    ResultSet* executarConsulta(const string& sqlQuery);
    void executarComanda(const string& sqlQuery);
};
