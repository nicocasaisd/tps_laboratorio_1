/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "Controller.h"
#include "micro.h"


int main(void)
{

	// usar todas las funciones del LL
	// cargo 10 empleados, remuevo 1, sobreescribo 1

	// sin menu

	//LinkedList* lista = ll_newLinkedList();
/*
	startTesting(1);  // ll_newLinkedList
	startTesting(2);  // ll_len
	startTesting(3);  // getNode - test_getNode
	startTesting(4);  // addNode - test_addNode
	startTesting(5);  // ll_add
	startTesting(6);  // ll_get
	startTesting(7);  // ll_set
	startTesting(8);  // ll_remove
	startTesting(9);  // ll_clear
	startTesting(10); // ll_deleteLinkedList
	startTesting(11); // ll_indexOf
	startTesting(12); // ll_isEmpty
	startTesting(13); // ll_push
	startTesting(14); // ll_pop
	startTesting(15); // ll_contains
	startTesting(16); // ll_containsAll
	startTesting(17); // ll_subList
	startTesting(18); // ll_clone
	startTesting(19); // ll_sort
*/
	controller_imprimirSeparador("TP 4. Casais Dassie, Nicolas");

	eMicro* nuevoMicro;
	eMicro* auxMicro;
	eMicro* auxMicro2 = eMicro_new();
	eMicro* auxPop = eMicro_new();
	int indexOf;
	int isEmpty;
	LinkedList* listaClonada;
	LinkedList* listaSublist;

	controller_imprimirSeparador("1. Creacion LinkedList");
	// creo la lista LinkedList
	LinkedList* lista;
	lista = ll_newLinkedList();
	if(lista!= NULL)
	{
		printf("Se creo la lista LinkedList correctamente. \n");
	}

	controller_imprimirSeparador("2. Cargo elementos desde archivo");
	// cargo desde archivo csv
	controller_loadFromText("DATA.csv", lista);

	// me fijo si cargo bien (500 entradas)
	printf("micros cargados: %d\n", ll_len(lista));

	controller_imprimirSeparador("3. Agrego empleado hardcodeado");
	// agrego un micro hardcodeado
	nuevoMicro = eMicro_new();
	nuevoMicro->id = 100;
	nuevoMicro->idEmpresa = 1003;
	nuevoMicro->idTipo = 5003;
	nuevoMicro->capacidad = 50;

	ll_add(lista, nuevoMicro);

	// me fijo si cargo bien (501 entradas)
	printf("micros cargados: %d\n", ll_len(lista));

	controller_imprimirSeparador("4. Obtengo un elemento y lo muestro");
	// cargo el primer elemento
	auxMicro = ll_get(lista, 0);
	printf("id: %d, idEmpresa: %d, idTipo: %d, capacidad: %d\n",
			auxMicro->id, auxMicro->idEmpresa, auxMicro->idTipo, auxMicro->capacidad);

	controller_imprimirSeparador("5. Sobreescribo usando ll_set()");
	// asigno este elemento al indice 1
	auxMicro2 = ll_get(lista,1);
	printf("id antes del set: %d\n", auxMicro2->id);
	ll_set(lista, 1, auxMicro);
	// compruebo que lo haya sobreescrito
	auxMicro2 = ll_get(lista,1);
	printf("id luego del set: %d\n", auxMicro2->id);

	controller_imprimirSeparador("6. Elimino elementos de la LinkedList");
	// elimino los primeros 10 elementos
	for(int i=0; i<10; i++)
	{
		if(ll_remove(lista, i) == 0)
		{
			printf("Se elimino el elemento %d correctamente. \n", i);
		}

	}

	controller_imprimirSeparador("7. Obtengo el indice de un elemento con ll_indexOf()");
	// obtengo el indice del nuevoMicro que agregamos
	indexOf = ll_indexOf(lista, nuevoMicro);
	printf("indice de nuevoMicro: %d\n", indexOf);

	controller_imprimirSeparador("8. Reviso si la lista esta vacia");
	// revisamos si la lista esta vacia (NO)
	isEmpty = ll_isEmpty(lista);
	if(isEmpty == 0)
	{
		printf("La lista NO esta vacia\n");
	}
	else if(isEmpty == 1)
	{
		printf("La lista esta vacia\n");
	}
	else
	{
		printf("Ocurrio un error al intenter ll_isEmpty()\n");
	}

	controller_imprimirSeparador("9. Agrego elemento con ll_push()");
	// hago un push del elemento nuevoMicro en el indice 0
	ll_push(lista, 0, nuevoMicro);
	// obtengo el indice del nuevoMicro que agregamos, que ahora deberia devolver 0
	indexOf = ll_indexOf(lista, nuevoMicro);
	printf("indice de nuevoMicro: %d\n", indexOf);

	// me fijo si cargo bien (492 entradas)
	printf("micros cargados: %d\n", ll_len(lista));

	controller_imprimirSeparador("10. Elimino un elemento con ll_pop() y lo muestro");
	// hago un pop de un elemento, lo muestro y muestro la cantidad de micros
	auxPop = ll_pop(lista, 0);
	printf("id: %d, idEmpresa: %d, idTipo: %d, capacidad: %d\n",
				auxPop->id, auxPop->idEmpresa, auxPop->idTipo, auxPop->capacidad);
	printf("micros cargados: %d\n", ll_len(lista));

	controller_imprimirSeparador("11. Pregunto si la lista contiene un elemento");
	// pregunto si la lista contiene el elemento nuevoMicro
	if(ll_contains(lista, nuevoMicro))
	{
		printf("La lista contiene el elemento nuevoMicro\n");
	}
	else
	{
		printf("La lista NO contiene el elemento nuevoMicro\n");
	}

	controller_imprimirSeparador("12. Clono la lista");
	// clono la lista actual
	listaClonada = ll_clone(lista);
	controller_imprimirSeparador("13. Creo una Sublist de la anterior");
	// y clono una sub lista entre indices 0 y 20 (inclusive)
	listaSublist = ll_subList(listaClonada, 0, 21);
	controller_imprimirSeparador("14. Pregunto si una contiene a la otra con ll_containsAll()");
	// pregunto si la listaSublist esta contenida por listaClonada
	if(ll_containsAll(listaClonada, listaSublist))
	{
		printf("La lista 'listaClonada' contiene todos los elementos de 'listaSublist'\n");
	}
	else
	{
		printf("La lista 'listaClonada' NO contiene todos los elementos de 'listaSublist'\n");
	}

	controller_imprimirSeparador("15. Hago un clear de la lista clonada");
	// hago un clear de 'listaClonada'
	ll_clear(listaClonada);
	isEmpty = ll_isEmpty(listaClonada);
	if(isEmpty == 0)
	{
		printf("La lista NO esta vacia\n");
	}
	else if(isEmpty == 1)
	{
		printf("La lista esta vacia\n");
	}
	else
	{
		printf("Ocurrio un error al intenter ll_isEmpty()\n");
	}

	controller_imprimirSeparador("16. Elimino la LinkedList");
	// elimino la 'listaClonada'
	ll_deleteLinkedList(listaClonada);

	controller_imprimirSeparador("17. Ordeno la lista 'ListaSublist'");
	// sort Passengers
	if(listaSublist != NULL)
	{
		if(ll_sort(listaSublist, eMicro_compareByIdEmpresa, 1) == 0)
		{
			printf("Se ordeno la lista correctamente\n");
		}
	}
	controller_imprimirSeparador("18. Guardo la sublista ordenada en un nuevo archivo 'DATA_subList.csv'");
	// escribo la 'listaSublist' en un nuevo archivo csv
	controller_saveAsText("DATA_subList.csv", listaSublist);


	controller_imprimirSeparador("FIN");
	//
    return 0;
}

































