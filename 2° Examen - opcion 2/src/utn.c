/*
 * utn.c
 *
 *  Created on: 15 abr. 2021
 *      Author: santi
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/** \brief obtiene un string pretermiando de 64 caracteres preguntado por pantalla un menasje.
 *
 * \param *pResultado retorno de string.
 * \param *mensaje que se muestrar al pedir datos.
 * \param *mensajeError mensaje cuando se carga incorectamente.
 * \param lenCompra lista de lenCompra
 * \return 1 si funciono correctamente
 *
 */
int utn_getString(char* pResultado,char* mensaje,char* mensajeError)
{
	int retorno = 1;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL)
	{
		printf("%s",mensaje);

		fgets(pResultado,64,stdin);

			if(pResultado[strlen(pResultado)-1]==10)
			{
				pResultado[strlen(pResultado)-1] = 0;
				retorno = 0;
			}
	}
	else
	{
		printf("%s",mensajeError);
	}


	return retorno;
}
/** \brief obtiene un caracter
 *
 * \param *letra retorno de char.
 * \param *mensaje que se mostrar al pedir datos.
 * \param *mensajeError lista de cliente.
 * \return 1 si funciono correctamente
 *
 */
int utn_getLetra(char* letra,char* mensaje,char* mensajeError)
{
	int retorno = 0;

	if(letra != NULL && mensaje != NULL && mensajeError != NULL)
	{
		printf("%s",mensaje);

		*letra=getchar();
		fflush(stdin);
		retorno = 1;
	}
	else
	{
		printf("%s",mensajeError);
	}

	return retorno;
}

/** \brief obtiene un entero
 *
 * \param *pEntero retorno de entero.
 * \param *mensaje que se muestrar al pedir datos.
 * \param *mensajeError mensaje cuando se carga incorectamente.
 * \return 1 si funciono correctamente
 *
 */
int utn_getInt(int* pEntero,char* mensaje,char* mensajeError)
{
	int retorno = 1;

	if(pEntero != NULL && mensaje != NULL && mensajeError != NULL)
	{

		printf("%s",mensaje);

		scanf("%d",pEntero);
		fflush(stdin);
		retorno = 0;
	}


	return retorno;
}

/** \brief obtiene un float
 *
 * \param *pFloat retorno de float.
 * \param *mensaje que se muestrar al pedir datos.
 * \param *mensajeError mensaje cuando se carga incorectamente.
 * \return 1 si funciono correctamente
 *
 */
int utn_getfloat(float* pFloat,char* mensaje,char* mensajeError)
{
	int retorno = 0;

	if(pFloat != NULL && mensaje != NULL && mensajeError != NULL)
	{
		printf("%s",mensaje);
		scanf("%f",pFloat);
		retorno = 1;
	}
	else
	{
		printf("%s",mensajeError);
	}

	return retorno;
}

/** \brief Valida si es un numero.
 *
 * \param *array que se desea validar.
 * \return 1 si funciono correctamente
 *
 */
int utn_validarNumero(char* array)
{
	int i=0;
	int retorno = 0;

	if(array != NULL)
	{
		while(array[i] != '\0')
		{
			if(array[i] != '-')
			{
				if(array[i] < '0' || array[i] > '9')
				{
					retorno = 1;
					break;
				}
			}

			i++;
		}
	}
	return retorno;
}

/** \brief Valida si es un Float.
 *
 * \param *array que se desea validar.
 * \return 1 si funciono correctamente
 *
 */
int utn_validarFloat(char* array)
{
	int i=0;
	int retorno = 0;

	if(array != NULL)
	{
		while(array[i] != '\0')
		{
			if(array[i] != '.' && array[i] != '-')
			{
				if(array[i] < '0' || array[i] > '9')
				{

					retorno = 1;
					break;
				}
			}
			i++;
		}
	}
	return retorno;
}
/** \brief Valida si es solo hay letras.
 *
 * \param *array que se desea validar.
 * \return 1 si funciono correctamente
 *
 */
int utn_validarLetra(char* array)
{
	int i=0;
	int retorno = 1;


	if(array != NULL)
	{
		while(array[i] != '\0')
		{

			if((array[i] >= 'a' && array[i] <= 'z') || (array[i] >= 'A' && array[i] <= 'Z'))
			{
				retorno = 0;
			}
			else
			{
				retorno = 1;
				break;
			}

			i++;
		}
	}
		return retorno;
}

/** \brief Valida si es una letra.
 *
 * \param *array que se desea validar
 * \return 1 si funciono correctamente
 *
 */
