#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
 * Gerar um vetor de K posições, onde 0<k<1000, calcular média,imprimir o maior e menor valor e informar qnts são pares e ímpares.
 */
int main(){
	srand(time(NULL));
	
	int num,par=0,impar=0,maior=0,menor=0,teste=1;
	float media=0.0;
	
	do{
		printf("Informe a quantidades de números: ");
		scanf(" %d", &num);
		
		if ( num<0 || num>1000){ 
			printf("Número inválido!\n");
			teste=0;
		}
					
	}while(!teste);
	
	int k[num],sorteio,cont=0;
	teste=0;
	
	do{
		sorteio=1+rand()%1000;
		for(int x=0; x<cont; x++){
			if (sorteio==k[x]){
				teste=1;
				break;
			}
		}
		if (!teste){
			k[cont]=sorteio;
			if (k[cont]%2==0)
				par++;
			if (k[cont]%2!=0)
				impar++;
			if (maior==0 && menor==0){
				maior=k[cont];
				menor=k[cont];
			}
			if (k[cont]>maior)
				maior=k[cont];
			if (k[cont]<menor)
				menor=k[cont];		
			media+=k[cont];
			cont++;
		}
	}while(cont<num);
	
	printf("\tQuantidades de números\nPares: %d\nÍmpares: %d\nMaior número: %d\nMenor número: %d\nMédia: %.2f\n\n", par, impar, maior, menor, (float)media/num);
	int numPar[par],numImpar[impar];
	int a=0;
	int b=0;
	for (int x=0; x<num; x++){
		if (k[x]%2==0){
			numPar[a]=k[x];
			a++;
		}
		if(k[x]%2!=0){
			numImpar[b]=k[x];
			b++;
		}
	}
	printf("Pares: ");
	for (int x=par-1; x>=0; x--){
		for (int y=0; y<x; y++){
			if (numPar[x]<numPar[y]){
				int troca=numPar[x];
				numPar[x]=numPar[y];
				numPar[y]=troca;
			}	
		}	
		printf ("%d  ",numPar[x]);
	}			
	printf ("\nÍmpares: ");
	for (int x=impar-1; x>=0; x--){
		for (int y=x-1; y>=0; y--){
			if (numImpar[x]<numImpar[y]){
				int troca=numImpar[x];
				numImpar[x]=numImpar[y];
				numImpar[y]=troca;
			}
		}		
		printf ("%d  ", numImpar[x]);
	}
	printf("\nNúmeros sorteados: ");
	for (int x=0; x<par; x++)
		printf ("%d  ", numPar[x]);
	return 0;
}



