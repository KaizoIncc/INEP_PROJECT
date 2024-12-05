#pragma once
#include <iostream>
#include "config.txt"

using namespace std;

class PassarelaUsuari {
private:

	string sobrenom, nom, contrasenya, correuElectronic, dataNaixement, subscripcio;

public:

	//Constructora
	PassarelaUsuari(string sobrenomU, string nomU, string contrasenyaU, string correuElectronicU, string dataNaixementU, string subscripcioU);

	//Constructora per defecte (per poder posar una passarelaUsuari com a atribut a la classe Petitflix)
	PassarelaUsuari();

	//Destructora
	~PassarelaUsuari();

	//Getters
	string getSobrenom();

	string getNom();	

	string getContrasenya();

	string getCorreuE();

	string getDataN();

	string getSubscripcio();

	//Setters
	void setNom(string nomU);	

	void setContrasenya(string contrasenyaU);

	void setCorreuE(string correuElectronicU);

	void setDataN(string dataNaixementU);

	void setSubscripcio(string subscripcioU);

	//Operacions sobre la BD
	void insereix();

	void modifica();

	void esborra();

};

