/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

#ifndef PASSENGER_H_
#define PASSENGER_H_


typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[10];
	char tipoPasajero[15];
	char estadoVuelo[15];
	int isEmpty;

}Passenger;

/**
 * @fn int buscarPassengerId(LinkedList*, int)
 * @brief  Funcion que sirve para buscar el ID de un pasajero.
 *
 * @param pArrayListPassenger  Puntero a la lista de pasajero.
 * @param id ID a comparar
 * @return Retorna el indice del pasajero si tuvo exito.
 */
int buscarPassengerId(LinkedList* pArrayListPassenger, int id);

/**
 * @fn Passenger Passenger_new*()
 * @brief Funcion constructora para crear un nuevo pasajero.
 *
 * @return Retorna el pasajero creado si tuvo exito.
 */
Passenger* Passenger_new();

/**
 * @fn Passenger Passenger_newParametros*(char*, char*, char*, char*, char*, char*, char*)
 * @brief
 *
 * @param idStr idStr ID a cargar en el pasajero pasado como cadena de caracteres.
 * @param nombreStr  Nombre a cargar en el pasajero pasado como cadena de caracteres.
 * @param apellidoStr Apellido a cargar en el pasajero pasado como cadena de caracteres.
 * @param precioStr  precio a cargar en el pasajero pasado como cadena de caracteres.
 * @param codigoVueloStr codigo de vuelo a cargar en el pasajero pasado como cadena de caracteres.
 * @param tipoPasajeroStr tipo pasajero a cargar en el pasajero pasado como cadena de caracteres.
 * @param statusFlightStr estado de vuelo a cargar en el pasajero pasado como cadena de caracteres.
 * @return retorna el pasajero creado si tuvo exito.
 */
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr ,char* codigoVueloStr,char* tipoPasajeroStr,char* statusFlightStr);


/**
 * @fn int Passenger_delete(Passenger*)
 * @brief Libera la memoria ocupada por un pasajero.
 *
 * @param this puntero a la estructura pasajero
 * @return  Retorna 0 si fallo y uno 1 si esta todoOk.
 */
int Passenger_delete(Passenger* this);

/**
 * @fn int Passenger_setId(Passenger*, int)
 * @brief Carga el id del pasajero.
 *
 * @param this Puntero a la lista de pasajero.
 * @param id a cargar en el pasajero.
 * @return Retorna 1 si esta todoOK y 0 si fallo.
 */
int Passenger_setId(Passenger* this,int id);

/**
 * @fn int Passenger_getId(Passenger*, int*)
 * @brief Busca el id del pasajero .
 *
 * @param this Puntero a la lista de pasajero.
 * @param id a cargar en el pasajero.
 * @return Retorna 1 si esta todoOK y 0 si fallo.
 */
int Passenger_getId(Passenger* this,int* id);



/**
 * @fn int Passenger_setNombre(Passenger*, char*)
 * @brief Carga el nombre del pasajero.
 *
 * @param this	 Puntero a la lista de pasajero.
 * @param nombre a cargar en el pasajero.
 * @return Retorna 1 si esta todoOK y 0 si fallo.
 */
int Passenger_setNombre(Passenger* this,char* nombre);



/**
 * @fn int Passenger_getNombre(Passenger*, char*)
 * @brief Busca el nombre del pasajero .
 *
 * @param this Puntero a la lista de pasajero.
 * @param nombre a buscar en el pasajero.
 * @return Retorna 1 si esta todoOK y 0 si fallo.
 */
int Passenger_getNombre(Passenger* this,char* nombre);



/**
 * @fn int Passenger_setApellido(Passenger*, char*)
 * @brief Carga el apellido del pasajero.
 *
 * @param this Puntero a la lista de pasajero.
 * @param apellido a cargar en el pasajero.
 * @return Retorna 1 si esta todoOK y 0 si fallo.
 */
int Passenger_setApellido(Passenger* this,char* apellido);

/**
 * @fn int Passenger_getApellido(Passenger*, char*)
 * @brief busca el apellido del pasajero.
 *
 * @param this Puntero a la lista de pasajero.
 * @param apellido a buscar en el pasajero.
 * @return Retorna 1 si esta todoOK y 0 si fallo.
 */
int Passenger_getApellido(Passenger* this,char* apellido);


/**
 * @fn int Passenger_setCodigoVuelo(Passenger*, char*)
 * @brief codigo a cargar en el pasajero
 *
 * @param this Puntero a la lista de pasajero.
 * @param codigoVuelo a cargar en el pasajero
 * @return Retorna 1 si esta todoOK y 0 si fallo.
 */
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);

/**
 * @fn int Passenger_getCodigoVuelo(Passenger*, char*)
 * @brief  busca el codigo de vuelo del pasajero.
 *
 * @param this this Puntero a la lista de pasajero.
 * @param codigoVuelo a buscar en el pasajero
 * @return Retorna 1 si esta todoOK y 0 si fallo.
 */
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);


/**
 * @fn int Passenger_setTipoPasajero(Passenger*, char*)
 * @brief carga el tipo de pasajero del pasajero
 *
 * @param this Puntero a la lista de pasajero.
 * @param tipoPasajero a cargar en el pasajero
 * @return Retorna 1 si esta todoOK y 0 si fallo.
 */
