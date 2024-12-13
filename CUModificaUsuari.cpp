#include "CUModificaUsuari.h"

CUModificaUsuari::CUModificaUsuari() {}

CUModificaUsuari::~CUModificaUsuari() {}

/*DTOUsuari CUModificaUsuari::consultaUsuari() {
	TxConsultaUsuari operacio;
	operacio.executar();	
	return DTOUsuari(operacio.obteUsuari());
}*/

void CUModificaUsuari::modificarUsuari(string nomU, string contrasenyaU, string correuElectronicU, string dataNaixamentU, string modalitatU) {
	PetitFlix consola = PetitFlix::getInstance();
	consola.refrescarPantalla(nomU, contrasenyaU, correuElectronicU, dataNaixamentU, modalitatU);
}
