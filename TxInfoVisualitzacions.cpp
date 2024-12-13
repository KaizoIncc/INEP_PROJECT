#include "TxInfoVisualitzacions.h"

TxInfoVisualitzacions::TxInfoVisualitzacions() : resultat() {}

void TxInfoVisualitzacions::executar() {
	CercadoraVisualitzaPel visualitzaP;
	CercadoraVisualitzaSerie visualitzaS;

	string sobrenom = PetitFlix::getInstance().getUsuari().getSobrenom();

	resultat = visualitzaP.cercaVisualitzacions(sobrenom) + visualitzaS.cercaVisualitzacions(sobrenom);
}

int TxInfoVisualitzacions::obteResultat() {
	return resultat;
}

void TxInfoVisualitzacions::mostrarInformacio() {
	cout << "Numero total de visualitzacions: " << this->obteResultat() << endl;
}