int utn_validarUnaLetra(char* letra)
{
	int retorno = 0;

		if((*letra <= 'a' && *letra >= 'z') || (*letra <= 'A' && *letra >= 'Z'))
		{
			retorno = 1;
		}

	return retorno;
}

/** \brief Valida si es una M o F.
 *
 * \param *letra que se desea validar.
 * \return 1 si funciono correctamente
 *
 */
int utn_validarSexo(char* letra)
{
	int retorno = 0;

	if(letra != NULL)
	{
		*letra=toupper(*letra);

		if((*letra == 'F'  ||  *letra == 'M'))
		{
			retorno = 1;
		}
	}

	return retorno;
}

/** \brief Obtine solo enteros
 *
 * \param *numero retorno de int.
 * \param *mensaje que se muestrar al pedir datos.
 * \param *mensajeError mensaje cuando se carga incorectamente.
 * \param reintentos reintento al obtener entero.
 * \return 1 si funciono correctamente
 *
 */
int utn_getSoloNumeroEntero(int* numero,char* mensaje, char* mensajeError,int reintetos)
{
	int i;
	char array[50];
	int retorno = 1;

	if(mensaje != NULL && mensajeError != NULL && reintetos >  0)
	{
		for(i=0;i<reintetos;i++)
		{
			if(!utn_getString(array, mensaje, mensajeError))
			{
				if(!utn_validarNumero(array))
				{
					*numero = atoi(array);
					retorno = 0;
					break;
				}
				else
				{
					printf("%s",mensajeError);
				}
			}
		}

	}

	return retorno;
}
/** \brief Obtine solo enteros entre dos enteros
 *
 * \param *numero retorno de int.
 * \param max el entero maximo a ingresar.
 * \param min el entero minimo a ingresar.
 * \param *mensaje que se muestrar al pedir datos.
 * \param *mensajeError mensaje cuando se carga incorectamente.
 * \param reintentos reintento al obtener informacion.
 * \return 1 si funciono correctamente
 *
 */
int utn_getSoloNumeroEnteroMaxMin(int* numero,int max,int min,char* mensaje,char* mensajeError,int reintetos)
{
	int retorno = 0;
	char bufferChar[50];
	int bufferInt;


	if(numero != NULL && mensaje != NULL && mensajeError != NULL && reintetos >  0 && min < max)
	{
		for(int i=0;i<reintetos;i++)
		{

			if(utn_getString(bufferChar, mensaje, mensajeError))
			{
				if(utn_validarNumero(bufferChar))
				{
					bufferInt=atoi(bufferChar);

					if(bufferInt >= min && bufferInt <= max)
					{
						*numero = atoi(bufferChar);
						retorno = 1;
						break;
					}
				}

					printf("%s",mensajeError);

			}
		}
	}


	return retorno;
}
/** \brief Obtine solo enteros entre dos enteros
 *
 * \param *numero retorno de float.
 * \param max el flotante maximo a ingresar.
 * \param min el flotante minimo a ingresar.
 * \param *mensaje que se muestrar al pedir datos.
 * \param *mensajeError mensaje cuando se carga incorectamente.
 * \param reintentos reintento al obtener informacion.
 * \return 1 si funciono correctamente
 *
 */
int utn_getSoloNumeroFloatEntreMaxMin(float* numero,int max,int min,char* mensaje,char* mensajeError,int reintetos)
{
		int retorno = 0;
		char bufferChar[50];
		float bufferInt;


		if(numero != NULL && mensaje != NULL && mensajeError != NULL && reintetos >  0 && min < max)
		{
			for(int i=0;i<reintetos;i++)
			{

				if(utn_getString(bufferChar, mensaje, mensajeError))
				{
					if(utn_validarFloat(bufferChar))
					{
						bufferInt=atof(bufferChar);

						if(bufferInt >= min && bufferInt <= max)
						{
							*numero = bufferInt;
							retorno = 1;
							break;
						}
					}

						printf("%s",mensajeError);

				}
			}
		}


		return retorno;
}
/** \brief Obtine solo flotantes
 *
 * \param *numero retorno de flotante.
 * \param *mensaje que se muestrar al pedir datos.
 * \param *mensajeError mensaje cuando se carga incorectamente.
 * \param reintentos reintento al obtener entero.
 * \return 1 si funciono correctamente
 *
 */
