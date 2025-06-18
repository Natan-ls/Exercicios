#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	srand (time(NULL));
	
	int numSorteio[100] = {0};
	int cont = 0, num = 0;
	
	for (int x = 0; x < 100; x++ ){
		numSorteio[x] = rand () % 10;
		//printf ("%d º: %d\n",x, numSorteio[x]);
	}
	printf ("Escolha um número de (0-9) para saber a quantidade de vezes em que ele foi sorteado: ");
	scanf (" %d", &num);
	
	system ("clear");
	
	for (int y = 0; y < 100; y++){
		if (num == numSorteio [y])
			cont++;
	}		
	printf ("O número %d foi sorteado %d vezes.", num, cont);
			
	return 0;
}



