#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl.h"

typedef struct{
	int cod, ano;
	char nome[100], autor[100];
}Livro;

//PROTÓTIPOS
void print_livros(Livro* l);
No* new_livro(Avl* a, Livro* l);
int menu();
void cadastro_livro(Avl* arvore_livros);
No* new_livro(Avl* a, Livro* l);
void print_livros(Livro* l);
void tecleEnter();
void print_Nome(Livro* l);

//FUNÇÕES

int menu(){
	int opc;
	printf("0 - Sair\n");
	printf("1 - Inserir livro\n");
	printf("2 - Imprimir livros\n");
	printf("3 - Remover livro\n");
	printf("4 - Buscar livro\n");
	printf("5 - Imprimir em formato de árvore\n");
	scanf(" %d", &opc);
	system("clear");
	return opc;
}

void cadastro_livro(Avl* arvore_livros){
	Livro* novoLivro = malloc(sizeof(Livro));
	printf("informe o nome: ");
	scanf(" %[^\n]s", novoLivro->nome);
	printf("Informe o autor: ");
	scanf(" %[^\n]s", novoLivro->autor);
	printf("Informe o ano de lançamento: ");
	scanf(" %d", &novoLivro->ano);
	printf("Informe o código do livro: ");
	scanf(" %d", &novoLivro->cod);
	No* novoNo = new_livro(arvore_livros, novoLivro);
	arvore_livros->raiz = arvore_livros->insert(arvore_livros->raiz, novoNo);
}

No* new_livro(Avl* a, Livro* l){
	No* novoNo = no_create();
	novoNo->item = l;
	novoNo->print = print_livros;
	a->cont_nos++;
	novoNo->chave = l->cod;
	return novoNo;
}

void print_livros(Livro* l){
	printf("Código %d\n", l->cod);
	printf("Título: %s\tAutor: %s\tAno: %d\n\n", l->nome, l->autor, l->ano);
}

void tecleEnter(){
	printf("\nClique enter para voltar ao menu...");
	setbuf(stdin, NULL);
	getchar();
	system("clear");
}

void print_Nome(Livro* l){
	printf("\"%s\"", l->nome);
}

int main(){
	Avl* arvore_livros = avl_create();
	int codigo;
	do{
		switch(menu()){
			case 1 : cadastro_livro(arvore_livros);
					 tecleEnter("clear");
					 break;
			case 2 : arvore_livros->show(arvore_livros->raiz);
					 tecleEnter();
					 break;
			case 3 : printf("Informe o código do livro: ");
					 scanf(" %d", &codigo);
					 arvore_livros->raiz = arvore_livros->delet(arvore_livros->raiz, codigo);
					 tecleEnter();
					 break;
			case 4 : printf("Informe o código: ");
					 scanf(" %d", &codigo);
					 arvore_livros->search(arvore_livros, codigo);
					 tecleEnter();
					 break;
			case 5 : imprimir(arvore_livros->raiz, 1 , print_Nome);
					 tecleEnter();
					 break;
			case 0: return 0;
		}
		
	}while(1);
}

