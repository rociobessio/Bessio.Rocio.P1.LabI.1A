
#include "eMascota.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "utn.h"
#include"eFecha.h"
#include "eColor.h"
#include "tipo.h"
#include "cliente.h"


int mostrarUnico(eMascota lista,int tam,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo,eCliente listaDuenio[],int tamDuenio)
{
	int todoOk =-1;

	char descripcionColor[50];
	char descripcionTipo[50];
	char descricionNomDuenio[20];

	if(tam>0 && colorMascota!=NULL && tamColor>0 && tipoLista!=NULL &&tamTipo>0 && listaDuenio!=NULL && tamDuenio>0)
	{
		cargarVectorMascotaColor(colorMascota, tamColor, lista.idColor, descripcionColor);
		cargarTipoMascota(tipoLista, tamTipo, lista.idTipo, descripcionTipo);
		cargarVectorNombreDuenio(listaDuenio, tamDuenio, lista.idDuenio, descricionNomDuenio);

		//EN CASO DE TENER OTRAS ENTIDAD SE DEBE DE HACER SU CARGA!
		printf("|%4d | %10s |  %10s    |%10s|         %c       | %2d     |   %10s |\n", lista.id,
																					   lista.nombre,
																					   descripcionTipo,
																					   descripcionColor,
																					   lista.vacunado,
																					   lista.edad,
																					   descricionNomDuenio);
		todoOk = 1;
	}
	return todoOk;
}


int listar(eMascota lista[],int tam,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo,eCliente listaDuenio[],int tamDuenio)
{
	int todoOk = -1;

	int bandera =0;

	if(lista!=NULL && tam>0 && colorMascota!=NULL && tamColor>0 && tipoLista!=NULL &&tamTipo>0 && listaDuenio!=NULL && tamDuenio>0)
	{
		printf("\n\n");
		showMessage("|----------------------------------------------------------------------------------------|");
		showMessage("|			         ***LISTADO DE MASCOTAS***                               | ");
		printf("|----------------------------------------------------------------------------------------|\n");
		showMessage("|  ID |	 NOMBRE    |	TIPO        |   COLOR  |      VACUNADO   | EDAD   | NOM.DUENIO   |");
		printf("|----------------------------------------------------------------------------------------|\n");

		for(int i = 0;i<tam;i++)
		{
			if(!lista[i].isEmpty)
			{
				mostrarUnico(lista[i], tam,colorMascota,tamColor,tipoLista,tamTipo,listaDuenio,tamDuenio);
				bandera=1;
			}
		}
		if(bandera==0)
		{
			showMessage("|                         NO HAY MASCOTAS EN EL SISTEMA                                  |");
		}
		showMessage("|----------------------------------------------------------------------------------------|");

		todoOk = 0;
	}
	return todoOk;
}



int inicializarEstructura(eMascota lista[],int tam)
{
	int todoOk = -1;
	if(lista!=NULL && tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			lista[i].isEmpty = 1;

			todoOk = 1;
		}
	}
	return todoOk;
}


int buscarLibre(eMascota lista[],int tam,int* pIndex)
{
	int todoOk = -1;

	if(lista!=NULL && tam>0 && pIndex!=NULL)
	{
		*pIndex= -1;
		for(int i=0;i<tam;i++)
		{
			if(lista[i].isEmpty)
			{
				*pIndex = i;
				break;
			}
			todoOk = 1;
		}
	}
	return todoOk;
}

int buscarReferencia(eMascota lista[],int tam,int* pIndex,int id)
{
	int todoOk = -1;

	if(lista!=NULL && tam>0 && pIndex!=NULL && id>0)
	{
		*pIndex= -1;
		for(int i=0;i<tam;i++)
		{
			if(!lista[i].isEmpty && lista[i].id == id)
			{
				*pIndex = i;
				break;
			}
			todoOk = 1;
		}
	}
	return todoOk;
}


int cargarNombreMascota(eMascota vec[],int tam,int id, char descripcion[])
{
	int todoOk =-1;

	int indice;
	//ACA SE LLAMA A BUSCAR: Y SE PASA EL INDICE PARA CARGAR EL NOMBRE DE LA MASCOTA SIEMPRE QUE SE NECESITE
	buscarReferencia(vec, tam, &indice, id);

	if(vec!=NULL && tam>0 && descripcion!=NULL && indice!=-1)
	{
		for(int i=0;i<tam;i++)
		{
			strcpy(descripcion,vec[indice].nombre);
			todoOk =0;
		}
	}
	return todoOk;
}


