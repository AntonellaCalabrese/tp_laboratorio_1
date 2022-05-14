/*
 ============================================================================
 Name        : TP2.c
 Author      : Antonella Calabrese
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "validation.h"

#define TAM 2000

int main(){
	setbuf(stdout, NULL);
	int respuestaMenuPrincipal;
	int opcionElegida;
	int flag=0;
	int nextId=1;
	char seguir='s';
	ePassenger lista[TAM];

    	if(initPassenger(lista, TAM) == -1)
    	{
    		printf("A problem occurred while initializing passengers.");
    	}
    do{
		respuestaMenuPrincipal=getNumero(&opcionElegida, " ***enter one of the options*** \n >>1. Add  \n >>2. Modification \n >>3. Remove: \n >>4. Inform:  \n >>5. forced load \n >>6. Exit\n", "re-enter the chosen option",1,6,3);
		if(respuestaMenuPrincipal==0)
		{
			switch(opcionElegida)
			{
    			case 1:
    					if(addPassenger(lista, TAM, &nextId))
    					{
    						printPassengers(lista,TAM);
    						printf("Register successful!!\n");
    						flag=1;
    					}else
    					{
    						printf("There was a problem registering\n");
    					}
    				break;
    			case 2:
    				if(flag==0)
    				{
    					printf("There are no passengers to modify. \n");
    				}
    				else
    				{
    					if(modificationPassenger(lista, TAM))
    					{
    						printf("modification successful. \n");
    					}
    					else
    					{
    						printf("There was a problem when making the modification \n");
    					}
    				}
    				break;
    			case 3:
    				if(flag==0)
    				{
    					printf("There was a problem doing the remove. \n");
    				}
    				else
    				{
    					if(removePassenger(lista, TAM))
    					{
    						printf("Lower successful. \n");
    						flagReset(lista, TAM, &flag);
    					}
    					else
    					{
    						printf("There was a problem doing the remove. \n");
    					}
    				}
    				break;
    			case 4:
    				if(flag==0)
					{
    					printf("There are no passengers to display. \n");
					}else
					{
						if(informList(lista,TAM))
						{
							printf("Lista informada. \n");
						}else
						{
							printf("There was a problem reporting. \n");
						}
					}
    				break;
    			case 5:
    					initListPassengers(lista);
    					flag=1;
    				break;
    			case 6:
    				seguir='n';
    				break;
    			default:
    				printf("invalid option\n\n");
    		}
		}
    }
    while(seguir == 's');
	return EXIT_SUCCESS;
}
