#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{


	setbuf(stdout,NULL);
    char seguir = 'n';
    int flagText = 0;
    int FlagBinary = 0;
    int respuestaMenuPrincipal;
    int opcionElegida;
	int flagIngreso = 0;


    LinkedList* lista = ll_newLinkedList();
    do{
    		respuestaMenuPrincipal=getNumero(&opcionElegida, " ***Ingrese una de las opciones: *** \n 1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto). \n 2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario). \n 3. Alta de pasajero \n 4. Modificar datos de pasajero \n 5. Baja de pasajero \n 6. Listar pasajeros \n 7. Ordenar pasajeros \n 8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto). \n 9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario). \n 10. Salir\n", "reingrese la opcion elegida",1,10,3);
    		if(respuestaMenuPrincipal==0)
    		{
    			switch(opcionElegida)
    			{
				case 1:
						flagText=1;
						controller_loadFromText("data.csv",lista);

					break;
				case 2:
					if(FlagBinary == 0 && flagText == 1)
					{
						printf("No se puede cargar la lista en modo binario si ya se cargo en modo texto.\n");
					}
					else if(FlagBinary == 0)
					{
						//controller_loadFromBinary("data.bin", lista);
						FlagBinary = 1;
					}
					else
					{
						printf("No puede volver a cargar la lista una vez cargada.\n");
					}
					break;
				case 3:
					controller_addPassenger(lista,"data.csv");
					break;
				case 4:
					if(lista->size)
					{
						controller_editPassenger(lista);
					}
					else
					{
						printf("Al menos debe dar de alta un pasajero para poder entrar a la opcion modificar.\n");
					}
					break;
				case 5:
					if(lista->size)
					{
						controller_removePassenger(lista);
					}
					else
					{
						printf("Al menos debe dar de alta un pasajero para poder entrar a la opcion dar de baja.\n");
					}
					break;
				case 6:
					if(lista->size)
					{
						controller_ListPassenger(lista);
					}
					else
					{
						printf("Al menos debe dar de alta un pasajero para poder entrar a la opcion listar pasajeros.\n");
					}
					break;
				case 7:
					if(lista->size)
					{
						controller_sortPassenger(lista);
					}
					else
					{
						printf("Al menos debe dar de alta un pasajero para poder entrar a la opcion ordenar pasajeros.\n");
					}
					break;
				case 8:
					if(lista->size)
					{
						controller_saveAsText("data.csv", lista);
						printf("Guardado Exitoso!!!\n");
					}
					else
					{
						printf("Al menos debe dar de alta un pasajero o cargar una lista para poder guardarla en modo texto.\n");
					}
					flagIngreso=1;
					break;
				case 9:
					if(lista->size)
					{
						controller_saveAsBinary("data.bin", lista);
						printf("Guardado Exitoso!!!\n");
					}
					else
					{
						printf("Al menos debe dar de alta un pasajero o cargar una lista para poder guardarla en modo binario.\n");
					}
					flagIngreso=1;
					break;
				case 10:
					if(flagIngreso==1)
					{
						pedirCaracter(&seguir, "¿Esta seguro que desea salir? s(si) y n(no).", "Error. letra invalida. Ingrese s si desea salir o n para continuar.", 's', 'n');
						fflush(stdin);
						if(seguir == 's')
						{
							ll_deleteLinkedList(lista);
							printf("Gracias por todo. Hasta la proxima!!!\n");
						}
					}
					else
					{
						printf("Al menos debe guardar un pasajero para salir.\n");
					}

					break;
				default:
					printf("Opcion invalida!!!\n");
					break;
    			}
    		}
    }while(seguir == 'n');
    return 0;
}

