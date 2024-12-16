#pragma once
#include "PassarelaCapitol.h"

class DTOCapitol {
private:

    int numero;
    string titol;
    string dataEstrena;
    string qualificacio;

public:

    DTOCapitol();

    DTOCapitol(int numeroC, string titolC, string dataEstrenaC, string qualificacioC);

    DTOCapitol(PassarelaCapitol capitol);

    int getNumeroC();

    string getTitol();

    string getDataEstrena();

    string getQualificacio();
};

