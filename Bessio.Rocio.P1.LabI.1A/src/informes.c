
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


///MIS BIBLIOTECAS
#include "eFecha.h"
#include "eColor.h"
#include "tipo.h"
#include "eMascota.h"
#include "servicio.h"
#include "utn.h"
#include "trabajo.h"
#include "cliente.h"

//1
int informeColorSeleccionado(eMascota lista[],int tam,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo,eFecha fecha,eServicio servicioLista[],int tamServicio,eTrabajo listaTrabajo[],int tamTrabajo,eCliente listaDuenio[],int tamDuenio)
{
	int todoOk = -1;

	int opcion;
	int bandera=0;
	char descripcion[25];

	if(lista!=NULL && tam>0 && colorMascota!=NULL && tamColor>0 && tipoLista!=NULL && tamTipo>0 && listaDuenio!=NULL && tamDuenio>0 && servicioLista!=NULL && tamServicio>0 && listaTrabajo!=NULL && tamTrabajo>0)
	{
		printf("\n____________________________________________________________");
		printf("\n                                                            |");
		printf("\n  INFORME COLOR DE MASCOTAS SELECCIONADO                    |\n");
		printf("____________________________________________________________|\n");

		listarColor(colorMascota, tamColor);
		getValidInt("INGRESE COLOR A INFORMAR: ", "\nVALOR INVALIDO REINTENTE: ", "\nUNICAMENTE NUMEROS: ", 5000, 5004, &opcion);
		while(!validarColor(colorMascota, tamColor, opcion))
		{
			getValidInt("\nERROR, INGRESE COLOR A INFORMAR: ", "\nVALOR INVALIDO REINTENTE: ", "\nUNICAMENTE NUMEROS: ", 5000, 5004, &opcion);
		}


		showMessage("|----------------------------------------------------------------------------------------|");
		showMessage("|			         ***LISTADO DE MASCOTAS***                               | ");
		printf("|----------------------------------------------------------------------------------------|\n");
		showMessage("|  ID |	 NOMBRE    |	TIPO        |   COLOR  |      VACUNADO   | EDAD   | NOM.DUENIO   |");
		printf("|----------------------------------------------------------------------------------------|\n");
		for(int i=0;i<tam;i++)
		{
			if(!lista[i].isEmpty && lista[i].idColor == opcion)
			{
				mostrarUnico(lista[i], tam, colorMascota, tamColor, tipoLista, tamTipo, listaDuenio, tamDuenio);
				bandera++;
			}
		}
		if(bandera==1)
		{
			cargarVectorMascotaColor(colorMascota, tamColor, opcion, descripcion);
			printf("\nNO HAY NINGUNA MASCOTA DE COLOR %s",descripcion);
		}
		printf("|----------------------------------------------------------------------------------------|\n");
		todoOk = 0;
	}

	return todoOk;
}

