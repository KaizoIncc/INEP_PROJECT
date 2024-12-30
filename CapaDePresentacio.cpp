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
	// Verificar formato con regex para DD-MM-YYYY
	regex dataRegex("^\\d{2}-\\d{2}-\\d{4}$");
	if (!regex_match(dataNaixement, dataRegex)) {
		return false; // El formato no coincide
	}

	// Extraer día, mes y año
	int dia, mes, any;
	sscanf(dataNaixement.c_str(), "%d-%d-%d", &dia, &mes, &any);

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
	// Crear una instancia de la transacción TxConsultaUsuari
	TxConsultaUsuari consulta;
	try {
		// Ejecutar la transacción
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
		// Ejecutar la transacción
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

void CapaDePresentacio::processarVisualitzarCapitol() {
	cin.ignore();
	system("CLS");
	string input;
	int temporada, capitulo;
	cout << "** Visualitzar Capitol **" << "\n";
	cout << "Nom de la serie: ";
	getline(cin, input);
	CUVisualitzarCapitol visualizaC;	
	DTOSerie serie = visualizaC.consultaSerie(input);
	int temporadesT = visualizaC.consultaTemporadaS(input);
	cout << "La serie te " << temporadesT <<  " temporades." << "\n";
	cout << "Escull temporada: ";
	cin >> temporada;
	vector <DTOCapitol> capitols = visualizaC.consultaCapitol(input, temporada);
	vector<DTOVisualitzacioCapitol> visualitzacions = visualizaC.consultaVisualitzacioC(input, temporada);
	cout << "Llista capitols:" << "\n";
	// Mostrar la lista de capitols
	for (int i = 0; i < capitols.size(); ++i) {
		cout << capitols[i].getNumeroC() << ". " << capitols[i].getTitol() << "; " << capitols[i].getDataEstrena() << "; ";
		bool visualitzat = false;
		// Buscar si este capítulo está en la lista de visualizaciones
		for (auto& visualitzacio : visualitzacions) {
			if (visualitzacio.getNumeroCapitol() == capitols[i].getNumeroC()) {
				cout << "visualitzat el " << visualitzacio.getDataVisualitzacio() << "\n";
				visualitzat = true;
				break;
			}
		}
		// Si no se encontró la visualización
		if (!visualitzat) {
			cout << "no visualitzat\n";
		}
	}
	cout << "Numero de capitol a visualitzar: ";
	cin >> capitulo;
	cout << "Vols continuar amb la visualitzacio (S/N): ";
	char conf;
	cin >> conf;
	visualizaC.visualitzarCapitol(input, temporada, capitulo);
	DTOVisualitzacioCapitol infoVisualitzacio = visualizaC.obteResultat();
	if (conf == 'S' or conf == 's') {
		cout << "Visualitzacio registrada: " << infoVisualitzacio.getDataVisualitzacio() << "\n";
	}
	
}

void CapaDePresentacio::processarVisualitzarPelicula()
{
	try {
		string nomP, contesta;
		PetitFlix& flix = PetitFlix::getInstance();
		// Obtenir l'usuari
		PassarelaUsuari usuari = flix.getUsuari();
		cout << "** Visualitzar Pelicula **" << endl;		//"** Visualitzar Pel·lícula **"
		cout << "Nom pelicula: ";					//"Nom pel·lícula: "
		cin.ignore();
		getline(cin, nomP);

		CUVisualitzarPeli CUvisualizarPeli(nomP);
		DTOPeli pelicula = CUvisualizarPeli.obteDTOPeli();


		//comprobar que la peli existeix
		if (!CUvisualizarPeli.existeixP(pelicula)) {
			cout << "No existeix cap pelicula amb el nom " << nomP << endl;
			return;
		}

		if (!CUvisualizarPeli.edat_adecuada(usuari.getDataN(), pelicula.getQualificacio())) {
			cout << "No tens l'edat adecuada per veure aquest contingut" << endl;
			return;
		}

		if (!CUvisualizarPeli.peli_estrenada(pelicula.getDataE())) {
			cout << "Aquesta pelicula encara no ha estat estrenada" << endl;
			return;
		}

		cout << "Informacio pelicula ...\n";
		cout << "Nom pelicula: " << pelicula.getTitol() << endl;
		cout << "Descripcio: " << pelicula.getDescripcio() << endl;
		cout << "Qualificacio edat: " << pelicula.getQualificacio() << endl;
		cout << "Data estrena: " << pelicula.getDataE() << endl;
		cout << "Duracio: " << pelicula.getDuracio() << " min" << endl;

		cout << "Vols continuar amb la visualitzacio (S/N): "; //"Vols continuar amb la visualització (S/N): "
		cin >> contesta;
		if (contesta == "S" || contesta == "s") {
			auto now = chrono::system_clock::now();
			time_t current_time1 = chrono::system_clock::to_time_t(now);
			ostringstream tiempoActualStream;
			tiempoActualStream << put_time(localtime(&current_time1), "%Y-%m-%d %H:%M");
			string tiempoActual = tiempoActualStream.str();

			// registrar visualització
			CUvisualizarPeli.visualitzarPeli();
			cout << "Visualitzacio rgistrada: " << tiempoActual << endl;
			cout << "Pelicules relacionades: ";
			TxPeliculesRelacionades TxPeliculesRelac(nomP);
			TxPeliculesRelac.executar();
			vector<DTOPeli> pelicules_relacionades = TxPeliculesRelac.obteResultat();
			for (int i = 0; i < pelicules_relacionades.size(); i++) {
				cout << "- " << pelicules_relacionades[i].getTitol() << "; " << pelicules_relacionades[i].getDescripcio() << "; " << pelicules_relacionades[i].getQualificacio() << "; " << pelicules_relacionades[i].getDuracio() << " min; " << pelicules_relacionades[i].getDataE() << endl;
			}
		}
		else {
			return;
		}
	}
	catch (const exception& e) {
		cout << e.what() << "\n";
	}
}

void CapaDePresentacio::processarConsultarVisualitzacions() {
	try {
		cout << "** Consultar Visualitzacions **" << endl;

		TxConsultaVisualitzacio consulta;
		auto resultat = consulta.executar();

		// Mostrar resultados
		auto pelicules = resultat.getPelicules();
		auto series = resultat.getSeries();

		if (pelicules.empty() && series.empty()) {
			cout << "No hi ha visualitzacions disponibles." << endl;
			return;
		}

		cout << "---- Visualitzacions de Pelicules ----" << endl;
		for (int i = 0; i < pelicules.size(); ++i) {
			cout << "Data: " << pelicules[i].getData()
				<< ", Titol: " << pelicules[i].getTitol()
				<< ", Descripcio: " << pelicules[i].getDescripcio()
				<< ", Qualificacio per edats: " << pelicules[i].getQualificacio()
				<< ", Vegades visualitzat: " << pelicules[i].getVegades() << endl;
		}

		cout << "\n---- Visualitzacions de Series ----" << endl;
		for (int i = 0; i < series.size(); ++i) {
			cout << "Data: " << series[i].getData()
				<< ", Titol serie: " << series[i].getTitolSerie()
				<< ", Temporada: " << series[i].getNumTemporada()
				<< ", Capitol: " << series[i].getNumCapitol()
				<< ", Qualificacio per edats: " << series[i].getQualificacio()
				<< ", Vegades visualitzat: " << series[i].getVegades() << endl;
		}
	}
	catch (const runtime_error& e) {
		cerr << "Error: " << e.what() << endl;
	}
}

void CapaDePresentacio::processarConsultarProperesEstrenes()
{
	string modalitat;
	PetitFlix& flix = PetitFlix::getInstance();
	// Obtenir l'usuari
	PassarelaUsuari usuari = flix.getUsuari();
	cout << "** Properes estrenes **" << endl;
	if (usuari.getNom() != "") {
		modalitat = usuari.getSubscripcio();
		cout << "Modalitat: " << modalitat << endl;
	}
	else {
		cout << "insereix una modalitat (Completa/Infantil/Cinefil) per defecte s assignara Completa" << endl;
		cout << "Modalitat: ";
		cin >> modalitat;
		if (modalitat == "Infantil") {
			modalitat = "Infantil";
		}
		else if (modalitat == "Cinefil") {
			modalitat = "Cinefil";
		}
		else {
			modalitat = "Completa";
		}
	}
	TxProperesEstrenes properes_estrenas(modalitat);
	vector<DTOProperesEstrenes> estrenes;
	properes_estrenas.executar();
	estrenes = properes_estrenas.obteResultat();
	string any, mes, dia;
	for (int i = 0; i < estrenes.size(); i++) {
		string data = estrenes[i].getDataE();
		any = data.substr(0, 4);
		mes = data.substr(5, 2);
		dia = data.substr(8, 2);
		cout << to_string(i + 1) << ".- " << dia << "/" << mes << "/" << any << " [";
		cout << estrenes[i].getTipus() << "]: " << estrenes[i].getTitol() << "; ";
		cout << estrenes[i].getQualificacio() << "; " << estrenes[i].getDuracio_nTemporada() << "." << endl;
	}
}

void CapaDePresentacio::processarConsultarPeliculesMesVistes() {
	try {
		cout << "** Pelicules mes vistes **" << endl;

		TxConsultaPeli transaccio;
		vector<PeliculaDTO> peliculesDTO = transaccio.executar();

		for (int i = 1; i <= peliculesDTO.size(); ++i) {
			cout << i << ". " << peliculesDTO[i - 1].getTitol() << " | Edat: "
				<< peliculesDTO[i - 1].getQualificacioEdats() << " | Duracio: "
				<< peliculesDTO[i - 1].getDuracio() << " min | Visualitzacions: "
				<< peliculesDTO[i - 1].getNumVisualitzacions() << " |" ;

			if (peliculesDTO[i - 1].teDataVisualitzacio()) cout << " Data de visualitzacio: " << peliculesDTO[i - 1].getDataVisualitzacio();
 
			cout << endl;
		}
	}
	catch (const runtime_error& e) {
		cout << "Error: " << e.what() << endl;
	}
}
