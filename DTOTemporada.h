#pragma once
#include "PassarelaTemporada.h"

class DTOTemporada {
private:

    string titol;
    int numTemporada;

public:

    DTOTemporada();

    DTOTemporada(string titolS, int numeroT);

    DTOTemporada(PassarelaTemporada serie);    

    int getTemporada();
};

