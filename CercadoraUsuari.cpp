#include "CercadoraUsuari.h"
using namespace sql;

CercadoraUsuari::CercadoraUsuari() {

}

CercadoraUsuari::~CercadoraUsuari() {

}

PassarelaUsuari CercadoraUsuari::cercaPerSobrenom(string sobrenomU) {
	PassarelaUsuari u;
	ConnexioBD& con = ConnexioBD::getInstance(PARAMS);
	string sql = "SELECT * FROM usuari WHERE sobrenom = '" + sobrenomU + "'";
	ResultSet* res = con.executarConsulta(sql);
	// Si no troba cap fila, activa excepció
	if (!res->next()) {
		throw runtime_error("Usuari no existeix");
	}
	else {
		u = PassarelaUsuari(res->getString("sobrenom"), res->getString("nom"), res->getString("contrasenya"), res->getString("correu_electronic"), res->getString("data_naixement"), res->getString("subscripcio"));
		delete res;
	}
	return u;
}

bool CercadoraUsuari::existeixSobrenom(const string& sobrenom) {
	string query = "SELECT COUNT(*) FROM usuari WHERE sobrenom = '" + sobrenom + "'";

	ConnexioBD& conn = ConnexioBD::getInstance(PARAMS);
	ResultSet* res = conn.executarConsulta(query);

	if (res->next()) { // Asegura que hi ha resultats
		int count = res->getInt(1); // Llegeix el primer camp (el COUNT)
		delete res; // Assegura que el `ResultSet` es neteja
		return count > 0; // Retorna true si count > 0
	}
	else {
		delete res;
		return false; // No hi ha cap fila retornada
	}
}

bool CercadoraUsuari::existeixCorreu(const string& correu) {
	string query = "SELECT COUNT(*) FROM usuari WHERE correu_electronic = '" + correu + "'";

	try {
		ConnexioBD& conn = ConnexioBD::getInstance(PARAMS);
		ResultSet* res = conn.executarConsulta(query);

		if (res == nullptr) {
			throw runtime_error("Error al recuperar el ResultSet.");
		}

		if (res->next()) { // Si hi ha resultats
			int count = res->getInt(1); // Llegeix el primer camp (el COUNT)
			delete res; // Allibera el ResultSet
			return count > 0; // Retorna true si el compte és més gran que 0
		}
		else {
			delete res; // Allibera el ResultSet
			return false; // Cap resultat
		}
	}
	catch (const sql::SQLException& e) {
		cerr << "Error SQL: " << e.what() << endl;
		throw runtime_error("Error al executar la consulta SQL.");
	}
	catch (const runtime_error& e) {
		cerr << "Error: " << e.what() << endl;
		throw; // Propaga l'excepció
	}
}