int alta(eMascota lista[],int tam,int* pId,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo,eCliente listaDuenio[],int tamDuenio,int* pIdDuenio)
{
	int todoOk = 0;

	int indice;

	char auxCad[50];
	int auxInt;
	int indiceDuenio;

	char confirmacion;

	eMascota auxMascota;

	if(lista!=NULL && tam>0 && pId!=NULL && colorMascota!=NULL && tamColor>0 && tipoLista!=NULL && tamTipo>0 && listaDuenio!=NULL && tamDuenio>0)
	{
		printf("\n____________________________________________________________");
		printf("\n                                                            |");
		printf("\n               ALTA     MASCOTAS                            |\n");
		printf("____________________________________________________________|\n");
		if(buscarLibre(lista, tam, &indice))
		{
			if(indice==-1)
			{
				showMessage("\n           NO HAY MAS ESPACIO EN EL SISTEMA!");
			}
			else
			{
				//YA ENTRE, AUMENTO ID
				auxMascota.id=*pId;
				(*pId)++;

				//NOMBRE
				getValidString("INGRESE NOMBRE DE LA MASCOTA: ", "\nERROR UNICAMENTE LETRAS: ", "\nINGRESE EN UN RANGO VALIDO: ", auxCad, 2, 20);
				strupr(auxCad);
				strcpy(auxMascota.nombre,auxCad);

				//COLOR
				listarColor(colorMascota, tamColor);
				getValidInt("\nINGRESE EL COLOR DE LA MASCOTA: ", "\nINGRESE UNA ID VALIDA.", "\nINGRESE UNICAMENTE NUMEROS: ", 5000, 5004, &auxInt);
				auxMascota.idColor = auxInt;

				//TIPO
				listarTipoMascota(tipoLista, tamTipo);
				getValidInt("\nINGRESE EL TIPO DE MASCOTA: ", "\nESA ID NO ES VALIDA.", "\nINGRESE NUMEROS UNICAMENTE: ", 1000, 1004, &auxInt);
				auxMascota.idTipo = auxInt;

				//VACUNADO
				getUserConfirmation(&confirmacion, "\nESTA VACUNADO (S/N): ", "\nVALOR INVALIDO,INGRESE (S/N): ");
				confirmacion = toupper(confirmacion);
				auxMascota.vacunado = confirmacion;

				//EDAD
				getValidInt("\nINGRESE LA EDAD DE LA MASCOTA: ", "\nINGRESE UN VALOR VALIDO ", "\nINGRESE NUMEROS UNICAMENTE: ", 1, 20, &auxInt);
				auxMascota.edad = auxInt;

				//DUENIO (PREGUNTO SI ESTA EN LA LISTA, SI NO LO ENVIO A QUE DE SU ALTA)
				listarDuenios(listaDuenio, tamDuenio);
				getUserConfirmation(&confirmacion, "\nESTA EL DUENIO DENTRO DE LA LISTA (S/N)?", "\nINGRESE VALOR VALIDO S/N");
				if(confirmacion=='s')
				{
					getValidInt("\nINGRESE ID DEL DUENIO AL QUE SE LE ASIGNA LA MASCOTA: ", "\nVALOR INVALIDO, REINTENTE.", "\nUNICAMENTE NUMEROS", 6000, 9000, &auxInt);
					while(!buscarReferenciaDuenio(listaDuenio, tam, &indiceDuenio, auxInt))
					{
						getValidInt("\nID NO ENCONTRADO EN EL SISTEMA, REINTENTE:  ", "\nVALOR INVALIDO, REINTENTE.", "\nUNICAMENTE NUMEROS", 6000, 9000, &auxInt);
					}
					auxMascota.idDuenio = auxInt;
				}
				else
				{
					altaDuenio(listaDuenio, tamDuenio, pIdDuenio);
					listarDuenios(listaDuenio, tamDuenio);
					getValidInt("\nINGRESE ID DEL DUENIO AL QUE SE LE ASIGNA LA MASCOTA: ", "\nVALOR INVALIDO, REINTENTE.", "\nUNICAMENTE NUMEROS", 6000, 9000, &auxInt);
					while(!buscarReferenciaDuenio(listaDuenio, tam, &indiceDuenio, auxInt))
					{
						getValidInt("\nID NO ENCONTRADO EN EL SISTEMA, REINTENTE:  ", "\nVALOR INVALIDO, REINTENTE.", "\nUNICAMENTE NUMEROS", 6000, 9000, &auxInt);
					}
					auxMascota.idDuenio = auxInt;
				}

				//MASCOTA
				//CAMBIO EL VALOR DE IS EMPTY
			    auxMascota.isEmpty = 0;

			    //ACA VOY A COPIAR TODO LO DEL AUXILIR EN LA ORIGINAL
				lista[indice] = auxMascota;

				todoOk = 1;
			}
		}
		else
		{
			showMessage("\nOCURRIO UN PROBLEMA CON EL SISTEMA!!\n");
		}
	}
	return todoOk;
}