//2
int informeMascotaPromedioVacunadas(eMascota lista[],int tam,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo,eFecha fecha,eServicio servicioLista[],int tamServicio,eTrabajo listaTrabajo[],int tamTrabajo,eCliente listaDuenio[],int tamDuenio)
{
	int todoOk = -1;

	int contadorVacunadas=0;
	int totalMascotas=0;
	float promedio=0;

	int bandera=0;


	if(lista!=NULL && tam>0 && colorMascota!=NULL && tamColor>0 && tipoLista!=NULL && tamTipo>0 && listaDuenio!=NULL && tamDuenio>0 && servicioLista!=NULL && tamServicio>0 && listaTrabajo!=NULL && tamTrabajo>0)
	{
		printf("\n____________________________________________________________");
		printf("\n                                                            |");
		printf("\n      INFORME PROMEDIO MASCOTAS VACUNADAS                   |\n");
		printf("____________________________________________________________|\n");
		//RECORRER LISTA E IR SUMANDO PARA EL TOTAL, DESPUES IF DESCARTA SI ESTA VACUNADO Y AHI CUENTO LUEGO DVIDO EL TOTAL DE MASC X VACUNADOS
		printf("\n\n");
		showMessage("|----------------------------------------------------------------------------------------|");
		showMessage("|			         ***LISTADO DE MASCOTAS***                               | ");
		printf("|----------------------------------------------------------------------------------------|\n");
		showMessage("|  ID |	 NOMBRE    |	TIPO        |   COLOR  |      VACUNADO   | EDAD   | NOM.DUENIO   |");
		printf("|----------------------------------------------------------------------------------------|\n");
		for(int i=0;i<tam;i++)
		{
			if(!lista[i].isEmpty)
			{
				totalMascotas++;
				if(lista[i].vacunado == 'S')
				{
					mostrarUnico(lista[i], tam, colorMascota, tamColor, tipoLista, tamTipo, listaDuenio, tamDuenio);//IMPRIMO LISTA EN J
					contadorVacunadas++;
					bandera++;
				}
			}
		}
		printf("|----------------------------------------------------------------------------------------|\n");

		promedio =(float) totalMascotas/contadorVacunadas;
		if(bandera==0)
		{
			printf("\nNO HAY MASCOTAS VACUNADAS EN EL SISTEMA!");
		}
		else
		{
			printf("\nEL PROMEDIO DE MASCOTAS VACUNADAS ES DE: %.2f",promedio);
			printf("\n");
		}
		todoOk=0;
	}
	return todoOk;
}

//4
int informeMascotasXTipo(eMascota lista[],int tam,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo,eFecha fecha,eServicio servicioLista[],int tamServicio,eTrabajo listaTrabajo[],int tamTrabajo,eCliente listaDuenio[],int tamDuenio)
{
	int todoOk = -1;

	int bandera=0;

	if(lista!=NULL && tam>0 && colorMascota!=NULL && tamColor>0 && tipoLista!=NULL && tamTipo>0 && listaDuenio!=NULL && tamDuenio>0 && servicioLista!=NULL && tamServicio>0 && listaTrabajo!=NULL && tamTrabajo>0)
	{
		printf("\n____________________________________________________________");
		printf("\n                                                            |");
		printf("\n  MOSTRAR LISTA MASCOTAS SEPARADAS POR TIPO                 |\n");
		printf("____________________________________________________________|\n");
		printf("\n");

		for(int i=0;i<tamTipo;i++)//RECORRO TIPO DE MASCOTAS
		{

			showMessage("|----------------------------------------------------------------------------------------|");
			printf("|			  ***LISTADO DE MASCOTAS TIPO %s***                                   ",tipoLista[i].descripcion);
			printf("|----------------------------------------------------------------------------------------|\n");
			showMessage("|  ID |	 NOMBRE    |	TIPO        |   COLOR  |      VACUNADO   | EDAD   | NOM.DUENIO   |");
			printf("|----------------------------------------------------------------------------------------|\n");
			for(int j=0;j<tam;j++)//RECORRO LISTA MASCOTAS
			{
				if(!lista[j].isEmpty && lista[j].idTipo == tipoLista[i].idTipo)
				{
					mostrarUnico(lista[j], tam, colorMascota, tamColor, tipoLista, tamTipo, listaDuenio, tamDuenio);//IMPRIMO LISTA EN J
					bandera=1;
				}
			}
			if(bandera==0)
			{
				printf("|                NO HAY NINGUNA MASCOTA DE ESE TIPO!                             |\n");
			}
			printf("|----------------------------------------------------------------------------------------|\n");
			printf("\n\n");
		}
		todoOk=0;
	}

	return todoOk;
}

