#pragma once
#include "TxConsultaSerie.h"
#include "TxConsultaTemporada.h"
#include "TxConsultaCapitol.h"
#include "TxVisualitzaCapitol.h"
#include "DTOSerie.h"
#include "DTOCapitol.h"
#include "DTOVisualitzacioCapitol.h"

class CUVisualitzarCapitol {
private:

	DTOVisualitzacioCapitol resultat;

public:

	CUVisualitzarCapitol();

	~CUVisualitzarCapitol();

	DTOSerie consultaSerie(string serieNom);

	int consultaTemporadaS(string serieNom);

	vector<DTOCapitol> consultaCapitol(string serieNom, int numTemporada);

	vector<DTOVisualitzacioCapitol> consultaVisualitzacioC(string serieNom, int numTemporada);

	void visualitzarCapitol(string titolS, int numT, int numC);

	DTOVisualitzacioCapitol obteResultat();
	
};

