#include "PassarelaCapitol.h"

//Constructora
PassarelaCapitol::PassarelaCapitol(string titolSerie, int numeroTemporadaS, int numeroC, string titolC, string dataEstrenaC, string qualificacioC) {
	titolS = titolSerie;
	numeroTemporada = numeroTemporadaS;
	numeroCap = numeroC;
	titolCap = titolC;
	dataEstrena = dataEstrenaC;
	qualificacio = qualificacioC;
}

//Constructora per defecte 
PassarelaCapitol::PassarelaCapitol() {

}

//Destructora
PassarelaCapitol::~PassarelaCapitol() {

}

//Getters
int PassarelaCapitol::getNumeroC() {
	return numeroCap; 
}

string PassarelaCapitol::getTitolCap() {
	return titolCap; 
}

string PassarelaCapitol::getDataEstrena() {
	return dataEstrena; 
}

string PassarelaCapitol::getQualificacio() {
	return qualificacio; 
}

string PassarelaCapitol::getNumeroTemporada()
{
	return to_string(numeroTemporada);
}

string PassarelaCapitol::getTitolSerie()
{
	return titolS;
}