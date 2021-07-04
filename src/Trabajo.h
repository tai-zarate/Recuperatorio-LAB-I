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

//ESTRUCTURA


typedef struct
{
    int mes;
    int dia;
    int anio;
}eFecha;
//ESTRUCTURA
typedef struct
{
    int idTrabajo;
    int idMascota;
    int idServicio;
    int idEmpleado;
    eFecha fecha;

    int isEmpty;
}eTrabajo;

/**
 * Inicializa los isEmpty de trabajo
 *
 * @param Array de trabajos
 * @param Tamaño del array
 */
void InicializarTrabajo (eTrabajo[], int);

/**
 * Busca un isEmpty en el array de trabajo
 *
 * @param Array de trabajos
 * @param Tamaño del array
 * @return Indice del espacio libre
 */
int BuscarLibreTrabajo (eTrabajo[], int);

/**
 * Crea un id autoincremental
 *
 * @param Array de trabajos
 * @param Tamaño del array
 * @return Id
 */
int AsignarIdTrabajo(eTrabajo[], int);

/**
 * Cuenta los isEmpty que esten OCUPADOS de eTrabajo[]
 *
 * @param Array de trabajos
 * @param Tamaño del array
 * @return Cantidad de trabajos
 */
int ContadorIsEmptyTrabajo (eTrabajo[], int);

/**
 * Pide día, mes y año
 *
 * @return Una fecha
 */
eFecha PedirFecha ();

/**
 * Verifica el minimo y maximo, de días en un mes o meses en un año
 *
 * @param minimo
 * @param maximo
 * @param Mensaje
 * @param Mensaje de error
 * @return Un día, un mes o un año
 */
int AsignarFecha (int, int, char[], char[]);

/**
 * Verifica el minimo y el maximo de días en un mes, según que mes sea
 *
 * @param Mes insertado
 * @param Año insertado
 * @param Mensaje
 * @param Mensaje de error
 * @return día
 */
int PedirDia(int, int, char[], char[]);

/**
 * Verifica que el id de servicio ingresado existe
 * @param id ingresado
 * @param Array de trabajos
 * @param Tamaño del array
 * @return
 */
int BuscarIdTrabajo (int,eTrabajo[],int);

/**
 * Pide nombre y confirma si es el deseado
 *
 * @param Mensaje
 * @param Guarda el array de caracteres
 */
void PedirNombre(char[], char *);





/**
 * Hardcodea el array de eTrabajos
 *
 * @param Array de trabajos
 * @param Tamaño del array
 */
void HardCodearTrabajos(eTrabajo[], int);
