

#ifndef DUENIO_H_
#define DUENIO_H_

typedef struct{

	int idDuenio;

	char nombreDue[25];

	char sexo;
	int isEmpty;

}eCliente;

#endif /* DUENIO_H_ */

///@brief	HARCODEO PARA FACILITAR LAS COSAS LA IDEA ES NO PERDER TIEMPO ES PARA TESTING
///@param lista [] eCliente array
///@param tam int tamanio del array
///@param pId int* puntero de id que ira aumentando por cada vuelta
///@param cant int cantidad que enviamos desde main que queremos hardcodear
///@return int 1 si los parametros son valios o 0 si Invalido
int hardcodeoDuenio(eCliente lista[],int tam,int* pId,int cant);

///@brief	CARGA CON STRING EL NOMBRE DEL DUENIO MEDIANTE SU ID
///@param lista [] eCliente array
///@param tam int tamanio del array
///@param Id int  id de la mascota
///@param descripcion char vector
///@return int 1 si los parametros son valios o 0 si Invalido
int cargarVectorNombreDuenio(eCliente listaDuenio[],int tam,int id, char descripcion[]);

///@brief	DA DE ALTA A UN DUENIO
///@param lista [] eCliente array
///@param tam int tamanio del array
///@param pId int* puntero de id que ira aumentando a medida que se da de alta
///@return int 1 si los parametros son valios o 0 si Invalido
int altaDuenio(eCliente listaDuenio[],int tam,int* pId);

///@brief	BUSCA ALGO MEDIANTE SU ID RECORRIENDO EL ARRAY
///@param listaDuenio [] eCliente array
///@param tam int tamanio del array
///@param pIndex int* puntero a lo que utilizaremos como referencia para ver si se encontro y en que posicion
///@param id int id que se busca
///@return int 1 si los parametros son valios o 0 si Invalido
int buscarReferenciaDuenio(eCliente listaDuenio[],int tam,int* pIndex,int id);

///@brief	BUSCA ESPACIO LIBRE EN EL ARRAY Y DEVUELVE -1 SI NO LO HAY
///@param listaDuenio [] eCliente array
///@param tam int tamanio del array
///@param pIndex int* puntero de indice de posicion
///@return int 1 si los parametros son valios o 0 si Invalido
int buscarLibreDuenio(eCliente listaDuenio[],int tam,int* pIndex);

///@brief	LISTA TODO EL ARRAY
///@param listaDuenio [] eCliente array
///@param tam int tamanio del array
///@return int 1 si los parametros son valios o 0 si Invalido
int listarDuenios(eCliente listaDuenio[],int tam);

///@brief	INICIALIZA UNA ESTRUCTURA CON IS EMPTY EN 1
///@param listaDuenio [] eCliente array de estructura
///@param tam int tamanio del array
///@return int 1 si los parametros son valios o 0 si Invalido
int inicializarEstructuraDuenio(eCliente listaDuenio[],int tam);
