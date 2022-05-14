#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "/home/nicocasaisd/c/my_lib.h"
#include "ArrayPassenger.h"
#include "tp2_lib.h"

int menu()
{
    int opcion;

    printf(" *** Menu de opciones ***\n\n");
    printf("1- Alta \n");
    printf("2- Modificacion \n");
    printf("3- Baja \n");
    printf("4- Informar \n");
    printf("5- Salir \n\n");
    printf("Ingrese opcion: ");
    if(scanf("%d", &opcion) == 0)
    {
        __fpurge(stdin);
        printf("Error. Valor no numerico.\n");
    }
    while(opcion < 1 || opcion > 5)
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

int pedirDatos(Passenger* pass)
{
    Passenger aux_ps;
    int exit_status = -1;
    if(pass != NULL)
    {
        printf("Ingrese nombre del pasajero: ");
        utn_gets(aux_ps.name, 50);
        while(!validarCadena(aux_ps.name, 50))
        {
            printf("Nombre demasiado largo. Ingrese nombre del pasajero: ");
            utn_gets(aux_ps.name, 50);
        }
        printf("Ingrese apellido del pasajero: ");
        utn_gets(aux_ps.lastName, 50);
        while(!validarCadena(aux_ps.lastName, 50))
        {
            printf("Apellido demasiado largo. Ingrese apellido del pasajero: ");
            utn_gets(aux_ps.lastName, 50);
        }
        printf("Ingrese precio: ");
        if(scanf("%f", &aux_ps.price)==0)
        {
            printf("Error. Valor no numerico.");
        }
        while(!validarPrecio(aux_ps.price))
        {
            __fpurge(stdin);
            printf("Error. Ingrese un precio entre 1 y 99.999.999: ");
            if(scanf("%f", &aux_ps.price)==0)
            {
                printf("Error. Valor no numerico.");
            }
        }

        printf("Ingrese codigo de vuelo (alfanumerico): ");
        utn_gets(aux_ps.flycode, 9);
        while(!validarCadena(aux_ps.flycode, 9))
        {
            printf("Codigo demasiado largo. Ingrese codigo del pasajero: ");
            utn_gets(aux_ps.flycode, 9);
        }
        printf("Ingrese tipo de pasajero (0: Turista, 1: Primera Clase, 2: Ejecutivo): ");
        if(scanf("%d", &aux_ps.typePassenger) == 0)
        {
            __fpurge(stdin);
            printf("Error. Valor no numerico.\n");
        }
        while(!validarIntRango(aux_ps.typePassenger, 0, 2))
        {
            printf("Error. Ingrese un tipo de pasajero entre 0 y 2: ");
            if(scanf("%d", &aux_ps.typePassenger) == 0)
            {
                __fpurge(stdin);
                printf("Error. Valor no numerico.\n");
            }
        }
        printf("Ingrese estado de vuelo (0: Suspendido, 1: Activo): ");
        if(scanf("%d", &aux_ps.statusFlight) == 0)
        {
            __fpurge(stdin);
            printf("Error. Valor no numerico.\n");
        }
        while(!validarIntRango(aux_ps.statusFlight, 0, 1))
        {
            printf("Error. Ingrese un estado de vuelo entre 0 y 1: ");
            if(scanf("%d", &aux_ps.statusFlight) == 0)
            {
                __fpurge(stdin);
                printf("Error. Valor no numerico.\n");
            }
        }

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
        {0, "Juan", "Badia", 135000, "AB100",0, 0},
        {0, "Daniela", "Vellozzi", 120000,"VB100",1,0},
        {0, "Lucia", "Ceresani", 140000,"VB100",1,0},
        {0, "Mauro", "Zeta", 120000,"NB100",2,0},
        {0, "Diego", "Maradona", 112700,"ZB100",0,1},
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
    int id;
    char confirmar = 'n';

    if(list != NULL && len > 0)
    {
        printPassengers(list, len);
        printf("Ingrese la id del pasajero: ");
        if(scanf("%d", &id) == 0)
        {
            __fpurge(stdin);
            printf("Error. Valor no numerico.\n");
        }

        while(!checkValidId(list, len, id))
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
            removePassenger(list, len, id);
            printf("*** Baja realizada con exito. \n");
            *flag = *flag -1;
            exit_status = 0;
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
        printf("Ingrese la id del pasajero: ");
        if(scanf("%d", &id) == 0)
        {
            __fpurge(stdin);
            printf("Error. Valor no numerico.\n");
        }

        while(!checkValidId(list, len, id))
        {
            printf("Error. Id inexistente. Reingrese la id del pasajero: ");
            if(scanf("%d", &id) == 0)
            {
                __fpurge(stdin);
                printf("Error. Valor no numerico.\n");
            }
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
                        printf("\nIngrese nuevo nombre: ");
                        utn_gets(list[index].name, 50);
                        while(!validarCadena(list[index].name, 50))
                        {
                            printf("Nombre demasiado largo. Ingrese nombre del pasajero: ");
                            utn_gets(list[index].name, 50);
                        }
                        printf("Se ha modificado el nombre\n");
                        break;
                    case 2:
                        printf("\nIngrese nuevo apellido: ");
                        utn_gets(list[index].lastName, 50);
                        while(!validarCadena(list[index].lastName, 50))
                        {
                            printf("Apellido demasiado largo. Ingrese apellido del pasajero: ");
                            utn_gets(list[index].lastName, 50);
                        }
                        printf("Se ha modificado el apellido\n");
                        break;
                    case 3:
                        printf("\nIngrese nuevo precio: ");
                        scanf("%f", &list[index].price);
                        while(!validarPrecio(list[index].price))
                        {
                            printf("Error. Ingrese un precio entre 1 y 99.999.999: ");
                            scanf("%f", &list[index].price);
                        }
                        printf("Se ha modificado el precio\n");
                        break;
                    case 4:
                        printf("Ingrese tipo de pasajero (0: Turista, 1: Primera Clase, 2: Ejecutivo): ");
                        scanf("%d", &list[index].typePassenger);
                        while(!validarIntRango(list[index].typePassenger, 0, 2))
                        {
                            printf("Error. Ingrese un tipo de pasajero entre 0 y 2: ");
                            scanf("%d", &list[index].typePassenger);
                        }
                        printf("Se ha modificado el tipo de pasajero\n");
                        break;
                    case 5:
                        printf("Ingrese codigo de vuelo (alfanumerico): ");
                        utn_gets(list[index].flycode, 10);
                        while(!validarCadena(list[index].flycode, 9))
                        {
                            printf("Codigo demasiado largo. Ingrese codigo del pasajero: ");
                            utn_gets(list[index].flycode, 9);
                        }
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
    printf("Ingrese opcion: ");
    if(scanf("%d", &opcion) == 0)
    {
        __fpurge(stdin);
        printf("Error. Valor no numerico.\n");
    }

    while(opcion < 1 || opcion > 6)
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
    printf("Ingrese opcion: ");
    if(scanf("%d", &opcion) == 0)
    {
        __fpurge(stdin);
        printf("Error. Valor no numerico.\n");
    }
    while(opcion < 1 || opcion > 4)
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

// VALIDACIONES

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
