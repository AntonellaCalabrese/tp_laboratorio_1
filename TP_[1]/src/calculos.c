/*
 * calculos.c
 *
 *  Created on: 13 abr 2022
 *      Author: antonella calabrese
 */
#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"


//4. Informar Resultados
void mostrarResultados(float precioLat, float precioAero, float descuentoLat, float descuentoAero, float interesLat, float interesAero, float bitcoinAero, float bitcoinLat, float precioKmAe, float precioKmLa, float difPrecioAL)
{
    printf("Latam: %f\n", precioLat);
    printf("a) Tarjeta de debito (descuento 10%%): %.2f\n",  descuentoLat);
    printf("b) Tarjeta de credito (interes 25%%): %.2f\n", interesLat);
    printf("c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos): %f\n", bitcoinLat);
    printf("d) Mostrar precio por km (precio unitario): %.2f\n", precioKmLa);

    printf("\nAaerolinea: %f\n", precioAero);
    printf("a) Tarjeta de debito (descuento 10%%): %.2f\n", descuentoAero);
    printf("b) Tarjeta de crédito (interes 25%%): %.2f\n", interesAero);
    printf("c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos): %f\n", bitcoinAero);
    printf("d) Mostrar precio por km (precio unitario): %.2f\n", precioKmAe);

    printf("\ne) Mostrar diferencia de precio ingresada (Latam - Aerolineas): %.2f\n", difPrecioAL);
}

int mostrarKM(){
    int km;

    printf("1) Ingresar Kilometros: ");
    scanf("%d", &km);

    return km;
}

int precioAerolinea(float* y, float* z)
{
    float precioL;
    float precioA;
    int esValido=0;

    if(y!=NULL && z!=NULL)
    {
        printf("ingrese el precio de latam: ");
        scanf("%f", &precioL);

        *z=precioL;

        printf("ingrese el precio de Aerolinea: ");
        scanf("%f", &precioA);

        *y=precioA;

        esValido=1;
    }
    return esValido;
}
//a) Tarjeta de débito (descuento 10%)

float realizarDescuento(float precioVuelo)
{
    float resultado;


    float descuento=precioVuelo*10/100;
    resultado= precioVuelo-descuento;
    return resultado;
}

//b) Tarjeta de crédito (interés 25%)

float realizarInteres(float interesVuelo)
{

    float resultado;

    float interes=interesVuelo*0.25;
    resultado=interesVuelo+interes;
    return resultado;
}

//Bitcoin (1BTC -> 4606954.55 Pesos Argentinos):
float realizarBitcoin(float resultBit){

    float bitcoin=4606954.55;
    float resultado;

    resultado=resultBit/bitcoin;

    return resultado;
}

//d) Mostrar precio por km (precio unitario):
float mostrarPrecioKm(float km, float precio)
{
    float resultado;

    resultado=precio/km;

    return resultado;
}

//e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas):

float difPrecio(float lat, float aero){
    float max;
    float diferencia;
    float min;

    if(lat>aero){
        max=lat;
        min=aero;
    }else{
        max=aero;
        min=lat;
    }

    diferencia=max-min;
    return diferencia;
}

//5. Carga forzada de datos

void cargaForzada()
{
    system("cls");
    printf("\nkm ingresados: 7090\n");
    printf("Latam: $159339\n");
    printf("a) Tarjeta de debito (descuento 10%%): %.2f\n", realizarDescuento(159339));
    printf("b) Tarjeta de credito (interes 25%%): %.2f\n",realizarInteres(159339));
    printf("c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos): %f\n",realizarBitcoin(159339));
    printf("d) Mostrar precio por km (precio unitario): %.2f\n", mostrarPrecioKm(7090, 159339 ));

    printf("\nAaerolinea: $162965\n");
    printf("a) Tarjeta de debito (descuento 10%%): %.2f\n", realizarDescuento(162965));
    printf("b) Tarjeta de crédito (interes 25%%): %.2f\n",realizarInteres(162965));
    printf("c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos): %f\n",realizarBitcoin(162965));
    printf("d) Mostrar precio por km (precio unitario): %.2f\n", mostrarPrecioKm(7090, 162965));

    printf("\ne) Mostrar diferencia de precio ingresada (Latam - Aerolineas): %.2f\n", difPrecio(162965,159339));
}
