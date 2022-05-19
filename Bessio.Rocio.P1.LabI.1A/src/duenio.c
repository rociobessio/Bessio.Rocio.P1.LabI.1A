
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "eMascota.h"
#include  "utn.h"
#include "eFecha.h"
#include "eColor.h"
#include "tipo.h"

#include "trabajo.h"
#include "servicio.h"


#include "duenio.h"



int listarDuenios(eDuenio listaDuenio[],int tam)
{
	int todoOk = -1;

	int bandera =0;

	if(listaDuenio!=NULL && tam>0)
	{

		printf("\n\n\n\n");
		showMessage("--------------------------------------------------------------------------|");
		showMessage("			 ***LISTADO DE DUENIOS***                         | ");
		printf("|-------------------------------------------------------------------------|\n");
		showMessage("|  ID    |	    NOMBRE      |	APELLIDO        |   SEXO          |");
		printf("|-------------------------------------------------------------------------|\n");

		for(int i = 0;i<tam;i++)
		{
			if(!listaDuenio[i].isEmpty)
			{
				printf("| %4d   |        %10s    |          %10s   |     %c           |\n",listaDuenio[i].idDuenio,
																						listaDuenio[i].nombreDue,
																						listaDuenio[i].apellidoDue,
																						listaDuenio[i].sexo);
				bandera=1;
			}
		}
		if(bandera==0)
		{
			showMessage("\nNO HAY NADA CARGADO EN EL SISTEMA!");
		}
		printf("|-------------------------------------------------------------------------|\n");


		todoOk = 0;
	}
	return todoOk;
}



int inicializarEstructuraDuenio(eDuenio listaDuenio[],int tam)
{
	int todoOk = -1;

	if(listaDuenio!=NULL && tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			listaDuenio[i].isEmpty = 1;

			todoOk = 1;
		}
	}
	return todoOk;
}


int buscarLibreDuenio(eDuenio listaDuenio[],int tam,int* pIndex)
{
	int todoOk = -1;

	if(listaDuenio!=NULL && tam>0 && pIndex!=NULL)
	{
		*pIndex= -1;
		for(int i=0;i<tam;i++)
		{
			if(listaDuenio[i].isEmpty)
			{
				*pIndex = i;
				break;
			}
			todoOk = 1;
		}
	}
	return todoOk;
}

int buscarReferenciaDuenio(eDuenio listaDuenio[],int tam,int* pIndex,int id)
{
	int todoOk = -1;

	if(listaDuenio!=NULL && tam>0 && pIndex!=NULL && id>0)
	{
		*pIndex= -1;
		for(int i=0;i<tam;i++)
		{
			if(!listaDuenio[i].isEmpty && listaDuenio[i].idDuenio == id)
			{
				*pIndex = i;
				break;
			}

		}
		todoOk = 1;
	}
	return todoOk;
}

int altaDuenio(eDuenio listaDuenio[],int tam,int* pId)
{
	int todoOk = -1;

	int indice;

	eDuenio auxDuenio;

	char auxCad[25];
	char auxChar;

	//SE CREA UNA VARIABLE AUXILIAR

	if(listaDuenio!=NULL && tam>0 && pId!=NULL)
	{
		printf("\n____________________________________________________________");
		printf("\n                                                            |");
		printf("\n               ALTA     DUENIO                              |\n");
		printf("____________________________________________________________|\n");
		if(buscarLibreDuenio(listaDuenio, tam, &indice))
		{
			if(indice==-1)
			{
				showMessage("\nNO HAY MAS ESPACIO EN EL SISTEMA!");
			}
			else
			{
				//ENTRO Y CARGO


				getValidString("\nINGRESE NOMBRE DEL DUENIO: ", "\nUNICAMENTE LETRAS: ", "\nRANGO INVALIDO REINTENTE. ", auxCad, 3, 24);
				strupr(auxCad);
				strcpy(auxDuenio.nombreDue,auxCad);

				getValidString("\nINGRESE APELLIDO DEL DUENIO: ", "\nUNICAMENTE LETRAS: ", "\nRANGO INVALIDO REINTENTE. ", auxCad, 3, 24);
				strupr(auxCad);
				strcpy(auxDuenio.apellidoDue,auxCad);

				printf("\nINGRESA SEXO DEL DUENIO (F/M): ");
				fflush(stdin);
				scanf("%c",&auxChar);
				auxChar = toupper(auxChar);
				while(auxChar!='F' && auxChar!='M')
				{
					printf("\nINVALIDO REINGRESE SEXO DEL DUENIO (F/M): ");
					fflush(stdin);
					scanf("%c",&auxChar);
					auxChar = toupper(auxChar);
				}
				auxDuenio.sexo = auxChar;

				//CAMBIO EL VALOR DE IS EMPTY
				auxDuenio.isEmpty = 0;

				//AUMENTO SU ID:
				auxDuenio.idDuenio = *pId;
				*pId = (*pId)+1;

				//ACA VOY A COPIAR TODO LO DEL AUXILIR EN LA ORIGINAL
				listaDuenio[indice] = auxDuenio;

				todoOk =1;
			}
		}
		else
		{
			showMessage("\nOCURRIO UN PROBLEMA CON EL SISTEMA!");
		}
	}
	return todoOk;
}





int hardcodeoDuenio(eDuenio lista[],int tam,int* pId,int cant)
{
	int todoOk = -1;

	eDuenio auxHarcodeo [] = {
			{0000,"MARIA","ESTEVANEZ",'F',0},
			{0000,"JUANA","REPETTO",'F',0},
			{0000,"MARTIN","GONZALES",'M',0},
			{0000,"MARCOS","ACUNIA",'M',0},
			{0000,"ROCCO","BESSIO",'M',0},
			{0000,"MARIANA","SINNESS",'F',0},
			{0000,"PABLO","KLOPP",'M',0},
			{0000,"DIEGO","TE",'M',0}

	};//ID NOM APE SEX EMP


	if(lista!=NULL && tam>0 && pId!=NULL && cant>0 && cant<=tam )
	{
		for(int i=0;i<cant;i++)
		{
			lista[i] = auxHarcodeo[i];
			lista[i].idDuenio = *pId;
			*pId = *pId+1;
		}
		todoOk = 0;
	}


	return todoOk;
}

int cargarVectorNombreDuenio(eDuenio listaDuenio[],int tam,int id, char descripcion[])
{
	int todoOk =-1;

	int indice;
	//ACA SE LLAMA A BUSCAR: Y SE PASA EL INDICE
	buscarReferenciaDuenio(listaDuenio, tam, &indice,id);

	if(listaDuenio!=NULL && tam>0 && descripcion!=NULL && indice!=-1)
	{
		for(int i=0;i<tam;i++)
		{
			strcpy(descripcion,listaDuenio[indice].nombreDue);
			todoOk =0;
		}
	}
	return todoOk;
}
