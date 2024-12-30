#pragma once
#include <iostream>
#include "ConnexioBD.h"
#include "config.txt"

using namespace std;

class DTOProperesEstrenes {

private:

	string data_estrena, tipus, titol, qualificacio, duracio_nTemporada;

public:

	//Constructora
	DTOProperesEstrenes(string data_estrena, string tipus, string titol, string qualificacio, string duracio_nTemporada);

	//Constructora per defecte (per poder posar una passarelaUsuari com a atribut a la classe Petitflix)
	DTOProperesEstrenes();

	//Destructora
	~DTOProperesEstrenes();

	//Getters
	string getDataE();

	string getTipus();

	string getTitol();

	string getQualificacio();

	string getDuracio_nTemporada();
};