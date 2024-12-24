#include "DTOVisualitzaPelicula.h"

VisualitzacioPeliculaDTO::VisualitzacioPeliculaDTO(string data, string titol, string descripcio,
    string qualificacio, int vegades) : data(data), titol(titol), descripcio(descripcio), qualificacio(qualificacio), vegades(vegades) {}

string VisualitzacioPeliculaDTO::getData() { 
    return data; 
}

string VisualitzacioPeliculaDTO::getTitol() {
    return titol; 
}

string VisualitzacioPeliculaDTO::getDescripcio() {
    return descripcio; 
}

string VisualitzacioPeliculaDTO::getQualificacio() { 
    return qualificacio; 
}

int VisualitzacioPeliculaDTO::getVegades() {
    return vegades; 
}