int utn_getSoloNumeroFloat(float* numero,char* mensaje, char* mensajeError,int reintetos)
{
	int i;
	char array[50];
	int retorno = 0;

	if(array != NULL && mensaje != NULL && mensajeError != NULL && reintetos >  0)
	{
		for(i=0;i<reintetos;i++)
		{
			if(utn_getString(array, mensaje, mensajeError))
			{
				if(utn_validarFloat(array))
				{
					*numero = atof(array);
					retorno = 1;
					break;
				}
				else
				{
					printf("%s, ",mensajeError);
				}
			}
		}

	}

	return retorno;
}
/** \brief Obtine string de solo letras
 *
 * \param *palabra retorno de string.
 * \param *mensaje que se muestrar al pedir datos.
 * \param *mensajeError mensaje cuando se carga incorectamente.
 * \param reintentos reintento al obtener entero.
 * \return 1 si funciono correctamente
 *
 */
int utn_getSoloLetras(char* palabra,char* mensaje,char* mensajeError,int reintetos)
{
	int retorno = 1;
	char array[64];
	int i;

	if(palabra != NULL && mensaje != NULL && mensajeError != NULL && reintetos >  0)
	{
		for(i=0;i<reintetos;i++)
		{
			if(!utn_getString(array, mensaje, mensajeError))
			{

				if(!utn_validarLetra(array))
				{
					strcpy(palabra,array);
					retorno =0;
					break;
				}
				else
				{
					printf("%s",mensajeError);
				}
			}
		}
	}

	return retorno;
}
/** \brief Obtiene solo una letra
 *
 * \param *letra retorno de string.
 * \param *mensaje que se muestrar al pedir datos.
 * \param *mensajeError mensaje cuando se carga incorectamente.
 * \param reintentos reintento al obtener entero.
 * \return 1 si funciono correctamente
 *
 */
int utn_getSoloUnaLetra(char* letra,char* mensaje,char* mensajeError,int reintentos)
{
	int retorno = 0;
	char bufferLetra;

	if(letra != NULL && mensaje != NULL && mensajeError != NULL && reintentos > 0)
	{
		for(int i = 0;i < reintentos;i++)
		{


			if(utn_getLetra(&bufferLetra,mensaje,mensajeError))
			{

				if(utn_validarLetra(&bufferLetra))
				{

					*letra=bufferLetra;
					retorno =1;
					break;
				}
				else
				{
					printf("%s",mensajeError);
				}
			}
		}
	}

	return retorno;
}
/** \brief Obtine f y m.
 *
 * \param *letra retorno de sexo.
 * \param *mensaje que se muestrar al pedir datos.
 * \param *mensajeError mensaje cuando se carga incorectamente.
 * \param reintentos reintento al obtener entero.
 * \return 1 si funciono correctamente
 *
 */
int utn_getSexo(char* letra,char* mensaje,char* mensajeError,int reintentos)
{
	int retorno = 0;
	char bufferLetra;

	if(letra != NULL && mensaje != NULL && mensajeError != NULL && reintentos > 0)
	{
		for(int i=0;i<reintentos;i++)
		{
			if(utn_getLetra(&bufferLetra, mensaje, mensajeError))
			{
				if(utn_validarSexo(&bufferLetra))
				{
					*letra=bufferLetra;
					retorno =1;
					break;
				}
				else
				{
					printf("%s",mensajeError);
				}
			}
		}
	}

	return retorno;
}

