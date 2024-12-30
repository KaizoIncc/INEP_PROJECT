#include "TxPeliculesRelacionades.h"
#include "PetitFlix.h"
#include "CercadoraPelicula.h"
#include <iostream>
#include <chrono>
#include <iomanip>

//constructora
TxPeliculesRelacionades::TxPeliculesRelacionades(string nomP) {
	this->nomP = nomP;
}

//destructora
TxPeliculesRelacionades::~TxPeliculesRelacionades() {}


void TxPeliculesRelacionades::executar() {
	CercadoraRelacionat CercadoraRelac;
	relacionats = CercadoraRelac.cercaRelacionats(nomP);
}

vector<DTOPeli> TxPeliculesRelacionades::obteResultat() {
	vector<DTOPeli> pelicules_relacionades;
	for (int i = 0; i < relacionats.size(); i++) {
		CercadoraContingut CercadoraContingut;
		PassarelaContingut contingut = CercadoraContingut.cercaContingutPeli(relacionats[i]);
		CercadoraPelicules CercadoraPelicula;
		PeliculaInfo Peli = CercadoraPelicula.cercaPerTitol(relacionats[i]);
		pelicules_relacionades.push_back(DTOPeli(nomP, contingut.getDescripcio(), contingut.getQualificacio(), Peli.getDataE(), Peli.getDuracioS()));
	}
	return pelicules_relacionades;
}