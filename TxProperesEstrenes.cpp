#include "TxProperesEstrenes.h"

//constructora
TxProperesEstrenes::TxProperesEstrenes(string modalitat) {
	this->modalitat = modalitat;
}

//destructora
TxProperesEstrenes::~TxProperesEstrenes() {}

void TxProperesEstrenes::executar() {

	auto now = chrono::system_clock::now();
	time_t current_time1 = chrono::system_clock::to_time_t(now);
	ostringstream dataActualStream;
	dataActualStream << put_time(localtime(&current_time1), "%Y-%m-%d");
	string dataActual = dataActualStream.str();

	CercadoraCapitol cercadora_capitol;
	CercadoraPelicules CercadoraPelicula;

	if (modalitat == "Infantil") {
		capitols = cercadora_capitol.cercaPerEstrenaInfantil(dataActual);
		pelicules = CercadoraPelicula.cercaPerEstrenaInfantil(dataActual);
	}
	else {

		vector<PeliculaInfo> Peli = CercadoraPelicula.cercaPerEstrena(dataActual);
		CercadoraContingut CercadoraContingut;
		PassarelaContingut contingut;
		for (int i = 0; i < Peli.size(); i++) {
			contingut = CercadoraContingut.cercaContingutPeli(Peli[i].getTitol());
			pelicules.push_back(DTOPeli(Peli[i].getTitol(), contingut.getDescripcio(), contingut.getQualificacio(), Peli[i].getDataE(), Peli[i].getDuracioS()));
		}

		if (modalitat == "Completa") {
			capitols = cercadora_capitol.cercaPerEstrena(dataActual);
		}
	}

}
vector<DTOProperesEstrenes> TxProperesEstrenes::obteResultat() {
	vector<DTOProperesEstrenes> properes_estrenes;
	CercadoraCapitol cercadoraCapitol;
	string data_estrena_capitol;
	if (modalitat == "Cinefil") {
		for (int i = 0; i < pelicules.size(); i++) {
			properes_estrenes.push_back(DTOProperesEstrenes(pelicules[i].getDataE(), "Pel·lícula", pelicules[i].getTitol(), pelicules[i].getQualificacio(), pelicules[i].getDuracio() + " min"));
		}
		return properes_estrenes;
	}
	else {
		int p = 0, c = 0;
		for (int i = 0; i < 5; i++) {
			if (p < pelicules.size()) {
				if (c < capitols.size()) {
					int anyP = stoi(pelicules[p].getDataE().substr(0, 4));
					int mesP = stoi(pelicules[p].getDataE().substr(5, 2));
					int diaP = stoi(pelicules[p].getDataE().substr(8, 2));

					int anyC = stoi(capitols[c].getDataEstrena().substr(0, 4));
					int mesC = stoi(capitols[c].getDataEstrena().substr(5, 2));
					int diaC = stoi(capitols[c].getDataEstrena().substr(8, 2));

					if (anyP < anyC || (anyP == anyC && mesP < mesC) || (anyP == anyC && mesP == mesC && diaP < diaC)) {
						properes_estrenes.push_back(DTOProperesEstrenes(pelicules[p].getDataE(), "Pelicula", pelicules[p].getTitol(), pelicules[p].getQualificacio(), pelicules[p].getDuracio() + " min"));
						p++;
					}
					else {
						properes_estrenes.push_back(DTOProperesEstrenes(capitols[c].getDataEstrena(), "Serie", capitols[c].getTitolSerie(), capitols[c].getQualificacio(), "Temporada " + capitols[c].getNumeroTemporada()));
						c++;
					}
				}
				else {
					properes_estrenes.push_back(DTOProperesEstrenes(pelicules[p].getDataE(), "Pelicula", pelicules[p].getTitol(), pelicules[p].getQualificacio(), pelicules[p].getDuracio() + " min"));
					p++;
				}
			}
			else if (c < capitols.size()) {
				properes_estrenes.push_back(DTOProperesEstrenes(capitols[c].getDataEstrena(), "Serie", capitols[c].getTitolSerie(), capitols[c].getQualificacio(), "Temporada " + capitols[c].getNumeroTemporada()));
				c++;
			}
		}
	}
	return properes_estrenes;
}