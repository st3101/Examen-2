/*
 * arancel.h
 *
 *  Created on: 19 jun. 2021
 *      Author: santi
 */

#include "collections/LinkedList.h"
#include "collections/Dictionary.h"

#ifndef SRC_ARANCEL_H_
#define SRC_ARANCEL_H_

typedef struct
{
	char nomenclado[64];
	float seguro;
	float porcentajeDeImportacion;
	float tasaEstadistica;
	char tipoDeLicencia[64];
}Arancel;

Arancel* ara_new(void);

Arancel* ara_newParams(char* momenclador,char* seguro,char* porcentajeDeImportacion,char* tasaEstadistica,char* tipoDeLicencia);
int ara_delete(Arancel* this);


int ara_setNomeclador(Arancel* this,char* momenclador);
int ara_getNomeclador(Arancel* this,char* momenclador);

int ara_setSeguro(Arancel* this,char* seguro);
int ara_getSeguro(Arancel* this,float* seguro);

int ara_setPorcentajeDeImportacion(Arancel* this,char* porcentajeDeImportacion);
int ara_getPorcentajeDeImportacion(Arancel* this,float* porcentajeDeImportacion);

int ara_setTasaEstadistica(Arancel* this,char* tasaEstadistica);
int ara_getTasaEstadistica(Arancel* this,float* tasaEstadistica);

int ara_setTipoDeLicencia(Arancel* this,char* tipoDeLicencia);
int ara_getTipoDeLicencia(Arancel* this,char* tipoDeLicencia);


int ara_alta(Dictionary* this);
int ara_modificar(Dictionary* this);
int ara_baja(Dictionary* this);
int ara_list(Dictionary* this);

int ara_listUno(Arancel* this);

int ara_parse(char* ArchivoNombre,Dictionary* this);
int ara_dump(char* archivoNombre,Dictionary* this);

int ara_menu(Dictionary* this);


#endif /* SRC_ARANCEL_H_ */
