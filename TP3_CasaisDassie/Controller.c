#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "Passenger_io.h"
#include "menu.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char* Ruta del archivo
 * \param pArrayListPassenger LinkedList* Puntero a LinkedList
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger, int* nextId)
{
	int exit_status = 0;
	// abro el archivo en un puntero a struct FILE en modo 'read'
	FILE* pFile = fopen(path, "r");
	if(pFile != NULL)
	{
		printf("Cargando desde archivo de texto ... \n");
		// llamo a parser que me lo carga en la LinkedList
		parser_PassengerFromText(pFile , pArrayListPassenger, nextId);
		// cierro el archivo
		fclose(pFile);
		exit_status = 1;
	}
	else
	{
		printf("Ocurrio un error al cargar el archivo de texto.\n");
	}

    return exit_status;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger, int* nextId)
{
	int exit_status = 0;

	// abro el archivo en un puntero a struct FILE en modo 'read binary'
	FILE* pFile = fopen(path, "rb");
	if(pFile != NULL)
	{
		printf("Cargando desde archivo binario ... \n");
		// llamo a parser que me lo carga en la LinkedList
		parser_PassengerFromBinary(pFile , pArrayListPassenger, nextId);
		// cierro el archivo
		fclose(pFile);
		exit_status = 1;
	}
	else
	{
		printf("Ocurrio un error al cargar el archivo binario.\n");
	}

    return exit_status;
}

/// @fn int controller_addPassenger(LinkedList*, int*)
/// @brief
///
/// @param pArrayListPassenger
/// @param nextId
/// @return
int controller_addPassenger(LinkedList* pArrayListPassenger, int* nextId)
{
	int exit_status = 0;
	if(pArrayListPassenger != NULL)
	{
		// pedimos lugar en memoria dinamica para un pasajero
		Passenger* new_passenger = Passenger_new();
		// pedimos datos y lo cargamos en el nuevo pasajero
		pedirDatos(new_passenger);
		// agregamos la estructura en memoria dinamica a la linked list
		addPassengerLinkedList(pArrayListPassenger, new_passenger, nextId);
		exit_status = 1;
	}
    return exit_status;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int exit_status = 0;
	int index = pedirIndexModificacion(pArrayListPassenger);
	if(index != -1)
	{
		pedirModificacion(pArrayListPassenger, index);
		exit_status = 1;
	}

    return exit_status;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int exit_status = 0;
	int index = pedirIndexBaja(pArrayListPassenger);
	if(index != -1)
	{
		ll_remove(pArrayListPassenger, index);
		exit_status = 1;
	}
    return exit_status;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_listPassengers(LinkedList* pArrayListPassenger)
{
	int exit_status = 0;
	Passenger* auxPass;

	if(pArrayListPassenger != NULL)
	{
		// encabezado
		printHeader();
		for(int i=0; i<ll_len(pArrayListPassenger); i++)
		{
			auxPass = (Passenger*) ll_get(pArrayListPassenger, i);
			printPassenger(auxPass);
		}
		exit_status = 1;
	}




    return exit_status;
}

/** \brief Ordenar pasajeros
 *
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int exit_status = 0;
	// recorro la linkedlist
	if(pArrayListPassenger != NULL)
	{
		ll_sort(pArrayListPassenger, Passenger_compareByCodigoVuelo, 1);
		exit_status = 1;
	}


    return exit_status;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int exit_status = 0;
	Passenger* pAux = NULL;
	FILE* pFile = fopen(path, "w");


	if(pFile != NULL)
	{
		//escribimos el encabezado
		fprintf(pFile, "id,name,lastname,price,flycode,typePassenger,statusFlight\n");
		for(int i=0; i<ll_len(pArrayListPassenger); i++)
		{
			pAux = ll_get(pArrayListPassenger, i);
			fprintf(pFile, "%d,%s,%s,%.2f,%s,%d,%s\n", pAux->id, pAux->nombre, pAux->apellido, pAux->precio, pAux->codigoVuelo, pAux->tipoPasajero, pAux->statusFlight);

		}
		fclose(pFile);
		printf("Escrbiendo en archivo de texto ...\n");
		exit_status = 1;
	}
    return exit_status;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int exit_status = 0;
	Passenger* pAux = NULL;
	FILE* pFile = fopen(path, "wb");


	if(pFile != NULL)
	{
		for(int i=0; i<ll_len(pArrayListPassenger); i++)
		{
			pAux = ll_get(pArrayListPassenger, i);
			fwrite(pAux, sizeof(Passenger), 1, pFile);
		}
		fclose(pFile);
		printf("Escrbiendo en archivo binario ...\n");
		exit_status = 1;
	}
    return exit_status;
}

