#pragma once

#include "DTOUsuari.h"
#include "PassarelaUsuari.h"
#include "PetitFlix.h"

class TxConsultaUsuari {
private:
    DTOUsuari resultat; // Almacena el resultado como un DTOUsuari
    PassarelaUsuari usuari; // Almacena el usuario como PassarelaUsuari

public:
    // Constructor
    TxConsultaUsuari();

    // M�todo para ejecutar la transacci�n
    void executar();

    // Obtener el resultado como un DTOUsuari
    DTOUsuari obteResultat() const;

    // Obtener el usuario actual como PassarelaUsuari
    PassarelaUsuari obteUsuari() const;
};
