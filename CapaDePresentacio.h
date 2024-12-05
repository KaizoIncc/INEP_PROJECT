#pragma once
#include <iostream>
#include "CapaDeDomini.h"

using namespace std;

class CapaDePresentacio {
private:

	CapaDePresentacio() {};

	~CapaDePresentacio();

public:

	static CapaDePresentacio& getInstance();	

	bool processarIniciarSessio();

	bool processarTancarSessio();

	void processarRegistrarUsuari();

	void processarConsultarUsuari();

	void processarModificarUsuari();

	void processarEsborrarUsuari();

};

