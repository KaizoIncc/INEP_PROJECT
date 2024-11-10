#include "ConnexioBD.h"

ConnexioBD::ConnexioBD(const string& host, const string& user, const string& bbdd, const string& password) {
    driver = get_mysql_driver_instance();
    con = driver->connect(host, user, password);
    con->setSchema(bbdd);
    cout << "Conexión establecida con éxito." << endl;
}

ConnexioBD::~ConnexioBD() {
    delete con;
    cout << "Conexión cerrada con éxito." << endl;
}

ResultSet* ConnexioBD::executarConsulta(const string& consultaSQL) {
    Statement* stmt = con->createStatement();
    ResultSet* res = stmt->executeQuery(consultaSQL);
    delete stmt; // Liberar el statement después de usarlo
    return res;
}

void ConnexioBD::executarComanda(const string& comandaSQL) {
    Statement* stmt = con->createStatement();
    stmt->execute(comandaSQL);
    delete stmt; // Liberar el statement después de usarlo
}

void ConnexioBD::registrarUsuari() {
    string sobrenom, nom, correu;
    cout << "Introdueix sobrenom: ";
    cin >> sobrenom;
    cout << "Introdueix nom: ";
    cin.ignore();
    getline(cin, nom);
    cout << "Introdueix correu electrònic: ";
    cin >> correu;

    string sql = "INSERT INTO Usuari (sobrenom, nom, correu_electronic) VALUES ('"
        + sobrenom + "', '" + nom + "', '" + correu + "')";
    executarComanda(sql);
    cout << "Usuari registrat correctament." << endl;
}

void ConnexioBD::consultarUsuari() {
    string sobrenom;
    cout << "Introdueix sobrenom per consultar: ";
    cin >> sobrenom;

    string sql = "SELECT * FROM Usuari WHERE sobrenom='" + sobrenom + "'";
    ResultSet* res = executarConsulta(sql);

    if (res->next()) {
        cout << "Sobrenom: " << res->getString("sobrenom") << endl;
        cout << "Nom: " << res->getString("nom") << endl;
        cout << "Correu: " << res->getString("correu_electronic") << endl;
    }
    else cout << "Usuari no trobat." << endl;

    delete res; // Liberar el resultado después de usarlo
}

void ConnexioBD::modificarUsuari() {
    string sobrenom, nouNom, nouCorreu;
    cout << "Introdueix sobrenom de l'usuari a modificar: ";
    cin >> sobrenom;
    cout << "Introdueix nou nom: ";
    cin.ignore();
    getline(cin, nouNom);
    cout << "Introdueix nou correu electrònic: ";
    cin >> nouCorreu;

    string sql = "UPDATE Usuari SET nom='" + nouNom + "', correu_electronic='"
        + nouCorreu + "' WHERE sobrenom='" + sobrenom + "'";
    executarComanda(sql);

    cout << "Usuari modificat correctament." << endl;
}

void ConnexioBD::esborrarUsuari() {
    string sobrenom;
    cout << "Introdueix sobrenom de l'usuari a esborrar: ";
    cin >> sobrenom;

    string sql = "DELETE FROM Usuari WHERE sobrenom='" + sobrenom + "'";
    executarComanda(sql);

    cout << "Usuari esborrat correctament." << endl;
}