//5
int informeCantidadColorYTipo(eMascota lista[],int tam,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo,eFecha fecha,eServicio servicioLista[],int tamServicio,eTrabajo listaTrabajo[],int tamTrabajo,eCliente listaDuenio[],int tamDuenio)
{
	int todoOk = -1;

	int bandera=0;
	int opcionTipo;
	int opcionColor;
	int contador=0;

	if(lista!=NULL && tam>0 && colorMascota!=NULL && tamColor>0 && tipoLista!=NULL && tamTipo>0 && listaDuenio!=NULL && tamDuenio>0 && servicioLista!=NULL && tamServicio>0 && listaTrabajo!=NULL && tamTrabajo>0)
	{
		printf("\n____________________________________________________________");
		printf("\n                                                            |");
		printf("\n  CANTIDAD DE MASCOTAS DE COLOR Y TIPO SELECCIONADO         |\n");
		printf("____________________________________________________________|\n");

		listarColor(colorMascota, tamColor);
		getValidInt("\nINGRESE COLOR A INFORMAR: ", "\nVALOR INVALIDO REINTENTE: ", "\nUNICAMENTE NUMEROS: ", 5000, 5004, &opcionColor);
		while(!validarColor(colorMascota, tamColor, opcionColor))
		{
			getValidInt("\nERROR, INGRESE COLOR A INFORMAR: ", "\nVALOR INVALIDO REINTENTE: ", "\nUNICAMENTE NUMEROS: ", 5000, 5004, &opcionColor);
		}

		listarTipoMascota(tipoLista, tamTipo);
		getValidInt("\nINGRESE EL TIPO A  INFORMAR: ", "\nVALOR INVALIDO REINTENTE: ", "\nUNICAMENTE NUMEROS: ", 1000, 1004, &opcionTipo);
		while(!validarTipo(tipoLista, tamTipo, opcionTipo))
		{
			getValidInt("\nERROR, INGRESE LA MARCA A INFORMAR: ", "\nVALOR INVALIDO REINTENTE: ", "\nUNICAMENTE NUMEROS: ", 1000, 1004, &opcionTipo);
		}
		printf("\n\n");
		showMessage("|----------------------------------------------------------------------------------------|");
		showMessage("|			         ***LISTADO DE MASCOTAS***                               | ");
		printf("|----------------------------------------------------------------------------------------|\n");
		showMessage("|  ID |	 NOMBRE    |	TIPO        |   COLOR  |      VACUNADO   | EDAD   | NOM.DUENIO   |");
		printf("|----------------------------------------------------------------------------------------|\n");
		for(int i=0;i<tam;i++)
		{
			if(!lista[i].isEmpty && lista[i].idColor==opcionColor && lista[i].idTipo==opcionTipo)
			{
				mostrarUnico(lista[i], tam, colorMascota, tamColor, tipoLista, tamTipo, listaDuenio, tamDuenio);
				contador++;
				bandera=1;
			}
		}
		if(bandera==0)
		{
			printf("|           NO HAY MASCOTAS REGISTRADAS CON ESE COLOR y ESE TIPO                         |\n");
			printf("|----------------------------------------------------------------------------------------|\n");
		}
		else
		{
			printf("|----------------------------------------------------------------------------------------|\n");
			printf("\nLA CANTIDAD DE MASCOTAS CON ESE COLOR y ESE TIPO ES DE: %d MASCOTAS\n",contador);
		}

		todoOk=0;
	}
	return todoOk;
}

