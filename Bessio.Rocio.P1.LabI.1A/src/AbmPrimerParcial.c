/*
 ============================================================================
 Name        : AbmPrimerParcial.c
 Author      : Bessio Rocio
 Division    : 1-A
 Fecha       : 11/05/22
 Tema        : MASCOTAS
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "eMascota.h"
#include  "utn.h"
#include "eFecha.h"
#include "eColor.h"
#include "tipo.h"

#include "trabajo.h"
#include "servicio.h"


#include "duenio.h"
#include "harcodeo.h"


int menu();

int submenu(eMascota lista[],int tam,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo,eFecha fecha,eServicio servicioLista[],int tamServicio,eTrabajo listaTrabajo[],int tamTrabajo,eDuenio listaDuenio[],int tamDuenio);

#define TAM 15 //TAM MASCOTAS

#define TAM_COLOR 5

#define TAM_TIPO 5

#define TAM_TRAB 10

#define TAM_SERV 3

#define TAM_DUE 15

int main(void) {
	setbuf(stdout,NULL);

	char salir = 'n';

	eMascota lista[TAM];

	eColor colorLista[TAM_COLOR] = {
			{5000,"NEGRO"},
			{5001,"BLANCO"},
			{5002,"ROJO"},
			{5003,"GRIS"},
			{5004,"AZUL"}
	};

	eTipo tipoLista[TAM_TIPO] ={
			{1000,"AVE"},
			{1001,"PERRO"},
			{1002,"ROEDOR"},
			{1003,"GATO"},
			{1004,"PEZ"},
	};

	eServicio servicioLista[TAM_SERV] = {
			{20000,"CORTE",450},
			{20001,"DESPARACITADO",800},
			{20002,"CASTRADO",600},

	};

	eTrabajo trabajoLista[TAM_TRAB];

	eDuenio listaDuenio[TAM_DUE];

	eFecha fecha;

	int idInicial = 1;

	int idTrabajoRandom = 2000;

	int idDuenio = 6000;

	int banderaAlta = 1;

	//ACA VA LA INICIALIZACION
	inicializarEstructura(lista, TAM);
	inicializarEstructuraTrabajo(trabajoLista, TAM_TRAB);
	inicializarEstructuraDuenio(listaDuenio, TAM_DUE);

	//HARDCODEOS
//	hardcodeo(lista, TAM, &idInicial, 6);
	harcodearMascotas(lista, TAM, 7, &idInicial);
	hardcodeoTrabajo(trabajoLista, TAM_TRAB, &idTrabajoRandom, 6);
	hardcodeoDuenio(listaDuenio, TAM_DUE, &idDuenio, 7);


	do
	{
		switch(menu())
		{
			case 'A':
				//ALTA
				if(alta(lista, TAM,&idInicial, colorLista,TAM_COLOR,tipoLista,TAM_TIPO,listaDuenio,TAM_DUE,&idDuenio))
				{
					showMessage("\nALTA DE MASCOTA EXITOSA!");
					banderaAlta=0;
				}
				else
				{
					showMessage("\nOCURRIO UN PROBLEMA CON EL SISTEMA!");
				}
			break;
			case 'C':
				//BAJA
				if(banderaAlta==1)
				{
					printf("NO HAY NINGUNA MASCOTA DENTRO DEL SISTEMA!");
				}
				else
				{
					baja(lista, TAM, &idInicial, colorLista,TAM_COLOR,tipoLista,TAM_TIPO,listaDuenio,TAM_DUE);
				}
				system("Pause");
			break;
			case 'B':
				//MODIFICACION
				if(banderaAlta==1)
				{
					printf("NO HAY NINGUNA MASCOTA DENTRO DEL SISTEMA!");
				}
				else
				{
					modificacion(lista, TAM, &idInicial, colorLista,TAM_COLOR,tipoLista,TAM_TIPO,listaDuenio,TAM_DUE);
				}
				system("Pause");
			break;
			case 'D':
				sortByTipoYNombre(lista, TAM, &idInicial, colorLista, TAM_COLOR, tipoLista, TAM_TIPO,listaDuenio,TAM_DUE);
				banderaAlta=0;
				system("Pause");
			break;
			case 'E':
				listarTipoMascota(tipoLista, TAM_TIPO);
				system("Pause");
			break;
			case 'F':
				listarColor(colorLista, TAM_COLOR);
				system("Pause");
			break;
			case 'G':
				listarServicio(servicioLista, TAM_SERV);
				system("Pause");
			break;
			case 'H':
				//ALTA  TRABAJO
				if(banderaAlta==1)
				{
					printf("\nNO SE DIO DE ALTA A NINGUNA MASCOTA!\n");
				}
				else
				{
					altaTrabajo(trabajoLista, TAM_TRAB, &idTrabajoRandom, lista, TAM, colorLista, TAM_COLOR, tipoLista, TAM_TIPO, servicioLista, TAM_SERV,listaDuenio,TAM_DUE);
				}
				system("Pause");
			break;
			case 'I':
				//LISTAR TRABAJO
				if(banderaAlta==1)
				{
					printf("\nNO SE PUEDE LISTAR NO SE DIO DE ALTA AUN!\n");
				}
				else
				{
					listarTrabajos(trabajoLista, TAM_TRAB, lista, TAM, colorLista, TAM_COLOR, tipoLista, TAM_TIPO, servicioLista, TAM_SERV);
				}
				system("Pause");
			break;
			case 'J':
				altaDuenio(listaDuenio, TAM_DUE, &idDuenio);
				system("Pause");
			break;
			case 'K':
				listarDuenios(listaDuenio, TAM_DUE);
				system("Pause");
			break;
			case 'L':
				submenu(lista, TAM, colorLista, TAM_COLOR, tipoLista, TAM_TIPO, fecha, servicioLista, TAM_SERV, trabajoLista, TAM_TRAB,listaDuenio,TAM_DUE);
			break;
			case 'S':
				getUserConfirmation(&salir, "\nDESEA FINALIZAR EL PROGRAMA (S/N)?", "\nERROR, INGRESE UN VALOR VALIDO (S/N): ");
				if(salir=='s')
				{
					showMessage("\nPROGRAMA FINALIZADO....\n");
				}
				else
				{
					showMessage("\nFINALIZACION CANCELADA....\n");
				}
				system("Pause");
			break;
		}
	}while(salir!='s');

	return EXIT_SUCCESS;
}


int menu()
{
	char opcion;
	printf("\n\n\n\n");
	printf("\n____________________________________________________________");
	printf("\n                                                            |");
	printf("\n                VETERINARIA    MASCOTAS                     |\n");
	printf("____________________________________________________________|\n");
	printf("____________________________");
	printf("\n|A)ALTA MASCOTA            |\n|"
			"B)MODIFICACION  MASCOTA   |\n|"
			"C)BAJA MASCOTA            |\n|"
			"D)MOSTRAR LISTA MASCOTAS  |\n|"
			"E)LISTAR TIPOS            |\n|"
			"F)LISTAR COLORES          |\n|"
			"G)LISTAR SERVICIOS        |\n|"
			"H)ALTA TRABAJO            |\n|"
			"I)LISTAR TRABAJOS         |\n|"
			"J)ALTA DUENIO             |\n|"
			"K)LISTA DUENIOS           |\n|"
			"L)INFORMES                |\n|"
			"S)SALIR                   |\n");
	printf("|__________________________|\n");
	printf("INGRESA OPCION: ");
	fflush(stdin);
	scanf("%c",&opcion);
	opcion = toupper(opcion);
	while(opcion!='A' && opcion!='B' && opcion!='C' && opcion!='D' && opcion!='E' && opcion!='F' && opcion!='G' && opcion!='H' && opcion!='I' && opcion!='J' && opcion!='K' && opcion!='L' && opcion!='M' &&  opcion!='S'  )
	{
		printf("\nENTRE (A-S): ");
		fflush(stdin);
		scanf("%c",&opcion);
		opcion = toupper(opcion);
	}


	return opcion;
}

int submenu(eMascota lista[],int tam,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo,eFecha fecha,eServicio servicioLista[],int tamServicio,eTrabajo listaTrabajo[],int tamTrabajo,eDuenio listaDuenio[],int tamDuenio)
{
	int todoOk =-1;
	int opcion;

	if(lista!=NULL && tam>0 && colorMascota!=NULL && tamColor>0 && tipoLista!=NULL && tamTipo>0 && servicioLista!=NULL && tamServicio>0 && listaTrabajo!=NULL && tamTrabajo>0)
	{
		printf("\n\n\n\n");
		printf("\n____________________________________________________________");
		printf("\n                                                            |");
		printf("\n       INFORMES    VETERINARIA    MASCOTAS                  |\n");
		printf("____________________________________________________________|\n");
		printf("____________________________");
		printf("\n|1)                        |\n|"
				"2)                        |\n|"
				"3)                        |\n|"
				"4)                        |\n|"
				"5)                        |\n|"
				"6)                        |\n|"
				"7)                        |\n|"
				"8)                        |\n|"
				"9)                        |\n|"
				"10)                       |\n|"
				"11)SALIR                  |\n");
		printf("|__________________________|\n");
		getValidInt("INGRESE UN NUMERO: ", "\nERROR, REINGRESE UN NUMERO VALIDO.", "\nUNICAMENTE NUMEROS.", 1, 11, &opcion);

		switch(opcion)
		{
			case 1:

				system("Pause");
			break;
			case 2:

				system("Pause");
			break;
			case 3:

				system("Pause");
			break;
			case 4:

				system("Pause");
			break;
			case 5:

				system("Pause");
			break;
			case 6:

				system("Pause");
			break;
			case 7:

				system("Pause");
			break;
			case 8:

				system("Pause");
			break;
			case 9:

				system("Pause");
			break;
			case 10:

				system("Pause");
			break;
			case 11:
				showMessage("\nSALIO DE INFORMES....\n");
				system("Pause");
			break;
		}
		todoOk=1;
	}

	return todoOk;
}
