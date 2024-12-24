#include "TxConsultaPeli.h"

TxConsultaPeli::TxConsultaPeli() {

}

TxConsultaPeli::~TxConsultaPeli() {

}

vector<PeliculaDTO> TxConsultaPeli::executar() {
    CercadoraPelicules cercadora;
    vector<PeliculaInfo> pelicules = cercadora.obtenirTopPelicules(5);

    vector<PeliculaDTO> peliculesDTO;
    for (int i = 0; i < pelicules.size(); ++i) {
        string dataVisualitzacio = pelicules[i].getDataVisualitzacio();
        PeliculaDTO dto(
            pelicules[i].getTitol(),
            pelicules[i].getQualificacioEdats(),
            pelicules[i].getDuracio(),
            pelicules[i].getNumVisualitzacions(),
            !dataVisualitzacio.empty() ? dataVisualitzacio : ""
        );
        peliculesDTO.push_back(dto);
    }

    return peliculesDTO;
}