#pragma once
#include <iostream>
#include "ConnexioBD.h"
#include "config.txt"

class CercadoraVisualitzaPel {
private:

public:

	CercadoraVisualitzaPel();

	~CercadoraVisualitzaPel();

	int cercaVisualitzacions(const string& sobrenom);
};