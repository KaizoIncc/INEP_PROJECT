#include "DTOProperesEstrenes.h"

//Constructora
DTOProperesEstrenes::DTOProperesEstrenes(string data_estrena, string tipus, string titol, string qualificacio, string duracio_nTemporada) {
	this->data_estrena = data_estrena;
	this->tipus = tipus;
	this->titol = titol;
	this->qualificacio = qualificacio;
	this->duracio_nTemporada = duracio_nTemporada;
}

//Constructora per defecte (per poder posar una PassarelaUsuari com a atribut a la classe Petitflix)
DTOProperesEstrenes::DTOProperesEstrenes() {
}

//Destructora
DTOProperesEstrenes::~DTOProperesEstrenes() {
}

//Getters
string DTOProperesEstrenes::getDataE() {
	return data_estrena;
}

string DTOProperesEstrenes::getTipus() {
	return tipus;
}

string DTOProperesEstrenes::getTitol() {
	return titol;
}

string DTOProperesEstrenes::getQualificacio() {
	return qualificacio;
}

string DTOProperesEstrenes::getDuracio_nTemporada() {
	return duracio_nTemporada;
}
