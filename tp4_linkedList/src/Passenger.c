/*
 * Passenger.c
 *
 *  Created on: 15 jun 2022
 *      Author: antonella
 */


#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "../inc/Controller.h"
#include "../inc/Passenger.h"

#include <string.h>
#include <ctype.h>

Passenger* Passenger_new()
{
	Passenger* newPassenger=(Passenger*)malloc(sizeof(Passenger));

	if(newPassenger != NULL)
	{
		newPassenger->id= 0;
		strcpy(newPassenger->nombre," ");
		strcpy(newPassenger->apellido," ");
		newPassenger->precio=0;
		strcpy(newPassenger->codigoVuelo," ");
		strcpy(newPassenger->tipoPasajero, " ");
		strcpy(newPassenger->estadoVuelo, " ");

	}

	return newPassenger;

}


Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr ,char* codigoVueloStr,char* tipoPasajeroStr,char* statusFlightStr)
{

	Passenger* pasajeroNuevo = Passenger_new();
	if(pasajeroNuevo != NULL)
	{
		if( !(Passenger_setId(pasajeroNuevo, atoi(idStr))
			 && Passenger_setNombre(pasajeroNuevo, nombreStr)
			 && Passenger_setApellido(pasajeroNuevo,apellidoStr)
			 && Passenger_setPrecio(pasajeroNuevo, atof(precioStr))
			 && Passenger_setCodigoVuelo(pasajeroNuevo, codigoVueloStr)
			 && Passenger_setTipoPasajero(pasajeroNuevo,tipoPasajeroStr)
			 && Passenger_setStatusFlight(pasajeroNuevo, statusFlightStr)
			 ))
		{
			free(pasajeroNuevo);
			pasajeroNuevo=NULL;

		}

	}
	return pasajeroNuevo;
}



int Passenger_delete(Passenger* this)
{
	int allOk = 0;
	if(this != NULL)
	{
		free(this);

		allOk = 1;
	}
	return allOk;
}

int Passenger_setId(Passenger* this,int idPassenger)
{
	int todoOk = 0;
	if(this != NULL && idPassenger > 0)
	{
		this->id = idPassenger;
		todoOk = 1;
	}
	else
	{
		printf("Id Invalido\n");
	}
	return todoOk;
}


int Passenger_getId(Passenger* this,int* idPassenger)
{
	int todoOk = 0;
	if(this != NULL && idPassenger != NULL)
	{
		*idPassenger = this->id;
		todoOk = 1;
	}
	return todoOk;
}



int Passenger_setNombre(Passenger* this,char* nombre){
	int todoOk = 0;
	if(this != NULL && nombre != NULL)
	{
		if(strlen(nombre) < 40 && strlen(nombre) > 1)
		{
			strcpy(this->nombre, nombre);
			strlwr(this->nombre);
			this->nombre[0] = toupper(this->nombre[0]);
			todoOk = 1;
		}
	}
	else
	{
		printf("Nombre Invalido\n");
	}
	return todoOk;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int todoOk = 0;
	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		todoOk = 1;
	}
	return todoOk;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int todoOk = 0;
	if(this != NULL && apellido != NULL)
	{
		if(strlen(apellido) < 30 && strlen(apellido) > 2)
		{
			strcpy(this->apellido, apellido);
			strlwr(this->apellido);
			this->apellido[0] = toupper(this->apellido[0]);
			todoOk = 1;
		}
	}
	else
	{
		printf("Apellido Invalido\n");
	}
	return todoOk;

}
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int allOk = 0;
	if(this != NULL && apellido != NULL)
	{
		strcpy(apellido, this->apellido);
		allOk = 1;
	}
	return allOk;
}



int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int allOk=0;

	if(this != NULL && codigoVuelo != NULL )
	{
		strcpy(this->codigoVuelo, codigoVuelo);
	}
	allOk=1;

    return allOk;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int allOk = 0;
	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(codigoVuelo, this->codigoVuelo);
		allOk = 1;
	}
	return allOk;
}


int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int allOk=0;

	if(this != NULL && tipoPasajero != NULL)
	{
		strcpy(this->tipoPasajero,tipoPasajero);
	}
	allOk=1;

    return allOk;
}

int Passenger_getTipoPasajero(Passenger* this, char* tipoPasajero)
{
	int allOk = 0;
	if(this != NULL && tipoPasajero != NULL)
	{
		strcpy(tipoPasajero, this->tipoPasajero);
		allOk = 1;
	}
	return allOk;
}


int Passenger_setPrecio(Passenger* this,float precio)
{
	int allOk=0;

	if(this != NULL && precio > 0 && precio <= 1000000000)
	{
		this->precio= precio;
	}
	allOk=1;

    return allOk;
}
int Passenger_getPrecio(Passenger* this, float* precio)
{
    int allOk=0;

    if(this != NULL && precio != 0)
    {
    	*precio=this->precio;
    	allOk=1;
    }

    return allOk;
}
int Passenger_setStatusFlight(Passenger* this, char* estadoVuelo)
{
	int allOk=0;

	if(this != NULL && estadoVuelo != NULL )
	{
		strcpy(this->estadoVuelo, estadoVuelo);
	}
	allOk=1;

    return allOk;
}

int Passenger_getStatusFlight(Passenger* this, char* estadoVuelo)
{
	int allOk = 0;
	if(this != NULL && estadoVuelo != NULL)
	{
		strcpy(estadoVuelo, this->estadoVuelo);
		allOk = 1;
	}
	return allOk;
}



