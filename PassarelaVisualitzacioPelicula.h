#pragma once
#include "ConnexioBD.h"
#include "config.txt"
#include <string>
using namespace std;

class PasarelaVisualitzacioPelicula {
private:
    string dataVisualitzacio;
    string titol;
    string descripcio;
    string qualificacio;
    int vegades;

    string sobrenom;
    string current_time;
    string num_visualitzacionsPel;

public:
    PasarelaVisualitzacioPelicula();

    PasarelaVisualitzacioPelicula(string data, string titol, string descripcio, string qualificacio, int vegades);

    PasarelaVisualitzacioPelicula(string sobrenom, string nomP, string current_time, string num_visualitzacionsPel);

    string getDataVisualitzacio();
    string getTitol();
    string getDescripcio();
    string getQualificacio();
    int getVegades();

    string getSobrenom();
    string getCurrent_time();
    string getNum_visualitzacionsPel();

    //Setters
    void setSobrenom(string sobrenom);
    void setNomP(string nomP);
    void setCurrent_time(string current_time);
    void setNum_visualitzacionsPel(string num_visualitzacionsPel);

    void insereix();
    void modificar_visualitzacio();
};