#include "TxConsultaSerie.h"

TxConsultaSerie::TxConsultaSerie(string titol) {
	titolS = titol;
}

TxConsultaSerie::~TxConsultaSerie() {

}

void TxConsultaSerie::executar() {
    CercadoraContingut cercadora;
    PassarelaContingut contingut = cercadora.cercaPerTitol(titolS); 
    resultat = DTOSerie(contingut);
}

DTOSerie TxConsultaSerie::obteResultat() {
	return resultat;
}