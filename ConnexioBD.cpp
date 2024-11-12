#include "ConnexioBD.h"

ConnexioBD::ConnexioBD(const string& servidor, const string& usuario, const string& password, const string& database) {
    driver = get_mysql_driver_instance();
    con = driver->connect(servidor, usuario, password);
    con->setSchema(database);
    cout << "Conexión establecida con éxito." << endl;
}

ConnexioBD::~ConnexioBD() {    
    con->close();
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
