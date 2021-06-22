/*
 * maritimo.h
 *
 *  Created on: 20 jun. 2021
 *      Author: santi
 */

#ifndef SRC_MARITIMO_H_
#define SRC_MARITIMO_H_

typedef struct
{
	float Mcubicos;
	float ValorDelcontenedor;
}Maritimo;

int mar_setMcubicos(Maritimo* this,char* Mcubicos);
int mar_getMcubicos(Maritimo* this,float* Mcubicos);

int mar_setValorDelcontenedor(Maritimo* this,char* ValorDelcontenedor);
int mar_getValorDelcontenedor(Maritimo* this,float* ValorDelcontenedor);

int mar_modificar(Maritimo* this);
int mar_list(Maritimo* this);

int mar_parse(char* archivoNombre,Maritimo* this);
int mar_dump(char* archivoNombre,Maritimo* this);





#endif /* SRC_MARITIMO_H_ */
