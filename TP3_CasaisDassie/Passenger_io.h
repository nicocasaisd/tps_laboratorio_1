/*
 * tp3_lib.h
 *
 *  Created on: 10 jun. 2022
 *      Author: nicocasaisd
 */

#ifndef TP3_LIB_H_
#define TP3_LIB_H_


// ABM
int addPassengerLinkedList(LinkedList* pArrayListPassenger, Passenger* newPassenger, int* nextId);
int getPassengerIndexById(LinkedList* pArrayListPassenger, int id);
int pedirModificacion(LinkedList* pArrayListPassenger, int index);

// PEDIR DATOS AL USUARIO
int pedirDatos(Passenger* aux_ps);
int pedirIndexBaja(LinkedList* pArrayListPassenger);
int pedirIndexModificacion(LinkedList* pArrayListPassenger);

// INFORMES
int printPassenger(Passenger* auxPass);

// VALIDACIONES
int checkValidId(LinkedList* pArrayListPassenger, int id);
int validarCadena(char str[], int largo);
int validarPrecio(float precio);
int validarIntRango(int opcion, int minimo, int maximo);
int validarCadenaStatusFlight(char str[], int largo);



#endif /* TP3_LIB_H_ */
