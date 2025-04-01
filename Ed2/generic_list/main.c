/* IMPLEMENTAR!!!

-> MÉTODO DE EXCLUSÃO DE ITEM DE UMA LISTA
	int  l->search(funcao especifica de busca)
	void l->delete(int index)
	
-> NOVA ENTIDADE
	PROFESSOR.
	
-> TODAS AS ENTIDADES DEVEM IMPLEMENTAR...
	-> INSERIR
	-> LISTAR
	-> BUSCAR
	-> EXCLUIR
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "disciplina.h"
#include "aluno.h"
#include "professor.h"

enum ENTIDADES {DISCIPLINA = 1,ALUNO,PROFESSOR};



int interface(){
	system("clear");
	printf("1 - Módulo Disciplina\n");
	printf("2 - Módulo Aluno\n");
	printf("3 - Módulo Professor\n");	
	int opt;
	scanf(" %d",&opt);
	return opt;
}

int main(){
	Lista* academico = lista_create();
	do{
		switch(interface()){
			case DISCIPLINA: interfaceDisciplina(academico, DISCIPLINA);
							break;
			case ALUNO: interfaceAluno(academico, ALUNO);
							break;
			case PROFESSOR: interfaceProfessor(academico, PROFESSOR);
							break;
			case 0: return 0;
			case 4: printf("\nImpressão da lista\n\n");
					academico->show(academico, 0);
					tecleEnter();
					break;
		}
	}while(1);
}
