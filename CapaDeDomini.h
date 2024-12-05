#pragma once
#include <iostream>
#include "CercadoraUsuari.h"
#include "PetitFlix.h"

using namespace std;

class CapaDeDomini {
private:

	CapaDeDomini() {};

	~CapaDeDomini();

	bool sessioIniciada = false;

public:

	static CapaDeDomini& getInstance();

	void iniciarSessio(string sobrenom, string contrasenya);

	bool obteResultat() const;
};

