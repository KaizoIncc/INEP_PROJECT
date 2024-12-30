#include "PassarelaVisualitzacioPelicula.h"

PasarelaVisualitzacioPelicula::PasarelaVisualitzacioPelicula()
{
}

PasarelaVisualitzacioPelicula::PasarelaVisualitzacioPelicula(
    string data, string titol, string descripcio,
    string qualificacio, int vegades
) : dataVisualitzacio(data), titol(titol), descripcio(descripcio),
qualificacio(qualificacio), vegades(vegades) {}

PasarelaVisualitzacioPelicula::PasarelaVisualitzacioPelicula(string sobrenom, string nomP, string current_time, string num_visualitzacionsPel) {
    this->sobrenom = sobrenom;
    this->titol = nomP;
    this->current_time = current_time;
    this->num_visualitzacionsPel = num_visualitzacionsPel;
}

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

string PasarelaVisualitzacioPelicula::getSobrenom() {
    return sobrenom;
}

string PasarelaVisualitzacioPelicula::getCurrent_time() {
    return current_time;
}

string PasarelaVisualitzacioPelicula::getNum_visualitzacionsPel() {
    return num_visualitzacionsPel;
}

//Setters
void PasarelaVisualitzacioPelicula::setSobrenom(string sobrenom) {
    this->sobrenom = sobrenom;
}
void PasarelaVisualitzacioPelicula::setNomP(string nomP) {
    this->titol = nomP;
}
void PasarelaVisualitzacioPelicula::setCurrent_time(string current_time) {
    this->current_time = current_time;
}
void PasarelaVisualitzacioPelicula::setNum_visualitzacionsPel(string num_visualitzacionsPel) {
    this->num_visualitzacionsPel = num_visualitzacionsPel;
}

void PasarelaVisualitzacioPelicula::modificar_visualitzacio()
{
    ConnexioBD& conn = ConnexioBD::getInstance(PARAMS);
    string query = "UPDATE inep06.visualitzacio_pelicula SET data = '" + current_time + "', num_visualitzacions = '" + num_visualitzacionsPel + "' WHERE ( sobrenom_usuari = '" + sobrenom + "' AND titol_pelicula = '" + titol + "' )";
    conn.executarComanda(query);
}

void PasarelaVisualitzacioPelicula::insereix()
{
    ConnexioBD& conn = ConnexioBD::getInstance(PARAMS);
    // Crear consulta SQL
    string query = "INSERT INTO inep06.visualitzacio_pelicula (sobrenom_usuari, titol_pelicula, data, num_visualitzacions) VALUES ('" + sobrenom + "', '" + titol + "', '" + current_time + "', '1')";
    // Executar comanda
    conn.executarComanda(query);
}