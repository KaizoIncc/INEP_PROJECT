#pragma once
#include <iostream>
#include "ConnexioBD.h"
#include "PassarelaVisualitzacioPelicula.h"
#include "config.txt"

class CercadoraVisualitzaPel {
private:

	int num_visualitzacionsPel;

public:

	CercadoraVisualitzaPel();

	~CercadoraVisualitzaPel();

	int cercaVisualitzacions(string sobrenom);

	PasarelaVisualitzacioPelicula obtenirVisualitzarPeli(string sobrenom, string nomP);
};