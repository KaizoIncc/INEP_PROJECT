#pragma once

#include <string>
using namespace std;

class VisualitzacioPeliculaDTO {
private:
    string data;
    string titol;
    string descripcio;
    string qualificacio;
    int vegades;

public:
    VisualitzacioPeliculaDTO(string data, string titol, string descripcio, string qualificacio, int vegades);

    string getData();
    string getTitol();
    string getDescripcio();
    string getQualificacio();
    int getVegades();
};
