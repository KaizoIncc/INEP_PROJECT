#pragma once
#include <iostream>
#include "CercadoraUsuari.h"
#include "PetitFlix.h"

using namespace std;

class TxIniciSessio {
private:	

	string sobrenom, contrasenya;
	bool sessioIniciada;

public:

	TxIniciSessio(string sobrenomU, string contrasenyaU);

	~TxIniciSessio();		

	void executar();

	bool obteResultat() ;
};

