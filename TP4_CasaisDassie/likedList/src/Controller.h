/*
 * Controller.h
 *
 *  Created on: 18 jun. 2022
 *      Author: nicocasaisd
 */

#ifndef SRC_CONTROLLER_H_
#define SRC_CONTROLLER_H_

int controller_loadFromText(char* path , LinkedList* LinkedList);
int parser_eMicroFromText(FILE* pFile , LinkedList* LinkedList);
int controller_saveAsText(char* path , LinkedList* LinkedList);

void controller_imprimirSeparador(char* string);

#endif /* SRC_CONTROLLER_H_ */