//6
int informeMasCantidadColor(eMascota lista[],int tam,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo,eFecha fecha,eServicio servicioLista[],int tamServicio,eTrabajo listaTrabajo[],int tamTrabajo,eCliente listaDuenio[],int tamDuenio)
{
	int todoOk = -1;

	int bandera=0;

	int contador[tamTipo];
	int mayorTipoElegido;

	if(lista!=NULL && tam>0 && colorMascota!=NULL && tamColor>0 && tipoLista!=NULL && tamTipo>0 && listaDuenio!=NULL && tamDuenio>0 && servicioLista!=NULL && tamServicio>0 && listaTrabajo!=NULL && tamTrabajo>0)
	{
		printf("\n____________________________________________________________");
		printf("\n                                                            |");
		printf("\n        COLOR DE MASCOTAS MAS ELEGIDA                       |\n");
		printf("____________________________________________________________|\n");
        for(int i=0; i < tamColor; i++){//INICIALIZO TODAS LAS POSICONES EN 0
        	contador[i] = 0;
        }
		for(int i=0;i<tamColor;i++)//RECORRO TAM TIPO
		{
			for(int j=0;j<tam;j++)//RECORRO TAM MASC
			{
				if(!lista[j].isEmpty && lista[j].idColor == colorMascota[i].idColor)
				{
					contador[i]++;
				}
			}
		}

		for(int i=0;i<tamColor;i++)
		{
			if(bandera|| contador[i]>mayorTipoElegido)
			{
				mayorTipoElegido = contador[i];
				bandera=0;
			}
		}

		printf("\nEL COLOR DE MASCOTA MAS ELEGIDA ES: ");
		for(int i=0;i<tamColor;i++)
		{
			if(contador[i] == mayorTipoElegido)
			{
				printf(" - %s",colorMascota[i].descripcion);
			}
		}
		printf("\n\n");

		todoOk=0;
	}


	return todoOk;
}

//7
int informeTrabajoRealizadoMascota(eMascota lista[],int tam,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo,eFecha fecha,eServicio servicioLista[],int tamServicio,eTrabajo listaTrabajo[],int tamTrabajo,eCliente listaDuenio[],int tamDuenio)
{
	int todoOk = -1;

	int idBuscada;
	int indice;
	char descripcion[20];

	int bandera=0;


	if(lista!=NULL && tam>0 && colorMascota!=NULL && tamColor>0 && tipoLista!=NULL && tamTipo>0 && listaDuenio!=NULL && tamDuenio>0 && servicioLista!=NULL && tamServicio>0 && listaTrabajo!=NULL && tamTrabajo>0)
	{
		printf("\n____________________________________________________________");
		printf("\n                                                            |");
		printf("\n        TRABAJOS REALIZADOS A UNA MASCOTA                   |\n");
		printf("____________________________________________________________|\n");

		listar(lista, tam, colorMascota, tamColor, tipoLista, tamTipo, listaDuenio, tamDuenio);
		getValidInt("\nINGRESE LA ID A BUSCAR: ", "\nINGRESE UN VALOR VALIDO: ", "\nINGRESE NUMEROS UNICAMENTE: ", 1, 2000, &idBuscada);
		while(!buscarReferencia(lista, tam, &indice, idBuscada))
		{
			getValidInt("\nID NO ENCONTRADA, REINTENTE: ", "\nINGRESE UN VALOR VALIDO: ", "\nINGRESE NUMEROS UNICAMENTE: ", 1, 2000, &idBuscada);
		}

		printf("\n\n");
		//MUESTRO UN ENCABEZADO
		showMessage("|---------------------------------------------------------------------------------------------------------|");
		showMessage("|	                            ***LISTADO DE TRABAJOS***                                             | ");
		showMessage("|---------------------------------------------------------------------------------------------------------|");
		showMessage("|  ID TRABAJO |	         SERVICIO        |	      ID. MASCOTA              |       FECHA SERVICIO     |");
		printf("|---------------------------------------------------------------------------------------------------------|\n");
		for(int i=0;i<tamTrabajo;i++)
		{
			cargarServicio(servicioLista, tamServicio, listaTrabajo[i].idServicio, descripcion);
			if(!lista[i].isEmpty && !listaTrabajo[i].isEmpty && listaTrabajo[i].idMascota == idBuscada)
			{
				printf("|%6d       |   %15s        |      %4d                           |        %02d/%02d/%02d        |\n",listaTrabajo[i].idTrabajo,
																															descripcion,
																															listaTrabajo->idMascota,
																															listaTrabajo[i].fechaTrabajo.dia,//SIEMPRE EN LA POSICION i SI NO PISA DATOS
																															listaTrabajo[i].fechaTrabajo.mes,
																															listaTrabajo[i].fechaTrabajo.anio);
				bandera=1;
			}
		}
		if(bandera==0)
		{
			printf("|     NO HAY TRABAJOS REALIZADOS A ESA MASCOTA!            |\n");
		}
		printf("|---------------------------------------------------------------------------------------------------------|\n");

		todoOk=0;
	}
	return todoOk;
}

