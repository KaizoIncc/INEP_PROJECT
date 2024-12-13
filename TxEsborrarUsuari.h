#pragma once
#include "PassarelaUsuari.h"
#include "PetitFlix.h"


class TxEsborrarUsuari {
public:
    // ructor
    TxEsborrarUsuari(string contrasenya);

    ~TxEsborrarUsuari();

    // M�todo para ejecutar el registro
    void executar();

    bool obteResultat();

private:
    // M�todos privados

    // Atributos
    string contrasenyaU;
    bool result;
};