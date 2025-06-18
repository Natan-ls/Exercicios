#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Calcular média dos números sorteados 
 */

int main(){
	srand(time(NULL));

	int num,acumulo=0;
	do {
		printf ("Informe a quantidade de números a ser sorteado: \n");
		scanf (" %d", &num);
		if (num<=0){
			printf ("Número inválido!\n");
		}
	} while (num<=0);
	int v[num],maior=-1,menor=10;
	
	for (int x=0; x<num; x++){
		v[x]=rand()%10;
		printf(" %d ", v[x]);
		if (v[x]>maior){
			maior=v[x];
		}
		if (v[x]<menor){
			menor=v[x];
		}
	}
	int cont=0;
	for (int x=0; x<num; x++){
		if (v[x]!=maior && v[x]!=menor){
			acumulo+=v[x];
			cont++;
		}
	
	}
	printf ("\nA média do valores sorteados é: %.2f", (float) acumulo/cont);
	return 0;
}



