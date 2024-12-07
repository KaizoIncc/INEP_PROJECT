#pragma once
#include <string>
#include "CercadoraUsuari.h"
#include "PassarelaUsuari.h"

using namespace std;

class TxRegistrarUsuari {
public:
    // Constructor
    TxRegistrarUsuari(const string& nom, const string& sobrenom,
        const string& contrasenya, const string& correuElectronic,
        const string& dataNaixement, const string& modalitatSubs);

    // Método para ejecutar el registro
    void executar();

private:
    // Métodos privados
    bool esModalitatValida(const string& modalitatSubs);

    // Atributos
    string nom;
    string sobrenom;
    string contrasenya;
    string correuElectronic;
    string dataNaixement;
    string modalitatSubs;
};