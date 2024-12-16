#include "DTOVisualitzacioCapitol.h"

DTOVisualitzacioCapitol::DTOVisualitzacioCapitol() {

}

DTOVisualitzacioCapitol::DTOVisualitzacioCapitol(string titolSerie, int numeroTemporada, int numeroCapitol, string dataVisualitzacio, int numeroVisualitzacio) {
	titolS = titolSerie;
	numeroT = numeroTemporada;
	numeroC = numeroCapitol;
	dataV = dataVisualitzacio;
	numeroV = numeroVisualitzacio;
}

DTOVisualitzacioCapitol::DTOVisualitzacioCapitol(PassarelaVisualitzaCapitol visualitzacio) {
	sobrenom = visualitzacio.getSobrenom();
	titolS = visualitzacio.getTitol();
	numeroT = visualitzacio.getNumeroT();
	numeroC = visualitzacio.getNumeroC();
	dataV = visualitzacio.getDataV();
	numeroV = visualitzacio.getNumeroV();
}

//Getters
string DTOVisualitzacioCapitol::getTitolSerie() {
	return titolS;
}

int DTOVisualitzacioCapitol::getNumeroTemporada() {
	return numeroT;
}

int DTOVisualitzacioCapitol::getNumeroCapitol() {
	return numeroC;
}

string DTOVisualitzacioCapitol::getDataVisualitzacio() {
	return dataV;
}

int DTOVisualitzacioCapitol::getNumeroVisualitzacio() {
	return numeroV;
}