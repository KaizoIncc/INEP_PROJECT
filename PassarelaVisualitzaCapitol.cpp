#include "PassarelaVisualitzaCapitol.h"

//Constructora
PassarelaVisualitzaCapitol::PassarelaVisualitzaCapitol(string titolSerie, int numT, int numC, string dataV, int numV) {	
	titolS = titolSerie;
	numTemporada = numT;
	numCapitol = numC;
	dataVisualitzacio = dataV;
	numVisualitzacions = numV;
}

PassarelaVisualitzaCapitol::PassarelaVisualitzaCapitol(string sobrenomU, string titolSerie, int numT, int numC, string dataV, int numV) {
	sobrenom = sobrenomU;
	titolS = titolSerie;
	numTemporada = numT;
	numCapitol = numC;
	dataVisualitzacio = dataV;
	numVisualitzacions = numV;
}

//Constructora per defecte 
PassarelaVisualitzaCapitol::PassarelaVisualitzaCapitol() {

}

//Destructora
PassarelaVisualitzaCapitol::~PassarelaVisualitzaCapitol() {

}

//Getters
string PassarelaVisualitzaCapitol::getSobrenom() {
	return sobrenom;
}

string PassarelaVisualitzaCapitol::getTitol() {
	return titolS;
}

int PassarelaVisualitzaCapitol::getNumeroT() {
	return numTemporada;
}

int PassarelaVisualitzaCapitol::getNumeroC() {
	return numCapitol;
}

string PassarelaVisualitzaCapitol::getDataV() {
	return dataVisualitzacio;
}

int PassarelaVisualitzaCapitol::getNumeroV() {
	return numVisualitzacions;
}

//Setters
void PassarelaVisualitzaCapitol::setData(string data) {
	dataVisualitzacio = data;
}

void PassarelaVisualitzaCapitol::setNumV(int numVisu) {
	numVisualitzacions = numVisu;
}

void PassarelaVisualitzaCapitol::insereix() {
	ConnexioBD& conn = ConnexioBD::getInstance(PARAMS);
	string query = "INSERT INTO visualitzacio_capitol (sobrenom_usuari, titol_serie, num_temporada, num_capitol, data, num_visualitzacions) "
		"VALUES ('" + sobrenom + "', '" + titolS + "', '" + to_string(numTemporada) + "', '" + to_string(numCapitol) + "', '" +
		dataVisualitzacio + "', 1)";
	conn.executarComanda(query);
}

void PassarelaVisualitzaCapitol::actualitza() {
	ConnexioBD& conn = ConnexioBD::getInstance(PARAMS);
	string query = "UPDATE visualitzacio_capitol SET data = '" + dataVisualitzacio + "', num_visualitzacions = '" + to_string(numVisualitzacions + 1) + "' "
		"WHERE sobrenom_usuari = '" + sobrenom + "' AND titol_serie = '" + titolS + "' AND num_temporada = '" + to_string(numTemporada) + "' AND num_capitol = '" + to_string(numCapitol) + "'";
	conn.executarComanda(query);
}

