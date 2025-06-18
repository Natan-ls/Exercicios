#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
 * 
 * 
*/
int main(){
	srand(time(NULL));
	
	int x,y;
	int sorteio=0,cont=0,resp;
	printf ("Informe dois números inteiros:\n");
	scanf (" %d %d", &x, &y);
	int vet1[x], vet2[y];
	printf("X: ");
	do{
		sorteio=rand()%(x+y); 
		resp=0;
		for(int a=0; a<x; a++){
			if (sorteio==vet1[a]){
				resp=1;
				continue;
			}
		}						
		if(!resp){
			vet1[cont]=sorteio;
			printf("%d - ", vet1[cont]);
			cont++;
		}					
	}while(cont<x);
	cont=0;
	printf("\nY: ");
	do{
		sorteio=rand()%(x+y);
		resp=0;
		for (int a=0; a<y; a++){
			if (sorteio==vet2[a]){
				resp=1;
				continue;
			}
		}
		if (!resp){
			vet2[cont]=sorteio;
			printf("%d - ", vet2[cont]);
			cont++;
		}
	}while(cont<y);
	printf("\n\nNumeros exclusivos do X: ");
	for (int a=0; a<x; a++){
		cont=0;
		for (int b=0; b<y; b++){
			if (vet1[a]!=vet2[b])
				cont++;
		}
		if (cont==y)
			printf ("%d - ",vet1[a]);
	}			
	printf("\n\nNumeros exclusivos do Y: ");
	for (int a=0; a<y; a++){
		cont=0;
		for(int b=0; b<x; b++){
			if (vet2[a]!=vet1[b])
				cont++;
		}
		if (cont==x)
			printf("%d - ",vet2[a]);
	}	
	printf("\n\nUnião X-Y: ");
	for (int a=0; a<x; a++){
		cont=0;
		for (int b=0; b<y; b++){
			if (vet1[a]!=vet2[b])
				cont++;
		}		
		if (cont<y)
			printf("%d - ", vet1[a]);
	}		
	return 0;
}



