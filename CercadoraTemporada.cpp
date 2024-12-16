#include "CercadoraTemporada.h"

CercadoraTemporada::CercadoraTemporada() {

}

CercadoraTemporada::~CercadoraTemporada() {

}

int CercadoraTemporada::cercaTemporadesTotales(string titolSerie) {
	ConnexioBD& conn = ConnexioBD::getInstance(PARAMS);
	string query = "SELECT COUNT(*) AS total_temporades FROM temporada WHERE titol_serie = '" + titolSerie + "'";
	ResultSet* res = conn.executarConsulta(query);

	if (res->next()) {
		temporadesTotals = res->getInt("total_temporades");
	}
	return temporadesTotals;
}

PassarelaTemporada CercadoraTemporada::cercaPerTemporada(string titolSerie) {	
	PassarelaTemporada t;
	ConnexioBD& con = ConnexioBD::getInstance(PARAMS);
	string sql = "SELECT * FROM temporada WHERE titol_serie = '" + titolSerie + "'";
	ResultSet* res = con.executarConsulta(sql);
	// Si no troba cap fila, activa excepció
	if (!res->next()) {
		throw runtime_error("Temporada no existeix");
	}
	else {
		t = PassarelaTemporada(res->getString("titol_serie"), res->getInt("numero"));
		delete res;
	}
	return t;
}