#pragma once
#include <iostream>
#include "PassarelaUsuari.h"

class PetitFlix {
private:

	PassarelaUsuari usuari;

	PetitFlix() {}

public:

	static PetitFlix getInstance();

	PassarelaUsuari getUsuari();

	void iniciarSessio(PassarelaUsuari userP);

	void tancarSessio();
	
	void refrescarPantalla(string nomU, string contrasenyaU, string correuElectronicU, string dataNaixamentU, string modalitatU);
};

