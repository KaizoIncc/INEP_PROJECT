#include "ConnexioBD.h"

int main() {
    string servidor = "ubiwan.epsevg.upc.edu", usuari = "inep06", contrasenya = "ahp8Oa4ohxaeyu", bbdd = "inep06";
    cout << "Introdueix el servidor: "; cin >> servidor;
    cout << "Introdueix l'usuari: "; cin.ignore(); getline(cin, usuari);
    cout << "Introdueix la contrasenya: "; cin >> contrasenya;
    cout << "Introdueix el nom de la bbdd: "; cin >> bbdd;

    try {
        // Crear instancia de ConnexioBD
        ConnexioBD connexio(servidor, usuari, contrasenya, bbdd);

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
