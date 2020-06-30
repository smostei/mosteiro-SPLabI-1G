#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include <string.h>
#include "bicicleta.h"
#include "menu.h"

int cargarListaBicicletas(LinkedList* listaBicis, char* archivoBicis) {

	int retorno = 1;
	int r;
    char id[5], nombreDuenio[25], tipo[20], tiempo[5];
    Bicicleta* bicicleta;
	FILE* pFile = fopen(archivoBicis, "r");

	if(pFile != NULL && listaBicis != NULL) {
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",	id, nombreDuenio, tipo, tiempo);

    	while(!feof(pFile)) {
        	r = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombreDuenio, tipo, tiempo);

            if(r == 4) {
            	bicicleta = newBicicletaParam(id, nombreDuenio, tipo, tiempo);

            	ll_add(listaBicis, bicicleta);
                retorno = 0;
            }
    	}
	}

	fclose(pFile);
	return retorno;
}

int guardarListaBicicletas(LinkedList* listaBicicletas, char* archivoBicis) {

	int retorno = 1;
    int tamLista;

    FILE* pFile = fopen(archivoBicis, "w");
    Bicicleta* bicicleta;

    if(pFile != NULL && listaBicicletas != NULL) {
    	tamLista = ll_len(listaBicicletas);

        fprintf(pFile, "id_bike,nombre,tipo,tiempo\n");

        for(int i = 0; i < tamLista; i++) {
           bicicleta = (Bicicleta*) ll_get(listaBicicletas, i);
           fprintf(pFile, "%d,%s,%s,%d\n", bicicleta->id, bicicleta->nombreDuenio, bicicleta->tipo, bicicleta->tiempo);
        }

        retorno = 0;
    }

    fclose(pFile);
    return retorno;
}

int mostrarBicicletas(LinkedList* listaBicicletas) {
	int retorno = 1;
	int longLista;
	Bicicleta* bicicleta;

	if(listaBicicletas != NULL) {
		longLista = ll_len(listaBicicletas);

        printf("ID Bicicleta		Duenio			  Tipo	  Tiempo\n");
        printf("--------------------------------------------------------------------------\n");

		for(int i = 0; i < longLista; i++) {
			bicicleta = (Bicicleta*) ll_get(listaBicicletas, i);

			if(bicicleta != NULL) {
				printf("%04d         %20s         %10s      %3d", bicicleta->id, bicicleta->nombreDuenio, bicicleta->tipo, bicicleta->tiempo);
				retorno = 0;
			}

	        printf("\n--------------------------------------------------------------------------\n");
		}
	}

	return retorno;
}


void* actualizarTiempoBicicleta(void* elemento) {
	Bicicleta* bicicletaMapeada = (Bicicleta*) elemento;

    int aleatorio;
    aleatorio = rand()%(71) + 50; //El tiempo se asiganara entre 50 y 120 minutos

	setTiempo(bicicletaMapeada, aleatorio);

	return bicicletaMapeada;
}

LinkedList* getListaTiemposActualizados(LinkedList* listaOriginal) {
	LinkedList* listaMapeada = NULL;

	if(listaOriginal != NULL && !ll_isEmpty(listaOriginal)) {
		listaMapeada = ll_map(listaOriginal, actualizarTiempoBicicleta);
	}

	return listaMapeada;
}

int ordenarBicicletaPorTiempo(void* bici1, void* bici2) {
	Bicicleta* primerBici = (Bicicleta*) bici1;
	Bicicleta* segundaBici = (Bicicleta*) bici2;

	int retorno = 0;

	if(primerBici->tiempo < segundaBici->tiempo) {
		retorno = 1;
	}

	if(primerBici->tiempo > segundaBici->tiempo) {
		retorno = -1;
	}

	return retorno;
}

int filtrarBicicletasPorBMX(void* elemento) {
	int retorno = -1;

	Bicicleta* bicicleta = (Bicicleta*) elemento;

	if(bicicleta != NULL) {
		retorno = 0;

		if(strcmp(bicicleta->tipo, "BMX") == 0) {
			retorno = 1;
		}
	}

	return retorno;
}

int filtrarBicicletasPorPlayera(void* elemento) {
	int retorno = -1;

	Bicicleta* bicicleta = (Bicicleta*) elemento;

	if(bicicleta != NULL) {
		retorno = 0;

		if(strcmp(bicicleta->tipo, "PLAYERA") == 0) {
			retorno = 1;
		}
	}

	return retorno;
}

int filtrarBicicletasPorMtb(void* elemento) {
	int retorno = -1;

	Bicicleta* bicicleta = (Bicicleta*) elemento;

	if(bicicleta != NULL) {
		retorno = 0;

		if(strcmp(bicicleta->tipo, "MTB") == 0) {
			retorno = 1;
		}
	}

	return retorno;
}

int filtrarBicicletasPorPaseo(void* elemento) {
	int retorno = -1;

	Bicicleta* bicicleta = (Bicicleta*) elemento;

	if(bicicleta != NULL) {
		retorno = 0;

		if(strcmp(bicicleta->tipo, "PASEO") == 0) {
			retorno = 1;
		}
	}

	return retorno;
}


int generarArchivoPorTipoBicicleta(LinkedList* listaAFiltrar, LinkedList* listaOriginal, char* nuevoArchivo) {
	int retorno = -1;

	switch(menuTipos()) {
	case 1:
		listaAFiltrar = ll_filter(listaOriginal, filtrarBicicletasPorBMX);
		break;
	case 2:
		listaAFiltrar = ll_filter(listaOriginal, filtrarBicicletasPorPlayera);
		break;
	case 3:
		listaAFiltrar = ll_filter(listaOriginal, filtrarBicicletasPorMtb);
		break;
	case 4:
		listaAFiltrar = ll_filter(listaOriginal, filtrarBicicletasPorPaseo);
		break;
	default:
		printf("Opcion invalida!\n\n");
		retorno = 1;
	}

	if(listaAFiltrar != NULL && guardarListaBicicletas(listaAFiltrar, nuevoArchivo) == 0) {
		retorno = 0;
	}

    return retorno;
}

