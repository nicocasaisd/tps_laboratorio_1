/*
 * utn_inputs.h
 *
 *  Created on: 27 jun. 2022
 *      Author: nicocasaisd
 */

#ifndef UTN_INPUTS_H_
#define UTN_INPUTS_H_



#endif /* UTN_INPUTS_H_ */


// INPUTS VALIDADOS

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroDecimal(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getTexto(char* pResultado, char* mensaje, char* mensajeError, int largo, int reintentos);
int utn_getTextoAlfanumerico(char* pResultado, char* mensaje, char* mensajeError, int largo, int reintentos);


