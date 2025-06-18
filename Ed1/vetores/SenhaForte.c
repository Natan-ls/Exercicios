#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 16
#define MIN 8
#define QUANTIDADESENHAS 10

int main(){
	srand(time(NULL));

	for (int x=0; x<QUANTIDADESENHAS; ){
		int tamanho = MIN + rand()% (MAX-MIN+1);
		int verificador[4]={0}, cont=0;
		char senha[tamanho+1];
		
		for (int y=0; y<tamanho; y++){
			int intervalo = rand()% 7, sorteio; 
		
			switch (intervalo) {
				case 0 :
					sorteio = 33 + rand()% (47-33+1);
					verificador[0]=1;
					break;
				case 1 :
					sorteio = 'A' + rand()% ('Z'-'A'+1);
					verificador[1]=1;
					break;
				case 2 :
					sorteio = 'a' + rand()% ('z'-'a'+1);
					verificador[2]=1;
					break; 
				case 3 :
					sorteio = '1' + rand()% ('9'-'1'+1);
					verificador[3]=1;
					break;
				case 4 :
					sorteio = 58 + rand()% (64-58+1);
					verificador[0]=1;
					break;	
				case 5 :
					sorteio = 91 + rand()% (96-91+1);
					verificador[0]=1;
					break;	
				case 6 :
					sorteio = 123 + rand()% (126-123+1);
					verificador[0]=1;
					break;

			}
			senha[y] = sorteio; 
		}
		
		senha[tamanho] = 0;
		
		for (int y=0; y<4; y++){
			cont+=verificador[y];
		}
		
		if (cont==4){
			printf ("Senha gerada: %s\n",senha);	
			x++;
		}	

	}

	return 0;
}



