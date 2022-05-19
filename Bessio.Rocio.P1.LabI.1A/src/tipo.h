
#ifndef TIPO_H_
#define TIPO_H_

typedef struct{

	int idTipo;

	char descripcion[20];

}eTipo;

#endif /* TIPO_H_ */

///@brief	VALIDA LA EXISTENCIA DEL ID INGRESADO
///@param vec [] eTipo array de estructura
///@param tam int tamanio del array
///@param id int id recibida
///@return int 1 si los parametros son valios o 0 si Invalido
int validarTipo(eTipo vec[], int tam, int id);

///@brief	CARGA LA DESCRIPCION DE LA ESTRUCTURA
///@param vec [] eTipo array de estructura
///@param tam int tamanio del array
///@param id int id recibida
///@param descripcion char array de lo que se va a cargar
///@return int 1 si los parametros son valios o 0 si Invalido
int cargarTipoMascota(eTipo vec[],int tam,int id, char descripcion[]);

///@brief	BUSCA EL INDICE DE ESA ID
///@param vec [] eTipo array de estructura
///@param tam int tamanio del array
///@param id int id recibida
///@param pIndex int* id el indice
///@return int 1 si los parametros son valios o 0 si Invalido
int buscarIndiceTipo(eTipo vec[],int tam,int id, int* pIndex);

///@brief	LO QUE HACE ES LISTAR TODO LO QUE HAY DENTRO DE LA ESTRUCTURA TIPO
///@param vec [] eTipo array de estructura
///@param tam int tamanio del array
///@return int 1 si los parametros son valios o 0 si Invalido
int listarTipoMascota(eTipo vec[],int tam);
