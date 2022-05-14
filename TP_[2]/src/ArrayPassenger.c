/*
 * ArrayPassenger.c
 *
 *  Created on: 13 may 2022
 *      Author: antonella calabrese
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validation.h"
#include "ArrayPassenger.h"

int initPassenger(ePassenger* lista, int tam)
{
	int allOk = -1;
	if(lista != NULL && tam > 0)
	    {
	        for(int i = 0; i < tam; i++)
	        {
	        	lista[i].isEmpty = 1;
	        }
	        allOk = 0;
	    }
	return allOk;
}

// /////////ALTA PASSENGER//////
int addPassenger(ePassenger* lista, int tam, int* pId)
{
	int allOk=0;
	int indice;
	ePassenger auxPassenger;

		if(lista != NULL && tam>0 && pId != NULL)
		{
			system("cls");
			printf("    *** add Passenger ***    \n");

			indice=searchFree(lista, tam);
			if(indice== -1)
			{
				printf("there is no place in the system\n");
			}
			else
			{
				auxPassenger.id=*pId;
				(*pId)++;

				pedirCadena(auxPassenger.name, "Enter Name: \n");
				validarLetras(auxPassenger.name);
				primerLetraMayuscula(auxPassenger.name);

				pedirCadena(auxPassenger.lastname, "Enter last name: \n");
				validarLetras(auxPassenger.lastname);
				primerLetraMayuscula(auxPassenger.lastname);

				pedirFlotante(&auxPassenger.price, "Enter price: \n", "error", 1,1000000);

				pedirCadena(auxPassenger.flycode, "Enter fly code: \n");

				pedirEntero(&auxPassenger.idTypePassenger, "Enter type Passenger: 1: Kid - 2: Adult - 3: old Man 4: disabled - 5: pregnant\n", "error", 1,5);

				pedirEntero(&auxPassenger.statusFlight, "Enter status flight: 1:Active 2: Inactive\n", "error", 1,5);

				auxPassenger.isEmpty=0;

				lista[indice]=auxPassenger;


			}
			allOk=1;
		}
	return allOk;
}






int findPassengerById(ePassenger* lista, int tam, int id){
	int indice=-1;

	if(lista != NULL && tam > 0)
	    {
	        for(int i = 0; i < tam; i++)
	        {
	            if(lista[i].id == id && lista[i].isEmpty == 0)
	            {
	            	indice = i;
	            	break;
	            }
	        }
	    }
	return indice;
}

int menuModificacion(){
	int opcion;


	printf("1. name \n");
	printf("2. last Name \n");
	printf("3. price \n");
	printf("4. fly code \n");
	printf("5. type passenger \n");
	printf("6. status flight \n");

	printf("enter one of the options to modify: \n");
	scanf("%d", &opcion);
	return opcion;
}

int submenu4(){
	int opcion;

	printf("1) show alphabetical order: \n");
	printf("2) show averages: \n");

	printf("choose an option: \n");
	scanf("%d", &opcion);
	return opcion;
}

// // MODIFICATION PASSENGER/////////
int modificationPassenger(ePassenger lista[], int tam){
	int allOk=0;
	int id;
	int indice;
	char confirma;
	char auxNombre[51];
	char auxLastname[51];
	float auxPrice;
	char auxFlycode[10];
	int auxTypePassenger;
	int auxStatusFlight;

	if(lista!=NULL && tam>0)
	{
		system("cls");
		printPassengers(lista, tam);
		printf("enter id: \n");
		scanf("%d", &id);
		indice=findPassengerById(lista, tam, id);
		if(indice==-1)
		{
			printf("there is no person with id: %d\n", id);
		}else
		{
			printPassenger(lista[indice]);

			printf("confirm modification?: s/n \n");
			fflush(stdin);
			scanf("%c", &confirma);
			if(confirma=='s')
			{
				switch(menuModificacion())
				{
					case 1:
						pedirCadena(auxNombre, "enter new name: \n");
						validarLetras(auxNombre);
						primerLetraMayuscula(auxNombre);
						strcpy(lista[indice].name, auxNombre);
						break;

					case 2:
						pedirCadena(auxLastname, "enter new last name: \n");
						validarLetras(auxLastname);
						primerLetraMayuscula(auxLastname);
						strcpy(lista[indice].lastname,auxLastname);
						break;

					case 3:
						pedirFlotante( &auxPrice,"enter new price: \n", "error", 1,500000);
						lista[indice].price=auxPrice;
						break;

					case 4:
						pedirCadena(auxFlycode, "enter new fly code: \n");
						strcpy(lista[indice].flycode, auxFlycode);
						break;

					case 5:
						pedirEntero(&auxTypePassenger, "enter new type passenger: \n", "error", 1,5);
						lista[indice].idTypePassenger=auxTypePassenger;
						break;
					case 6:
						pedirEntero(&auxStatusFlight, "enter new status flight: 1:Active 2: Inactive \n", "error", 1,2);
						lista[indice].statusFlight=auxStatusFlight;
						break;
					default:
						printf("invalid option. \n");
				}
				allOk=1;
			}else{
				printf("the modification has been canceled \n");
			}
		}
	}
	return allOk;
}

int searchFree(ePassenger* lista, int tam)
{
	int indice= -1;
	if(lista != NULL && tam > 0)
	    {
	        for(int i = 0; i < tam; i++)
	        {
	            if(lista[i].isEmpty)
	            {
	                indice = i;
	                break;
	            }
	        }
	    }
	return indice;
}

int printPassengers(ePassenger* lista, int tam)
{
	int allOk=0;
	int flag=1;

	if(lista != NULL && tam>0)
	{
		system("cls");
		printf("                      ***LIST PASSENGER***                 \n");
		printf("| id |     Name      |     LastName     |     Price     |     FlyCode     |     TypePassenger     |     StatusFligth     \n");
		for(int i=0; i<tam; i++)
		{
			if(!lista[i].isEmpty)
			{
				printPassenger(lista[i]);
				flag=0;
			}
		}
		if(flag)
		{
			printf("There are no people to display. \n");
		}
		allOk=1;
	}
	return allOk;
}

void printPassenger(ePassenger onePassenger)
{


	eTypePassenger tipos[5]={{1,"kid"},{2,"adult"}, { 3,"old man"}, { 4,"disable"}, { 5,"pregnant"}};

	for(int i=0; i<5; i++)//recorro los tipos
	{
			if(onePassenger.idTypePassenger == tipos[i].idTypePassenger) // si coincide
			{
				printf(" %-5d   %11s     %11s     %10.2f     %11s     %14s     %18d \n",
					onePassenger.id,
					onePassenger.name,
					onePassenger.lastname,
					onePassenger.price,
					onePassenger.flycode,
					tipos[i].descripcion,
					onePassenger.statusFlight);
				break;
			}

	}
}

// ///////////////BAJA PASAJERO ////////////////////

int removePassenger(ePassenger* lista, int tam)
{
	int allOk;
	int id;
	int indice;
	char confirma;

	if(lista!=NULL && tam>0)
	{
		system("cls");

		printf("enter id: \n");
		scanf("%d", &id);

		indice=findPassengerById(lista, tam, id);

		if(indice==-1)
		{
			printf("there is no person with id: %d\n", id);
		}else
		{
			printPassenger(lista[indice]);
			printf("confirm low?: s/n");
			fflush(stdin);
			scanf("%c", &confirma);
		}
		if(confirma=='s')
		{
			lista[indice].isEmpty=1;
			allOk=1;
		}else{
			printf("discharge has been cancelled.");
		}

	}
	return allOk;

}

//1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.
int sortPassenger(ePassenger* lista, int tam, int order)
{
	ePassenger auxPasajeros;
	int allOk=0;

	if(lista!=NULL && tam>0)
	{
		for(int i=0; i<tam-1; i++)
			{
				for(int j=i+1; j<tam; j++)
				{
					if(order==1){
						if((strcmp(lista[i].lastname, lista[j].lastname)>0) || (strcmp(lista[i].lastname, lista[j].lastname)==0 && lista[i].idTypePassenger>lista[j].idTypePassenger))
						{
							auxPasajeros=lista[i];
							lista[i]=lista[j];
							lista[j]=auxPasajeros;
						}
					}else
					{
						if(order==0)
						{
							if((strcmp(lista[i].lastname, lista[j].lastname)<0) || (strcmp(lista[i].lastname, lista[j].lastname)==0 && lista[i].idTypePassenger<lista[j].idTypePassenger))
							{
								auxPasajeros=lista[i];
								lista[i]=lista[j];
								lista[j]=auxPasajeros;
							}
						}
					}
			}
		}printPassengers(lista,tam);

		allOk=1;
	}
	return allOk;
}
//2.Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.
int promedio(ePassenger* lista, int tam){

	int allOk;
	float contPasajeros=0;
	float promedio;
	float acumPrecios=0;
	float contPrecioSuperado=0;

	if(lista!=NULL && tam>0){
		for(int i=0; i<tam; i++)
		{
			if(lista[i].isEmpty==0){
				acumPrecios+=lista[i].price;
				contPasajeros++;
			}
		}

		promedio= acumPrecios/contPasajeros;

		for(int i=0; i<tam; i++)
		{
			if(lista[i].price>promedio)
				{
					contPrecioSuperado++;
				}
			break;
		}allOk=1;
	}
	printf("total ticket price: %.2f\n", acumPrecios);
	printf("average ticket prices: %.2f\n", promedio);
	printf("the number of passengers that exceeded the average price are: %.2f\n", contPrecioSuperado);
	return allOk;
}

//3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO
int sortPassengerByCode(ePassenger* lista, int tam, int order)
{
	ePassenger auxPasajeros;
	int allOk=0;

	if(lista!=NULL && tam>0)
	{
		for(int i=0; i<tam-1; i++)
		{
			for(int j=i+1; j<tam; j++)
			{
				if(order==1){
					if((strcmp(lista[i].flycode , lista[j].flycode )>0) || (strcmp(lista[i].flycode, lista[j].flycode)==0 && lista[i].statusFlight >lista[j].statusFlight))
					{
						auxPasajeros=lista[i];
						lista[i]=lista[j];
						lista[j]=auxPasajeros;
					}
				}else
				{
					if(order==0)
					{
						if((strcmp(lista[i].flycode, lista[j].flycode)<0) || (strcmp(lista[i].flycode, lista[j].flycode)==0 && lista[i].statusFlight<lista[j].statusFlight))
						{
							auxPasajeros=lista[i];
							lista[i]=lista[j];
							lista[j]=auxPasajeros;

						}
					}
				}
			}
		}printPassengers(lista,tam);

		allOk=1;
	}
	return allOk;
}


int informList(ePassenger* lista, int tam)
{

	int allOk;
	int opcion;
	int order;

	if(lista != NULL && tam>0 )
	{
		system("cls");
		printf("     ****informs****     \n");
		printf("choose an option: \n");
		printf(">>  1. display passengers alphabetically by Last Name and Passenger Type. \n");
		printf(">>  2. show total price and average price. \n");
		printf(">>  3. list of passengers by flight code and active flight status. \n");
		printf(">>  4. ordering of passengers by flight code and flight status. \n");



		scanf("%d",&opcion);

		switch(opcion)
		{
			case 1:
				order=submenuListado();
				sortPassenger(lista,tam,order);
				break;
			case 2:
				promedio(lista, tam);
				break;
			case 3:
				for(int i=0;i<tam;i++)
				{
					if(lista[i].statusFlight == 1)
					{
						printPassenger(lista[i]);
					}
				}
				break;
			case 4:
				order=submenuListado();
				sortPassengerByCode(lista,tam,order);
				break;

		}allOk=1;

	}

	return allOk;
}

int submenuListado(){
	int opcion;

	printf("choose an option: \n");
	printf("1- sort ascending. \n");
	printf("0- sort descending. \n");

	scanf("%d", &opcion);

	return opcion;
}

void initListPassengers(ePassenger* lista)
{
    ePassenger aux[] = {

                        {1,"Pedro", "Ramirez", 90000, "123A",1,2},
                        {2,"Alfonso", "Perez", 20000.50,"125B",3,1},
                        {3.,"Matias", "Scarlato", 65500, "1B4",4,2},
                        {4,"Juan","Ramirez",90500.60,"MS123",5,1},
                        {5,"Agustin","Gomez",90000,"MS590",2,2}
                        };
    for(int i=0; i<5; i++)
    {
        lista[i] = aux[i];
    }
}

int flagReset(ePassenger list[], int tam, int* flag)
{
    int todoOk = 0;

    if(list != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(list[i].isEmpty == 0)
            {
                *flag = 1;
                todoOk = 1;
                break;
            }
            else
            {
                *flag = 0;
            }
        }
    }
    return todoOk;
}


