#pragma once
#include <iostream>
#include "ConnexioBD.h"
#include "config.txt"

using namespace std;

class PassarelaCapitol {
private:

    string titolS, titolCap, dataEstrena, qualificacio;
    int numeroTemporada, numeroCap;

public:

    PassarelaCapitol(string titolSerie, int numeroTemporadaS, int numeroC, string titolC, string dataEstrenaC, string qualificacioC);

    PassarelaCapitol();

    ~PassarelaCapitol();

    //Getters
    int getNumeroC();

    string getTitolCap();

    string getDataEstrena();

    string getQualificacio();

    string getNumeroTemporada();
    
    string getTitolSerie();
};

