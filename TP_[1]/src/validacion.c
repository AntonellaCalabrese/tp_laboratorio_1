/*
 * validacion.c
 *
 *  Created on: 14 abr 2022
 *      Author: antonella calabrese
 */
#include <stdio.h>
#include <stdlib.h>
#include "validacion.h"
#include <ctype.h>
int getCaracter(char* caracter, char* mensaje, char* mensajeError, char caracterVal1, char caracterVal2)
{
	int esValido = -1;
	char caracterIngresado;

	if(caracter != NULL && mensaje != NULL && mensajeError != NULL)
	{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%c", &caracterIngresado);
		caracterIngresado = tolower(caracterIngresado);

		while(caracterIngresado != caracterVal1 && caracterIngresado != caracterVal2)
		{
			printf("%s",mensajeError);
			fflush(stdin);
			scanf("%c", &caracterIngresado);
			caracterIngresado = tolower(caracterIngresado);
		}
		*caracter=caracterIngresado;
		esValido=0;
	}
	return esValido;
}



int getNumero(int* pResultado, char* mensaje, char* msjError, int min, int max, int reintentos){
	int retorno=-1;
	int bufferInt;

	do{
		if(pResultado != NULL && mensaje != NULL && msjError != NULL && min<= max && reintentos>0)
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%d", &bufferInt);
			if(bufferInt>=min && bufferInt<=max){
				*pResultado=bufferInt;
				retorno=0;
				break;
			}else{
				printf("%s", msjError);
				reintentos--;
			}
		}
	}while(reintentos>=0);
	return retorno;
}
