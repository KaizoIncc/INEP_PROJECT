#pragma once
#include "PassarelaContingut.h"

class DTOSerie {
private:

    string titol, descripcio, qualificacio;

public:

    DTOSerie();

    DTOSerie(string titolS, string descripcioS, string qualificacioS);

    DTOSerie(PassarelaContingut serie);

    string getTitol();

    string getDescripcio();

    string getQualificacio();

};
