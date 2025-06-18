#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Sortear N números e calcular a potência com base em um número escolhido
 * pelo usuário 
*/

int main(){
	int x,n;
	
	do{
		printf("Informe a quantidade de números a ser sorteado:\n");
		scanf (" %d", &n);
		if (n<0){
			printf("Número inválido!\n");
		}
	}while(n<0);
	
	do{
		printf("Informe o número de x:\n");
		scanf(" %d", &x);
		if (x<0){
			printf("Número inválido!\n");
		}
	}while(x<0);
	
	int vetor[2][n];

	for (int a=0; a<n; a++){
		vetor[0][a]=rand()%20;
		vetor[1][a]=vetor[0][a];
	}
	
	for (int a=0; a<n; a++){
		if(x==0){
			vetor[1][a]=1;
		}
		else{	
			for (int b=0; b<x-1; b++){
				vetor[1][a]*=vetor[0][a];
			}
		}	
	}
	
	for (int a=0; a<n; a++){
		printf("%d^%d = %d\n", vetor[0][a], x, vetor[1][a]);
	}

	return 0;
}



