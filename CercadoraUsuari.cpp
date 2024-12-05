#include "CercadoraUsuari.h"

CercadoraUsuari::CercadoraUsuari() {

}

CercadoraUsuari::~CercadoraUsuari() {

}

PassarelaUsuari CercadoraUsuari::cercaPerSobrenom(string sobrenomU) {
	PassarelaUsuari u;
	ConnexioBD& con = ConnexioBD::getInstance(PARAMS);
	string sql = "SELECT * FROM usuari WHERE sobrenom = '" + sobrenomU + "'";
	sql::ResultSet* res = con.executarConsulta(sql);
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