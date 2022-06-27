#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"

int initPassengers(Passenger* list, int len)
{
    int exit_status = -1;

    if(list != NULL && len > 0)
    {
        for(int i=0; i<len; i++)
        {
            list[i].isEmpty = 1;
        }
        exit_status = 0;
    }

    return exit_status;
}

int addPassenger(Passenger* list, int len, int id, char name[],char
                 lastName[],float price,int typePassenger, char flycode[], int statusFlight)
{
    int exit_status = -1;

    if(list!=NULL && len>0 && name != NULL && lastName != NULL && flycode != NULL
    && typePassenger <= 4 && typePassenger >= 0)
    {
        Passenger auxPassenger; //defino un auxiliar de tipo Passenger

        int index = -1;
        // recorre el array buscando un lugar libre
        // si no existe, el index sigue valiendo -1
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty)
            {
                index = i;
                break;
            }
        }
        if(index >= 0)
        {
            // asignamos los valores al aux
            auxPassenger.id = id;
            strcpy(auxPassenger.name, name);
            strcpy(auxPassenger.lastName, lastName);
            auxPassenger.price = price;
            strcpy(auxPassenger.flycode, flycode);
            auxPassenger.typePassenger = typePassenger;
            auxPassenger.isEmpty = 0;
            auxPassenger.statusFlight = statusFlight;

            list[index] = auxPassenger;

            exit_status = 0;
        }
    }
    return exit_status;
}

int printPassengers(Passenger* list, int len)
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
            if(list[i].isEmpty == 0)
            {
                if(list[i].statusFlight)
                {
                    strcpy(estado, "Activo");
                }
                else
                {
                    strcpy(estado, "Suspendido");
                }
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

int findPassengerById(Passenger* list, int len,int id)
{
    int index = -1;
    if(list != NULL && len > 0 && id >0)
    {
       for(int i=0; i<len; i++)
       {
            if(list[i].id == id)
            {
                index = i;
                break;
            }
       }
    }
    return index;
}

int removePassenger(Passenger* list, int len, int id)
{
    int exit_status = -1;
    int index;
    if(list != NULL && len > 0 && id > 0)
    {
        index = findPassengerById(list, len, id);
        if(index >= 0)
        {
            list[index].isEmpty = 1;
            exit_status = 0;
        }
    }
    return exit_status;
}

int sortPassengers(Passenger* list, int len, int order)
{
    int exit_status = -1;
    Passenger aux_ps;
    if(list != NULL && len >0 && (order == 1 || order == 0) )
    {
        for(int i=0; i<len-1; i++)
        {
            for(int j=i+1; j<len; j++)
            {               // condicion ascendente
                if( (order && (
                        // si son del mismo tipo, ordeno por apellido
                    (list[i].typePassenger == list[j].typePassenger &&
                        (strcmp(list[i].lastName, list[j].lastName) > 0))
                     || // si son de distinto tipo, ordeno por tipo
                     (list[i].typePassenger != list[j].typePassenger &&
                      list[i].typePassenger > list[j].typePassenger)
                    ))      // condicion descendente
                ||  (!order && (
                        // si son del mismo tipo, ordeno por apellido
                    (list[i].typePassenger == list[j].typePassenger &&
                        (strcmp(list[i].lastName, list[j].lastName) < 0))
                     || // si son de distinto tipo, ordeno por tipo
                     (list[i].typePassenger != list[j].typePassenger &&
                      list[i].typePassenger < list[j].typePassenger)
                    ))
                )
                {   //swapeo
                    aux_ps = list[i];
                    list[i] = list[j];
                    list[j] = aux_ps;
                }
            }
        }
        exit_status = 0;
    }
    return exit_status;
}

int sortPassengersByCode(Passenger* list, int len, int order)
{
    int exit_status = -1;
    Passenger aux_ps;
    if(list != NULL && len >0 && (order == 1 || order == 0) )
    {
        for(int i=0; i<len-1; i++)
        {
            for(int j=i+1; j<len; j++)
            {               // condicion ascendente
                if( (order && (
                        // si son del mismo tipo, ordeno por apellido
                    (list[i].statusFlight == list[j].statusFlight &&
                        (strcmp(list[i].flycode, list[j].flycode) > 0))
                     || // si son de distinto tipo, ordeno por tipo
                     (list[i].statusFlight != list[j].statusFlight &&
                      list[i].statusFlight > list[j].statusFlight)
                    ))      // condicion descendente
                ||  (!order && (
                        // si son del mismo tipo, ordeno por apellido
                    (list[i].statusFlight == list[j].statusFlight &&
                        (strcmp(list[i].flycode, list[j].flycode) < 0))
                     || // si son de distinto tipo, ordeno por tipo
                     (list[i].statusFlight != list[j].statusFlight &&
                      list[i].statusFlight < list[j].statusFlight)
                    ))
                )
                {   //swapeo
                    aux_ps = list[i];
                    list[i] = list[j];
                    list[j] = aux_ps;
                }
            }
        }
        exit_status = 0;
    }
    return exit_status;
}
