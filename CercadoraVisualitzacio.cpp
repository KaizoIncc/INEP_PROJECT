#include "CercadoraVisualitzacio.h"

CercadoraVisualitzacio::CercadoraVisualitzacio() {

}

CercadoraVisualitzacio::~CercadoraVisualitzacio() {

}

// Obtener visualizaciones de películas
vector<PasarelaVisualitzacioPelicula> CercadoraVisualitzacio::obtenirVisualitzacionsPelicules(const string& sobrenom) {
    ConnexioBD& connexio = ConnexioBD::getInstance(PARAMS);
    vector<PasarelaVisualitzacioPelicula> llistaPelicules;

    string consultaSQL =
        "SELECT v.data, p.titol, c.descripcio, c.qualificacio, v.num_visualitzacions "
        "FROM visualitzacio_pelicula v "
        "JOIN pelicula p ON v.titol_pelicula = p.titol "
        "JOIN contingut c ON p.titol = c.titol "
        "WHERE v.sobrenom_usuari = '" + sobrenom + "' "
        "ORDER BY v.data DESC";

    try {
        ResultSet* res = connexio.executarConsulta(consultaSQL);
        while (res->next()) {
            string data = res->getString("data");
            string titol = res->getString("titol");
            string descripcio = res->getString("descripcio");
            string qualificacio = res->getString("qualificacio");
            int vegades = res->getInt("num_visualitzacions");

            llistaPelicules.emplace_back(data, titol, descripcio, qualificacio, vegades);
        }
        delete res;
    }
    catch (const exception& e) {
        cerr << "Error obtenint visualitzacions de pel·lícules: " << e.what() << endl;
    }

    return llistaPelicules;
}

// Obtener visualizaciones de series
vector<PasarelaVisualitzacioSerie> CercadoraVisualitzacio::obtenirVisualitzacionsSeries(const string& sobrenom) {
    ConnexioBD& connexio = ConnexioBD::getInstance(PARAMS);
    vector<PasarelaVisualitzacioSerie> llistaSeries;

    string consultaSQL =
        "SELECT v.data, s.titol, c.numero_temporada, c.numero, c.qualificacio, v.num_visualitzacions "
        "FROM visualitzacio_capitol v "
        "JOIN capitol c ON v.titol_serie = c.titol_serie "
        "AND v.num_temporada = c.numero_temporada "
        "AND v.num_capitol = c.numero "
        "JOIN serie s ON c.titol_serie = s.titol "
        "WHERE v.sobrenom_usuari = '" + sobrenom + "' "
        "ORDER BY v.data DESC";

    try {
        ResultSet* res = connexio.executarConsulta(consultaSQL);
        while (res->next()) {
            string data = res->getString("data");
            string titolSerie = res->getString("titol");
            int numTemporada = res->getInt("numero_temporada");
            int numCapitol = res->getInt("numero");
            string qualificacio = res->getString("qualificacio");
            int vegades = res->getInt("num_visualitzacions");

            llistaSeries.emplace_back(data, titolSerie, numTemporada, numCapitol, qualificacio, vegades);
        }
        delete res;
    }
    catch (const exception& e) {
        cerr << "Error obtenint visualitzacions de sèries: " << e.what() << endl;
    }

    return llistaSeries;
}
