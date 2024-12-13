#pragma once
#include "PassarelaUsuari.h"

class DTOUsuari {
private:

	string sobrenom, nom, correuElectronic, dataNaixement, subscripcio;

public:

	DTOUsuari();

	DTOUsuari(string sobrenomU, string nomU, string correuElectronicU, string dataNaixementU, string subscripcioU);

	DTOUsuari(PassarelaUsuari usuari);

	string getSobrenom();

	string getNom();

	string getCorreuE();

	string getDataN();

	string getSubscripcio();

	// M�todo para mostrar informaci�n (opcional)
	void mostrarInformacio() const;
};

