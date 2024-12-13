#include "TxEsborrarUsuari.h"

// ructor
TxEsborrarUsuari::TxEsborrarUsuari(string contrasenya) {
    contrasenyaU = contrasenya;
    result = true;
}

// Destructora
TxEsborrarUsuari::~TxEsborrarUsuari() {
    
}

// M�todo para ejecutar el registro
void TxEsborrarUsuari::executar() {    

    PetitFlix flix = PetitFlix::getInstance();
    // Obtenir l'usuari
    PassarelaUsuari usuari = flix.getUsuari();    

    if (usuari.getContrasenya() == contrasenyaU) {
        usuari.esborra(); // Esborra l'usuari
        result = false;
        flix.tancarSessio();
    }
    else {
        throw exception("La contrasenya no �s correcta");
    }
}

bool TxEsborrarUsuari::obteResultat() {
    return result;
}