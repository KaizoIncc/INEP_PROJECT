#include "PassarelaTemporada.h"

//Constructora
PassarelaTemporada::PassarelaTemporada(string titolSerie, int numero) {
	titolS = titolSerie;
	numeroT = numero;
}

//Constructora per defecte 
PassarelaTemporada::PassarelaTemporada() {

}

//Destructora
PassarelaTemporada::~PassarelaTemporada() {

}

//Getters
string PassarelaTemporada::getTitol() {
	return titolS;
}

int PassarelaTemporada::getNumeroT() {
	return numeroT;
}