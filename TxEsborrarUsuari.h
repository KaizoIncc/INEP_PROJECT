#pragma once
#include <string>
#include "CercadoraUsuari.h"
#include "PassarelaUsuari.h"

using namespace std;

class TxEsborrarUsuari {
public:
    // Constructor
    TxEsborrarUsuari(string contrasenya);

    // Método para ejecutar el registro
    void executar();

private:
    // Métodos privados

    // Atributos
    string contrasenya;
};