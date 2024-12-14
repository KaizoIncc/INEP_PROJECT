#pragma once
#include "TxConsultaUsuari.h"
#include "PassarelaUsuari.h"
#include "DTOUsuari.h"
#include "PetitFlix.h"

class CUModificaUsuari {
public:
	CUModificaUsuari();

	~CUModificaUsuari();

	DTOUsuari consultaUsuari();

	void modificarUsuari(string nomU, string contrasenyaU, string correuElectronicU, string dataNaixamentU, string modalitatU);

private:	

};

