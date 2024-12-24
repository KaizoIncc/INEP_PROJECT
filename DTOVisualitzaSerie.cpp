#include "DTOVisualitzaSerie.h"

VisualitzacioSerieDTO::VisualitzacioSerieDTO(string data, string titolSerie, int numTemporada, int numCapitol,
    string qualificacio, int vegades) : data(data), titolSerie(titolSerie), numTemporada(numTemporada), numCapitol(numCapitol),
    qualificacio(qualificacio), vegades(vegades) {}

string VisualitzacioSerieDTO::getData() { 
    return data; 
}

string VisualitzacioSerieDTO::getTitolSerie() { 
    return titolSerie; 
}

int VisualitzacioSerieDTO::getNumTemporada() { 
    return numTemporada; 
}

int VisualitzacioSerieDTO::getNumCapitol() { 
    return numCapitol; 
}

string VisualitzacioSerieDTO::getQualificacio() { 
    return qualificacio; 
}

int VisualitzacioSerieDTO::getVegades() { 
    return vegades; 
}