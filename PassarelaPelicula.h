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
    string data_estrena;
    string duracioS;

public:
    PeliculaInfo(string titol, string qualificacioEdats, int duracio, int numVisualitzacions, string dataVisualitzacio);

    PeliculaInfo(string titol, string data_estrena, string duracio);

    PeliculaInfo();

    ~PeliculaInfo();
    // Getters
    string getTitol();

    string getQualificacioEdats();

    int getDuracio();

    int getNumVisualitzacions();

    string getDataVisualitzacio();

    string getDataE();
    
    string getDuracioS();

    // Setters
    void setTitol(string titol);

    void setQualificacioEdats(string qualificacio);

    void setDuracio(int duracio);

    void setNumVisualitzacions(int num);

    void setDataVisualitzacio(string data);
};