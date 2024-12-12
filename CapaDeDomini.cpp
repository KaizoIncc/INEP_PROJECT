#include "CapaDeDomini.h"

CapaDeDomini& CapaDeDomini::getInstance() {
	static CapaDeDomini instance;
	return instance;
}

CapaDeDomini::~CapaDeDomini() {

}

void CapaDeDomini::iniciarSessio(string sobrenom, string contrasenya) {		
	CercadoraUsuari userC = CercadoraUsuari();
	PassarelaUsuari userP = userC.cercaPerSobrenom(sobrenom);
	if (userP.getContrasenya() == contrasenya) {
		PetitFlix& petitflix = PetitFlix::getInstance();
		petitflix.iniciarSessio(userP);
		sessioIniciada = true;
	} else throw exception ("Usuari o contrasenya incorrecta");
}

bool CapaDeDomini::obteResultat() const {
	return sessioIniciada;
}
