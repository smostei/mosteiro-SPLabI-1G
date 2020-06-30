#include "bicicleta.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Bicicleta* newBicicleta() {
	Bicicleta* this = (Bicicleta*) malloc(sizeof(Bicicleta));

	if(this != NULL) {
		this->id = 0;
		this->tiempo = 0;
		strcpy(this->nombreDuenio, "");
		strcpy(this->tipo, "");
	}

	return this;
}

Bicicleta* newBicicletaParam(char* idStr, char* nombreDuenio, char* tipo, char* tiempoStr) {

	Bicicleta* this = newBicicleta();

	if(this != NULL) {
		int id = atoi(idStr);
		int tiempo = atoi(tiempoStr);

		if(setId(this, id) || setNombreDuenio(this, nombreDuenio) ||
				setTipo(this, tipo) || setTiempo(this, tiempo))
		{
			free(this);
			this = NULL;
		}
	}

	return this;
}

int setId(Bicicleta* bicicleta, int id) {
	int retorno = 1;

	if(bicicleta != NULL) {
		bicicleta->id = id;
		retorno = 0;
	}

	return retorno;
}

int getId(Bicicleta* bicicleta, int* id) {
	int retorno = 1;

	if(bicicleta != NULL && id != NULL) {
		*id = bicicleta->id;
		retorno = 0;
	}

	return retorno;
}

int setNombreDuenio(Bicicleta* bicicleta, char* nombreDuenio) {
	int retorno = 1;

	if(bicicleta != NULL) {
		strcpy(bicicleta->nombreDuenio, nombreDuenio);
		retorno = 0;
	}

	return retorno;
}

int getNombreDuenio(Bicicleta* bicicleta, char* nombreDuenio) {
	int retorno = 1;

	if(bicicleta != NULL && nombreDuenio != NULL) {
		strcpy(nombreDuenio, bicicleta->nombreDuenio);
		retorno = 0;
	}

	return retorno;
}

int setTipo(Bicicleta* bicicleta, char* tipo) {
	int retorno = 1;

	if(bicicleta != NULL) {
		strcpy(bicicleta->tipo, tipo);
		retorno = 0;
	}

	return retorno;
}

int getTipo(Bicicleta* bicicleta, char* tipo) {
	int retorno = 1;

	if(bicicleta != NULL && tipo != NULL) {
		strcpy(tipo, bicicleta->tipo);
		retorno = 0;
	}

	return retorno;
}

int setTiempo(Bicicleta* bicicleta, int tiempo) {
	int retorno = 1;

	if(bicicleta != NULL) {
		bicicleta->tiempo = tiempo;
		retorno = 0;
	}

	return retorno;
}

int getTiempo(Bicicleta* bicicleta, int* tiempo) {
	int retorno = 1;

	if(bicicleta != NULL && tiempo != NULL) {
		*tiempo = bicicleta->tiempo;
		retorno = 0;
	}

	return retorno;
}

