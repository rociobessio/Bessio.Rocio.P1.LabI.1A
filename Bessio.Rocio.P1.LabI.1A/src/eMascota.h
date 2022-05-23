//RECORDAR INCLUIR OTRAS BIBLIOTECAS PARA QUE RECONOZCA

#include "eFecha.h"
#include "eColor.h"
#include "tipo.h"
#include "duenio.h"

#ifndef EESTRUCTURA_H_
#define EESTRUCTURA_H_

typedef struct{

	int id;
	int idTipo;
	int idColor;

	char nombre[20];

	char vacunado;
	int edad;

	int idDuenio;

	int isEmpty;
}eMascota;


#endif /* EESTRUCTURA_H_ */


//								ABM

///@brief	INICIALIZA UNA ESTRUCTURA CON IS EMPTY EN 1
///@param lista [] eMascota array de estructura
///@param tam int tamanio del array
///@return int 1 si los parametros son valios o 0 si Invalido
int inicializarEstructura(eMascota lista[],int tam);

///@brief	BUSCA ESPACIO LIBRE EN EL ARRAY Y DEVUELVE -1 SI NO LO HAY
///@param lista [] eMascota array
///@param tam int tamanio del array
///@param pIndex int* puntero de indice de posicion
///@return int 1 si los parametros son valios o 0 si Invalido
int buscarLibre(eMascota lista[],int tam,int* pIndex);

///@brief	BUSCA ALGO MEDIANTE SU ID RECORRIENDO EL ARRAY
///@param lista [] eMascota array
///@param tam int tamanio del array
///@param pIndex int* puntero a lo que utilizaremos como referencia para ver si se encontro y en que posicion
///@param id int id que se busca
///@return int 1 si los parametros son valios o 0 si Invalido
int buscarReferencia(eMascota lista[],int tam,int* pIndex,int id);

///@brief	DA DE ALTA Y SE FIJA QUE NO HAYA OCURRIDO UN PROBLEMA Y USA BUSCAR LIBRE PARA VERIFICAR QUE HAY LUGAR
///@param lista [] eMascota array
///@param tam int tamanio del array
///@param pId int* puntero de id que ira aumentando a medida que se da de alta
///@param colorMascota eColor[] array de colores
///@param tamColor int tamanio del color de mascotas
///@param tipoLista eTipo[] array de tipos de mascotas
///@param tamTipo int tamanio del array de tipo de mascotas
///@return int 1 si los parametros son valios o 0 si Invalido
int alta(eMascota lista[],int tam,int* pId,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo,eDuenio listaDuenio[],int tamDuenio,int* pIdDuenio);

///@brief	DA DE BAJA  Y CAMBIA EL ISEMPTY A 1
///@param lista [] eMascota array
///@param tam int tamanio del array
///@param pId int* puntero de id que se buscara dar de baja
///@param colorMascota eColor[] array de colores
///@param tamColor int tamanio del color de mascotas
///@param tipoLista eTipo[] array de tipos de mascotas
///@param tamTipo int tamanio del array de tipo de mascotas
///@return int 1 si los parametros son valios o 0 si Invalido
int baja(eMascota lista[],int tam,int* pId,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo,eDuenio listaDuenio[],int tamDuenio);

///@brief	SE MODIFICA ALGUN CAMPO DE LA ESTRUCTURA BUSCANDO SU ID
///@param lista [] eMascota array
///@param tam int tamanio del array
///@param pId int* puntero de id que se buscara dar de baja
///@param colorMascota eColor[] array de colores
///@param tamColor int tamanio del color de mascotas
///@param tipoLista eTipo[] array de tipos de mascotas
///@param tamTipo int tamanio del array de tipo de mascotas
///@return int 1 si los parametros son valios o 0 si Invalido
int modificacion(eMascota lista[],int tam,int* pId,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo,eDuenio listaDuenio[],int tamDuenio);

///@brief	HARCODEO PARA FACILITAR LAS COSAS LA IDEA ES NO PERDER TIEMPO ES PARA TESTING
///@param lista [] eMascota array
///@param tam int tamanio del array
///@param pId int* puntero de id que ira aumentando por cada vuelta
///@param cant int cantidad que enviamos desde main que queremos hardcodear
///@return int 1 si los parametros son valios o 0 si Invalido
int hardcodeo(eMascota lista[],int tam,int* pId,int cant);

int cargarNombreMascota(eMascota vec[],int tam,int id, char descripcion[]);

///							MOSTRAR

///@brief	LISTA TODO EL ARRAY
///@param lista [] eMascota array
///@param tam int tamanio del array
///@param colorMascota eColor[] array de colores
///@param tamColor int tamanio del color de mascotas
///@param tipoLista eTipo[] array de tipos de mascotas
///@param tamTipo int tamanio del array de tipo de mascotas
///@return int 1 si los parametros son valios o 0 si Invalido
int listar(eMascota lista[],int tam,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo,eDuenio listaDuenio[],int tamDuenio);

///@brief	MUESTRA EL CONTENIDO DE UNA POSICION DE LA ESTRUCTURA
///@param lista [] eMascota array
///@param tam int tamanio del array
///@param colorMascota eColor[] array de colores
///@param tamColor int tamanio del color de mascotas
///@param tipoLista eTipo[] array de tipos de mascotas
///@param tamTipo int tamanio del array de tipo de mascotas
///@return int 1 si los parametros son valios o 0 si Invalido
int mostrarUnico(eMascota lista,int tam,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo,eDuenio listaDuenio[],int tamDuenio);

///@brief	HACE UN SORT POR TIPO DE MASCOTA Y NOMBRE DE ESTA
///@param lista [] eMascota array
///@param tam int tamanio del array
///@param colorMascota eColor[] array de colores
///@param tamColor int tamanio del color de mascotas
///@param tipoLista eTipo[] array de tipos de mascotas
///@param tamTipo int tamanio del array de tipo de mascotas
///@return int 1 si los parametros son valios o 0 si Invalido
int sortByTipoYNombre(eMascota lista[],int tam,int* pId,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo,eDuenio listaDuenio[],int tamDuenio);

