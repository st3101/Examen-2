/*
 * utn.h
 *
 *  Created on: 15 abr. 2021
 *      Author: santi
 */
#define SRC_UTN_H_
//menu


//principal
int utn_getString(char* string,char* mensaje,char* mensajeError);
int utn_getLetra(char* letra,char* mensaje,char* mensajeError);
int utn_getInt(int* pEntero,char* mensaje,char* mensajeError);
int utn_getfloat(float* pFloat,char* mensaje,char* mensajeError);
int utn_getStringConCaracteres(char* string,char* mensaje,char* mensajeError,int cantidadCaracteres);


//Validaciones
int utn_validarNumero(char* array);
int utn_validarFloat(char* array);
int utn_validarLetra(char* array);
int utn_validarUnaLetra(char* letra);
int utn_validarSexo(char* letra);

//Tranfromaciones
int utn_PrimerLetraMayuscula(char* string);

//Pedida de datos
int utn_getSringConReintentos(char *palabra,char* mensaje,char* mensajeError,int reintetos);
int utn_getSoloNumeroEntero(int* numero,char* mensaje,char* mensajeError,int reintetos);
int utn_getSoloNumeroEnteroMaxMin(int* numero,int max,int min,char* mensaje,char* mensajeError,int reintetos);
int utn_getSoloNumeroFloat(float* numero,char* mensaje,char* mensajeError,int reintetos);
int utn_getSoloNumeroFloatEntreMaxMin(float* numero,int max,int min,char* mensaje,char* mensajeError,int reintetos);
int utn_getSoloLetras(char* palabra,char* mensaje,char* mensajeError,int reintetos);
int utn_getSoloUnaLetra(char* letra,char* mensaje,char* mensajeError,int reintentos);
int utn_getSexo(char* letra,char* mensaje,char* mensajeError,int reintentos);
int utn_getStringEntreOpciones2(char* string,char* opcion1,char* opcion2,char* mensaje,char* mensajeError,int reintentos);
int utn_getStringEntreOpciones3(char* string,char* opcion1,char* opcion2, char* opcion3,char* mensaje,char* mensajeError,int reintentos);
int utn_getStringConMaximoCaracteres(char* string,char* mensaje,char* mensajeError,int cantidadCaracteres, int reitnetos);
int utn_getSoloStringConMaximoCaracteres(char* string,char* mensaje,char* mensajeError,int cantidadCaracteres,int reintentos);
int utn_getStringNumeroChar(char* string,char* mensaje,char* mensajeError,int reintentos);
int utn_getStringFloatChar(char* string,char* mensaje,char* mensajeError,int reintentos);


