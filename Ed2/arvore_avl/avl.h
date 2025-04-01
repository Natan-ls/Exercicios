typedef struct No{
    int chave;
    void* item;
    struct No *esquerdo, *direito;
    int altura;
	void(*print)();
}No;

typedef struct Avl{
	No *raiz;
	No*(*insert)();
	void(*show)();
	No*(*delet)();
	void(*search)();
	int cont_nos;
}Avl;

//PROTÓTIPOS
Avl* avl_create();
No* no_create();
No* remover(No* raiz, int chave);
void imprimir (No* raiz, int nivel, void(*exec)());
void avl_binary_search(Avl* arvore, int chave);
No* inserir(No* raiz, No* novoNo);
void inorder(No* no);
int maior(int a, int b);
int alturaDoNo (No* no);
short fatorDeBalanceamento (No* no);
No* rotacaoEsquerda (No *r);
No* rotacaoDireita (No *r);
No* rotacaoDireitaEsquerda (No *r);
No* rotacaoEsquerdaDireita (No *r);
No* balancear(No* raiz);

//FUNCÇÕES

Avl* avl_create(){
	Avl* arvore = malloc(sizeof(Avl));
	arvore->raiz = NULL;
	arvore->insert = inserir;
	arvore->show = inorder;
	arvore->delet = remover;
	arvore->search = avl_binary_search;
	arvore->cont_nos = 0;
	return arvore;
}

No* no_create() {
    No* novo = malloc(sizeof(No));
    if(novo){
        novo->esquerdo = NULL;
        novo->direito = NULL;
        novo->altura = 0;
    }
    else
        printf("\nERRO ao alocar nó!\n");
    return novo;
}

int maior(int a, int b){ 
    return (a > b)? a: b;
}

int alturaDoNo (No* no) {
    if(no == NULL)
        return -1;
    else
        return no->altura;
}

short fatorDeBalanceamento (No* no) {
    if (no)
        return(alturaDoNo (no->esquerdo) - alturaDoNo (no->direito));
    else
        return 0;
}

No* rotacaoEsquerda (No *r) {
    No* y; 
    No* f;
    y = r->direito;
    f = y->esquerdo;
    y->esquerdo = r;
    r->direito = f;
    r->altura = maior (alturaDoNo (r->esquerdo), alturaDoNo (r->direito)) + 1;
    y->altura = maior (alturaDoNo (y->esquerdo), alturaDoNo(y->direito)) + 1;
    return y;
}

No* rotacaoDireita (No *r) {
    No* y; 
    No* f;
    y = r->esquerdo;
    f = y->direito;
    y->direito = r;
    r->esquerdo = f;
    r->altura = maior(alturaDoNo (r->esquerdo), alturaDoNo (r->direito)) + 1; 
    y->altura = maior (alturaDoNo (y->esquerdo), alturaDoNo(y->direito)) + 1;
    return y;
}

No* rotacaoDireitaEsquerda (No *r) {
    r->direito = rotacaoDireita (r->direito);
    return rotacaoEsquerda (r);
}

No* rotacaoEsquerdaDireita (No *r) {
    r->esquerdo = rotacaoEsquerda (r->esquerdo);
    return rotacaoDireita(r);
}

No* balancear(No* raiz){
    int fb = fatorDeBalanceamento(raiz);
    
    // Rotação à esquerda
    if(fb < -1 && fatorDeBalanceamento(raiz->direito) <= 0)
         raiz = rotacaoEsquerda(raiz);

    // Rotação à direita
    else if(fb > 1 && fatorDeBalanceamento(raiz->esquerdo) >= 0)
        raiz = rotacaoDireita(raiz);

    // Rotação dupla à esquerda
    else if(fb > 1 && fatorDeBalanceamento(raiz->esquerdo) < 0)
        raiz = rotacaoEsquerdaDireita(raiz);

    // Rotação dupla à direita
    else if(fb < -1 && fatorDeBalanceamento(raiz->direito) > 0)
        raiz = rotacaoDireitaEsquerda(raiz);
    
    return raiz;
}

No* inserir(No* raiz, No* novoNo) {
    if(raiz == NULL) // árvore vazia
        return novoNo;
    else{ // inserção será à esquerda ou à direita
        if(novoNo->chave < raiz->chave)
            raiz->esquerdo = inserir(raiz->esquerdo, novoNo);
        else if (novoNo->chave > raiz->chave)
            raiz->direito = inserir(raiz->direito, novoNo);
        else 
            printf("\nInsercao nao realizada!\n");
    }

    // Recalcula a altura de todos os nós entre a raiz e o novo no inserido
    raiz->altura = maior(alturaDoNo(raiz->esquerdo), alturaDoNo(raiz->direito))+1;

    // verifica a necessidade de rebalancear a árvore raiz balancear(raiz);
    raiz = balancear(raiz);

    return raiz;
}

No* remover(No* raiz, int chave) {
    if(raiz == NULL) {
        printf("Valor nao encontrado!\n");
        return NULL;
    }else{ // procura o nó a remover
        if(raiz->chave == chave){
            // remove nós folhas (nós sem filhos)
            if(raiz->esquerdo == NULL && raiz->direito == NULL) {
                free(raiz);
                return NULL;
            }
            else{
                // remover nós que possuem 2 filhos
                if(raiz->esquerdo != NULL && raiz->direito != NULL) {
                No* aux = raiz->esquerdo;
                while(aux->direito != NULL)
                    aux = aux->direito;
                raiz->chave = aux->chave;
                aux->chave = chave;
                raiz->esquerdo = remover(raiz->esquerdo, chave);
                return raiz;
            }
            else{
                // remover nós que possuem apenas 1 filho
                No* aux;
                if(raiz->esquerdo != NULL)
                    aux = raiz->esquerdo;
                else
                    aux = raiz->direito;
                free(raiz);
                return aux;
            }
        }
        }else{
            if (chave < raiz->chave)
                raiz->esquerdo = remover(raiz->esquerdo, chave);
            else
                raiz->direito = remover(raiz->direito, chave);
        }
        // Recalcula a altura de todos os nós entre a raiz e o novo nó inserido
        raiz->altura = maior(alturaDoNo(raiz->esquerdo), alturaDoNo(raiz->direito)) + 1;
        // verifica a necessidade de rebalancear a árvore raiz balancear(raiz);
        raiz = balancear(raiz);
        return raiz;
    }
}

void inorder(No* no){
	if(!no)
		return;
	inorder(no->esquerdo);
	no->print(no->item);
	inorder(no->direito);
}

void imprimir (No* raiz, int nivel, void(*exec)()) {
    if(raiz){
        imprimir(raiz->direito, nivel + 1, exec); 
        printf("\n\n");

        for(int i = 0; i < nivel; i++)
            printf("\t");

        printf("%d: ", raiz->chave);
        exec(raiz->item);
        imprimir(raiz->esquerdo, nivel + 1, exec);
    }
}

void avl_binary_search(Avl* arvore, int chave){
	if(!arvore->raiz){
		return;
	}
	No* no = arvore->raiz;
	while(no){
		if(no->chave == chave){
			no->print(no->item);
			return;
		}	
		else if(no->chave > chave)
			no = no->esquerdo;
		else 
			no = no->direito;
	}
	printf("Item não está na lista!\n");
}
