#pragma once

#include "ConnexioBD.h"
#include "config.txt"
#include "PassarelaVisualitzacioPelicula.h"
#include "PassarelaVisualitzacioSerie.h"
#include <vector>
using namespace std;

class CercadoraVisualitzacio {
private:

public:

	CercadoraVisualitzacio();

	~CercadoraVisualitzacio();

	vector<PasarelaVisualitzacioPelicula> obtenirVisualitzacionsPelicules(const string& correuU);

	vector<PasarelaVisualitzacioSerie> obtenirVisualitzacionsSeries(const string& correuU);
};