#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "LinkedList.h"
#include "controller.h"
#include "bicicleta.h"

#define SUCCESS 0
#define ERROR 1

int main() {

	srand (time(NULL));
	char seguir = 's';
	char confirmarRespuesta;

	LinkedList* listaBicicletas = ll_newLinkedList();
	LinkedList* listaMapeada = NULL;
	LinkedList* listaFiltrada = NULL;

	char* ARCHIVO_BICICLETAS = "bicicletas.csv";
	char * ARCHIVO_TEXTO = "bicicletasMapeadas.txt";
	char* ARCHIVO_BICICLETAS_POR_TIPO = "bicicletasFiltradasTipo.csv";

	do {
		switch(menuPrincipal()) {
			case 1:
				if(cargarListaBicicletas(listaBicicletas, ARCHIVO_BICICLETAS) == SUCCESS) {
					printf("Las bicicletas han sido cargados con exito!\n\n");
				} else {
					printf("No se pudieron cargar las bicicletas\n\n");
				}
				break;
			case 2:
				if(listaMapeada != NULL) {
					if(mostrarBicicletas(listaMapeada) == ERROR) {
						printf("No hay bicicletas para mostrar\n\n");
					}
				} else {
					if(mostrarBicicletas(listaBicicletas) == ERROR) {
						printf("No hay bicicletas para mostrar\n\n");
					}
				}
				break;
			case 3:
				if(!ll_isEmpty(listaBicicletas)) {
					listaMapeada = getListaTiemposActualizados(listaBicicletas);

					if(listaMapeada != NULL && !ll_isEmpty(listaMapeada)) {
						printf("Se han actualizado los tiempos de la carrera!\n\n");
					} else {
						printf("Hubo un error al actualizar los tiempos\n\n");
					}
				}
				break;
			case 4:
				if(listaMapeada != NULL) {
					if(generarArchivoPorTipoBicicleta(listaFiltrada, listaMapeada, ARCHIVO_BICICLETAS_POR_TIPO) == SUCCESS) {
						printf("Se ha generado un archivo con las bicicletas almacenadas segun el tipo!\n\n");
					}
				} else if(listaBicicletas != NULL) {
					if(generarArchivoPorTipoBicicleta(listaFiltrada, listaBicicletas, ARCHIVO_BICICLETAS_POR_TIPO) == SUCCESS) {
						printf("Se ha generado un archivo con las bicicletas almacenadas segun el tipo!\n\n");
					}
				}
				break;
			case 5:
				if(listaMapeada != NULL) {
					ll_sort(listaMapeada, ordenarBicicletaPorTiempo, 0);
					mostrarBicicletas(listaMapeada);
					printf("\n\nSe han ordenado las bicicletas por tiempo ascendente!\n\n");
				} else if(listaBicicletas != NULL) {
					ll_sort(listaBicicletas, ordenarBicicletaPorTiempo, 0);
					mostrarBicicletas(listaMapeada);
					printf("\n\nSe han ordenado las bicicletas por tiempo ascendente!\n\n");
				} else {
					printf("Hubo un error al intentar ordenar las bicicletas\n\n");
				}
				break;
			case 6:
				if(!ll_isEmpty(listaMapeada)) {
					if(guardarListaBicicletas(listaMapeada, ARCHIVO_TEXTO) == SUCCESS) {
						printf("Las bicicletas han sido guardadas con exito!\n\n");
					} else {
						printf("Hubo un error al intentar guardar las bicicletas\n\n");
					}
				} else {
					printf("No hay datos para guardar\n\n");
				}
				break;
			case 7:
				printf("Desea salir? s/n\n");
				fflush(stdin);
				scanf("%c", &confirmarRespuesta);
				if(confirmarRespuesta == 's')
					seguir = 'n';
				printf("\nSaliste del programa");
				break;
			default:
				printf("Opcion invalida!\n\n");
		}

        system( "read -n 1 -s -p \"Presione enter para continuar...\"" );

	} while(seguir == 's');

	return EXIT_SUCCESS;
}
