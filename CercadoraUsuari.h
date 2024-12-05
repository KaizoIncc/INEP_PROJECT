#pragma once
#include <iostream>
#include "PassarelaUsuari.h"
#include "ConnexioBD.h"

class CercadoraUsuari {
private:

public:

	CercadoraUsuari();

	~CercadoraUsuari();

	PassarelaUsuari cercaPerSobrenom(string sobrenom);
};

