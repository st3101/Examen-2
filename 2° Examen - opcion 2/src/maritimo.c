/*
 * maritimo.c
 *
 *  Created on: 20 jun. 2021
 *      Author: santi
 */
#include <stdio.h>
#include <stdlib.h>
#include "maritimo.h"
#include "utn.h"

int mar_setMcubicos(Maritimo* this,char* Mcubicos)
{
	int retorno=1;

	if(this != NULL && Mcubicos != NULL && !utn_validarFloat(Mcubicos))
	{
		this->Mcubicos=atof(Mcubicos);
		retorno = 0;
	}
	return retorno;
}
int mar_getMcubicos(Maritimo* this,float* Mcubicos)
{
	int retorno=1;

	if(this != NULL)
	{
		*Mcubicos = this->Mcubicos;
		retorno=0;
	}
	return retorno;
}

int mar_setValorDelcontenedor(Maritimo* this,char* ValorDelcontenedor)
{
	int retorno = 1;

	if(this != NULL && ValorDelcontenedor != NULL && !utn_validarFloat(ValorDelcontenedor))
	{
		this->ValorDelcontenedor=atof(ValorDelcontenedor);
		retorno = 0;
	}
	return retorno;
}
int mar_getValorDelcontenedor(Maritimo* this,float* ValorDelcontenedor)
{
	int retorno = 1;

	if(this != NULL )
	{
		*ValorDelcontenedor=this->ValorDelcontenedor;
		retorno = 0;
	}
	return retorno;
}

int mar_modificar(Maritimo* this)
{
	int retorno = 1;
	int opcion;
	char buffer[64];
	if(this != NULL)
	{
		do
		{
			utn_getInt(&opcion, "MODIFICAR MARITIMO\n1)Metros cubicos\n2)Valor contenedor\n3)Volver\nOPCION: ", "Error, ");

			switch (opcion)
			{
				case 1:
					if(!utn_getStringNumeroChar(buffer, "Ingrese el nuevo metro cubico: ", "Error, ", 3))
					{
						if(!mar_setMcubicos(this, buffer))
						{
							retorno = -1;
						}
					}
					break;
				case 2:
					if(!utn_getStringFloatChar(buffer, "Ingrese el Valor del contenedor: ", "Error, ", 3))
					{
						if(!mar_setValorDelcontenedor(this, buffer))
						{
							retorno = -1;
						}
					}
					break;
				case 3:
					retorno = 0;
					break;
				default:
				printf("Error, Ingrese una opcion valida \n");
				break;
			}

			if(retorno == -1)
			{
				printf("Se modifico correctamente!\n");
				retorno = 1;
			}
			else if (retorno == 1)
			{
				printf("Se pudo modificar!\n");
			}

		}while(opcion != 3);



	}
	return retorno;
}


int mar_parse(char* archivoNombre,Maritimo* this)
{
	int retorno = 1;
	int flag=1;

	char bufferMCubicos[64];
	char bufferValorDelcontenedor[64];

	FILE* pArchivo = fopen(archivoNombre,"r");

	do
	{
		if(pArchivo != NULL && this != NULL)
		{
				if(2==fscanf(pArchivo,"%[^,],%[^\n]\n",bufferMCubicos,bufferValorDelcontenedor))
				{
					if(flag == 0)
					{
						if(!mar_setMcubicos(this, bufferMCubicos) && !mar_setValorDelcontenedor(this, bufferValorDelcontenedor))
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

int mar_dump(char* archivoNombre,Maritimo* this)
{
	FILE* pArchivo = fopen(archivoNombre,"w+");
	Maritimo aux;
	int retorno=1;

	if(this != NULL && pArchivo != NULL)
	{
		fprintf(pArchivo,"Mcubicos,ValorDelcontenedor\n");

			if(!mar_getMcubicos(this,&aux.Mcubicos) && !mar_getValorDelcontenedor(this, &aux.ValorDelcontenedor))
			{
				fprintf(pArchivo,"%f,%f\n",aux.Mcubicos,aux.ValorDelcontenedor);
				retorno=0;
			}
	}

	fclose(pArchivo);

	return retorno;
}
int mar_list(Maritimo* this)
{
	int retorno=1;
	Maritimo aux;

	if(this != NULL)
	{
		if(!mar_getMcubicos(this, &aux.Mcubicos) && !mar_getValorDelcontenedor(this, &aux.ValorDelcontenedor))
		{
			printf("MARITIMO\nMetros cubicos: %f\nValor del contenedor: %f\n",aux.Mcubicos,aux.ValorDelcontenedor);
			retorno = 0;
		}
	}
	return retorno;
}