int baja(eMascota lista[],int tam,int* pId,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo,eCliente listaDuenio[],int tamDuenio)
{
	int todoOk;

	int indice;
	int idBuscada;

	char confirmacion;

	if(lista!=NULL && tam>0 && pId!=NULL && colorMascota!=NULL && tamColor>0 && tipoLista!=NULL && tamTipo>0 && listaDuenio!=NULL && tamDuenio>0)
	{
		printf("\n____________________________________________________________");
		printf("\n                                                            |");
		printf("\n               BAJA         MASCOTAS                        |\n");
		printf("____________________________________________________________|\n");
		//SE MUESTRA LA LISTA
		listar(lista, tam,colorMascota,tamColor,tipoLista,tamTipo,listaDuenio,tamDuenio);
		// SE PIDE LA ID A BUSCAR
		getValidInt("\nINGRESE LA ID A BUSCAR: ", "\nINGRESE UN VALOR VALIDO: ", "\nINGRESE NUMEROS UNICAMENTE: ", 1, 2000, &idBuscada);

		if(buscarReferencia(lista, tam, &indice, idBuscada))
		{
			if(indice==-1)
			{
				printf("\nNO SE ENCONTRO A NINGUNA MASCOTA CON ID Nº%d\n",idBuscada);
			}
			else
			{
				printf("\n\n");
				showMessage("|----------------------------------------------------------------------------------------|");
				showMessage("|			         ***LISTADO DE MASCOTAS***                               | ");
				printf("|----------------------------------------------------------------------------------------|\n");
				showMessage("|  ID |	 NOMBRE    |	TIPO        |   COLOR  |      VACUNADO   | EDAD   | NOM.DUENIO   |");
				printf("|----------------------------------------------------------------------------------------|\n");
				mostrarUnico(lista[indice], tam,colorMascota,tamColor,tipoLista,tamTipo,listaDuenio,tamDuenio);
				printf("|----------------------------------------------------------------------------------------|\n");

				getUserConfirmation(&confirmacion, "\nDESEA DAR DE BAJA A LA MASCOTA (S/N)? ", "\nINGRESE VALOR VALIDO (S/N)? ");
				if(confirmacion =='s')
				{
					lista[indice].isEmpty = 1; //DEBE DE ESTAR EN 1
					printf("\nBAJA REALIZADA CON EXITO!\n");
				}
				else
				{
					printf("\nBAJA CANCELADA!\n");
				}
				todoOk=1;
			}
		}
	}
	return todoOk;
}

