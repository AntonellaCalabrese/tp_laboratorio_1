#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "controller.h"
#include "utn.h"
#include "parser.h"
#include <string.h>
#include <ctype.h>


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int todoOk = 0;
	FILE* f;
	if(path != NULL && pArrayListPassenger != NULL)
	{
		f = fopen(path, "r");
		if(ll_isEmpty(pArrayListPassenger)!=1)
		{
			parser_PassengerFromText(f, pArrayListPassenger);

		}
		printf("Lista cargada exitosamente!!\n");
		todoOk = 1;
	}
	fclose(f);
    return todoOk;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		printf("Enter Load 1\n");
		FILE* pFile = fopen(path,"rb");
		if(pFile!=NULL)
		{
			printf("Enter Load 2\n");
			retorno=0;
			parser_PassengerFromBinary(pFile, pArrayListPassenger);
			fclose(pFile);
		}
	}
	return retorno;
}


void controller_saveNextId(int id)
{
    FILE* f=fopen("ultimoID.txt", "r+");

    if(f==NULL)
    {
        f=fopen("ultimoID.txt", "w");
    }

    fprintf(f,"%d", id);
    fclose(f);
}

int controller_nextId(LinkedList* pArrayListPassenger)
{
	FILE* f=fopen("ultimoID.txt", "r");
	int* idActual=(int*) malloc(sizeof(int));
    int siguienteId;

    if(f==NULL)
    {
    	siguienteId=0;
    }
    else
    {
        fscanf(f, "%d", idActual);
        siguienteId=*idActual+1;
    }
    fclose(f);

    return siguienteId;
}

int controller_getMaxId(FILE* pFile)
{

	int maxId=0;
	char var1[50],var2[50],var3[50],var4[50],var5[50],var6[50],var7[50];
	Passenger* newPassenger=NULL;
	int r=0;

	pFile=fopen("data.csv","r");
	if(pFile==NULL)
	{
		printf("El archivo es nulo");
	}

	fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5,var6,var7);

	while(!feof(pFile))
	{
		r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5,var6,var7);
		if(r<7)
		{
			break;
		}
		newPassenger = Passenger_newParametros(var1,var2,var3,var4,var5,var6,var7);

		if(newPassenger!=NULL)
		{
			maxId++;
		}
	}
	fclose(pFile);
	return maxId;
}

// ///////////////////// ALTA  ////////////////////////////////
/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger,char* path)
{

	int allOk=0;
	int flagArchivo=0;

	int id=0;
	int idMaximo=1020;

	char nombre[50];
	char apellido[50];
	float precio;

	int typePassenger_int;
	int statusFlight_int;

	char typePassenger[15];
	char codigoVuelo[15];
	char statusFlight[15];
	char respuesta;

	Passenger* auxPasajero;

	system("cls");
	printf("              *** Alta Pasajero ***                  \n");
	printf("-----------------------------------------------------\n");

	if(pArrayListPassenger != NULL)
	{
		auxPasajero = Passenger_new();
		if(auxPasajero != NULL)
		{

			FILE*pFile;
			pFile=fopen(path,"r");
			if(flagArchivo==0)
			{
				id=controller_getMaxId(pFile)+1;
				flagArchivo=1;
				fclose(pFile);
			}

			id = controller_nextId(pArrayListPassenger);
			Passenger_setId(auxPasajero, id);

			pedirCadena(nombre, "Enter Name: \n");
			fflush(stdin);
			Passenger_setNombre(auxPasajero, nombre);

			pedirCadena(apellido, "Enter Last Name: \n");
			fflush(stdin);
			Passenger_setApellido(auxPasajero, apellido);

			pedirFlotante(&precio, "Enter Price: \n", "Error.Enter price again $1 - $1000000000: ", 1, 1000000000);
			Passenger_setPrecio(auxPasajero, precio);

			pedirCadena(codigoVuelo, "Enter Fly code: \n" );
			fflush(stdin);
			Passenger_setCodigoVuelo(auxPasajero,codigoVuelo);


			pedirEntero(&typePassenger_int, "Enter the type of passenger: \n 1) Economy \n 2) First class \n 3) executive \n","error, enter a valid number",1,3);
			switch(typePassenger_int)
			{
				case 1:
					strcpy(typePassenger,"Economy");
				break;
				case 2:
					strcpy(typePassenger,"First class");
				break;
				case 3:
					strcpy(typePassenger,"Executive ");
					break;
			}
			Passenger_setTipoPasajero(auxPasajero,typePassenger );

			pedirEntero(&statusFlight_int, "Enter Status flight\n 1) flying\n 2) Landed \n 3) Delayed flight","error, enter a valid number",1,3);
			switch(statusFlight_int)
			{
				case 1:
					strcpy(statusFlight,"flying");
					break;
				case 2:
					strcpy(statusFlight,"Landed");
					break;
				case 3:
					strcpy(statusFlight,"Delayed flight");
					break;
			}
			Passenger_setStatusFlight(auxPasajero, statusFlight);

			printf("                      ***LIST PASSENGER***                 \n");
			printf("| id |     Name      |     LastName     |     Price     |     FlyCode     |     TypePassenger     |     StatusFligth     \n");
			controller_mostrarPassenger(auxPasajero);

			pedirCaracter(&respuesta, "Desea dar de alta a este pasajero? s Ó n \n", "Error.Ingrese la letra nuevamente. Desea dar de alta a este Pasajero? s(si) o n(no)\n", 's', 'n');
			if(respuesta == 's')
			{
				ll_add(pArrayListPassenger, auxPasajero);
				controller_saveNextId(id);
				allOk = 1;
				printf("Pasajero dado de alta con exito!!!\n");
			}
			else
			{
				printf("Se ah cancelado el alta.\n");
			}
		}
	}
    return allOk;
}


