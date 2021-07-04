#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"

#define TAM 4
#define TAM_SERVICIOS 3
#define TAM_MASCOTAS 5
#define DESOCUPADO -1
#define OCUPADO 1
#define VACIO 0

typedef struct
{
    int idServicio;
    char descripcion[25];
    float precio;

    int isEmpty;
}eServicio;

/**
 * Inicializa los isEmpty de servicios
 *
 * @param Array de servicios
 * @param Tamaño del array
 */
void InicializarServicio (eServicio[], int);

/**
 * Busca un isEmpty en el array de servicios
 *
 * @param Array de servicios
 * @param Tamaño del array
 * @return Indice del espacio libre
 */
int BuscarLibreServicio (eServicio[], int);

/**
 * Verifica si el id ingresado de servicios existe
 *
 * @param id ingresado
 * @param Array de servicios
 * @param Tamaño del array
 * @return id ingresado
 */
int BuscarIdServicios (int,eServicio[],int);

/**
 * Carga los datos de un servicio
 *
 * @param Array de servicios
 * @param Tamaño del array
 * @return Devuelve los datos cargados
 */
int PedirIdServicios(eServicio[],int);

/**
 * Muestra listado de servicios cargados
 *
 * @param Array de servicios
 * @param Tamaño del array
 */
void MostrarListadoServicios (eServicio[], int);
