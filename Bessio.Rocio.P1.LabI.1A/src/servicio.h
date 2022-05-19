

#ifndef SERVICIO_H_
#define SERVICIO_H_

typedef struct{

	int idServicio;
	char descripcion[20];
	float precio;

}eServicio;

#endif /* SERVICIO_H_ */

///@brief	LO QUE HACE ES LISTAR TODO LO QUE HAY DENTRO DE LA ESTRUCTURA SERVICIO
///@param vecServicio [] eServicio array de estructura
///@param tam int tamanio del array
///@return int 1 si los parametros son valios o 0 si Invalido
int listarServicio(eServicio vecServicio[],int tam);

///@brief	BUSCA EL INDICE DE ESA ID DE SERVICIO
///@param vecServicio [] eServicio array de estructura
///@param tam int tamanio del array
///@param id int id recibida
///@param pIndex int* id el indice
///@return int 1 si los parametros son valios o 0 si Invalido
int buscarIndiceServicio(eServicio vecServicio[],int tam,int id, int* pIndex);

///@brief	CARGA LA DESCRIPCION DE LA ESTRUCTURA SERVICIO
///@param vecServicio [] eServicio array de estructura
///@param tam int tamanio del array
///@param id int id recibida
///@param descripcion char array de lo que se va a cargar
///@return int 1 si los parametros son valios o 0 si Invalido
int cargarServicio(eServicio vecServicio[],int tam,int id, char descripcion[]);

///@brief	VALIDA LA EXISTENCIA DEL ID INGRESADO DE SERVICIO
///@param vec [] eServicio array de estructura
///@param tam int tamanio del array
///@param id int id recibida
///@return int 1 si los parametros son valios o 0 si Invalido
int validarServicio(eServicio vec[], int tam, int id);
