#pragma once

#include <cppconn/driver.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <mysql_driver.h>
#include <iostream>

using namespace std;
using namespace sql;
using namespace sql::mysql;

class ConnexioBD {
private:
    MySQL_Driver* driver;
    Connection* con;

public:
    ConnexioBD(const string& servidor, const string& usuario, const string& password, const string& database);
    ~ConnexioBD();

    ResultSet* executarConsulta(const string& sqlQuery);
    void executarComanda(const string& sqlQuery);
};


