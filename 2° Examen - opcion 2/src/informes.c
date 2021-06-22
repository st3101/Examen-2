/*
 * informes.c
 *
 *  Created on: 21 jun. 2021
 *      Author: santi
 */
#include <stdio.h>
#include <stdlib.h>
#include "articulo.h"
#include "maritimo.h"
#include "arancel.h"
#include "aereo.h"
#include "collections/LinkedList.h"
#include "collections/Dictionary.h"

int inf_calBaseImponible(Articulo* art,Arancel* ara,float flete,float* resultado)
{
	int retorno=1;

	float bufferValorFob;
	float bufferSeguro;
	if(art != NULL && ara != NULL && flete > 0)
	{

		if(!art_getValorFob(art, &bufferValorFob) && !ara_getSeguro(ara, &bufferSeguro))
		{
			*resultado=bufferValorFob+((bufferValorFob*bufferSeguro)/100)+flete;
			retorno = 0;
		}
	}

	return retorno;
}
int inf_claFleteAereo(Articulo* art,Aereo esAereo,float* resultado)
{
	int retorno=1;

	float pesoReal;
	float pesoVolumetrico;

	float pesoEnKilosArt;
	float valorPorKiloAer;

	float anchoCmArt;
	float altoCmArt;
	float profundidadCmArt;

	float constanteVolumetricaAer;

	if(art != NULL)
	{
		if(!art_getPesoEnKilos(art, &pesoEnKilosArt) && !aer_getvalorPorKilor(&esAereo, &valorPorKiloAer) && !art_getAnchoCm(art, &anchoCmArt) && !art_getAltoCm(art, &altoCmArt) && !art_getProfundidaCm(art, &profundidadCmArt) && !aer_getconstanteVolumetrica(&esAereo, &constanteVolumetricaAer))
		{
			pesoReal=(pesoEnKilosArt) *valorPorKiloAer; //POSIBLE ERROR PROFE AL CALCULAR

			pesoVolumetrico=((anchoCmArt*altoCmArt*profundidadCmArt)/6000) *valorPorKiloAer;

			retorno = 0;
			if(pesoReal>pesoVolumetrico)
			{
				*resultado=pesoReal;

			}else
			{
				*resultado=pesoVolumetrico;
			}

		}


	}
	return retorno;
}
int inf_calFleteMaritimo(Articulo* art,Maritimo esMaritimo,float* resultado)
{
	int retorno = 1;

	float bufferAncho;
	float bufferAlto;
	float bufferProfundidad;

	float bufferMcubicos;
	float bufferValorContenedor;

	if(art != NULL)
	{
		if(!art_getAnchoCm(art, &bufferAncho) && !art_getAltoCm(art, &bufferAlto) && !art_getProfundidaCm(art, &bufferProfundidad) && !mar_getMcubicos(&esMaritimo, &bufferMcubicos) && ! mar_getValorDelcontenedor(&esMaritimo, &bufferValorContenedor))
		{
			*resultado= ((bufferAncho * bufferAlto * bufferProfundidad) / 1000000) * (bufferValorContenedor / bufferMcubicos);
			retorno = 0;
		}
	}
	return retorno;
}

Arancel* inf_getArancelDeUnArticulo(Articulo* pArticulo,Dictionary* ara)
{
	Arancel* pArancel;
	char auxPosicionArancelari[64];

	if(pArticulo != NULL && ara != NULL && !art_getPosicionAranceleria(pArticulo, auxPosicionArancelari))
	{
		pArancel=dict_get(ara, auxPosicionArancelari);
	}
	return pArancel;
}
int inf_calCostoArgentino(float baseImponible,Arancel* pAracel,float* resultado)
{
	int retorno=1;
	float porcentajeDeImportacion;
	float tasaEstadistica;

	if(baseImponible > 0 && pAracel != NULL)
	{
		if(!ara_getPorcentajeDeImportacion(pAracel, &porcentajeDeImportacion) && !ara_getTasaEstadistica(pAracel, &tasaEstadistica))
		{
			*resultado=baseImponible + (baseImponible*(porcentajeDeImportacion/100))+ (baseImponible*(tasaEstadistica/100));
			retorno = 0;
		}
	}
	return retorno;
}
int inf_infomar(Dictionary* DicArt,Dictionary* DicAra,Maritimo esMaritimo,Aereo esAereo)
{
	int retono = 1;
	LinkedList* listArticulos;
	Articulo* pArticulo;
	Arancel* pArancel;

	float fleteMaritimo;
	float fleteAereo;
	float baseImponibleMartimo;
	float baseImponibleAereo;
	float costoArgentinoMaritimo;
	float costoArgentinoAereo;


	if(DicArt != NULL && DicAra != NULL)
	{
		listArticulos=dict_getValues(DicArt);

		if(listArticulos != NULL)
		{
			for(int i=0;i<ll_len(listArticulos);i++)
			{
				pArticulo=ll_get(listArticulos, i);

				if(pArticulo != NULL)
				{
					pArancel=inf_getArancelDeUnArticulo(pArticulo, DicAra);

					if(pArancel != NULL)
					{
						printf("%-5s%-15s%-20s%-15s%-15s%-15s%-15s%-15s%-15s%-15s\n","ID","CODIGO","DESCIPCION","ORIGEN","FOB","PESO","AMCHO","ALTO","PROFUNDIDAD","POSICION ARANCELARIA");

						if(!art_ListUno(pArticulo) && !inf_calFleteMaritimo(pArticulo, esMaritimo, &fleteMaritimo) && !inf_calBaseImponible(pArticulo, pArancel, fleteMaritimo, &baseImponibleMartimo) && !inf_claFleteAereo(pArticulo, esAereo, &fleteAereo) && !inf_calBaseImponible(pArticulo, pArancel, fleteAereo, &baseImponibleAereo))
						{
							if(!inf_calCostoArgentino(baseImponibleMartimo, pArancel, &costoArgentinoMaritimo) && !inf_calCostoArgentino(baseImponibleAereo, pArancel, &costoArgentinoAereo))
							{
								printf("-------------------  COSTO ARGENTINA    Maritimo: %-20fAereo: %f         -----------------\n",costoArgentinoMaritimo,costoArgentinoAereo);
								retono = 0;
							}
						}
					}
				}
			}
		}
	}

	return retono;
}
