#ifndef EMPLEADOS_H_
#define EMPLEADOS_H_

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
	int idEmpleado;
	char nombre[120];
	float salario;
	int isEmpty;
} eEmpleado;

void inicializarEmpleados(eEmpleado empleados[], int tam_empleados);
int BuscarLibreEmpleado(eEmpleado empleados[], int tam_empleados);
int BuscarIdEmpleado(int idIngreasado,eEmpleado empleados[], int tam_empleados);
int PedirIdEmpleado(eEmpleado empleados[], int tam_empleados);

void mostrarUnEmpleado(eEmpleado empleado);
void mostrarTodosLosEmpleados(eEmpleado empleados[], int tam_empleados);

#endif /* EMPLEADOS_H_ */