// ///////////////////// MOFIDICAR ////////////////////////////////


int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int allOk=0;
	char respuesta='s';
	int id;
	char nombre[50];
	char apellido[50];
	float precio;

	int typePassenger_int;
	int statusFlight_int;

	char typePassenger[15];
	char codigoVuelo[15];
	char statusFlight[15];
	int indicePasajero;
	Passenger* auxPassenger;

	system("cls");
	printf("              *** Passenger Modification ***                           \n");
	printf("-------------------------------------------------------------------\n");

	if(pArrayListPassenger != NULL)
	{
		controller_ListPassenger(pArrayListPassenger);
		printf("Enter Passenger ID to be removed.\n");
		scanf("%d", &id);
		while(controller_validarId(pArrayListPassenger, id) == -1)
		{
			printf("Error. Invalid ID. Enter Passenger ID to be removed.\n");
			scanf("%d", &id);
		}
		indicePasajero = buscarPassengerId(pArrayListPassenger, id);
		auxPassenger = ll_get(pArrayListPassenger, indicePasajero);

		if(indicePasajero == -1)
		{
			printf("The entered ID doesnt exist.\n");
		}
		else
		{
			printf("| id |     Name      |     LastName     |     Price     |     FlyCode     |     TypePassenger     |     StatusFligth     \n");
			printf("---------------------------------------------------------------------------------------------------------------------------------------------------\n");

			controller_mostrarPassenger(auxPassenger);

			pedirCaracter(&respuesta, "Are you sure you want to modify this passenger from the system? (s: YES and n: NO)", "Enter option again. Are you sure you want to modify this passenger in the system (s: YES and n: NO)?", 's', 'n');
			fflush(stdin);

			if(respuesta == 's')
			{
				switch(menuDeModificaciones())
				{
					case 1:
						pedirCadena(nombre, "Enter New Name: \n");
						fflush(stdin);
						Passenger_setNombre(auxPassenger, nombre);
						printf("Successful Modification!!!\n");
						break;
					case 2:
						pedirCadena(apellido, "Enter New last name: \n");
						fflush(stdin);
						Passenger_setApellido(auxPassenger, apellido);
						break;
					case 3:
						pedirFlotante(&precio, "Enter New Price: \n", "Error.Enter price again $1 - $1000000000: ", 1, 1000000000);
						Passenger_setPrecio(auxPassenger, precio);
						printf("Successful Modification!!!\n");
						break;
					case 4:
						pedirCadena(codigoVuelo, "Enter Fly code: \n" );
						fflush(stdin);
						Passenger_setCodigoVuelo(auxPassenger,codigoVuelo);
						break;
					case 5:
						pedirEntero(&statusFlight_int, "Enter Status flight\n 1) flying\n 2) Landed \n 3) Delayed flight","error, enter a valid number",1,3);
						switch(statusFlight_int)
						{
							case 1:
								strcpy(statusFlight,"flying");
								break;
							case 2:
								strcpy(statusFlight,"Landed");
								break;
							case 3:
								strcpy(statusFlight,"Delayed flight");
								break;
						}
						Passenger_setStatusFlight(auxPassenger, statusFlight);
						break;
						case 6:
							pedirEntero(&typePassenger_int, "Enter the type of passenger: \n 1) Economy \n 2) First class \n 3) executive \n","error, enter a valid number",1,3);
							switch(typePassenger_int)
							{
								case 1:
									 strcpy(typePassenger,"Economy");
									break;
								case 2:
									strcpy(typePassenger,"First class");
									break;
								case 3:
									strcpy(typePassenger,"Executive ");
									break;
							}
							Passenger_setTipoPasajero(auxPassenger, typePassenger);
							break;
					default:
						printf("Invalid option!!!\n");
						break;
				}
			}
			else
			{
				printf("The modification has been cancelled.\n");
			}
		}
		allOk = 1;
	}
    return allOk;
    return 1;
}

