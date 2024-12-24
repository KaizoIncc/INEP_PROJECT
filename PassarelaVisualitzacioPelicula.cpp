#include "PassarelaVisualitzacioPelicula.h"

PasarelaVisualitzacioPelicula::PasarelaVisualitzacioPelicula(
    string data, string titol, string descripcio,
    string qualificacio, int vegades
) : dataVisualitzacio(data), titol(titol), descripcio(descripcio),
qualificacio(qualificacio), vegades(vegades) {}

string PasarelaVisualitzacioPelicula::getDataVisualitzacio() { 
    return dataVisualitzacio; 
}

string PasarelaVisualitzacioPelicula::getTitol() { 
    return titol; 
}

string PasarelaVisualitzacioPelicula::getDescripcio() { 
    return descripcio; 
}

string PasarelaVisualitzacioPelicula::getQualificacio() { 
    return qualificacio; 
}

int PasarelaVisualitzacioPelicula::getVegades() { 
    return vegades; 
}