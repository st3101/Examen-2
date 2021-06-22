/*
 * articulo.c
 *
 *  Created on: 15 jun. 2021
 *      Author: santi
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arancel.h"
#include "articulo.h"
#include "utn.h"
#include "id.h"

#define MENU_PRODUCTO "MENU PRODUCTO\n1)Alta\n2)Modificacion\n3)Baja\n4)Listar\n5)Volver\nOPCION:"
#define ART_ARCHIVO "articulos.cvs"

Articulo* art_new(void)
{
	return (Articulo*) malloc(sizeof(Articulo));
}

Articulo* art_newParams(char* id,char* codigo,char* descripcion,char* paisDeFabricacion,char* valorFob,char* pesoEnKilo,char* anchoCm,char* altoCm,char* profundidadCm,char* posicionArancelaria)
{
	Articulo* pArticulo = art_new();

	if(pArticulo != NULL && id != NULL && codigo != NULL && descripcion != NULL && paisDeFabricacion != NULL && valorFob != NULL && pesoEnKilo != NULL && anchoCm != NULL && altoCm != NULL && profundidadCm != NULL && posicionArancelaria != NULL)
	{
		if(art_setId(pArticulo, id) || art_setCodigo(pArticulo, codigo) || art_setDescripcion(pArticulo,descripcion) || art_setPaisDeFabricacion(pArticulo, paisDeFabricacion) || art_setValorFob(pArticulo, valorFob) || art_setPesoEnKilos(pArticulo, pesoEnKilo) || art_setAnchoCm(pArticulo, anchoCm) || art_setAltoCm(pArticulo, altoCm) || art_setProfundidaCm(pArticulo, profundidadCm) || art_setPosicionArancelaria(pArticulo, posicionArancelaria))
		{
			art_delete(pArticulo);
			pArticulo=NULL;
		}
	}
	return pArticulo;
}
int art_delete(Articulo* this)
{
	int retorno=1;

	if(this != NULL)
	{
		free(this);
		retorno=0;
	}
	return retorno;
}

int art_setId(Articulo* this,char* id)
{
	int retorno = 1;

	if(this != NULL && !utn_validarNumero(id))
	{
		this->id=atoi(id);
		retorno = 0;
	}

	return retorno;
}
int art_getId(Articulo* this,int* id)
{
	int retorno = 1;
	if(this != NULL)
	{
		*id=this->id;
		retorno = 0;
	}

	return retorno;
}

int art_setDescripcion(Articulo* this,char* descripcion)
{
		int retorno = 1;

		if(this != NULL)
		{
			strcpy(this->descripcion,descripcion);
			retorno = 0;
		}

		return retorno;
}
int art_getDescripcion(Articulo* this,char* descripcion)
{
	int retorno = 1;
	if(this != NULL)
	{
		strcpy(descripcion,this->descripcion);
		retorno = 0;
	}
	return retorno;
}

int art_setCodigo(Articulo* this,char* codigo)
{
	int retorno = 1;
	if(this != NULL && codigo != NULL)
	{
		strcpy(this->codigo,codigo);
		retorno = 0;
	}

	return retorno;
}
int art_getCodigo(Articulo* this,char* codigo)
{
	int retorno = 1;
	if(this != NULL)
	{
		strcpy(codigo,this->codigo);
		retorno = 0;
	}
	return retorno;
}

int art_setPaisDeFabricacion(Articulo* this,char* paisDeFabricacion)
{
	int retorno = 1;
	if(this != NULL && paisDeFabricacion != NULL)
	{
		strcpy(this->paisDeFabricacion,paisDeFabricacion);
		retorno = 0;
	}
	return retorno;
}
int art_getPaisDeFabricacion(Articulo* this,char* paisDeFabricacion)
{
	int retorno = 1;
	if(this != NULL)
	{
		strcpy(paisDeFabricacion,this->paisDeFabricacion);
		retorno = 0;
	}
	return retorno;
}

int art_setValorFob(Articulo* this,char* valorFob)
{
	int retorno = 1;
	if(this != NULL && !utn_validarFloat(valorFob))
	{
		this->valorFob = atof(valorFob);
		retorno = 0;
	}
	return retorno;
}
int art_getValorFob(Articulo* this,float* valorFob)
{
	int retorno = 1;
	if(this != NULL)
	{
		*valorFob = this->valorFob;
		retorno = 0;
	}
	return retorno;
}
int art_setPesoEnKilos(Articulo* this,char* pesoEnKilo)
{
	int retorno = 1;
	if(this != NULL && !utn_validarFloat(pesoEnKilo))
	{
		this->pesoEnKilo = atof(pesoEnKilo);
		retorno = 0;
	}
	return retorno;
}
int art_getPesoEnKilos(Articulo* this,float* pesoEnKilo)
{
	int retorno = 1;
	if(this != NULL)
	{
		*pesoEnKilo = this->pesoEnKilo;
		retorno = 0;
	}
	return retorno;
}

int art_setAnchoCm(Articulo* this,char* anchoCm)
{
	int retorno = 1;
	if(this != NULL && !utn_validarFloat(anchoCm))
	{
		this->anchoCm = atof(anchoCm);
		retorno = 0;
	}
	return retorno;
}
int art_getAnchoCm(Articulo* this,float* anchoCm)
{
	int retorno = 1;
	if(this != NULL)
	{
		*anchoCm = this->anchoCm;
		retorno = 0;
	}
	return retorno;
}

int art_setAltoCm(Articulo* this,char* altoCm)
{
	int retorno = 1;
	if(this != NULL && !utn_validarFloat(altoCm))
	{
		this->altoCm = atof(altoCm);
		retorno = 0;
	}
	return retorno;
}
int art_getAltoCm(Articulo* this,float* altoCm)
{
	int retorno = 1;
	if(this != NULL)
	{
		*altoCm = this->altoCm;
		retorno = 0;
	}
	return retorno;
}

int art_setProfundidaCm(Articulo* this,char* profundidadCm)
{
	int retorno = 1;
	if(this != NULL && !utn_validarFloat(profundidadCm))
	{
		this->profundidadCm = atof(profundidadCm);
		retorno = 0;
	}
	return retorno;
}
int art_getProfundidaCm(Articulo* this,float* profundidadCm)
{
	int retorno = 1;
	if(this != NULL)
	{
		*profundidadCm = this->profundidadCm;
		retorno = 0;
	}
	return retorno;
}


int art_setPosicionArancelaria(Articulo* this,char* posicionArancelaria)
{
	int retorno = 1;
	if(this != NULL && posicionArancelaria != NULL)
	{
		strcpy(this->posicionArancelaria,posicionArancelaria);
		retorno = 0;
	}
	return retorno;
}
int art_getPosicionAranceleria(Articulo* this,char* posicionArancelaria)
{
	int retorno = 1;
	if(this != NULL)
	{
		strcpy(posicionArancelaria,this->posicionArancelaria);
		retorno = 0;
	}
	return retorno;
}

int art_alta(Dictionary* thisArt,Dictionary* thisAra)
{
	Articulo* pArticulo;
	Arancel* pArancel;

	int retono=1;

	char bufferId[64];
	char bufferCodigo[64];
	char bufferDescripcion[64];
	char bufferPaisDeFabricacion[64];
	char bufferValorFob[64];
	char bufferPesoEnKilo[64];
	char bufferAnchoCm[64];
	char bufferAltoCm[64];
	char bufferProfundidad[64];
	char bufferPosicionAranselaria[64];

	if(thisArt != NULL)
	{
		if(!utn_getSringConReintentos(bufferCodigo, "Ingrese el codigo: ", "Error ,", 3) && !utn_getSringConReintentos(bufferDescripcion, "Ingrese la descipcion: ", "Error, ", 3)  && !utn_getSoloLetras(bufferPaisDeFabricacion, "Ingrese el pais de fabricacion: ", "Error, ",3) && !utn_getStringFloatChar(bufferValorFob, "Ingrese el valor fob: ", "Error, ",3) && !utn_getStringFloatChar(bufferPesoEnKilo,"Ingrese el peso en kilos:", "Error, ", 3) && !utn_getStringFloatChar(bufferAnchoCm, "Ingrese el ancho en cm: ", "Error, ", 3) && !utn_getStringFloatChar(bufferAltoCm,"Ingrese el alto en cm: "	, "Error, ",3) && !utn_getStringFloatChar(bufferProfundidad, "Ingrese la profundidad en cm: ", "Error, ", 3) && !utn_getSringConReintentos(bufferPosicionAranselaria, "Ingrese la posicion alanceraria: ", "Error,",3))
		{

			id_New("idArt.txt",bufferId);
			pArticulo=art_newParams(bufferId, bufferCodigo, bufferDescripcion, bufferPaisDeFabricacion, bufferValorFob, bufferPesoEnKilo, bufferAnchoCm, bufferAltoCm, bufferProfundidad,bufferPosicionAranselaria);



			if(pArticulo != NULL)
			{
				pArancel=dict_get(thisAra, bufferPosicionAranselaria);

				if(pArancel != NULL)
				{
					dict_insert(thisArt, bufferId, pArticulo);
					retono = 0;
				}
				else
				{
					printf("ALTA ARANCEL\n");
					if(!ara_alta(thisAra))
					{
						dict_insert(thisArt, bufferId, pArticulo);
						retono = 0;
					}
				}


			}

		}
	}
	return retono;
}

int art_modificar(Dictionary* this)
{
	int opcion;
	int retorno=1;
	char key[64];
	Articulo* pArticulo;
	char buffer[64];

	if(this != NULL)
	{
		if(!art_list(this))
		{
			utn_getSringConReintentos(key, "Ingrese el id del articulo a modificar: ", "Error, ",3);

			pArticulo=dict_get(this, key);

			if(pArticulo != NULL)
			{
				do
				{
					utn_getInt(&opcion, "MODIFICAR ARTICULO\n1)Descripcion\n2)Pais de fabricacion\n3)Valor fob\n4)Peso (kilos)\n5)Ancho (cm)\n6)Alto (cm)\n7)Profundidad\n8)Posicion arancelaria\n9)Volver\nOPCION: ", "Error, ");
					switch (opcion) {
						case 1:
							if(!utn_getSringConReintentos(buffer, "Ingrese el nuevo nombre: ","Error, ", 3))
							{
								if(!art_setDescripcion(pArticulo, buffer))
								{
									retorno=-1;
								}
							}
							break;
						case 2:
							if(!utn_getSringConReintentos(buffer, "Ingrese el nuevo pais de fabricacion: ","Error, ", 3))
							{
								if(!art_setPaisDeFabricacion(pArticulo, buffer))
								{
									retorno=-1;
								}
							}
							break;
						case 3:
							if(!utn_getSringConReintentos(buffer, "Ingrese el nuevo valor fob: ","Error, ", 3))
							{
								if(!art_setValorFob(pArticulo, buffer))
								{
									retorno=-1;
								}
							}
							break;
						case 4:
							if(!utn_getSringConReintentos(buffer, "Ingrese el nuevo peso (kilos): ","Error, ", 3))
							{
								if(!art_setPesoEnKilos(pArticulo, buffer))
								{
									retorno=-1;
								}
							}
							break;
						case 5:
							if(!utn_getSringConReintentos(buffer, "Ingrese el nuevo ancho (cm): ","Error, ", 3))
							{
								if(!art_setAnchoCm(pArticulo, buffer))
								{
									retorno=-1;
								}
							}
							break;
						case 6:
							if(!utn_getSringConReintentos(buffer, "Ingrese el nuevo alto (cm): ","Error, ", 3))
							{
								if(!art_setAltoCm(pArticulo, buffer))
								{
									retorno=-1;
								}
							}
							break;
						case 7:
							if(!utn_getSringConReintentos(buffer, "Ingrese el nuevo profunidad (cm): ","Error, ", 3))
							{
								if(!art_setProfundidaCm(pArticulo, buffer))
								{
									retorno=-1;
								}
							}
							break;
						case 8:
							if(!utn_getSringConReintentos(buffer, "Ingrese el nuevo posicion arancelaria: ","Error, ", 3))
							{
								if(!art_setPosicionArancelaria(pArticulo, buffer))
								{
									retorno=-1;
								}
							}
							break;
						case 9:
							retorno = 0;
							break;
						default:
							printf("Opcion invalida, ");
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

				}while(opcion != 9);

			}
		}
	}
	return retorno;
}
int art_ListUno(Articulo* this)
{
	int retono = 1;
	Articulo artAux;

	if(this != NULL && !art_getId(this,&artAux.id) && !art_getCodigo(this, artAux.codigo) && !art_getDescripcion(this, artAux.descripcion) && !art_getPaisDeFabricacion(this, artAux.paisDeFabricacion) && !art_getValorFob(this,&artAux.valorFob) && !art_getPesoEnKilos(this, &artAux.pesoEnKilo) && !art_getAnchoCm(this, &artAux.anchoCm) && !art_getAltoCm(this,&artAux.altoCm) && !art_getProfundidaCm(this, &artAux.profundidadCm) && !art_getPosicionAranceleria(this,artAux.posicionArancelaria))
	{
		printf("%-5d%-15s%-20s%-15s%-15f%-15f%-15f%-15f%-15f%-15s\n",artAux.id,artAux.codigo,artAux.descripcion,artAux.paisDeFabricacion,artAux.valorFob,artAux.pesoEnKilo,artAux.anchoCm,artAux.altoCm,artAux.profundidadCm,artAux.posicionArancelaria);
		retono = 0;
	}


		return retono;
}

int art_list(Dictionary* this)
{
	int retorno=1;
	int i;

	LinkedList* pListaArticulos;
	Articulo* pArticulo;

	if(this != NULL)
	{
		pListaArticulos=dict_getValues(this);

		if(pListaArticulos != NULL)
		{
			for(i=0;i<ll_len(pListaArticulos);i++)
			{
				pArticulo=ll_get(pListaArticulos, i);

					if(retorno == 1)
					{
						printf("%-5s%-15s%-20s%-15s%-15s%-15s%-15s%-15s%-15s%-15s\n","ID","CODIGO","DESCIPCION","ORIGEN","FOB","PESO","AMCHO","ALTO","PROFUNDIDAD","POSICION ARANCELARIA");
					}

					if(!art_ListUno(pArticulo))
					{
						retorno=0;
					}
			}
		}

		ll_deleteLinkedList(pListaArticulos);
	}

	return retorno;
}
int art_parse(char* ArchivoNombre,Dictionary* this)
{

	int retorno = 1;
	int flag=1;

	char bufferId[64];
	char bufferCodigo[64];
	char bufferDescripcion[64];
	char bufferPaisDeFabricacion[64];
	char bufferValorFob[64];
	char bufferPesoEnKilo[64];
	char bufferAnchoCm[64];
	char bufferAltoCm[64];
	char bufferProfundidadCm[64];
	char bufferPosicionArancelaria[64];

	FILE* pArchivo = fopen(ArchivoNombre,"r");
	Articulo* pArticulos;

	do
	{
		if(pArchivo != NULL && this != NULL)
		{

				if(10==fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferCodigo,bufferDescripcion,bufferPaisDeFabricacion,bufferValorFob,bufferPesoEnKilo,bufferAnchoCm,bufferAltoCm,bufferProfundidadCm,bufferPosicionArancelaria))
				{

					if(flag == 0)
					{
						pArticulos=art_newParams(bufferId, bufferCodigo, bufferDescripcion, bufferPaisDeFabricacion, bufferValorFob, bufferPesoEnKilo, bufferAnchoCm, bufferAltoCm, bufferProfundidadCm, bufferPosicionArancelaria);

						if(pArticulos != NULL)
						{
							dict_insert(this, bufferId, pArticulos);
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

int art_dump(char* nombreArchivo,Dictionary* this)
{
	FILE* pArchivo = fopen(nombreArchivo,"w");
	LinkedList* listaArticulos = dict_getValues(this);
	Articulo* pArticulo;
	Articulo artAux;
	int reotno=1;

	if(this != NULL && pArchivo != NULL && listaArticulos != NULL)
	{
		fprintf(pArchivo,"id,codigo,descripcion,paisDeFabricacion,fob,peso,ancho,alto,profundidad,posicionArancelaria\n");

		for(int i=0;i<ll_len(listaArticulos);i++)
		{
			pArticulo=ll_get(listaArticulos, i);

			if(pArticulo != NULL && !art_getId(pArticulo,&artAux.id) && !art_getCodigo(pArticulo, artAux.codigo) && !art_getDescripcion(pArticulo, artAux.descripcion) && !art_getPaisDeFabricacion(pArticulo, artAux.paisDeFabricacion) && !art_getValorFob(pArticulo,&artAux.valorFob) && !art_getPesoEnKilos(pArticulo, &artAux.pesoEnKilo) && !art_getAnchoCm(pArticulo, &artAux.anchoCm) && !art_getAltoCm(pArticulo,&artAux.altoCm) && !art_getProfundidaCm(pArticulo, &artAux.profundidadCm) && !art_getPosicionAranceleria(pArticulo,artAux.posicionArancelaria))
			{
				fprintf(pArchivo,"%d,%s,%s,%s,%f,%f,%f,%f,%f,%s\n",artAux.id,artAux.codigo,artAux.descripcion,artAux.paisDeFabricacion,artAux.valorFob,artAux.pesoEnKilo,artAux.anchoCm,artAux.altoCm,artAux.profundidadCm,artAux.posicionArancelaria);
				reotno=1;
			}
		}

	}
	fclose(pArchivo);
	return reotno;
}
int art_baja(Dictionary* this)
{
	int retorno=1;
	char key[64];

	Articulo* pArticulo;
	if(this != NULL)
	{
		if(!art_list(this))
		{
			utn_getString(key, "Ingrese el id a borrar: ", "Error, ");

			pArticulo=dict_get(this, key);

			if(pArticulo != NULL)
			{
				art_delete(pArticulo);
				dict_remove(this, key);
				retorno=0;
			}
		}
	}
	return retorno;
}

int art_menu(Dictionary* this,Dictionary* thiAra)
{
	int opcion=0;
	//art_parse(ART_ARCHIVO, this);
	do
	{
		utn_getInt(&opcion,MENU_PRODUCTO, "Error, ");

		switch (opcion) {
			case 1:
				art_alta(this,thiAra);
				art_dump(ART_ARCHIVO, this);
				break;
			case 2:
				art_modificar(this);
				art_dump(ART_ARCHIVO, this);
				break;
			case 3:
				art_baja(this);
				art_dump(ART_ARCHIVO, this);
				break;
			case 4:
				art_list(this);
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
