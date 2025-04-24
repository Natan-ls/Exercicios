#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Doc{
	char nome[10];
	int tamanho;
	struct Doc* proximo;
	struct Doc* anterior;
}Doc;

typedef struct Fila{
	Doc *inicio_fila;
	Doc *fim_fila;
}Fila;

Fila *criaFila(){
	Fila *nova_fila = malloc(sizeof(Fila));
	nova_fila->inicio_fila = NULL;
	nova_fila->fim_fila = NULL;
	return nova_fila;
}

void mensagemNenhumDocumento(){
	printf("Nenhum documento na fila de impressão!\n");
	return;
}

int interface(){
	int opt;
	printf("1: Enviar doc p/ impressão\n");
	printf("2: Imprimir doc da fila\n");
	printf("3: Imprimir fila de impressão\n");
	printf("4: Excluir doc da fila\n");
	printf("5: Dar prioridade em doc da fila\n");
	scanf(" %d", &opt);
	return opt;
}

Fila* cadastrar(Fila* fila_doc){
	Doc* novo_doc = (Doc*) malloc(sizeof(Doc));
	printf("Informe o nome: ");
	scanf(" %[^\n]s", novo_doc->nome);
	/*printf("Informe o numero de paginas: ");
	scanf(" %d", &novo_doc->tamanho);*/
	novo_doc->tamanho = rand()% 10;
	novo_doc->proximo = NULL;
	novo_doc->anterior = fila_doc->fim_fila;
	
	//Se for o primeiro cadastro
	if(!fila_doc->inicio_fila){
		fila_doc->inicio_fila = novo_doc;
		fila_doc->fim_fila = novo_doc;
		return fila_doc;
	}
	fila_doc->fim_fila->proximo = novo_doc;
	fila_doc->fim_fila = novo_doc;
	
	return fila_doc;
}

void mostrar(Fila* fila_doc){
	if(!fila_doc->inicio_fila){
		mensagemNenhumDocumento();
		return;
	}
	printf("\nDOCUMENTOS NA FILA DE IMPRESSÃO\n");
	Doc *p_Doc = fila_doc->inicio_fila;
	while(p_Doc){
		printf("\nNome do documento:%s\nNumero de paginas: %d\n", p_Doc->nome, p_Doc->tamanho);
		p_Doc = p_Doc->proximo;
	}
}

Doc* buscar(Doc *p_doc, char pesq[]){
	while(p_doc){
		if(!strcmp(pesq, p_doc->nome)){
			return p_doc;
		}
		p_doc = p_doc->proximo;
	}
	return NULL;
}

Fila *excluir(Fila *fila_doc){
	if(!fila_doc->inicio_fila){
		mensagemNenhumDocumento();
		return fila_doc;
	}
	char pesq[10];
	mostrar(fila_doc);
	printf("Qual deseja excluir:\n");
	scanf(" %[^\n]s", pesq);
	Doc *alvo = buscar(fila_doc->inicio_fila, pesq);
	if(!alvo)
		printf("Não existe\n");
	else{
		// Primeiro da fila a ser excluído
		if(alvo == fila_doc->inicio_fila){
			fila_doc->inicio_fila = fila_doc->inicio_fila->proximo;
			if(fila_doc->inicio_fila)
				fila_doc->inicio_fila->anterior = NULL;
			else
				fila_doc->fim_fila = NULL;
		}
		else{
			Doc *doc_anterior = alvo->anterior;
			doc_anterior->proximo = alvo->proximo;
			// Último da fila a ser excluído
			if(fila_doc->fim_fila == alvo)
				fila_doc->fim_fila = doc_anterior;
			else
				alvo->proximo->anterior = doc_anterior;
		}
		free(alvo);
	}
	return fila_doc;
}

Fila *imprimirDoc(Fila *fila_doc){
	if(!fila_doc->inicio_fila){
		mensagemNenhumDocumento();
		return fila_doc;
	}
	printf("\nDocumento: %s\t%d Páginas\nImprimindo.....\n\n", fila_doc->inicio_fila->nome, fila_doc->inicio_fila->tamanho);
	Doc *remove = fila_doc->inicio_fila;
	fila_doc->inicio_fila = fila_doc->inicio_fila->proximo;
	if(!fila_doc->inicio_fila)
		fila_doc->fim_fila = NULL;
	else 
		fila_doc->inicio_fila->anterior = NULL;
	free(remove);
	
	return fila_doc;
}

Fila *priorizarDocumento(Fila *fila_doc){
	if(!fila_doc->inicio_fila){
		mensagemNenhumDocumento();
		return fila_doc;
	}
	char pesq[10];
	if(fila_doc->inicio_fila == fila_doc->fim_fila){
		printf("Esse documento já está na prioridade!\n\n");
		return fila_doc;
	}
	mostrar(fila_doc);
	printf("\nQual documento deseja priorizar?\n");
	scanf(" %[^\n]s", pesq);
	Doc *alvo = buscar(fila_doc->inicio_fila, pesq);
	if(!alvo){
		printf("Documento não encontrado!\n\n");
		return fila_doc;
	}
	// Se o documento escolhido for o primeiro da fila 
	if(alvo == fila_doc->inicio_fila){
		printf("\nEsse documento já está na prioridade!\n\n");
		return fila_doc;
	}
	Doc *pAnterior = alvo->anterior;
	// Se o documento for o último da fila
	if(alvo == fila_doc->fim_fila){
		fila_doc->fim_fila->proximo = fila_doc->inicio_fila;
		fila_doc->inicio_fila->anterior = fila_doc->fim_fila;
		fila_doc->fim_fila->anterior = NULL;
		pAnterior->proximo = NULL;
		fila_doc->inicio_fila = fila_doc->fim_fila;
		fila_doc->fim_fila = pAnterior;
		return fila_doc;
	}
	// Se o documento estiver entre o inicio e fim
	pAnterior->proximo = alvo->proximo;
	alvo->proximo->anterior = pAnterior;
	alvo->anterior = NULL;
	alvo->proximo = fila_doc->inicio_fila;
	fila_doc->inicio_fila->anterior = alvo;
	fila_doc->inicio_fila = alvo;
	return fila_doc;
}

void aguardarEnter(){
	printf("\nPressione ENTER....\n");
	setbuf(stdin,NULL);
	getchar();
}

int main(){
	Fila *fila_documentos = NULL;
	fila_documentos = criaFila();
	
	while(1){
		switch(interface()){
			case 1: 
				fila_documentos = cadastrar(fila_documentos);
				break;
			case 2: 
				fila_documentos = imprimirDoc(fila_documentos);
				break;
			case 3: 
				mostrar(fila_documentos);
				break;
			case 4: 
				fila_documentos = excluir(fila_documentos);
				break;
			case 5:
				fila_documentos = priorizarDocumento(fila_documentos);
				break;
			case 0:	return 0;
		}
		aguardarEnter();
		system("clear");
	}
}
