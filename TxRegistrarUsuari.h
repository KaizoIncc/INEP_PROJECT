#pragma once
#include "CercadoraUsuari.h"
#include "PassarelaUsuari.h"

class TxRegistrarUsuari {
public:
    // Constructor
    TxRegistrarUsuari(string nom, string sobrenom, string contrasenya, string correuElectronic, string dataNaixement, string modalitatSubs);

    // Destructor
    ~TxRegistrarUsuari();

    // M�todo para ejecutar el registro
    void executar();

private:
    // M�todos privados

    // Atributos
    string nom, sobrenom, contrasenya, correuElectronic, dataNaixement, modalitatSubs;
};