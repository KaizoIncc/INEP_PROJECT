#pragma once
#include <iostream>
#include "ConnexioBD.h"
#include "config.txt"

using namespace std;

class DTOPeli {

private:

	string titol, descripcio, qualificacio, data_estrena, duracio;

public:

	//Constructora
	DTOPeli(string titolP, string descripcioP, string qualificacioP, string data_estrenaP, string duracioP);

	//Constructora per defecte (per poder posar una passarelaUsuari com a atribut a la classe Petitflix)
	DTOPeli();

	//Destructora
	~DTOPeli();

	//Getters
	string getTitol();
	string getDescripcio();
	string getQualificacio();
	string getDataE();
	string getDuracio();

	//Setters
	void setTitol(string titolP);
	void setDescripcio(string descripcioP);
	void setQualificacio(string qualificacioP);
	void setDataE(string data_estrenaP);
	void setDuracio(string duracioP);
};