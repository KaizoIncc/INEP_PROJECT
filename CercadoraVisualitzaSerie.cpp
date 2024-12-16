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

vector<PassarelaVisualitzaCapitol> CercadoraVisualitzaSerie::cercaPerSobreNomST(string sobrenom, string titolSerie, int numeroTemporada) {
	vector<PassarelaVisualitzaCapitol> infoUsuari;
	ConnexioBD& con = ConnexioBD::getInstance(PARAMS);
	string sql = "SELECT titol_serie, num_temporada, num_capitol, DATE(data) AS data, num_visualitzacions "
		"FROM visualitzacio_capitol WHERE sobrenom_usuari = '" + sobrenom + "' AND titol_serie = '" + titolSerie + "' AND num_temporada = '" + to_string(numeroTemporada) + "' ";
	ResultSet* res = con.executarConsulta(sql);

	while (res->next()) {
		string titolSerie = res->getString("titol_serie");
		int numeroTemporada = res->getInt("num_temporada");
		int numeroC = res->getInt("num_capitol");
		string dataV = res->getString("data");
		int numV = res->getInt("num_visualitzacions");

		PassarelaVisualitzaCapitol infoU(titolSerie, numeroTemporada, numeroC, dataV, numV);

		infoUsuari.push_back(infoU);
	}
	delete res;
	return infoUsuari;
}

PassarelaVisualitzaCapitol CercadoraVisualitzaSerie::cercaPerVisualitzacio(string sobrenom, string titolSerie, int numeroTemporada, int numeroCapitol) {	
	ConnexioBD& con = ConnexioBD::getInstance(PARAMS);
	string sql = "SELECT titol_serie, num_temporada, num_capitol, data, num_visualitzacions FROM visualitzacio_capitol WHERE sobrenom_usuari = '" + sobrenom + "' AND titol_serie = '" + titolSerie + "' AND num_temporada = " + to_string(numeroTemporada) + " AND num_capitol = " + to_string(numeroCapitol);
	ResultSet* res = con.executarConsulta(sql);
	if (res->next()) {
		string titolSerie = res->getString("titol_serie");
		int numeroTemporada = res->getInt("num_temporada");
		int numeroC = res->getInt("num_capitol");
		string dataV = res->getString("data");
		int numV = res->getInt("num_visualitzacions");
		delete res;
		return PassarelaVisualitzaCapitol(titolSerie, numeroTemporada, numeroC, dataV, numV);
	}
	else {
	delete res; 
		return PassarelaVisualitzaCapitol("", -1, -1, "", -1); 
	}
}