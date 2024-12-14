#pragma once
#include <iostream>
#include "ConnexioBD.h"
#include "config.txt"

class CercadoraVisualitzaPel {
private:

	int num_visualitzacionsPel;

public:

	CercadoraVisualitzaPel();

	~CercadoraVisualitzaPel();

	int cercaVisualitzacions(string sobrenom);
};