#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 100

/*
 * Cadastrar pessoas e sortear data de nascimentos para elas
*/

typedef struct {
	int dia , mes , ano;
}DataNascimento;

typedef struct {
	DataNascimento dataNasc;
	char nome[50];
	int idade;
}Pessoa;

void calculoIdade (Pessoa *endPessoa){
	time_t tempoS = time (NULL);
	struct tm *tempoS1 = localtime(&tempoS);
	
	if (tempoS1->tm_mday == endPessoa->dataNasc.dia && 
		tempoS1->tm_mon+1 == endPessoa->dataNasc.mes)
		endPessoa->idade = ((tempoS1->tm_year+1900) - endPessoa->dataNasc.ano);
	else 
		endPessoa->idade = ((tempoS1->tm_year+1900) - endPessoa->dataNasc.ano)-1;
}

void cadastroPessoa (Pessoa *endPessoa){
	printf ("Nome: ");
	scanf (" %[^\n]s", endPessoa->nome);
	endPessoa->dataNasc.dia = 1+ rand() %31;
	endPessoa->dataNasc.mes = 1+ rand() %12;
	endPessoa->dataNasc.ano = 1960+ rand() %(2022-1960);
	calculoIdade(endPessoa);
}

void listaPessoas(Pessoa *endPessoa, int cont){
	printf ("NOME\t\tNASCIMENTO\t\tIDADE\n");
	for (int x=cont-1; x>=0; x--){
		printf ("%s\t\t", (endPessoa+x)->nome);
		printf ("%02d/%02d/%02d\t\t", (endPessoa+x)->dataNasc.dia, 
				(endPessoa+x)->dataNasc.mes, (endPessoa+x)->dataNasc.ano);
		printf ("%d Anos\n", (endPessoa+x)->idade);
	}
}

void ordenar (Pessoa vet[], int cont){
	do {
		int rep = 0;
		if (cont>=1){
			for (int num=0; num<cont-1; num++){
				if (vet[num].idade>vet[num+1].idade){
					Pessoa troca = vet[num];
					vet[num] = vet[num+1];
					vet[num+1] = troca;
					rep++;
				}
			
			}	
		}
		if (rep==0)
			break;
	}while (1);
}

int main(){
	srand (time(NULL));
	Pessoa pessoa[MAX];
	int contador = 0;
	
	do {
		system ("clear");
		printf ("[1] Cadastrar pessoa\n");
		printf ("[2] Listrar pessoas \n");
		int resp;
		scanf (" %d", &resp);
		
		switch (resp) {
		
			case 1 : 
				cadastroPessoa((pessoa+contador));
				contador++;
				ordenar (pessoa, contador);
				break;
			case 2 :
				listaPessoas(pessoa, contador);
				setbuf(stdin,NULL);
				getchar();
				break;
			default :
				printf ("Opção inválida!\n");
				setbuf(stdin,NULL);
				getchar();
				break;
		}

	} while(contador<MAX); 
	
	return 0;
	
}

