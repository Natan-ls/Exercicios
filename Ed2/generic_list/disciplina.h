typedef struct Disciplina{
	char nome[100];
	int ch;
	int codigo;
	char professor[100];
}Disciplina;

//PROTOTIPOS

void interfaceDisciplina(Lista* l, int tipo);
void interfaceBuscaDisciplina();
void printDisciplina(Disciplina* d);
Disciplina* __new_Disciplina(char* nome, int ch, char* prof, int cod);
void cadastrarDisciplina(Lista* l, int tipo);
void buscaDisciplina(Lista* l);
Disciplina* __cmpNomeDisciplina(Disciplina* disc, char* nome);
Disciplina* __cmpCodigoDisciplina(Disciplina* disc, int cod);
void deletarDisciplina(Lista* l);

//FUNÇÕES...

void interfaceDisciplina(Lista* l, int tipo){
	system("clear");
	do{
		int total_disciplinas = lista_cont_type(l, tipo);
		printf("\t%d Disciplinas cadastradas!\n", total_disciplinas);
		printf("1 - Cadastrar Disciplina\n");
		printf("2 - Listar Disciplinas\n");
		printf("3 - Buscar Disciplinas\n");
		printf("4 - Remover Disciplinas\n");
		printf("0 - VOLTAR AO MENU PRINCIPAL\n");
		int opt;
		scanf(" %d",&opt);
		switch(opt){
			case 0: return;
			case 1: cadastrarDisciplina(l, tipo);
					 break;
			case 2: if(total_disciplinas){
						printf("\nDISCIPLINAS\n");
						l->show(l, tipo);
					} else printf("Nenhuma disciplina cadastrada!\n");
					break;
			case 3: interfaceBuscaDisciplina(l, tipo, printDisciplina);
					break;
			case 4: interfaceBuscaDisciplina(l, tipo, l->delet);
					break;
		}
		tecleEnter();
	}while(1);
}

void interfaceBuscaDisciplina(Lista* l, int tipo, void(*function)()){
	if(!lista_cont_type(l, tipo)){
		printf("Nenhuma disciplina cadastrada\n");
		return;
	}
	printf("Escolha a opção para fazer a busca.\n");
	printf("1 - Por Nome\n");
	printf("2 - Por Código\n");
	int opt;
	scanf(" %d", &opt);
	int encontrou = 0;
	switch(opt){
		case 1: printf("Informe o nome da disciplina:\n");
				char nome[100];
				scanf(" %[^\n]s", nome);
				encontrou = l->exec(l, tipo, __cmpNomeDisciplina, function, nome);
				break;
		case 2: printf("Informe o código da disciplina:\n");
				int cod;
				scanf(" %d", &cod);
				encontrou = l->exec(l, tipo, __cmpCodigoDisciplina, function, cod);
				break;
	}
	if(!encontrou)
		printf("Disciplina não encontrada!\n");
	else if (function == l->delet)	
		printf("Disciplina removida....!\n");
}

//métodos privados
Disciplina* __new_Disciplina(char* nome, int ch, char* prof, int cod){
	Disciplina* d = malloc(sizeof(Disciplina));
	strcpy(d->nome,nome);
	d->ch = ch;
	strcpy(d->professor,prof);
	d->codigo = cod;
	return d;
}

Disciplina* __cmpNomeDisciplina(Disciplina* disc, char* nome){
	if(!strcmp(disc->nome, nome))
		return disc;
	return NULL;
}

Disciplina* __cmpCodigoDisciplina(Disciplina* disc, int cod){
	if(disc->codigo == cod)
		return disc;
	return NULL;
}

//métodos públicos
void cadastrarDisciplina(Lista* l, int tipo){
	printf("Qual nome da Disciplina: ");
	char disc[100];
	scanf(" %[^\n]s",disc);
	printf("Qual a CH da Disciplina: ");
	int ch;
	scanf(" %d",&ch);
	printf("Qual o nome do Professor: ");
	char prof[100];
	scanf(" %[^\n]s",prof);
	int codigo = lista_cont_type(l, tipo) + 1;
	//tudo acima tem q garantir que os dados são validos.
	Disciplina* nova = __new_Disciplina(disc,ch,prof,codigo);
	Object* objDisc = object_create(nova);
	objDisc->print = printDisciplina;	
	objDisc->type = tipo;
	l->insert(l,objDisc);
}

void printDisciplina(Disciplina* d){
	printf("Código da Disciplina: %d\n", d->codigo);
	printf("Nome da Disciplina: %s\n",d->nome);
	printf("CH da Disciplina: %d\n",d->ch);
	printf("Professor da Disciplina: %s\n\n",d->professor);
}
