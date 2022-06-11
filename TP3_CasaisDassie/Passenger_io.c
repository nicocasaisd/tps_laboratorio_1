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

int pedirDatos(Passenger* pass)
{
    Passenger aux_ps;
    int exit_status = 0;
    if(pass != NULL)
    {
        printf("Ingrese nombre del pasajero: ");
        utn_gets(aux_ps.nombre, 50);
        while(!validarCadena(aux_ps.nombre, 50))
        {
            printf("Nombre demasiado largo. Ingrese nombre del pasajero: ");
            utn_gets(aux_ps.nombre, 50);
        }
        printf("Ingrese apellido del pasajero: ");
        utn_gets(aux_ps.apellido, 50);
        while(!validarCadena(aux_ps.apellido, 50))
        {
            printf("Apellido demasiado largo. Ingrese apellido del pasajero: ");
            utn_gets(aux_ps.apellido, 50);
        }
        printf("Ingrese precio: ");
        if(scanf("%f", &aux_ps.precio)==0)
        {
            printf("Error. Valor no numerico.");
        }
        while(!validarPrecio(aux_ps.precio))
        {
            __fpurge(stdin);
            printf("Error. Ingrese un precio entre 1 y 99.999.999: ");
            if(scanf("%f", &aux_ps.precio)==0)
            {
                printf("Error. Valor no numerico.");
            }
        }

        printf("Ingrese codigo de vuelo (alfanumerico): ");
        utn_gets(aux_ps.codigoVuelo, 9);
        while(!validarCadena(aux_ps.codigoVuelo, 9))
        {
            printf("Codigo demasiado largo. Ingrese codigo del pasajero: ");
            utn_gets(aux_ps.codigoVuelo, 9);
        }
        printf("Ingrese tipo de pasajero (0: EconomyClass, 1: FirstClass, 2: ExecutiveClass): ");
        if(scanf("%d", &aux_ps.tipoPasajero) == 0)
        {
            __fpurge(stdin);
            printf("Error. Valor no numerico.\n");
        }
        while(!validarIntRango(aux_ps.tipoPasajero, 0, 2))
        {
            printf("Error. Ingrese un tipo de pasajero entre 0 y 2: ");
            if(scanf("%d", &aux_ps.tipoPasajero) == 0)
            {
                __fpurge(stdin);
                printf("Error. Valor no numerico.\n");
            }
        }
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


int validarCadena(char str[], int largo)
{
    int esValido = 0;
    if(strlen(str) < largo)
    {
        esValido = 1;
    }
    return esValido;
}

int validarPrecio(float precio)
{
    int esValido = 0;
    if(precio >= 1 && precio <= 99999999)
    {
        esValido = 1;
    }
    return esValido;
}

int validarIntRango(int opcion, int minimo, int maximo)
{
    int esValido = 0;
    if(opcion >= minimo && opcion <= maximo)
    {
        esValido = 1;
    }
    return esValido;
}

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
