#include "Controlador.h"

void MenuTrabajos(eTrabajo trabajos[], int tam,eServicio servicios[], int tam_servicios, eMascota mascotas[], int tam_mascota, eEmpleado empleados[], int tam_empleados)
{
	int opcion;
	int opcionMostrar;
	int trabajo;
	int index;
	int contadorIteraciones;
	char continuar;

	contadorIteraciones = ContadorIsEmptyTrabajo(trabajos, tam);

	do
	{
		printf("1. ALTA\n");
		printf("2. BAJA\n");
		printf("3. MODIFICACION\n");
		printf("4. MOSTRAR\n");
		printf("5. Total\n");
		printf("6. Salir\n");
		opcion =  GetInt("Ingrese una opción: ");

		switch(opcion)
		{
			case 1:
				do
				{
					index = BuscarLibreTrabajo(trabajos, tam);
					if(index != DESOCUPADO)
						{
							trabajo = AltaTrabajo (trabajos, tam, servicios, tam_servicios, mascotas, tam_mascota, empleados, tam_empleados);
							continuar = GetChar("Desea agregar otro? (s/n): ");
						} else
						{
							printf("No hay más espacio\n");
						}
				} while(continuar == 's' && index != DESOCUPADO);
			break;
			case 2:
				do
				{
					if(contadorIteraciones != 0)
					{
						BajaTrabajo(trabajos, tam, servicios, tam_servicios, mascotas, tam_mascota, empleados, tam_empleados);
						continuar = GetChar("Desea dar de baja otro? (s/n): ");
					} else
					{
						printf("No hay más trabajos para dar de baja\n");
					}
				}while(continuar == 's' && index != VACIO);
			break;
		   case 3:
				do
				{
					if(contadorIteraciones != 0)
					{
						ModificarTrabajo(trabajos, tam, servicios, tam_servicios, mascotas, tam_mascota, empleados, tam_empleados);
						continuar = GetChar("Desea modificar otro? (s/n): ");
					} else
					{
						printf("No hay trabajos para modificar\n");
					}
				}while(continuar == 's' && index != VACIO);
			break;
			case 4:
				do
				{
					if(contadorIteraciones != 0)
					{
						printf("1.Mostrar listado ordenado por año\n");
						printf("2.Mostrar listado ordenado por nombres\n");
						printf("3.El o los servicios con más trabajos realizados.\n");
						printf("4.Listado de servicios con los nombres de las mascotas que se lo realizaron.\n");
						printf("5.Promedio de edades por servicios.\n");
						printf("6.Trabajos de cada empleado\n");
						printf("7.Mostrar paga de cada empleado\n");
						opcionMostrar = GetInt("Ingrese una opción: ");
						switch(opcionMostrar)
						{
							case 1:
								OrdenarTrabajosFecha(trabajos, tam, mascotas, tam_mascota);
								MostrarListadoTrabajo(trabajos, tam, servicios, tam_servicios, mascotas, tam_mascota, empleados, tam_empleados);
							break;
							case 2:
								ListadoTrabajosOrdenadoNombre(trabajos, tam, mascotas, tam_mascota);
								MostrarListadoTrabajo(trabajos, tam, servicios, tam_servicios, mascotas, tam_mascota, empleados, tam_empleados);
							break;
							case 3:
								MostrarServiciosConMasTrabajos(trabajos, tam, servicios, tam_servicios);
							break;
							case 4:
								ListadoServiciosMascotas(trabajos, tam, servicios, tam_servicios, mascotas, tam_mascota);
							break;
							case 5:
								ListadoServiciosPromedios(trabajos, tam, servicios, tam_servicios, mascotas, tam_mascota);
							break;
							case 6:
								empleadosResponsabilidades(trabajos, tam, servicios, tam_servicios, mascotas, tam_mascota, empleados, tam_empleados);
							break;
							case 7:
								MostrarPagaEmpleados(trabajos, tam, servicios, tam_servicios, empleados, tam_empleados);
							break;
						}

					} else
					{
						printf("No hay trabajos para mostrar\n");
					}
				}while(continuar == 's' && index != VACIO);

			break;
			case 5:
				do
				{
					if(contadorIteraciones != 0)
					{
						MostrarTotal(trabajos, tam, servicios, tam_servicios);
					} else
					{
						printf("No se han ingresados trabajos para calcular el total\n");
					}
				}while(continuar == 's' && index != VACIO);

			break;
		}
	}while(opcion!=6);
}

