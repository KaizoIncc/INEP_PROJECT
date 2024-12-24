#pragma once

#include <string>
using namespace std;

class VisualitzacioSerieDTO {
private:
    string data;
    string titolSerie;
    int numTemporada;
    int numCapitol;
    string qualificacio;
    int vegades;

public:
    VisualitzacioSerieDTO(string data, string titolSerie, int numTemporada, int numCapitol, string qualificacio, int vegades);

    string getData();
    string getTitolSerie();
    int getNumTemporada();
    int getNumCapitol();
    string getQualificacio();
    int getVegades();
};