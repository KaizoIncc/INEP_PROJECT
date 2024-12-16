#include "TxVisualitzaCapitol.h"

TxVisualitzaCapitol::TxVisualitzaCapitol(string titol, int temporada) {
	titolS = titol;
	temporadaS = temporada;
}

TxVisualitzaCapitol::~TxVisualitzaCapitol() {

}

void TxVisualitzaCapitol::executar() {
	CercadoraVisualitzaSerie cercadora = CercadoraVisualitzaSerie();
	PetitFlix& petitflix = PetitFlix::getInstance();
	PassarelaUsuari usuari = petitflix.getUsuari();

	vector<PassarelaVisualitzaCapitol> serieP = cercadora.cercaPerSobreNomST(usuari.getSobrenom(), titolS, temporadaS);
	for (auto& infoS : serieP) {
		DTOVisualitzacioCapitol infoVisualitzacio(infoS.getTitol(), infoS.getNumeroT(), infoS.getNumeroC(), infoS.getDataV(), infoS.getNumeroV());
		resultat.push_back(infoVisualitzacio);
	}
}

vector<DTOVisualitzacioCapitol> TxVisualitzaCapitol::obteResultat() {
	return resultat;
}