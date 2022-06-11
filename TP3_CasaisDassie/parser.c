#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "my_lib.h"

/** \brief Parsea los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger, int* nextId)
{
	int exit_status = 0;
	int r;
	char id[50],nombre[50],apellido[50],precio[50], tipoPasajero[50],codigoVuelo[50],statusFlight[50];
	Passenger* auxPass;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		// lectura fantasma del encabezado
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, apellido, precio, codigoVuelo, tipoPasajero, statusFlight);

		while(!feof(pFile))
		{
			// guardo en variables auxiliares de tipo char
			r = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n\r]\n", id, nombre, apellido, precio, codigoVuelo, tipoPasajero, statusFlight);
			if(r == 7)
			{
				// si fscanf pudo cargar todas las variables
				// pido lugar para un Passenger en memoria dinamica
				auxPass = Passenger_new();
				if(auxPass != NULL)
				{
					// seteo el auxiliar tipo Passenger (casteando cuando necesario)
					//Passenger_setId(auxPass, atoi(id));
					Passenger_setId(auxPass, *nextId);
					*nextId += 1;
					Passenger_setNombre(auxPass, nombre);
					Passenger_setApellido(auxPass, apellido);
					Passenger_setPrecio(auxPass, atof(precio));
					Passenger_setCodigoVuelo(auxPass, codigoVuelo);
					Passenger_setTipoPasajero(auxPass, atoi(tipoPasajero));
					Passenger_setStatusFlight(auxPass, statusFlight);
					// printf para testeo
					//printf("id:%d nom:%s ape:%s pre:%.2f cod:%s tipo:%d stat:%s", auxPass->id, auxPass->nombre, auxPass->apellido, auxPass->precio, auxPass->codigoVuelo, auxPass->tipoPasajero, auxPass->statusFlight);

					//agrego el auxiliar Passenger cargado a la linkedlist
					ll_add(pArrayListPassenger, auxPass);
					// seteo el auxiliar a NULL por seguridad
					auxPass = NULL;
					exit_status = 1;
				}
			}
		}
	}
    return exit_status;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger, int* nextId)
{
	int exit_status = 0;
	Passenger* auxPass;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		while(!feof(pFile))
		{
			// pido lugar para un Passenger en memoria dinamica
			auxPass = Passenger_new();
			if(auxPass != NULL)
			{
				// leo del archivo binario 1 Passenger y lo asigno a auxPass
				fread(auxPass, sizeof(Passenger), 1, pFile);
				// condicional para evitar lectura fantasma del archivo
				if(feof(pFile))
				{
					break;
				}
				Passenger_setId(auxPass, *nextId);
				*nextId += 1;
				// printf para testeo
				//printf("id:%d nom:%s ape:%s pre:%.2f cod:%s tipo:%d stat:%s", auxPass->id, auxPass->nombre, auxPass->apellido, auxPass->precio, auxPass->codigoVuelo, auxPass->tipoPasajero, auxPass->statusFlight);

				//agrego el auxiliar Passenger cargado a la linkedlist
				ll_add(pArrayListPassenger, auxPass);
				// seteo el auxiliar a NULL por seguridad
				auxPass = NULL;
				exit_status = 1;
			}
		}

	}
    return exit_status;
}
