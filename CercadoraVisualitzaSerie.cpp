#include "CercadoraVisualitzaSerie.h"

CercadoraVisualitzaSerie::CercadoraVisualitzaSerie() {

}

CercadoraVisualitzaSerie::~CercadoraVisualitzaSerie() {

}

int CercadoraVisualitzaSerie::cercaVisualitzacions(const string& sobrenom) {
	ConnexioBD& conn = ConnexioBD::getInstance(PARAMS);
	int num_visualitzacions;

	string query = "SELECT * FROM visualitzacio_capitol WHERE sobrenom_usuari = '" + sobrenom + "'";
	ResultSet* res = conn.executarConsulta(query);

	if (res->next()) num_visualitzacions = res->getInt("num_visualitzacions");
	else num_visualitzacions = 0;

	return num_visualitzacions;
}