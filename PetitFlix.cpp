#include "PetitFlix.h"

PetitFlix& PetitFlix::getInstance() {
	static PetitFlix instance;
	return instance;
}

PassarelaUsuari PetitFlix::getUsuari() {
	return usuari;
}

void PetitFlix::iniciarSessio(PassarelaUsuari userP) {
	usuari = userP;
}

void PetitFlix::tancarSessio() {

}