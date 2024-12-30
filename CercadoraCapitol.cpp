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

vector<PassarelaCapitol> CercadoraCapitol::cercaPerEstrena(string dataA)
{
    vector<PassarelaCapitol> capitols;
    ConnexioBD& con = ConnexioBD::getInstance(PARAMS);
    // Consulta SQL
    string sql = "SELECT* FROM inep06.capitol WHERE data_estrena > '" + dataA + "' AND"
        " numero = (SELECT MIN(numero) FROM inep06.capitol c2 WHERE c2.titol_serie = capitol.titol_serie AND c2.data_estrena > '" + dataA + "' "
        ") ORDER BY data_estrena ASC LIMIT 5";
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
vector<PassarelaCapitol> CercadoraCapitol::cercaPerEstrenaInfantil(string dataA) {
    vector<PassarelaCapitol> capitols;
    ConnexioBD& con = ConnexioBD::getInstance(PARAMS);
    // Consulta SQL 
    string sql = "SELECT* FROM inep06.capitol WHERE data_estrena > '" + dataA + "' AND qualificacio != '18 +' AND"
        " numero = (SELECT MIN(numero) FROM inep06.capitol c2 WHERE c2.titol_serie = capitol.titol_serie AND c2.data_estrena > '" + dataA + "' "
        "AND c2.qualificacio != '18+') ORDER BY data_estrena ASC LIMIT 5";
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
