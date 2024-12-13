#include "TxConsultaUsuari.h"

// Constructor
TxConsultaUsuari::TxConsultaUsuari() : resultat(), usuari() {}

// Método para ejecutar la transacción
void TxConsultaUsuari::executar() {
    // Obtener el usuario actual desde PetitFlix
    usuari = PetitFlix::getInstance().getUsuari();

    // Crear un DTOUsuari a partir del usuario actual
    resultat = DTOUsuari(usuari);
}

// Método para obtener el resultado
DTOUsuari TxConsultaUsuari::obteResultat() const {
    return resultat;
}

// Método para obtener el usuario como PassarelaUsuari
PassarelaUsuari TxConsultaUsuari::obteUsuari() const {
    return usuari;
}
