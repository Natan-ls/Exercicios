#include <stdlib.h>
#include <stdio.h>

int main(){
	
	do{		
		int k,cont=0;
		do{
			printf ("Informe um número inteiro maior que dez: \n");
			scanf (" %d", &k);
			if (k>10)
				break;
		}while(1);
		
		int num[2]={k,k};
		
		do{
			num[0]/=10;
			cont++;
			if (num[0]<10)
				break;
		}while(1);
		
		int vet[cont+1];
		
		for (int a=0; a<cont+1; a++){
			vet[a]=num[1]%10;
			num[1]/=10;
		}
		
		int x=0,y=cont;
		
		for (int a=0; a<cont+1; a++){
			for (int b=y; b>0; b-- ){
				vet[a]*=10;
			}
			x+=vet[a];
			y--;	
		}
		
		if (k==x)
			printf ("\nNúmero palídromo.");
		if (k!=x)	
			printf ("\nNão é um número palídromo.");
		setbuf(stdin,NULL);
		getchar();
		system("clear");	
	}while(1);
	return 0;
}