int controller_validarId(LinkedList* pArrayListPassenger, int idPas)
{
	int idEncontrada;
	int idValidada=-1;
	int tam;
	Passenger* auxPassenger;

	if(pArrayListPassenger != NULL && idPas >= 0)
	{
		tam = ll_len(pArrayListPassenger);

		for (int i = 0; i < tam; ++i) {

			auxPassenger = ll_get(pArrayListPassenger, i);

			if(auxPassenger != NULL)
			{
				Passenger_getId(auxPassenger, &idEncontrada);

				if(idPas==idEncontrada)
				{
					idValidada= 1;
					break;
				}
			}
		}
	}
	return idValidada;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int todoOk = 0;
	int id;
	char answer;
	int indicePasajero;
	Passenger* auxPassenger;


	system("cls");
	printf("              *** Remove Passenger ***                           \n");
	printf("------------------------------------------------------------------\n");
	if(pArrayListPassenger != NULL)
	{
		controller_ListPassenger(pArrayListPassenger);
		printf("Enter the ID of the passenger to be removed.\n");
		scanf("%d", &id);
		while(controller_validarId(pArrayListPassenger, id) == -1)
		{
			printf("Error. Invalid ID. Enter the ID of the passenger to be removed.");
			scanf("%d", &id);
		}
		indicePasajero = buscarPassengerId(pArrayListPassenger, id);
		auxPassenger = ll_get(pArrayListPassenger, indicePasajero);

		if(indicePasajero == -1)
		{
			printf("The entered ID does not exist\n");
		}
		else
		{
			printf("                                    ***LIST PASSENGER***                 \n");
			printf("-------------------------------------------------------------------------------------------------------------------------\n");
			printf("| id |     Name      |     LastName     |     Price     |     FlyCode     |     TypePassenger     |     StatusFligth     \n");
			//controller_mostrarPassenger(auxPassenger);

			pedirCaracter(&answer, "Are you sure you want to delete this passenger from the system (s: YES and n: NO)?\n", "Enter option again. Are you sure you want to delete this passenger from the system? (s: YES and n: NO) \n", 's', 'n');
			fflush(stdin);

			if(answer == 's')
			{
				ll_remove(pArrayListPassenger, indicePasajero);
				Passenger_delete(auxPassenger);
				todoOk = 1;
				printf("Successful discharge!!!\n");
			}
			else
			{
				printf("The discharge has been cancelled.\n");
			}
		}
	}
    return todoOk;

    return 1;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* pAuxPassenger;
	int allOk=0;


	if(pArrayListPassenger != NULL)
	{

		system("cls");
		printf("------------------------------------------------------------------------------------------------------------------------------  \n");
		printf("                                                    ***LIST PASSENGER***                                                       \n");
		printf("------------------------------------------------------------------------------------------------------------------------------  \n");
		printf("| id |     Name      |     LastName     |     Price     |     FlyCode     |     TypePassenger     |     StatusFligth     \n");


		for(int i = 0; i < ll_len(pArrayListPassenger); i++)
		{
			pAuxPassenger = ll_get(pArrayListPassenger, i);
			if(pAuxPassenger != NULL)
			{
				controller_mostrarPassenger(pAuxPassenger);
				allOk = 1;
			}
		}
	}

    return allOk;
}

