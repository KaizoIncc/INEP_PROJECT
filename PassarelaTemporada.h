#pragma once
#include <iostream>
#include "ConnexioBD.h"
#include "config.txt"

using namespace std;

class PassarelaTemporada {
private:

    string titolS;
    int numeroT;

public:

    PassarelaTemporada(string titolSerie, int numero);

    PassarelaTemporada();

    ~PassarelaTemporada();

    //Getters
    string getTitol();

    int getNumeroT();
};

