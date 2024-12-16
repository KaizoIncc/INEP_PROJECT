#pragma once
#include "PassarelaTemporada.h"

class CercadoraTemporada {
private:

    int temporadesTotals;

public:

    CercadoraTemporada();

    ~CercadoraTemporada();

    int cercaTemporadesTotales(string titolSerie);

    PassarelaTemporada cercaPerTemporada(string titolSerie);
};