int Passenger_SortId(void* item1, void* item2)
{
	int allOk = 0;
	Passenger* Pasajero1 = NULL;
	Passenger* Pasajero2 = NULL;
	int id1;
	int id2;

	Pasajero1 = (Passenger*) item1;
	Pasajero2 = (Passenger*) item2;
	if(item1 != NULL && item2 != NULL)
	{
		if(Passenger_getId(Pasajero1, &id1) == 1 && Passenger_getId(Pasajero2, &id2) == 1)
		{
			if(id1 > id2)
			{
				allOk = 1;
			}
			else if(id1 < id2)
			{
				allOk = -1;
			}
		}
	}
	return allOk;
}

int Passenger_SortName(void* item1, void* item2)
{
	int allOk = 0;
	Passenger* pasajero1 = NULL;
	Passenger* pasajero2 = NULL;
	char name1[128];
	char name2[128];

	pasajero1 = (Passenger*) item1;
	pasajero2 = (Passenger*) item2;
	if(item1 != NULL && item2 != NULL)
	{
		if(Passenger_getNombre(pasajero1, name1) == 1 && Passenger_getNombre(pasajero2, name2) == 1)
		{
			if(strcmp(name1, name2) > 0)
			{
				allOk = 1;
			}
			else if(strcmp(name1, name2) < 0)
			{
				allOk = -1;
			}
		}
	}
	return allOk;
}

int Passenger_SortLastName(void* item1, void* item2)
{
	int allOk = 0;
	Passenger* pasajero1 = NULL;
	Passenger* pasajero2 = NULL;
	char apellido1[128];
	char apellido2[128];

	pasajero1 = (Passenger*) item1;
	pasajero2 = (Passenger*) item2;
	if(item1 != NULL && item2 != NULL)
	{
		if(Passenger_getNombre(pasajero1, apellido1) == 1 && Passenger_getNombre(pasajero2, apellido2) == 1)
		{
			if(strcmp(apellido1, apellido2) > 0)
			{
				allOk = 1;
			}
			else if(strcmp(apellido1, apellido2) < 0)
			{
				allOk = -1;
			}
		}
	}
	return allOk;
}

int Passenger_SortPrice(void* item1, void* item2)
{
	int allOk = 0;
	Passenger* pasajero1 = NULL;
	Passenger* pasajero2 = NULL;
	float price1;
	float price2;

	pasajero1 = (Passenger*) item1;
	pasajero2 = (Passenger*) item2;
	if(item1 != NULL && item2 != NULL)
	{
		if(Passenger_getPrecio(pasajero1, &price1) == 1 && Passenger_getPrecio(pasajero2, &price2) == 1)
		{
			if(price1 > price2)
			{
				allOk = 1;
			}
			else if(price1 < price2)
			{
				allOk = -1;
			}
		}
	}
	return allOk;
}

int Passenger_SortStatusFlight(void* item1, void* item2)
{
	int allOk = 0;
	Passenger* pasajero1 = NULL;
	Passenger* pasajero2 = NULL;
	char status1[128];
	char status2[128];

	pasajero1 = (Passenger*) item1;
	pasajero2 = (Passenger*) item2;
	if(item1 != NULL && item2 != NULL)
	{
		if(Passenger_getNombre(pasajero1, status1) == 1 && Passenger_getNombre(pasajero2, status2) == 1)
		{
			if(strcmp(status1, status2) > 0)
			{
				allOk = 1;
			}
			else if(strcmp(status1, status2) < 0)
			{
				allOk = -1;
			}
		}
	}
	return allOk;
}
int Passenger_SortFlyCode(void* item1, void* item2)
{
	int allOk = 0;
	Passenger* pasajero1 = NULL;
	Passenger* pasajero2 = NULL;
	char code1[128];
	char code2[128];

	pasajero1 = (Passenger*) item1;
	pasajero2 = (Passenger*) item2;
	if(item1 != NULL && item2 != NULL)
	{
		if(Passenger_getNombre(pasajero1, code1) == 1 && Passenger_getNombre(pasajero2, code2) == 1)
		{
			if(strcmp(code1, code2) > 0)
			{
				allOk = 1;
			}
			else if(strcmp(code1, code2) < 0)
			allOk = -1;
		}
	}
	return allOk;
}


int Passenger_SortTypePassenger(void* item1, void* item2)
{
	int allOk = 0;
	Passenger* pasajero1 = NULL;
	Passenger* pasajero2 = NULL;
	char type1[128];
	char type2[128];

	pasajero1 = (Passenger*) item1;
	pasajero2 = (Passenger*) item2;
	if(item1 != NULL && item2 != NULL)
	{
		if(Passenger_getNombre(pasajero1, type1) == 1 && Passenger_getNombre(pasajero2, type2) == 1)
		{
			if(strcmp(type1, type2) > 0)
			{
				allOk = 1;
			}
			else if(strcmp(type1, type2) < 0)
			{
				allOk = -1;
			}
		}
	}
	return allOk;
}


int buscarPassengerId(LinkedList* pArrayListPassenger, int id)
{

	int seEncontro = - 1;
	int idComparar;
	Passenger* newPassenger;
	if(pArrayListPassenger != NULL && id > 0)
	{
		for(int i = 0; i < ll_len(pArrayListPassenger); i++)
		{
			newPassenger = ll_get(pArrayListPassenger, i);
			if(newPassenger != NULL)
			{
				Passenger_getId(newPassenger, &idComparar);
				if(idComparar == id)
				{
					seEncontro = i;
					break;
				}
			}
		}
	}
	return seEncontro;
}

