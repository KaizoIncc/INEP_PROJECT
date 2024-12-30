#include "CUVisualitzarPeli.h"
#include <iostream>
#include <chrono>
#include <iomanip>

//constructora
CUVisualitzarPeli::CUVisualitzarPeli(string nomP) {
	this->nomP = nomP;
}

CUVisualitzarPeli::CUVisualitzarPeli() {}

//destructora
CUVisualitzarPeli::~CUVisualitzarPeli() {}

DTOPeli CUVisualitzarPeli::obteDTOPeli() {
	CercadoraContingut CercadoraContingut;
	PassarelaContingut contingut = CercadoraContingut.cercaContingutPeli(nomP);

	CercadoraPelicules CercadoraPelicula;
	PeliculaInfo Peli = CercadoraPelicula.cercaPerTitol(nomP);

	return DTOPeli(nomP, contingut.getDescripcio(), contingut.getQualificacio(), Peli.getDataE(), Peli.getDuracioS());
}

bool CUVisualitzarPeli::existeixP(DTOPeli p) {
	return p.getTitol() != "";
}

bool CUVisualitzarPeli::edat_adecuada(string data_naixamentU, string edatP) {
	auto now = chrono::system_clock::now();
	time_t current_time1 = chrono::system_clock::to_time_t(now);
	ostringstream tiempoActualStream;
	tiempoActualStream << put_time(localtime(&current_time1), "%Y-%m-%d %H:%M:%S");
	string tiempoActual = tiempoActualStream.str();										//data actual

	int anyU = stoi(data_naixamentU.substr(0, 4));
	int mesU = stoi(data_naixamentU.substr(5, 2));
	int diaU = stoi(data_naixamentU.substr(8, 2));

	int anyA = stoi(tiempoActual.substr(0, 4));
	int mesA = stoi(tiempoActual.substr(5, 2));
	int diaA = stoi(tiempoActual.substr(8, 2));

	int edad = anyA - anyU;

	if ((mesA < mesU) || (mesA == mesU && diaA < diaU)) {
		edad--;
	}
	int tamany = edatP.size();
	if (edatP == "TP") {
		return true;
	}
	else if (stoi(edatP.substr(0, tamany - 1)) < edad) {
		return false;
	}
	return true;
}

bool CUVisualitzarPeli::peli_estrenada(string data_estrenaP) {
	auto now = chrono::system_clock::now();
	time_t current_time1 = chrono::system_clock::to_time_t(now);
	ostringstream tiempoActualStream;
	tiempoActualStream << put_time(localtime(&current_time1), "%Y-%m-%d %H:%M:%S");
	string tiempoActual = tiempoActualStream.str();										//data actual

	int anyA = stoi(tiempoActual.substr(0, 4));
	int mesA = stoi(tiempoActual.substr(5, 2));
	int diaA = stoi(tiempoActual.substr(8, 2));

	int anyP = stoi(data_estrenaP.substr(0, 4));
	int mesP = stoi(data_estrenaP.substr(5, 2));
	int diaP = stoi(data_estrenaP.substr(8, 2));

	int estrena = anyA - anyP;
	if ((mesA < mesP) || (mesA == mesP && diaA < diaP)) {
		estrena--;
	}
	if (estrena < 0) {
		return false;
	}
	return true;
}

void CUVisualitzarPeli::visualitzarPeli()
{
	CercadoraVisualitzaPel cercadora = CercadoraVisualitzaPel();
	PetitFlix& petitflix = PetitFlix::getInstance();
	PassarelaUsuari usuari = petitflix.getUsuari();
	auto t = time(nullptr);
	std::tm* now = localtime(&t);
	char buffer[20];
	strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", now);
	string dataActual = buffer;
	PasarelaVisualitzacioPelicula VisuarlitzaPeli = cercadora.obtenirVisualitzarPeli(usuari.getSobrenom(), nomP);

	if (VisuarlitzaPeli.getNum_visualitzacionsPel() != "") {
		VisuarlitzaPeli.setSobrenom(usuari.getSobrenom());
		VisuarlitzaPeli.setNomP(nomP);
		VisuarlitzaPeli.setCurrent_time(dataActual);
		string numVisua = VisuarlitzaPeli.getNum_visualitzacionsPel();
		int num = stoi(numVisua) + 1;
		VisuarlitzaPeli.setNum_visualitzacionsPel(to_string(num));
		VisuarlitzaPeli.modificar_visualitzacio();
	}
	else {
		VisuarlitzaPeli.setSobrenom(usuari.getSobrenom());
		VisuarlitzaPeli.setNomP(nomP);
		VisuarlitzaPeli.setCurrent_time(dataActual);
		VisuarlitzaPeli.setNum_visualitzacionsPel("1");
		VisuarlitzaPeli.insereix();
	}
}