#pragma once
#include "TxRegistrarUsuari.h"
#include "TxEsborrarUsuari.h"
#include "TxTancaSessio.h"
#include "TxConsultaUsuari.h"
#include "TxIniciSessio.h"
#include "TxInfoVisualitzacions.h"
#include "DTOUsuari.h"
#include "CUModificaUsuari.h"
#include "CUVisualitzarCapitol.h"
#include "TxConsultaSerie.h"
#include "PetitFlix.h"
#include <regex>
#include <ctime>

using namespace std;

class CapaDePresentacio {
private:

	CapaDePresentacio() {};

	~CapaDePresentacio();

	bool esDataValida(const string& dataNaixement);	
	
	bool comprovarCorreu(string correu);

public:

	static CapaDePresentacio& getInstance();

	bool processarIniciarSessio();

	bool processarTancarSessio();

	void processarRegistrarUsuari();

	void processarConsultarUsuari();

	void processarModificarUsuari();
	
	bool processarEsborrarUsuari();

	void processarVisualitzarCapitol();

	void processarVisualitzarPelicula();

	void processarConsultarVisualitzacions();

	void processarConsultarProperesEstrenes();

	void processarConsultarUltimesNovetats();

	void processarConsultarPeliculesMesVistes();
};

