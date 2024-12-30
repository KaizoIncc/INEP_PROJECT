# README del Fitxer de Configuració Extern

Aquest repositori inclou un fitxer de configuració extern per gestionar els paràmetres de connexió a la base de dades. A continuació s'explica com funciona aquest fitxer i com personalitzar-lo segons les necessitats del vostre entorn.

### Descripció dels Paràmetres

- **servidor**: És el servidor de la base de dades al qual us connecteu. Inclou el nom del servidor o IP, seguit del port (per defecte 3306 per MySQL/MariaDB).
- **usuario**: És el nom d'usuari de la base de dades.
- **password**: És la contrasenya associada a l'usuari de la base de dades.
- **database**: És el nom de la base de dades a la qual voleu accedir.

## Personalització del Fitxer

Per utilitzar aquest projecte en el vostre entorn, heu de modificar els valors dels paràmetres del fitxer de configuració extern per adaptar-los al vostre sistema. Per exemple:

```c
#define PARAMS "servidor=el_meu_servidor:3306 usuario=el_meu_usuari password=la_meva_contrasenya database=la_meva_base_de_dades"
```

### Exemple

Si el vostre servidor és `mysql.local`, l'usuari és `admin`, la contrasenya és `1234` i la base de dades es diu `projecte`, la línia hauria de quedar així:

```c
#define PARAMS "servidor=mysql.local:3306 usuario=admin password=1234 database=projecte"
```

## Integració

Aquest fitxer de configuració s'utilitza per inicialitzar la connexió a la base de dades en el projecte. És important assegurar-se que el fitxer està ben configurat abans d'executar l'aplicació.

## Preguntes o Suport

Si teniu algun dubte sobre com configurar aquest fitxer o qualsevol altre problema relacionat amb el projecte, no dubteu a contactar amb els mantenidors del repositori.
