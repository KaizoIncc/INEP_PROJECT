#pragma once
#include "PassarelaContingut.h"

class CercadoraContingut {
private:

public:

    CercadoraContingut();

    ~CercadoraContingut();

    PassarelaContingut cercaPerTitol(string titol);

    PassarelaContingut cercaContingutPeli(string titol);
};

