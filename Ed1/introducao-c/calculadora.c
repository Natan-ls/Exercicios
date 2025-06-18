#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main(){
	
	setlocale (LC_ALL,"Portuguese_Brazil");

	int num1,num2;
	char operacao, pergunta = 'N';
	int x;
	
	while (1){

		printf ("Digite um número: \n");
		scanf (" %d", &num1);
		printf ("Digite a operação que deseja fazer: \n");
		scanf (" %c", &operacao);
		printf ("Digite outro número: \n");
		scanf (" %d", &num2);
	
		switch (operacao){
	
			case '+' : 
				printf ("%d + %d = %d",num1,num2,num1 + num2);
				break; 
			case '-' :
				printf ("%d - %d = %d",num1,num2,num1 - num2);
				break;
			case '*' :	
				printf ("%d x %d = %d",num1,num2,num1 * num2);			
				break;
			case '/' :
				printf ("%d / %d = %d",num1,num2,num1 / num2);
				break;
			case '%' :
				printf ("O resto desta divisão é: %d",num1 % num2);
				break;
			case '^' :
				x = num1;
				for (int y = 1; y < num2; y++){
					x *= num1;
				}
				printf ("%d^%d = %d",num1,num2,x);						
				break;
			default :	
				printf ("Opção Inválida!\n ");			
							
		}

		printf ("\n\n\tDeseja encerrar (S/N)?\n\n");
		scanf (" %c", &pergunta);
		setbuf(stdin, NULL);
		getchar();
		system ("cls");

		if (pergunta == 'S' || pergunta == 's')
			break;
	}	
	

	return 0;
}

