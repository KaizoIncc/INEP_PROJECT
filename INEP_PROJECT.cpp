#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <iostream>
#include <mysql_connection.h>
#include <mysql_driver.h>
using namespace std;

int main()
{
	sql::mysql::MySQL_Driver* driver = NULL;
	sql::Connection* con = NULL;
	sql::Statement* stmt = NULL;
	try {
		driver = sql::mysql::get_mysql_driver_instance();
		con = driver->connect("URL_servidor:port",
			"usuari", "contrasenya");
		con->setSchema("nom_base_dades");
		stmt = con->createStatement();
		// Sentència SQL per obtenir totes les files de la taula usuari
		string sql = "SELECT * FROM usuari";
		sql::ResultSet* res = stmt->executeQuery(sql);
		// Bucle per recórrer les dades retornades mostrant les dades de cada fila
		while (res->next()) {
			// a la funció getString fem servir el nom de la columna de la taula
			cout << "Sobrenom: " << res->getString("sobrenom") << endl;
			cout << "Nom: " << res->getString("nom") << endl;
			cout << "Correu: " << res->getString("correu_electronic") << endl;
		}
		con->close();
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error: " << e.what() << std::endl;
		// si hi ha un error es tanca la connexió (si esta oberta)
		if (con != NULL) con->close();
	}
	return 0;
}
