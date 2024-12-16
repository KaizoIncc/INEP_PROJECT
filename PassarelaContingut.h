#pragma once
#include <iostream>
#include "ConnexioBD.h"
#include "config.txt"

using namespace std;

class PassarelaContingut {
private:

    string titol, descripcio, qualificacio, tipus;

public:

    PassarelaContingut(string titolC, string descripcioC, string qualificacioC, string tipusC);  

    PassarelaContingut();

    ~PassarelaContingut();

    //Getters
    string getTitol();

    string getDescripcio();

    string getQualificacio();

    string getTipus();

};

