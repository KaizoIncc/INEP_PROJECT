#include "Usuario.h"

void Usuario::registrarUsuari(const string& servidor, const string& usuario, const string& password, const string& database) {
    try {
        ConnexioBD connexio(servidor, usuario, password, database);

        string sobrenom, nom, correu;
        cout << "Introdueix el sobrenom: ";
        cin >> sobrenom;
        cout << "Introdueix el nom: ";
        cin.ignore();
        getline(cin, nom);
        cout << "Introdueix el correu electrònic: ";
        cin >> correu;

        string sql = "INSERT INTO Usuari (sobrenom, nom, correu_electronic) VALUES ('" + sobrenom + "', '" + nom + "', '" + correu + "')";
        connexio.executarComanda(sql);

        cout << "Usuari registrat correctament." << endl;
    }
    catch (SQLException& e) {
        cerr << "SQL Error: " << e.what() << endl;
    }
}

void Usuario::consultaUsuari(const string& servidor, const string& usuario, const string& password, const string& database) {
    try {
        ConnexioBD connexio(servidor, usuario, password, database);

        string sobrenom;
        cout << "Introdueix el sobrenom de l'usuari: ";
        cin >> sobrenom;

        string sql = "SELECT * FROM Usuari WHERE sobrenom='" + sobrenom + "'";
        ResultSet* res = connexio.executarConsulta(sql);

        if (res->next()) {
            cout << "Sobrenom: " << res->getString("sobrenom") << endl;
            cout << "Nom: " << res->getString("nom") << endl;
            cout << "Correu: " << res->getString("correu_electronic") << endl;
        }
        else {
            cout << "Usuari no trobat." << endl;
        }
        delete res;
    }
    catch (SQLException& e) {
        cerr << "SQL Error: " << e.what() << endl;
    }
}

void Usuario::modificarUsuari(const string& servidor, const string& usuario, const string& password, const string& database) {
    try {
        ConnexioBD connexio(servidor, usuario, password, database);

        string sobrenom, nouNom, nouCorreu;
        cout << "Introdueix el sobrenom de l'usuari a modificar: ";
        cin >> sobrenom;
        cout << "Introdueix el nou nom: ";
        cin.ignore();
        getline(cin, nouNom);
        cout << "Introdueix el nou correu: ";
        cin >> nouCorreu;

        string sql = "UPDATE Usuari SET nom='" + nouNom + "', correu_electronic='" + nouCorreu + "' WHERE sobrenom='" + sobrenom + "'";
        connexio.executarComanda(sql);

        cout << "Usuari modificat correctament." << endl;
    }
    catch (SQLException& e) {
        cerr << "SQL Error: " << e.what() << endl;
    }
}

void Usuario::esborrarUsuari(const string& servidor, const string& usuario, const string& password, const string& database) {
    try {
        ConnexioBD connexio(servidor, usuario, password, database);

        string sobrenom;
        cout << "Introdueix el sobrenom de l'usuari a esborrar: ";
        cin >> sobrenom;

        string sql = "DELETE FROM Usuari WHERE sobrenom='" + sobrenom + "'";
        connexio.executarComanda(sql);

        cout << "Usuari esborrat correctament." << endl;
    }
    catch (SQLException& e) {
        cerr << "SQL Error: " << e.what() << endl;
    }
}
