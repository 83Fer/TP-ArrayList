#include <stdio.h>
#include <stdlib.h>

#include"funcionesArrayList.h"
#include"funciones.h"
#include "funcionesParaArray.h"

//Constructor del ArrayList

ArrayList* newArrayList()
{
	ArrayList* self; //creo un puntero
	
	self = (ArrayList*) malloc(sizeof(ArrayList));  
	
	self -> pElements = malloc(INCREMENTO * sizeof(void*));
	
	self -> reservedSize = INCREMENTO; 

	self -> size = 0;



	//Asignacion de las funciones a los punteros a funciones

	self -> add = add;
	
	self -> remov = remov;
	
	self -> clear = clear;
	
	self -> set = set;
	
	self -> get = get;
	
	self -> push = push;
	
	self -> pop = pop;
	
	self -> indexOf = indexOf;
	
	self -> sizes = sizes;
	
	self -> contains = contains;
	
	self -> containsAll = containsAll;
	
	self -> isEmpty = isEmpty;
	
	self -> clone = clone;
	
	
	
	return self;
	
}


//Cargar elementos al Arraylist

void add(ArrayList* self, void* element)
{
	
	
	if(self -> size  == self -> reservedSize)
	{		
		reSizeUp(self);
		
		self -> pElements[self->size] = element;
		
		self -> reservedSize += INCREMENTO;
		
		self->size++;
	}
	else
	{
		self -> pElements[self->size] = element;
		self -> size++;
	}
	
}


//incrementa y decrementa mi lista reservada
void reSizeUp(ArrayList* self)
{
	void* tmp_ptr;

	
	tmp_ptr = (void*) realloc(self->pElements, (sizeof(void*)) * (self->reservedSize + INCREMENTO));
		
	if(tmp_ptr == NULL)
	{
		printf("ERROR, no hay mas memoria");
		system("PAUSE");
	}
		
	else
		self -> pElements = tmp_ptr;
	
}

//Mostrar los elementos del ArrayList

void mostrar(ArrayList* self)
{
	int i;
	
	if(self -> size > 0)
	{
		printf("POSICIONES\tVALORES\n");
		
		for(i = 0; i < self->size ; i++)
		{
			printf("[%d]\t\t%d\n", i+1 , *(int*)(self->pElements[i]));
		}
		
		printf("\nLa memoria reservada es de %d posiciones\n", self -> reservedSize);
	}
	else
		printf("\nDebe ingresar por lo menos un elemento a la lista\n");
		
	system("PAUSE");
	
	system("cls");
	
}



//Borra por completo el ArrayList

void clear(ArrayList* self)
{
	
		free(self);
			
		self = newArrayList();
		
}

//Borra un elemento de la lista
void remov(ArrayList* self, int index)
{
	int i;
	
	decrecimientoLista(self);
	
	for(i=index; i < self -> size ; i++)
	{
		self -> pElements[i] = self -> pElements[i+1];
	}
	
	
	
	self -> size--;
	
	
}

//Ingresa un elemento en una posicion
void set(ArrayList* self, int index, void*element)
{
	
	self->pElements[index] = element;
	
}


//retorna un elemento
void* get(ArrayList* self, int index)
{
	
	return self->pElements[index];
	
}


//Inserta un elemento a la lista
void push(ArrayList* self, int index, void* element)
{
	
	int i;
	
	incrementoLista(self);
	
	for(i = (self->size-1); i >= index ; i--)//para no pisar el elemeto empiezo del final
	{
		self -> pElements[i + 1] = self -> pElements[i];
	}
	
	self -> pElements[index] = element;
	
	self -> size++;	
	
}


//Muestra y elimina un elemento
void* pop(ArrayList* self, int index)
{
	void* elemento;
	
	
	elemento = self->pElements[index];
	
	self->remov(self, index); 
	
	return elemento;
}

//Muestra el indice del elemento
int indexOf(ArrayList* self, void* element)
{
	int i;
	
	for(i = 0; i < self->size; i++)
	{
		if(*(int*)(element) == *(int*)(self->pElements[i]))
			return i++;
		
	}
	
	if(self->size == i)
		return -1;
		
}


//Muestra tamaño de lista
int sizes(ArrayList* self)
{
	return self->size;
}


//comprueba que exista el elemento en la lista
int contains(ArrayList* self, void* element)
{
	int i;
	
	for(i = 0; i < self->size; i++)
	{
		if(*(int*)(element) == *(int*)(self->pElements[i]))
			return 1;
		
	}
	
	if(self->size == i)
		return 0;

}


//Comprueba si existen los elementos en la lista
int containsAll(ArrayList* self, ArrayList* array)
{
	int i;
	int j;
	
	ArrayList* ptrLista;
	
	ptrLista = newArrayList();
	
	ptrLista = self->clone(self);
	
	
	
	for(i = 0; i < array->size; i++)
	{
		for(j = 0; j < ptrLista->size; j++)
		{
			if(*(int*)(array->pElements[i]) == *(int*)(ptrLista->pElements[j]))
			{
				
				*(int*)ptrLista->pElements[j] = NULL; 

				break;
				
				
			}
			if(ptrLista->size == j+1)
				return 0;
		
		}
	
	
	}
	
	free(ptrLista);
	
	return 1;
}


//comprueba si contiene elementos
int isEmpty(ArrayList* self)
{
	if(self->size < 1)
		return 0;
	else 
		return 1;
}


//clona lista
ArrayList* clone(ArrayList* self)
{
	int i, *elementAux;
	ArrayList* listaAux;
	
	
	listaAux = newArrayList();
	
	
	for(i = 0; i < self->size; i++)
	{
		elementAux = (int*) malloc(sizeof(int));
		
		*elementAux = *(int*)self->pElements[i];
		
		listaAux->add(listaAux, elementAux);
		
	}
	
	return listaAux;
}


//funcion subList()
ArrayList* subList(ArrayList*self, int from, int to)
{
	int i, *elementAux;
	
	ArrayList* listaAux;
	
	
	listaAux = newArrayList();

	
	for(i = from; i <= to; i++)
	{
		elementAux = (int*) malloc(sizeof(int));
		
		*elementAux = *(int*)(self->pElements[i]);
		
		listaAux->add(listaAux, elementAux);
		
		
	}
	
	return listaAux;
}



//Funciones a parte


void decrecimientoLista(ArrayList* self)
{
	//decrecimento mi lista reservada si es necesario
	if((self->reservedSize - (self->size-1)) > INCREMENTO)
	{
		self->reservedSize=	self->reservedSize - INCREMENTO ;
		
		
		
		reSizeUp(self);
	
	}
}

void incrementoLista(ArrayList* self)
{
		//Incremento mi lista reservada si es necesario
		if(self->reservedSize == self->size)
		{	
		
			reSizeUp(self);
		
			self->reservedSize+=INCREMENTO;
		}

}
