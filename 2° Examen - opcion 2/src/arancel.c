/*
 * arancel.c
 *
 *  Created on: 19 jun. 2021
 *      Author: santi
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "collections/LinkedList.h"
#include "collections/Dictionary.h"
#include "arancel.h"
#include "utn.h"

#define ARA_ARCHIVO "aranceles.cvs"
#define MENU_ARANCEL "MENU ARANCEL\n1)Alta\n2)Modificacion\n3)Baja\n4)Listar\n5)Volver\nOPCION:"

Arancel* ara_new(void)
{
	return (Arancel*) malloc(sizeof(Arancel));
}

int ara_delete(Arancel* this)
{
	int retorno = 1;
	if(this != NULL)
	{
		free(this);
		retorno = 0;
	}
	return retorno;
}
Arancel* ara_newParams(char* nomenclador,char* seguro,char* porcentajeDeImportacion,char* tasaEstadistica,char* tipoDeLicencia)
{
	Arancel* pArancel = ara_new();

	if(pArancel != NULL && nomenclador != NULL && seguro != NULL && porcentajeDeImportacion != NULL && tasaEstadistica != NULL && tipoDeLicencia != NULL)
	{
		if(ara_setNomeclador(pArancel, nomenclador) || ara_setSeguro(pArancel, seguro ) || ara_setPorcentajeDeImportacion(pArancel, porcentajeDeImportacion) || ara_setTasaEstadistica(pArancel, tasaEstadistica) || ara_setTipoDeLicencia(pArancel, tipoDeLicencia))
		{
			ara_delete(pArancel);
			pArancel=NULL;
		}
	}
	return pArancel;
}


int ara_setNomeclador(Arancel* this,char* momenclador)
{
	int retorno=1;

	if(this != NULL && momenclador != NULL)
	{
		strcpy(this->nomenclado,momenclador);
		retorno = 0;

	}
	return retorno;
}
int ara_getNomeclador(Arancel* this,char* momenclador)
{
	int retono = 1;

	if(this != NULL)
	{
		strcpy(momenclador,this->nomenclado);
		retono = 0;
	}
	return retono;
}

int ara_setSeguro(Arancel* this,char* seguro)
{
	int retorno=1;
	if(this != NULL && !utn_validarFloat(seguro))
	{
		this->seguro=atof(seguro);
		retorno = 0;
	}
	return retorno;
}
int ara_getSeguro(Arancel* this,float* seguro)
{
	int retorno = 1;
	if(this != NULL)
	{
		*seguro=this->seguro;
		retorno = 0;
	}
	return retorno;
}

int ara_setPorcentajeDeImportacion(Arancel* this,char* porcentajeDeImportacion)
{
	int retorno = 1;
	if(this != NULL && !utn_validarFloat(porcentajeDeImportacion))
	{
		this->porcentajeDeImportacion = atof(porcentajeDeImportacion);
		retorno = 0;
	}
	return retorno;
}
int ara_getPorcentajeDeImportacion(Arancel* this,float* porcentajeDeImportacion)
{
	int retorno = 1;

	if(this != NULL )
	{
		*porcentajeDeImportacion = this->porcentajeDeImportacion;
		retorno = 0;
	}
	return retorno;
}

int ara_setTasaEstadistica(Arancel* this,char* tasaEstadistica)
{
	int retorno = 1;
	if(this != NULL && !utn_validarFloat(tasaEstadistica))
	{
		this->tasaEstadistica = atof(tasaEstadistica);
		retorno = 0;
	}
	return retorno;
}
int ara_getTasaEstadistica(Arancel* this,float* tasaEstadistica)
{
	int retorno = 1;
	if(this != NULL)
	{
		*tasaEstadistica = this->tasaEstadistica;
		retorno = 0;
	}
	return retorno;
}

int ara_setTipoDeLicencia(Arancel* this,char* tipoDeLicencia)
{
	int retorno = 1;
	if(this != NULL && tipoDeLicencia != NULL)
	{
		strcpy(this->tipoDeLicencia,tipoDeLicencia);
		retorno = 0;
	}
	return retorno;
}
int ara_getTipoDeLicencia(Arancel* this,char* tipoDeLicencia)
{
	int retorno = 1;
	if(this != NULL)
	{
		strcpy(tipoDeLicencia,this->tipoDeLicencia);
		retorno = 0;
	}
	return retorno;
}

int ara_alta(Dictionary* this)
{
	int retorno = 1;

	Arancel* pArancel;

	char bufferNomenclado[64];
	char bufferSeguro[64];;
	char bufferPorcentajeDeImportacion[64];;
	char bufferTasaEstadistica[64];;
	char bufferTipoDeLicencia[64];

	if(this != NULL)
	{
		if(!utn_getSringConReintentos(bufferNomenclado,"Ingrese el nomenclador: ","Error, ", 3) && !utn_getStringFloatChar(bufferSeguro, "Ingrese el porsentaje del seguro: ", "Error, ", 3)
				&& !utn_getStringFloatChar(bufferPorcentajeDeImportacion, "Ingrese el porsentaje de importacion: ", "Error, ", 3) && !utn_getStringFloatChar(bufferTasaEstadistica, "Ingrese tasa estadistica: ", "Error, ", 3)
				&& !utn_getStringEntreOpciones2(bufferTipoDeLicencia, "NO_AUTOMATICA", "AUTOMATICA", "OPCION: ", "Error, ", 3))

		{
			pArancel=ara_newParams(bufferNomenclado, bufferSeguro, bufferPorcentajeDeImportacion, bufferTasaEstadistica, bufferTipoDeLicencia);

			if(pArancel != NULL)
			{
				dict_insert(this, bufferNomenclado, pArancel);
				retorno = 0;
			}
		}
	}

	return retorno;
}
int ara_listUno(Arancel* this)
{
	int retorno = 1;
	Arancel aux;
	if(this != NULL && !ara_getNomeclador(this, aux.nomenclado) && !ara_getSeguro(this,&aux.seguro) && !ara_getPorcentajeDeImportacion(this, &aux.porcentajeDeImportacion) && !ara_getTasaEstadistica(this, &aux.tasaEstadistica) && !ara_getTipoDeLicencia(this, aux.tipoDeLicencia))
	{
		printf("%-20s%-15f%-15f%-15f%-15s\n",aux.nomenclado,aux.seguro,aux.porcentajeDeImportacion,aux.tasaEstadistica,aux.tipoDeLicencia);
		retorno=0;
	}
	return retorno;
}
int ara_list(Dictionary* this)
{
	int retorno=1;
	int i;

	LinkedList* pListaAranceles;
	Arancel* pArancel;


	if(this != NULL)
	{
		pListaAranceles=dict_getValues(this);

		if(pListaAranceles != NULL)
		{
			for(i=0;i<ll_len(pListaAranceles);i++)
			{
				pArancel=ll_get(pListaAranceles, i);


					if(retorno == 1)
					{
						printf("%-20s%-15s%-15s%-15s%-15s\n","NOMENCLADOR","SEGURO","%IMPORTACION","TASA","LICENCIA");

					}

					if(!ara_listUno(pArancel))
					{
						retorno = 0;
					}


				}
			}
			ll_deleteLinkedList(pListaAranceles);
		}

	return retorno;
}

int ara_modificar(Dictionary* this)
{
	Arancel* pArancel;

	char bufferSeguro[64];
	char bufferPorcentajeDeImportacion[64];
	char bufferTasaEstadistica[64];
	char bufferTipoDeLicencia[64];

	int retorno=1;
	int opcion;
	char key[64];

	if(this != NULL)
	{
		if(!ara_list(this) && !utn_getSringConReintentos(key, "Ingrese el nomeclador a editar: ", "Error, ", 3))
		{
			pArancel=dict_get(this, key);

			if(pArancel != NULL)
			{
				do
				{
					utn_getInt(&opcion, "MODIFICAR\n1)Seguro\n2)Porcentaje de importacion\n3)Tasa Estadistica\n4)tipoDeLicencia\n5)Volver\nOPCION:", "Error, ");

					switch (opcion) {
						case 1:
							if(!utn_getStringFloatChar(bufferSeguro, "Ingrese el nuevo seguro: ", "Error, ", 3))
							{
								if(!ara_setSeguro(pArancel, bufferSeguro))
								{
									retorno = -1;
								}
							}
							break;
						case 2:
							if(!utn_getStringFloatChar(bufferPorcentajeDeImportacion, "Ingrese el nuevo porcentaje de importacion: ", "Error, ", 3))
							{
								if(ara_setPorcentajeDeImportacion(pArancel,bufferPorcentajeDeImportacion))
								{
									retorno = -1;
								}
							}
							break;
						case 3:
							if(!utn_getStringFloatChar(bufferTasaEstadistica, "Ingrese el nuevo tasa estadistica: ", "Error, ", 3))
							{
								if(!ara_setTasaEstadistica(pArancel, bufferTasaEstadistica))
									{
										retorno =-1;
									}
							}
							break;
						case 4:
							if(!utn_getStringEntreOpciones2(bufferTipoDeLicencia, "NO_AUTOMATICA", "AUTOMATICA", "OPCION: ", "Error, ", 3))
							{
								if(!ara_setTipoDeLicencia(pArancel,bufferTipoDeLicencia))
								{
									retorno = -1;
								}
							}
							break;
						case 5:
							retorno = 0;
							break;
						default:
							printf("Error, ingrese una opcion valida\n ");
							break;
					}

					if(retorno==-1)
					{
						printf("Se modifico correctamente\n");
						retorno=1;
					}
					else if(retorno == 1)
					{
						printf("No se pudo modificar\n");
					}

				}while(opcion != 5);
			}
		}
	}
	return retorno;
}
int ara_dump(char* archivoNombre,Dictionary* this)
{
	FILE* pArchivo = fopen(archivoNombre,"w");
	LinkedList* listaArancel = dict_getValues(this);
	Arancel* pArancel;
	Arancel aux;
	int reotno=1;

	if(this != NULL && pArchivo != NULL && listaArancel != NULL)
	{
		fprintf(pArchivo,"NOMENCLADOR,SEGURO,IMPORTACION,TASA ESTADISTICA,LICENCIA\n");

		for(int i=0;i<ll_len(listaArancel);i++)
		{
			pArancel=ll_get(listaArancel, i);

			if(pArancel != NULL && !ara_getNomeclador(pArancel, aux.nomenclado) && !ara_getSeguro(pArancel, &aux.seguro) && !ara_getPorcentajeDeImportacion(pArancel, &aux.porcentajeDeImportacion) && !ara_getTasaEstadistica(pArancel, &aux.tasaEstadistica) && !ara_getTipoDeLicencia(pArancel, aux.tipoDeLicencia))
			{
				fprintf(pArchivo,"%s,%f,%f,%f,%s\n",aux.nomenclado,aux.seguro,aux.porcentajeDeImportacion,aux.tasaEstadistica,aux.tipoDeLicencia);
				reotno=1;
			}
		}

	}
	fclose(pArchivo);
	return reotno;
}
int ara_parse(char* ArchivoNombre,Dictionary* this)
{
	int retorno = 1;
	int flag=1;

	char bufferNomeclador[64];
	char seguro[64];
	char porcentajeDeImportacion[64];
	char tasaEstadistica[64];
	char tipoDeLicencia[64];

	FILE* pArchivo = fopen(ArchivoNombre,"r");
	Arancel* pArancel;

	do
	{
		if(pArchivo != NULL && this != NULL)
		{
				if(5==fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferNomeclador,seguro,porcentajeDeImportacion,tasaEstadistica,tipoDeLicencia))
				{

					if(flag == 0)
					{
						pArancel=ara_newParams(bufferNomeclador, seguro, porcentajeDeImportacion, tasaEstadistica, tipoDeLicencia);

						if(pArancel != NULL)
						{
							dict_insert(this, bufferNomeclador, pArancel);
							retorno=0;
						}
					}
					else
					{
						if(flag==1)
						{
							flag=0;
						}
					}
				}
		}
	}while(feof(pArchivo)==0);

	fclose(pArchivo);
	return retorno;
}
int ara_baja(Dictionary* this)
{
	int retorno=1;
	char key[64];

	Arancel* pArancel;
	if(this != NULL)
	{
		if(!ara_list(this))
		{
			utn_getString(key, "Ingrese el nomenclador a borrar: ", "Error, ");

			pArancel=dict_get(this, key);

			if(pArancel != NULL)
			{
				ara_delete(pArancel);
				dict_remove(this, key);
				retorno=0;
			}
		}
	}
	return retorno;
}
int ara_menu(Dictionary* this)
{
	int opcion=0;

	do
	{
		utn_getInt(&opcion,MENU_ARANCEL, "Error, ");

		switch (opcion) {
			case 1:
				ara_alta(this);
				ara_dump(ARA_ARCHIVO, this);
				break;
			case 2:
				ara_modificar(this);
				ara_dump(ARA_ARCHIVO, this);
				break;
			case 3:
				ara_baja(this);
				ara_dump(ARA_ARCHIVO,this);
				break;
			case 4:
				ara_list(this);
				break;
			case 5:
				break;
			default:
				printf("Opcion invalida\n");
				break;
		}
	}while(opcion != 5);

	return 0;
}
