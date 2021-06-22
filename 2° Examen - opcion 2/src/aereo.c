/*
 * aereo.c
 *
 *  Created on: 21 jun. 2021
 *      Author: santi
 */
#include <stdio.h>
#include <stdlib.h>
#include "aereo.h"
#include "utn.h"

int aer_setconstanteVolumetrica(Aereo* this,char* constanteVolumetrica)
{
	int retorno = 1;

	if(this != NULL && constanteVolumetrica != NULL && !utn_validarFloat(constanteVolumetrica))
	{
		this->constanteVolumetrica=atof(constanteVolumetrica);
		retorno = 0;
	}
	return retorno;
}
int aer_getconstanteVolumetrica(Aereo* this,float* constanteVolumetrica)
{
	int retorno = 1;

	if(this != NULL)
	{
		*constanteVolumetrica=this->constanteVolumetrica;
		retorno = 0;
	}
	return retorno;
}
int aer_setvalorPorKilo(Aereo* this,char* valorPorKilo)
{
	int retorno = 1;

	if(this != NULL && valorPorKilo != NULL && !utn_validarFloat(valorPorKilo))
	{
		this->valorPorKilo=atof(valorPorKilo);
		retorno=0;
	}
	return retorno;
}
int aer_getvalorPorKilor(Aereo* this,float* valorPorKilo)
{
	int retorno = 1;

	if(this != NULL)
	{
		*valorPorKilo=this->valorPorKilo;
		retorno = 0;
	}
	return retorno;
}

int aer_modificar(Aereo* this)
{
	int retorno = 1;
	int opcion;
	char buffer[64];
	if(this != NULL)
	{
		do
		{
			utn_getInt(&opcion,"MODIFICAR AEREO\n1)Constante volumetrica\n2)Valor por kilo\n3)Volver\nOPCION: ", "Error, ");

			switch (opcion) {
				case 1:
					if(!utn_getStringFloatChar(buffer, "Ingrese una nueva constante volumetrica: ", "Error, ", 3))
					{
						if(!aer_setconstanteVolumetrica(this, buffer))
						{
							retorno = -1;
						}
					}
					break;
				case 2:
					if(!utn_getStringFloatChar(buffer, "Ingrese el nuevo valor por kilo: ", "Error, ", 3))
					{
						if(!aer_setvalorPorKilo(this, buffer))
						{
							retorno = -1;
						}
					}
					break;
				case 3:
					retorno = 0;
					break;
				default:
					printf("Error, Ingrese una opcion valida\n");
					break;
			}

			if(retorno == -1)
			{
				printf("Se modifico correctamente!\n");
				retorno = 1;
			}
			else if(retorno == 1)
			{
				printf("No se puedo modificar!\n");
			}


		}while(opcion != 3);


	}
	return retorno;
}
int aer_list(Aereo* this)
{
	int retorno=1;
	Aereo aux;

	if(this != NULL)
	{
		if(!aer_getconstanteVolumetrica(this, &aux.constanteVolumetrica)&& !aer_getvalorPorKilor(this, &aux.valorPorKilo))
		{
			printf("AEREO\nConstante volumetrica: %f\nValor por kilo: %f\n",aux.constanteVolumetrica,aux.valorPorKilo);
			retorno = 0;
		}
	}
	return retorno;
}


int aer_parse(char* archivoNombre,Aereo* this)
{

	int retorno = 1;
	int flag=1;

	char bufferConstanteVolumetrica[64];
	char bufferValorPorKilo[64];

	FILE* pArchivo = fopen(archivoNombre,"r");

	do
	{
		if(pArchivo != NULL && this != NULL)
		{
				if(2==fscanf(pArchivo,"%[^,],%[^\n]\n",bufferConstanteVolumetrica,bufferValorPorKilo))
				{
					if(flag == 0)
					{
						if(!aer_setconstanteVolumetrica(this, bufferConstanteVolumetrica) && !aer_setvalorPorKilo(this, bufferValorPorKilo))
						{
							retorno = 0;
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
int aer_mar_dump(char* archivoNombre,Aereo* this)
{
	int retorno=1;
	FILE* pArchivo = fopen(archivoNombre,"w");

	float bufferConstanteVolumetrica;
	float bufferValorPorKilo;

	if(archivoNombre != NULL && this != NULL && pArchivo != NULL)
	{
		fprintf(pArchivo,"constanteVolumetrica,valorPorKilo\n");

		if(!aer_getconstanteVolumetrica(this, &bufferConstanteVolumetrica) && !aer_getvalorPorKilor(this, &bufferValorPorKilo))
		{
			fprintf(pArchivo,"%f,%f\n",bufferConstanteVolumetrica,bufferValorPorKilo);
			retorno = 0;
		}
	}
	fclose(pArchivo);
	return retorno;
}
