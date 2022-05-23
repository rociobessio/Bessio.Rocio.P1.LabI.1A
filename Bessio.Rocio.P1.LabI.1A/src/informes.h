#include "eFecha.h"
#include "eColor.h"
#include "tipo.h"
#include "duenio.h"
#include "eMascota.h"
#include "servicio.h"
#include "trabajo.h"


#ifndef INFORMES_H_
#define INFORMES_H_

#endif /* INFORMES_H_ */



///									INFORMES

///@brief	IMPRIME LAS MASCOTAS CON EL COLOR ESPECIFICADO
///@param lista [] eMascota array
///@param tam int tamanio del array
///@param colorMascota eColor[] array de colores
///@param tamColor int tamanio del color de mascotas
///@param tipoLista eTipo[] array de tipos de mascotas
///@param tamTipo int tamanio del array de tipo de mascotas
///@return int 1 si los parametros son valios o 0 si Invalido
int informeColorSeleccionado(eMascota lista[],int tam,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo,eFecha fecha,eServicio servicioLista[],int tamServicio,eTrabajo listaTrabajo[],int tamTrabajo,eDuenio listaDuenio[],int tamDuenio);


///@brief	PROMEDIO MASCOTAS VACUNADAS
///@param lista [] eEstructura array
///@param tam int tamanio del array
///@param colorMascota eColor[] array de colores
///@param tamColor int tamanio del color de mascotas
///@param tipoLista eTipo[] array de tipos de mascotas
///@param tamTipo int tamanio del array de tipo de mascotas
///@return int 1 si los parametros son valios o 0 si Invalido
int informeMascotaPromedioVacunadas(eMascota lista[],int tam,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo,eFecha fecha,eServicio servicioLista[],int tamServicio,eTrabajo listaTrabajo[],int tamTrabajo,eDuenio listaDuenio[],int tamDuenio);

///@brief	INFORMA LAS MASCOTAS DE MENOR EDAD
///@param lista [] eEstructura array
///@param tam int tamanio del array
///@param colorMascota eColor[] array de colores
///@param tamColor int tamanio del color de mascotas
///@param tipoLista eTipo[] array de tipos de mascotas
///@param tamTipo int tamanio del array de tipo de mascotas
///@return int 1 si los parametros son valios o 0 si Invalido
int informeMascotaMenorEdad(eMascota lista[],int tam,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo,eFecha fecha,eServicio servicioLista[],int tamServicio,eTrabajo listaTrabajo[],int tamTrabajo,eDuenio listaDuenio[],int tamDuenio);

///@brief	IMPRIME TODAS LAS MASCOTAS QUE HAY EN CADA TIPO
///@param lista [] eMascota array
///@param tam int tamanio del array
///@param colorMascota eColor[] array de colores
///@param tamColor int tamanio del color de mascotas
///@param tipoLista eTipo[] array de tipos de mascotas
///@param tamTipo int tamanio del array de tipo de mascotas
///@return int 1 si los parametros son valios o 0 si Invalido
int informeMascotasXTipo(eMascota lista[],int tam,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo,eFecha fecha,eServicio servicioLista[],int tamServicio,eTrabajo listaTrabajo[],int tamTrabajo,eDuenio listaDuenio[],int tamDuenio);

///@brief	CUENTA LA CANTIDAD DE MASCOTAS DE UN TIPO Y COLOR SELECCIONADOS
///@param lista [] eEstructura array
///@param tam int tamanio del array
///@param colorMascota eColor[] array de colores
///@param tamColor int tamanio del color de mascotas
///@param tipoLista eTipo[] array de tipos de mascotas
///@param tamTipo int tamanio del array de tipo de mascotas
///@return int 1 si los parametros son valios o 0 si Invalido
int informeCantidadColorYTipo(eMascota lista[],int tam,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo,eFecha fecha,eServicio servicioLista[],int tamServicio,eTrabajo listaTrabajo[],int tamTrabajo,eDuenio listaDuenio[],int tamDuenio);

///@brief	CUENTA CUAL ES EL TIPO DE MASCOTA QUE MAS HAY/FUE MAS ELEGIDA
///@param lista [] eMascota array
///@param tam int tamanio del array
///@param colorMascota eColor[] array de colores
///@param tamColor int tamanio del color de mascotas
///@param tipoLista eTipo[] array de tipos de mascotas
///@param tamTipo int tamanio del array de tipo de mascotas
///@return int 1 si los parametros son valios o 0 si Invalido
int informeMasCantidadColor(eMascota lista[],int tam,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo,eFecha fecha,eServicio servicioLista[],int tamServicio,eTrabajo listaTrabajo[],int tamTrabajo,eDuenio listaDuenio[],int tamDuenio);
///@brief	IMPRIME LOS TRABAJOS REALIZADOS A UNA MASCOTA
///@param lista [] eMascota array
///@param tam int tamanio del array
///@param colorMascota eColor[] array de colores
///@param tamColor int tamanio del color de mascotas
///@param tipoLista eTipo[] array de tipos de mascotas
///@param tamTipo int tamanio del array de tipo de mascotas
///@return int 1 si los parametros son valios o 0 si Invalido
int informeTrabajoRealizadoMascota(eMascota lista[],int tam,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo,eFecha fecha,eServicio servicioLista[],int tamServicio,eTrabajo listaTrabajo[],int tamTrabajo,eDuenio listaDuenio[],int tamDuenio);

///@brief	IMPRIME EL PRECIO TOTAL DE TODOS LOS SERVICIOS REALIZADOS A LA MASCOTA
///@param lista [] eMascota array
///@param tam int tamanio del array
///@param colorMascota eColor[] array de colores
///@param tamColor int tamanio del color de mascotas
///@param tipoLista eTipo[] array de tipos de mascotas
///@param tamTipo int tamanio del array de tipo de mascotas
///@return int 1 si los parametros son valios o 0 si Invalido
int informeImporteTrabajoMascota(eMascota lista[],int tam,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo,eFecha fecha,eServicio servicioLista[],int tamServicio,eTrabajo listaTrabajo[],int tamTrabajo,eDuenio listaDuenio[],int tamDuenio);

///@brief PIDE UN SERVICIO Y MUESTRA A LOS AUTOS QUE SE LES REALIZO EL SERVICIO Y LA FECHA
///@param lista [] eMascota array
///@param tam int tamanio del array
///@param colorMascota eColor[] array de colores
///@param tamColor int tamanio del color de mascotas
///@param tipoLista eTipo[] array de tipos de mascotas
///@param tamTipo int tamanio del array de tipo de mascotas
///@return int 1 si los parametros son valios o 0 si Invalido
int informeTrabajoFecha(eMascota lista[],int tam,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo,eFecha fecha,eServicio servicioLista[],int tamServicio,eTrabajo listaTrabajo[],int tamTrabajo,eDuenio listaDuenio[],int tamDuenio);

///@brief PIDE UNA FECHA Y MUESTRA TODOS LOS SERVICIOS REALIZADOS ESE DIA
///@param lista [] eMascota array
///@param tam int tamanio del array
///@param colorMascota eColor[] array de colores
///@param tamColor int tamanio del color de mascotas
///@param tipoLista eTipo[] array de tipos de mascotas
///@param tamTipo int tamanio del array de tipo de mascotas
///@return int 1 si los parametros son valios o 0 si Invalido
int informeFechaEspecificaYServicio(eMascota lista[],int tam,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo,eFecha fecha,eServicio servicioLista[],int tamServicio,eTrabajo listaTrabajo[],int tamTrabajo,eDuenio listaDuenio[],int tamDuenio);
