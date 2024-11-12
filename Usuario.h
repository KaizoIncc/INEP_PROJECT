#include "ConnexioBD.h"

class Usuario {
public:
    static void consultaUsuari(const string& servidor, const string& usuario, const string& password, const string& database);
    static void registrarUsuari(const string& servidor, const string& usuario, const string& password, const string& database);
    static void modificarUsuari(const string& servidor, const string& usuario, const string& password, const string& database);
    static void esborrarUsuari(const string& servidor, const string& usuario, const string& password, const string& database);
};