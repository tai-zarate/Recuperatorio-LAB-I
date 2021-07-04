/*
 ============================================================================
 Name        : ParcialPrtUno.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 Desarrollar en ANSI C:
Se necesita gestionar una veterinaria y para eso se deberá desarrollar lo siguiente:
ENTIDADES:
Servicio:
• id (comienza en 20000)
• descripción (máximo 25 caracteres)
• precio
Trabajo:
• id (autoincremental)
• nombreMascota (cadena)
• idServicio (debe existir) Validar
• fecha (Validar día, mes y año)
DATOS PREVIOS:
El array de servicios será hardcodeado.
Servicios (Corte: $250, Desparasitado: $300, Castrado: $400)

NOTAS:
I. Se deberá desarrollar bibliotecas por cada entidad, las cuales contendrán las
funciones Alta, Baja, Modificar y Listar.
II. Las validaciones (input), deberán estar en una biblioteca aparte.
III. Tener en cuenta que no se podrá ingresar a los casos Modificar, Baja, y
listados sin antes haber realizado al menos un Alta (utilizar banderas y/o
contadores).
IV. El código deberá tener comentarios con la documentación de cada una de
las funciones y respetar las reglas de estilo de la cátedra.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"
#include "Controlador.h"
#include "Empleados.h"

#define TAM 4
#define TAM_SERVICIOS 3
#define TAM_MASCOTAS 5
#define TAM_EMPLEADOS 3
#define DESOCUPADO -1
#define OCUPADO 1
#define VACIO 0

int main()
{
    setbuf(stdout, NULL);

    eServicio servicios[TAM_SERVICIOS] = {{20000,"Corte",250, OCUPADO},{20001,"Desparasitado",300, OCUPADO},{20002,"Castrado",400, OCUPADO}};
    eMascota mascotas[TAM_MASCOTAS] = {{15,"Flo",7,"Persa", OCUPADO},{16,"Canela",15,"Britsh", OCUPADO},{17,"Teya",16,"Cocker", OCUPADO},{18,"Titi",5,"Bulldog", OCUPADO},{19,"Pepe",11,"Labrador", OCUPADO}};
    eEmpleado empleados[TAM_EMPLEADOS] = {{1,"Ricardo", 30000, OCUPADO},{2,"Amelia", 37000,OCUPADO},{3,"Jose",32000,OCUPADO}};
    eTrabajo trabajos[TAM];
    InicializarTrabajo (trabajos, TAM);
    HardCodearTrabajos(trabajos, TAM);

    MenuTrabajos(trabajos, TAM,servicios, TAM_SERVICIOS, mascotas, TAM_MASCOTAS, empleados, TAM_EMPLEADOS);

    return 0;
}
