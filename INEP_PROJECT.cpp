#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <iostream>
#include <mysql_connection.h>
#include <mysql_driver.h>

using namespace std; // Esto elimina la necesidad de usar el prefijo `std::`
using namespace sql; // Esto elimina la necesidad de usar el prefijo `sql::`
using namespace sql::mysql; // Esto elimina la necesidad de usar el prefijo `sql::mysql`

void registrarUsuari(Connection* con) {
    string sobrenom, nom, correu;
    cout << "Introdueix sobrenom: "; cin >> sobrenom;
    cout << "Introdueix nom: "; cin.ignore(); getline(cin, nom);
    cout << "Introdueix correu electrònic: "; cin >> correu;

    string sql = "INSERT INTO usuari (sobrenom, nom, correu_electronic) VALUES ('"
        + sobrenom + "', '" + nom + "', '" + correu + "')";

    Statement* stmt = con->createStatement();
    stmt->execute(sql);
    cout << "Usuari registrat correctament." << endl;
    delete stmt;
}

void consultarUsuari(Connection* con) {
    string sobrenom;
    cout << "Introdueix sobrenom per consultar: "; cin >> sobrenom;

    string sql = "SELECT * FROM usuari WHERE sobrenom='" + sobrenom + "'";
    Statement* stmt = con->createStatement();
    ResultSet* res = stmt->executeQuery(sql);

    if (res->next()) {
        cout << "Sobrenom: " << res->getString("sobrenom") << endl;
        cout << "Nom: " << res->getString("nom") << endl;
        cout << "Correu: " << res->getString("correu_electronic") << endl;
    }
    else {
        cout << "Usuari no trobat." << endl;
    }
    delete res;
    delete stmt;
}

void modificarUsuari(Connection* con) {
    string sobrenom, nouNom, nouCorreu;
    cout << "Introdueix sobrenom de l'usuari a modificar: "; cin >> sobrenom;
    cout << "Introdueix nou nom: "; cin.ignore(); getline(cin, nouNom);
    cout << "Introdueix nou correu electrònic: "; cin >> nouCorreu;

    string sql = "UPDATE usuari SET nom='" + nouNom + "', correu_electronic='"
        + nouCorreu + "' WHERE sobrenom='" + sobrenom + "'";

    Statement* stmt = con->createStatement();
    int rowsAffected = stmt->executeUpdate(sql);
    if (rowsAffected > 0) {
        cout << "Usuari modificat correctament." << endl;
    }
    else {
        cout << "Usuari no trobat." << endl;
    }
    delete stmt;
}

void esborrarUsuari(Connection* con) {
    string sobrenom;
    cout << "Introdueix sobrenom de l'usuari a esborrar: "; cin >> sobrenom;

    string sql = "DELETE FROM usuari WHERE sobrenom='" + sobrenom + "'";
    Statement* stmt = con->createStatement();
    int rowsAffected = stmt->executeUpdate(sql);

    if (rowsAffected > 0) {
        cout << "Usuari esborrat correctament." << endl;
    }
    else {
        cout << "Usuari no trobat." << endl;
    }
    delete stmt;
}

int main() {
    MySQL_Driver* driver = NULL;
    Connection* con = NULL;
    try {
        driver = get_mysql_driver_instance();
        con = driver->connect("URL_servidor:port", "usuari", "contrasenya");
        con->setSchema("nom_base_dades");

        int opcio;
        do {
            cout << "Opcions:\n1. Registrar usuari\n2. Consultar usuari\n3. Modificar usuari\n4. Esborrar usuari\n5. Sortir\n";
            cout << "Tria una opció: "; cin >> opcio;

            switch (opcio) {
            case 1:
                registrarUsuari(con);
                break;
            case 2:
                consultarUsuari(con);
                break;
            case 3:
                modificarUsuari(con);
                break;
            case 4:
                esborrarUsuari(con);
                break;
            case 5:
                cout << "Sortint..." << endl;
                break;
            default:
                cout << "Opció no vàlida." << endl;
            }
        } while (opcio != 5);

        con->close();
    }
    catch (SQLException& e) {
        cerr << "SQL Error: " << e.what() << endl;
        if (con != NULL) con->close();
    }

    return 0;
}
