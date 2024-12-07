#include "CapaDePresentacio.h"
#include "TxRegistrarUsuari.h"

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
	cin >> sobrenomU;; // ;;?? con una no basta?
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

void CapaDePresentacio::processarRegistrarUsuari() {
	string nom, sobrenom, contrasenya, correuElectronic, dataNaixement, modalitatSubs;

	cout << "Introdueix el nom de l'usuari: ";
	getline(cin, nom);

	cout << "Introdueix el sobrenom de l'usuari: ";
	getline(cin, sobrenom);

	cout << "Introdueix la contrasenya: ";
	getline(cin, contrasenya);

	cout << "Introdueix el correu electrònic: ";
	getline(cin, correuElectronic);

	cout << "Introdueix la data de naixement (YYYY-MM-DD): ";
	getline(cin, dataNaixement);

	cout << "Introdueix la modalitat de subscripció (BASICA, PREMIUM, VIP): ";
	getline(cin, modalitatSubs);

	TxRegistrarUsuari usuariRegistrat(nom, sobrenom, contrasenya, correuElectronic, dataNaixement, modalitatSubs);

	usuariRegistrat.executar();
}