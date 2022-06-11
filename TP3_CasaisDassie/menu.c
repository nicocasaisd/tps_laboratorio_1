/*
 * menu.c
 *
 *  Created on: 10 jun. 2022
 *      Author: nicocasaisd
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "Passenger.h"


int menu()
{
    int opcion;

    printf(" *** Menu de opciones ***\n\n");
    printf("1- Cargar los datos de los pasajeros desde el archivo data.csv (modo texto). \n");
    printf("2- Cargar los datos de los pasajeros desde el archivo data.bin (modo binario).\n");
    printf("3- Alta de pasajero \n");
    printf("4- Modificar datos de pasajero \n");
    printf("5- Baja de pasajero \n");
    printf("6- Listar pasajeros \n");
    printf("7- Ordenar pasajeros \n");
    printf("8- Guardar los datos de los pasajeros en el archivo data.csv (modo texto). \n");
    printf("9- Guardar los datos de los pasajeros en el archivo data.bin (modo binario). \n");
    printf("10- Salir \n\n");
    printf("Ingrese opcion: ");
    if(scanf("%d", &opcion) == 0)
    {
        __fpurge(stdin);
        printf("Error. Valor no numerico.\n");
    }
    while(opcion < 1 || opcion > 10)
    {
        printf("Opcion invalida. Reingrese opcion: ");
        if(scanf("%d", &opcion) == 0)
        {
            __fpurge(stdin);
            printf("Error. Valor no numerico.\n");
        }
    }
    return opcion;
}

int menuModificar()
{
    int opcion;
    printf("     *** Campos a modificar ***\n");
    printf("1- Nombre\n");
    printf("2- Apellido\n");
    printf("3- Precio\n");
    printf("4- Tipo de pasajero\n");
    printf("5- Codigo de vuelo\n");
    printf("6- Estado de Vuelo\n");
    printf("7- Salir\n");
    printf("Ingrese opcion: ");
    if(scanf("%d", &opcion) == 0)
    {
        __fpurge(stdin);
        printf("Error. Valor no numerico.\n");
    }

    while(opcion < 1 || opcion > 7)
    {
        printf("Opcion invalida. Reingrese opcion: ");
        if(scanf("%d", &opcion) == 0)
        {
            __fpurge(stdin);
            printf("Error. Valor no numerico.\n");
        }
    }
    return opcion;
}

void printHeader()
{
	printf("  id       Nombre        Apellido        Precio       CodigoVuelo    TipoPasajero        Estado\n");
	printf("----------------------------------------------------------------------------------------------------\n");

}