eTrabajo PedirTrabajo(eTrabajo trabajos[], int tam, eServicio servicios[], int tam_servicios, eMascota mascotas[], int tam_mascota, eEmpleado empleados[], int tam_empleados)
{
	eTrabajo trabajo;

	trabajo.idTrabajo = AsignarIdTrabajo(trabajos, tam);

	trabajo.idMascota = PedirIdMascota(mascotas, tam_mascota);

    trabajo.idServicio = PedirIdServicios(servicios, tam_servicios);

    trabajo.idEmpleado = PedirIdEmpleado(empleados, tam_empleados);

    trabajo.fecha = PedirFecha();

    trabajo.isEmpty = OCUPADO;

    printf("Se agregó con exíto\n");

    return trabajo;
}

/**
 * Da de alta una mascota
 */
int AltaTrabajo(eTrabajo trabajos[], int tam,eServicio servicios[], int tam_servicios, eMascota mascotas[], int tam_mascota, eEmpleado empleados[], int tam_empleados)
{
    int i;

    i = BuscarLibreTrabajo(trabajos, tam);

    if(i != DESOCUPADO)
    {
    	trabajos[i] = PedirTrabajo(trabajos, tam, servicios, tam_servicios, mascotas, tam_mascota, empleados, tam_empleados);
    }

    return i;
}

/**
 * Da de baja una mascota
 */
void BajaTrabajo (eTrabajo trabajos[], int tam,eServicio servicios[], int tam_servicios, eMascota mascotas[], int tam_mascota, eEmpleado empleados[], int tam_empleados)
{
    int i;
    int idIngresado;
    int verificar;
    char confirmar;

    do
    {
    	MostrarListadoTrabajo (trabajos, tam, servicios, tam_servicios, mascotas, tam_mascota, empleados, tam_empleados);
		idIngresado = GetInt("Ingrese el id del que desea dar de baja: ");
		verificar = BuscarIdTrabajo(idIngresado, trabajos, tam);

		while(verificar == DESOCUPADO)
		{
			idIngresado = GetInt("Ingrese el id del que desea dar de baja: ");
			verificar = BuscarIdTrabajo(idIngresado, trabajos, tam);
		}

		confirmar = GetChar("Seguro/a (s/n): ");
	}while(confirmar != 's');

	for(i=0; i<=tam; i++)
	{
		if(idIngresado == trabajos[i].idTrabajo && trabajos[i].isEmpty == OCUPADO)
		{
			trabajos[i].isEmpty = DESOCUPADO;
			break;
		}
	}

	printf("Se ha dado de baja con exito.\n");
}

/**
 * Modifica los datos de una mascota
 */
