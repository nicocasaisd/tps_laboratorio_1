/*
 * utn.c
 *
 *  Created on: 27 jun. 2022
 *      Author: nicocasaisd
 */
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>
#include "utn.h"



static int myGets(char* cadena, int longitud);

// getNumero
static int esNumerica(char* cadena);
static int getInt(int* pResultado);


//getNumeroConDecimales
static int esDecimal(char* cadena);
static int getFloat(float* pResultado);

//getTexto
static int getString(char* pResultado);
static int esTexto(char* cadena);

// getTextoAlfanumerico
static int getStringAlfa(char* pResultado);
static int esTextoAlfa(char* cadena);



/**
* \brief
Lee ​ de​ ​ stdin​ ​ hasta​ ​ que​ ​ encuentra​ ​ un​ '\n' o ​ hasta​ ​ que​ ​ haya​ ​ copiado​ ​ en​ ​ cadena
*
un​ ​ máximo​ ​ de​ '​ longitud​ - 1' ​ caracteres​ .
* \​ param​ pResultado ​ Puntero​ ​ al​ ​ espacio​ ​ de​ ​ memoria​ ​ donde​ ​ se​ ​ copiara​ ​ la​ ​ cadena​ ​ obtenida
* \​ param​ ​ longitud​ Define el ​ tamaño​ ​ de​ ​ cadena
* \return ​ Retorna​ 0 (EXITO) ​ si​ ​ se​ ​ obtiene​ ​ una​ ​ cadena​ y -1 (ERROR) ​ si​ no
*
*/
static int myGets(char* cadena, int longitud)
{
    int retorno=-1;
    if(cadena != NULL && longitud > 0 && fgets(cadena, longitud, stdin) == cadena)
    {
        __fpurge(stdin);
        if(cadena[strlen(cadena)-1] == '\n')
        {
            cadena[strlen(cadena)-1] = '\0';
        }
        retorno = 0;
    }
    return retorno;
}

/**
* \brief ​ Verifica​ ​ si​ ​ la​ ​ cadena​ ​ ingresada​ ​ es​ ​ numerica
* \​param​ ​ cadena​ ​ Cadena​ ​ de​ ​ caracteres​ a ​ ser​ ​ analizada
* \return ​ Retorna​ 1 (​ verdadero​ ) ​ si​ ​ la​ ​ cadena​ ​ es​ ​ numerica​ y 0 (​ falso​ ) ​ si​ no ​ lo​ ​ es
*/
static int esNumerica(char* cadena)
{
    int i=0;
    int retorno = 1;
    if(cadena != NULL && strlen(cadena) > 0)
    {
        while(cadena[i] != '\0')
        {
            if(cadena[i] < '0' || cadena[i] > '9')
            {
                retorno = 0;
                break;
            }
            i++;
        }
    }

    return retorno;
}



/**
* \brief ​ Verifica​ ​ si​ ​ la​ ​ cadena​ ingresada​ ​ es​ ​ numerica
* \​param​ pResultado ​ Puntero​ ​ al​ espacio​ ​ de​ ​ memoria​ ​ donde​ ​ se​ ​ dejara​ el ​ resultado​ ​ de​ ​ la​ ​ funcion
* \return ​ Retorna​ 0 (EXITO) ​ si​ se​ ​ obtiene​ ​ un​ ​ numero​ ​ entero​ y -1 (ERROR) ​ si​ no
*
*/

/** \brief Obtiene una cadena del buffer, lo valida y convierte a entero
 *
 * \param pResultado int* Puntero al espacio de memoria donde se escribe
 * \return int Retorna 0 si se pudo obtener el numero entero y -1 si ocurrio un error.
 *
 */
static int getInt(int* pResultado)
{
    int ret = -1;
    char buffer[64];

    if(pResultado != NULL)
    {
        if(myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer) && strlen(buffer)>0)
        {
            *pResultado = atoi(buffer);
            ret = 0;
        }
    }

    return ret;
}



int utn_getNumero(int* pResultado,
                  char* mensaje,
                  char* mensajeError,
                  int minimo,
                  int maximo,
                  int reintentos)
{
    int retorno;
    int bufferInt;

    while(reintentos > 0)
    {
        reintentos --;
        printf("%s", mensaje);
        if(getInt(&bufferInt) == 0)
        {
            if(bufferInt <= maximo && bufferInt >= minimo)
            {
                *pResultado = bufferInt;
                retorno = 0;
                break;
            }
        }
        printf("%s", mensajeError);
    }

    return retorno;
}

// GET NUMERO DECIMAL

/** \brief
 *
 * \param cadena char*
 * \return int
 *
 */
