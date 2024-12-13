#include "DTOUsuari.h"

DTOUsuari::DTOUsuari() {
	sobrenom = "";
	nom = ""; 
	correuElectronic = "";
	dataNaixement = "";  
	subscripcio = "";
}

DTOUsuari::DTOUsuari(string sobrenomU, string nomU, string correuElectronicU, string dataNaixementU, string subscripcioU) {
	sobrenom = sobrenomU; 
	nom = nomU; 
	correuElectronic = correuElectronicU;
	dataNaixement = dataNaixementU;
	subscripcio = subscripcioU;
}

DTOUsuari::DTOUsuari(PassarelaUsuari usuari) {
	sobrenom = usuari.getSobrenom();
	nom = usuari.getNom();
	correuElectronic = usuari.getCorreuE();
	dataNaixement = usuari.getDataN();
	subscripcio = usuari.getSubscripcio();
}

//Getters
string DTOUsuari::getSobrenom() {
	return sobrenom;
}

string DTOUsuari::getNom() {
	return nom;
}

string DTOUsuari::getCorreuE() {
	return correuElectronic;
}

string DTOUsuari::getDataN() {
	return dataNaixement;
}

string DTOUsuari::getSubscripcio() {
	return subscripcio;
}

void DTOUsuari::mostrarInformacio() const {
	cout << "Nom: " << nom << endl;
	cout << "Sobrenom: " << sobrenom << endl;
	cout << "Correu Electronic: " << correuElectronic << endl;
	cout << "Data de naixement: " << dataNaixement << endl;
	cout << "Modalitat de Suscripcio: " << subscripcio << endl;
}