#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "parser.h"
#include "Passenger_io.h"
#include "my_lib.h"
#include "menu.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/




int main()
{
	setbuf(stdout, NULL);

    LinkedList* listaPasajeros = ll_newLinkedList();
    int nextId;
    // NOTA: El manejo del Id se hace a traves del archivo next_id.bin que al comenzar el programa lo carga, y al terminar lo guarda en como int nextId dentro del archivo binario.
    // De esa manera, podemos cargar nuevos pasajeros al programa antes de cargar desde archivo, y luego cuando los carguemos no se repetiran los ids.

    //cargamos desde next_id.bin
    if(controller_loadNextIdFromBinary(&nextId))
    {
    	printf("NextId cargado correctamente.\n");
    }
    int flagSave = 0;
    char salir = 'n';



    do{
    	system("clear");	// NOTA: Esta funcion no permite limpiar consola de Eclipse pero SI funciona desde el ejecutable con la consola real de Linux
        switch(menu())
        {
            case 1:
                if(controller_loadFromText("data.csv",listaPasajeros))
                {
                	printf("Datos cargados correctamente desde archivo de texto\n");
                }
                break;
            case 2:
				if(controller_loadFromBinary("data.bin",listaPasajeros))
				{
					printf("Datos cargados correctamente desde archivo binario\n");
				}
				break;
            case 3:
                if(controller_addPassenger(listaPasajeros, &nextId))
                {
                	printf("Pasajero agregado con exito!\n");
                }
            	break;
            case 4:
            	if(ll_len(listaPasajeros) > 0)
				{
            		if(controller_editPassenger(listaPasajeros))
					{
						printf("Pasajero modificado con exito!\n");
					}
				}
				else
				{
					printf("No puede modificar porque aun no se ingresaron pasajeros. \n\n");
				}


            	break;
            case 5:
            	if(ll_len(listaPasajeros) > 0)
				{
            		if(controller_removePassenger(listaPasajeros))
            		{
            			printf("Baja realizada con exito!\n");
            			printf("Cantidad de pasajeros: %d\n", ll_len(listaPasajeros));
            		}
				}
				else
				{
					printf("No puede dar de baja porque aun no se ingresaron pasajeros. \n\n");
				}


				break;
            case 6:
            	if(ll_len(listaPasajeros) > 0)
            	{
            		controller_listPassengers(listaPasajeros);
            		printf("Cantidad de pasajeros: %d\n", ll_len(listaPasajeros));
            	}
            	else
            	{
            		printf("Aun no se ingresaron pasajeros. \n\n");
            	}

				break;
            case 7:
            	if(ll_len(listaPasajeros) > 0)
            	{
            		controller_sortPassenger(listaPasajeros);
            		printf("Pasajeros ordenados por codigo de vuelo ascendente.\n");
            	}
            	else
            	{
            		printf("Aun no se ingresaron pasajeros. \n\n");
            	}

				break;
            case 8:
            	if(ll_len(listaPasajeros) > 0)
				{
            		if(controller_saveAsText("data.csv", listaPasajeros))
					{
						printf("Archivo de texto guardado correctamente.\n");
						flagSave += 1;
					}
				}
				else
				{
					printf("Aun no se ingresaron pasajeros. \n\n");
				}

            	break;
            case 9:
            	if(ll_len(listaPasajeros) > 0)
				{
            		if(controller_saveAsBinary("data.bin", listaPasajeros))
					{
						printf("Archivo binario guardado correctamente.\n");
						flagSave += 1;
					}
				}
				else
				{
					printf("Aun no se ingresaron pasajeros. \n\n");
				}

            	break;
            case 10:
            	if(flagSave == 0)
            	{
            		printf("No puede salir del programa sin haber guardado algun archivo.\n\n");
            	}
            	else
            	{
            		// guardamos el entero nextId en el archivo next_id.bin
            		if(controller_saveNextIdAsBinary(&nextId))
            		{
            			printf("NextId guardado correctamente!");
            		}
            		salir = 's';
            	}
            	break;
        }
        pausar();
    }while(salir != 's');


    return 0;
}

