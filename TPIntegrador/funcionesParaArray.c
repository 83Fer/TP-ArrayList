#include <stdio.h>
#include <stdlib.h>

#include"funcionesArrayList.h"
#include"funciones.h"
#include "funcionesParaArray.h"



void ingresarNumeros(ArrayList* self)
{
	char resp = 's';
	int* element;
	
	do
	{
		element = (int*) malloc(sizeof(int));
		
		*element = pedirNumero("Ingrese un numero: ");
		
		self -> add(self, element);
		
		resp = preguntarSiSeguir("Desea continuar?s/n: ");
		
		resp = tolower(resp);
		
	//	fwrite(self->pElements, sizeof(self), 1, datos);
		
	}while(resp != 'n');
}

//funcion para CLEAR()
void borrarElementosLista(ArrayList* self)
{
		char resp = 's';
	
	resp = preguntarSiSeguir("\nSeguro que desea borrar por completo la lista?s/n: ");
	resp = tolower(resp);
	
	if(resp == 's')
	{
		if(self -> size > 0)
		{
			self -> clear(self);
		}
		else
			printf("\nNo existe una lista a borrar\n");
		
	}

	//No se hace nada
}


//funcion para REMOVE()
void eliminarElemento(ArrayList* self)
{
	int i;
	char resp;
	
	do
	{
		
		resp = 'n';
		
		i = pedirNumero("Ingrese la posicion en la lista que desea borrar: ");
	
		i--;
	
		if(longitudLista(self, i) == 0)
			resp = preguntarSiSeguir("\nLa posicion no existe\nDesea volver a intentarlo?s/n: ");
		else
		{
			self -> remov(self, i);
			printf("\nPosicion borrada");
			
		}
			
			
		resp = tolower(resp);

	}while(resp != 'n');
	
	
	
	system("PAUSE");
	
}


//funcion para SET()
void ingresarElementoEnIndice(ArrayList* self)
{
	int i;
	char resp;
	int* numero;
	
	do
	{
		resp = 'n';
		
		i = pedirNumero("Ingrese la posicion de la lista que desea insertar: ");
	
		i--;
	
		if(!longitudLista(self, i))
			resp = preguntarSiSeguir("\nLa posicion no existe\nDesea volver a intentarlo?s/n: ");
		else
		{
			numero = (int*) malloc(sizeof(int));
	
			*numero = pedirNumero("Ingrese un numero a la posicion: ");
	
			self->set(self, i, numero);
			
			printf("\nValor agregado con exito\n");

		}		
		resp = tolower(resp);

	}while(resp != 'n');
	
		
	
	
	
	system("PAUSE");
}

//funcion para get
void retornaElemento(ArrayList* self)
{
	int i;
	char resp;
	
	do
	{
		resp = 'n';
		
		i = pedirNumero("Ingrese la posicion de la lista que desea obtener: ");
	
		i--;
	
		if(!longitudLista(self, i))
			resp = preguntarSiSeguir("\nLa posicion no existe\nDesea volver a intentarlo?s/n: ");
		else
		{
				
			printf("\nEl conenido de la posicion [%d] es: %d\n", i+1 , *(int*)(self->get(self, i)));
			

		}		
		resp = tolower(resp);

	}while(resp != 'n');
	
		
	
	
	
	system("PAUSE");	
}

//funcion para push()
//inserta elemento en la lista
void insertaElemento(ArrayList* self)
{
	
	int i;
	char resp;
	int* numero;
	
	
	
	do
	{
		resp = 'n';
		
		i = pedirNumero("Ingrese la posicion de la lista que desea insertar: ");
	
		i--;
	
		if(!longitudLista(self, i))
			resp = preguntarSiSeguir("\nLa posicion no existe\nDesea volver a intentarlo?s/n: ");
		else
		{
			numero = (int*) malloc(sizeof(int));
	
			*numero = pedirNumero("Ingrese un numero a la posicion: ");
			
	
			self->push(self, i, numero);
			
			printf("\nElemento agregado con exito\n");

		}		
		resp = tolower(resp);

	}while(resp != 'n');
	
		
	
	
	
	system("PAUSE");
	
}


//funcion para pop()
void muestraElimina(ArrayList* self)
{
	int i;
	char resp;
	
	do
	{
		resp = 'n';
		
		i = pedirNumero("Ingrese la posicion de la lista que desea obtener: ");
	
		i--;
	
		if(!longitudLista(self, i))
			resp = preguntarSiSeguir("\nLa posicion no existe\nDesea volver a intentarlo?s/n: ");
		else
		{
				
			printf("\nEl conenido de la posicion [%d] es: %d\n", i+1 , *(int*)(self->pop(self, i)));
			printf("\nHa sido eliminada\n");

		}		
		resp = tolower(resp);

	}while(resp != 'n');
	
		
	
	
	
	system("PAUSE");	
}


