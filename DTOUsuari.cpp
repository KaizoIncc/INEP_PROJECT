#include "DTOUsuari.h"

DTOUsuari::DTOUsuari() {

}

DTOUsuari::DTOUsuari(string sobrenomU, string nomU, string contrasenyaU, string correuElectronicU, string dataNaixementU, string subscripcioU) {
	sobrenom = sobrenomU; 
	nom = nomU; 
	contrasenya = contrasenyaU;
	correuElectronic = correuElectronicU;
	dataNaixement = dataNaixementU;
	subscripcio = subscripcioU;
}

DTOUsuari::DTOUsuari(PassarelaUsuari usuari) {
	sobrenom = usuari.getSobrenom();
	nom = usuari.getNom();
	contrasenya = usuari.getContrasenya();
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
string DTOUsuari::getContrasenya() {
	return contrasenya;
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
