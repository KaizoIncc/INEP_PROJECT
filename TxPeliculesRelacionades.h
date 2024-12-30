#pragma once
#include <iostream>
#include "PetitFlix.h"
#include "PassarelaPelicula.h"
#include "CercadoraPelicula.h"
#include "CercadoraContingut.h"
#include "CercadoraRelacionat.h"
#include "DTOPeli.h"

using namespace std;

class TxPeliculesRelacionades {

private:

	string nomP;
	vector<string> relacionats;

public:

	//constructora
	TxPeliculesRelacionades(string nomP);

	//destructora
	~TxPeliculesRelacionades();

	void executar();
	vector<DTOPeli> obteResultat();
};