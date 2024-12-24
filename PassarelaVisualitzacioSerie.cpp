#include "PassarelaVisualitzacioSerie.h"

PasarelaVisualitzacioSerie::PasarelaVisualitzacioSerie(
    const string& data, const string& titolSerie, int numTemporada,
    int numCapitol, const string& qualificacio, int vegades
) : dataVisualitzacio(data), titolSerie(titolSerie), numTemporada(numTemporada),
numCapitol(numCapitol), qualificacio(qualificacio), vegades(vegades) {}

string PasarelaVisualitzacioSerie::getDataVisualitzacio() const { 
    return dataVisualitzacio; 
}

string PasarelaVisualitzacioSerie::getTitolSerie() const { 
    return titolSerie; 
}

int PasarelaVisualitzacioSerie::getNumTemporada() const { 
    return numTemporada; 
}

int PasarelaVisualitzacioSerie::getNumCapitol() const { 
    return numCapitol; 
}

string PasarelaVisualitzacioSerie::getQualificacio() const { 
    return qualificacio; 
}

int PasarelaVisualitzacioSerie::getVegades() const { 
    return vegades; 
}