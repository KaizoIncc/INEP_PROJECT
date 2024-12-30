#include "PassarelaPelicula.h"

PeliculaInfo::PeliculaInfo(string titolP, string qualificacioEdatsP, int duracioP, int numVisualitzacionsP, string dataVisualitzacioP) {
	titol = titolP;
	qualificacioEdats = qualificacioEdatsP;
	duracio = duracioP;
	numVisualitzacions = numVisualitzacionsP;
	dataVisualitzacio = dataVisualitzacioP;
}

PeliculaInfo::PeliculaInfo(string titolP, string data_estrenaP, string duracioP)
{
	titol = titolP;
	data_estrena = data_estrenaP;
	duracioS = duracioP;
}

PeliculaInfo::PeliculaInfo() {
	titol = "";
	qualificacioEdats = "";
	duracio = 0;
	numVisualitzacions = 0;
	dataVisualitzacio = "";
}

PeliculaInfo::~PeliculaInfo() {

}

string PeliculaInfo::getTitol() {
	return titol;
}

string PeliculaInfo::getQualificacioEdats() {
	return qualificacioEdats;
}

int PeliculaInfo::getDuracio() {
	return duracio;
}

int PeliculaInfo::getNumVisualitzacions() {
	return numVisualitzacions;
}

string PeliculaInfo::getDataVisualitzacio() {
	return dataVisualitzacio;
}

string PeliculaInfo::getDataE() {
	return data_estrena;
}

string PeliculaInfo::getDuracioS() {
	return duracioS;
}

void PeliculaInfo::setTitol(string titolP) {
	titol = titolP;
}

void PeliculaInfo::setQualificacioEdats(string qualificacioP) {
	qualificacioEdats = qualificacioP;
}

void PeliculaInfo::setDuracio(int duracioP) {
	duracio = duracioP;
}

void PeliculaInfo::setNumVisualitzacions(int numP) {
	numVisualitzacions = numP;
}

void PeliculaInfo::setDataVisualitzacio(string dataP) {
	dataVisualitzacio = dataP;
}