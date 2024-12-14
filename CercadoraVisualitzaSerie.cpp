#include "CercadoraVisualitzaSerie.h"

CercadoraVisualitzaSerie::CercadoraVisualitzaSerie() {

}

CercadoraVisualitzaSerie::~CercadoraVisualitzaSerie() {

}

int CercadoraVisualitzaSerie::cercaVisualitzacions(string sobrenom) {
	ConnexioBD& conn = ConnexioBD::getInstance(PARAMS);	

	//string query = "SELECT * FROM visualitzacio_capitol WHERE sobrenom_usuari = '" + sobrenom + "'";

	string query = "SELECT COUNT(DISTINCT titol_serie) AS total FROM visualitzacio_capitol WHERE sobrenom_usuari = '" + sobrenom + "'";
	ResultSet* res = conn.executarConsulta(query);

	// Solo se tiene en cuenta las series vistas, no se tiene en cuenta las veces que ves una misma serie
	if (res->next()) {
		num_visualitzacionsSer = res->getInt("total");  // Obtiene el total de películas vistas
	}

	/*while (res->next()) {
		num_visualitzacionsSer += res->getInt("num_visualitzacions");  // Sumar las visualizaciones
	}*/ // este cuenta todas las visualizaciones incluyendo si has vuelto a ver una serie

	return num_visualitzacionsSer;
}