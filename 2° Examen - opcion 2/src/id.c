/*
 * id.c
 *
 *  Created on: 18 jun. 2021
 *      Author: santi
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int id_parse(char* nameFile,char* id)
{

	char bufferId[32];
	int retorno=1;

	FILE* pFile = fopen(nameFile,"r");

	if(pFile != NULL)
	{
		if(fscanf(pFile,"%[^\n]\n",bufferId)==1)
		{
			strcpy(id,bufferId);
			retorno = 0;
		}
	}
	return retorno;
}

int id_dump(char* nameFile,int id)
{
	int retorno=1;
	FILE* pFile = fopen(nameFile,"w");

	if(pFile != NULL && id >= 0)
	{
		fprintf(pFile,"%d\n",id);
		retorno = 0;
	}
	fclose(pFile);

	return retorno;
}
int id_New(char* nameFile,char* id)
{
	int retorno=-1;
	int idAux=0;

	if(nameFile != NULL)
	{
		if(!id_parse(nameFile,id))
		{
			idAux=atoi(id);

			if(idAux >-1 )
			{
				idAux++;

				if(!id_dump(nameFile, idAux))
				{
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

