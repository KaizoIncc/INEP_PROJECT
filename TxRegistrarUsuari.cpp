#include "TxRegistrarUsuari.h"

// ructor
TxRegistrarUsuari::TxRegistrarUsuari(string nomU, string sobrenomU, string contrasenyaU,  string correuElectronicU, string dataNaixementU, string modalitatSubsU)
    : nom(nomU), sobrenom(sobrenomU), contrasenya(contrasenyaU), correuElectronic(correuElectronicU), dataNaixement(dataNaixementU), modalitatSubs(modalitatSubsU) {}

TxRegistrarUsuari::~TxRegistrarUsuari() {
}

// Método para ejecutar el registro
void TxRegistrarUsuari::executar() {
    CercadoraUsuari cerca = CercadoraUsuari();
    PassarelaUsuari usuari(sobrenom, nom, contrasenya, correuElectronic, dataNaixement, modalitatSubs);

    try {
        cerca.cercaPerSobrenom(sobrenom);
    }
    catch (...) {
        try {
            usuari.insereix();
            return;
        }
        catch (...) {
            throw exception("El correu ja existeix.");
        }
    }
    throw exception("El sobrenom ja existeix.");
}

