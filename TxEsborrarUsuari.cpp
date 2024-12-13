#include "TxEsborrarUsuari.h"
#include "PetitFlix.h"
#include <stdexcept>

// Constructor
TxEsborrarUsuari::TxEsborrarUsuari(string contrasenya) {
    this->contrasenya = contrasenya;
}

// Método para ejecutar el registro
void TxEsborrarUsuari::executar() {
    string contrasenyaU;

    PetitFlix& flix = PetitFlix::getInstance();
    // Obtenir l'usuari
    PassarelaUsuari usuari = flix.getUsuari();

    contrasenyaU = usuari.getContrasenya();
    cout << contrasenyaU << endl;
    cout << contrasenya << endl;

    if (contrasenyaU == contrasenya) {
        usuari.esborra();
    }
}
