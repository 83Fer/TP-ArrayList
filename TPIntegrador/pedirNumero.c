#include<stdio.h>
#include<stdlib.h>

#include"pedirNumero.h"

int pedirNumero()
{
	int numero;
	
	do{
		
		printf("\nIngrese un numero: ");
		scanf("%d", &numero);
		fflush(stdin);

	}while(numero < -20000 || numero > 20000);
	
	return numero;

}
