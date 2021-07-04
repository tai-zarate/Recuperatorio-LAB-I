#include "Servicios.h"

void InicializarServicio(eServicio servicios[], int tam_servicios)
{
    int i;

    for(i=0; i<tam_servicios;i++)
	{
    	servicios[i].isEmpty = DESOCUPADO;
	}
}

int BuscarLibreServicio(eServicio servicios[], int tam_servicios)
{
    int i;
    int index;
    index = DESOCUPADO;
    for(i=0; i<tam_servicios;i++)
	{
		if(servicios[i].isEmpty == DESOCUPADO)
		{
			index = i;
			break;
		}
	}

    return index;
}

int BuscarIdServicios(int idIngreasado,eServicio servicios[],int tam_servicios)
{
    int i;
    int resultado;

    resultado = DESOCUPADO;

    for(i=0;i<tam_servicios;i++)
    {
        if(idIngreasado == servicios[i].idServicio)
        {
            resultado = OCUPADO;
            break;
        }
    }
    return resultado;
}

int PedirIdServicios(eServicio servicios[],int tam_servicios)
{
	int idIngreasado;
	int verificar;
	char confirmar;

	do
	{
		MostrarListadoServicios(servicios, tam_servicios);
		idIngreasado = GetInt("Ingrese el id correspondiente: ");
		verificar = BuscarIdServicios(idIngreasado, servicios, tam_servicios);

		while(verificar == DESOCUPADO)
		{
			MostrarListadoServicios(servicios, tam_servicios);
			idIngreasado = GetInt("ERROR.Ingrese el id correspondiente: ");
			verificar = BuscarIdServicios(idIngreasado, servicios, tam_servicios);
		}

		confirmar = GetChar("Seguro/a (s/n): ");
	}while(confirmar != 's');


	return idIngreasado;
}

void MostrarListadoServicios (eServicio servicios[], int tam_servicios)
{
    int i;


    for(i=0; i<tam_servicios; i++)
    {
    	if(servicios[i].isEmpty == OCUPADO)
    	{
    		printf("%d----%s----%.2f\n", servicios[i].idServicio, servicios[i].descripcion, servicios[i].precio);
    	}
    }
}
