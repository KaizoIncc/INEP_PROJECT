#pragma once
#include <iostream>
#include <chrono>
#include <iomanip>
#include "PetitFlix.h"
#include "PassarelaPelicula.h"
#include "PassarelaCapitol.h"
#include "CercadoraPelicula.h"
#include "CercadoraCapitol.h"
#include "CercadoraContingut.h"
#include "CercadoraRelacionat.h"
#include "DTOProperesEstrenes.h"
#include "DTOCapitol.h"
#include "DTOPeli.h"

using namespace std;

class TxProperesEstrenes {

private:

	string modalitat;

	vector<DTOProperesEstrenes> estrenes;
	vector<PassarelaCapitol> capitols;
	vector<DTOPeli> pelicules;

public:

	//constructora
	TxProperesEstrenes(string nomP);
	TxProperesEstrenes();

	//destructora
	~TxProperesEstrenes();
	void executar();
	vector<DTOProperesEstrenes> obteResultat();

};