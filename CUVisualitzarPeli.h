#pragma once
#include <iostream>
#include "PetitFlix.h"
#include "PassarelaPelicula.h"
#include "CercadoraPelicula.h"
#include "CercadoraUsuari.h"
#include "CercadoraVisualitzaPel.h"
#include "CercadoraContingut.h"
#include "DTOPeli.h"

using namespace std;

class CUVisualitzarPeli {

private:

	string nomP;

public:

	//constructora
	CUVisualitzarPeli(string nomP);
	CUVisualitzarPeli();

	//destructora
	~CUVisualitzarPeli();

	DTOPeli obteDTOPeli();
	bool existeixP(DTOPeli p);
	bool edat_adecuada(string data_naixamentU, string edatP);
	bool peli_estrenada(string data_estrenaP);
	void visualitzarPeli();
};