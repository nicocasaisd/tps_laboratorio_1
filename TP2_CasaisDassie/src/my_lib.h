#ifndef MY_LIB_H_INCLUDED
#define MY_LIB_H_INCLUDED

#include <stdlib.h>
#include <string.h>

/// @fn char strlwr*(char*)
/// @brief Version propia de la funcion strlwr que se encuentra deprecada en Linux
///
/// @param s
/// @return
char* strlwr(char* s);

/// @fn char strupr*(char*)
/// @brief Version propia de la funcion strupr que se encuentra deprecada en Linux
///
/// @param s
/// @return
char* strupr(char* s);

/// @fn int utn_gets(char[], int)
/// @brief Funcion similar a gets() que no se puede usar en Linux.
/// 		Recibe un vector de caracteres y un tamaño y no permite escribir
/// 		más alla de ese tamaño.
///
/// @param vec Vector de caracteres en el que se escribe
/// @param tam Tamaño máximo de la cadena
/// @return
int utn_gets(char vec[], int tam);

/// @fn void pausar()
/// @brief Pausa la consola hasta que se presione la tecla enter.
///
void pausar();

#endif // MY_LIB_H_INCLUDED
