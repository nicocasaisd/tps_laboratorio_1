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
/// @fn Passenger Passenger_newParametros*(char*, char*, char*, char*, char*, char*, char*)
/// @brief Crea una estructura Passenger en memoria dinamica y devuelve un puntero hacia ella a partir de todos sus campos como parametros tipo string
///
/// @param idStr
/// @param nombreStr
/// @param apellidoStr
/// @param precioStr
/// @param tipoPasajeroStr
/// @param codigoVueloStr
/// @param statusFlightStr
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
/// @fn void Passenger_delete(Passenger*)
/// @brief Libera en memoria a la estructura Passenger
///
/// @param this Puntero a Passenger a borrar
void Passenger_delete(Passenger* this)
{
	if(this != NULL)
	{
		free(this);
	}

}

/// @fn int Passenger_setId(Passenger*, int)
/// @brief Valida y asigna la id a la estructura Passenger
///
/// @param this Puntero a Passenger
/// @param id
/// @return Devuelve 0 si ocurrio un error, y 1 si se completo exitosamente.
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
/// @brief Obtiene la id de la estructura y la asigna en el valor del puntero int
///
/// @param this Puntero a Passenger
/// @param id Puntero a int de la id
/// @return Devuelve 0 si ocurrio un error, y 1 si se completo exitosamente.
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
/// @brief Valida y asigna el nombre a la estructura Passenger
///
/// @param this Puntero a Passenger
/// @param nombre Vector de caracteres
/// @return Devuelve 0 si ocurrio un error, y 1 si se completo exitosamente.
int Passenger_setNombre(Passenger* this,char* nombre)
{
	int exit_status = 0;
	if(this != NULL && nombre != NULL)
	{
		if(validarCadena(nombre, 50))
		{
			strncpy(this->nombre, nombre, sizeof(this->nombre));
			exit_status = 1;
		}
	}

	return exit_status;
}

/// @fn int Passenger_getNombre(Passenger*, char*)
/// @brief Obtiene la nombre de la estructura y la asigna en el valor del puntero char
///
/// @param this Puntero a Passenger
/// @param nombre Vector de caracteres
/// @return Devuelve 0 si ocurrio un error, y 1 si se completo exitosamente.
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
/// @brief Valida y asigna el nombre a la estructura Passenger
///
/// @param this Puntero a Passenger
/// @param apellido Vector de caracteres
/// @return Devuelve 0 si ocurrio un error, y 1 si se completo exitosamente.
int Passenger_setApellido(Passenger* this,char* apellido)
{
	int exit_status = 0;
	if(this != NULL && apellido != NULL)
	{
		if(validarCadena(apellido, 50))
		{
			strncpy(this->apellido, apellido, sizeof(this->apellido));
			exit_status = 1;
		}
	}

	return exit_status;
}

/// @fn int Passenger_getApellido(Passenger*, char*)
/// @brief Obtiene el apellido de la estructura y la asigna en el valor del puntero char
///
/// @param this Puntero a Passenger
/// @param apellido Vector de caracteres
/// @return Devuelve 0 si ocurrio un error, y 1 si se completo exitosamente.
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
/// @brief Valida y asigna el codigo de vuelo a la estructura Passenger
///
/// @param this Puntero a Passenger
/// @param codigoVuelo Vector de caracteres
/// @return Devuelve 0 si ocurrio un error, y 1 si se completo exitosamente.
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int exit_status = 0;
	if(this != NULL && codigoVuelo != NULL)
	{
		if(validarCadena(codigoVuelo, 8))
		{
			strncpy(this->codigoVuelo, codigoVuelo, sizeof(this->codigoVuelo));
			exit_status = 1;
		}
	}

	return exit_status;
}

/// @fn int Passenger_getCodigoVuelo(Passenger*, char*)
/// @brief Obtiene el codigo de vuelo de la estructura y la asigna en el valor del puntero int
///
/// @param this Puntero a Passenger
/// @param codigoVuelo Vector de caracteres
/// @return Devuelve 0 si ocurrio un error, y 1 si se completo exitosamente.
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
/// @brief Valida y asigna el tipo de pasajero a la estructura Passenger
///
/// @param this Puntero a Passenger
/// @param tipoPasajero Entero
/// @return Devuelve 0 si ocurrio un error, y 1 si se completo exitosamente.
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int exit_status = 0;
	if(this != NULL && validarIntRango(tipoPasajero, 1, 3))
	{
		this->tipoPasajero = tipoPasajero;
		exit_status = 1;
	}

	return exit_status;
}

