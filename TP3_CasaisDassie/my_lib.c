/*
 * my_lib.c
 *
 *  Created on: 10 jun. 2022
 *      Author: nicocasaisd
 */


#include "my_lib.h"
#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/// @fn int utn_gets(char[], int)
/// @brief Funcion similar a gets() que no se puede usar en Linux.
/// 		Recibe un vector de caracteres y un tamaño y no permite escribir
/// 		más alla de ese tamaño.
///
/// @param vec Vector de caracteres en el que se escribe
/// @param tam Tamaño máximo de la cadena
/// @return
int utn_gets(char vec[], int tam)
{
    int retorno = 0;
    char aux[100];
    // validaciones
    if(vec != NULL && tam > 0){
        __fpurge(stdin);
        fgets(aux, 100, stdin);
        // limpiamos el '\n' de fgets
        for(int i=0; i<100; i++){
            if(aux[i]=='\n'){
                aux[i] = '\0';
                break;
            }
        }
        while(strlen(aux) >= tam){
            printf("La cadena ingresada es demasiado larga. Reingrese: ");
            __fpurge(stdin);
            fgets(aux, 100, stdin);
            // limpiamos el '\n' de fgets
            for(int i=0; i<100; i++){
                if(aux[i]=='\n'){
                    aux[i] = '\0';
                    break;
            }
        }
        }
        strcpy(vec, aux);
        retorno = 1;
    }
    return retorno;
}
/// @fn void pausar()
/// @brief Pausa la consola hasta que se presione la tecla enter.
///
void pausar()
{
    char auxPausa;
    __fpurge(stdin);
    printf("\n\nPresione una tecla para continuar...");
    scanf("%c", &auxPausa);
}


