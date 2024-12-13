#include "ConnexioBD.h"

// Constructor privado
ConnexioBD::ConnexioBD(const string& cadenaConexion) {
    // Pasar la cadena de conexión y extraer los parámetros
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

    // Validar parámetros
    if (servidor.empty() || usuario.empty() || password.empty() || database.empty()) {
        throw runtime_error("Parámetros de conexión incompletos");
    }

    // Establecer la conexión
    driver = get_mysql_driver_instance();
    con = driver->connect(servidor, usuario, password);
    con->setSchema(database);

    //cout << "Conexión establecida con éxito." << "\n";
}

// Destructor privado
ConnexioBD::~ConnexioBD() {
    if (con) {
        con->close();
        delete con;
        cout << "Conexión cerrada con éxito." << "\n";
    }
}

// Método estático para acceder a la instancia única
ConnexioBD& ConnexioBD::getInstance(const string& cadenaConexion) {
    static ConnexioBD* instance = nullptr;

    if (!instance) {
        // Crear instancia única
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
        throw; // Re-llança l'excepció després de registrar-la
    }
}

// Ejecutar un comando SQL (INSERT, UPDATE, DELETE, etc.)
void ConnexioBD::executarComanda(const string& comandaSQL) {
    try {
        Statement* stmt = con->createStatement();
        
        stmt->execute(comandaSQL);
        
        delete stmt; // Liberar el statement después de usarlo
    }
    catch (const sql::SQLException& e) {
        cerr << "Error SQL: " << e.what() << "\n";
        cerr << "Codi SQLState: " << e.getSQLState() << "\n";
        cerr << "Codi d'error: " << e.getErrorCode() << "\n";
        throw; // Propaga l'excepció per a la seva gestió posterior
    }
}