int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);

/**
 * @fn int Passenger_getTipoPasajero(Passenger*, char*)
 * @brief busca el tipo de pasajero del pasajero
 *
 * @param this Puntero a la lista de pasajero.
 * @param tipoPasajero a buscar en el pasajero
 * @return Retorna 1 si esta todoOK y 0 si fallo.
 */
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);

/**
 * @fn int Passenger_setStatusFlight(Passenger*, char*)
 * @brief carga el estado de vuelo del pasajero
 *
 * @param this Puntero a la lista de pasajero.
 * @param estadoVuelo carga el estado de vuelo en el pasajero
 * @return Retorna 1 si esta todoOK y 0 si fallo.
 */
int Passenger_setStatusFlight(Passenger* this,char* estadoVuelo);

/**
 * @fn int Passenger_getStatusFlight(Passenger*, char*)
 * @brief busca el estado de vuelo del pasajero
 *
 * @param this Puntero a la lista de pasajero.
 * @param estadoVuelo buscar el estado de vuelo del pasajero
 * @return Retorna 1 si esta todoOK y 0 si fallo.
 */
int Passenger_getStatusFlight(Passenger* this,char* estadoVuelo);

/**
 * @fn int Passenger_setPrecio(Passenger*, float)
 * @brief  carga el precio del pasajero
 *
 * @param this Puntero a la lista de pasajero.
 * @param precio carga el precio en el pasajero
 * @return Retorna 1 si esta todoOK y 0 si fallo.
 */
int Passenger_setPrecio(Passenger* this,float precio);

/**
 * @fn int Passenger_getPrecio(Passenger*, float*)
 * @brief busca el precio del pasajero
 *
 * @param this Puntero a la lista de pasajero.
 * @param precio buscar el precio en el pasajero
 * @return Retorna 1 si esta todoOK y 0 si fallo.
 */
int Passenger_getPrecio(Passenger* this,float* precio);

/**
 * @fn int Passenger_SortId(void*, void*)
 * @brief Funcion que compara los ids de 2 pasajeros para poder ordenarlos luego.
 *
 * @param item1 variable para referirse al primer pasajero.
 * @param item2 variable para referirse al segundo pasajero.
 * @return Retorna 1 para que luego se ordene de forma ascendente o -1 para que se ordene de forma descendente.
 */
int Passenger_SortId(void* item1, void* item2);

/**
 * @fn int Passenger_SortName(void*, void*)
 * @brief  Funcion que compara los nombres de 2 pasajeros para poder ordenarlos luego.
 *
 * @param item1 variable para referirse al primer pasajero.
 * @param item2 variable para referirse al segundo pasajero.
 * @return Retorna 1 para que luego se ordene de forma ascendente o -1 para que se ordene de forma descendente.
 */
int Passenger_SortName(void* item1, void* item2);

/**
 * @fn int Passenger_SortLastName(void*, void*)
 * @brief  Funcion que compara los apellidos de 2 pasajeros para poder ordenarlos luego.
 *
 * @param item1 variable para referirse al primer pasajero.
 * @param item2 variable para referirse al segundo pasajero.
 * @return Retorna 1 para que luego se ordene de forma ascendente o -1 para que se ordene de forma descendente.
 */
int Passenger_SortLastName(void* item1, void* item2);

/**
 * @fn int Passenger_SortPrice(void*, void*)
 * @brief  Funcion que compara los precios de 2 pasajeros para poder ordenarlos luego.
 *
 * @param item1 variable para referirse al primer pasajero.
 * @param item2 variable para referirse al segundo pasajero.
 * @return Retorna 1 para que luego se ordene de forma ascendente o -1 para que se ordene de forma descendente.
 */
int Passenger_SortPrice(void* item1, void* item2);

/**
 * @fn int Passenger_SortStatusFlight(void*, void*)
 * @brief Funcion que compara los estados de vuelo de 2 pasajeros para poder ordenarlos luego.
 *
 * @param item1 variable para referirse al primer pasajero.
 * @param item2 variable para referirse al segundo pasajero.
 * @return Retorna 1 para que luego se ordene de forma ascendente o -1 para que se ordene de forma descendente.
 */
int Passenger_SortStatusFlight(void* item1, void* item2);

/**
 * @fn int Passenger_SortFlyCode(void*, void*)
 * @brief Funcion que compara los codigo de vuelo de 2 pasajeros para poder ordenarlos luego.
 *
 * @param item1 variable para referirse al primer pasajero.
 * @param item2 variable para referirse al segundo pasajero.
 * @return Retorna 1 para que luego se ordene de forma ascendente o -1 para que se ordene de forma descendente.
 */
int Passenger_SortFlyCode(void* item1, void* item2);

/**
 * @fn int Passenger_SortTypePassenger(void*, void*)
 * @brief Funcion que compara los tipo de pasajero de 2 pasajeros para poder ordenarlos luego.
 *
 * @param item1 variable para referirse al primer pasajero.
 * @param item2 variable para referirse al segundo pasajero.
 * @return Retorna 1 para que luego se ordene de forma ascendente o -1 para que se ordene de forma descendente.
 */
int Passenger_SortTypePassenger(void* item1, void* item2);
#endif /* PASSENGER_H_ */

