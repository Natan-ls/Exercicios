#include <stdio.h>

int main(){
	
	int num1,num2;
	printf ("Digite o número que irá comerçar a contagem: ");
	scanf (" %d", &num1);
	printf ("Digite o número que irá calcular: ");
	scanf(" %d",&num2);
	
	int multiplicacao = num1, soma = num1;
	
	printf("Resultados da multiplicação\n");
	for (int cont = 0; cont <= 9; cont++){
		
		printf (" %d\t", multiplicacao);
		if ( cont == 9)
			printf (" %d\n", multiplicacao);
		multiplicacao *= num2;
	}
	printf("Resultados da soma\n");	
	for (int cont2 = 0; cont2 <= 9; cont2++){
	
		printf ("%d\t", soma);
		soma += num2;
	}
	
	return 0;
}



