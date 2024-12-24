#include "CercadoraPelicula.h"

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