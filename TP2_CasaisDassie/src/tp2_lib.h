#ifndef TP2_LIB_H_INCLUDED
#define TP2_LIB_H_INCLUDED

// MENUS
/// @fn int menu()
/// @brief Imprime el menu principal y devuelve la opcion seleccionada por el usuario.
///
/// @return	Devuelve un entero con la opcion elegida
int menu();

/// @fn int menuModificar()
/// @brief Imprime el sub-menu para modificacion y devuelve la opcion seleccionada por el usuario.
///
/// @return	Devuelve un entero con la opcion elegida
int menuModificar();

/// @fn int menuInformes()
/// @brief Imprime el sub-menu para informes y devuelve la opcion seleccionada por el usuario.
///
/// @return
int menuInformes();

// ABM
/// @fn int checkEntry(Passenger[], int)
/// @brief Recorre el array y devuelve el indice del primer lugar vacío.
///
/// @param list Array de tipo Passenger
/// @param len	Tamaño del array
/// @return Devuelve un entero con el indice del primer lugar vacío.
int checkEntry(Passenger list[], int len);

/// @fn int pedirDatos(Passenger*)
/// @brief Pide al usuario los datos para el alta de un nuevo pasajero
///
/// @param aux_ps Estructura de tipo Passenger
/// @return Devuelve -1 si ocurrió un error y 0 si la función pudo ejecutarse correctamente.
int pedirDatos(Passenger* aux_ps);

/// @fn int hardcodearPasajeros(Passenger[], int, int, int*, int*)
/// @brief Realiza una carga forzada de pasajeros en el array tipo Passenger
///
/// @param list Array de tipo Passenger
/// @param len Tamaño del array list
/// @param cant Cantidad de pasajeros que querramos cargar (max 10)
/// @param nextId Puntero a entero de la variable nextId
/// @param flag Puntero a entero de la variable flag
/// @return Devuelve -1 si ocurrió un error y 0 si la función pudo ejecutarse correctamente.
int hardcodearPasajeros(Passenger list[], int len, int cant, int* nextId, int* flag);

/// @fn int pedirBaja(Passenger[], int, int*)
/// @brief Llama al sub-menu de baja y pide al usuario las opciones para realizar la baja
///
/// @param list Array de tipo Passenger
/// @param len Tamaño del array list
/// @param flag Puntero a entero de la variable flag
/// @return Devuelve -1 si ocurrió un error y 0 si la función pudo ejecutarse correctamente.
int pedirBaja(Passenger list[], int len, int* flag);

/// @fn int pedirModificacion(Passenger[], int)
/// @brief LLama al sub-menu de modificacion y pide al usuario las opciones a modificar.
///
/// @param list Array de tipo Passenger
/// @param len Tamaño del array list
/// @return Devuelve -1 si ocurrió un error y 0 si la función pudo ejecutarse correctamente.
int pedirModificacion(Passenger list[], int len);

/// @fn int checkValidId(Passenger[], int, int)
/// @brief Chequea que la id ingresada corresponda a un pasajero existente y dado de alta.
///
/// @param list Array de tipo Passenger
/// @param len Tamaño del array list
/// @param id Id que queremos validar.
/// @return Devuelve 1 si la Id es valida y 0 si la Id es invalida.
int checkValidId(Passenger list[], int len, int id);

// INFORMES
/// @fn int pedirInformes(Passenger[], int)
/// @brief LLama al sub-menu de informes y imprime los informes solicitados
///
/// @param list Array de tipo Passenger
/// @param len Tamaño del array list
/// @return Devuelve -1 si ocurrió un error y 0 si la función pudo ejecutarse correctamente.
int pedirInformes(Passenger list[], int len);

/// @fn int calcularPromedio(Passenger[], int, float*, float*, int*)
/// @brief Calcula los valores de total  y promedio de los precios de pasajeros, y la cantidad
/// 		de pasajeros que se encuentran por encima del promedio.
///
/// @param list Array de tipo Passenger
/// @param len Tamaño del array list
/// @param total Puntero a flotante donde se escribe el total
/// @param promedio Puntero a flotante donde se escribe el promedio
/// @param cantSupera Puntero a entero donde se escribe la cantidad que supera el promedio
/// @return Devuelve -1 si ocurrió un error y 0 si la función pudo ejecutarse correctamente.
int calcularPromedio(Passenger list[], int len, float* total, float* promedio, int* cantSupera);

/// @fn int printActivePassengers(Passenger[], int)
/// @brief Imprime un listado de pasajeros con estado de vuelo Activo
///
/// @param list Array de tipo Passenger
/// @param len Tamaño del array list
/// @return Devuelve -1 si ocurrió un error y 0 si la función pudo ejecutarse correctamente.
int printActivePassengers(Passenger list[], int len);

// VALIDACIONES
/// @fn int validarCadena(char[], int)
/// @brief Chequea que la cadena ingresada no exceda el largo máximo.
///
/// @param str Puntero a cadena
/// @param largo Numero entero maximo de caracteres permitidos
/// @return Devuelve 1 si la cadena es valida, 0 si la cadena es invalida
int validarCadena(char str[], int largo);

/// @fn int validarPrecio(float)
/// @brief Chequea que el valor flotante ingresado se encuentre dentro del rango definido
///
/// @param precio Valor flotante que se quiere validar
/// @return Devuelve 1 si el flotante es valido, 0 si es invalido
int validarPrecio(float precio);

/// @fn int validarIntRango(int, int, int)
/// @brief Chequea que el valor entero ingresado se encuentre dentro del rango definido
///
/// @param opcion Valor entero que se quiere validar
/// @param minimo Entero minimo
/// @param maximo Entero maximo
/// @return Devuelve 1 si el entero es valido, 0 si es invalido
int validarIntRango(int opcion, int minimo, int maximo);

#endif // TP2_LIB_H_INCLUDED
