#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "eMascota.h"
#include  "utn.h"
#include "eFecha.h"
#include "eColor.h"
#include "tipo.h"

#include "trabajo.h"
#include "servicio.h"


#include "cliente.h"
#include "harcodeo.h"

int tiposIds[10]={

		1000,1001,1002,1003,1004,1001,1000,1002,1003,1004


};

int coloresIds[10]={

		5000,5001,5002,5003,5004,5001,5000,5002,5003,5004


};

char nombres[10][20]={

		{"COQUI"},{"ALMENDRA"},{"CHARLY"},{"SASHA"},{"GUS"},{"TOMMY"},{"POL"},{"LOLA"},{"NACHO"},{"FRY"}

};

char vacunado[10]={

		'S','N','S','N','S','N','S','N','S','N'

};

int edad[10]={

		10,5,1,15,2,3,2,5,8,9

};

int idDuenio[10]={

		6000,6001,6002,6003,6004,6005,6006,6007,6008,6009

};


int harcodearMascotas(eMascota listaMas[],int tamMasc,int cantidad,int* pId)
{
	int contador=-1;


	if(listaMas!=NULL && tamMasc>0 && cantidad>=0 && cantidad<=tamMasc && pId!=NULL )
	{
		contador=0;

		for(int i=0;i<cantidad;i++)
		{
			listaMas[i].id = *pId;
			(*pId)++;
			listaMas[i].idTipo = tiposIds[i];
			listaMas[i].idColor = coloresIds[i];
			strcpy(listaMas[i].nombre, nombres[i]);
			listaMas[i].vacunado = vacunado[i];
			listaMas[i].edad = edad[i];
			listaMas[i].idDuenio = idDuenio[i];
			listaMas[i].isEmpty=0;
			contador++;
		}
	}

	return contador;
}
