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

void PassarelaUsuari::insereix() {
	ConnexioBD& conn = ConnexioBD::getInstance(PARAMS);

	// Crear consulta SQL
	string query = "INSERT INTO usuari (sobrenom, nom, contrasenya, correu_electronic, data_naixement, subscripcio) "
		"VALUES ('" + sobrenom + "', '" + nom + "', '" + contrasenya + "', '" + correuElectronic + "', '" +
		dataNaixement + "', '" + subscripcio + "')";

	// Executar comanda
	conn.executarComanda(query);
}


void PassarelaUsuari::modifica() {
	ConnexioBD& conn = ConnexioBD::getInstance(PARAMS);
	string query = "UPDATE usuari SET nom = '" + nom + "', contrasenya = '" + contrasenya + "', correu_electronic = '" + correuElectronic + "', data_naixement = '" + dataNaixement + "', subscripcio = '" + subscripcio + "';";
	conn.executarComanda(query);
}

void PassarelaUsuari::esborra() {
	ConnexioBD& conn = ConnexioBD::getInstance(PARAMS);
	string query = "DELETE FROM usuari WHERE (sobrenom = '" + sobrenom + "')";
	conn.executarComanda(query);
}
