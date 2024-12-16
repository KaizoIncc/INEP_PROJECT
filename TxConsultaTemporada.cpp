#include "TxConsultaTemporada.h"

TxConsultaTemporada::TxConsultaTemporada(string titol) {
	titolS = titol;
}

TxConsultaTemporada::~TxConsultaTemporada() {

}

void TxConsultaTemporada::executar() {
	CercadoraTemporada cercadora;
	PassarelaTemporada temporada = cercadora.cercaPerTemporada(titolS);
	resultat = DTOTemporada(temporada);

	temporadesTotals = cercadora.cercaTemporadesTotales(titolS);
}

DTOTemporada TxConsultaTemporada::obteResultat() {
	return resultat;
}

int TxConsultaTemporada::obteTemporadesT() {
	return temporadesTotals;
}