/// @fn int Passenger_getTipoPasajero(Passenger*, int*)
/// @brief Obtiene el tipo de pasajero de la estructura y la asigna en el valor del puntero int
///
/// @param this Puntero a Passenger
/// @param tipoPasajero Puntero a entero
/// @return Devuelve 0 si ocurrio un error, y 1 si se completo exitosamente.
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
/// @brief Valida y asigna el precio a la estructura Passenger
///
/// @param this Puntero a Passenger
/// @param precio Float
/// @return Devuelve 0 si ocurrio un error, y 1 si se completo exitosamente.
int Passenger_setPrecio(Passenger* this,float precio)
{
	int exit_status = 0;
	if(this != NULL && validarIntRango(precio, 1, 99999999))
	{
		this->precio = precio;
		exit_status = 1;
	}

	return exit_status;
}

/// @fn int Passenger_getPrecio(Passenger*, float*)
/// @brief Obtiene el precio de la estructura y la asigna en el valor del puntero int
///
/// @param this Puntero a Passenger
/// @param precio Puntero a Float
/// @return Devuelve 0 si ocurrio un error, y 1 si se completo exitosamente.
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
/// @brief Valida y asigna el estado de vuelo a la estructura Passenger
///
/// @param this Puntero a Passenger
/// @param statusFlight Vector de caracteres
/// @return Devuelve 0 si ocurrio un error, y 1 si se completo exitosamente.
int Passenger_setStatusFlight(Passenger* this,char* statusFlight)
{
	int exit_status = 0;
	if(this != NULL && statusFlight != NULL)
	{
		if(validarCadenaStatusFlight(statusFlight, 20))
		{
			strncpy(this->statusFlight, statusFlight, sizeof(this->statusFlight));
			exit_status = 1;
		}

	}

	return exit_status;
}

/// @fn int Passenger_getStatusFlight(Passenger*, char*)
/// @brief Obtiene el estado de vuelo de la estructura y la asigna en el valor del puntero char
///
/// @param this Puntero a Passenger
/// @param statusFlight Vector de caracteres
/// @return Devuelve 0 si ocurrio un error, y 1 si se completo exitosamente.
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


// FUNCIONES COMPARADORAS


/// @fn int Passenger_compareByCodigoVuelo(void*, void*)
/// @brief Castea los punteros a Passenger y compara los codigos de vuelo de dos elementos. Funcion hecha para pasarse a ll_sort()
///
/// @param a Puntero a void que se castea a Passenger
/// @param b Puntero a void que se castea a Passenger
/// @return Devuelve 1 si el primero es mayor, -1 si es menor, 0 si son iguales
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

// VALIDACIONES



/// @fn int validarCadena(char[], int)
/// @brief Chequea que la cadena ingresada no exceda el largo máximo.
///
/// @param str Puntero a cadena
/// @param largo Numero entero maximo de caracteres permitidos
/// @return Devuelve 1 si la cadena es valida, 0 si la cadena es invalida
int validarCadena(char str[], int largo)
{
    int esValido = 0;
    if(str != NULL && strlen(str) < largo)
    {
        esValido = 1;
    }
    return esValido;
}

/// @fn int validarPrecio(float)
/// @brief Chequea que el valor flotante ingresado se encuentre dentro del rango definido
///
/// @param precio Valor flotante que se quiere validar
/// @return Devuelve 1 si el flotante es valido, 0 si es invalido
int validarPrecio(float precio)
{
    int esValido = 0;
    if(precio >= 1 && precio <= 99999999)
    {
        esValido = 1;
    }
    return esValido;
}
/// @fn int validarIntRango(int, int, int)
/// @brief Chequea que el valor entero ingresado se encuentre dentro del rango definido
///
/// @param opcion Valor entero que se quiere validar
/// @param minimo Entero minimo
/// @param maximo Entero maximo
/// @return Devuelve 1 si el entero es valido, 0 si es invalido
int validarIntRango(int opcion, int minimo, int maximo)
{
    int esValido = 0;
    if(opcion >= minimo && opcion <= maximo)
    {
        esValido = 1;
    }
    return esValido;
}
/// @fn int validarCadena(char[], int)
/// @brief Chequea que la cadena ingresada no exceda el largo máximo y que corresponda a los valores permitidos de Estado de Vuelo.
///
/// @param str Puntero a cadena
/// @param largo Numero entero maximo de caracteres permitidos
/// @return Devuelve 1 si la cadena es valida, 0 si la cadena es invalida
int validarCadenaStatusFlight(char str[], int largo)
{
    int esValido = 0;
    if(validarCadena(str, largo) &&
    		(strcmp(str, "Aterrizado") == 0 ||
			 strcmp(str, "En Horario") == 0 ||
			 strcmp(str, "En Vuelo") == 0 ||
			 strcmp(str, "Demorado") == 0
			))
    {
        esValido = 1;
    }
    return esValido;
}




//*/






