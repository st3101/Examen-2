
#include <stdio.h>
#include <stdlib.h>

#include "collections/LinkedList.h"
#include "collections/Dictionary.h"
#include "maritimo.h"
#include "aereo.h"
#include "articulo.h"
#include "arancel.h"
#include "transporte.h"
#include "informes.h"

#include "utn.h"

#define ART_ARCHIVO "articulos.cvs"
#define ARA_ARCHIVO "aranceles.cvs"
#define MAR_ARCHIVO "maritimo.cvs"
#define AER_ARCHIVO "aereo.cvs"

int main(void)
{
	setbuf(stdout,NULL);

	int opcion;
	Dictionary* dictArticulos = dict_new(0);
	Dictionary* dictAranceles = dict_new(0);


	Maritimo esMaritimo;
	Aereo esAereo;

	art_parse(ART_ARCHIVO, dictArticulos);
	ara_parse(ARA_ARCHIVO, dictAranceles);
	mar_parse(MAR_ARCHIVO,&esMaritimo);
	aer_parse(AER_ARCHIVO,&esAereo);


	do
	{
		utn_getInt(&opcion, "MENU\n1)Articulos\n2)Aranceles\n3)Transoportes\n4)Informes\n5)Salir\nOPCION: ", "Error, ");
		switch (opcion) {
			case 1:
				art_menu(dictArticulos,dictAranceles);
				break;
			case 2:
				ara_menu(dictAranceles);
				break;
			case 3:
				tra_menu(&esMaritimo,&esAereo);
				break;
			case 4:
				inf_infomar(dictArticulos, dictAranceles,esMaritimo,esAereo);
				break;
			case 5:
				break;
			default:
				printf("Opcion invalida\n");
				break;
		}

	}while(opcion != 5);



}

