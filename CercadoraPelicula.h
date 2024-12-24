#pragma once

#include "PassarelaPelicula.h"
#include "PassarelaUsuari.h"
#include "config.txt"
#include "ConnexioBD.h"
#include "PetitFlix.h"
#include <string>
#include <vector>

class CercadoraPelicules {
private:
	
public:
	vector<PeliculaInfo> obtenirTopPelicules(int limit);
};