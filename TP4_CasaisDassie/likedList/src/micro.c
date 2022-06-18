/*
 * micro.c
 *
 *  Created on: 18 jun. 2022
 *      Author: nicocasaisd
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "micro.h"

/// @fn eMicro eMicro_new*()
/// @brief Crea una estructura eMicro en memoria dinamica y devuelve un puntero hacia ella
///
/// @return

eMicro* eMicro_new()
{
	eMicro* new_eMicro = (eMicro*) calloc(1, sizeof(eMicro));

	return new_eMicro;
}

// FUNCIONES COMPARADORAS


/// @fn int Passenger_compareByCodigoVuelo(void*, void*)
/// @brief Castea los punteros a Passenger y compara los codigos de vuelo de dos elementos. Funcion hecha para pasarse a ll_sort()
///
/// @param a Puntero a void que se castea a Passenger
/// @param b Puntero a void que se castea a Passenger
/// @return Devuelve 1 si el primero es mayor, -1 si es menor, 0 si son iguales
int eMicro_compareByIdEmpresa(void* a, void* b)
{
	int comparison = 0;
	int id1, id2;
	eMicro* first;
	eMicro* second;

	if(a != NULL && b != NULL)
	{
		// casteo a eMicro
		first = (eMicro*) a;
		second = (eMicro*) b;
		// cargo ids
		id1 = first->idEmpresa;
		id2 = second->idEmpresa;
		// comparacion
		if(id1 > id2)
		{
			comparison = 1;
		}
		else if(id1 < id2)
		{
			comparison = -1;
		}
	}
    return comparison;
}
