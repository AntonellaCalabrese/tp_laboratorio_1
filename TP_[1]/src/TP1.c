#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"
#include "validacion.h"
int main()
{
	setbuf(stdout, NULL);
    int km;
    char salir = 's';
    int flag=0;
    float precioA;
    float precioL;
    float precioLatam;
    float precioAero;
    float descA;
    float descL;
    float intA;
    float intL;
    float bitcoinA;
    float bitcoinL;
    float precioKmA;
    float precioKmL;
    float precioDifIng;
    int respuestaMenuPrincipal;
    int opcionElegida;

    do
    {
    	respuestaMenuPrincipal=getNumero(&opcionElegida, "ingrese una de las opciones\n 1. Ingresar Kilometros:  \n 2. Ingresar Precio de Vuelos: \n 3. Calcular todos los costos: \n 4. Informar Resultados: \n 5. Carga forzada de datos \n 6. Salir\n", "reingrese la opcion elegida",1,6,3);
    	if(respuestaMenuPrincipal==0)
    	{
			switch(opcionElegida){
			case 1:
				if (flag==0) {
					  km=mostrarKM();
					   flag=1;
					}
				break;
			case 2:
				if(flag==1){
					 precioAerolinea(&precioA, &precioL);
					 flag=2;
					}else{
				   printf("\nPorfavor, primero ingrese los Km en la opcion 1\n");
				 }
				break;
			case 3:
				if(flag==2) {
					  precioLatam=(precioA);
						precioAero=(precioL);
						descL=realizarDescuento(precioL);
						descA=realizarDescuento(precioA);
						intL=realizarInteres(precioL);
						intA=realizarInteres(precioA);
						bitcoinA=realizarBitcoin(precioA);
						bitcoinL=realizarBitcoin(precioL);
						precioKmA=mostrarPrecioKm(km, precioA);
						precioKmL=mostrarPrecioKm(km, precioL);
						precioDifIng=difPrecio(precioL, precioA);
						flag=3;
					}
					else{
					printf("\nIngrese primero la opcion 1 y 2 para poder calcular\n");
					}
					break;
			case 4:
				if(flag==3){
						mostrarResultados(precioAero, precioLatam, descL, descA, intL, intA, bitcoinA, bitcoinL, precioKmA, precioKmL, precioDifIng);
						flag=0;
					}else{
						printf("\nPorfavor, primero ingrese los precios en la opcion 2 y luego presione 3 para calcularlos\n");
					}
					break;
			case 5:
				cargaForzada();
				break;
			case 6:
				getCaracter(&salir,"Desea continuar? s/n", "error, ingrese s ó n", 's','n');
				break;
			}
			system("pause");
    	}
  } while(salir == 's');
    return 0;
}
