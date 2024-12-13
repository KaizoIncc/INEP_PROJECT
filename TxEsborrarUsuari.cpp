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

    if (contrasenyaU == contrasenya) {
        usuari.esborra();

        //tanca sessio
    }
    else {
        cout << "La contrasenya no és correcta, l'usuari no s'esborrat\n";
    }
}
