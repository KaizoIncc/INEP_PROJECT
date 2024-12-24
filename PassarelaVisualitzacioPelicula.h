#pragma once

#include <string>
using namespace std;

class PasarelaVisualitzacioPelicula {
private:
    string dataVisualitzacio;
    string titol;
    string descripcio;
    string qualificacio;
    int vegades;

public:
    PasarelaVisualitzacioPelicula(string data, string titol, string descripcio, string qualificacio, int vegades);

    string getDataVisualitzacio();
    string getTitol();
    string getDescripcio();
    string getQualificacio();
    int getVegades();
};