//8
int informeImporteTrabajoMascota(eMascota lista[],int tam,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo,eFecha fecha,eServicio servicioLista[],int tamServicio,eTrabajo listaTrabajo[],int tamTrabajo,eCliente listaDuenio[],int tamDuenio)
{
	int todoOk = -1;

	int idBuscada;
	int indice;
	float acumuladorImportes = 0;


	if(lista!=NULL && tam>0 && colorMascota!=NULL && tamColor>0 && tipoLista!=NULL && tamTipo>0 && listaDuenio!=NULL && tamDuenio>0 && servicioLista!=NULL && tamServicio>0 && listaTrabajo!=NULL && tamTrabajo>0)
	{
		printf("\n____________________________________________________________");
		printf("\n                                                            |");
		printf("\n    SUMA DE IMPORTES REALIZADOS A MASCOTA                   |\n");
		printf("____________________________________________________________|\n");

		listar(lista, tam, colorMascota, tamColor, tipoLista, tamTipo, listaDuenio, tamDuenio);
		getValidInt("\nINGRESE LA ID A BUSCAR: ", "\nINGRESE UN VALOR VALIDO: ", "\nINGRESE NUMEROS UNICAMENTE: ", 1, 2000, &idBuscada);
		while(!buscarReferencia(lista, tam, &indice, idBuscada))
		{
			getValidInt("\nID NO ENCONTRADA, REINTENTE: ", "\nINGRESE UN VALOR VALIDO: ", "\nINGRESE NUMEROS UNICAMENTE: ", 1, 2000, &idBuscada);
		}

    	for(int i=0;i<tamTrabajo;i++) //ES TAM TRABAJO o  TAM SERVICIO?
    	{
    		if(!listaTrabajo[i].isEmpty && listaTrabajo[i].idMascota==idBuscada )
    		{
    			for(int j=0;j<tamServicio;j++)
    			{
    				if(servicioLista[j].idServicio == listaTrabajo[i].idServicio)
    				{
    					acumuladorImportes = servicioLista[j].precio + acumuladorImportes;
    				}
    			}
    		}
    	}
    	if(acumuladorImportes==0)
    	{
    		printf("\nESA MASCOTA NO TIENE IMPORTES!\n");
    	}
    	else
    	{
    		printf("\nEL TOTAL DE IMPORTES DE LA MASCOTA ES DE: $ %.2f\n",acumuladorImportes);
    	}


		todoOk=0;
	}

	return todoOk;
}

