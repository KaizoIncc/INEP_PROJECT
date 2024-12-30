#include "DTOPeli.h"

//Constructora
DTOPeli::DTOPeli(string titolP, string descripcioP, string qualificacioP, string data_estrenaP, string duracioP) {
	titol = titolP;
	descripcio = descripcioP;
	qualificacio = qualificacioP;
	data_estrena = data_estrenaP;
	duracio = duracioP;
}

//Constructora per defecte (per poder posar una PassarelaUsuari com a atribut a la classe Petitflix)
DTOPeli::DTOPeli() {
}

//Destructora
DTOPeli::~DTOPeli() {
}

//Getters
string DTOPeli::getTitol() {
	return titol;
}

string DTOPeli::getDescripcio() {
	return descripcio;
}

string DTOPeli::getQualificacio() {
	return qualificacio;
}

string DTOPeli::getDataE() {
	return data_estrena;
}

string DTOPeli::getDuracio() {
	return duracio;
}

//Setters
void DTOPeli::setTitol(string titolP) {
	titol = titolP;
}

void DTOPeli::setDescripcio(string descripcioP) {
	descripcio = descripcioP;
}

void DTOPeli::setQualificacio(string qualificacioP) {
	qualificacio = qualificacioP;
}

void DTOPeli::setDataE(string data_estrenaP) {
	data_estrena = data_estrenaP;
}

void DTOPeli::setDuracio(string duracioP) {
	duracio = duracioP;
}