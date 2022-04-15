/*
 * tp1_lib.h
 *
 *  Created on: 15 abr. 2022
 *      Author: nicocasaisd
 */

#ifndef TP1_LIB_H_
#define TP1_LIB_H_


void imprimirMenu(int km, float precioAA, float precioLatam);
void pedirOpcion(int* pOpcion, int min, int max);
int pedirNumero(int min, int max);
int ingresarKm(int* pKm);
float calcularDebito(float precio);
float calcularCredito(float precio);
float calcularBTC(float precio);
float calcularUnitario(float precio, int km);
float calcularDiferencia(float precio1, float precio2);
void ingresarPrecioVuelos(float* pAA, float* pLat, int* pflagAA, int* pflagLatam);
void mostrarResultados(int kilometros, float precioAA, float precioAADebito, float precioAACredito, float precioAABTC, float precioAAUnitario, float precioLatam, float precioLatamDebito, float precioLatamCredito, float precioLatamBTC, float precioLatamUnitario, float diferenciaDePrecio);
void pausar();
void cargaForzada(int* pkm, float* pPrecioAA, float* pPrecioLatam, int* flagKm, int* flagAA, int* flagLatam);


#endif /* TP1_LIB_H_ */
