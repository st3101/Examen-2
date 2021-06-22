/*
 * transporte.c
 *
 *  Created on: 20 jun. 2021
 *      Author: santi
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "maritimo.h"
#include "aereo.h"
#define MAR_ARCHIVO "maritimo.cvs"
#define AER_ARCHIVO "aereo.cvs"

int tra_menu(Maritimo* esMaitimo,Aereo* esAereo)
{
	int retorno = 1;
	int opcion;


	if(esMaitimo != NULL && esAereo != NULL)
	{
		do
		{
			utn_getInt(&opcion, "MODIFICAR TRANSPORTE\n1)Maritimo\n2)Aereo\n3)Listar Transportes\n4)Volver\nOPCION: " ,"Error, ");

			switch (opcion) {
				case 1:
					if(!mar_modificar(esMaitimo))
					{
						if(!mar_dump(MAR_ARCHIVO, esMaitimo))
						{
							retorno = -1;
						}
					}
					break;
				case 2:
					if(!aer_modificar(esAereo))
					{
						if(!aer_mar_dump(AER_ARCHIVO, esAereo))
						{
							retorno = -1;
						}
					}
					break;
				case 3:
					if(!mar_list(esMaitimo) && !aer_list(esAereo))
					{
						retorno = -1;
					}
					break;
				case 4:
					retorno = 0;
					break;
				default:
					break;
			}

		}while(opcion != 4);
	}
	return retorno;
}
