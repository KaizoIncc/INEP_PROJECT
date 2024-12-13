#include "TxIniciSessio.h"

TxIniciSessio::TxIniciSessio(string sobrenomU, string contrasenyaU) {
	sobrenom = sobrenomU;
	contrasenya = contrasenyaU;
	sessioIniciada = false;
}

TxIniciSessio::~TxIniciSessio() {

}

void TxIniciSessio::executar() {		
	CercadoraUsuari userC = CercadoraUsuari();
	PassarelaUsuari userP = userC.cercaPerSobrenom(sobrenom);
	if (userP.getContrasenya() == contrasenya) {
		sessioIniciada = true;
		PetitFlix petitflix = PetitFlix::getInstance();
		petitflix.iniciarSessio(userP);		
	} else throw exception ("Usuari o contrasenya incorrecta");
}

bool TxIniciSessio::obteResultat()  {
	return sessioIniciada;
}
