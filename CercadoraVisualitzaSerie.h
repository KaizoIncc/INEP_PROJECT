#pragma once
#include "ConnexioBD.h"
#include "config.txt"

class CercadoraVisualitzaSerie {
private:

public:

	CercadoraVisualitzaSerie();

	~CercadoraVisualitzaSerie();

	int cercaVisualitzacions(const string& sobrenom);
};