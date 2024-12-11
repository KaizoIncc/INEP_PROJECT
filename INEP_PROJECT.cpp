#include "CapaDePresentacio.h"
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
					wcout << "*********************" << endl << "    Menu Principal" << endl << "*********************" << endl;
					wcout << "1. Iniciar sessió" << endl;
					wcout << "2. Registrar usuari" << endl;
					wcout << "3. Consultes" << endl;
					wcout << "4. Sortir" << endl;
					wcout << "Escriu opció: ";
					cin >> opcio;
					system("CLS");
					switch (opcio) {
					case 1:
						sessioIniciada = presentacio.processarIniciarSessio();
						break;
					case 2:
						// Registrar usuario presentacio.processarRegistrarUsuari(); 
						//presentacio.processarRegistrarUsuari();
						break;
					case 3:
						// Consultas
						break;
					case 4:
						return 0;
					default:
						wcout << "Selecciona una opció valida amb les tecles de l'1 al 4" << endl;
					}
				}
			}			
			sleep_for(chrono::seconds(1));
			system("CLS");
			wcout << "*********************" << endl << "    Menu Principal" << endl << "*********************" << endl;
			wcout << "1. Gestió usuaris" << endl;
			wcout << "2. Visualitzar" << endl;
			wcout << "3. Consultes" << endl;
			wcout << "4. Tancar sessió" << endl;
			wcout << "5. Sortir" << endl;
			wcout << "Escriu opció: ";
			cin >> opcio;
			system("CLS");
			switch (opcio) {
			case 1:
				wcout << "- - - - - - - - - - - - - -" << endl << "    Gestió Usuari" << endl << "- - - - - - - - - - - - - -" << endl;
				wcout << "1. Consulta usuari" << endl;
				wcout << "2. Modifica usuari" << endl;
				wcout << "3. Esborra usuari" << endl;
				wcout << "4. Tornar" << endl;
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
					break;
				case 4:
					break;
				default:
					wcout << "Selecciona una opció valida amb les tecles de l'1 al 4" << endl;
					break;
				}
				break;
			case 2:
				wcout << "- - - - - - - - - - - - - -" << endl << "    Visualitzar" << endl << "- - - - - - - - - - - - - -" << endl;
				wcout << "1. Visualitzar pel·lícula" << endl;
				wcout << "2. Visualitzar capítol" << endl;
				wcout << "3. Consulta visualitzacions" << endl;
				wcout << "4. Tornar" << endl;
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
					wcout << "Selecciona una opció valida amb les tecles de l'1 al 4" << endl;
					break;
				}
				break;
			case 3:
				wcout << "- - - - - - - - - - - - - -" << endl << "    Consultes" << endl << "- - - - - - - - - - - - - -" << endl;
				wcout << "1. Properes estrenes" << endl;
				wcout << "2. Últimes novetats" << endl;
				wcout << "3. Pel·lícules més vistes" << endl;
				wcout << "4. Tornar" << endl;
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
					wcout << "Selecciona una opció valida amb les tecles de l'1 al 4" << endl;
					break;
				}
				break;
			case 4:
				// Cerrar sesion
				break;
			case 5:
				return 0;
			default:
				wcout << "Selecciona una opció vàlida amb les tecles de l'1 al 5" << endl;
			}
		}
    return 0;
}
