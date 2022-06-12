#include <stdio.h>
#include <stdlib.h>


#ifndef PARSER_H_
#define PARSER_H_

/**
 * @fn int parser_PassengerFromText(FILE*, LinkedList*)
 * @brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * @param pFile Direccion de memoria del archivo que sera parseado.
 * @param pArrayListPassenger puntero a la lista de pasajeros.
 * @return Retorna 1 si esta todo OK y 0 si fallo.
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger);


/**
 * @fn int parser_PassengerFromBinary(FILE*, LinkedList*)
 * @brief Parsea los datos los datos de los pasajeros desde el archivo data.bin (modo binario).
 *
 * @param pFile Direccion de memoria del archivo que sera parseado.
 * @param pArrayListPassenger puntero a la lista de pasajeros.
 * @return Retorna 1 si esta todo OK y 0 si fallo.
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);
#endif /* PARSER_H_ */
