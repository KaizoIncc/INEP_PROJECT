#pragma once
#include "CercadoraVisualitzaPel.h"
#include "CercadoraVisualitzaSerie.h"
#include "PetitFlix.h"

class TxInfoVisualitzacions {
private:
	int resultat;

public:
	TxInfoVisualitzacions();

	void executar();

	int obteResultat();

	void mostrarInformacio();
};