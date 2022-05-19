
#ifndef ECOLOR_H_
#define ECOLOR_H_

typedef struct{
	int idColor;
	char descripcion[20];
}eColor;

#endif /* ECOLOR_H_ */

///@brief	LO QUE HACE ES LISTAR TODO LO QUE HAY DENTRO DE LA ESTRUCTURA COLOR
///@param vec [] eColor array de estructura
///@param tam int tamanio del array
///@return int 1 si los parametros son valios o 0 si Invalido
int listarColor(eColor vec[],int tam);

///@brief	BUSCA EL INDICE DE ESA ID DE COLOR
///@param vec [] eColor array de estructura
///@param tam int tamanio del array
///@param id int id recibida
///@param pIndex int* id el indice
///@return int 1 si los parametros son valios o 0 si Invalido
int buscarIndice(eColor vec[],int tam,int id, int* pIndex);

///@brief	CARGA LA DESCRIPCION DE LA ESTRUCTURA
///@param vec [] eColor array de estructura
///@param tam int tamanio del array
///@param id int id recibida
///@param descripcion char array de lo que se va a cargar
///@return int 1 si los parametros son valios o 0 si Invalido
int cargarVectorMascotaColor(eColor vec[],int tam,int id, char descripcion[]);

///@brief	VALIDA LA EXISTENCIA DEL ID INGRESADO
///@param vec [] eColor array de estructura
///@param tam int tamanio del array
///@param id int id recibida
///@return int 1 si los parametros son valios o 0 si Invalido
int validarColor(eColor vec[], int tam, int id);
