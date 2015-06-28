#include <stdio.h>
#include <stdlib.h>

#include"funcionesArrayList.h"
#include"funciones.h"
#include "funcionesParaArray.h"



/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	//variables
	char resp = 's';
	int aux;
	int i;
	int opcion;
	int a = 0;
	
	
	
	
	//Creo mi puntero de ArrayList
	ArrayList* self;
	
	//Constructor
	self = newArrayList();
	
	
	//funcionFread(self);
	
	while(opcion != 17)
	{
		printf("\n\tMENU\n");
		printf("1-Add\n");
		printf("2-Remove\n");
		printf("3-Set\n");
		printf("4-Get\n");
		printf("5-Push\n");
		printf("6-Pop\n");
		printf("7-IndexOf\n");
		printf("8-Size\n");
		printf("9-Contains\n");
		printf("10-ContainsAll\n");
		printf("11-isEmpty\n");
		printf("12-Clone\n");
		printf("13-subList\n");
		printf("14-Clear\n");
		printf("16-Mostrar\n");
		printf("17-Salir");		
		
		do
		{	
			printf("\nIngrese opcion: ");
			scanf("%d", &opcion);
			fflush(stdin);
		
		
			if(a == 0)
			{
				if(opcion != 1 && opcion != 17 && opcion != 11 && opcion != 16)
					printf("\nDebe ingresar algun producto antes para realizar esta accion\n\n");
				else	
					a = 1;
			}
			
		}while(a == 0);
		
		
		system("cls");
		
		
				
		switch(opcion)
		{
			case 1:
				ingresarNumeros(self);
							
				break;
				
			case 2:
				eliminarElemento(self);
				
				break;
				
			case 3:
				ingresarElementoEnIndice(self);
				
				break;
				
			case 4:
				retornaElemento(self);
				
				break;
				
			case 5:
				insertaElemento(self);
				
				break;
				
			case 6:
				muestraElimina(self);
				
				break;
				
			case 7:
				muestraIndice(self);
				
				break;
				
			case 8:
				muestraTamanioLista(self);
				
				break;
				
			case 9:
				compruebaElemento(self);
				
				break;
				
			case 10:
				compruebaLista(self);
				
				break;
				
			case 11:
				listaVacia(self);
				
				break;
				
			case 12:
				clonarLista(self);
				
				break;
				
			case 13:
				subConjunto(self);
				
				break;
							
			case 14:
				borrarElementosLista(self);
				
				break;
				
			case 16:
				mostrar(self);
				
				break;
				
			case 17:
				printf("\nSalio del programa");
				break;
			
			default:
				printf("\nERROR, ingrese una opcion del menu\n");
				break;
		}
		
		
	}
	
	system("PAUSE");
	return 0;
}
