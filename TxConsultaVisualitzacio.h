#pragma once

#include "CercadoraVisualitzacio.h"
#include "PassarelaVisualitzacioPelicula.h"
#include "DTOConsultaVisualitzacio.h"
#include "PassarelaVisualitzacioSerie.h"
#include "PetitFlix.h"
#include <iostream>
#include <vector>
#include <string>

class TxConsultaVisualitzacio {
private:

public:
	TxConsultaVisualitzacio();

	~TxConsultaVisualitzacio();

	ConsultaVisualitzacionsDTO executar();
};