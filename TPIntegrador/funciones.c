#include <stdio.h>
#include <stdlib.h>

#include"funcionesArrayList.h"
#include"funciones.h"
#include "funcionesParaArray.h"

#include"archivos.h"

int pedirNumero(char mensaje[])
{
	int numero;
	
	printf("%s", mensaje);
	scanf("%d", &numero);
	fflush(stdin);
	
	return numero;
}


//Pregunta por si o por no
char preguntarSiSeguir(char mensaje[])
{
	char respuesta = 's';
	
	printf("%s", mensaje);
	scanf("%c", &respuesta);
	fflush(stdin);
	
	return respuesta;
}

//longitud de la lista
int longitudLista(ArrayList*self, int i)
{
	if(i >= self -> size || i < 0)
		return 0;//no existe
		
	else
		return 1;//existe
}






