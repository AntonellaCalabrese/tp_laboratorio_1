/*
 * utn.h
 *
 *  Created on: 15 jun 2022
 *      Author: antonella
 */
#include <stdio.h>
#include <stdlib.h>
#include "../inc/Controller.h"
#include "../inc/Passenger.h"

#ifndef INC_UTN_H_
#define INC_UTN_H_

/**
 * @fn int getNumero(int*, char*, char*, int, int, int)
 * @brief con esta funcion valido que el usuario solo ingrese numeros.
 *
 * @param pResultado variable de tipo entera con puntero donde se almacena la opcion elegida por el usuario del men�.
 * @param mensaje variable de tipo char con puntero donde se almacena el mensaje para mostrar en pantalla para que el usuario decida cual opcion elegir.
 * @param msjError variable de tipo char con puntero donde se almacena el mensaje de error si el cliente no accede bien a las opciones del men�.
 * @param min variable de tipo entera donde se almacena el minimo de numeros que puede el usuario seleccionar en el men�.
 * @param max variable de tipo entera donde se almacena el maximo de numeros que puede el usuario seleccionar en el men�.
 * @param reintentos variable de tipo entera donde se almacena la cant de veces que el usuario se puede equivocar para entrar al men� correctamente.
 * @return el return devuelve a getNumero la opcion elegida del men� por el usuario.
 */
int getNumero(int* pResultado, char* mensaje, char* msjError, int min, int max, int reintentos);

/**
 * @fn int pedirEntero(int*, char*, char*, int, int)
 * @brief con esta funcion valida que el usuario solo ingrese enteros
 *
 * @param entero variable de tipo entera que permite que el usuario solo ingrese enteros.
 * @param mensaje variable de tipo entera que almacena el msj a imprimir en pantalla
 * @param mensajeError variable de tipo entera que almacena el msj de error si el usuario ingresa otra cosa que no sea entero
 * @param min variable de tipo entera donde se almacena el minimo de enteros que puede el usuario seleccionar en el men�.
 * @param max variable de tipo entera donde se almacena el maximo de enteros que puede el usuario seleccionar en el men�.
 * @return retorna 0 si salio bien
 */
int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max);

/**
 * @fn int pedirFlotante(float*, char*, char*, float, float)
 * @brief esta funcion valida que el usuario solo ingrese un flotante
 *
 * @param flotante variable de tipo float que guarda el flotante ingresado por el usuario
 * @param mensaje  variable de tipo char donde se almacena el msj a imprimir en pantalla
 * @param mensajeError variable de tipo char que almacena el msj de error si el usuario ingresa algo que no sea un flotante
 * @param min varile de tipo float que almacena el minimo de flotantes que el usuario puede ingresar
 * @param max varile de tipo float que almacena el maximo de flotantes que el usuario puede ingresar
 * @return retorna 0 si salio bien
 */
int pedirFlotante(float* flotante, char* mensaje, char* mensajeError, float min, float max);

/**
 * @fn int pedirCadena(char*, char*)
 * @brief funcion que valida que el usario ingrese cadena de caracteres es decir puede ingresar numeros y letras
 *
 * @param cadena variable de tipo char donde se almacena char ingresado por le usario
 * @param mensaje variable de tipo char donde se almacena el msj a imprimir en pantalla.
 * @return
 */
int pedirCadena(char* cadena, char* mensaje);

/**
 * @fn int primerLetraMayuscula(char[])
 * @brief funcion que sirve para que el usuario si escribe con mayusculas y minisculas su nombre se ordene poniendo
 * 		 la primer letra en Mayuscula
 *
 * @param name variable de tipo char donde se almacena el nombre ingresado por el usuario
 * @return
 */
int primerLetraMayuscula(char name[]);

/**
 * @fn int validarLetras(char[])
 * @brief funcion que valida que el usuario solo ingrese letras.
 *
 * @param string variable de tipo char donde se almacena los char ingresado por el usuario.
 * @return
 */
int validarLetras(char string[]);

/**
 * @fn int pedirCaracter(char*, char*, char*, char, char)
 * @brief
 *
 * @param caracter
 * @param mensaje
 * @param mensajeError
 * @param caracterVal1
 * @param caracterVal2
 * @return
 */
int pedirCaracter(char* caracter, char* mensaje, char* mensajeError, char caracterVal1, char caracterVal2);
int menuDeSort();
int menuDeModificaciones();
int menuDeOrdenamiento();

#endif /* INC_UTN_H_ */