//9
int informeTrabajoFecha(eMascota lista[],int tam,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo,eFecha fecha,eServicio servicioLista[],int tamServicio,eTrabajo listaTrabajo[],int tamTrabajo,eCliente listaDuenio[],int tamDuenio)
{
	int todoOk = -1;

	int idBuscada;
	char descripcion[20];
	int bandera=0;


	if(lista!=NULL && tam>0 && colorMascota!=NULL && tamColor>0 && tipoLista!=NULL && tamTipo>0 && listaDuenio!=NULL && tamDuenio>0 && servicioLista!=NULL && tamServicio>0 && listaTrabajo!=NULL && tamTrabajo>0)
	{
		printf("\n____________________________________________________________");
		printf("\n                                                            |");
		printf("\n        SERVICIO ELEGIDO Y FECHA                            |\n");
		printf("____________________________________________________________|\n");

		listarServicio(servicioLista, tamServicio);
		getValidInt("\nINGRESE ID DE SERVICIO: ", "\nVALOR INVALIDO, REINTENTE: ", "\nINGRESE UNICAMENTE NUMEROS", 20000, 20002,  &idBuscada);
		while(!validarServicio(servicioLista, tamServicio, idBuscada))
		{
			getValidInt("\nINGRESE ID DE SERVICIO: ", "\nVALOR INVALIDO, REINTENTE: ", "\nINGRESE UNICAMENTE NUMEROS",20000, 20002,  &idBuscada);
		}
		printf("\n\n");
		//MUESTRO UN ENCABEZADO
		showMessage("|---------------------------------------------------------------------------------------------------------|");
		showMessage("|	                            ***LISTADO DE TRABAJOS***                                             | ");
		showMessage("|---------------------------------------------------------------------------------------------------------|");
		showMessage("|  ID TRABAJO |	         SERVICIO        |	      ID. MASCOTA              |       FECHA SERVICIO     |");
		printf("|---------------------------------------------------------------------------------------------------------|\n");
		for(int i=0;i<tamTrabajo;i++)
		{
			if(!lista[i].isEmpty && !listaTrabajo[i].isEmpty  && listaTrabajo[i].idServicio == idBuscada)
			{
				cargarServicio(servicioLista, tamServicio, listaTrabajo[i].idServicio, descripcion);
				printf("|%6d       |   %15s        |      %4d                           |        %02d/%02d/%02d        |\n",listaTrabajo[i].idTrabajo,
																															descripcion,
																															listaTrabajo->idMascota,
																															listaTrabajo[i].fechaTrabajo.dia,//SIEMPRE EN LA POSICION i SI NO PISA DATOS
																															listaTrabajo[i].fechaTrabajo.mes,
																															listaTrabajo[i].fechaTrabajo.anio);
			bandera++;
			}
		}
	    if(bandera==0)
	    {
	       printf("|    NO SE REALIZO EL SERVICIO %s!       |\n",descripcion);
	    }
		printf("|---------------------------------------------------------------------------------------------------------|\n");


		todoOk=0;
	}
	return todoOk;
}

