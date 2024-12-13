#pragma once
#include <iostream>
#include "CercadoraUsuari.h"
#include "PetitFlix.h"

using namespace std;

class TxTancaSessio {
private:

	bool sessioIniciada;

public:

	TxTancaSessio();

	~TxTancaSessio();

	void executar();

	bool obteResultat() const;
};
