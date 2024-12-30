#pragma once
#include "PassarelaCapitol.h"

class CercadoraCapitol {
private:

public:

	CercadoraCapitol();

	~CercadoraCapitol();

	vector<PassarelaCapitol> cercaPerTemporada(string titolSerie, int numeroTemporada);

	vector<PassarelaCapitol> cercaPerEstrena(string dataA);

	vector<PassarelaCapitol> cercaPerEstrenaInfantil(string dataA);

};

