#include "TxConsultaCapitol.h"

TxConsultaCapitol::TxConsultaCapitol(string titol, int temporada) {
    titolS = titol;
    temporadaS = temporada;
}

TxConsultaCapitol::~TxConsultaCapitol() {

}

void TxConsultaCapitol::executar() {
    CercadoraCapitol cercadora = CercadoraCapitol();
    vector<PassarelaCapitol> capitolsP = cercadora.cercaPerTemporada(titolS, temporadaS);    
    for (auto& capitol : capitolsP) {
        DTOCapitol infoCapitol(capitol.getNumeroC(), capitol.getTitolCap(), capitol.getDataEstrena(), capitol.getQualificacio());
        resultat.push_back(infoCapitol);
    }    
}

vector<DTOCapitol> TxConsultaCapitol::obteResultat() {
    return resultat;
}