#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PRATELEIRA 3
#define MAX_TIPO 100
#define MAX_STRING 100

typedef struct{
	char titulo[MAX_STRING], autor[MAX_STRING];
	int ano;
}Livro;

typedef struct{
	char nome_Area[MAX_STRING];
	Livro livro[50]; 
	int numLivros;
}Area_Conhecimento;

void getTipos(Area_Conhecimento vet[], int contador){
	printf ("Nome:");
	scanf (" %[^\n]s", vet[contador].nome_Area);
}

void getLivro(Area_Conhecimento vet[], int contador){
	if (contador==0)
		printf ("Cadastre uma area de conhecimento!\n");
	else{ 
		printf("Escolha um área de conhecimento abaixo\n");
		for (int x=0; x<contador; x++)
			printf ("[%d].%s\n", x+1, vet[x].nome_Area);
		int resp;
		do{
			scanf(" %d", &resp);
			if (resp>0 && resp<contador+1)
				break;
			else 
				printf ("Informe uma opção entre 1 e %d\n", contador);
		}while(1);	
		printf ("\t%s\n", vet[resp-1].nome_Area);
		printf ("Título do livro:");
		scanf (" %[^\n]s", vet[resp-1].livro[vet[resp-1].numLivros].titulo);
		printf ("Autor:");
		scanf (" %[^\n]s", vet[resp-1].livro[vet[resp-1].numLivros].autor);
		printf ("Ano:");
		scanf (" %d", &vet[resp-1].livro[vet[resp-1].numLivros].ano);
		vet[resp-1].numLivros++;
	}
}

void setMostrar(Area_Conhecimento vet[], int contador){
	int localizacao = 1, contLocalizacao = 0;
	for (int x=0; x<contador; x++){
		printf ("\nÁrea de conhecimento: %s\n",vet[x].nome_Area);
		printf ("TÍTULO\t\tAUTOR\t\tANO\t\tLOCALIZAÇÃO\n");
		for (int y=0; y<vet[x].numLivros; y++){
			printf ("%s\t\t%s\t\t%d\t\t%d\n", vet[x].livro[y].titulo,
					vet[x].livro[y].autor, vet[x].livro[y].ano, localizacao);
			contLocalizacao++;
			if (contLocalizacao%MAX_PRATELEIRA==0)
				localizacao++;
		}
		localizacao++;
	}
}

void setBubleSort (Area_Conhecimento vet[], int contador){
	for (int x=contador; x>=0; x--){
		if ( strcmp(vet[x].nome_Area, vet[x-1].nome_Area) < 0 ){
			Area_Conhecimento auxi = vet[x-1];
			vet[x-1] = vet[x];
			vet[x] = auxi;
		} 
	}
}

void setOrdenarLivro(Area_Conhecimento vet[], int contador){
	for (int tipo=0; tipo<contador; tipo++){
		if (vet[tipo].numLivros>1){
			for (int contLivro=vet[tipo].numLivros-1; contLivro>=1; contLivro--){
				if (strcmp(vet[tipo].livro[contLivro].titulo,
					vet[tipo].livro[contLivro-1].titulo) < 0 ){
						Area_Conhecimento auxi = vet[tipo];
						vet[tipo].livro[contLivro-1] = vet[tipo].livro[contLivro];
						vet[tipo].livro[contLivro] = auxi.livro[contLivro-1];
					
				}
			}
		}
	}
	
}

int main(){
	int contTipo = 0;
	do{
		Area_Conhecimento biblioteca[MAX_TIPO];
		int opcao;
		system("clear");
		printf ("[1]. Cadastrar área de conhecimento\n");
		printf ("[2]. Cadastrar livro\n");
		printf ("[3]. Mostrar os livros\n");
		printf ("[4]. Encerrar\n");
		scanf (" %d", &opcao);
		
		switch (opcao){
			
			case 1 :
				getTipos(biblioteca, contTipo);
				setBubleSort(biblioteca, contTipo);
				contTipo++;
				break;
			case 2 :
				getLivro(biblioteca, contTipo);
				setOrdenarLivro(biblioteca, contTipo);
				break;
			case 3 :
				setMostrar(biblioteca, contTipo);
				printf ("Press enter\n");
				setbuf(stdin,NULL);
				getchar();
				break;
			case 4 :
				return 0;
			default : 
				break;
		}
	}while (1);
}

