#pragma once

#include <string>
using namespace std;

class PasarelaVisualitzacioSerie {
private:
    string dataVisualitzacio;
    string titolSerie;
    int numTemporada;
    int numCapitol;
    string qualificacio;
    int vegades;

public:
    PasarelaVisualitzacioSerie(
        const string& data, const string& titolSerie, int numTemporada,
        int numCapitol, const string& qualificacio, int vegades
    );

    string getDataVisualitzacio() const;
    string getTitolSerie() const;
    int getNumTemporada() const;
    int getNumCapitol() const;
    string getQualificacio() const;
    int getVegades() const;
};