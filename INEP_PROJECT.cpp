#include "Usuario.h"
#include <fstream>
#include <sstream>
#include <map>

// Funció per llegir el fitxer de configuració
map<string, string> llegirConfig(const string& nameFile) {
    map<string, string> config;
    ifstream fitxer(nameFile);
    string linia;

    if (fitxer.is_open()) {
        while (getline(fitxer, linia)) {
            istringstream iss(linia);
            string clau, valor;
            if (getline(iss, clau, '=') && getline(iss, valor)) {
                config[clau] = valor;
            }
        }
        fitxer.close();
    }
    else {
        throw runtime_error("No s'ha pogut obrir l'arxiu de configuració");
    }

    return config;
}

int main() {
    try {
        map<string, string> config = llegirConfig("config.txt");
        string servidor = config["servidor"];
        string usuario = config["usuario"];
        string password = config["password"];
        string database = config["database"];

        int opcio;
        do {
            cout << "Opcions:\n1. Registrar usuari\n2. Consultar usuari\n3. Modificar usuari\n4. Esborrar usuari\n5. Sortir\n";
            cout << "Tria una opcio: ";
            cin >> opcio;

            switch (opcio) {
            case 1:
                Usuario::registrarUsuari(servidor, usuario, password, database);
                break;
            case 2:
                Usuario::consultaUsuari(servidor, usuario, password, database);
                break;
            case 3:
                Usuario::modificarUsuari(servidor, usuario, password, database);
                break;
            case 4:
                Usuario::esborrarUsuari(servidor, usuario, password, database);
                break;
            case 5:
                cout << "Sortint..." << endl;
                break;
            default:
                cout << "Opció no vàlida." << endl;
            }
        } while (opcio != 5);

    }
    catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
    }
    catch (const sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << endl;
    }

    return 0;
}
