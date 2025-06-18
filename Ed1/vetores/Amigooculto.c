#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	srand(time(NULL));
	int num;
	
	do {
		printf ("Informe a quantidade de pessoas que irá participar do A.O:\n");
		scanf (" %d", &num);
	} while (num<2 || num%2!=0);
	int vet[2][num];
	char nome[num][100];
	
	for (int a=0; a<num; a++){
		printf ("Informe o %dº nome:\n", a+1);
		scanf(" %[^\n]s", nome[a]);
	}
	
	for (int a=0; a<num; ){
		int sorteio=rand()%num,resp=0;
		for (int b=0; b<a; b++){
			if (vet[0][b]==sorteio){
				resp++;
				break;
			}
		}
		if (!resp){
			vet[0][a]=sorteio;
			a++;
		}
	}
	int teste=0;
	do{
		teste=0;
		for (int a=0; a<num; ){
			int sorteio=rand()%num,resp=0;

			for (int b=0; b<a; b++){
				if (vet[1][b]==sorteio){
					resp=1;
					break;
				}
			}
			if (!resp){
				vet[1][a]=sorteio;
				a++;
			}
		}
		printf("\n");
		for (int b=0; b<num; b++){
			if (vet[0][b]==vet[1][b]){
				teste++;
				break;
			}
		}
	}while (teste>0);
	
	printf ("\tNomes sorteados\n");
	for (int a=0; a<num; a++){
		printf ("%s ==>> %s\n", nome[vet[0][a]], nome[vet[1][a]]);
	}
	return 0;
}



