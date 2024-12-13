#include "TxConsultaUsuari.h"

// Constructor
TxConsultaUsuari::TxConsultaUsuari() : resultat(), usuari() {}

// M�todo para ejecutar la transacci�n
void TxConsultaUsuari::executar() {
    // Obtener el usuario actual desde PetitFlix
    usuari = PetitFlix::getInstance().getUsuari();

    // Crear un DTOUsuari a partir del usuario actual
    resultat = DTOUsuari(usuari);
}

// M�todo para obtener el resultado
DTOUsuari TxConsultaUsuari::obteResultat() const {
    return resultat;
}

// M�todo para obtener el usuario como PassarelaUsuari
PassarelaUsuari TxConsultaUsuari::obteUsuari() const {
    return usuari;
}
