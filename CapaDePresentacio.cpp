#include "CapaDePresentacio.h"


CapaDePresentacio& CapaDePresentacio::getInstance() {
	static CapaDePresentacio instance;
	return instance;
}

CapaDePresentacio::~CapaDePresentacio() {

}

bool CapaDePresentacio::processarIniciarSessio() {
	string sobrenomU, nomU, correuU, contrasenyaU;
	bool sessio = false;
	cout << "** Iniciar sessio **" << endl;
	cout << "Sobrenom: ";
	cin >> sobrenomU;;
	cout << "Contrasenya: ";
	cin >> contrasenyaU;
	CapaDeDomini& domini = CapaDeDomini::getInstance();
	try {
		domini.iniciarSessio(sobrenomU, contrasenyaU);		
	}
	catch (const exception& e) {
		cout << "Error: " << e.what() << endl;
	}

}