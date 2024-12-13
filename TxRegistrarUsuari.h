#pragma once
#include "CercadoraUsuari.h"
#include "PassarelaUsuari.h"

class TxRegistrarUsuari {
public:
    // Constructor
    TxRegistrarUsuari(string nom, string sobrenom, string contrasenya, string correuElectronic, string dataNaixement, string modalitatSubs);

    // Destructor
    ~TxRegistrarUsuari();

    // Método para ejecutar el registro
    void executar();

private:
    // Métodos privados

    // Atributos
    string nom, sobrenom, contrasenya, correuElectronic, dataNaixement, modalitatSubs;
};