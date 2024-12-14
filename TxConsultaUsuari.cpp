#include "TxConsultaUsuari.h"

// Constructor
TxConsultaUsuari::TxConsultaUsuari() {

}

TxConsultaUsuari::~TxConsultaUsuari() {

}

// Método para ejecutar la transacción
void TxConsultaUsuari::executar() {
    // Obtener el usuario actual desde PetitFlix
    PetitFlix& petitflix = PetitFlix::getInstance();
    PassarelaUsuari usuariP = petitflix.getUsuari();

    // Crear un DTOUsuari a partir del usuario actual
    resultat = DTOUsuari(usuariP);

    usuari = usuariP;
    
}

// Método para obtener el resultado
DTOUsuari TxConsultaUsuari::obteResultat() {
    return resultat;
}

PassarelaUsuari TxConsultaUsuari::obteUsuari() {
    return usuari;
}

