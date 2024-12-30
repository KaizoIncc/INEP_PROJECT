#include "CercadoraVisualitzaPel.h"

CercadoraVisualitzaPel::CercadoraVisualitzaPel() {

}

CercadoraVisualitzaPel::~CercadoraVisualitzaPel() {

}

int CercadoraVisualitzaPel::cercaVisualitzacions(string sobrenom) {
	ConnexioBD& conn = ConnexioBD::getInstance(PARAMS);

	//string query = "SELECT * FROM visualitzacio_pelicula WHERE sobrenom_usuari = '" + sobrenom + "'";

	string query = "SELECT COUNT(DISTINCT titol_pelicula) AS total FROM visualitzacio_pelicula WHERE sobrenom_usuari = '" + sobrenom + "'";
	ResultSet* res = conn.executarConsulta(query);

	// Solo se tiene en cuenta las peliculas vistas, no se tiene en cuenta las veces que ves una misma pelicula
	if (res->next()) {
		num_visualitzacionsPel = res->getInt("total");  // Obtiene el total de películas vistas
	}

	/*while (res->next()) {
		num_visualitzacionsPel += res->getInt("num_visualitzacions");  // Sumar las visualizaciones
	}*/ // este cuenta todas las visualizaciones incluyendo si has vuelto a ver una pelicula

	return num_visualitzacionsPel;
}

PasarelaVisualitzacioPelicula CercadoraVisualitzaPel::obtenirVisualitzarPeli(string sobrenom, string nomP)
{
	PasarelaVisualitzacioPelicula Vp;
	ConnexioBD& con = ConnexioBD::getInstance(PARAMS);
	string sql = "SELECT * FROM inep06.visualitzacio_pelicula WHERE sobrenom_usuari = '" + sobrenom + "' AND titol_pelicula = '" + nomP +"'";
	ResultSet* res = con.executarConsulta(sql);
	// Si no troba cap fila, activa excepció
	if (!res->next()) {
		return Vp;
	}
	else {
		Vp = PasarelaVisualitzacioPelicula(res->getString("sobrenom_usuari"), res->getString("titol_pelicula"), res->getString("data"), res->getString("num_visualitzacions"));
		delete res;
	}
	return Vp;
}