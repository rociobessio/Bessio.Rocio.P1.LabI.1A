
#include "servicio.h"
#include "eMascota.h"
#include "eFecha.h"

#ifndef TRABAJO_H_
#define TRABAJO_H_

typedef struct{

	int idTrabajo;
	int idServicio;
	int idMascota;

	eFecha fechaTrabajo;

	int isEmpty;

}eTrabajo;

#endif /* TRABAJO_H_ */

///@brief	INICIALIZA LA ESTRUCTURA DE TRABAJO CON IS EMPTY EN 1
///@param listaTrabajo [] eTrabajo array de estructura
///@param tamTrabajo int tamanio del array
///@return int 1 si los parametros son valios o 0 si Invalido
int inicializarEstructuraTrabajo(eTrabajo listaTrabajo[],int tamTrabajo);

///@brief	BUSCA ESPACIO LIBRE EN EL ARRAY DE TRABAJO Y DEVUELVE -1 SI NO LO HAY
///@param listaTrabajo [] eTrabajo array
///@param tamTrabajo int tamanio del array de trabajo
///@param pIndex int* puntero de indice de posicion
///@return int 1 si los parametros son valios o 0 si Invalido
int buscarLibreTrabajo(eTrabajo listaTrabajo[],int tamTrabajo,int* pIndex);

///@brief	BUSCA UNA ID DE TRABAJO
///@param listaTrabajo [] eTrabajo array
///@param tamTrabajo int tamanio del array
///@param pIndex int* puntero a lo que utilizaremos como referencia para ver si se encontro y en que posicion
///@param id int id que se busca
///@return int 1 si los parametros son valios o 0 si Invalido
int buscarReferenciaTrabajo(eTrabajo listaTrabajo[],int tamTrabajo,int* pIndex,int id);

///@brief	DA DE ALTA Y SE FIJA QUE NO HAYA OCURRIDO UN PROBLEMA Y USA BUSCAR LIBRE PARA VERIFICAR QUE HAY LUGAR
///@param lista [] eMascota array de mascotas
///@param tam int tamanio del array de mascotas
///@param lislistaTrabajota [] eTrabajo array de trabajo
///@param tamTrabajo int tamanio del array de trabajo
///@param pIdTrab int* puntero de id de trabajo que ira aumentando a medida que se da de alta
///@param colorMascota eColor[] array de colores
///@param tamColor int tamanio del color de mascotas
///@param tipoLista eTipo[] array de tipos de mascotas
///@param tamTipo int tamanio del array de tipo de mascotas
///@return int 1 si los parametros son valios o 0 si Invalido
int altaTrabajo(eTrabajo listaTrabajo[],int tamTrabajo,int* pIdTrab,eMascota lista[],int tam,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo,eServicio listaServicio[],int tamServ,eDuenio listaDuenio[],int tamDuenio);
///@brief	LISTA TODO EL ARRAY DE TRABAJO
///@param listaTrabajo [] eTrabajo array
///@param tamTrabajo int tamanio del array
///@return int 1 si los parametros son valios o 0 si Invalido
int listarTrabajos(eTrabajo listaTrabajo[],int tamTrabajo,eMascota lista[],int tam,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo,eServicio listaServicio[],int tamServ);
///@brief	HARCODEO PARA FACILITAR LAS COSAS LA IDEA ES NO PERDER TIEMPO ES PARA TESTING
///@param listaTrabajo [] eTrabajo array
///@param tamTrab int tamanio del array
///@param pIdTrab int* puntero de id que ira aumentando por cada vuelta
///@param cant int cantidad que enviamos desde main que queremos hardcodear
///@return int 1 si los parametros son valios o 0 si Invalido
int hardcodeoTrabajo(eTrabajo listaTrabajo[],int tamTrab,int* pIdTrab,int cant);
