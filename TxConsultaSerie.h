#pragma once
#include "PassarelaContingut.h"
#include "CercadoraContingut.h"
#include "DTOSerie.h"

class TxConsultaSerie {
private:

	string titolS;
	DTOSerie resultat;

public:

	TxConsultaSerie(string titol);

	~TxConsultaSerie();

	void executar();

	DTOSerie obteResultat();

};