void ModificarTrabajo (eTrabajo trabajos[], int tam,eServicio servicios[], int tam_servicios, eMascota mascotas[], int tam_mascota, eEmpleado empleados[], int tam_empleados)
{
	int i;
	int idIngresado;
	int verificar;
	char confirmar;
	int opcion;
	char confirmarOpcion;

	do
	{
		MostrarListadoTrabajo (trabajos, tam, servicios, tam_servicios, mascotas, tam_mascota, empleados, tam_empleados);
		idIngresado = GetInt("Ingrese el id del que desea modificar: ");
		verificar = BuscarIdTrabajo(idIngresado, trabajos, tam);

		while(verificar == DESOCUPADO)
		{
			idIngresado = GetInt("ERROR.Ingrese el id del que desea modificar: ");
			verificar = BuscarIdTrabajo(idIngresado, trabajos, tam);
		}

		confirmar = GetChar("Seguro/a (s/n): ");
	}while(confirmar != 's');

    for(i=0; i<tam; i++)
	{
        if(idIngresado == trabajos[i].idTrabajo && trabajos[i].isEmpty == OCUPADO)
        {
            do
    			{
            		printf("1. Cambiar mascota\n");
            		printf("2. Cambiar servicio\n");
            		printf("3. Cambiar empleado\n");
            		printf("4. Salir\n");
    				opcion = GetInt("Ingrese una opción: ");

    				switch(opcion)
    				{
        				case 1:
        					do
        					{
        						trabajos[i].idMascota = PedirIdMascota(mascotas, tam_mascota);
        						confirmarOpcion = GetChar("Seguro/a (s/n): ");
        					}while(confirmarOpcion != 's');
                            printf("Se realizo el cambio\n");
        				break;
        				case 2:
        					do
        					{
        						trabajos[i].idServicio = PedirIdServicios(servicios, tam_servicios);
        						confirmarOpcion = GetChar("Seguro/a (s/n): ");
        					}while(confirmarOpcion != 's');
        					printf("Se realizo el cambio\n");
        				break;
        				case 3:
        					do
							{
								trabajos[i].idEmpleado = PedirIdEmpleado(empleados, tam_empleados);
								confirmarOpcion = GetChar("Seguro/a (s/n): ");
							}while(confirmarOpcion != 's');
							printf("Se realizo el cambio\n");
        				break;
    				}
    			}while(opcion!=3);
    		break;
        }
	}
}
void MostrarUnTrabajo(eTrabajo trabajos, eServicio servicios, eMascota mascotas, eEmpleado empleados)
{
	printf("%d----%s----%s----%s----%.2f----%d/%d/%d\n", trabajos.idTrabajo, mascotas.nombre, servicios.descripcion, empleados.nombre, servicios.precio, trabajos.fecha.dia, trabajos.fecha.mes, trabajos.fecha.anio);
}
void MostrarListadoTrabajo (eTrabajo trabajos[], int tam,eServicio servicios[], int tam_servicios, eMascota mascotas[], int tam_mascota, eEmpleado empleados[], int tam_empleados)
{
    int i;
    eServicio servicio;
    eMascota mascota;
    eEmpleado empleado;

    for(i=0; i<tam; i++)
    {
    	if(trabajos[i].isEmpty == OCUPADO)
    	{
    		servicio = BuscarServicioListado (servicios, trabajos[i], tam_servicios);
    		mascota = BuscarMascotaListado(mascotas, trabajos[i], tam_mascota);
    		empleado = BuscarEmpleadoListado(empleados, trabajos[i], tam_empleados);
    		MostrarUnTrabajo(trabajos[i], servicio, mascota, empleado);
    	}
    }
}

float SumaPrecios(eTrabajo trabajos[], int tam, eServicio servicios[], int tam_servicios)
{
    int i;
    float sumaPrecios;
    eServicio servicio;

    sumaPrecios = 0;

    for(i=0; i<tam; i++)
    {
    	if(trabajos[i].isEmpty == OCUPADO)
    	{
    		servicio = BuscarServicioListado(servicios, trabajos[i], tam_servicios);
    		sumaPrecios = sumaPrecios + servicio.precio;
    	}
    }
    return sumaPrecios;
}

void MostrarTotal(eTrabajo trabajos[], int tam, eServicio servicios[], int tam_servicios)
{
	float total;
	total = SumaPrecios(trabajos, tam, servicios, tam_servicios);

	printf("El total de los trabajos es de: %.2f\n", total);
}

eServicio BuscarServicioListado (eServicio servicios[], eTrabajo trabajo, int tam_servicios)
{
	int i;
	eServicio servicio;

	for(i=0; i<tam_servicios; i++)
	{
		if(trabajo.idServicio == servicios[i].idServicio)
		{
			servicio = servicios[i];
			break;
		}
	}

	return servicio;
}

eMascota BuscarMascotaListado (eMascota mascotas[], eTrabajo trabajo, int tam_mascota)
{
	int i;
	eMascota mascota;

	for(i=0; i<tam_mascota; i++)
	{
		if(trabajo.idMascota == mascotas[i].idMascotas)
		{
			mascota = mascotas[i];
			break;
		}
	}

	return mascota;
}

eEmpleado BuscarEmpleadoListado (eEmpleado empleados[], eTrabajo trabajo, int tam_empleados)
{
	int i;
	eEmpleado empleado;

	for(i=0; i<tam_empleados; i++)
	{
		if(trabajo.idEmpleado == empleados[i].idEmpleado)
		{
			empleado = empleados[i];
			break;
		}
	}

	return empleado;
}

