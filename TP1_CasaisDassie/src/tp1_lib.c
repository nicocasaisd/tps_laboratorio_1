/*
 * tp1_lib.c
 *
 *  Created on: 15 abr. 2022
 *      Author: nicocasaisd
 */

#include <stdio.h>
#include <stdlib.h>
#include "tp1_lib.h"


void imprimirMenu(int km, float precioAA, float precioLatam)
{
    printf("1. Ingresar kilometros: %d km\n", km);
    printf("2. Ingresar precio de vuelos\n");
    printf("    *Precio vuelo Aerolineas: $%.2f\n", precioAA);
    printf("    *Precio vuelo Latam: $%.2f\n", precioLatam);
    printf("3. Calcular todos los costos\n");
    printf("4. Informar resultados\n");
    printf("5. Carga forzada de datos\n");
    printf("6. Salir\n");
}
void pedirOpcion(int* pOpcion, int min, int max)
{
    int auxOpc=0;

    printf("Ingrese opcion: ");
    scanf("%d", &auxOpc);

    while(auxOpc<min || auxOpc>max)
    {
        printf("Opcion invalida. Reingrese: ");
        __fpurge(stdin); // en windows fflush(stdin);
        scanf("%d", &auxOpc);
    }

    *pOpcion = auxOpc;
}

int ingresarKm(int* pKm)
{
    int exit_status=0;
    int auxKm;
    printf("Ingrese la cantidad de kilometros (sin decimales): \n");
    auxKm = pedirNumero(0, 100000);
    *pKm = auxKm;

    exit_status=1;
    return exit_status;
}

void ingresarPrecioVuelos(float* pAA, float* pLat, int* pflagAA, int* pflagLatam)
{
    int opcion=0;
    float auxAA;
    float auxLat;

    printf("Ingresar precio de vuelos\n");
    printf("1. Precio de vuelo Aerolineas Argentinas.\n");
    printf("2. Precio de vuelo Latam.\n");
    printf("3. Volver.\n");
    pedirOpcion(&opcion, 1, 3);
    switch(opcion)
    {
    case 1:
        system("clear");
        printf("Ingrese precio de vuelo para Aerolineas Argentinas: \n");
        auxAA = pedirNumero(0, 10000000);
        *pAA = auxAA;
        *pflagAA = 1;
        break;
    case 2:
        system("clear");
        printf("Ingrese precio de vuelo para Latam: \n");
        auxLat = pedirNumero(0, 10000000);
        *pLat = auxLat;
        *pflagLatam = 1;
    default:
        break;
    }
}

int pedirNumero(int min, int max)
{
    int numero;

    printf("Ingrese un valor entre %d y %d: ", min, max);
    while(scanf("%d", &numero)==0)
    {
        printf("ERROR. Solo valores numericos. Reingrese: ");
        scanf("%d", &numero);
        __fpurge(stdin); // en windows fflush(stdin);
    }
    while(numero<min || numero>max)
    {
        printf("Numero fuera de rango. Reingrese: ");
        __fpurge(stdin); // en windows fflush(stdin);
        scanf("%d", &numero);
    }

    return numero;
}
void pausar()
{
    char auxPausa;
    __fpurge(stdin);
    printf("\n\nPresione una tecla para continuar...");
    scanf("%c", &auxPausa);
}

void cargaForzada(int* pkm, float* pPrecioAA, float* pPrecioLatam, int* flagKm, int* flagAA, int* flagLatam)
{
    *pkm = 7090;
    *pPrecioAA = 162965;
    *pPrecioLatam = 159339;

    *flagKm = 1;
    *flagAA = 1;
    *flagLatam = 1;
}

void mostrarResultados(int kilometros, float precioAA, float precioAADebito, float precioAACredito, float precioAABTC, float precioAAUnitario, float precioLatam, float precioLatamDebito, float precioLatamCredito, float precioLatamBTC, float precioLatamUnitario, float diferenciaDePrecio)
{
    printf("Kilometros ingresados: %d\n\n", kilometros);
    printf("Precio Aerolineas: $%.2f\n", precioAA);
    printf("a) Precio con tarjeta de debito: $%.2f\n", precioAADebito);
    printf("b) Precio con tarjeta de credito: $%.2f\n", precioAACredito);
    printf("c) Precio con bitcoin: $%.6f\n", precioAABTC);
    printf("d) Mostrar precio unitario: $%.2f\n\n", precioAAUnitario);

    printf("Precio Latam: $%.2f\n", precioLatam);
    printf("a) Precio con tarjeta de debito: $%.2f\n", precioLatamDebito);
    printf("b) Precio con tarjeta de credito: $%.2f\n", precioLatamCredito);
    printf("c) Precio con bitcoin: $%.6f\n", precioLatamBTC);
    printf("d) Mostrar precio unitario: $%.2f\n\n", precioLatamUnitario);

    printf("e) La diferencia de precio es: %.2f\n", diferenciaDePrecio);

    pausar();

}

float calcularDebito(float precio)
{
    float resultado;
    resultado = precio * 0.9;

    return resultado;
}

float calcularCredito(float precio)
{
    float resultado;
    resultado = precio * 1.25;

    return resultado;
}

float calcularBTC(float precio)
{
    float precioBTC = 4606954.55;
    float resultado;
    resultado = precio / precioBTC;

    return resultado;
}

float calcularUnitario(float precio, int km)
{
    float resultado;
    resultado = (float)precio / km;

    return resultado;
}

float calcularDiferencia(float precio1, float precio2)
{
    float resultado;
    resultado = (precio1 - precio2);

    return resultado;
}
