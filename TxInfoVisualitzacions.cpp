#include "TxInfoVisualitzacions.h"

TxInfoVisualitzacions::TxInfoVisualitzacions() {

}

TxInfoVisualitzacions::~TxInfoVisualitzacions() {

}

void TxInfoVisualitzacions::executar() {
	CercadoraVisualitzaPel visualitzaP = CercadoraVisualitzaPel();
	CercadoraVisualitzaSerie visualitzaS = CercadoraVisualitzaSerie();

	PetitFlix& petitflix = PetitFlix::getInstance();
	PassarelaUsuari usuari = petitflix.getUsuari();

	string sobrenom = PetitFlix::getInstance().getUsuari().getSobrenom();

	int nVisualitzaP = visualitzaP.cercaVisualitzacions(usuari.getSobrenom());
	resultat.visualitzacions.push_back(nVisualitzaP);

	int nVisualitzaS = visualitzaS.cercaVisualitzacions(usuari.getSobrenom());
	resultat.visualitzacions.push_back(nVisualitzaS);
	
}

TxInfoVisualitzacions::res TxInfoVisualitzacions::obteResultat() {
	return resultat;
}
