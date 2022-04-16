/*
 * tp1_lib.h
 *
 *  Created on: 15 abr. 2022
 *      Author: nicocasaisd
 */

#ifndef TP1_LIB_H_
#define TP1_LIB_H_

/// @fn void imprimirMenu(int, float, float)
/// @brief Imprime las opciones del menú e informa los datos ya ingresados en kilometros y precios.
///
/// @param km Kilometros ingresados
/// @param precioAA Precio ingresado para Aerolineas Argentinas
/// @param precioLatam Precio ingresado para Latam
void imprimirMenu(int km, float precioAA, float precioLatam);

/// @fn void pedirOpcion(int*, int, int)
/// @brief Pide una opcion por consola, la valida y la escribe en la variable global de opcion.
///
/// @param pOpcion Puntero a la variable donde se escribe el valor pedido.
/// @param min Valor minimo en el rango de opciones.
/// @param max Valor maximo en el rango de opciones.
void pedirOpcion(int* pOpcion, int min, int max);

/// @fn float pedirNumero(int, int)
/// @brief Pide un numero dentro de un rango, lo valida y lo devuelve.
///
/// @param min Valor minimo del rango de opciones.
/// @param max Valor maximo del rango de opciones.
/// @return Devuelve un numero de tipo float.
float pedirNumero(int min, int max);

/// @fn int ingresarKm(int*)
/// @brief Pide un valor entero por consola, lo valida y lo asigna al valor del puntero recibido.
///
/// @param pKm Puntero a la variable entera donde se escribe el valor pedido.
/// @return Devuelve 1 si la carga fue exitosa y 0 si no lo fue.
int ingresarKm(int* pKm);

/// @fn float calcularDebito(float)
/// @brief Calcula el descuento por pago con debito.
///
/// @param precio Valor float sobre el cual se aplica el descuento.
/// @return Devuelve el resultado como valor tipo float.
float calcularDebito(float precio);

/// @fn float calcularCredito(float)
/// @brief Calcula el aumento por pago con credito.
///
/// @param precio Valor float sobre el cual se aplica el aumento.
/// @return Devuelve el resultado como valor tipo float.
float calcularCredito(float precio);

/// @fn float calcularBTC(float)
/// @brief Calcula el precio pagando con Bitcoin.
///
/// @param precio Valor float que se convierte a btc.
/// @return Devuelve el resultado como valor tipo float.
float calcularBTC(float precio);

/// @fn float calcularUnitario(float, int)
/// @brief Calcula el precio unitario dividiendo el precio por la cantidad de kms.
///
/// @param precio Valor float que representa el precio.
/// @param km Valor int que representa la cantidad de kms.
/// @return Devuelve el resultado como valor tipo float.
float calcularUnitario(float precio, int km);

/// @fn float calcularDiferencia(float, float)
/// @brief Calcula la diferencia entre dos precios.
///
/// @param precio1 Valor float que representa el primer precio.
/// @param precio2 Valor float que representa el segundo precio.
/// @return Devuelve el resultado como valor tipo float.
float calcularDiferencia(float precio1, float precio2);

/// @fn void ingresarPrecioVuelos(float*, float*, int*, int*)
/// @brief Crea un submenu para ingresar los precios de los vuelos.
///		   Cuando ingresamos el precio de una aerolinea cambia la bandera para avisar que se ingreso un valor.
/// @param pAA Puntero flotante que apunta a la variable precio Aerolineas.
/// @param pLat Puntero flotante que apunta a la variable precio Latam.
/// @param pflagAA Puntero entero que apunta a la variable bandera de precio Aerolineas.
/// @param pflagLatam Puntero entero que apunta a la variable bandera de precio Latam.
void ingresarPrecioVuelos(float* pAA, float* pLat, int* pflagAA, int* pflagLatam);

/// @fn void mostrarResultados(int, float, float, float, float, float, float, float, float, float, float, float)
/// @brief Muestra los resultados de los calculos realizados para los kms y precios ingresados.
///
/// @param kilometros
/// @param precioAA
/// @param precioAADebito
/// @param precioAACredito
/// @param precioAABTC
/// @param precioAAUnitario
/// @param precioLatam
/// @param precioLatamDebito
/// @param precioLatamCredito
/// @param precioLatamBTC
/// @param precioLatamUnitario
/// @param diferenciaDePrecio
void mostrarResultados(int kilometros, float precioAA, float precioAADebito, float precioAACredito, float precioAABTC, float precioAAUnitario, float precioLatam, float precioLatamDebito, float precioLatamCredito, float precioLatamBTC, float precioLatamUnitario, float diferenciaDePrecio);

/// @fn void pausar()
/// @brief Pausa el programa hasta que presionemos enter.
///
void pausar();

/// @fn void cargaForzada(int*, float*, float*, int*, int*, int*)
/// @brief Realiza la carga de valores en kilometros, precio Aerolineas y precio Latam,
/// y cambia las banderas para informar que ya se ingresaron valores.
///
/// @param pkm Puntero entero a la variable kilometros.
/// @param pPrecioAA Puntero float a la variable precio Aerolineas.
/// @param pPrecioLatam Puntero float a la variable precio Latam.
/// @param flagKm Puntero entero a la bandera de kilometros.
/// @param flagAA Puntero entero a la bandera de precio Aerolineas.
/// @param flagLatam Puntero entero a la bandera de precio Latam.
void cargaForzada(int* pkm, float* pPrecioAA, float* pPrecioLatam, int* flagKm, int* flagAA, int* flagLatam);



#endif /* TP1_LIB_H_ */
