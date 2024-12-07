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
	string query = "SELECT COUNT(*) FROM usuaris WHERE sobrenom = '" + sobrenom + "'";
	ConnexioBD& conn = ConnexioBD::getInstance(PARAMS);
	ResultSet* res = conn.executarConsulta(query);
	// Si troba una fila, activa excepció
	if (res->next()) return true;
	else return false;
}

bool CercadoraUsuari::existeixCorreu(const string& correu) {
	string query = "SELECT COUNT(*) FROM usuaris WHERE correu = '" + correu + "'";
	ConnexioBD& conn = ConnexioBD::getInstance(PARAMS);
	ResultSet* res = conn.executarConsulta(query);
	// Si troba una fila, activa excepció
	if (res->next()) return true;
	else return false;
}