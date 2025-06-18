#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int cont,conta,errado,recorde = 0;	
	int num[100], adiv[100];
	
	do{
		conta = 0;
		cont = 1;
		errado = 0;
		do{	
			srand(time(NULL));
			num[conta] = rand() % 9;
			printf ("\tRODADA %d\n\n",cont);
			if (conta == 0)
				printf ("%d ", num[conta]);
			if (conta != 0){	
				for (int x = 0; x < cont; x++){
					if (cont - x == 1){
						printf ("%d ", num[x]);
						break;
					}	
					if(x == cont-1)
						printf ("%d", num[x]);	
					else
						printf("%d - ", num[x]);
				}					
			}	
			printf ("\n\n\nTecla enter");
			setbuf(stdin,NULL);
			getchar();
			system ("clear");
			printf ("Digite os números informados na tela:\n");
			for (int x = 0; x < cont; x++){
				scanf(" %d", &adiv[x]);
				if (num[x] != adiv[x])
					errado++;
			}
			printf ("\nNumeros sorteado:\n");
			for (int x = 0; x < cont; x++){
				printf ("%d \t", num[x]);
				if (!x % 7 && x != 0)
					printf ("\n");
			}
			printf ("\nNumeros adivinhado:\n");
			for (int x = 0; x < cont; x++){
				printf ("%d \t", adiv[x]);
				if (!x % 7 && x != 0)
					printf ("\n");
			}		
			cont++;
			conta++;
			if (errado > 0){
				printf("\n\n\n\n\nPerdeu no nível %d!",cont-1);
				if (cont-1 > recorde){
					recorde = cont-1;
					printf ("\nNovo recorde alcançado!\nNível %d",recorde);
				}	
				printf ("\n");
				setbuf(stdin,NULL);
				getchar();
				system ("clear");
				break;
			}	
			printf ("\n\n\n");
			setbuf(stdin,NULL);
			getchar();
			system ("clear");
		}while (1);	
		
		char resposta = '0';
		printf ("1.Novo Jogo\t2.Encerrar\n");
		scanf (" %c", &resposta);
		if (resposta == '1'){
			setbuf(stdin,NULL);
			getchar();
			system("clear");
			continue;
		}	
		if (resposta == '2')
			break;
	}while(1);
	return 0;
}



