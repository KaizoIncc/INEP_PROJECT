#pragma once
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <iostream>
#include <mysql_connection.h>
#include <mysql_driver.h>

using namespace std; // Esto elimina la necesidad de usar el prefijo `std::`
using namespace sql; // Esto elimina la necesidad de usar el prefijo `sql::`
using namespace sql::mysql; // Esto elimina la necesidad de usar el prefijo `sql::mysql`

class ConnexioBD
{
private:
	Driver* driver;
	Connection* con;

public:
	ConnexioBD(const string& host, const string& user, const string& bbdd, const string& password);
	~ConnexioBD();
	ResultSet* executarConsulta(const string& sql);
	void executarComanda(const string& sql);

	void registrarUsuari();
	void consultarUsuari();
	void modificarUsuari();
	void esborrarUsuari();
};

