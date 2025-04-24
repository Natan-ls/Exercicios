#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void sorteioNumeros(int vetor[], int n, int opc){
	srand(time(NULL));
	for (int x=0; x<n; ){
		int numero = opc == 1? rand() % (2*n) : rand()% n;
		int aux = 0;
		// Números sem repetição
		if(opc == 1){
			for(int y=0; y<x; y++){
				if(vetor[y] == numero){
					aux = 1;
					break;
				}
			}
			if(!aux){
				vetor[x] = numero;
				x++;
			}
		}
		// Números com repetição
		if(opc == 2){
			vetor[x] = numero;
			x++;
		}
	}
}

void mostrarNumeros(int vetor[], int n){
	for (int x=0; x<n; x++){
		printf ("%d ", vetor[x]);
	}	
	printf("\n");
}

void trocaNumero(int vet[], int indice_1, int indice_2){
	int aux = vet[indice_1];
	vet[indice_1] = vet[indice_2];
	vet[indice_2] = aux;
}

void criaArvore(int vetor[], int pai, int quantidade){
	int filho_e = (pai * 2) + 1;
	int filho_d = (pai * 2) + 2;
	int indice_maior = pai;
	
	if((filho_e < quantidade) & (vetor[filho_e] > vetor[pai]))
		indice_maior = filho_e;
	if((filho_d < quantidade) & (vetor[filho_d] > vetor[indice_maior]))
		indice_maior = filho_d;
	if(pai != indice_maior){
		trocaNumero(vetor, indice_maior, pai);
		criaArvore(vetor, indice_maior, quantidade);
	}
}

void heapSort(int vetor[], int quantidade){
	//Fase 1 do heapSort
	for (int x=quantidade/2-1; x>=0; x--){
		criaArvore(vetor, x, quantidade);
	}
	//Fase 2 do heapSort
	for(int x=0; x<quantidade-1; x++){
		trocaNumero(vetor, 0, quantidade - (x+1));
		criaArvore(vetor, 0, (quantidade - (x+1)));
	}
}

int main(){
	int quantidade;

	printf("Informe a quantidade de números para o sorteio:\n");
	scanf(" %d", &quantidade);
	if(quantidade <= 0)
		return 0;
	else{
		int vet[quantidade];
		// 1 - Para retornar números sorteados repetidos
		// 2 - Para retornar números sorteados únicos
		sorteioNumeros(vet, quantidade, 1);
		printf("\nNúmeros sorteados:\n");
		mostrarNumeros(vet, quantidade);
		printf("\nNúmeros ordenados com o HeapSort:\n");
		heapSort(vet, quantidade);
		mostrarNumeros(vet, quantidade);
	}
}

