#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"
#include "Trabajo.h"
#include "Servicios.h"
#include "Mascotas.h"
#include "Empleados.h"

#define TAM 4
#define TAM_SERVICIOS 3
#define TAM_MASCOTAS 5
#define DESOCUPADO -1
#define OCUPADO 1
#define VACIO 0

/**
 * Carga los datos de un trabajo ingresado
 *
 * @param Array de trabajos
 * @param Tamaño del array de eTrabajo
 * @param Array de servicios
 * @param Tamaño del array de eServicio
 * @return Datos ingresados
 */
eTrabajo PedirTrabajo (eTrabajo[], int,eServicio[], int, eMascota[], int, eEmpleado[], int);

/**
 * Da de alta un nuevo trabajo con los datos ingresados
 * @param Array de trabajos
 * @param Tamaño del array de eTrabajo
 * @param Array de servicios
 * @param Tamaño del array de eServicio
 * @return Indice del eTrabajo con los datos ingresados
 */
int AltaTrabajo (eTrabajo[], int,eServicio[], int, eMascota[], int, eEmpleado[], int);

/**
 * Da de baja un trabajo comparando según el id ingresado
 * @param Array de trabajos
 * @param Tamaño del array de eTrabajo
 * @param Array de servicios
 * @param Tamaño del array de eServicio
 */
void BajaTrabajo (eTrabajo[], int,eServicio[], int, eMascota[], int, eEmpleado[], int);

/**
 * Modifica los datos de un trabajo comparando según el id ingresado
 *
 * @param Array de trabajos
 * @param Tamaño del array de eTrabajo
 * @param Array de servicios
 * @param Tamaño del array de eServicio
 */
void ModificarTrabajo (eTrabajo[], int,eServicio[], int, eMascota[], int, eEmpleado[], int);

void MostrarUnTrabajo(eTrabajo trabajos, eServicio servicios, eMascota mascotas, eEmpleado empleados);

/**
 * Muestra el listado de trabajos ingresados
 *
 * @param Array de trabajos
 * @param Tamaño del array de eTrabajo
 * @param Array de servicios
 * @param Tamaño del array de eServicio
 */
void MostrarListadoTrabajo (eTrabajo[], int,eServicio[], int, eMascota[], int, eEmpleado[], int);

/**
 * Acumula los precios de los trabajos ingresados
 *
 * @param Array de trabajos
 * @param Tamaño del array de eTrabajo
 * @param Array de servicios
 * @param Tamaño del array de eServicio
 * @return El total de los precios
 */
float SumaPrecios(eTrabajo[], int , eServicio[], int );

/**
 * Muestra el total de los precios acumulados
 *
 * @param Array de trabajos
 * @param Tamaño del array de eTrabajo
 * @param Array de servicios
 * @param Tamaño del array de eServicio
 */
void MostrarTotal(eTrabajo [], int , eServicio [], int );

/**
 * Compara el FK de idServicio de eTrabajo con el Pk de idServicios de eServicio
 * @param Tamaño del array de eTrabajo
 * @param Trabajo al que se compara
 * @param Array de servicios
 * @return
 */
eServicio BuscarServicioListado (eServicio[], eTrabajo, int);

/**
 * Compara el FK de idServicio de eTrabajo con el Pk de idServicios de eServicio
 * @param Tamaño del array de eTrabajo
 * @param Trabajo al que se compara
 * @param Array de servicios
 * @return
 */
eMascota BuscarMascotaListado (eMascota[], eTrabajo, int);

eEmpleado BuscarEmpleadoListado (eEmpleado [], eTrabajo , int);

/**
 * Muestra el menu de trabajos
 *
 * @param Array de trabajos
 * @param Tamaño del array de eTrabajo
 * @param Array de servicios
 * @param Tamaño del array de eServicio
 */
void MenuTrabajos(eTrabajo[], int,eServicio[], int, eMascota[], int, eEmpleado[], int);

/**
 * Ordena los trabajos por fecha
 *
 * @param Array de trabajos
 * @param Tamaño del array
 */
void OrdenarTrabajosFecha(eTrabajo[], int, eMascota[], int);

/**
 * Si los años coinciden, ordena por orden alfabetico comparando los nombres
 *
 * @param Trabajo I
 * @param Trabajo J
 */
int OrdenarTrabajosNombre(eTrabajo ,eTrabajo, eMascota[], int);

void ListadoTrabajosOrdenadoNombre (eTrabajo[], int, eMascota[], int);

int ContadorServicio (eTrabajo[], int, eServicio);
int BuscarServicioConMasTrabajos(eTrabajo[],int,eServicio[], int);
void MostrarUnServicioConMasTrabajos(eServicio, int, int);
void MostrarServiciosConMasTrabajos(eTrabajo[], int, eServicio[], int);

void ListadoServiciosMascotas(eTrabajo[], int,eServicio[], int, eMascota[], int);

void ListadoServiciosPromedios(eTrabajo[], int,eServicio[], int, eMascota[], int);

void empleadosResponsabilidades (eTrabajo[], int ,eServicio[], int , eMascota[], int , eEmpleado[], int );

void MostrarPagaEmpleados(eTrabajo trabajos[], int tam, eServicio servicios[],int tam_servicios, eEmpleado empleados[], int tam_empleados);
