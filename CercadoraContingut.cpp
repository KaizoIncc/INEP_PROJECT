#include "CercadoraContingut.h"

CercadoraContingut::CercadoraContingut() {

}

CercadoraContingut::~CercadoraContingut() {

}

PassarelaContingut CercadoraContingut::cercaPerTitol(string titol) {
	PassarelaContingut c;
	ConnexioBD& con = ConnexioBD::getInstance(PARAMS);
	string sql = "SELECT * FROM contingut WHERE titol = '" + titol + "'";
	ResultSet* res = con.executarConsulta(sql);
	// Si no troba cap fila, activa excepció
	if (!res->next()) {
		throw runtime_error("Serie no existeix");
	}
	else {
		c = PassarelaContingut(res->getString("titol"), res->getString("descripcio"), res->getString("qualificacio"), res->getString("tipus"));
		delete res;
	}
	return c;
}

PassarelaContingut CercadoraContingut::cercaContingutPeli(string titol) {
	PassarelaContingut c;
	ConnexioBD& con = ConnexioBD::getInstance(PARAMS);
	string sql = "SELECT * FROM contingut WHERE titol = '" + titol + "' AND tipus = 'pelicula'";
	ResultSet* res = con.executarConsulta(sql);
	// Si no troba cap fila, activa excepció
	if (!res->next()) {
		throw runtime_error("El contingut no existeix");
	}
	else {
		c = PassarelaContingut(res->getString("titol"), res->getString("descripcio"), res->getString("qualificacio"), res->getString("tipus"));
		delete res;
	}
	return c;
}