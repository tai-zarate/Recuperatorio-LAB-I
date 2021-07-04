#include "Empleados.h"

void inicializarEmpleados(eEmpleado empleados[], int tam_empleados)
{
	int i;

	for(i=0; i<tam_empleados;i++)
	{
		empleados[i].idEmpleado = DESOCUPADO;
	}
}

int BuscarLibreEmpleado(eEmpleado empleados[], int tam_empleados)
{
    int i;
    int index;
    index = DESOCUPADO;
    for(i=0; i<tam_empleados;i++)
	{
		if(empleados[i].isEmpty == DESOCUPADO)
		{
			index = i;
			break;
		}
	}

    return index;
}

int BuscarIdEmpleado(int idIngreasado,eEmpleado empleados[], int tam_empleados)
{
    int i;
    int resultado;

    resultado = DESOCUPADO;

    for(i=0;i<tam_empleados;i++)
    {
        if(idIngreasado == empleados[i].idEmpleado)
        {
            resultado = OCUPADO;
            break;
        }
    }
    return resultado;
}

int PedirIdEmpleado(eEmpleado empleados[], int tam_empleados)
{
	int idIngreasado;
	int verificar;
	char confirmar;

	do
	{
		mostrarTodosLosEmpleados(empleados, tam_empleados);
		idIngreasado = GetInt("Ingrese el id correspondiente: ");
		verificar = BuscarIdEmpleado(idIngreasado, empleados, tam_empleados);

		while(verificar == DESOCUPADO)
		{
			mostrarTodosLosEmpleados(empleados, tam_empleados);
			idIngreasado = GetInt("ERROR.Ingrese el id correspondiente: ");
			verificar = BuscarIdEmpleado(idIngreasado, empleados, tam_empleados);
		}

		confirmar = GetChar("Seguro/a (s/n): ");
	}while(confirmar != 's');

	return idIngreasado;
}



void mostrarUnEmpleado(eEmpleado empleado)
{
	printf("%d----%s----%f", empleado.idEmpleado, empleado.nombre, empleado.salario);
}

void mostrarTodosLosEmpleados(eEmpleado empleados[], int tam_empleados)
{
	int i;

	for(i=0;i<tam_empleados;i++)
	{
		mostrarUnEmpleado(empleados[i]);
	}
}
