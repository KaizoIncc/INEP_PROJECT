#include "ConnexioBD.h"
#include <fstream>
#include <sstream>
#include <map>

map<string, string> llegirConfig(const string& nameFile) {
    map<string, string> config;
    ifstream fitxer(nameFile);
    string linia;

    if (fitxer.is_open()) {
        while (getline(fitxer, linia)) {
            istringstream iss(linia);
            string clau, valor;
            if (getline(iss, clau, '=') && getline(iss, valor)) config[clau] = valor;
        }
        fitxer.close();
    }
    else throw runtime_error("No s'ha pogut obrir l'arxiu de configuracio");
    
    return config;
}

int main() {

    map<string, string> config = llegirConfig("config.txt");

    try {
        // Crear instancia de ConnexioBD
        ConnexioBD connexio(config["servidor"], config["usuari"], config["bbdd"], config["contrasenya"]);

        int opcio;
        do {
            cout << "Opcions:\n1. Registrar usuari\n2. Consultar usuari\n3. Modificar usuari\n4. Esborrar usuari\n5. Sortir\n";
            cout << "Tria una opcio: "; cin >> opcio;

            switch (opcio) {
            case 1:
                connexio.registrarUsuari();
                break;
            case 2:
                connexio.consultarUsuari();
                break;
            case 3:
                connexio.modificarUsuari();
                break;
            case 4:
                connexio.esborrarUsuari();
                break;
            case 5:
                cout << "Sortint..." << endl;
                break;
            default:
                cout << "Opció no vàlida." << endl;
            }
        } while (opcio != 5);

    }
    catch (SQLException& e) {
        cerr << "SQL Error: " << e.what() << endl;
    }

    return 0;
}
