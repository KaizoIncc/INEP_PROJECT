#pragma once

#include "CercadoraPelicula.h"
#include "PassarelaPelicula.h"
#include "DTOPelicula.h"
#include "PetitFlix.h"
#include <string>
#include <vector>
using namespace std;

class TxConsultaPeli {
private:
	
public:

	TxConsultaPeli();

	~TxConsultaPeli();

	vector<PeliculaDTO> executar();
};