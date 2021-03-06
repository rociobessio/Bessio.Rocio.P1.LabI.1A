/*
 ============================================================================
 Name          : AbmPrimerParcial.c
 Author        : Bessio Rocio
 Division      : 1-A
 Fecha Part. 1 : 11/05/22
 Fecha Part. 2 : 23/05/22
 Tema          : MASCOTAS

 - NO PODRA ENTRAR A CIERTOS APARTADOS SALVO QUE DE ALTA O MUESTRE LA LISTA CON LOS HARDCODEADOS
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


#include "cliente.h"
#include "harcodeo.h"
#include "informes.h"




int menu();

int submenu(eMascota lista[],int tam,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo,eFecha fecha,eServicio servicioLista[],int tamServicio,eTrabajo listaTrabajo[],int tamTrabajo,eCliente listaDuenio[],int tamDuenio);

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

	eCliente listaDuenio[TAM_DUE];

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
				//LISTAR
				sortByTipoYNombre(lista, TAM, &idInicial, colorLista, TAM_COLOR, tipoLista, TAM_TIPO,listaDuenio,TAM_DUE);
				banderaAlta=0;
				system("Pause");
			break;
			case 'E':
				//LISTAR TIPO
				listarTipoMascota(tipoLista, TAM_TIPO);
				system("Pause");
			break;
			case 'F':
				//LISTAR COLOR
				listarColor(colorLista, TAM_COLOR);
				system("Pause");
			break;
			case 'G':
				//LISTAR SERVICIOS
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
					printf("\nNO SE PUEDE LISTAR TRABAJOS SI NO SE DIO DE ALTA AUN!\n");
				}
				else
				{
					listarTrabajos(trabajoLista, TAM_TRAB, lista, TAM, colorLista, TAM_COLOR, tipoLista, TAM_TIPO, servicioLista, TAM_SERV);
				}
				system("Pause");
			break;
			case 'J':
				//ALTA DUENIO
				altaDuenio(listaDuenio, TAM_DUE, &idDuenio);
				system("Pause");
			break;
			case 'K':
				//LISTAR DUENIOS
				listarDuenios(listaDuenio, TAM_DUE);
				system("Pause");
			break;
			case 'L':
				//SUBMENU INFORMES
				if(banderaAlta==1)
				{
					printf("\nNO SE PUEDE INFORMAR SI NO SE DIO DE ALTA!\n");
					system("Pause");
				}
				else
				{
					submenu(lista, TAM, colorLista, TAM_COLOR, tipoLista, TAM_TIPO, fecha, servicioLista, TAM_SERV, trabajoLista, TAM_TRAB,listaDuenio,TAM_DUE);
				}
			break;
			case 'S':
				//SALIR
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

int submenu(eMascota lista[],int tam,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo,eFecha fecha,eServicio servicioLista[],int tamServicio,eTrabajo listaTrabajo[],int tamTrabajo,eCliente listaDuenio[],int tamDuenio)
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
		printf("\n|1)COLOR SELECCIONADO      |\n|"
				"2)PROMEDIO VACUNADAS      |\n|"
				"3)LA/LAS MENOR EDAD       |\n|"
				"4)SEPARADAS POR TIPO      |\n|"
				"5)CUANTAS DE COLOR Y TIPO |\n|"
				"6)COLOR MAS ELEGIDO       |\n|"
				"7)TRABAJOS A MASCOTA      |\n|"
				"8)SUMA DE IMPORTES        |\n|"
				"9)SERVICIO Y FECHA        |\n|"
				"10)FECHA ELEGIDA          |\n|"
				"11)SALIR                  |\n");
		printf("|__________________________|\n");
		getValidInt("INGRESE UN NUMERO: ", "\nERROR, REINGRESE UN NUMERO VALIDO.", "\nUNICAMENTE NUMEROS.", 1, 11, &opcion);

		switch(opcion)
		{
			case 1:
				informeColorSeleccionado(lista, tam, colorMascota, tamColor, tipoLista, tamTipo, fecha, servicioLista, tamServicio, listaTrabajo, tamTrabajo, listaDuenio, tamDuenio);
				system("Pause");
			break;
			case 2:
				informeMascotaPromedioVacunadas(lista, tam, colorMascota, tamColor, tipoLista, tamTipo, fecha, servicioLista, tamServicio, listaTrabajo, tamTrabajo, listaDuenio, tamDuenio);
				system("Pause");
			break;
			case 3:
				informeMascotaMenorEdad(lista, tam, colorMascota, tamColor, tipoLista, tamTipo, fecha, servicioLista, tamServicio, listaTrabajo, tamTrabajo, listaDuenio, tamDuenio);
				system("Pause");
			break;
			case 4:
				informeMascotasXTipo(lista, tam, colorMascota, tamColor, tipoLista, tamTipo, fecha, servicioLista, tamServicio, listaTrabajo, tamTrabajo, listaDuenio, tamDuenio);
				system("Pause");
			break;
			case 5:
				informeCantidadColorYTipo(lista, tam, colorMascota, tamColor, tipoLista, tamTipo, fecha, servicioLista, tamServicio, listaTrabajo, tamTrabajo, listaDuenio, tamDuenio);
				system("Pause");
			break;
			case 6:
				informeMasCantidadColor(lista, tam, colorMascota, tamColor, tipoLista, tamTipo, fecha, servicioLista, tamServicio, listaTrabajo, tamTrabajo, listaDuenio, tamDuenio);
				system("Pause");
			break;
			case 7:
				informeTrabajoRealizadoMascota(lista, tam, colorMascota, tamColor, tipoLista, tamTipo, fecha, servicioLista, tamServicio, listaTrabajo, tamTrabajo, listaDuenio, tamDuenio);
				system("Pause");
			break;
			case 8:
				informeImporteTrabajoMascota(lista, tam, colorMascota, tamColor, tipoLista, tamTipo, fecha, servicioLista, tamServicio, listaTrabajo, tamTrabajo, listaDuenio, tamDuenio);
				system("Pause");
			break;
			case 9:
				informeTrabajoFecha(lista, tam, colorMascota, tamColor, tipoLista, tamTipo, fecha, servicioLista, tamServicio, listaTrabajo, tamTrabajo, listaDuenio, tamDuenio);
				system("Pause");
			break;
			case 10:
				informeFechaEspecificaYServicio(lista, tam, colorMascota, tamColor, tipoLista, tamTipo, fecha, servicioLista, tamServicio, listaTrabajo, tamTrabajo, listaDuenio, tamDuenio);
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
