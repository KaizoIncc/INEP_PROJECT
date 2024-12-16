#include "CercadoraCapitol.h"

CercadoraCapitol::CercadoraCapitol() {

}

CercadoraCapitol::~CercadoraCapitol() {

}

vector<PassarelaCapitol> CercadoraCapitol::cercaPerTemporada(string titolSerie, int numeroTemporada) {    
        vector<PassarelaCapitol> capitols;
        ConnexioBD& con = ConnexioBD::getInstance(PARAMS);
        // Consulta SQL para buscar todos los capítulos de una temporada específica
        string sql = "SELECT titol_serie, numero_temporada, numero, titol, DATE(data_estrena) AS data_estrena, qualificacio FROM capitol "
            "WHERE titol_serie = '" + titolSerie + "' AND numero_temporada = " + to_string(numeroTemporada) +
            " ORDER BY numero DESC";
        ResultSet* res = con.executarConsulta(sql);

        // Bucle para iterar sobre las filas del ResultSet        
        while (res->next()) {            
            string titolSerie = res->getString("titol_serie");
            int numeroTemporada = res->getInt("numero_temporada");
            int numero = res->getInt("numero");
            string titol = res->getString("titol");
            string dataEstrena = res->getString("data_estrena");
            string qualificacio = res->getString("qualificacio");
            
            PassarelaCapitol infoCapitol(titolSerie, numeroTemporada, numero, titol, dataEstrena, qualificacio);
            
            capitols.push_back(infoCapitol);
        }
        delete res;
        return capitols;
}