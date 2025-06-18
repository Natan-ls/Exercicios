#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Leia um número intero positivo, sorteia os números desse intervalo e
 * troque os números pela metade.
*/

int main(){
	srand(time(NULL));
	
	int x;
	do {
		printf ("Informe um número que seja par e maior que 10:\n");
		scanf (" %d", &x);
		if (x>=10 && x%2==0){
			break;
		}
	} while(1);
	int v[x], metade=x/2;
	
	for (int cont=0; cont<x; ){
		int sorteio=rand()%x,resp=0;
		for (int a=0; a<cont; a++){
			if (sorteio==v[a]){
				resp++;
				break;
			}
		}
		if (!resp){
			v[cont]=sorteio;
			printf(" %d ", v[cont]);
			cont++;
		}
	}
	
	printf("\n");
	
	for (int cont=0; cont<x; cont++){
		if (cont<metade){
			int troca=v[cont+metade];
			v[cont+metade]=v[cont];
			v[cont]=troca;
		}
		printf (" %d ", v[cont]);
	}
	return 0;
}



