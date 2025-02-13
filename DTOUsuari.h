#pragma once
#include "PassarelaUsuari.h"

class DTOUsuari {
private:

	string sobrenom, nom, contrasenya, correuElectronic, dataNaixement, subscripcio;

public:

	DTOUsuari();

	DTOUsuari(string sobrenomU, string nomU, string contrasenyaU, string correuElectronicU, string dataNaixementU, string subscripcioU);

	DTOUsuari(PassarelaUsuari usuari);

	string getSobrenom();

	string getNom();

	string getContrasenya();

	string getCorreuE();

	string getDataN();

	string getSubscripcio();

};

