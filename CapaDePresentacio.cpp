#include "CapaDePresentacio.h"


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
	cin.ignore();
	string sobrenomU, contrasenyaU;
	bool sessio = false;
	system("CLS");
	cout << "** Iniciar sessio **" << "\n";
	cout << "Sobrenom: ";
	getline(cin, sobrenomU);
	cout << "Contrasenya: ";
	getline(cin, contrasenyaU);
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
	cin.ignore();
	string resposta;
	system("CLS");
	cout << "** Tancar sessio **" << "\n";
	cout << "Vols tancar la sessio? (S/N) ";
	getline(cin, resposta);
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
        cout << "Data de naixement (DD-MM-YYYY): ";
        getline(cin, dataNaixement);

        if (esDataValida(dataNaixement)) {
            break; // Salir del bucle si la fecha es v�lida
        }
        else {
            cout << "La data introdu�da no �s v�lida. Torna-ho a intentar." << "\n";
        }
    }

	cout << "Modalitats de subscripci� disponibles" << "\n";
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
	// Verificar formato con regex para DD-MM-YYYY
	regex dataRegex("^\\d{2}-\\d{2}-\\d{4}$");
	if (!regex_match(dataNaixement, dataRegex)) {
		return false; // El formato no coincide
	}

	// Extraer d�a, mes y a�o
	int dia, mes, any;
	sscanf(dataNaixement.c_str(), "%d-%d-%d", &dia, &mes, &any);

	// Validar rango b�sico de mes y d�a
	if (mes < 1 || mes > 12 || dia < 1 || dia > 31) {
		return false; // Rango inv�lido
	}

	// Crear una estructura tm
	tm data = {};
	data.tm_year = any - 1900; // tm_year cuenta desde 1900
	data.tm_mon = mes - 1;     // tm_mon va de 0 a 11
	data.tm_mday = dia;

	// Convertir a tiempo UNIX y verificar si se ajusta
	time_t t = mktime(&data);
	if (t == -1) {
		return false; // Conversi�n fallida
	}

	// Verificar si mktime ajust� la fecha
	if (data.tm_year != any - 1900 || data.tm_mon != mes - 1 || data.tm_mday != dia) {
		return false; // La fecha no era v�lida
	}

	// Obtener la fecha actual
	time_t tActual = time(0);
	tm* avui = localtime(&tActual);

	// Verificar si la fecha est� en el futuro
	if (t > tActual) {
		return false; // La fecha es futura
	}

	return true; // La fecha es v�lida
}


bool CapaDePresentacio::processarEsborrarUsuari() {
	cin.ignore();
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

void CapaDePresentacio::processarConsultarUsuari() {
	cin.ignore();
	system("CLS");
	cout << "** Consulta usuari **" << "\n";
	// Crear una instancia de la transacci�n TxConsultaUsuari
	TxConsultaUsuari consulta;
	try {
		// Ejecutar la transacci�n
		consulta.executar();
	}
	catch (const exception& e) {
		cout << "Error: " << e.what() << "\n" << "\n";
	}
	
	// Obtener el resultado como un DTOUsuari
	DTOUsuari resultat = consulta.obteResultat();
	cout << "Nom complet: " << resultat.getNom() << "\n";
	cout << "Sobrenom: " << resultat.getSobrenom() << "\n";
	cout << "Correu electronic: " << resultat.getCorreuE() << "\n";
	cout << "Data naixement (DD/MM/AAAA): " << resultat.getDataN() << "\n";
	cout << "Modalitat subscripcio: " << resultat.getSubscripcio() << "\n";
	cout << "\n";

	// Crear una instancia de la transaccion TxInfoVisualitzacions
	TxInfoVisualitzacions visualitzacions;
	try {
		// Ejecutar la transacci�n
		visualitzacions.executar();
		TxInfoVisualitzacions::res infoVisualitzacions = visualitzacions.obteResultat();
		cout << infoVisualitzacions.visualitzacions[0] << " pelicules visualitzades." << "\n";
		cout << infoVisualitzacions.visualitzacions[1] << " capitols visualitzades." << "\n\n";
	}
	catch (const exception& e) {
		cout << "Error: " << e.what() << "\n" << "\n";
	}	
	
}

void CapaDePresentacio::processarModificarUsuari() {
	cin.ignore();
	system("CLS");
	string input;
	cout << "** Modifica usuari **" << "\n";
	CUModificaUsuari cuModificaUsuari;
	DTOUsuari usuari = cuModificaUsuari.consultaUsuari();
	cout << "Nom complet: " << usuari.getNom() << "\n";
	cout << "Sobrenom: " << usuari.getSobrenom() << "\n";
	cout << "Correu electronic: " << usuari.getCorreuE() << "\n";
	cout << "Data naixement (DD/MM/AAAA): " << usuari.getDataN() << "\n";
	cout << "Modalitat subscripcio: " << usuari.getSubscripcio() << "\n\n";
	cout << "Omplir la informacio que es vol modificar ..." << "\n";

	// Capturar i actualitzar dades
	string nom = usuari.getNom();
	cout << "Nom complet: ";
	getline(cin, input);
	if (!input.empty()) nom = input;
	string contrasenya = usuari.getContrasenya();
	cout << "Contrasenya: ";
	getline(cin, input);
	if (!input.empty()) contrasenya = input;
	string correu = usuari.getCorreuE();
	cout << "Correu electronic: ";
	getline(cin, input);
	if (!input.empty() && comprovarCorreu(input)) correu = input;
	string dataNaixement = usuari.getDataN();
	cout << "Data naixement (DD/MM/AAAA): ";
	getline(cin, input);
	if (!input.empty()) dataNaixement = input;
	string subscripcio = usuari.getSubscripcio();
	cout << "Modalitat subscripcio: ";
	getline(cin, input);
	if (!input.empty()) subscripcio = input;

	try {
		cuModificaUsuari.modificarUsuari(nom, contrasenya, correu, dataNaixement, subscripcio);
		cout << "\n" << "** Dades usuari modificades **" << "\n";
		usuari = cuModificaUsuari.consultaUsuari();
		cout << "Nom complet: " << usuari.getNom() << "\n";
		cout << "Sobrenom: " << usuari.getSobrenom() << "\n";
		cout << "Correu electronic :" << usuari.getCorreuE() << "\n";
		cout << "Data naixement (DD/MM/AAAA): " << usuari.getDataN() << "\n";
		cout << "Modalitat subscripcio: " << usuari.getSubscripcio() << "\n";
	}
	catch (const exception& e)
	{
		cout << "Error: " << e.what() << "\n";
	}
} 
