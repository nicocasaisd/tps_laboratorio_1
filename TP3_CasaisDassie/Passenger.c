/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author:
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Passenger.h"
#include "my_lib.h"


/// @fn Passenger Passenger_new*()
/// @brief Crea una estructura Passenger en memoria dinamica y devuelve un puntero hacia ella
///
/// @return
Passenger* Passenger_new()
{
	Passenger* new_passenger = (Passenger*) calloc(1, sizeof(Passenger));

	return new_passenger;
}
/// @fn Passenger Passenger_newParametros*(char*, char*, char*)
/// @brief
///
/// @param idStr
/// @param nombreStr
/// @param tipoPasajeroStr
/// @return
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr, char* precioStr, char* tipoPasajeroStr, char* codigoVueloStr, char* statusFlightStr)
{
	// pido memoria para un Passenger
	Passenger* new_passenger = Passenger_new();
	// valido
	if(new_passenger != NULL)
	{
		if(!(	Passenger_setId(new_passenger, atoi(idStr)) &&
				Passenger_setNombre(new_passenger, nombreStr) &&
				Passenger_setApellido(new_passenger, apellidoStr) &&
				Passenger_setPrecio(new_passenger, atof(precioStr)) &&
				Passenger_setTipoPasajero(new_passenger, atoi(tipoPasajeroStr)) &&
				Passenger_setCodigoVuelo(new_passenger, codigoVueloStr) &&
				Passenger_setStatusFlight(new_passenger, statusFlightStr)
				))
		{
			Passenger_delete(new_passenger);
			new_passenger = NULL;
		}
	}
	return new_passenger;
}

void Passenger_delete(Passenger* this)
{

	if(this != NULL)
	{
		free(this);
	}

}

/// @fn int Passenger_setId(Passenger*, int)
/// @brief
///
/// @param this
/// @param id
/// @return
int Passenger_setId(Passenger* this,int id)
{
	int exit_status = 0;
	if(this != NULL && id > 0)
	{
		this->id = id;
		exit_status = 1;
	}

	return exit_status;
}

/// @fn int Passenger_getId(Passenger*, int*)
/// @brief
///
/// @param this
/// @param id
/// @return
int Passenger_getId(Passenger* this,int* id)
{
	int exit_status = 0;
		if(this != NULL && id != NULL)
		{
			*id = this->id;
			exit_status = 1;
		}

	return exit_status;
}

/// @fn int Passenger_setNombre(Passenger*, char*)
/// @brief
///
/// @param this
/// @param nombre
/// @return
int Passenger_setNombre(Passenger* this,char* nombre)
{
	int exit_status = 0;
	if(this != NULL && nombre != NULL)
	{
		strncpy(this->nombre, nombre, sizeof(this->nombre));
		exit_status = 1;
	}

	return exit_status;
}

/// @fn int Passenger_getNombre(Passenger*, char*)
/// @brief
///
/// @param this
/// @param nombre
/// @return
int Passenger_getNombre(Passenger* this,char* nombre)
{
	int exit_status = 0;
		if(this != NULL && nombre != NULL)
		{
			strcpy(nombre, this->nombre);
			exit_status = 1;
		}

	return exit_status;
}

/// @fn int Passenger_setApellido(Passenger*, char*)
/// @brief
///
/// @param this
/// @param apellido
/// @return
int Passenger_setApellido(Passenger* this,char* apellido)
{
	int exit_status = 0;
	if(this != NULL && apellido != NULL)
	{
		strncpy(this->apellido, apellido, sizeof(this->apellido));
		exit_status = 1;
	}

	return exit_status;
}

/// @fn int Passenger_getApellido(Passenger*, char*)
/// @brief
///
/// @param this
/// @param apellido
/// @return
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int exit_status = 0;
		if(this != NULL && apellido != NULL)
		{
			strcpy(apellido, this->apellido);
			exit_status = 1;
		}

	return exit_status;
}

