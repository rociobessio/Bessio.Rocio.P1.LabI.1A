

#ifndef DUENIO_H_
#define DUENIO_H_

typedef struct{

	int idDuenio;

	char nombreDue[25];
	char apellidoDue[25];
	char sexo;
	int isEmpty;

}eDuenio;

#endif /* DUENIO_H_ */

int hardcodeoDuenio(eDuenio lista[],int tam,int* pId,int cant);

int cargarVectorNombreDuenio(eDuenio listaDuenio[],int tam,int id, char descripcion[]);

int altaDuenio(eDuenio listaDuenio[],int tam,int* pId);

int buscarReferenciaDuenio(eDuenio listaDuenio[],int tam,int* pIndex,int id);

int buscarLibreDuenio(eDuenio listaDuenio[],int tam,int* pIndex);

int listarDuenios(eDuenio listaDuenio[],int tam);

int inicializarEstructuraDuenio(eDuenio listaDuenio[],int tam);