int controller_mostrarPassenger(Passenger* pArrayListPassenger)
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char tipoPasajero[15];
	char codigoVuelo[10];
	char estadoVuelo[15];
	int allOk=0;


	if(pArrayListPassenger!=NULL )
	{
		Passenger_getId(pArrayListPassenger,&id);

		Passenger_getNombre(pArrayListPassenger, nombre);

		Passenger_getApellido(pArrayListPassenger, apellido);

		Passenger_getPrecio(pArrayListPassenger, &precio);

		Passenger_getCodigoVuelo(pArrayListPassenger, codigoVuelo);

		Passenger_getTipoPasajero(pArrayListPassenger, tipoPasajero);

		Passenger_getStatusFlight(pArrayListPassenger, estadoVuelo);

		printf(" %-5d   %11s     %11s     %10.2f     %11s     %14s     %18s \n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo);
		allOk=1;
		}

	return allOk;

}


/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int allOk = 0;
	int critery;
	LinkedList* sort;

	if(pArrayListPassenger != NULL)
	{
		sort = ll_clone(pArrayListPassenger);
		critery = menuDeSort();

		switch(menuDeOrdenamiento())
		{
			case 1:
				ll_sort(sort, Passenger_SortId, critery);
				printf("One moment, the list is being processed.\n");
				controller_ListPassenger(sort);
				printf("Successful ordering!!!\n");
				break;
			case 2:
				ll_sort(sort, Passenger_SortName, critery);
				printf("One moment, the list is being processed..\n");
				controller_ListPassenger(sort);
				printf("Successful ordering!!!\n");
				break;
			case 3:
				ll_sort(sort, Passenger_SortLastName, critery);
				printf("One moment, the list is being processed..\n");
				controller_ListPassenger(sort);
				printf("Successful ordering!!!\n");
				break;
			case 4:
				ll_sort(sort, Passenger_SortPrice, critery);
				printf("One moment, the list is being processed..\n");
				controller_ListPassenger(sort);
				printf("Successful ordering!!!\n");
				break;
			case 5:
				ll_sort(sort, Passenger_SortFlyCode, critery);
				printf("One moment, the list is being processed..\n");
				controller_ListPassenger(sort);
				printf("Successful ordering!!!\n");
				break;
			case 6:
				ll_sort(sort, Passenger_SortTypePassenger, critery);
				printf("One moment, the list is being processed..\n");
				controller_ListPassenger(sort);
				printf("Successful ordering!!!\n");
				break;
			case 7:
				ll_sort(sort, Passenger_SortStatusFlight, critery);
				printf("One moment, the list is being processed..\n");
				controller_ListPassenger(sort);
				printf("Successful ordering!!!\n");
				break;
			case 8:
				printf("Order cancelled.\n");
				break;
			default:
				printf("Invalid option!!!\n");
				break;
		}
		ll_deleteLinkedList(sort);
		allOk = 1;
	}

    return allOk;
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	Passenger* auxPassenger ;
	FILE* pArchivo;
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char typePassenger[15];
	char codigoVuelo[15];
	char statusFlight[15];
	int allOk=0;


	if(path != NULL && pArrayListPassenger != NULL)
	{
		pArchivo = fopen(path, "w");

		auxPassenger = Passenger_new();

		fprintf(pArchivo, "id,name,Last name,price,Fly Code,Type Passenger, Status Flight\n");

		for(int i = 0; i < ll_len(pArrayListPassenger); i++)
		{
			auxPassenger = ll_get(pArrayListPassenger, i);
			if(auxPassenger != NULL)
			{
				Passenger_getId(auxPassenger, &id);
				Passenger_getNombre(auxPassenger, nombre);
				Passenger_getApellido(auxPassenger, apellido);
				Passenger_getPrecio(auxPassenger, &precio);
				Passenger_getCodigoVuelo(auxPassenger, codigoVuelo);
				Passenger_getTipoPasajero(auxPassenger, typePassenger);
				Passenger_getStatusFlight(auxPassenger, statusFlight);


				fprintf(pArchivo, "%d,%s,%s,%f,%s,%s,%s\n",id,nombre,apellido,precio,codigoVuelo,typePassenger,statusFlight);
				allOk = 1;
			}
			else
			{
				allOk = 0;
				break;
			}
		}
		fclose(pArchivo);
	}
    return allOk;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int allOk = 0;
	FILE* f;
	Passenger* auxPassenger ;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		f = fopen(path, "wb");

		auxPassenger = Passenger_new();

		if(auxPassenger != NULL)
		{
			for(int i = 0; i < ll_len(pArrayListPassenger); i++)
			{
				auxPassenger = ll_get(pArrayListPassenger, i);
				fwrite(auxPassenger, sizeof(Passenger), 1, f);
			}
			allOk = 1;
		}
		fclose(f);
	}
    return allOk;
    return 1;
}



