#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int menuPrincipal() {
	int respuesta;

	printf("1) Cargar lista de bicicletas\n");
	printf("2) Mostrar lista de bicicletas\n");
	printf("3) Asignar tiempos\n");
	printf("4) Crear archivo nuevo filtrando las bicicletas del tipo seleccionado\n");
	printf("5) Mostrar posiciones ordenadas por tiempo ASC\n");
	printf("6) Guardar posiciones\n");
	printf("7) Salir\n\n");

	printf("Elige una opcion: ");
	scanf("%d", &respuesta);

	return respuesta;
}

int menuTipos() {
	int respuesta;

	printf("1) BMX\n");
	printf("2) PLAYERA\n");
	printf("3) MTB\n");
	printf("4) PASEO\n");
	printf("Elige el tipo de la bici: ");

	scanf("%d", &respuesta);

	return respuesta;
}
