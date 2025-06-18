#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Múltiplicação dos vetores 
*/

int main(){
	srand(time(NULL));
	int num,x=0,sorteio,resp=0,cont=0;
	
	do {
		printf("Digite a quantidade de números que deseja sortear: \n");
		scanf(" %d", &num);
		if (num<0){
			printf ("Número inválido!\n");
			continue;
		}
	}while(num<0);

	do{
		printf("Digite o valor máximo para ser sorteado: \n");
		scanf (" %d",&x);
		if (x>num)
			break;
	}while(1);
	
	printf("\nVet1: ");
	int vet1[num],vet2[num];
	
	do{
		sorteio=rand()%x;
		resp=0;
		for(int a=0; a<cont; a++){
			if (sorteio==vet1[a]){
				resp=1;
				break;
			}
		}
		if (!resp){
			vet1[cont]=sorteio;
			printf("%d ",vet1[cont]);
			cont++;
		}
	}while(cont<num);
	
	cont=0;
	printf("\nVet2: ");
	
	do{
		sorteio=rand()%x;
		while(sorteio==vet1[cont]){
			sorteio=rand()%x;
		}
		resp=0;
		for (int a=0; a<cont; a++){
			if (sorteio==vet2[a]){
				resp=1;
				break;
			}
		}
		if (!resp){
			vet2[cont]=sorteio;
			printf("%d ",vet2[cont]);
			cont++;			
		}

	}while(cont<num);
	
	for (int a=0; a<num; a++)
		printf ("\n\n%d x %d = %d\n", vet1[a], vet2[a], vet1[a]*vet2[a]);
	return 0;
}



