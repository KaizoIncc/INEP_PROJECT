#pragma once
#include <iostream>
#include "PetitFlix.h"

class TxTancaSessio {
private:

	bool sessioIniciada;

public:

	TxTancaSessio();

	~TxTancaSessio();

	void executar();

	bool obteResultat();
};
