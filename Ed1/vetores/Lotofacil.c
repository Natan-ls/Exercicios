#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 15

int main(){
	srand(time(NULL));
	
	int cont=0, rep=0, sorteio=0;
	int vet[MAX]={0};
	
	do{
		sorteio=1+rand()%24;
		rep=0;
		for (int x=0; x<cont; x++){
			if (sorteio==vet[x]){
				rep=1;
				continue;
			}
		}	
		if (!rep){
			vet[cont]=sorteio;
			if(cont == MAX-1)
				printf("%d",vet[cont]);
			else
				printf("%d - ",vet[cont]);
			cont++;
		}	
	}while (cont < MAX);	
	return 0;
}