//10
int informeFechaEspecificaYServicio(eMascota lista[],int tam,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo,eFecha fecha,eServicio servicioLista[],int tamServicio,eTrabajo listaTrabajo[],int tamTrabajo,eCliente listaDuenio[],int tamDuenio)
{
	int todoOk = -1;

	eFecha fechaTrabajoAux;
	int status;

	char descripcion[20];
	int bandera=0;


	if(lista!=NULL && tam>0 && colorMascota!=NULL && tamColor>0 && tipoLista!=NULL && tamTipo>0 && listaDuenio!=NULL && tamDuenio>0 && servicioLista!=NULL && tamServicio>0 && listaTrabajo!=NULL && tamTrabajo>0)
	{
		printf("\n____________________________________________________________");
		printf("\n                                                            |");
		printf("\n  FECHA ELEGIDA Y SERVICIOS ESE DIA                         |\n");
		printf("____________________________________________________________|\n");
        printf("\nINGRESE FECHA DE SERVICIO: dd/mm/aaaa: ");//TOMAMOS TRES VARIABLES JUNTAS
        scanf("%d/%d/%d", &fechaTrabajoAux.dia,&fechaTrabajoAux.mes,&fechaTrabajoAux.anio);

        status = isValidDate(&fechaTrabajoAux);
        while(status!=1)
        {
	         printf("\nERROR REINGRESE FECHA DE SERVICIO VALIDA: dd/mm/aaaa: ");//TOMAMOS TRES VARIABLES JUNTAS
	         scanf("%d/%d/%d", &fechaTrabajoAux.dia,&fechaTrabajoAux.mes,&fechaTrabajoAux.anio);
	         status = isValidDate(&fechaTrabajoAux);
        }

		printf("\n\n");
		//MUESTRO UN ENCABEZADO
		showMessage("|---------------------------------------------------------------------------------------------------------|");
		showMessage("|	                            ***LISTADO DE TRABAJOS***                                             | ");
		showMessage("|---------------------------------------------------------------------------------------------------------|");
		showMessage("|  ID TRABAJO |	         SERVICIO        |	      ID. MASCOTA              |       FECHA SERVICIO     |");
		printf("|---------------------------------------------------------------------------------------------------------|\n");
		for(int i=0;i<tam;i++)
		{
		   if(!lista[i].isEmpty)
		   {
		      if(listaTrabajo[i].fechaTrabajo.dia == fechaTrabajoAux.dia
		         && listaTrabajo[i].fechaTrabajo.mes == fechaTrabajoAux.mes && listaTrabajo[i].fechaTrabajo.anio == fechaTrabajoAux.anio)
		        {
		        	cargarServicio(servicioLista, tamServicio, listaTrabajo[i].idServicio, descripcion);
		        	printf("|%6d       |   %15s        |      %4d                           |        %02d/%02d/%02d        |\n",listaTrabajo[i].idTrabajo,
		        			 																									descripcion,
		        			 																									listaTrabajo->idMascota,
		        			 																									listaTrabajo[i].fechaTrabajo.dia,//SIEMPRE EN LA POSICION i SI NO PISA DATOS
		        			 																									listaTrabajo[i].fechaTrabajo.mes,
		        			 																									listaTrabajo[i].fechaTrabajo.anio);
		        	bandera++;
		        }
		   }
		}
        if(bandera==0)
        {
       	 printf("|    NO SE REALIZARON TRABAJOS EN LA FECHA %02d/%02d/%02d!       |\n",fechaTrabajoAux.dia,fechaTrabajoAux.mes,fechaTrabajoAux.anio);
        }
		printf("|---------------------------------------------------------------------------------------------------------|\n");


		todoOk=0;
	}
	return todoOk;
}
//3
int informeMascotaMenorEdad(eMascota lista[],int tam,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo,eFecha fecha,eServicio servicioLista[],int tamServicio,eTrabajo listaTrabajo[],int tamTrabajo,eCliente listaDuenio[],int tamDuenio)
{
	int todoOk = -1;

	int edadMenor;
	int banderaMayor=0;


	if(lista!=NULL && tam>0 && colorMascota!=NULL && tamColor>0 && tipoLista!=NULL && tamTipo>0 && listaDuenio!=NULL && tamDuenio>0 && servicioLista!=NULL && tamServicio>0 && listaTrabajo!=NULL && tamTrabajo>0)
	{
		printf("\n____________________________________________________________");
		printf("\n                                                            |");
		printf("\n   LA/LAS MASCOTA/S DE MENOR EDAD                           |\n");
		printf("____________________________________________________________|\n");

		for(int i = 0;i<tam;i++)//RECORRE EL ARRAY BUSCANDO ESA EDAD MAYOR
		{	if(!lista[i].isEmpty)
			{
				if(edadMenor>lista[i].edad || !banderaMayor)
				{
					edadMenor = lista[i].edad;
					banderaMayor = 1;
				}
			}
		}
		if(banderaMayor == 0)
		{
			printf("\nNO HAY MASCOTAS CARGADAS EN EL SISTEMA!\n");
		}
		else
		{
			printf("\n\n");
			showMessage("|----------------------------------------------------------------------------------------|");
			showMessage("|			         ***LISTADO DE MASCOTAS***                               | ");
			printf("|----------------------------------------------------------------------------------------|\n");
			showMessage("|  ID |	 NOMBRE    |	TIPO        |   COLOR  |      VACUNADO   | EDAD   | NOM.DUENIO   |");
			printf("|----------------------------------------------------------------------------------------|\n");
			for(int i = 0;i<tam;i++)//RECORRE EL ARRAY IMPRIMIEND EN PANTALLA
			{	if(!lista[i].isEmpty)
				{
					if(lista[i].isEmpty == 0  && lista[i].edad == edadMenor)
					{
						mostrarUnico(lista[i], tam, colorMascota, tamColor, tipoLista, tamTipo, listaDuenio, tamDuenio);
					}
				}
			}
		}
		printf("|----------------------------------------------------------------------------------------|\n");
		todoOk=0;
	}
	return todoOk;
}
