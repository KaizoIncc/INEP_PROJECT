#pragma once
#include "PassarelaVisualitzaCapitol.h"
#include "CercadoraVisualitzaSerie.h"
#include "DTOVisualitzacioCapitol.h"
#include "PetitFlix.h"
#include "PassarelaUsuari.h"

class TxVisualitzaCapitol {
private:

	string titolS;
	int temporadaS;
	vector<DTOVisualitzacioCapitol> resultat;

public:

	TxVisualitzaCapitol(string titol, int temporada);

	~TxVisualitzaCapitol();

	void executar();

	vector<DTOVisualitzacioCapitol> obteResultat();
};

