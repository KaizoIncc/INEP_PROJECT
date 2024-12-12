#pragma once
#include <iostream>
#include <regex>
#include "TxIniciSessio.h"
#include "CUModificaUsuari.h"

using namespace std;

class CapaDePresentacio {
private:

	CapaDePresentacio() {};

	~CapaDePresentacio();

	bool comprovarCorreu(string correu);

public:

	static CapaDePresentacio& getInstance();	

	bool processarIniciarSessio();

	bool processarTancarSessio();

	void processarRegistrarUsuari();

	void processarConsultarUsuari();

	void processarModificarUsuari();

	void processarEsborrarUsuari();

};

