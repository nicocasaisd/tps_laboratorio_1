#ifndef TP2_LIB_H_INCLUDED
#define TP2_LIB_H_INCLUDED

// MENUS
int menu();
int menuModificar();
int menuInformes();

// ABM
int checkEntry(Passenger list[], int len);
void pedirOpcion(int* pOpcion, int min, int max);
int pedirDatos(Passenger* aux_ps);
int hardcodearEmpleados(Passenger list[], int len, int cant, int* nextId, int* flag);
int pedirBaja(Passenger list[], int len, int* flag);
int pedirModificacion(Passenger list[], int len);
int checkValidId(Passenger list[], int len, int id);

// INFORMES
int pedirInformes(Passenger list[], int len);
int calcularPromedio(Passenger list[], int len, float* total, float* promedio, int* cantSupera);
int printPromedio(Passenger list[], int len, float total, float promedio, int cantSupera);
int printActivePassengers(Passenger list[], int len);

// VALIDACIONES
int validarCadena(char str[], int largo);
int validarPrecio(float precio);
int validarIntRango(int opcion, int minimo, int maximo);

#endif // TP2_LIB_H_INCLUDED