/// @fn int Passenger_setCodigoVuelo(Passenger*, char*)
/// @brief
///
/// @param this
/// @param codigoVuelo
/// @return
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int exit_status = 0;
	if(this != NULL && codigoVuelo != NULL)
	{
		strncpy(this->codigoVuelo, codigoVuelo, sizeof(this->codigoVuelo));
		exit_status = 1;
	}

	return exit_status;
}

/// @fn int Passenger_getCodigoVuelo(Passenger*, char*)
/// @brief
///
/// @param this
/// @param codigoVuelo
/// @return
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int exit_status = 0;
		if(this != NULL && codigoVuelo != NULL)
		{
			strcpy(codigoVuelo, this->codigoVuelo);
			exit_status = 1;
		}

	return exit_status;
}

/// @fn int Passenger_setTipoPasajero(Passenger*, int)
/// @brief
///
/// @param this
/// @param tipoPasajero
/// @return
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int exit_status = 0;
	if(this != NULL && (tipoPasajero > 0 && tipoPasajero < 4))
	{
		this->tipoPasajero = tipoPasajero;
		exit_status = 1;
	}

	return exit_status;
}

/// @fn int Passenger_getTipoPasajero(Passenger*, int*)
/// @brief
///
/// @param this
/// @param tipoPasajero
/// @return
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int exit_status = 0;
		if(this != NULL && tipoPasajero != NULL)
		{
			*tipoPasajero = this->tipoPasajero;
			exit_status = 1;
		}

	return exit_status;
}

/// @fn int Passenger_setPrecio(Passenger*, float)
/// @brief
///
/// @param this
/// @param precio
/// @return
int Passenger_setPrecio(Passenger* this,float precio)
{
	int exit_status = 0;
	if(this != NULL && precio > 0)
	{
		this->precio = precio;
		exit_status = 1;
	}

	return exit_status;
}

/// @fn int Passenger_getPrecio(Passenger*, float*)
/// @brief
///
/// @param this
/// @param precio
/// @return
int Passenger_getPrecio(Passenger* this,float* precio)
{
	int exit_status = 0;
		if(this != NULL && precio != NULL)
		{
			*precio = this->precio;
			exit_status = 1;
		}

	return exit_status;
}

/// @fn int Passenger_setStatusFlight(Passenger*, char*)
/// @brief
///
/// @param this
/// @param statusFlight
/// @return
int Passenger_setStatusFlight(Passenger* this,char* statusFlight)
{
	int exit_status = 0;
	if(this != NULL && statusFlight != NULL)
	{
		strncpy(this->statusFlight, statusFlight, sizeof(this->statusFlight));

		exit_status = 1;
	}

	return exit_status;
}

/// @fn int Passenger_getStatusFlight(Passenger*, char*)
/// @brief
///
/// @param this
/// @param statusFlight
/// @return
int Passenger_getStatusFlight(Passenger* this,char* statusFlight)
{
	int exit_status = 0;
		if(this != NULL && statusFlight != NULL)
		{
			strcpy(statusFlight, this->statusFlight);
			exit_status = 1;
		}

	return exit_status;
}



int Passenger_swap(Passenger* first, Passenger* second)
{
	int exit_status = 0;
	Passenger* auxPass = NULL;

	if(first != NULL && second != NULL)
	{
		auxPass = first;
		first = second;
		second = auxPass;
		auxPass = NULL;
		exit_status = 1;
	}
    return exit_status;
}
// COMPARADORAS



int Passenger_compareByCodigoVuelo(void* a, void* b)
{
	int comparison = 0;
	char codigoVuelo1[8], codigoVuelo2[8];
	Passenger* first;
	Passenger* second;

	if(a != NULL && b != NULL)
	{
		// casteo a Passenger
		first = (Passenger*) a;
		second = (Passenger*) b;
		// cargo codigos de vuelo
		Passenger_getCodigoVuelo(first, codigoVuelo1);
		Passenger_getCodigoVuelo(second, codigoVuelo2);
		// comparacion de strings
		comparison = strcmp(codigoVuelo1, codigoVuelo2);
		if(comparison > 0)
		{
			comparison = 1;
		}
		else if(comparison < 0)
		{
			comparison = -1;
		}
	}
    return comparison;
}





//*/