void OrdenarTrabajosFecha(eTrabajo trabajos[], int tam, eMascota mascotas[], int tam_mascota)
{
    int i;
    int j;
    eTrabajo auxiliar;

    for(i=0; i<tam-1;i++)
	{
    	for(j=i+1; j<tam;j++)
		{
			if(trabajos[i].isEmpty==OCUPADO && trabajos[j].isEmpty == OCUPADO)
			{
				if(trabajos[i].fecha.anio>trabajos[j].fecha.anio)
				{
					auxiliar = trabajos[i];
					trabajos[i] = trabajos[j];
					trabajos[j] = auxiliar;
				} else
				{
					if(trabajos[i].fecha.anio == trabajos[j].fecha.anio)
					{
						OrdenarTrabajosNombre(trabajos[i],trabajos[j], mascotas, tam_mascota);
					}
				}
			}

    	}
	}
}

int OrdenarTrabajosNombre(eTrabajo trabajoI ,eTrabajo trabajoJ, eMascota mascotas[], int tam_mascota)
{
	int returnAux;
	eMascota auxiliarI;
	eMascota auxiliarJ;

	auxiliarI = BuscarMascotaListado(mascotas, trabajoI, tam_mascota);
	auxiliarJ = BuscarMascotaListado(mascotas, trabajoJ, tam_mascota);
	printf("El nombre de I es: %s\n", auxiliarI.nombre);
	printf("El nombre de J es: %s\n", auxiliarJ.nombre);
	returnAux = strcmp(auxiliarI.nombre,auxiliarJ.nombre);
	printf("Es %d\n", returnAux);
	return returnAux;
}

void ListadoTrabajosOrdenadoNombre(eTrabajo trabajos[], int tam, eMascota mascotas[], int tam_mascota)
{
    int i;
    int j;
    eMascota auxiliarI;
    eMascota auxiliarJ;
    eTrabajo  auxiliar;

    for(i=0; i<tam-1;i++)
	{
    	for(j=i+1; j<tam;j++)
		{
			if(trabajos[i].isEmpty==OCUPADO && trabajos[j].isEmpty == OCUPADO)
			{
				auxiliarI = BuscarMascotaListado(mascotas, trabajos[i], tam_mascota);
				auxiliarJ = BuscarMascotaListado(mascotas, trabajos[j], tam_mascota);

				if((strcmp(auxiliarI.nombre, auxiliarJ.nombre)) > 0)
				{
					auxiliar = trabajos[i];
					trabajos[i] = trabajos[j];
					trabajos[j] = auxiliar;
				}
			}
    	}
	}
}

int ContadorServicio (eTrabajo trabajos[], int tam, eServicio servicio)
{
    int i;
    int contador;

    contador = 0;
    for(i=0; i<tam; i++)
    {
        if(trabajos[i].idServicio == servicio.idServicio)
        {
            contador++;
        }
    }
    return contador;
}

int BuscarServicioConMasTrabajos(eTrabajo trabajos[],int tam, eServicio servicios[], int tam_servicios)
{
    int i;
    int contador;
    int mayorCantidad;

    for(i=0; i<tam_servicios; i++)
    {
        contador = ContadorServicio(trabajos,tam,servicios[i]);
        if(i == 0 || contador >= mayorCantidad)
        {
            mayorCantidad = contador;
        }
    }

    return mayorCantidad;
}

void MostrarUnTipoConMasProductos(eServicio servicios, int contador, int cantidadProductos)
{
    if(contador == cantidadProductos)
        {
            printf("%s: %d\n", servicios.descripcion, contador);
        }
}

void MostrarServiciosConMasTrabajos(eTrabajo trabajos[],int tam, eServicio servicios[], int tam_servicios)
{
    int cantidadProductos;
    int i;
    int contador;

    cantidadProductos = BuscarServicioConMasTrabajos(trabajos,tam, servicios, tam_servicios);

    for(i=0; i<tam_servicios; i++)
    {
        contador = ContadorServicio(trabajos,tam,servicios[i]);
        MostrarUnTipoConMasProductos(servicios[i], contador, cantidadProductos);
    }

}

