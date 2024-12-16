#include "DTOTemporada.h"

DTOTemporada::DTOTemporada() {

}

DTOTemporada::DTOTemporada(string titolS, int numeroT) {
	titol = titolS;
	numTemporada = numeroT;	
}

DTOTemporada::DTOTemporada(PassarelaTemporada serie) {
	titol = serie.getTitol();
	numTemporada = serie.getNumeroT();
}

int DTOTemporada::getTemporada() {
	return numTemporada;
}