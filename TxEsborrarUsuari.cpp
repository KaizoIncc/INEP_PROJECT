#include "TxEsborrarUsuari.h"
#include "PetitFlix.h"
#include <stdexcept>

#include <stdexcept>

// Constructor
TxEsborrarUsuari::TxEsborrarUsuari(const string contrasenya) : contrasenya(contrasenya){}

// M�todo para ejecutar el registro
void TxEsborrarUsuari::executar() {
    CercadoraUsuari cercadora;
    string contrasenyaU;

    PetitFlix& flix = PetitFlix::getInstance();
    // Obtenir l'usuari
    PassarelaUsuari usuari = flix.getUsuari();

    contrasenyaU = usuari.getContrasenya();

    if (contrasenyaU == contrasenya) {
        usuari.esborra();
    }
}
