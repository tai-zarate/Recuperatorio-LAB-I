#include "Trabajo.h"
/**
 * Inicializas los id
 */
void InicializarTrabajo(eTrabajo trabajos[], int tam)
{
    int i;

    for(i=0; i<tam;i++)
	{
    	trabajos[i].isEmpty = DESOCUPADO;
	}
}

/**
 * Busca los espacios libres
 */
int BuscarLibreTrabajo(eTrabajo trabajos[], int tam)
{
    int i;
    int index;
    index =DESOCUPADO;
    for(i=0; i<tam;i++)
	{
		if(trabajos[i].isEmpty == DESOCUPADO)
		{
			index = i;
			break;
		}
	}

    return index;
}

int AsignarIdTrabajo(eTrabajo trabajos[], int tam)
{
	int i;
	int id;

	id = ContadorIsEmptyTrabajo(trabajos, tam);

	for(i=0;i<tam;i++)
	{
		if(trabajos[i].isEmpty == OCUPADO)
		{
			if(id==trabajos[i].idTrabajo)
			{
				id = id+1;
			}
		}
	}

	return id;
}

int ContadorIsEmptyTrabajo (eTrabajo trabajos[], int tam)
{
    int i;
    int contador;

    contador = 0;
    for(i=0; i<tam; i++)
    {
        if(trabajos[i].isEmpty == OCUPADO)
        {
            contador++;
        }
    }
    return contador;
}

eFecha PedirFecha()
{
	eFecha fecha;

	fecha.anio = AsignarFecha(1990,2022,"Ingrese el año: ", "ERROR.Ese año no está disponible: ");

	fecha.mes = AsignarFecha(1,12,"Ingrese el mes: ", "ERROR.Ese mes no está disponible: ");

	fecha.dia = PedirDia(fecha.mes, fecha.anio, "Ingrese el día: ", "ERROR.Ese día no está disponible: ");

    return fecha;
}

int AsignarFecha (int minimo, int maximo, char msj[], char msjError[])
{
	int numero;
	char confirmar;

	do
	{
		numero = GetInt(msj);

		while(numero < minimo || numero > maximo)
			{
				numero = GetInt(msjError);
			}

		confirmar = GetChar("Seguro/a (s/n): ");
	}while(confirmar != 's');

	return numero;
}

int PedirDia (int mes, int anio, char msj[], char msjError[])
{
	int dia;

	if(mes==1||mes==3||mes==5||mes==7||mes==8||mes==10||mes==12)
	{
		dia = AsignarFecha(1, 31, msj,msjError);
	} else
	{
		if(mes==4||mes==6||mes==9||mes==11)
		{
			dia = AsignarFecha(1, 30, msj,msjError);
		} else
		{
			if(anio % 400 == 0)
			{
				dia = AsignarFecha(1, 29, msj,msjError);
			} else
			{
				if(anio % 4 == 0 && anio % 100 != 0)
				{
					dia = AsignarFecha(1, 29, msj,msjError);
				} else
				{
					dia = AsignarFecha(1, 28, msj,msjError);
				}
			}
		}
	}

	return dia;
}

int BuscarIdTrabajo(int idIngreasado,eTrabajo trabajos[],int tam)
{
    int i;
    int resultado;


    resultado = DESOCUPADO;

    for(i=0;i<=tam;i++)
    {
        if(idIngreasado == trabajos[i].idTrabajo)
        {
            resultado=OCUPADO;
            break;
        }
    }
    return resultado;
}

void PedirNombre(char msj[], char *nombre)
{
	char confirmar;
	GetString(msj, nombre);

	confirmar = GetChar("Seguro/a (s/n): ");

	while(confirmar != 's')
	{
		GetString(msj, nombre);
		confirmar = GetChar("Seguro/a (s/n): ");
	}
}

void HardCodearTrabajos(eTrabajo trabajos[], int tam)
{
	int i;
	int idTrabajo[] = {2,1,4,3};
	int idMascota[] = {15,16,18,19};
	int idServicio[] = {20000,20001,20000,20002};
	int idEmpleado[] = {1,2,3,1};
	int anio[] = {2000,2000,2001,1999};
	int mes[] = {5,2,25,6};
	int dia[] = {1,4,12,30};
	int isEmpty[] = {OCUPADO,OCUPADO,OCUPADO,OCUPADO};

	for(i=0;i<tam;i++)
	{
		trabajos[i].idTrabajo = idTrabajo[i];
		trabajos[i].idMascota = idMascota[i];
		trabajos[i].idServicio = idServicio[i];
		trabajos[i].idEmpleado = idEmpleado[i];
		trabajos[i].fecha.dia = dia[i];
		trabajos[i].fecha.mes = mes[i];
		trabajos[i].fecha.anio = anio[i];
		trabajos[i].isEmpty = isEmpty[i];
		/*if(i == Numero a cortar si quiero agregar más por mi cuenta)
		{
			break;
		}*/
	}
}
