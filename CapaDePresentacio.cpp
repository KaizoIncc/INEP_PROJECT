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

bool CapaDePresentacio::processarTancarSessio() {
	string resposta;
	cout << "Vols tancar la sessio? (S/N)";
	cin >> resposta;
	if (resposta == "S" || resposta == "s") {
		TxTancaSessio tancaSessio;
		try {
			tancaSessio.executar();
		}
		catch (const exception& e) {
			cout << "La sessio no s ha pogut tancar" << endl;
		}
		return tancaSessio.obteResultat();
	}
}

void CapaDePresentacio::processarRegistrarUsuari() {
    string nom, sobrenom, contrasenya, correuElectronic, dataNaixement, modalitatSubs;
/*void CapaDePresentacio::processarRegistrarUsuari() {
	string nom, sobrenom, contrasenya, correuElectronic, dataNaixement, modalitatSubs;

    cout << "Introdueix el nom de l'usuari: ";
    cin.ignore();
    getline(cin, nom);

    cout << "Introdueix el sobrenom de l'usuari: ";
    getline(cin, sobrenom);

    cout << "Introdueix la contrasenya: ";
    getline(cin, contrasenya);

    cout << "Introdueix el correu electronic: ";
    getline(cin, correuElectronic);

    // Validar fecha de nacimiento
    while (true) {
        cout << "Introdueix la data de naixement (YYYY-MM-DD): ";
        getline(cin, dataNaixement);

        if (esDataValida(dataNaixement)) {
            break; // Salir del bucle si la fecha es válida
        }
        else {
            cout << "La data introduïda no és vàlida. Torna-ho a intentar." << endl;
        }
    }

    // Validar modalitat
    while (true) {
        cout << "Introdueix la modalitat de subscripcio (Cinefil, Infantil, Completa): ";
        getline(cin, modalitatSubs);

        if (esModalitatValida(modalitatSubs)) {
            break; // Si la modalitat és vàlida, sortir del bucle
        }
        else {
            cout << "Modalitat no vàlida. Torna-ho a intentar." << endl;
        }
    }

    TxRegistrarUsuari usuariRegistrat(nom, sobrenom, contrasenya, correuElectronic, dataNaixement, modalitatSubs);

    usuariRegistrat.executar();
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

    // Obtener la fecha actual
    time_t t = time(0);
    tm* avui = localtime(&t);
    int anyActual = avui->tm_year + 1900;
    int mesActual = avui->tm_mon + 1;
    int diaActual = avui->tm_mday;

    // Verificar si la fecha está en el futuro
    if (any > anyActual ||
        (any == anyActual && mes > mesActual) ||
        (any == anyActual && mes == mesActual && dia > diaActual)) {
        return false; // La fecha es futura
    }

    // Si la fecha es válida y no está en el futuro, es válida
    return true;
}

// Método privado para validar la modalidad
bool CapaDePresentacio::esModalitatValida(const string& modalitatSubs) {
    // Validar modalidad según la lógica de negocio (aquí simplemente es un ejemplo)
    const vector<string> modalitatsValides = { "Cinefil", "Infantil", "Completa" };
    return find(modalitatsValides.begin(), modalitatsValides.end(), modalitatSubs) != modalitatsValides.end();
}
	usuariRegistrat.executar();
}
*/

bool CapaDePresentacio::processarEsborrarUsuari() {
	string contrasenya;
	bool sessio = true;
	system("CLS");
	wcout << "** Esborrar usuari **\n";
	wcout << "Per confirmar l'esborrat, s'ha d'entrar la contrasenya ...\n";
	wcout << "Contrasenya: ";

	cin>> contrasenya;

	TxEsborrarUsuari usuariEliminat(contrasenya);
	TxTancaSessio tancaSessio;
	try {
		usuariEliminat.executar();
		cout << "Usuari esborrat correctament!\n";
		tancaSessio.executar();
		sessio = tancaSessio.obteResultat();
	}
	catch(const exception& e) {
		cout << "L'usuari no s'esborrat correctament!" << endl;

	}

	return sessio; 
}

void disableEcho() {
	system("stty -echo");  // Desactivar la visualización
}

void enableEcho() {
	system("stty echo");  // Activar la visualización
}


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