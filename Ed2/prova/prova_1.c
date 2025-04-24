#include <stdio.h>
#include <stdlib.h>

typedef struct Processo{
	int num;
	struct Processo *proximo;
	struct Processo *anterior;
}Processo;

typedef struct Fila{
	Processo *inicioFila;
	Processo *fimFila;
	int capacidade;
	int contProcesso;
}Fila;

Fila *criaFila(){
	Fila *novaFila = malloc(sizeof(Fila));
	novaFila->inicioFila = NULL;
	novaFila->fimFila = NULL;
	novaFila->contProcesso = 0;
	return novaFila;
}

void adicionaProcesso(Fila *filaCache, int num){
	Processo *novo = malloc(sizeof(Processo));
	novo->num = num;
	novo->proximo = NULL;
	novo->anterior = filaCache->fimFila;
	if(filaCache->fimFila)
		filaCache->fimFila->proximo = novo;
	if(!filaCache->inicioFila)
		filaCache->inicioFila = novo;
	filaCache->fimFila = novo;
	filaCache->contProcesso++;
}

void mostra(Fila *filaCache){
	Processo *ptrCache = filaCache->fimFila;
	while(ptrCache){
		printf("%d ", ptrCache->num);
		ptrCache = ptrCache->anterior;
	}
}

Processo *busca(Fila *filaCache, int numP){
	Processo *ptrCache = filaCache->inicioFila;
	while(ptrCache){
		if(ptrCache->num == numP){
			return ptrCache;
		}
		ptrCache = ptrCache->proximo;
	}
	return NULL;
}

void troca(Fila *filaCache, Processo *alvo){
	if(alvo == filaCache->fimFila)
		return;
	Processo *anter = alvo->anterior;
	if(alvo == filaCache->inicioFila){
		filaCache->inicioFila->anterior = filaCache->fimFila;
		filaCache->fimFila->proximo = filaCache->inicioFila;
		filaCache->fimFila = alvo;
		filaCache->inicioFila = filaCache->inicioFila->proximo;
        filaCache->inicioFila->anterior = NULL;
		filaCache->fimFila->proximo = NULL;
		return;
	}
	anter->proximo = alvo->proximo;
    alvo->proximo->anterior = anter;
    alvo->anterior = filaCache->fimFila;
    filaCache->fimFila->proximo = alvo;
    alvo->proximo = NULL;
    filaCache->fimFila = alvo;
}

void removeF(Fila *filaCache){
    Processo *alvo = filaCache->inicioFila;
    filaCache->inicioFila = filaCache->inicioFila->proximo;
    if(filaCache->inicioFila)
        filaCache->inicioFila->anterior = NULL;
    else
         filaCache->fimFila = NULL;
    filaCache->contProcesso--;
    free(alvo);
}

int main(){
	Fila *cache = criaFila();
	int num;
	do{
		printf("Informe a capacidade da cache: ");
		scanf(" %d", &cache->capacidade);
	} while(cache->capacidade <= 0);
	
	while(1){
		scanf(" %d", &num);
		if(num <= 0){
			mostra(cache);
			return 0;
		}
		Processo *alvo = busca(cache, num);
		if(!alvo)
			if(cache->contProcesso == cache->capacidade){
				removeF(cache);
                adicionaProcesso(cache, num);
			}
			else
				adicionaProcesso(cache, num);
		else{
			troca(cache, alvo);
		}
	
	}
}

