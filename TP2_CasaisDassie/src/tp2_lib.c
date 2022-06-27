#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "my_lib.h"
#include "ArrayPassenger.h"
#include "tp2_lib.h"
#include "utn.h"


int menu()
{
    int opcion;

    printf(" *** Menu de opciones ***\n\n");
    printf("1- Alta \n");
    printf("2- Modificacion \n");
    printf("3- Baja \n");
    printf("4- Informar \n");
    printf("5- Carga forzada \n");
    printf("6- Salir \n\n");

    utn_getNumero(&opcion, "Ingrese opcion: ", "Opcion invalida. Ingrese un valor numerico.\n", 1, 6, 5);

    return opcion;
}

int pedirDatos(Passenger* pass)
{
    Passenger aux_ps;
    int exit_status = -1;
    if(pass != NULL)
    {
    	// nombre
    	utn_getTexto(aux_ps.name, "Ingrese nombre del pasajero: ", "Nombre invalido. Ingrese solo caracteres.\n", 50, 5);
    	// apellido
    	utn_getTexto(aux_ps.lastName, "Ingrese apellido del pasajero: ", "Apellido invalido. Ingrese solo caracteres.\n", 50, 5);
    	// precio
    	utn_getNumeroDecimal(&aux_ps.price, "Ingrese precio: ", "Error. Ingrese un precio entre 1 y 99.999.999.\n ", 1, 99999999, 5);
    	// codigo de vuelo
    	utn_getTextoAlfanumerico(aux_ps.flycode, "Ingrese codigo de vuelo (alfanumerico): ", "Codigo invalido. Ingrese caracteres alfanumericos.\n", 11, 5);
    	// tipo de pasajero
    	utn_getNumero(&aux_ps.typePassenger, "Ingrese tipo de pasajero (0: Turista, 1: Primera Clase, 2: Ejecutivo): ", "Valor invalido.\n", 0, 2, 5);
    	// estado de vuelo
    	utn_getNumero(&aux_ps.statusFlight, "Ingrese estado de vuelo (0: Suspendido, 1: Activo): ", "Valor invalido.\n", 0, 1, 5);

        *pass = aux_ps;
        exit_status = 0;
    }
    return exit_status;
}

int checkEntry(Passenger list[], int len)
{
    int index = -1;
    if(list != NULL && len>0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty)
            {
                index = i;
                break;
            }
        }
    }
    return index;
}

int hardcodearPasajeros(Passenger list[], int len, int cant, int* nextId, int* flag)
{

    int todoOk = -1;
    Passenger impostores[] =
    {
        {0, "Mariela", "Gomez", 20000, "AA200",1, 1},
        {0, "Juan Pablo", "Martinez", 30000,"LA201",2,1},
        {0, "Mauro", "Gomez", 18000,"AA200",2,1},
        {0, "Yolanda", "Alberdi", 32000,"LA200",1,1},
        {0, "Fabio", "Benitez", 45000,"AA220",2,2},
        {0, "Juana", "Gramigna", 139000,"FB100",2,1},
        {0, "Miguel", "Del Sel", 120000,"AB100",2,1},
        {0, "Luciano", "Pereyra", 155000,"GB100",1,0},
        {0, "Marina", "Muller", 220000,"GBG00",1,1},
        {0, "Dalma", "Maradona", 119500,"HH100",0,1}
    };

    if(list != NULL && len > 0 && nextId != NULL && cant > 0 && cant <= 10)
    {

        for(int i=0; i < cant; i++)
        {
            list[i] = impostores[i];
            list[i].id = *nextId;
            *nextId = *nextId +1;
            *flag = *flag +1;

        }
        todoOk = 0;
    }
    return todoOk;

}

