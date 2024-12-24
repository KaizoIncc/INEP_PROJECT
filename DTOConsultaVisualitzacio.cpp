#include "DTOConsultaVisualitzacio.h"

ConsultaVisualitzacionsDTO::ConsultaVisualitzacionsDTO(vector<VisualitzacioPeliculaDTO> pelicules, vector<VisualitzacioSerieDTO> series) : pelicules(pelicules), series(series) {}

vector<VisualitzacioPeliculaDTO> ConsultaVisualitzacionsDTO::getPelicules() { 
	return pelicules; 
}

vector<VisualitzacioSerieDTO> ConsultaVisualitzacionsDTO::getSeries() { 
	return series; 
}