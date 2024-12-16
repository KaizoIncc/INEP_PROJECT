#include "DTOCapitol.h"

DTOCapitol::DTOCapitol() {

}

DTOCapitol::DTOCapitol(int numeroC, string titolC, string dataEstrenaC, string qualificacioC) {
	numero = numeroC;
	titol = titolC;
	dataEstrena = dataEstrenaC;
	qualificacio = qualificacioC;
}

DTOCapitol::DTOCapitol(PassarelaCapitol capitol) {
	numero = capitol.getNumeroC();
	titol = capitol.getTitolCap();
	dataEstrena = capitol.getDataEstrena();
	qualificacio = capitol.getQualificacio();
}

//Getters
int DTOCapitol::getNumeroC() {
	return numero;
}

string DTOCapitol::getTitol() {
	return titol; 
}

string DTOCapitol::getDataEstrena() {
	return dataEstrena; 
}

string DTOCapitol::getQualificacio() {
	return qualificacio; 
}