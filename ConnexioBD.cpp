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

    //cout << "Conexi�n establecida con �xito." << "\n";
}

// Destructor privado
ConnexioBD::~ConnexioBD() {
    if (con) {
        con->close();
        delete con;
        cout << "Conexi�n cerrada con �xito." << "\n";
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
    try {
        Statement* stmt = con->createStatement();
        
        ResultSet* res = stmt->executeQuery(consultaSQL); 

        delete stmt;
        
        return res;
    }
    catch (const sql::SQLException& e) {
        cerr << "SQL Exception: " << e.what() << "\n";
        cerr << "Error Code: " << e.getErrorCode() << "\n";
        cerr << "SQL State: " << e.getSQLState() << "\n";
        throw; // Re-llan�a l'excepci� despr�s de registrar-la
    }
}

// Ejecutar un comando SQL (INSERT, UPDATE, DELETE, etc.)
void ConnexioBD::executarComanda(const string& comandaSQL) {
    try {
        Statement* stmt = con->createStatement();
        
        stmt->execute(comandaSQL);
        
        delete stmt; // Liberar el statement despu�s de usarlo
    }
    catch (const sql::SQLException& e) {
        cerr << "Error SQL: " << e.what() << "\n";
        cerr << "Codi SQLState: " << e.getSQLState() << "\n";
        cerr << "Codi d'error: " << e.getErrorCode() << "\n";
        throw; // Propaga l'excepci� per a la seva gesti� posterior
    }
}
