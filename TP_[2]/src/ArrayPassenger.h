/*
 * ArrayPassenger.h
 *
 *  Created on: 13 may 2022
 *      Author: antonella calabrese
 */
#include <stdio.h>
#include <stdlib.h>

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
/**
 * @struct structura anidada de los tipo de pasajero.
 * @brief
 *
 */
typedef struct{
	int idTypePassenger;
	char descripcion[20];
} eTypePassenger;

/**
 * @struct structura con los campos de cada pasajero.
 * @brief
 *
 */
typedef struct{
 int id;
 char name[51];
 char lastname[51];
 float price;
 char flycode[10];
 int idTypePassenger;
 int statusFlight;
 int isEmpty;
}ePassenger;

#endif /* ARRAYPASSENGER_H_ */
/**
 * @fn int initPassenger(ePassenger[], int)
 * @brief Funcion Para indicar que todas las posiciones del array están vacías, esta función pone la bandera
          (isEmpty) en TRUE en todas las posiciones del array.
 *
 * @param lista por la lista le paso los campos de la estructura.
 * @param tam por el tam le paso la cant de estructuras que hay.
 * @return
 */
int initPassenger(ePassenger lista[], int tam);

/**
 * @fn int addPassenger(ePassenger[], int, int*)
 * @brief funcion que permite ingresar un pasajero calculando automáticamente el
          número de Id. Agrega en un array de pasajeros existente los valores recibidos como parámetro en la primer
          posición libre.
 *
 * @param lista lista por la lista le paso los campos de la estructura.
 * @param tam por el tam le paso la cant de estructuras que hay.
 * @param pId por el id incrementamos la variable nextId del main para ver los lugares vacios.
 * @return retorna 1 si todo salio bien
 */
int addPassenger(ePassenger lista[], int tam, int* pId);

/**
 * @fn int findPassengerById(ePassenger[], int, int)
 * @brief funcion que busca un pasajero recibiendo como parámetro de búsqueda su Id.
 *
 * @param lista
 * @param tam por el tam le paso la cant de estructuras que hay.
 * @param id busca el id que fue ingresado para modificarlo o darle de baja
 * @return retorna el indice seleccionado
 */
int findPassengerById(ePassenger lista[], int tam, int id);

/**
 * @fn int menuModificacion()
 * @brief funcion para que el usario eliga que campo de la estructura moficar en la funcion modificar
 *
 * @return retorna la opcion elegida
 */
int menuModificacion();

/**
 * @fn int modificationPassenger(ePassenger[], int)
 * @brief funcion para modificar uno de los campos ingresados de la estructura
 *
 * @param lista le paso por parametro los campos de la estructura.
 * @param tam por tam le paso por parametro la cant de esctruras de pasajeros.
 * @return retorna 1 si todo salio bien
 */
int modificationPassenger(ePassenger lista[], int tam);

/**
 * @fn int searchFree(ePassenger[], int)
 * @brief esta funcion busca alguna estructura vacia (isEmpty).
 *
 * @param lista le paso por parametro los campos de la estructura
 * @param tam le paso por tam la cant de estructuras.
 * @return retorna el indice que este isEmpty
 */
int searchFree(ePassenger lista[], int tam);

/**
 * @fn int printPassengers(ePassenger[], int)
 * @brief  funcion que imprime en pantalla el array todos los pasajeros ingresados
 *
 * @param lista le paso por param todas las estructuras
 * @param tam le paso por tam la cant de estructuras.
 * @return
 */
int printPassengers(ePassenger lista[] , int tam);


/**
 * @fn void printPassenger(ePassenger)
 * @brief funcion que Imprime el array de pasajeros de forma encolumnada.
 *
 * @param onePassenger por onePassenger guardo los datos de la estructura para luego mostrarlo.
 */
void printPassenger(ePassenger onePassenger);


/**
 * @fn int removePassenger(ePassenger[], int)
 * @brief funcion que Elimina de manera lógica un pasajero recibiendo como parametro la estructura y el tamaño
 *
 * @param lista le paso por parametro los campos de la estructura.
 * @param tam le paso por tam la cant de pasajeros.
 * @return retorna AllOk si salio todo bien
 */
int removePassenger(ePassenger lista[], int tam);


/**
 * @fn int sortPassenger(ePassenger[], int, int)
 * @brief funcion que ordena el array de pasajeros por apellido y tipo de pasajero de manera ascendente o
          descendente.
 *
 * @param lista  le paso por parametro los campos de la estructura.
 * @param tam le paso por tam la cant de pasajeros.
 * @param order [1] indicate UP - [0] indicate DOWN
 * @return retorna 1 si todo salio bien.
 */
int sortPassenger(ePassenger lista[], int tam, int order);


/**
 * @fn int promedio(ePassenger[], int)
 * @brief funcion para calcular el promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.
 *
 * @param lista le paso por parametro los campos de la estructura.
 * @param tam le paso por tam la cant de pasajeros.
 * @return retorna 1 si AllOK salio bien
 */
int promedio(ePassenger lista[], int tam);


/**
 * @fn int sortPassengerByCode(ePassenger[], int, int)
 * @brief Ordena el array de pasajeros por código de vuelo y estado de vuelo de manera ascendente o
          descendente.
 *
 * @param lista  le paso por parametro los campos de la estructura.
 * @param tam le paso por tam la cant de pasajeros.
 * @param order
 * @return [1] indicate UP - [0] indicate DOWN
 */
int sortPassengerByCode(ePassenger lista[], int tam, int order);


/**
 * @fn int informList(ePassenger[], int)
 * @brief  funcion que informa 4 opciones a elegir por el usuario.
 *
 * @param lista le paso por parametro los campos de la estructura.
 * @param tam le paso por tam la cant de pasajeros.
 * @return retorna allOk si todo salio bien.
 */
int informList(ePassenger lista[], int tam);


/**
 * @fn int submenuListado()
 * @brief funcion que luego es llamada en informList para mostrar un submenu para saber si ordenar
 *        de manera ascendente o descendente los pasajeros.
 *
 * @return retorna la opcion elegida.
 */
int submenuListado();


/**
 * @fn int flagReset(ePassenger[], int, int*)
 * @brief funcion que sirve para resetear las flags en el main para que si no ingrese ningun pasajero no me deje
 * 		  entrar al menu
 *
 * @param list le paso por parametro los campos de la estructura.
 * @param tam le paso por tam la cant de pasajeros.
 * @param flag
 * @return
 */
int flagReset(ePassenger list[], int tam, int* flag);


/**
 * @fn void initListPassengers(ePassenger*)
 * @brief
 *
 * @param lista
 */
void initListPassengers(ePassenger* lista);






