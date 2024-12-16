#pragma once
#include "PassarelaVisualitzaCapitol.h"

class DTOVisualitzacioCapitol {
private:

    string sobrenom, titolS, dataV;
    int numeroT, numeroC, numeroV;


public:

    DTOVisualitzacioCapitol();

    DTOVisualitzacioCapitol(string titolSerie, int numeroTemporada, int numeroCapitol, string dataVisualitzacio, int numVisualitzacio);

    DTOVisualitzacioCapitol(PassarelaVisualitzaCapitol visualitzacio);

    string getTitolSerie();

    int getNumeroTemporada();

    int getNumeroCapitol();

    string getDataVisualitzacio();

    int getNumeroVisualitzacio();
};

