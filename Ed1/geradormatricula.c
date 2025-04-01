#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){

	do {
		srand(time(NULL));
		int num;
		printf ("Informe a quantidade de matrículas que deseja gerar: ");
		scanf (" %d", &num);
		
		for (int cont = 0; cont < num; cont++){
		
			int a = rand () % 10;
			int b = rand () % 10;
			int c = rand () % 10;
			int d = rand () % 10;
			int v = abs(a - b + c - d);
			
			if (v >= 10){
				
				int primeiroNum = v / 10;
				int segundoNum = v % 10;
				int codigoV = primeiroNum + segundoNum;
				
				printf ("%d%d%d%d-%d\n", a, b, c, d, codigoV);
				continue;
			}
			if (v < 10){
				printf ("%d%d%d%d-%d\n", a,b,c,d, v);
				continue;
			}			
		}
	
		printf ("Deseja gerar mais números de matrícula? (S/N)");
		char resposta;
		scanf (" %c", &resposta);
		setbuf(stdin, NULL);
		getchar();
		
		if (resposta == 'N' || resposta == 'n')
			break;
		if (resposta != 'N' && resposta != 'n'){
			system("clear");
			continue;
		}
	
	} while (1);
	return 0;
}



