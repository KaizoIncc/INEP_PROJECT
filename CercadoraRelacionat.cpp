#include "CercadoraRelacionat.h"

CercadoraRelacionat::CercadoraRelacionat() {
}

CercadoraRelacionat::~CercadoraRelacionat() {
}

vector<string> CercadoraRelacionat::cercaRelacionats(string titolP) {
    vector<string> relacionats;
    ConnexioBD& con = ConnexioBD::getInstance(PARAMS);

    // Consulta SQL para buscar todos los capítulos de una temporada específica
    string sql = "SELECT titol_y FROM inep06.relacionat WHERE titol_x = '" + titolP + "'";

    ResultSet* res = con.executarConsulta(sql);
    // Bucle para iterar sobre las filas del ResultSet        
    while (res->next()) {
        string titolSerie = res->getString("titol_y");
        relacionats.push_back(titolSerie);
    }

    delete res;

    return relacionats;
}