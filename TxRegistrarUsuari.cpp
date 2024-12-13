#include "TxRegistrarUsuari.h"
#include <stdexcept>

// Constructor
TxRegistrarUsuari::TxRegistrarUsuari(const string& nom, const string& sobrenom,
    const string& contrasenya, const string& correuElectronic,
    const string& dataNaixement, const string& modalitatSubs)
    : nom(nom), sobrenom(sobrenom), contrasenya(contrasenya),
    correuElectronic(correuElectronic), dataNaixement(dataNaixement),
    modalitatSubs(modalitatSubs) {}

// M�todo para ejecutar el registro
void TxRegistrarUsuari::executar() {
    CercadoraUsuari cercadora;

    // Validar sobrenom �nico
    if (cercadora.existeixSobrenom(sobrenom)) {
        throw runtime_error("Ja existeix un usuari amb aquest sobrenom...");
    }

    // Validar correo �nico
    if (cercadora.existeixCorreu(correuElectronic)) {
        throw runtime_error("Ja existeix un usuari amb aquest correu electr�nic...");
    }

    // Crear el usuario
    PassarelaUsuari usuari(sobrenom, nom, contrasenya, correuElectronic, dataNaixement, modalitatSubs);

    // Insertar el usuario en la base de datos
    usuari.insereix();
}