int pedirBaja(Passenger list[], int len, int* flag)
{
    int exit_status = -1;
    int id = 0;
    char confirmar = 'n';

    if(list != NULL && len > 0)
    {
        printPassengers(list, len);


        utn_getNumero(&id, "Ingrese la id del pasajero: ", "Error. Id inexistente.\n", 1000, 200000, 3);

        while(!checkValidId(list, len, id))
        {
        	printf("Error. Id inexistente.\n");
        	utn_getNumero(&id, "Ingrese la id del pasajero: ", "Error. Id inexistente.\n", 1000, 200000, 3);
        }

        printf("Ud ingreso la id %d. Esta seguro que desea eliminar al pasajero?\n", id);
        printf("(Ingrese 'S/s' para confirmar, cualquier otra cosa para cancelar: \n");
        __fpurge(stdin);
        scanf("%c", &confirmar);
        if(confirmar == 's' || confirmar == 'S')
        {
            if(removePassenger(list, len, id) == 0)
            {
            	printf("*** Baja realizada con exito. \n");
				*flag = *flag -1;
				exit_status = 0;
            }
            else
            {
            	printf("*** No se pudo realizar la baja.\n");
            }
        }
        else
        {
            printf("Baja cancelada por el usuario.\n");
        }

    }
    return exit_status;
}
int pedirModificacion(Passenger list[], int len)
{
    int exit_status = -1;
    int id;
    int index;
    Passenger aux_ps;
    char estado[11];
    char salir = 'n';

    if(list != NULL && len > 0)
    {
        printPassengers(list, len);
        utn_getNumero(&id, "Ingrese la id del pasajero: ", "Error. Id inexistente.\n", 1000, 200000, 3);

        while(!checkValidId(list, len, id))
        {
        	printf("Error. Id inexistente.\n");
        	utn_getNumero(&id, "Ingrese la id del pasajero: ", "Error. Id inexistente.\n", 1000, 200000, 3);
        }

        index = findPassengerById(list, len, id);
        aux_ps = list[index];
        if(aux_ps.statusFlight)
                {
                    strcpy(estado, "Activo");
                }
                else
                {
                    strcpy(estado, "Suspendido");
                }
        system("clear");
        printf("   Id          Nombre           Apellido          Precio         Codigo    Tipo    Estado\n");
        printf("---------------------------------------------------------------------------------------------\n");
        printf("  %5d%15s  %15s \t %9.2f \t %s \t    %d   %s\n\n",
                aux_ps.id, aux_ps.name, aux_ps.lastName, aux_ps.price,
                aux_ps.flycode, aux_ps.typePassenger, estado);

        do
        {
            switch(menuModificar())
            {
                case 1:
                		utn_getTexto(list[index].name, "Ingrese nuevo nombre: ", "Nombre invalido.\n", 50, 5);
                        printf("Se ha modificado el nombre\n");
                        break;
                    case 2:
                    	utn_getTexto(list[index].lastName, "Ingrese nuevo apellido: ", "Apellido invalido.\n", 50, 5);
						printf("Se ha modificado el apellido\n");
						break;
                    case 3:
                    	utn_getNumeroDecimal(&list[index].price, "Ingrese nuevo precio: ", "Precio invalido.\n", 1, 99999999, 5);
                    	printf("Se ha modificado el precio\n");
                        break;
                    case 4:

                    	utn_getNumero(&list[index].typePassenger, "Ingrese tipo de pasajero (0: Turista, 1: Primera Clase, 2: Ejecutivo): ", "Error. Ingrese un tipo de pasajero entre 0 y 2. \n", 0, 2, 5);
                        printf("Se ha modificado el tipo de pasajero\n");
                        break;
                    case 5:
                    	utn_getTextoAlfanumerico(list[index].flycode, "Ingrese codigo de vuelo (alfanumerico): ", "Codigo invalido.\n", 10, 5);
                        printf("Se ha modificado el codigo de vuelo\n");
                        break;
                    case 6:
                        salir = 's';
                        break;
            }

        }while(salir != 's');

    }
    return exit_status;

}

int checkValidId(Passenger list[], int len, int id)
{
    int isValid = 0;

    if(list != NULL && len > 0 && id > 0)
    {
        for(int i=0; i < len; i++)
        {
            if(list[i].id == id && !list[i].isEmpty)
            {
                isValid = 1;
                break;
            }
        }
    }
    return isValid;
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
    printf("6- Salir\n");

    utn_getNumero(&opcion, "Ingrese opcion: ", "Opcion invalida. Ingrese un valor numerico.\n", 1, 6, 5);
    return opcion;
}

int pedirInformes(Passenger list[], int len)
{
    int exit_status = -1;
    char salir = 'n';
    float totalPrecios = 0;
    float promedioPrecios = 0;
    int cantSupera = 0;


    do
    {
        switch(menuInformes())
        {
            case 1:
                system("clear");
                sortPassengers(list, len, 1);
                printPassengers(list, len);
                break;
            case 2:
                system("clear");
                calcularPromedio(list, len, &totalPrecios, &promedioPrecios, &cantSupera);
                printf("Total precio pasajes: %.2f\n", totalPrecios);
                printf("Promedio precio pasajes: %.2f\n", promedioPrecios);
                printf("Cantidad de pasajeros por encima del promedio: %d\n\n", cantSupera);

                break;
            case 3:
                system("clear");
                sortPassengersByCode(list, len, 1);
                printActivePassengers(list, len);
                break;
            case 4:
                salir = 's';
                break;
        }


    }while(salir != 's');

    exit_status = 0;
    return exit_status;
}

int menuInformes()
{
    int opcion;
    printf("1- Informar todos los pasajeros\n\n");
    printf("2- Total y promedio de los precios de los pasajes, \n  y cuántos pasajeros superan el precio promedio.\n\n");
    printf("3- Listado de los pasajeros por Código de vuelo \n  y estados de vuelos ‘ACTIVO’\n\n");
    printf("4- Salir\n");

    utn_getNumero(&opcion, "Ingrese opcion: ", "Opcion invalida. Ingrese un valor numerico.\n", 1, 4, 5);

    return opcion;
}

int calcularPromedio(Passenger list[], int len, float* total, float* promedio, int* cantSupera)
{
    int exit_status = -1;
    int contador = 0;
    float acumulador = 0;
    int contadorSupera = 0;

    for(int i=0; i<len; i++)
    {
        if(!list[i].isEmpty)
        {
            acumulador += list[i].price;
            contador += 1;
        }
    }
    *total = acumulador;
    if(contador > 0)
    {
        *promedio = acumulador/contador;
    }


    for(int i=0; i<len; i++)
    {
        if(list[i].price > *promedio)
        {
            contadorSupera += 1;
        }
    }
    *cantSupera = contadorSupera;
    return exit_status;
}

int printActivePassengers(Passenger* list, int len)
{
    int exit_status = -1;
    char estado[11];
    Passenger aux_ps;
    if(list != NULL && len >0)
    {

        printf("     \t\t*** Lista de Pasajeros  ***\n");
        printf("--------------------------------------------------------\n\n");
        printf("   Id          Nombre           Apellido          Precio         Codigo    Tipo    Estado\n");
        printf("---------------------------------------------------------------------------------------------\n");
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty == 0 && list[i].statusFlight)
            {
                strcpy(estado, "Activo");
                aux_ps = list[i];
                printf("  %5d%15s  %15s \t %9.2f \t %s \t    %d   %s\n",
                aux_ps.id, aux_ps.name, aux_ps.lastName, aux_ps.price,
                aux_ps.flycode, aux_ps.typePassenger, estado);
            }
        }
        printf("\n");


    }

    return exit_status;
}
