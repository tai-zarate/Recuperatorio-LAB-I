#include "Mascotas.h"

void InicializarMascotas(eMascota mascotas[], int tam_mascota)
{
    int i;

    for(i=0; i<tam_mascota;i++)
	{
    	mascotas[i].isEmpty = DESOCUPADO;
	}
}

int BuscarLibreMascotas(eMascota mascotas[], int tam_mascota)
{
    int i;
    int index;
    index = DESOCUPADO;
    for(i=0; i<tam_mascota;i++)
	{
		if(mascotas[i].isEmpty == DESOCUPADO)
		{
			index = i;
			break;
		}
	}

    return index;
}

int BuscarIdMascotas(int idIngreasado,eMascota mascotas[], int tam_mascota)
{
    int i;
    int resultado;

    resultado = DESOCUPADO;

    for(i=0;i<tam_mascota;i++)
    {
        if(idIngreasado == mascotas[i].idMascotas)
        {
            resultado = OCUPADO;
            break;
        }
    }
    return resultado;
}

int PedirIdMascota(eMascota mascotas[], int tam_mascota)
{
	int idIngreasado;
	int verificar;
	char confirmar;

	do
	{
		MostrarListadoMascotas(mascotas, tam_mascota);
		idIngreasado = GetInt("Ingrese el id correspondiente: ");
		verificar = BuscarIdMascotas(idIngreasado, mascotas, tam_mascota);

		while(verificar == DESOCUPADO)
		{
			MostrarListadoMascotas(mascotas, tam_mascota);
			idIngreasado = GetInt("ERROR.Ingrese el id correspondiente: ");
			verificar = BuscarIdMascotas(idIngreasado, mascotas, tam_mascota);
		}

		confirmar = GetChar("Seguro/a (s/n): ");
	}while(confirmar != 's');

	return idIngreasado;
}

void MostrarListadoMascotas (eMascota mascotas[], int tam_mascota)
{
    int i;


    for(i=0; i<tam_mascota; i++)
    {
    	if(mascotas[i].isEmpty == OCUPADO)
    	{
    		printf("%d----%s----%d----%s\n", mascotas[i].idMascotas, mascotas[i].nombre, mascotas[i].edad, mascotas[i].raza);
    	}
    }
}
