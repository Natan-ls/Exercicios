#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
 * Um baralho tem N cartas, não repetidas, numeradas entre 1-N. Faça um programa que leia N e imprima o resultado do embaralhamento de cartas.
*/ 
int main(){
	srand(time(NULL));
	
	int n;
	printf ("Informe a quantidade de cartas: \n");
	scanf (" %d", &n);
	int cartas[n],sorteio,cont=0;
	do{ 
		sorteio=1+rand()%n;
		int resp=0;
		for (int x=0; x<cont; x++){
			if (sorteio==cartas[x]){
				resp=1;
				break;
			}	
		}
		if (!resp){
			cartas[cont]=sorteio;
			printf(" %d",cartas[cont]);
			cont++;
		}	
	}while(cont<n);
	return 0;
}



