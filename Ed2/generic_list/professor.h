typedef struct{
	char nome[100];
	char email[100];
}Professor;

//PROTOTIPOS

void interfaceProfessor(Lista* l, int tipo);
void interfaceBuscaProfessor(Lista* l, int tipo, void(*funcao_exec)());
Professor* __new_Professor(char* nome, char* email);
Professor* __cmpNomeProfessor(Professor* prof, char* nome);
Professor* __cmpEmailProfessor(Professor* prof, char* email);
void cadastrarProfessor(Lista* l, int tipo);
void printProfessor(Professor* prof);

//FUNÇÕES

void interfaceProfessor(Lista* l, int tipo){
	system("clear");
	do{
		int total_prof = lista_cont_type(l, tipo);
		printf("\t%d Professores cadastrados!\n", total_prof);
		printf("1 - Cadastrar Professor\n");
		printf("2 - Listar Professor\n");
		printf("3 - Buscar Professor\n");
		printf("4 - Remover Professor\n");
		printf("0 - VOLTAR AO MENU PRINCIPAL\n");
		int opt;
		scanf(" %d", &opt);
		switch (opt){
			case 0 : return;
			case 1 : cadastrarProfessor(l, tipo);
					 break;
			case 2 : if(total_prof){
					 	printf("\nPROFESSORES\n");
					 	l->show(l, tipo);
					 } else printf("Nenhum professor cadastrado!\n");
					 break;
			case 3 : interfaceBuscaProfessor(l, tipo, printProfessor);
					 break;
			case 4 : interfaceBuscaProfessor(l, tipo, l->delet);
					 break;
		}
		tecleEnter();
	}while(1);
}

void interfaceBuscaProfessor(Lista* l, int tipo, void(*funcao_exec)()){
	if(!lista_cont_type(l, tipo)){
		printf("Nenhum aluno cadastrado!\n");
		return;
	}
	printf("Escolha a opção para fazer a busca.\n");
	printf("1 - Por nome\n");
	printf("2 - Por email\n");
	int opt;
	scanf(" %d", &opt);
	int encontrou = 0;
	switch (opt){
		case 1: printf("Informe o nome da professor: ");
				char nome[100];
				scanf(" %[^\n]s", nome);
				encontrou = l->exec(l, tipo, __cmpNomeDisciplina, funcao_exec, nome);
				break;
		case 2: printf("Informe o email do Professor: ");
				char email[100];
				scanf(" %[^\n]s", email);
				encontrou = l->exec(l, tipo, __cmpNomeDisciplina, funcao_exec, email);
				break;	
	}
	if(!encontrou)
		printf("Professor não encontrado\n");
	else if (funcao_exec == l->delet)
		printf("Professor removido...\n");

}

//Métodos privados
Professor* __new_Professor(char* nome, char* email){
	Professor* novo = malloc(sizeof(Professor));
	strcpy(novo->nome, nome);
	strcpy(novo->email, email);
	return novo;
}

Professor* __cmpNomeProfessor(Professor* prof, char* nome){
	if(!(strcmp(prof->nome, nome)))
		return prof;
	return NULL;
}

Professor* __cmpEmailProfessor(Professor* prof, char* email){
	if(!(strcmp(prof->email, email)))
		return prof;
	return NULL;
}

//Métodos públicos
void cadastrarProfessor(Lista* l, int tipo){
	printf("Qual o nome do professor: ");
	char nome[100];
	scanf(" %[^\n]s", nome);
	printf("Qual o email do professor: ");
	char email[100];
	scanf(" %[^\n]s", email);
	Professor* novo = __new_Professor(nome, email);
	Object* objProf = object_create(novo);
	objProf->print = printProfessor;
	objProf->type = tipo;
	lista_insert(l, objProf);
}

void printProfessor(Professor* prof){
	printf("Nome do professor: %s\n", prof->nome);
	printf("Email do professor: %s\n\n", prof->email);
}
