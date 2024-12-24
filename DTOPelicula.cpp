#include "DTOPelicula.h"

// Constructor
PeliculaDTO::PeliculaDTO(string titol, string qualificacioEdats, int duracio, int numVisualitzacions, string dataVisualitzacio)
    : titol(titol), qualificacioEdats(qualificacioEdats), duracio(duracio), numVisualitzacions(numVisualitzacions), dataVisualitzacio(dataVisualitzacio) {}

// Getters
string PeliculaDTO::getTitol() { 
    return titol; 
}

string PeliculaDTO::getQualificacioEdats() { 
    return qualificacioEdats; 
}

int PeliculaDTO::getDuracio() { 
    return duracio; 
}

int PeliculaDTO::getNumVisualitzacions() { 
    return numVisualitzacions; 
}

string PeliculaDTO::getDataVisualitzacio() { 
    return dataVisualitzacio; 
}

bool PeliculaDTO::teDataVisualitzacio() { 
    return !dataVisualitzacio.empty(); 
}