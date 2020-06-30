#include "bicicleta.h"

#ifndef CONTROLER_H_
#define CONTROLER_H_



#endif /* CONTROLER_H_ */

/** @brief funcion que carga las bicicletas al linked list
 *
 * @param la lista en la que se almacenara el csv
 * @param archivo del que se trae la informacion
 *
 * @return SUCCESS 0 ERROR 1
 */
int cargarListaBicicletas(LinkedList* listaBicis, char* archivoBicis);

/** @brief funcion que guarda las bicicletas del linked list
 *
 * @param la lista de la que se guardara la informacion
 * @param archivo en el que se guardara la informacion
 */
int guardarListaBicicletas(LinkedList* listaBicis, char* archivoBicis);

/** @brief funcion que muestra las bicicletas del linked list
 *
 * @param la lista de la que se guardara la informacion
 */
int mostrarBicicletas(LinkedList* listaBicis);

/** @brief funcion que actualiza el campo tiempo en las bicicletas
 *
 * @param elemento a mapear
 *
 * @return el elemento que se casteara a Bicicleta para actualizar su tiempo
 */
void* actualizarTiempoBicicleta(void* elemento);

/** @brief funcion que devuelve la lista mapeada con tiempos actualizados
 *
 * @param la lista que se intentara mapear
 *
 * @return la linked list mapeada
 */
LinkedList* getListaTiemposActualizados(LinkedList* listaOriginal);

/** @brief funcion que compara dos elementos segun un criterio
 *
 * @param primer campo a comparar
 * @param segundo campo a comparar
 *
 * @return SUCCESS 0 ERROR 1
 */
int ordenarBicicletaPorTipo(void* bici1, void* bici2);

/** @brief funcion que sabe filtrar bicicletas por tipo BMX para pasarsela al filter
 *
 * @param elemento que se intentara filtrar
 *
 * @return SUCCESS 1 ERROR 0
 */
int filtrarBicicletasPorBMX(void* elemento);

/** @brief funcion que sabe filtrar bicicletas por tipo PLAYERA para pasarsela al filter
 *
 * @param elemento que se intentara filtrar
 *
 * @return SUCCESS 1 ERROR 0
 */
int filtrarBicicletasPorPlayera(void* elemento);

/** @brief funcion que sabe filtrar bicicletas por tipo MTB para pasarsela al filter
 *
 * @param elemento que se intentara filtrar
 *
 * @return SUCCESS 1 ERROR 0
 */
int filtrarBicicletasPorMtb(void* elemento);

/** @brief funcion que sabe filtrar bicicletas por tipo PASEO para pasarsela al filter
 *
 * @param elemento que se intentara filtrar
 *
 * @return SUCCESS 1 ERROR 0
 */
int filtrarBicicletasPorPaseo(void* elemento);

/** @brief funcion que genera un archivo nuevo y segun una lista filtrada pasada por parametro
 *
 * @param lista a filtrar
 * @param lista original de la que se va a obtener la informacion
 * @param el archivo en el que se almacenara la informacion
 *
 * @return SUCCESS 1 ERROR 0
 */
int generarArchivoPorTipoBicicleta(LinkedList* listaAFiltrar, LinkedList* listaOriginal, char* nuevoArchivo);
