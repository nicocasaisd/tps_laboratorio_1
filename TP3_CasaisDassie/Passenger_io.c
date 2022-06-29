/*
 * Passenger_io.c
 *
 *  Created on: 10 jun. 2022
 *      Author: nicocasaisd
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "Passenger_io.h"
#include "Controller.h"
#include "my_lib.h"
#include "menu.h"
#include "utn_inputs.h"

/// @fn int pedirDatos(Passenger*)
/// @brief Pide datos al usuario y los guarda en la estructura a la que apunta pass
///
/// @param pass Puntero a Passenger
/// @return Devuelve 0 si ocurrio un error, y 1 si se completo exitosamente.
int pedirDatos(Passenger* pass)
{
    Passenger aux_ps;
    int exit_status = 0;
    if(pass != NULL)
    {
    	// nombre
		utn_getTexto(aux_ps.nombre, "Ingrese nombre del pasajero: ", "Nombre invalido. Ingrese solo caracteres.\n", 50, 5);
		// apellido
		utn_getTexto(aux_ps.apellido, "Ingrese apellido del pasajero: ", "Apellido invalido. Ingrese solo caracteres.\n", 50, 5);


		// precio
		utn_getNumeroDecimal(&aux_ps.precio, "Ingrese precio: ", "Error. Ingrese un precio entre 1 y 99.999.999.\n ", 1, 99999999, 5);


		// codigo de vuelo
		utn_getTextoAlfanumerico(aux_ps.codigoVuelo, "Ingrese codigo de vuelo (alfanumerico): ", "Codigo invalido. Ingrese caracteres alfanumericos.\n", 11, 5);


		// tipo de pasajero
		utn_getNumero(&aux_ps.tipoPasajero, "Ingrese tipo de pasajero (0: Turista, 1: Primera Clase, 2: Ejecutivo): ", "Valor invalido.\n", 0, 2, 5);


		// estado de vuelo
        printf("Ingrese estado de vuelo ('Aterrizado','En Horario','En Vuelo','Demorado'): ");
        utn_gets(aux_ps.statusFlight, 20);
                while(!validarCadenaStatusFlight(aux_ps.statusFlight, 20))
                {
                    printf("Codigo invalido. Ingrese codigo del pasajero: ");
                    utn_gets(aux_ps.statusFlight, 20);
                }

        *pass = aux_ps;
        exit_status = 1;
    }
    return exit_status;
}

/// @fn int pedirIndexBaja(LinkedList*)
/// @brief Pide al usuario que elija un pasajero para borrar y devuelve el indice en la LinkedList
///
/// @param pArrayListPassenger Puntero a LinkedList
/// @return Devuelve un entero con el indice, -1 si ocurrio un error
int pedirIndexBaja(LinkedList* pArrayListPassenger)
{
	int index = -1;
	int id;
	char confirmar;

	controller_listPassengers(pArrayListPassenger);

    printf("Ingrese la id del pasajero: ");
    if(scanf("%d", &id) == 0)
    {
        __fpurge(stdin);
        printf("Error. Valor no numerico.\n");
    }

    while(!checkValidId(pArrayListPassenger, id))
    {
        printf("Error. Id inexistente. Reingrese la id del pasajero: ");
        if(scanf("%d", &id) == 0)
        {
            __fpurge(stdin);
            printf("Error. Valor no numerico.\n");
        }
    }

    printf("Ud ingreso la id %d. Esta seguro que desea eliminar al pasajero?\n", id);
    printf("(Ingrese 'S/s' para confirmar, cualquier otra cosa para cancelar: \n");
    __fpurge(stdin);
    scanf("%c", &confirmar);
    if(confirmar == 's' || confirmar == 'S')
    {
    	index = getPassengerIndexById(pArrayListPassenger, id);
    }
    else
    {
    	index = -1;
        printf("Baja cancelada por el usuario.\n");
    }
	return index;
}

/// @fn int pedirIndexModificacion(LinkedList*)
/// @brief Pide al usuario que elija un pasajero para modificar y devuelve el indice en la LinkedList
///
/// @param pArrayListPassenger Puntero a LinkedList
/// @return Devuelve un entero con el indice, -1 si ocurrio un error
int pedirIndexModificacion(LinkedList* pArrayListPassenger)
{
	int index = -1;
	int id;
	char confirmar;

	controller_listPassengers(pArrayListPassenger);

    printf("Ingrese la id del pasajero: ");
    if(scanf("%d", &id) == 0)
    {
        __fpurge(stdin);
        printf("Error. Valor no numerico.\n");
    }

    while(!checkValidId(pArrayListPassenger, id))
    {
        printf("Error. Id inexistente. Reingrese la id del pasajero: ");
        if(scanf("%d", &id) == 0)
        {
            __fpurge(stdin);
            printf("Error. Valor no numerico.\n");
        }
    }

    printf("Ud ingreso la id %d. Esta seguro que desea modificar al pasajero?\n", id);
    printf("(Ingrese 'S/s' para confirmar, cualquier otra cosa para cancelar: \n");
    __fpurge(stdin);
    scanf("%c", &confirmar);
    if(confirmar == 's' || confirmar == 'S')
    {
    	index = getPassengerIndexById(pArrayListPassenger, id);
    }
    else
    {
    	index = -1;
        printf("Modificacion cancelada por el usuario.\n");
    }
	return index;
}

/// @fn int pedirModificacion(LinkedList*, int)
/// @brief Imprime el menu de modificacion y permite al usuario elegir e ingresar nuevos datos a los campos del pasajero
///
/// @param pArrayListPassenger Puntero a LinkedList
/// @param index Indice del pasajero a modificar
/// @return Devuelve 0 si ocurrio un error, y 1 si se completo exitosamente.
int pedirModificacion(LinkedList* pArrayListPassenger, int index)
{
	int exit_status = 0;
	char salir = 'n';
	char nombre[50], apellido[50], codigoVuelo[8], statusFlight[20];
	float precio;
	int tipoPasajero;
	Passenger* auxPass;

	auxPass = ll_get(pArrayListPassenger, index);
	printHeader();
	printPassenger(auxPass);
	printf("\n");
	do
	{
		switch(menuModificar())
		{
			case 1:
					printf("\nIngrese nuevo nombre: ");
					utn_gets(nombre, 50);
					while(!validarCadena(nombre, 50))
					{
						printf("Nombre demasiado largo. Ingrese nombre del pasajero: ");
						utn_gets(nombre, 50);
					}
					Passenger_setNombre(auxPass, nombre);
					printf("Se ha modificado el nombre\n");
					break;
				case 2:
					printf("\nIngrese nuevo apellido: ");
					utn_gets(apellido, 50);
					while(!validarCadena(apellido, 50))
					{
						printf("Apellido demasiado largo. Ingrese apellido del pasajero: ");
						utn_gets(apellido, 50);
					}
					Passenger_setApellido(auxPass, apellido);
					printf("Se ha modificado el apellido\n");
					break;
				case 3:
					printf("\nIngrese nuevo precio: ");
					scanf("%f", &precio);
					while(!validarPrecio(precio))
					{
						printf("Error. Ingrese un precio entre 1 y 99.999.999: ");
						scanf("%f", &precio);
					}
					Passenger_setPrecio(auxPass, precio);
					printf("Se ha modificado el precio\n");
					break;
				case 4:
					printf("Ingrese tipo de pasajero (1: EconomyClass, 2: FirstClass , 3: ExecutiveClass): ");
					scanf("%d", &tipoPasajero);
					while(!validarIntRango(tipoPasajero, 1, 3))
					{
						printf("Error. Ingrese un tipo de pasajero entre 1 y 3: ");
						scanf("%d", &tipoPasajero);
					}
					Passenger_setTipoPasajero(auxPass, tipoPasajero);
					printf("Se ha modificado el tipo de pasajero\n");
					break;
				case 5:
					printf("Ingrese codigo de vuelo (alfanumerico): ");
					utn_gets(codigoVuelo, 9);
					while(!validarCadena(codigoVuelo, 8))
					{
						printf("Codigo demasiado largo. Ingrese codigo del pasajero: ");
						utn_gets(codigoVuelo, 9);
					}
					Passenger_setCodigoVuelo(auxPass, codigoVuelo);
					printf("Se ha modificado el codigo de vuelo\n");
					break;
				case 6:
					printf("Ingrese estado de vuelo ('Aterrizado','En Horario','En Vuelo','Demorado'): ");
					utn_gets(statusFlight, 20);
					while(!validarCadenaStatusFlight(statusFlight, 20))
					{
						printf("Estado de vuelo invalido. Ingrese estado de vuelo ('Aterrizado','En Horario','En Vuelo','Demorado'): ");
						utn_gets(statusFlight, 20);
					}
					Passenger_setStatusFlight(auxPass, statusFlight);
					printf("Se ha modificado el estado de vuelo\n");
					break;

				case 7:
					salir = 's';
					break;
		}

	}while(salir != 's');


	return exit_status;
}

/// @fn int getPassengerIndexById(LinkedList*, int)
/// @brief Obtiene el indice del pasajero a partir de su id
///
/// @param pArrayListPassenger Puntero a LinkedList
/// @param id Entero con la id del pasajero
/// @return Devuelve un entero con el indice, -1 si ocurrio un error
int getPassengerIndexById(LinkedList* pArrayListPassenger, int id)
{
	int index = -1;
	Passenger* auxPass;

	for(int i=0; i<ll_len(pArrayListPassenger); i++)
	{
		auxPass = ll_get(pArrayListPassenger, i);
		if(auxPass->id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

/// @fn int addPassengerLinkedList(LinkedList*, Passenger*, int*)
/// @brief Agrega un pasajero a la LinkedList y le asigna su id
///
/// @param pArrayListPassenger Puntero a LinkedList
/// @param newPassenger Puntero a Passenger
/// @param nextId Puntero a entero
/// @return Devuelve 0 si ocurrio un error, y 1 si se completo exitosamente.
int addPassengerLinkedList(LinkedList* pArrayListPassenger, Passenger* newPassenger, int* nextId)
{
    int exit_status = 0;

    if(pArrayListPassenger!=NULL && newPassenger != NULL && nextId != NULL)
    {
    	newPassenger->id = *nextId;
    	ll_add(pArrayListPassenger, newPassenger);
    	*nextId += 1;


		exit_status = 1;

    }
    return exit_status;
}

/// @fn int printPassenger(Passenger*)
/// @brief Imprime en pantalla los datos de un pasajero
///
/// @param auxPass Puntero a Passenger
/// @return Devuelve 0 si ocurrio un error, y 1 si se completo exitosamente.
int printPassenger(Passenger* auxPass)
{
	int exit_status = 0;
	int id, tipoPasajero;
	float precio;
	char nombre[50], apellido[50], codigoVuelo[8], statusFlight[20];

	if(auxPass != NULL)
	{
		// getters
		Passenger_getId(auxPass, &id);
		Passenger_getNombre(auxPass, nombre);
		Passenger_getApellido(auxPass, apellido);
		Passenger_getPrecio(auxPass, &precio);
		Passenger_getTipoPasajero(auxPass, &tipoPasajero);
		Passenger_getCodigoVuelo(auxPass, codigoVuelo);
		Passenger_getStatusFlight(auxPass, statusFlight);
		// print
		printf(" %4d   %10s \t%10s \t%9.2f \t%7s \t%d \t\t%s\n", id, nombre, apellido, precio, codigoVuelo, tipoPasajero, statusFlight);
		exit_status = 1;
	}

	return exit_status;
}











// VALIDACIONES


/// @fn int checkValidId(LinkedList*, int)
/// @brief Valida que la id ingresada pertenezca a un pasajero activo de la LinkedList
///
/// @param pArrayListPassenger Puntero a LinkedList
/// @param id Entero
/// @return Devuelve 1 si la id es valida, 0 si no es valida
int checkValidId(LinkedList* pArrayListPassenger, int id)
{
	int esValido = 0;
	Passenger* auxPass;

	for(int i=0; i<ll_len(pArrayListPassenger); i++)
	{
		auxPass = ll_get(pArrayListPassenger, i);
		if(auxPass->id == id)
		{
			esValido = 1;
			break;
		}
	}
	return esValido;
}
