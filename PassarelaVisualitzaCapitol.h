#pragma once
#include <iostream>
#include "ConnexioBD.h"
#include "config.txt"

using namespace std;

class PassarelaVisualitzaCapitol {
private:

	string sobrenom, titolS, dataVisualitzacio;

	int numTemporada, numCapitol, numVisualitzacions;

public:

	PassarelaVisualitzaCapitol(string titolSerie, int numT, int numC, string dataV, int numV);

	PassarelaVisualitzaCapitol(string sobrenomU, string titolSerie, int numT, int numC, string dataV, int numV);

	PassarelaVisualitzaCapitol();

	~PassarelaVisualitzaCapitol();

	//Getters
	string getSobrenom();

	string getTitol();

	int getNumeroT();

	int getNumeroC();	

	string getDataV();

	int getNumeroV();

	void insereix();

	void actualitza();

	//Setters
	void setData(string data);

	void setNumV(int numV);
};

