#include "PassarelaContingut.h"

//Constructora
PassarelaContingut::PassarelaContingut(string titolC, string descripcioC, string qualificacioC, string tipusC) {
	titol = titolC;
	descripcio = descripcioC;
	qualificacio = qualificacioC;
	tipus = tipusC;
}

//Constructora per defecte 
PassarelaContingut::PassarelaContingut() {

}

//Destructora
PassarelaContingut::~PassarelaContingut() {

}

//Getters
string PassarelaContingut::getTitol() {
	return titol;
}

string PassarelaContingut::getDescripcio() {
	return descripcio;
}

string PassarelaContingut::getQualificacio() {
	return qualificacio;
}

string PassarelaContingut::getTipus() {
	return tipus;
}