int utn_PrimerLetraMayuscula(char* string)
{
	int retorno = 0;
	int i=0;

	if(string != NULL)
	{

		while(string[i] != '\0')
		{

			if(retorno == 0)
			{
				string[i]=toupper(string[i]);
			}
			else
			{
				string[i]=tolower(string[i]);
			}

			retorno=1;
			i++;
		}
	}
	return retorno;
}
int utn_getStringEntreOpciones2(char* string,char* opcion1,char* opcion2,char* mensaje,char* mensajeError,int reintentos)
{
	int retorno = 1;

	int opcion;


		if(string != NULL && opcion1 != NULL && opcion2 != NULL && mensaje != NULL && mensajeError != NULL)
		{
			printf("1)%s\n2)%s\n",opcion1,opcion2);

			for(int i=0;i<reintentos;i++)
			{

				if(!utn_getSoloNumeroEntero(&opcion, mensaje, mensajeError, reintentos))
				{
					switch(opcion)
					{
						case 1:
							strcpy(string,opcion1);
							retorno = 0;
							break;
						case 2:
							strcpy(string,opcion2);
							retorno = 0;
							break;
						default:
							printf("%s",mensajeError);
					}
				}

				if(retorno == 0)
				{
					break;
				}
			}

		}
		return retorno;
}
int utn_getStringEntreOpciones3(char* string,char* opcion1,char* opcion2, char* opcion3,char* mensaje,char* mensajeError,int reintentos)
{
	int retorno = 0;
	int opcion;


	if(string != NULL && opcion1 != NULL && opcion2 != NULL && opcion3 != NULL && mensaje != NULL && mensajeError != NULL)
	{
		printf("1)%s\n2)%s\n3)%s\n",opcion1,opcion2,opcion3);

		for(int i=0;i<reintentos;i++)
		{

			if(utn_getSoloNumeroEntero(&opcion, mensaje, mensajeError, reintentos))
			{
				switch(opcion)
				{
					case 1:
						strcpy(string,opcion1);
						retorno = 1;
						break;
					case 2:
						strcpy(string,opcion2);
						retorno = 1;
						break;
					case 3:
						strcpy(string,opcion3);
						retorno = 1;
						break;
					default:
						printf("%s",mensajeError);
				}
			}

			if(retorno == 1)
			{
				break;
			}
		}

	}

	return retorno;
}
int utn_getSringConReintentos(char *palabra,char* mensaje,char* mensajeError,int reintetos)
{
	int retorno = 1;
	char bufferPalabra[50];

	if(palabra != NULL && mensaje != NULL && mensajeError != NULL && reintetos > 0)
	{
		for(int i=0;i<reintetos;i++)
		{
			if(!utn_getString(bufferPalabra, mensaje, mensajeError))
			{
				strcpy(palabra,bufferPalabra);
				retorno = 0;
				break;
			}
		}
	}

	return retorno;

}
int utn_getStringConCaracteres(char* string,char* mensaje,char* mensajeError,int cantidadCaracteres)
{
	int retorno = 0;

	if(string != NULL && mensaje != NULL && mensajeError != NULL)
	{
		printf("%s",mensaje);

		fgets(string,cantidadCaracteres,stdin);

			if(string[strlen(string)-1]=='\n')
			{
				string[strlen(string)-1] = '\0';
				retorno = 1;
			}
	}
	else
	{
		printf("%s",mensajeError);
	}


	return retorno;
}
int utn_getStringConMaximoCaracteres(char* string,char* mensaje,char* mensajeError,int cantidadCaracteres, int reitnetos)
{
	int retono=0;
	char BufferSring[cantidadCaracteres];

	if(string != NULL && mensaje != NULL && cantidadCaracteres > 1 && reitnetos > 0)
	{
		for(int i=0;i<reitnetos;i++)
		{
			if(utn_getStringConCaracteres(BufferSring, mensaje, mensajeError, cantidadCaracteres))
			{
				if(utn_PrimerLetraMayuscula(BufferSring))
				{
					strcpy(string,BufferSring);
					retono=1;
					break;
				}

			}
		}
	}

	return retono;
}
int utn_getSoloStringConMaximoCaracteres(char* string,char* mensaje,char* mensajeError,int cantidadCaracteres,int reintentos)
{
	int retorno = 0;
	char BufferSring[cantidadCaracteres];

	if(string != NULL && mensaje != NULL && cantidadCaracteres > 1 && reintentos > 0)
	{
		for(int i=0;i<reintentos;i++)
		{
			if(utn_getStringConCaracteres(BufferSring, mensaje, mensajeError, cantidadCaracteres))
			{
				if(utn_validarLetra(BufferSring))
				{
					if(utn_PrimerLetraMayuscula(BufferSring))
					{
						strcpy(string,BufferSring);
						retorno=1;
						break;
					}
				}

			}
			printf(mensajeError);
		}
	}

	return retorno;
}

int utn_getStringNumeroChar(char* string,char* mensaje,char* mensajeError,int reintentos)
{
	char buffer[100];
	int retorno = 1;

	if(string != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		for(int i=0;i<reintentos;i++)
		{
			if(!utn_getString(buffer, mensaje, mensajeError))
			{
				if(!utn_validarNumero(buffer))
				{
					strcpy(string,buffer);
					retorno = 0;
					break;
				}else
				{
					printf("%s",mensajeError);
				}
			}
		}
	}

	return retorno;
}


int utn_getStringFloatChar(char* string,char* mensaje,char* mensajeError,int reintentos)
{
	char buffer[100];
	int retorno = 1;

	if(string != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		for(int i=0;i<reintentos;i++)
		{
			if(!utn_getString(buffer, mensaje, mensajeError))
			{
				if(!utn_validarFloat(buffer))
				{
					strcpy(string,buffer);
					retorno = 0;
					break;
				}else
				{
					printf("%s",mensajeError);
				}
			}
		}
	}

	return retorno;
}

