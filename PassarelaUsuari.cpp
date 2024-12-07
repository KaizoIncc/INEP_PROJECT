#include "PassarelaUsuari.h"

//Constructora
PassarelaUsuari::PassarelaUsuari(string sobrenomU, string nomU, string contrasenyaU, string correuElectronicU, string dataNaixementU, string subscripcioU) {
	sobrenom = sobrenomU;
	nom = nomU;
	contrasenya = contrasenyaU;
	correuElectronic = correuElectronicU;
	dataNaixement = dataNaixementU;
	subscripcio = subscripcioU;
}

//Constructora per defecte (per poder posar una PassarelaUsuari com a atribut a la classe Petitflix)
PassarelaUsuari::PassarelaUsuari() {

}

//Destructora

PassarelaUsuari::~PassarelaUsuari() {

}

//Getters
string PassarelaUsuari::getSobrenom() {
	return sobrenom;
}

string PassarelaUsuari::getNom() {
	return nom;
}

string PassarelaUsuari::getContrasenya() {
	return contrasenya;
}

string PassarelaUsuari::getCorreuE() {
	return correuElectronic;
}

string PassarelaUsuari::getDataN() {
	return dataNaixement;
}

string PassarelaUsuari::getSubscripcio() {
	return subscripcio;
}

//Setters
void PassarelaUsuari::setNom(string nomU) {
	nom = nomU;
}

void PassarelaUsuari::setContrasenya(string contrasenyaU) {
	contrasenya = contrasenyaU;
}

void PassarelaUsuari::setCorreuE(string correuElectronicU) {
	correuElectronic = correuElectronicU;
}

void PassarelaUsuari::setDataN(string dataNaixementU) {
	dataNaixement = dataNaixementU;
}
void PassarelaUsuari::setSubscripcio(string subscripcioU) {
	subscripcio = subscripcioU;
}

//Operacions sobre la BD
void PassarelaUsuari::insereix() {
	ConnexioBD& conn = ConnexioBD::getInstance(PARAMS);
	string query = "INSERT INTO usuaris (nom, sobrenom, contrasenya, correu_electronic, data_naixement, modalitat_subs) "
		"VALUES ('" + nom + "', '" + sobrenom + "', '" + contrasenya + "', '" + correuElectronic + "', '" +
		dataNaixement + "', '" + subscripcio + "')";
	conn.executarComanda(query);
}

void PassarelaUsuari::modifica() {
	
}

void PassarelaUsuari::esborra() {
	
}