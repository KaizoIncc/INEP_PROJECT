#include "CapaDePresentacio.h"
#include <iostream>
#include <locale>
#include <thread>

using namespace std;
using namespace this_thread;
int main() {

	std::locale::global(std::locale("es_ES.UTF-8"));

	int opcio;
	bool usuariRegistrat = false;
	bool sessioIniciada = false and usuariRegistrat;
	CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();
	while (true) {
		if (!sessioIniciada) {
			while (!sessioIniciada) {
				wcout << "*********************" << "\n" << "    Menu Principal" << "\n" << "*********************" << "\n";
				wcout << "1. Iniciar sessió" << "\n";
				wcout << "2. Registrar usuari" << "\n";
				wcout << "3. Consultes" << "\n";
				wcout << "4. Sortir" << "\n";
				wcout << "Escriu opció: ";
				cin >> opcio;
				system("CLS");
				switch (opcio) {
				case 1:
					// Iniciar sesion
					sessioIniciada = presentacio.processarIniciarSessio();
					break;
				case 2:
					// Registrar usuario 
					presentacio.processarRegistrarUsuari();
					break;
				case 3:
					// Consultas
					break;
				case 4:
					return 0;
				default:
					wcout << "Selecciona una opció valida amb les tecles de l'1 al 4" << "\n";
				}
				sleep_for(chrono::seconds(1));
				system("CLS");
			}			
		}
		wcout << "*********************" << "\n"<< "    Menu Principal" << "\n"<< "*********************" << "\n";
		wcout << "1. Gestió usuaris" << "\n";
		wcout << "2. Visualitzar" << "\n";
		wcout << "3. Consultes" << "\n";
		wcout << "4. Tancar sessió" << "\n";
		wcout << "5. Sortir" << "\n";
		wcout << "Escriu opció: ";
		cin >> opcio;
		system("CLS");
		switch (opcio) {
		case 1:
			wcout << "- - - - - - - - - - - - - -" << "\n"<< "    Gestió Usuari" << "\n"<< "- - - - - - - - - - - - - -" << "\n";
			wcout << "1. Consulta usuari" << "\n";
			wcout << "2. Modifica usuari" << "\n";
			wcout << "3. Esborra usuari" << "\n";
			wcout << "4. Tornar" << "\n";
			wcout << "Escriu opció: ";
			cin >> opcio;
			system("CLS");
			switch (opcio) {
			case 1:
				// Consulta usuario
				break;
			case 2:
				// presentacio.processarModificarUsuari();
				break;
			case 3:
				// Borrar usuario
				sessioIniciada = presentacio.processarEsborrarUsuari();
				break;
			case 4:
				
				break;
			default:
				wcout << "Selecciona una opció valida amb les tecles de l'1 al 4" << "\n";
				break;
			}
			break;
		case 2:
			wcout << "- - - - - - - - - - - - - -" << "\n"<< "    Visualitzar" << "\n"<< "- - - - - - - - - - - - - -" << "\n";
			wcout << "1. Visualitzar pel·lícula" << "\n";
			wcout << "2. Visualitzar capítol" << "\n";
			wcout << "3. Consulta visualitzacions" << "\n";
			wcout << "4. Tornar" << "\n";
			wcout << "Escriu opció: ";
			cin >> opcio;
			system("CLS");
			switch (opcio) {
			case 1:
				// Visualizar peli
				break;
			case 2:
				// Visualizar capitulo
				break;
			case 3:
				// Consulta visualizaciones
				break;
			case 4:
				break;
			default:
				wcout << "Selecciona una opció valida amb les tecles de l'1 al 4" << "\n";
				break;
			}
			break;
		case 3:
			wcout << "- - - - - - - - - - - - - -" << "\n"<< "    Consultes" << "\n"<< "- - - - - - - - - - - - - -" << "\n";
			wcout << "1. Properes estrenes" << "\n";
			wcout << "2. Últimes novetats" << "\n";
			wcout << "3. Pel·lícules més vistes" << "\n";
			wcout << "4. Tornar" << "\n";
			wcout << "Escriu opció: ";
			cin >> opcio;
			system("CLS");
			switch (opcio) {
			case 1:
				// Proximos estrenos
				break;
			case 2:
				// Novedades
				break;
			case 3:
				// Pelis mas vistas
				break;
			case 4:
				break;
			default:
				wcout << "Selecciona una opció valida amb les tecles de l'1 al 4" << "\n";
				break;
			}
			break;
		case 4:
			// Tancar sessió
			sessioIniciada = presentacio.processarTancarSessio();
			break;
		case 5:
			return 0;
		default:
			wcout << "Selecciona una opció vàlida amb les tecles de l'1 al 5" << "\n";
		}
		sleep_for(chrono::seconds(1));
		system("CLS");
	}
	return 0;
}