void ListadoServiciosMascotas(eTrabajo trabajos[], int tam,eServicio servicios[], int tam_servicios, eMascota mascotas[], int tam_mascotas)
{
	int i;
	int j;
	int contador;
	contador = 0;
	eMascota auxiliar;

	for(i=0; i<tam_servicios;i++)
	{
		printf("%s:\n", servicios[i].descripcion);
		for(j=0;j<tam; j++)
		{
			if(trabajos[j].idServicio == servicios[i].idServicio)
			{
				contador++;
				auxiliar = BuscarMascotaListado(mascotas, trabajos[j], tam_mascotas);
				printf("%s\n", auxiliar.nombre);
			}
		}
		if(contador==0)
		{
			printf("No hay mascotas que se hayan realizado este servicio\n");
		}
	}
}

void ListadoServiciosPromedios(eTrabajo trabajos[], int tam,eServicio servicios[], int tam_servicios, eMascota mascotas[], int tam_mascotas)
{
	int opcion;
	int i;
	int j;
	int contador;
	int acumulador;
	int bandera;
	float promedio;
	eMascota auxiliar;
	contador=0;
	acumulador=0;
	bandera=-1;

	printf("Elija el ID del servicio que quiere saber el promedio de edades:\n");
	for(i=0;i<tam_servicios;i++)
	{
		printf("%d. %s\n", servicios[i].idServicio, servicios[i].descripcion);
	}
	opcion = GetInt("Ingrese el ID: ");

	for(i=0;i<tam_servicios;i++)
	{
		if(opcion == servicios[i].idServicio)
		{
			bandera=0;
			for(j=0; j<tam;j++)
			{
				if(trabajos[j].idServicio == servicios[i].idServicio)
				{
					contador++;
					auxiliar = BuscarMascotaListado(mascotas, trabajos[j], tam_mascotas);
					acumulador = acumulador + auxiliar.edad;
				}
			}
			break;
		}
	}

	if(bandera==-1)
	{
		printf("Usted ha ingresado el ID de un servicio no registrado\n");
	} else
	{
		promedio = (float)acumulador/contador;
		printf("El promedio de las edades del servicio '%s' es: %f.2\n", servicios[i].descripcion, promedio);
	}
}

void empleadosResponsabilidades (eTrabajo trabajos[], int tam,eServicio servicios[], int tam_servicios, eMascota mascotas[], int tam_mascota, eEmpleado empleados[], int tam_empleados)
{
	int i;
	int j;
	eServicio servicio;
	eMascota mascota;
	int bandera;

	for(i=0; i<tam_empleados;i++)
	{
		bandera = -1;
		printf("%s:\n", empleados[i].nombre);
		for(j=0;j<tam;j++)
		{
			if(trabajos[j].idEmpleado == empleados[i].idEmpleado)
			{
				bandera = 0;
				servicio = BuscarServicioListado(servicios, trabajos[j], tam_servicios);
				mascota = BuscarMascotaListado(mascotas, trabajos[j], tam_mascota);
				printf("%s -- %s\n", mascota.nombre, servicio.descripcion);
			}
		}
		if(bandera==-1)
		{
			printf("No tiene mascotas a cargo\n");
		}
	}
}

void MostrarPagaEmpleados(eTrabajo trabajos[], int tam, eServicio servicios[],int tam_servicios, eEmpleado empleados[], int tam_empleados)
{
	int i;
	int j;
	float sueldo;
	int contador;
	eServicio servicio;

	for(i=0;i<tam_empleados;i++)
	{
		contador = 0;
		sueldo = empleados[i].salario;
		printf("El salario estandar de %s es de: %.2f\n", empleados[i].nombre, sueldo);
		for(j=0;j<tam;j++)
		{
			if(trabajos[j].idEmpleado == empleados[i].idEmpleado)
			{
				contador++;
				servicio = BuscarServicioListado(servicios, trabajos[j], tam_servicios);
				sueldo = sueldo + servicio.precio;
			}
		}
		if(contador != 0)
		{
			printf("Además, %s tiene %d servicios realizados, por lo cuál su salario completo es de: %.2f\n", empleados[i].nombre, contador, sueldo);
		} else
		{
			printf("%s no ha realizado servicios\n",empleados[i].nombre);
		}
	}
}
