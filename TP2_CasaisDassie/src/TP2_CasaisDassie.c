/*
 ============================================================================
 Name        : TP2_Nico.c
 Author      : Nicolas
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"
#include "tp2_lib.h"
#include "my_lib.h"

#define TAM 2000



int main()
{
	setbuf(stdout, NULL);
    char salir = 'n';
    int nextId = 10000;
    int flagPassenger = 0;

    Passenger list[TAM];
    Passenger aux_ps;

    initPassengers(list, TAM);
    hardcodearEmpleados(list, TAM, 1, &nextId, &flagPassenger);


    do
    {
        system("clear");
        //opcion = ;
        switch(menu())
        {
        case 1:
            system("clear");
            printf("\t\t *** Menu Alta Pasajero ***\n\n");
            if(checkEntry(list, TAM)>-1)
            {
                pedirDatos(&aux_ps);
                if(addPassenger(list, TAM, nextId, aux_ps.name, aux_ps.lastName, aux_ps.price,
                aux_ps.typePassenger, aux_ps.flycode, aux_ps.statusFlight) == 0)
                {
                    nextId ++;
                    printf("Pasajero agregado con exito!");
                    flagPassenger ++;
                }
                else
                {
                    printf("Ocurrio un error al realizar la carga.");
                }
            }

            break;
        case 2:
            if(flagPassenger > 0)
            {
                system("clear");
                printf("\t\t *** Menu Modificacion Pasajero ***\n\n");
                pedirModificacion(list, TAM);
            }
            else
            {
                printf("Aun no se ingresaron pasajeros!");
            }

            break;
        case 3:
        if(flagPassenger > 0)
            {
                system("clear");
                printf("\t\t *** Menu Baja Pasajero ***\n\n");
                pedirBaja(list, TAM, &flagPassenger);
            }
            else
            {
                printf("Aun no se ingresaron pasajeros!");
            }
            break;
        case 4:
            if(flagPassenger > 0)
            {
                system("clear");
                printf("\t\t *** Menu Informes Pasajeros ***\n\n");
                pedirInformes(list, TAM);
            }
            else
            {
                printf("Aun no se ingresaron pasajeros!");
            }
            break;
        case 5:
            salir = 's';
            break;
        }
        pausar();

    }
    while(salir!='s');

    return 0;
}


