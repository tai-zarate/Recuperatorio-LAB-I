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
    int idMascotas;
    char nombre[30];
    int edad;
    char raza[30];

    int isEmpty;
}eMascota;

/**
 * Inicializa los isEmpty de mascotas
 *
 * @param Array de trabajos
 * @param Tamaño del array
 */
void InicializarMascotas (eMascota[], int);

/**
 * Busca un isEmpty en el array de mascotas
 *
 * @param Array de mascotas
 * @param Tamaño del array
 * @return Indice del espacio libre
 */
int BuscarLibreMascotas (eMascota[], int);

/**
 * Verifica si el id ingresado de mascota existe
 *
 * @param id ingresado
 * @param Array de mascotas
 * @param Tamaño del array
 * @return id ingresado
 */
int BuscarIdMascotas (int,eMascota[], int);

/**
 * Carga los datos de una mascota
 *
 * @param Array de mascotas
 * @param Tamaño del array
 * @return Devuelve los datos cargados
 */
int PedirIdMascota(eMascota[], int);

/**
 * Muestra listado de mascotas cargadas
 *
 * @param Array de mascotas
 * @param Tamaño del array
 */
void MostrarListadoMascotas (eMascota[], int);
