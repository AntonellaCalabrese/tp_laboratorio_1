/*
 * validacion.h
 *
 *  Created on: 14 abr 2022
 *      Author: antonella calabrese
 */

#ifndef VALIDACION_H_
#define VALIDACION_H_



#endif /* VALIDACION_H_ */
/**
 * @fn int getNumero(int*, char*, char*, int, int, int)
 * @brief funcion de tipo entera que sirve para validar que lo que el usuario ingrese en el menú de opciones sean numeros y eliga una opcion
 *
 * @param pResultado variable de tipo entera con puntero donde se almacena la opcion elegida por el usuario del menú.
 * @param mensaje variable de tipo char con puntero donde se almacena el mensaje para mostrar en pantalla para que el usuario decida cual opcion elegir.
 * @param msjError variable de tipo char con puntero donde se almacena el mensaje de error si el cliente no accede bien a las opciones del menú.
 * @param min variable de tipo entera donde se almacena el minimo de numeros que puede el usuario seleccionar en el menú.
 * @param max variable de tipo entera donde se almacena el maximo de numeros que puede el usuario seleccionar en el menú.
 * @param reintentos variable de tipo entera donde se almacena la cant de veces que el usuario se puede equivocar para entrar al menú correctamente.
 * @return el return devuelve a getNumero la opcion elegida del menú por el usuario.
 */
int getNumero(int* pResultado, char* mensaje, char* msjError, int min, int max, int reintentos);

/**
 * @fn int getCaracter(char*, char*, char*, char, char)
 * @brief funcion de tipo entera que sirve para validar que lo que el usuario ingrese en el menú de opciones sean caracteres y eliga una opcion
 *
 * @param caracter variable char con puntero donde se almacena la opcion elegida por el usuario.
 * @param mensaje variable de tipo char con puntero donde se almacena el mensaje para mostrar en pantalla para que el usuario decida cual opcion elegir.
 * @param mensajeError variable de tipo char con puntero donde se almacena el mensaje de error si el cliente no accede bien a las opciones.
 * @param caracterVal1 variable de tipo char donde se guarda la primer opcion a elegir. incluso le he agreagado la función tolower que convierte un Tipo de dato carácter a minúscula
 *  	para que cuando el usuario en el case 6 tenga que elegir entre S o N y sin queres lo ponga en mayuscula con tolower, se convierta en Minuscula.
 * @param caracterVal2 variable de tipo char donde se guarda el segunda opcion a elegir.
 * @return el return devuelve la opcion elegida por el usuario.
 */
int getCaracter(char* caracter, char* mensaje, char* mensajeError, char caracterVal1, char caracterVal2);
