

#include <stdio.h>
#include <stdlib.h>

#include"funcionesArrayList.h"
#include"funciones.h"
#include "funcionesParaArray.h"

#include"archivos.h"


int funcionFread(ArrayList* self) 
{
	FILE*datos;
	int cant;
	
	
	if((datos = fopen("Archivos.dat", "rb")) == NULL)
		if((datos = fopen("Archivos.dat", "wb")) == NULL)
		{
			printf("El archivo no se puede abrir");
			return 0;
		}
		
		while(!feof(datos))
		{
			cant = fread(self, sizeof(ArrayList), 1, datos);
			
			if(cant!=1)
			{
				if(feof(datos))
					break;
				else
				{
					printf("\nNo se leyo el ultimo registro\n");
					break;
				}
			}
		}
		
		return 1;

}


void funcionFwrite(ArrayList* self, FILE* datos)
{		
		
		if((datos = fopen("Archivos.dat", "wb")) == NULL)
			printf("Error");
}

