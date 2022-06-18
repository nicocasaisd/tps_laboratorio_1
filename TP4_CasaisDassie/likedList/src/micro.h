/*
 * micro.h
 *
 *  Created on: 18 jun. 2022
 *      Author: nicocasaisd
 */

#ifndef SRC_MICRO_H_
#define SRC_MICRO_H_

typedef struct{
    int id;
    int idEmpresa;
    int idTipo;
    int capacidad;
}eMicro;



#endif /* SRC_MICRO_H_ */

eMicro* eMicro_new();
int eMicro_compareByIdEmpresa(void* a, void* b);