static int esDecimal(char* cadena)
{
    int i=0;
    int retorno = 1;
    if(cadena != NULL && strlen(cadena) > 0)
    {
        while(cadena[i] != '\0')
        {
            if( (cadena[i] < '0' || cadena[i] > '9') && cadena[i]!= '.')
            {
                retorno = 0;
                break;
            }
            i++;
        }
    }

    return retorno;
}

/**
* \brief ​ Verifica​ ​ si​ ​ la​ ​ cadena​ ingresada​ ​ es​ ​ decimal
* \​param​ pResultado ​ Puntero​ ​ al​ espacio​ ​ de​ ​ memoria​ ​ donde​ ​ se​ ​ dejara​ el ​ resultado​ ​ de​ ​ la​ ​ funcion
* \return ​ Retorna​ 0 (EXITO) ​ si​ se​ ​ obtiene​ ​ un​ ​ numero​ ​ entero​ y -1 (ERROR) ​ si​ no
*
*/
static int getFloat(float* pResultado)
{
    int ret = -1;
    char buffer[64];

    if(pResultado != NULL)
    {
        if(myGets(buffer, sizeof(buffer)) == 0 && esDecimal(buffer))
        {
            *pResultado = atof(buffer);
            ret = 0;
        }
    }

    return ret;
}

int utn_getNumeroDecimal(float* pResultado,
                  char* mensaje,
                  char* mensajeError,
                  int minimo,
                  int maximo,
                  int reintentos)
{
    int retorno;
    float bufferFloat;

    while(reintentos > 0)
    {
        reintentos --;
        printf("%s", mensaje);
        if(getFloat(&bufferFloat) == 0)
        {
            if(bufferFloat <= maximo && bufferFloat >= minimo)
            {
                *pResultado = bufferFloat;
                retorno = 0;
                break;
            }
        }
        printf("%s", mensajeError);
    }

    return retorno;
}

// GET TEXTO

static int esTexto(char* cadena)
{
    int i=0;
    int retorno = 1;
    if(cadena != NULL && strlen(cadena) > 0)
    {
        while(cadena[i] != '\0')
        {
            if( ! ((cadena[i] >= 'A' && cadena[i] <= 'Z') || (cadena[i] >= 'a' && cadena[i] <= 'z')))
            {
                retorno = 0;
                break;
            }
            i++;
        }
    }

    return retorno;
}

static int getString(char* pResultado)
{
    int ret = -1;
    char buffer[64];

    if(pResultado != NULL)
    {
        if(myGets(buffer, sizeof(buffer)) == 0 && esTexto(buffer))
        {
            strcpy(pResultado, buffer);
            ret = 0;
        }
    }

    return ret;
}

int utn_getTexto(char* pResultado,
                  char* mensaje,
                  char* mensajeError,
                  int largo,
                  int reintentos)
{
    int retorno;
    char bufferStr[64];

    while(reintentos > 0)
    {
        reintentos --;
        printf("%s", mensaje);
        if(getString(bufferStr) == 0)
        {
            if(strlen(bufferStr) <= largo && strlen(bufferStr) > 0)
            {
                strcpy(pResultado, bufferStr);
                retorno = 0;
                break;
            }
        }
        printf("%s", mensajeError);
    }

    return retorno;
}


// GET TEXTO ALFANUMERICO


static int esTextoAlfa(char* cadena)
{
    int i=0;
    int retorno = 1;
    if(cadena != NULL && strlen(cadena) > 0)
    {
        while(cadena[i] != '\0')
        {
            if( ! ((cadena[i] >= 'A' && cadena[i] <= 'Z')
                   || (cadena[i] >= 'a' && cadena[i] <= 'z')
                   || (cadena[i] >= '0' && cadena[i] <= '9')
                   ))
            {
                retorno = 0;
                break;
            }
            i++;
        }
    }

    return retorno;
}

static int getStringAlfa(char* pResultado)
{
    int ret = -1;
    char buffer[64];

    if(pResultado != NULL)
    {
        if(myGets(buffer, sizeof(buffer)) == 0 && esTextoAlfa(buffer))
        {
            strcpy(pResultado, buffer);
            ret = 0;
        }
    }

    return ret;
}


int utn_getTextoAlfanumerico(char* pResultado,
                  char* mensaje,
                  char* mensajeError,
                  int largo,
                  int reintentos)
{
    int retorno;
    char bufferStr[64];

    while(reintentos > 0)
    {
        reintentos --;
        printf("%s", mensaje);
        if(getStringAlfa(bufferStr) == 0)
        {
            if(strlen(bufferStr) <= largo && strlen(bufferStr) > 0)
            {
                strcpy(pResultado, bufferStr);
                retorno = 0;
                break;
            }
        }
        printf("%s", mensajeError);
    }

    return retorno;
}
