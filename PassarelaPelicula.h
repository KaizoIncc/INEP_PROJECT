#pragma once

#include <string>
using namespace std;

class PeliculaInfo {
private:
    string titol;
    string qualificacioEdats;
    int duracio;
    int numVisualitzacions;
    string dataVisualitzacio;

public:
    PeliculaInfo(string titol, string qualificacioEdats, int duracio, int numVisualitzacions, string dataVisualitzacio);

    PeliculaInfo();

    ~PeliculaInfo();
    // Getters
    string getTitol();

    string getQualificacioEdats();

    int getDuracio();

    int getNumVisualitzacions();

    string getDataVisualitzacio();
    // Setters
    void setTitol(string titol);

    void setQualificacioEdats(string qualificacio);

    void setDuracio(int duracio);

    void setNumVisualitzacions(int num);

    void setDataVisualitzacio(string data);
};