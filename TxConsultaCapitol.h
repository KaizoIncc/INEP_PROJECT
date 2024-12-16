#pragma once
#include "PassarelaCapitol.h"
#include "CercadoraCapitol.h"
#include "DTOCapitol.h"

class TxConsultaCapitol {
private:

	string titolS;
	int temporadaS;
	vector<DTOCapitol> resultat;

public:

	TxConsultaCapitol(string titol, int temporada);

	~TxConsultaCapitol();

	void executar();

	vector<DTOCapitol> obteResultat();

};

