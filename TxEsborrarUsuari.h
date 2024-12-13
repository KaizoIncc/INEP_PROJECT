#pragma once
#include "PassarelaUsuari.h"
#include "PetitFlix.h"


class TxEsborrarUsuari {
public:
    // ructor
    TxEsborrarUsuari(string contrasenya);

    ~TxEsborrarUsuari();

    // Método para ejecutar el registro
    void executar();

    bool obteResultat();

private:
    // Métodos privados

    // Atributos
    string contrasenyaU;
    bool result;
};