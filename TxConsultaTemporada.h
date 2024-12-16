#pragma once
#include "PassarelaTemporada.h"
#include "CercadoraTemporada.h"
#include "DTOTemporada.h"

class TxConsultaTemporada {
private:

	string titolS;
	DTOTemporada resultat;
	int temporadesTotals;

public:

	TxConsultaTemporada(string titol);

	~TxConsultaTemporada();

	void executar();

	DTOTemporada obteResultat();

	int obteTemporadesT();

};

