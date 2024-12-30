#pragma once

#include "PassarelaPelicula.h"
#include "PassarelaUsuari.h"
#include "DTOPeli.h"
#include "config.txt"
#include "ConnexioBD.h"
#include "PetitFlix.h"
#include <string>
#include <vector>

class CercadoraPelicules {
private:
	
public:
	CercadoraPelicules();

	vector<PeliculaInfo> obtenirTopPelicules(int limit);

	PeliculaInfo cercaPerTitol(string titol);

	vector<PeliculaInfo> cercaPerEstrena(string dataA);

	vector<DTOPeli> cercaPerEstrenaInfantil(string dataA);
};