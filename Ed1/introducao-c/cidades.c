#include <stdio.h>
#include <stdlib.h>

int main(){
		
	int cidadeA = 0, cidadeB = 0;
	float porcentoA = 0.0, porcentoB = 0.0;
	int cont = 0;
		
	printf ("Informe o número de habitantes da cidade A: \n");
	scanf (" %d", &cidadeA);
	printf ("Informe a taxa de natalidade ao ano da cidade A: \n");
	scanf (" %f", &porcentoA);
	printf ("Informe o número de habitantes da cidade B: \n");
	scanf (" %d", &cidadeB);
	printf ("Informe a taxa de natalidade ao ano da cidade B: \n");
	scanf (" %f", &porcentoB);
	
	do {
				
		cidadeA = (float) cidadeA + ((cidadeA * porcentoA)/100);
		cidadeB = (float) cidadeB + ((cidadeB * porcentoB)/100);		
		
		if (porcentoA <= porcentoB){
			printf ("A cidade A nunca irá alcançar a cidade B. \n");
			break;
		}
		cont ++;
	} while (cidadeA < cidadeB);
	if(cont)
		printf ("A cidade A irá ultrapassar a cidade B em %d anos. \n", cont);
	return 0;
}



