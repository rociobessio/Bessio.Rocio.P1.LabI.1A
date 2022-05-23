

#ifndef DUENIO_H_
#define DUENIO_H_

typedef struct{

	int idDuenio;

	char nombreDue[25];

	char sexo;
	int isEmpty;

}eCliente;

#endif /* DUENIO_H_ */

int hardcodeoDuenio(eCliente lista[],int tam,int* pId,int cant);

int cargarVectorNombreDuenio(eCliente listaDuenio[],int tam,int id, char descripcion[]);

int altaDuenio(eCliente listaDuenio[],int tam,int* pId);

int buscarReferenciaDuenio(eCliente listaDuenio[],int tam,int* pIndex,int id);

int buscarLibreDuenio(eCliente listaDuenio[],int tam,int* pIndex);

int listarDuenios(eCliente listaDuenio[],int tam);

int inicializarEstructuraDuenio(eCliente listaDuenio[],int tam);
