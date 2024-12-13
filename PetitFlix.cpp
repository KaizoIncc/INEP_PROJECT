#include "PetitFlix.h"

PetitFlix PetitFlix::getInstance() {
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

void PetitFlix::refrescarPantalla(string nomU, string contrasenyaU, string correuElectronicU, string dataNaixamentU, string modalitatU) {
	string correuAntic = usuari.getCorreuE();
	try {
		usuari.setNom(nomU);
		usuari.setContrasenya(contrasenyaU);
		usuari.setCorreuE(correuElectronicU);
		usuari.setDataN(dataNaixamentU);
		usuari.setSubscripcio(modalitatU);
		usuari.modifica();
	}
	catch (...) {
		usuari.setCorreuE(correuAntic);
		if (correuAntic != correuElectronicU) throw exception("Correu ja registrat.");
	}

}