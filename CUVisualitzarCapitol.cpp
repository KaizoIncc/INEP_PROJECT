#include "CUVisualitzarCapitol.h"

CUVisualitzarCapitol::CUVisualitzarCapitol() {

}

CUVisualitzarCapitol::~CUVisualitzarCapitol() {

}

DTOSerie CUVisualitzarCapitol::consultaSerie(string serieNom) {
	TxConsultaSerie operacio(serieNom);
	operacio.executar();
	return operacio.obteResultat();
}

int CUVisualitzarCapitol::consultaTemporadaS(string serieNom) {
	TxConsultaTemporada operacio(serieNom);
	operacio.executar();
	return operacio.obteTemporadesT();
}

vector<DTOCapitol> CUVisualitzarCapitol::consultaCapitol(string serieNom, int numTemporada) {
	TxConsultaCapitol operacio(serieNom, numTemporada);
	operacio.executar();
	return operacio.obteResultat();
}

vector<DTOVisualitzacioCapitol> CUVisualitzarCapitol::consultaVisualitzacioC(string serieNom, int numTemporada) {
	TxVisualitzaCapitol operacio(serieNom, numTemporada);
	operacio.executar();
	return operacio.obteResultat();
}

void CUVisualitzarCapitol::visualitzarCapitol(string titolS, int numT, int numC) {
	CercadoraVisualitzaSerie cercadora = CercadoraVisualitzaSerie();
	PetitFlix& petitflix = PetitFlix::getInstance();
	PassarelaUsuari usuari = petitflix.getUsuari();
	auto t = time(nullptr);
	std::tm* now = localtime(&t);
	char buffer[20];
	strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", now);
	string dataActual = buffer;
	resultat = DTOVisualitzacioCapitol(cercadora.cercaPerVisualitzacio(usuari.getSobrenom(), titolS, numT, numC));
	if (resultat.getNumeroCapitol() == -1) {
		PassarelaVisualitzaCapitol visualitzacio(usuari.getSobrenom(), titolS, numT, numC, dataActual, 1);
		visualitzacio.insereix();
		resultat = DTOVisualitzacioCapitol(visualitzacio);
	}
	else {
		PassarelaVisualitzaCapitol visualitzacio(usuari.getSobrenom(), titolS, numT, numC, dataActual, resultat.getNumeroVisualitzacio());
		visualitzacio.setData(dataActual);
		visualitzacio.setNumV(resultat.getNumeroVisualitzacio() + 1);
		visualitzacio.actualitza();
		resultat = DTOVisualitzacioCapitol(visualitzacio);
	}
}

DTOVisualitzacioCapitol CUVisualitzarCapitol::obteResultat() {
	return resultat;
}