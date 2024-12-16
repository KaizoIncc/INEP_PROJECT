#pragma once
#include "PassarelaVisualitzaCapitol.h"

class CercadoraVisualitzaSerie {
private:

	int num_visualitzacionsSer;

public:

	CercadoraVisualitzaSerie();

	~CercadoraVisualitzaSerie();

	int cercaVisualitzacions(string sobrenom);

	vector<PassarelaVisualitzaCapitol> cercaPerSobreNomST(string sobrenom, string titolSerie, int numeroTemporada);

	PassarelaVisualitzaCapitol cercaPerVisualitzacio(string sobrenom, string titolSerie, int numeroTemporada, int numeroCapitol);
};