int modificacion(eMascota lista[],int tam,int* pId,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo,eCliente listaDuenio[],int tamDuenio)
{
	int todoOk;

	int indice;

	int idBuscada;

	char confirma;

	char opcion;

	int auxiliarMasco;

	if(lista!=NULL && tam>0 && pId!=NULL && colorMascota!=NULL && tamColor>0 && tipoLista!=NULL && tamTipo>0 && listaDuenio!=NULL && tamDuenio>0)
	{
		printf("\n____________________________________________________________");
		printf("\n                                                            |");
		printf("\n               MODIFICACION       MASCOTAS                  |\n");
		printf("____________________________________________________________|\n");
		//SE MUESTRA LA LISTA
		listar(lista, tam,colorMascota,tamColor,tipoLista,tamTipo,listaDuenio,tamDuenio);
		// SE PIDE LA ID A BUSCAR
		getValidInt("\nINGRESE LA ID A BUSCAR: ", "\nINGRESE UN VALOR VALIDO: ", "\nINGRESE NUMEROS UNICAMENTE: ", 1, 2000, &idBuscada);

		if(buscarReferencia(lista, tam, &indice, idBuscada))
		{
			if(indice==-1)
			{
				printf("\nNO SE ENCONTRO A NINGUNA MASCOTA CON ID Nº%d \n",idBuscada);
			}
			else
			{
				printf("\n\n");
				showMessage("|----------------------------------------------------------------------------------------|");
				showMessage("|			         ***LISTADO DE MASCOTAS***                               | ");
				printf("|----------------------------------------------------------------------------------------|\n");
				showMessage("|  ID |	 NOMBRE    |	TIPO        |   COLOR  |      VACUNADO   | EDAD   | NOM.DUENIO   |");
				printf("|----------------------------------------------------------------------------------------|\n");
				mostrarUnico(lista[indice], tam,colorMascota,tamColor,tipoLista,tamTipo,listaDuenio,tamDuenio);
				printf("|----------------------------------------------------------------------------------------|\n");
				printf("____________________________");
				printf("\n|A)TIPO                    |\n|"
						"B)VACUNADO                |\n");
				printf("|__________________________|");
				printf("\nINGRESE QUE DESEA MODIFICAR: ");
				fflush(stdin);
				scanf("%c",&opcion);
				opcion= toupper(opcion);
				while(opcion!='A' && opcion!='B')
				{
					printf("\nERROR INGRESE UN VALOR VALIDO A/B: ");
					scanf("%c",&opcion);
				}
				switch(opcion)
				{
					case 'A':
						listarTipoMascota(tipoLista, tamTipo);
						getValidInt("\nINGRESE EL TIPO DE MASCOTA: ", "\nINGRESE UN NUMERO VALIDO: ", "\nINGRESE NUMEROS UNICAMENTE: ", 1000, 10004, &auxiliarMasco);
						getUserConfirmation(&opcion, "\nDESEA REALIZAR LA MODIFICACION DE LA MASCOTA? (S/N): ", "\nINGRESE VALOR VALIDO (S/N): ");
						if(opcion=='s')
						{
							lista[indice].idTipo = auxiliarMasco;
							printf("\nMODIFICACION DE MASCOTA REALIZADA CON EXITO!\n");
						}
						else
						{
							printf("\nMODIFICACION DE MASCOTA CANCELADA!\n");
						}
					break;
					case 'B':
						getUserConfirmation(&confirma, "\nESTA VACUNADO (S/N)?: ", "\nVALOR INVALIDO,INGRESE (S/N): ");
						confirma = toupper(confirma);
						getUserConfirmation(&opcion, "\nDESEA REALIZAR LA MODIFICACION DE LA MASCOTA? (S/N): ", "\nINGRESE VALOR VALIDO (S/N): ");
						if(opcion=='s')
						{
							lista[indice].vacunado = confirma;
							printf("\nMODIFICACION DE MASCOTA REALIZADA CON EXITO!\n");
						}
						else
						{
							printf("\nMODIFICACION DE MASCOTA CANCELADA!\n");
						}
					break;
				}
			todoOk=1;
			}
		}
	}
	return todoOk;
}

int hardcodeo(eMascota lista[],int tam,int* pId,int cant)
{
	int todoOk = -1;

	eMascota auxHarcodeo [] = {
			{000,1000,5002,"SALCHICHA",'S',5,6000,0},
			{000,1001,5001,"MICHI",'N',11,6001,0},
			{000,1002,5000,"NACHO",'S',9,6002,0},
			{000,1004,5003,"LOLA",'N',7,6003,0},
			{000,1000,5001,"SASHA",'S',8,6004,0},
			{000,1001,5000,"PUDDLE",'N',4,6005,0},
			{000,1004,5003,"ROMAN",'S',1,6006,0},
			{000,1002,5001,"CHARLY",'N',13,6007,0},
			{000,1004,5002,"ALMENDRA",'S',8,6008,0}
	};//     ID, TIPO,COLOR,NOMBRE,VACUNADO,EDAD,ISEMPTY


	if(lista!=NULL && tam>0 && pId!=NULL && cant>0 && cant<=tam )
	{
		for(int i=0;i<cant;i++)
		{
			lista[i] = auxHarcodeo[i];
			lista[i].id = *pId;
			*pId = *pId+1;
		}
		todoOk = 0;
	}
	return todoOk;
}

int sortByTipoYNombre(eMascota lista[],int tam,int* pId,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo,eCliente listaDuenio[],int tamDuenio)
{
	int todoOk = -1;
	eMascota auxMascota;

	if(lista!=NULL && tam>0)
	{
		for(int i = 0; i<tam;i++)
		{
			for(int j = i;j<tam;j++)
			{
				if(strcmp(lista[i].nombre,lista[j].nombre)>0)//ASC Z-A
				{
					auxMascota = lista[i];
					lista[i] = lista[j];
					lista[j] = auxMascota;
				}
				else if(strcmp(lista[i].nombre,lista[j].nombre)==0 && lista[i].idTipo>lista[j].idTipo)
				{
					auxMascota = lista[i];
					lista[i] = lista[j];
					lista[j] = auxMascota;
				}
			}
		}
		todoOk=0;
	}
	listar(lista, tam, colorMascota, tamColor, tipoLista, tamTipo,listaDuenio,tamDuenio);
	return todoOk;
}

