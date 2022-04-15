/*
 ============================================================================
 Name        : TP1_Nico.c
 Author      : Nicolas
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "tp1_lib.h"

int main()
{
	setbuf(stdout, NULL);

    int opcion=0;
    int kilometros=0;
    float precioAA=0;
    float precioLatam=0;

    int flagKm=0;
    int flagAA=0;
    int flagLatam=0;
    int flagCalculos=0;

    float precioAADebito;
    float precioAACredito;
    float precioAABTC;
    float precioAAUnitario;
    float precioLatamDebito;
    float precioLatamCredito;
    float precioLatamBTC;
    float precioLatamUnitario;
    float diferenciaDePrecio;


    while(opcion!=6)
    {

        system("clear");

        imprimirMenu(kilometros, precioAA, precioLatam);
        pedirOpcion(&opcion, 1, 6);

        switch(opcion)
        {
        case 1:
            system("clear"); // en windows system("cls");
            flagKm = ingresarKm(&kilometros);
            break;
        case 2:
            system("clear"); // en windows system("cls");
            ingresarPrecioVuelos(&precioAA, &precioLatam, &flagAA, &flagLatam);
            break;
        case 3:
            system("clear");
            if(flagKm == 1 && flagAA == 1 && flagLatam==1)
            {
                precioAADebito = calcularDebito(precioAA);
                precioAACredito = calcularCredito(precioAA);
                precioAABTC = calcularBTC(precioAA);
                precioAAUnitario = calcularUnitario(precioAA, kilometros);

                precioLatamDebito = calcularDebito(precioLatam);
                precioLatamCredito = calcularCredito(precioLatam);
                precioLatamBTC = calcularBTC(precioLatam);
                precioLatamUnitario = calcularUnitario(precioLatam, kilometros);

                diferenciaDePrecio = calcularDiferencia(precioAA, precioLatam);

                printf("Se realizaron los calculos.");
                flagCalculos = 1;

                pausar();
            }
            else
            {
                system("clear");
                printf("ERROR. Para realizar los calculos se deben ingresar valores para kilometros, precio Aerolineas y precio Latam.");
                pausar();
            }
            break;
        case 4:
            system("clear");
            if(flagCalculos == 1){
            mostrarResultados(kilometros, precioAA, precioAADebito, precioAACredito, precioAABTC, precioAAUnitario, precioLatam, precioLatamDebito, precioLatamCredito, precioLatamBTC, precioLatamUnitario, diferenciaDePrecio);
            }
            else{
                system("clear");
                printf("ERROR. Para mostrar los resultados primero deben realizarse los calculos.");
                pausar();
            }
            break;
        case 5:
            system("clear");
            cargaForzada(&kilometros, &precioAA, &precioLatam, &flagKm, &flagAA, &flagLatam);
            break;
        }

    }
    return 0;
}
