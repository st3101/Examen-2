/*
 * aere.h
 *
 *  Created on: 20 jun. 2021
 *      Author: santi
 */

#ifndef SRC_COLLECTIONS_AEREO_H_
#define SRC_COLLECTIONS_AEREO_H_

typedef struct
{
	float constanteVolumetrica;
	float valorPorKilo;

}Aereo;

int aer_setconstanteVolumetrica(Aereo* this,char* constanteVolumetrica);
int aer_getconstanteVolumetrica(Aereo* this,float* constanteVolumetrica);

int aer_setvalorPorKilo(Aereo* this,char* valorPorKilo);
int aer_getvalorPorKilor(Aereo* this,float* valorPorKilo);

int aer_modificar(Aereo* this);
int aer_list(Aereo* this);

int aer_parse(char* archivoNombre,Aereo* this);
int aer_mar_dump(char* archivoNombre,Aereo* this);

#endif /* SRC_COLLECTIONS_AEREO_H_ */
