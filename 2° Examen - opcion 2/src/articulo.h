/*
 * articulo.h
 *
 *  Created on: 15 jun. 2021
 *      Author: santi
 */

#include "collections/Dictionary.h"

#ifndef ARTICULO_H_
#define ARTICULO_H_

typedef struct
{
	int id;
	char codigo[64];
	char descripcion[64];
	char paisDeFabricacion[64];
	float valorFob;
	float pesoEnKilo;
	float anchoCm;
	float altoCm;
	float profundidadCm;
	char posicionArancelaria[64];
}Articulo;

Articulo* art_new(void);
Articulo* art_newParams(char* id,char* codigo,char* descripcion,char* paisDeFabricacion,char* valorFob,char* pesoEnKilo,char* anchoCm,char* altoCm,char* profundidadCm,char* posicionArancelaria);

int art_delete(Articulo* this);

int art_setId(Articulo* this,char* id);
int art_getId(Articulo* this,int* id);

int art_setDescripcion(Articulo* this,char* descripcion);
int art_getDescripcion(Articulo* this,char* descripcion);

int art_setCodigo(Articulo* this,char* codigo);
int art_getCodigo(Articulo* this,char* codigo);

int art_setPaisDeFabricacion(Articulo* this,char* paisDeFabricacion);
int art_getPaisDeFabricacion(Articulo* this,char* paisDeFabricacion);

int art_setValorFob(Articulo* this,char* valorFob);
int art_getValorFob(Articulo* this,float* valorFob);

int art_setPesoEnKilos(Articulo* this,char* pesoEnKilo);
int art_getPesoEnKilos(Articulo* this,float* pesoEnKilo);

int art_setAnchoCm(Articulo* this,char* anchoCm);
int art_getAnchoCm(Articulo* this,float* anchoCm);

int art_setAltoCm(Articulo* this,char* altoCm);
int art_getAltoCm(Articulo* this,float* altoCm);

int art_setProfundidaCm(Articulo* this,char* profundidadCm);
int art_getProfundidaCm(Articulo* this,float* profundidadCm);

int art_setPosicionArancelaria(Articulo* this,char* posicionArancelaria);
int art_getPosicionAranceleria(Articulo* this,char* posicionArancelaria);


int art_alta(Dictionary* thisArt,Dictionary* thisAra);
int art_modificar(Dictionary* this);
int art_baja(Dictionary* this);
int art_list(Dictionary* this);

int art_ListUno(Articulo* this);

int art_parse(char* ArchivoNombre,Dictionary* this);
int art_dump(char* path,Dictionary* this);

int art_menu(Dictionary* this,Dictionary* thisAra);




#endif /* ARTICULO_H_ */
