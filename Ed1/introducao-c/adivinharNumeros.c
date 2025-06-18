#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int num = 0,cont = 0;
		
	srand(time(NULL));
	int numSorteado = rand() % 11;
	
	do{	
		printf ("Adivinhe o número entre \"0-10\": \n");
		scanf (" %d", &num);
		cont++;	
		
		if (num != numSorteado){
			continue;
		} 
		
		if (num == numSorteado)
			break;
		
	} while (1);
	
	printf("O número sorteado foi: %d\n", numSorteado);
	printf ("Total de %d tentativas.", cont);
	
	return 0;
}

