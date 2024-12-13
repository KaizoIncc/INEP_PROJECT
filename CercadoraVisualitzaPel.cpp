#include "CercadoraVisualitzaPel.h"

CercadoraVisualitzaPel::CercadoraVisualitzaPel() {

}

CercadoraVisualitzaPel::~CercadoraVisualitzaPel() {

}

int CercadoraVisualitzaPel::cercaVisualitzacions(const string& sobrenom) {
	ConnexioBD& conn = ConnexioBD::getInstance(PARAMS);
	int num_visualitzacionsPel;
	string query = "SELECT * FROM visualitzacio_pelicula WHERE sobrenom_usuari = '" + sobrenom + "'";
	ResultSet* res = conn.executarConsulta(query);

	if (res->next()) num_visualitzacionsPel = res->getInt("num_visualitzacions");
	else num_visualitzacionsPel = 0;

	return num_visualitzacionsPel;
}