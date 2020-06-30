
#ifndef USUARIO_H_
#define USUARIO_H_

typedef struct {
	int id;
	char nombreDuenio[25];
	char tipo[20];
	int tiempo;
} Bicicleta;

#endif /* USUARIO_H_ */

Bicicleta* newBicicleta();
Bicicleta* newBicicletaParam(char* idStr, char* nombreDuenio, char* tipo, char* tiempoStr);

int setId(Bicicleta* bicicleta, int id);
int getId(Bicicleta* bicicleta, int* id);

int setNombreDuenio(Bicicleta* bicicleta, char* nombreDuenio);
int getNombreDuenio(Bicicleta* bicicleta, char* nombreDuenio);

int setTipo(Bicicleta* bicicleta, char* tipo);
int getTipo(Bicicleta* bicicleta, char* tipo);

int setTiempo(Bicicleta* bicicleta, int tiempo);
int getTiempo(Bicicleta* bicicleta, int* tiempo);


