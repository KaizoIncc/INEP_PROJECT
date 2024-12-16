#include "DTOSerie.h"

DTOSerie::DTOSerie() {

}

DTOSerie::DTOSerie(string titolS, string descripcioS, string qualificacioS) {
	titol = titolS;
	descripcio = descripcioS;
	qualificacio = qualificacioS;
}

DTOSerie::DTOSerie(PassarelaContingut serie) {
	titol = serie.getTitol();
	descripcio = serie.getDescripcio();
	qualificacio = serie.getQualificacio();
}

//Getters
string DTOSerie::getTitol() {
	return titol;
}

string DTOSerie::getDescripcio() {
	return descripcio;
}

string DTOSerie::getQualificacio() {
	return qualificacio;
}