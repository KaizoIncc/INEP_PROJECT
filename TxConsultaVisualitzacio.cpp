#include "TxConsultaVisualitzacio.h"

TxConsultaVisualitzacio::TxConsultaVisualitzacio() {

}

TxConsultaVisualitzacio::~TxConsultaVisualitzacio() {

}

ConsultaVisualitzacionsDTO TxConsultaVisualitzacio::executar() {
    try {
        CercadoraVisualitzacio cercadora;
        PetitFlix& sistema = PetitFlix::getInstance();
        string usuariSobrenom = sistema.getUsuari().getSobrenom();

        // Obtener datos
        auto peliculesBase = cercadora.obtenirVisualitzacionsPelicules(usuariSobrenom);
        auto seriesBase = cercadora.obtenirVisualitzacionsSeries(usuariSobrenom);

        if (peliculesBase.empty() && seriesBase.empty()) {
            throw runtime_error("No hi ha visualitzacions per aquest usuari.");
        }

        // Transformar en DTO
        vector<VisualitzacioPeliculaDTO> pelicules;
        for (int i = 0; i < peliculesBase.size(); ++i) {
            pelicules.emplace_back(peliculesBase[i].getDataVisualitzacio(), peliculesBase[i].getTitol(), peliculesBase[i].getDescripcio(),
                peliculesBase[i].getQualificacio(), peliculesBase[i].getVegades());
        }

        vector<VisualitzacioSerieDTO> series;
        for (int i = 0; i < seriesBase.size(); ++i) {
            series.emplace_back(seriesBase[i].getDataVisualitzacio(), seriesBase[i].getTitolSerie(), seriesBase[i].getNumTemporada(),
                seriesBase[i].getNumCapitol(), seriesBase[i].getQualificacio(), seriesBase[i].getVegades());
        }

        return ConsultaVisualitzacionsDTO(pelicules, series);
    }
    catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
        throw; // Propagar el error
    }
    catch (const exception& e) {
        cerr << "Error inesperat: " << e.what() << endl;
        throw;
    }
}
