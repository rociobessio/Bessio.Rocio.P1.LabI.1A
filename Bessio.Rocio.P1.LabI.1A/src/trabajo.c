
#include "eMascota.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"
#include"eFecha.h"
#include "eColor.h"
#include "tipo.h"

#include "trabajo.h"
#include "servicio.h"




int inicializarEstructuraTrabajo(eTrabajo listaTrabajo[],int tamTrabajo)
{
	int todoOk = -1;

	if(listaTrabajo!=NULL && tamTrabajo>0)
	{
		for(int i=0;i<tamTrabajo;i++)
		{
			listaTrabajo[i].isEmpty = 1;
			todoOk = 1;
		}
	}
	return todoOk;
}


int buscarLibreTrabajo(eTrabajo listaTrabajo[],int tamTrabajo,int* pIndex)
{
	int todoOk = -1;

	if(listaTrabajo!=NULL && tamTrabajo>0 && pIndex!=NULL)
	{
		*pIndex= -1;
		for(int i=0;i<tamTrabajo;i++)
		{
			if(listaTrabajo[i].isEmpty)
			{
				*pIndex = i;
				break;
			}
			todoOk = 1;
		}
	}
	return todoOk;
}

int buscarReferenciaTrabajo(eTrabajo listaTrabajo[],int tamTrabajo,int* pIndex,int id)
{
	int todoOk = -1;

	if(listaTrabajo!=NULL && tamTrabajo>0 && pIndex!=NULL && id>0)
	{
		*pIndex= -1;
		for(int i=0;i<tamTrabajo;i++)
		{
			if(!listaTrabajo[i].isEmpty && listaTrabajo[i].idTrabajo == id)
			{
				*pIndex = i;
				break;
			}
			todoOk = 1;
		}
	}
	return todoOk;
}

int altaTrabajo(eTrabajo listaTrabajo[],int tamTrabajo,int* pIdTrab,eMascota lista[],int tam,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo,eServicio listaServicio[],int tamServ,eDuenio listaDuenio[],int tamDuenio)
{
	int todoOk = -1;

	int indice;
	int indiceMascota;

	eTrabajo trabajoAux;

	if(listaTrabajo!=NULL && tamTrabajo>0 && pIdTrab!=NULL && lista !=NULL && tam>0 && colorMascota!=NULL && tamColor>0 && tipoLista !=NULL && tamTipo>0 && listaServicio!=NULL && tamServ >0)
	{
		printf("\n____________________________________________________________");
		printf("\n                                                            |");
		printf("\n               ALTA   TRABAJO MASCOTA                       |\n");
		printf("____________________________________________________________|\n");
		if(buscarLibreTrabajo(listaTrabajo, tamTrabajo, &indice))
		{
			if(indice==-1)
			{
				showMessage("\nNO HAY MAS ESPACIO EN EL SISTEMA!");
			}
			else
			{
				trabajoAux.idTrabajo = *pIdTrab;
				*pIdTrab = (*pIdTrab)+1;
				//ENTRO Y CARGO
				listar(lista, tam, colorMascota, tamColor, tipoLista, tamTipo,listaDuenio,tamDuenio);

				getValidInt("\nINGRESE ID DE LA MASCOTA: ", "\nVALOR INVALIDO, REINTENTE: ", "\nINGRESE UNICAMENTE NUMEROS", 1, 500000, &trabajoAux.idMascota);
				buscarReferencia(lista, tam, &indiceMascota, trabajoAux.idMascota);

				while(indiceMascota ==-1)//No existe
				{
					getValidInt("\nID INVALIDO REINGRESE: ", "\nVALOR INVALIDO, REINTENTE: ", "\nINGRESE UNICAMENTE NUMEROS", 1, 500000, &trabajoAux.idMascota);
					buscarReferencia(lista, tam, &indiceMascota, trabajoAux.idMascota);
				}

		        listarServicio(listaServicio, tamServ);
				getValidInt("\nINGRESE ID DE SERVICIO: ", "\nVALOR INVALIDO, REINTENTE: ", "\nINGRESE UNICAMENTE NUMEROS", 20000, 20002, &trabajoAux.idServicio);
				while(!validarServicio(listaServicio, tamServ, trabajoAux.idServicio))
				{
					getValidInt("\nINGRESE ID DE SERVICIO: ", "\nVALOR INVALIDO, REINTENTE: ", "\nINGRESE UNICAMENTE NUMEROS",20000, 20002, &trabajoAux.idServicio);

				}

		         printf("\nINGRESE FECHA DE SERVICIO: dd/mm/aaaa: ");//TOMAMOS TRES VARIABLES JUNTAS
		         scanf("%d/%d/%d", &trabajoAux.fechaTrabajo.dia,&trabajoAux.fechaTrabajo.mes,&trabajoAux.fechaTrabajo.anio);
		         while(trabajoAux.fechaTrabajo.anio<1990 || trabajoAux.fechaTrabajo.anio>2023 || trabajoAux.fechaTrabajo.dia<1 || trabajoAux.fechaTrabajo.dia>31 || trabajoAux.fechaTrabajo.mes<1 || trabajoAux.fechaTrabajo.mes>12 )
		         {
			         printf("\nERROR FECHA INVALIDA, REINGRESE FECHA DE SERVICIO: dd/mm/aaaa: ");//TOMAMOS TRES VARIABLES JUNTAS
			         scanf("%d/%d/%d", &trabajoAux.fechaTrabajo.dia,&trabajoAux.fechaTrabajo.mes,&trabajoAux.fechaTrabajo.anio);
		         }

				//CAMBIO EL VALOR DE IS EMPTY
				trabajoAux.isEmpty = 0;

				//ACA VOY A COPIAR TODO LO DEL AUXILIR EN LA ORIGINAL
				listaTrabajo[indice] = trabajoAux;

				todoOk = 0;
			}
		}
		else
		{
			showMessage("\nOCURRIO UN PROBLEMA CON EL SISTEMA!!!!");
		}
	}
	return todoOk;
}



