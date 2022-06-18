/*
 * Controller.c
 *
 *  Created on: 18 jun. 2022
 *      Author: nicocasaisd
 */

#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "Controller.h"
#include "micro.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char* Ruta del archivo
 * \param LinkedList LinkedList* Puntero a LinkedList
 * \return int Devuelve 0 si ocurrio un error, y 1 si se completo exitosamente.
 *
 */
int controller_loadFromText(char* path , LinkedList* LinkedList)
{
	int exit_status = 0;
	// abro el archivo en un puntero a struct FILE en modo 'read'
	FILE* pFile = fopen(path, "r");
	if(pFile != NULL)
	{
		printf("Cargando desde archivo de texto ... \n");
		// llamo a parser que me lo carga en la LinkedList
		parser_eMicroFromText(pFile , LinkedList);
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

/// @fn int parser_eMicroFromText(FILE*, LinkedList*)
/// @brief Parsea los datos de los pasajeros desde el archivo data.csv (modo texto).
///
/// @param pFile Puntero a FILE
/// @param LinkedList Puntero a LinkedList
/// @return Devuelve 0 si ocurrio un error, y 1 si se completo exitosamente.
int parser_eMicroFromText(FILE* pFile , LinkedList* LinkedList)
{
	int exit_status = 0;
	int r;
	char id[50],idEmpresa[50],idTipo[50],capacidad[50];
	eMicro* auxMicro;

	if(pFile != NULL && LinkedList != NULL)
	{
		// lectura fantasma del encabezado
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, idEmpresa, idTipo, capacidad);

		while(!feof(pFile))
		{
			// guardo en variables auxiliares de tipo char
			r = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, idEmpresa, idTipo, capacidad);
			if(r == 4)
			{
				// si fscanf pudo cargar todas las variables
				// pido lugar para un eMicro en memoria dinamica
				auxMicro = eMicro_new();
				if(auxMicro != NULL)
				{
					// seteo el auxiliar tipo eMicro (casteando cuando necesario)

					auxMicro->id = atoi(id);
					auxMicro->idEmpresa = atoi(idEmpresa);
					auxMicro->idTipo = atoi(idTipo);
					auxMicro->capacidad = atoi(capacidad);
					//agrego el auxiliar eMicro cargado a la linkedlist
					ll_add(LinkedList, auxMicro);
					// seteo el auxiliar a NULL por seguridad
					auxMicro = NULL;
					exit_status = 1;
				}
			}
		}
	}
    return exit_status;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char* Ruta del archivo donde se guarda
 * \param LinkedList LinkedList* Puntero a LinkedList
 * \return int Devuelve 0 si ocurrio un error, y 1 si se completo exitosamente.
 *
 */
int controller_saveAsText(char* path , LinkedList* LinkedList)
{
	int exit_status = 0;
	eMicro* pAux = NULL;
	FILE* pFile = fopen(path, "w");


	if(pFile != NULL)
	{
		//escribimos el encabezado
		fprintf(pFile, "id,idEmpresa,idTipo,capacidad\n");
		for(int i=0; i<ll_len(LinkedList); i++)
		{
			pAux = ll_get(LinkedList, i);
			fprintf(pFile, "%d,%d,%d,%d\n", pAux->id, pAux->idEmpresa, pAux->idTipo, pAux->capacidad);

		}
		fclose(pFile);
		printf("Escrbiendo en archivo de texto ...\n");
		exit_status = 1;
	}
    return exit_status;
}

void controller_imprimirSeparador(char* string)
{
    printf("\n********************************************************************\n");
	printf("**           %20s\n",string);
    printf("********************************************************************\n");

}
















