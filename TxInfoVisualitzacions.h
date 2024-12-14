#pragma once
#include "CercadoraVisualitzaPel.h"
#include "CercadoraVisualitzaSerie.h"
#include "PetitFlix.h"

class TxInfoVisualitzacions {
public:
	TxInfoVisualitzacions();

	~TxInfoVisualitzacions();

	struct res {	

		vector<int> visualitzacions;	
	};

	void executar();

	res obteResultat();

private:

	res resultat;
};