#pragma once
#include <string>
#include "CercadoraUsuari.h"
#include "PassarelaUsuari.h"

using namespace std;

class TxEsborrarUsuari {
public:
    // Constructor
    TxEsborrarUsuari(string contrasenya);

    // M�todo para ejecutar el registro
    void executar();

private:
    // M�todos privados

    // Atributos
    string contrasenya;
};