#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <gconio.h>

#define MIN_X 1
#define MAX_X 80
#define MIN_Y 3
#define MAX_Y 24

typedef struct{
	int x, y;
}Cordenada;

typedef struct Ponto{
	char tipo_corpo;
	struct Ponto *proximo;
	struct Ponto *anterior;
	Cordenada posicao;
}Ponto;

typedef struct Cobra{
	Ponto *cabeca;
	int tamanho_cobra;
	Cordenada alvo;
}Cobra;

void criaPosicaoAlvo(Cobra *cobra){
	srand(time(NULL));
	cobra->alvo.x = MIN_X + rand()%(MAX_X-MIN_X+1);
	cobra->alvo.y = MIN_Y + rand()%(MAX_Y-MIN_Y+1);
	gotoxy(cobra->alvo.x, cobra->alvo.y);
	textcolor(4);
	printf("$");
}

void printPontos(Cobra *cobra){
	gotoxy(9,1);
	textcolor(7);
	printf("%d", cobra->tamanho_cobra-1);
}

Ponto *criaPonto(Cobra *cobra){
	Ponto *novoPonto = malloc(sizeof(Ponto));
	if(!cobra->cabeca){
		novoPonto->tipo_corpo = '*';
		novoPonto->anterior = novoPonto;
		novoPonto->proximo = novoPonto;
		novoPonto->posicao.x = MIN_X;
		novoPonto->posicao.y = MIN_Y;
		return novoPonto;
	}
	Ponto *cabecaCobra = cobra->cabeca;
	Ponto *ultimoPonto = cobra->cabeca->anterior;
	ultimoPonto->proximo = novoPonto;
	novoPonto->anterior = ultimoPonto;
	novoPonto->proximo = cabecaCobra;
	cabecaCobra->anterior = novoPonto;
	novoPonto->tipo_corpo = '*';
	cobra->tamanho_cobra++;
	return novoPonto;
}

Cobra *criaCobra(){
	Cobra *novaCobra = malloc(sizeof(Cobra));
	novaCobra->cabeca = NULL;
	Ponto *novoPonto = criaPonto(novaCobra);
	novaCobra->cabeca = novoPonto;
	novaCobra->tamanho_cobra = 1;
	criaPosicaoAlvo(novaCobra);
	
	return novaCobra;
}

void printCobra(Cobra *cobra){
	Ponto *p = cobra->cabeca;
	do{
		textcolor(7);
		gotoxy(p->posicao.x, p->posicao.y);
		printf("%c", p->tipo_corpo);
		p = p->proximo;
	}while(p != cobra->cabeca);
}

void movimentaCobra(Cobra *cobra, char tecla){
	Ponto *ultimoPonto = cobra->cabeca->anterior;
	Cordenada proxCordenada = cobra->cabeca->posicao;
	switch(tecla){
		case 'a':
				proxCordenada.x--;
				if (proxCordenada.x < MIN_X)
					proxCordenada.x = MAX_X;
				break;
		case 'd':
				proxCordenada.x++;
				if (proxCordenada.x > MAX_X)
					proxCordenada.x = MIN_X;
				break;
		case 'w':
				proxCordenada.y--;
				if (proxCordenada.y < MIN_Y)
					proxCordenada.y = MAX_Y;
				break;
		case 's':
				proxCordenada.y++;
				if(proxCordenada.y > MAX_Y)
					proxCordenada.y = MIN_Y;
				break;
	}
	if((cobra->alvo.x == proxCordenada.x) && (cobra->alvo.y == proxCordenada.y)){
		cobra->cabeca = criaPonto(cobra);
		criaPosicaoAlvo(cobra);
		printPontos(cobra);
	}
	else{
		gotoxy(ultimoPonto->posicao.x, ultimoPonto->posicao.y);
		printf(" ");
		cobra->cabeca = ultimoPonto;
	}
	cobra->cabeca->posicao = proxCordenada;
	printCobra(cobra);
}

int main(){
	textbackground(0);
	int maxPontos;
	printf("Quantos alvos desejas???\n");
	scanf(" %d", &maxPontos);
	system("clear");
	printf("Alvos = 0/%d", maxPontos);
	gotoxy(1,2);
	for(int x = 0; x < MAX_X; x++){
		printf("_");
	};
	cursor(0);
	Cobra *cobra = criaCobra();
	printPontos(cobra);
	gotoxy(cobra->cabeca->posicao.x, cobra->cabeca->posicao.y);
	printf("%c", cobra->cabeca->tipo_corpo);
	while(maxPontos>=cobra->tamanho_cobra){
		char tecla = getch();
		movimentaCobra(cobra, tecla);
	}
	gotoxy(1,4);
	printf("PARABÉNS!!!!!!!");
	return 0;
}
