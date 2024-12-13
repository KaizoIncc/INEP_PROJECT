#include "TxTancaSessio.h"


TxTancaSessio::TxTancaSessio() {
	sessioIniciada = true;
}

TxTancaSessio::~TxTancaSessio() {

}

void TxTancaSessio::executar() {
	PetitFlix petitflix = PetitFlix::getInstance();
	petitflix.tancarSessio();
	sessioIniciada = false;
}

bool TxTancaSessio::obteResultat() {
	return sessioIniciada;
}
