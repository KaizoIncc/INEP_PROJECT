
#include <vector>
#include <string>

using namespace std;

class PeliculaDTO {
private:
    string titol;
    string qualificacioEdats;
    int duracio;
    int numVisualitzacions;
    string dataVisualitzacio;

public:
    // ructor
    PeliculaDTO( string titol,  string qualificacioEdats, int duracio, int numVisualitzacions,  string dataVisualitzacio = "");

    // Getters
    string getTitol();
    string getQualificacioEdats();    
    int getDuracio();
    int getNumVisualitzacions();
    string getDataVisualitzacio();

    // Método para verificar si hay fecha de visualización
    bool teDataVisualitzacio();
};
