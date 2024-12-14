#pragma once
#include "ConnexioBD.h"
#include "config.txt"

class CercadoraVisualitzaSerie {
private:

	int num_visualitzacionsSer;

public:

	CercadoraVisualitzaSerie();

	~CercadoraVisualitzaSerie();

	int cercaVisualitzacions(string sobrenom);
};