/*
 * calculos.h
 *
 *  Created on: 13 abr 2022
 *      Author: antonella
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_



#endif /* CALCULOS_H_ */

/**
 * @fn int mostrarMenu()
 * @brief
 *\brief funcion de tipo entero para mostrar menú de opciones.
 *
 * @return  \retorna la opcion elegida.
 */
int mostrarMenu();
/**
 * @fn int mostrarKM()
 * @brief \funcion de tipo entero para mostrar los KM ingresados.
 *
 * @return \retorna los km ingresados.
 */
int mostrarKM();
/**
 * @fn int precioAerolinea(float*, float*)
 * @brief \funcion de tipo entero para mostrar el precio que le ingresan a Aerolinea y Latam.
 *
 * @param y \parametro donde se guarda el valor de aerolinea.
 * @param z \parametro donde se guarda el valor de Latam.
 * @return \int Retorna 1 si esValido y 0 si fallo.
 */
int precioAerolinea(float* y, float* z);

/**
 * @fn float realizarDescuento(float)
 * @brief \funcion de tipo flotante que calcula el descuento del precio del vuelo.
 *
 * @param precioVuelo \parametro donde ingresa el valor del precio del vuelo para hacer el descuento.
 * @return \retorna el precio del vuelo con descuento.
 */
float realizarDescuento(float precioVuelo);

/**
 * @fn float realizarInteres(float)
 * @brief \funcion de tipo flotante que calcula el interes del precio del vuelo.
 *
 * @param interesVuelo \parametro donde ingresa el valor del precio del vuelo para hacer el interes.
 * @return \retorna el precio del vuelo con intereses.
 */
float realizarInteres(float interesVuelo);
/**
 * @fn void mostrarResultados(float, float, float, float, float, float, float, float, float, float, float)
 * @brief \ funcion de tipo float que muestra los resultados ya calculados listos para imprimir en pantalla.
 *
 * @param precioLat \precio del vuelo latam.
 * @param precioAero \precio del vuelo aerolinea.
 * @param descuentoLat \precio con descuento del vuelo latam.
 * @param descuentoAero \precio con descuento del vuelo aerolinea.
 * @param interesLat \precio con interes del vuelo latam.
 * @param interesAero \precio con interes del vuelo aerolinea.
 * @param bitcoinAero \precio en bitcoin de aerolinea.
 * @param bitcoinLat \precio en bitcoin de Latam.
 * @param precioKmAe \precio por km de Aerolinea.
 * @param precioKmLa \precio por km de Latam.
 * @param difPrecioAL \diferencia de precio entre Latam y Aerolinea .
 */
void mostrarResultados(float precioLat, float precioAero, float descuentoLat, float descuentoAero, float interesLat, float interesAero, float bitcoinAero, float bitcoinLat, float precioKmAe, float precioKmLa, float difPrecioAL);

/**
 * @fn float realizarBitcoin(float)
 * @brief \funcion de tipo float que realiza la conversión del precio del vuelo en pesos Arg a Bitcoin
 *
 * @param resultBit \parametro donde se ingresa el valor en pesos para hacer la conversion a Bitcoins.
 * @return \ retorna el valor en bitcoins del precio del vuelo.
 */
float realizarBitcoin(float resultBit);
/**
 * @fn float mostrarPrecioKm(float, float)
 * @brief \funcion de tipo float que calcula el precio por KM del vuelo.
 *
 * @param km  \parametro donde se ingresan la cantidad de KM .
 * @param precio  \parametro donde se ingresa el precio del Vuelo.
 * @return  \retorna el precio por KM ya calculado.
 */
float mostrarPrecioKm(float km, float precio);
/**
 * @fn float difPrecio(float, float)
 * @brief  \funcion de tipo float que realiza el calculo de la diferencia de precio entre Aerolinea y Latam.
 *
 * @param lat  \parametro de tipo float que ingresa el precio del vuelo de Latam.
 * @param aero  \parametro de tipo float que ingresa el precio del vuelo de Aerolinea.
 * @return  \retorna la diferencia de precio entre Aerolinea y Latam.
 */
float difPrecio(float lat, float aero);
/**
 * @fn void cargaForzada()
 * @brief  \funcion que ya tiene los datos hardcodeados(ya ingresados) y solo los imprime en pantalla, es de tipo vacia y no retorna nada.
 *
 */
void cargaForzada();