int listarTrabajos(eTrabajo listaTrabajo[],int tamTrabajo,eMascota lista[],int tam,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo,eServicio listaServicio[],int tamServ)
{
	int todoOk = -1;

	int bandera =0;

	char descripcionNombre[20];
	char descripcionServicio[20];

	if(listaTrabajo!=NULL && tamTrabajo>0 && lista!=NULL && tam>0 && colorMascota!=NULL && tamColor>0 && tipoLista!=NULL && tamTipo>0 && listaServicio!=NULL && tamServ>0)
	{
		printf("\n\n");
		//MUESTRO UN ENCABEZADO
		showMessage("|---------------------------------------------------------------------------------------------------------|");
		showMessage("|	                            ***LISTADO DE TRABAJOS***                                             | ");
		showMessage("|---------------------------------------------------------------------------------------------------------|");
		showMessage("|  ID TRABAJO |	         SERVICIO        |	      N. MASCOTA              |       FECHA SERVICIO      |");
		printf("|---------------------------------------------------------------------------------------------------------|\n");
		for(int i = 0;i<tamTrabajo;i++)
		{
			cargarServicio(listaServicio, tamServ, listaTrabajo[i].idServicio, descripcionServicio);
			cargarNombreMascota(lista, tam, listaTrabajo[i].idMascota, descripcionNombre);
			if(!listaTrabajo[i].isEmpty)
			{
				printf("|   %4d      |     %13s        |    	%15s               |  	 %02d/%02d/%02d       |\n",listaTrabajo[i].idTrabajo,
																													descripcionServicio,
																													descripcionNombre,
																													listaTrabajo[i].fechaTrabajo.dia,
																													listaTrabajo[i].fechaTrabajo.mes,
																													listaTrabajo[i].fechaTrabajo.anio);
				bandera=1;
			}
		}
		if(bandera==0)
		{
			showMessage("\nNO HAY TRABAJOS CARGADOS EN EL SISTEMA!");
		}
		printf("|---------------------------------------------------------------------------------------------------------|\n");
		todoOk = 0;
	}
	return todoOk;
}


int hardcodeoTrabajo(eTrabajo listaTrabajo[],int tamTrab,int* pIdTrab,int cant)
{
	int todoOk = -1;

	eTrabajo auxHarcodeo [] = {
			{2000,20000,1,{5,1,2005},0},
			{2001,20001,4,{7,10,2004},0},
			{2002,20002,5,{6,12,2020},0},
			{2003,20003,6,{8,5,1998},0},
			{2004,20000,3,{17,9,2013},0},
			{2005,20001,2,{10,3,2001},0},
			{2006,20001,4,{06,11,2016},0},
			{2007,20002,5,{21,8,1999},0},
	};


	if(listaTrabajo!=NULL && tamTrab>0 && pIdTrab!=NULL && cant>0 && cant<=tamTrab )
	{
		for(int i=0;i<cant;i++)
		{
			listaTrabajo[i] = auxHarcodeo[i];
			listaTrabajo[i].idTrabajo = *pIdTrab;
			*pIdTrab = (*pIdTrab)+1;
		}
		todoOk = 0;
	}
	return todoOk;
}
