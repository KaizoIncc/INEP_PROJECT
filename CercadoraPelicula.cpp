#include "CercadoraPelicula.h"

CercadoraPelicules::CercadoraPelicules()
{
}

vector<PeliculaInfo> CercadoraPelicules::obtenirTopPelicules(int limit) {
    vector<PeliculaInfo> pelicules;
    try {
        ConnexioBD& conn = ConnexioBD::getInstance(PARAMS);
        PassarelaUsuari usuari = PetitFlix::getInstance().getUsuari();

        // Consulta SQL
        string query = "SELECT p.titol AS titol_pelicula, q.nom, p.duracio, SUM(v.num_visualitzacions) AS total_visualitzacions, MAX(v.data) AS data "
            "FROM pelicula p "
            "JOIN contingut c ON p.titol = c.titol "
            "JOIN visualitzacio_pelicula v ON c.titol = v.titol_pelicula "
            "JOIN qualificacio_edat q ON c.qualificacio = q.nom "
            "GROUP BY p.titol, q.nom, p.duracio "
            "ORDER BY total_visualitzacions DESC "
            "LIMIT " + to_string(limit) + ";";

        // Ejecutar consulta
        ResultSet* res = conn.executarConsulta(query);

        while (res->next()) {
            PeliculaInfo pelicula;
            pelicula.setTitol(res->getString("titol_pelicula"));
            pelicula.setQualificacioEdats(res->getString("nom"));
            pelicula.setDuracio(res->getInt("duracio"));
            pelicula.setNumVisualitzacions(res->getInt("total_visualitzacions"));
            pelicula.setDataVisualitzacio(res->getString("data"));

            // Si hay un usuario logueado, verificamos la fecha de visualización
            string usuariSobrenom = usuari.getSobrenom();
            if (!usuariSobrenom.empty()) {
                string subQuery = "SELECT MAX(v.data) AS data_visualitzacio "
                                  "FROM visualitzacio_pelicula v "
                                  "WHERE v.titol_pelicula = '" + pelicula.getTitol() + "' "
                                  "AND v.sobrenom_usuari = '" + usuariSobrenom + "';";

                ResultSet* subRes = conn.executarConsulta(subQuery);
                if (subRes->next()) {
                    string dataVisualitzacio = subRes->getString("data_visualitzacio");
                    pelicula.setDataVisualitzacio(dataVisualitzacio);
                }
                delete subRes;
            }


            pelicules.push_back(pelicula);
        }

        delete res; // Liberar el resultado
    }
    catch (const runtime_error& e) {
        throw runtime_error("Error en obtenir les pelicules mes vistes: " + string(e.what()));
    }
    catch (const sql::SQLException& e) {
        cerr << "Error SQL: " << e.what() << "\n";
        cerr << "Codi SQLState: " << e.getSQLState() << "\n";
        cerr << "Codi d'error: " << e.getErrorCode() << "\n";
        throw; // Propaga l'excepció per a la seva gestió posterior
    }

    return pelicules;
}

PeliculaInfo CercadoraPelicules::cercaPerTitol(string titolP) {
    PeliculaInfo p;
    ConnexioBD& con = ConnexioBD::getInstance(PARAMS);
    string sql = "SELECT * FROM inep06.pelicula WHERE titol = '" + titolP + "'";
    ResultSet* res = con.executarConsulta(sql);
    // Si no troba cap fila, activa excepció
    if (!res->next()) {
        throw runtime_error("Pelicula no existeix");
    }
    else {
        p = PeliculaInfo(res->getString("titol"), res->getString("data_estrena"), res->getString("duracio"));
        delete res;
    }
    return p;
}

vector<PeliculaInfo> CercadoraPelicules::cercaPerEstrena(string dataA)
{
    vector<PeliculaInfo> estrena;
    ConnexioBD& con = ConnexioBD::getInstance(PARAMS);
    // Consulta SQL para buscar todos los capítulos de una temporada específica
    string sql = "SELECT * FROM inep06.pelicula WHERE data_estrena > '" + dataA + "' ORDER BY data_estrena ASC LIMIT 5;";
    ResultSet* res = con.executarConsulta(sql);
    // Bucle para iterar sobre las filas del ResultSet        
    while (res->next()) {
        string titol = res->getString("titol");
        string data_estrena = res->getString("data_estrena");
        string duracio = res->getString("duracio");
        estrena.push_back(PeliculaInfo(titol, data_estrena, duracio));
    }
    return estrena;
}

vector<DTOPeli> CercadoraPelicules::cercaPerEstrenaInfantil(string dataA)
{
    vector<DTOPeli> estrena;
    ConnexioBD& con = ConnexioBD::getInstance(PARAMS);
    // Consulta SQL para buscar todos los capítulos de una temporada específica
    string sql = "SELECT p.titol, p.data_estrena, p.duracio, c.descripcio, c.qualificacio FROM inep06.pelicula p JOIN inep06.contingut c"
        " ON p.titol = c.titol WHERE p.data_estrena > '" + dataA + "' AND c.qualificacio != '18+' ORDER BY p.data_estrena ASC LIMIT 5";
    ResultSet* res = con.executarConsulta(sql);
    // Bucle para iterar sobre las filas del ResultSet        
    while (res->next()) {
        string titol = res->getString("titol");
        string data_estrena = res->getString("data_estrena");
        string duracio = res->getString("duracio");
        string descripcio = res->getString("descripcio");
        string qualificacio = res->getString("qualificacio");
        estrena.push_back(DTOPeli(titol, descripcio, qualificacio, data_estrena, duracio));
    }
    return estrena;
}