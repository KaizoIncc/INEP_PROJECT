#include "CapaDePresentacio.h"
#include "TxRegistrarUsuari.h"


CapaDePresentacio& CapaDePresentacio::getInstance() {
	static CapaDePresentacio instance;
	return instance;
}

CapaDePresentacio::~CapaDePresentacio() {

}

bool CapaDePresentacio::comprovarCorreu(string correu) {
	regex pattern(R"(^[_a-z0-9-]*@[a-z0-9-]+(\.[a-z]{2,4})+$)");
	return regex_match(correu, pattern);
}

bool CapaDePresentacio::processarIniciarSessio() {
	string sobrenomU, contrasenyaU;
	bool sessio = false;
	system("CLS");
	cout << "** Iniciar sessio **" << endl;
	cout << "Sobrenom: ";
	cin >> sobrenomU;
	cout << "Contrasenya: ";
	cin >> contrasenyaU;
	TxIniciSessio iniSessio(sobrenomU, contrasenyaU);
	try {
		iniSessio.executar();		
	}
	catch (const exception& e) {
		cout << "Usuari o contrasenya incorrecta" << endl;
	}
	if (iniSessio.obteResultat()) cout << "Sessio iniciada correctament!" << endl;
	return iniSessio.obteResultat();
}

/*void CapaDePresentacio::processarRegistrarUsuari() {
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
}*/

/*void CapaDePresentacio::processarModificarUsuari() {
	system("CLS");
	string input;
	cout << "** Modifica usuari **" << endl;
	CUModificaUsuari cuModificaUsuari;
	DTOUsuari usuari = cuModificaUsuari.consultaUsuari();
	cout << "Nom complet: " << usuari.getNom() << endl;
	cout << "Sobrenom: " << usuari.getSobrenom() << endl;
	cout << "Correu electronic " << usuari.getCorreuE() << endl;
	cout << "Data naixement (DD/MM/AAAA): " << usuari.getDataN() << endl;
	cout << "Modalitat subscripció: " << usuari.getSubscripcio() << endl;
	cout << "*********************************************" << endl;
	cout << "Omplir la informacio que es vol modificar ..." << endl;
	cout << "Nom complet: ";
	cin >> input;
	if (input.size() != 0) usuari.getNom() = input;
	cout << "Contrasenya: ";
	cin >> input;
	if (input.size() != 0) usuari.getContrasenya() = input;
	cout << "Correu electronic: ";
	cin >> input;
	if (comprovarCorreu(input)) usuari.getCorreuE() = input;
	cout << "Data naixement (DD/MM/AAAA): ";
	cin >> input;
	if (input.size() != 0) usuari.getDataN() = input;
	cout << "Modalitat subscripcio: ";
	cin >> input;
	if (input.size() != 0) usuari.getSubscripcio() = input;

	try
	{
		cuModificaUsuari.modificarUsuari(usuari.getNom(), usuari.getContrasenya(), usuari.getCorreuE(), usuari.getDataN(), usuari.getSubscripcio();
		cout << "** Dades usuari modificades **" << endl;
		usuari = cuModificaUsuari.consultaUsuari();
		cout << "Nom complet: " << usuari.getNom() << endl;
		cout << "Sobrenom: " << usuari.getSobrenom() << endl;
		cout << "Correu electronic :" << usuari.getCorreuE() << endl;
		cout << "Data naixement (DD/MM/AAAA): " << usuari.getDataN() << endl;
		cout << "Modalitat subscripcio: " << usuari.getSubscripcio() << endl;
	}
	catch (const std::exception& e)
	{
		cout << "Error: " << e.what() << endl;
	}
}*/