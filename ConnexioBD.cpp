#include "ConnexioBD.h"

// Constructor privado
ConnexioBD::ConnexioBD(const string& cadenaConexion) {
    // Pasar la cadena de conexi�n y extraer los par�metros
    string servidor, usuario, password, database;

    stringstream ss(cadenaConexion);
    string token;
    while (getline(ss, token, ' ')) {
        size_t eqPos = token.find('=');
        if (eqPos != string::npos) {
            string clave = token.substr(0, eqPos);
            string valor = token.substr(eqPos + 1);
            if (clave == "servidor") servidor = valor;
            else if (clave == "usuario") usuario = valor;
            else if (clave == "password") password = valor;
            else if (clave == "database") database = valor;
        }
    }

    // Validar par�metros
    if (servidor.empty() || usuario.empty() || password.empty() || database.empty()) {
        throw runtime_error("Par�metros de conexi�n incompletos");
    }

    // Establecer la conexi�n
    driver = get_mysql_driver_instance();
    con = driver->connect(servidor, usuario, password);
    con->setSchema(database);

    cout << "Conexi�n establecida con �xito." << endl;
}

// Destructor privado
ConnexioBD::~ConnexioBD() {
    if (con) {
        con->close();
        delete con;
        cout << "Conexi�n cerrada con �xito." << endl;
    }
}

// M�todo est�tico para acceder a la instancia �nica
ConnexioBD& ConnexioBD::getInstance(const string& cadenaConexion) {
    static ConnexioBD* instance = nullptr;

    if (!instance) {
        // Crear instancia �nica
        instance = new ConnexioBD(cadenaConexion);
    }

    return *instance;
}

// Ejecutar una consulta SQL y devolver un ResultSet
ResultSet* ConnexioBD::executarConsulta(const string& consultaSQL) {
    Statement* stmt = con->createStatement();
    ResultSet* res = stmt->executeQuery(consultaSQL);
    delete stmt; // Liberar el statement despu�s de usarlo
    return res;
}

// Ejecutar un comando SQL (INSERT, UPDATE, DELETE, etc.)
void ConnexioBD::executarComanda(const string& comandaSQL) {
    Statement* stmt = con->createStatement();
    stmt->execute(comandaSQL);
    delete stmt; // Liberar el statement despu�s de usarlo
}
