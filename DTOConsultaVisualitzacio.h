#pragma once

#include "DTOVisualitzaPelicula.h"
#include "DTOVisualitzaSerie.h"
#include <vector>
#include <string>
using namespace std;

class ConsultaVisualitzacionsDTO {
private:
    vector<VisualitzacioPeliculaDTO> pelicules;
    vector<VisualitzacioSerieDTO> series;

public:
    ConsultaVisualitzacionsDTO(vector<VisualitzacioPeliculaDTO> pelicules, vector<VisualitzacioSerieDTO> series);

    vector<VisualitzacioPeliculaDTO> getPelicules();
    vector<VisualitzacioSerieDTO> getSeries();
};