//funcion para indexof()
void muestraIndice(ArrayList* self)
{
	int* numero;
	char resp;
	
	
	do
	{
		resp = 'n';
		
		numero = (int*) malloc(sizeof(int));
		
		*numero = pedirNumero("Ingrese un numero para buscar en la lista: ");
		
		if(self->indexOf(self, numero) == -1)
		{
			printf("\nEl numero ingresado no se encuentra en la lista\n");
			
			resp = preguntarSiSeguir("\nDesea volver a intentarlo?s/n: ");
		}
		
		else
		{
				
			printf("\nEl valor ingresado se encuentra primero en el indice [%d]\n", self->indexOf(self, numero) + 1);

		}		
		resp = tolower(resp);

	}while(resp != 'n');
	
		
	
	
	
	system("PAUSE");	
	
}


//funcion size()
void muestraTamanioLista(ArrayList* self)
{
	printf("El tamanio de la lista es: %d\n", self->sizes(self));
	
	system("PAUSE");
	system("cls");
}


//funcion contains()
void compruebaElemento(ArrayList* self)
{
	int* numero;
	char resp;
	
	
	do
	{
		resp = 'n';
		
		numero = (int*) malloc(sizeof(int));
		
		*numero = pedirNumero("Ingrese un numero para buscar en la lista: ");
		
		if(!self->contains(self, numero))
		{
			printf("\nEl numero ingresado no se encuentra en la lista\n");
			
			resp = preguntarSiSeguir("\nDesea volver a intentarlo?s/n: ");
		}
		
		else
		{
				
			printf("\nEl valor ingresado se encuentra en la lista\n", self->contains(self, numero) + 1);

		}		
		resp = tolower(resp);

	}while(resp != 'n');
	
		
	
	
	
	system("PAUSE");	
	
}


//funcion containsAll()
void compruebaLista(ArrayList* self)
{
	int* aux;
	ArrayList* array;
	
	char resp = 's';
	
	
	array = newArrayList();
	
	do
	{
		aux = (int*) malloc(sizeof(int));
		
		*aux = pedirNumero("Ingrese un numero: ");
		
		array -> add(array, aux);
		
		resp = preguntarSiSeguir("Desea continuar?s/n: ");
		
		resp = tolower(resp);
		
	}while(resp != 'n');
	
	if(array->sizes(array) > self->sizes(self))
		printf("\nLos elementos a analizar superan el tamanio de la lista a comparar\n");
	
	else
	{
		if(!self->containsAll(self, array))
			printf("\nLos elementos a analizar no coinciden\n");
			
		else 
			printf("\nLos elementos analizados coinciden\n");
	}
	
	free(array);	
	
}


//funcion isEmpty()
void listaVacia(ArrayList* self)
{
	
	if(!self -> isEmpty(self))
		printf("\nNo hay elementos en la lista\n");
	else
		printf("\nLa lista contiene elementos");
		
}


//funcion clone
void clonarLista(ArrayList* self)
{
	ArrayList* listaClon;
	
	listaClon = self -> clone(self);
	
	
	printf("\nLISTA CLONADA\n");
	
	mostrar(listaClon);
	
	free(listaClon);
	
	printf("\n");
}



//funcion subList()
void subConjunto(ArrayList* self)
{
	int to, from;
	char resp;
	
	ArrayList* subLista;
	
	do
	{
		resp = 'n';
		
		from = pedirNumero("Ingrese la posicion desde donde desea empezar a copiar: ");
		
		to = pedirNumero("Ingrese la posicion hasta donde desea terminar de copiar: ");
	
		from--;
		to--;
		
		if(from > to)
			resp = preguntarSiSeguir("\nLas posiciones ingresadas son incorrectas\nDesea volver a intentarlo?s/n: ");
	
		else if(!longitudLista(self, from)||!longitudLista(self, to))
			resp = preguntarSiSeguir("\nLas posiciones ingresadas son incorrectas\nDesea volver a intentarlo?s/n: ");
		else
		{
			
			subLista = subList(self, from, to);
				
			printf("\nCONTENIDO DE LA SUBLISTA\n");
			
			mostrar(subLista);
			

		}		
		resp = tolower(resp);

	}while(resp != 'n');

	free(subLista);
	
}
