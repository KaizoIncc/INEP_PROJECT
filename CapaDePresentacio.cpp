#include <cstdlib>
#include "CapaDePresentacio.h"
#include "TxRegistrarUsuari.h"
#include <regex>
#include <ctime>
#include "TxEsborrarUsuari.h"
#include "TxTancaSessio.h"


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
	cout << "** Iniciar sessio **" << "\n";
	cout << "Sobrenom: ";
	cin >> sobrenomU;
	cout << "Contrasenya: ";
	cin >> contrasenyaU;
	TxIniciSessio iniSessio(sobrenomU, contrasenyaU);
	try {
		iniSessio.executar();		
	}
	catch (...) {
		cout << "Usuari o contrasenya incorrecta" << "\n";
	}
	if (iniSessio.obteResultat()) cout << "Sessio iniciada correctament!" << "\n";
	return iniSessio.obteResultat();
}

bool CapaDePresentacio::processarTancarSessio() {
	string resposta;
	system("CLS");
	cout << "** Tancar sessio **" << "\n";
	cout << "Vols tancar la sessio? (S/N) ";
	cin >> resposta;
	TxTancaSessio tancaSessio;
	if (resposta == "S" || resposta == "s") {		
		tancaSessio.executar();
		cout << "Sessio tancada correctament!" << "\n";
	}
	else if (resposta == "N") {
		cout << "\n";
		return true;
	}
	else {
		cout << "Has de contestar amb S o N!" << "\n";
	}
	return tancaSessio.obteResultat();
}

void CapaDePresentacio::processarRegistrarUsuari() {
	string nom, sobrenom, contrasenya, correuElectronic, dataNaixement, modalitatSubs;
	int opcio;
	cin.ignore();
	system("CLS");
	cout << "** Registrar usuari **" << "\n";
	cout << "Nom complet: ";
    getline(cin, nom);
	cout << "Sobrenom: ";
    getline(cin, sobrenom);
	cout << "Contrasenya: ";
    getline(cin, contrasenya);
	cout << "Correu electronic: ";
    getline(cin, correuElectronic);
	if (!comprovarCorreu(correuElectronic)) {
		cout << "Error: Correu no valid." << "\n\n";
		return;
	}
    // Validar fecha de nacimiento
    while (true) {
        cout << "Data de naixement (YYYY-MM-DD): ";
        getline(cin, dataNaixement);

        if (esDataValida(dataNaixement)) {
            break; // Salir del bucle si la fecha es válida
        }
        else {
            cout << "La data introduïda no és vàlida. Torna-ho a intentar." << "\n";
        }
    }

	cout << "Modalitats de subscripció disponibles" << "\n";
	cout << " > 1. Completa" << "\n";
	cout << " > 2. Cinefil" << "\n";
	cout << " > 3. Infantil" << "\n";
	cout << "Escull modalitat: ";
	cin >> opcio;
	switch (opcio) {
	case 1:
		modalitatSubs = "Completa";
		break;
	case 2:
		modalitatSubs = "Cinefil";
		break;
	case 3:
		modalitatSubs = "Infantil";
		break;
	default:
		cout << "Modalitat no existeix" << "\n";
		break;
	}
    TxRegistrarUsuari usuariRegistrat(nom, sobrenom, contrasenya, correuElectronic, dataNaixement, modalitatSubs);
	try {
		usuariRegistrat.executar();
	}
	catch (exception e) {
		cout << "Error: " << e.what() << "\n" << "\n";
		return;
	}
	cout << "Nou usuari registrat correctament!" << "\n" << "\n";
}

bool CapaDePresentacio::esDataValida(const string& dataNaixement) {
	// Verificar formato con regex
	regex dataRegex("^\\d{4}-\\d{2}-\\d{2}$");
	if (!regex_match(dataNaixement, dataRegex)) {
		return false; // El formato no coincide
	}

	// Extraer año, mes y día
	int any, mes, dia;
	sscanf(dataNaixement.c_str(), "%d-%d-%d", &any, &mes, &dia);

	// Validar rango básico de mes y día
	if (mes < 1 || mes > 12 || dia < 1 || dia > 31) {
		return false; // Rango inválido
	}

	// Crear una estructura tm
	tm data = {};
	data.tm_year = any - 1900; // tm_year cuenta desde 1900
	data.tm_mon = mes - 1;     // tm_mon va de 0 a 11
	data.tm_mday = dia;

	// Convertir a tiempo UNIX y verificar si se ajusta
	time_t t = mktime(&data);
	if (t == -1) {
		return false; // Conversión fallida
	}

	// Verificar si mktime ajustó la fecha
	if (data.tm_year != any - 1900 || data.tm_mon != mes - 1 || data.tm_mday != dia) {
		return false; // La fecha no era válida
	}

	// Obtener la fecha actual
	time_t tActual = time(0);
	tm* avui = localtime(&tActual);

	// Verificar si la fecha está en el futuro
	if (t > tActual) {
		return false; // La fecha es futura
	}

	return true; // La fecha es válida
}

bool CapaDePresentacio::processarEsborrarUsuari() {
	string contrasenya;
	bool sessio = true;
	system("CLS");
	wcout << "** Esborrar usuari **" << "\n";
	wcout << "Per confirmar l'esborrat, s'ha d'entrar la contrasenya ..." << "\n";
	wcout << "Contrasenya: ";
	cin>> contrasenya;

	TxEsborrarUsuari usuariEliminat(contrasenya);	
	try {
		usuariEliminat.executar();
		cout << "Usuari esborrat correctament!" << "\n";				
	}
	catch(const exception& e) {
		cout << e.what() << "\n";
	}

	return usuariEliminat.obteResultat();
}

/*void CapaDePresentacio::processarModificarUsuari() {
	system("CLS");
	string input;
	cout << "** Modifica usuari **" << "\n";
	CUModificaUsuari cuModificaUsuari;
	DTOUsuari usuari = cuModificaUsuari.consultaUsuari();
	cout << "Nom complet: " << usuari.getNom() << "\n";
	cout << "Sobrenom: " << usuari.getSobrenom() << "\n";
	cout << "Correu electronic " << usuari.getCorreuE() << "\n";
	cout << "Data naixement (DD/MM/AAAA): " << usuari.getDataN() << "\n";
	cout << "Modalitat subscripció: " << usuari.getSubscripcio() << "\n";
	cout << "*********************************************" << "\n";
	cout << "Omplir la informacio que es vol modificar ..." << "\n";
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
		cout << "** Dades usuari modificades **" << "\n";
		usuari = cuModificaUsuari.consultaUsuari();
		cout << "Nom complet: " << usuari.getNom() << "\n";
		cout << "Sobrenom: " << usuari.getSobrenom() << "\n";
		cout << "Correu electronic :" << usuari.getCorreuE() << "\n";
		cout << "Data naixement (DD/MM/AAAA): " << usuari.getDataN() << "\n";
		cout << "Modalitat subscripcio: " << usuari.getSubscripcio() << "\n";
	}
	catch ( std::exception e)
	{
		cout << "Error: " << e.what() << "\n";
	}
}*/