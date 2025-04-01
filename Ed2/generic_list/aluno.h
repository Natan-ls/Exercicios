typedef struct Aluno{
	char nome[100];
	char email[100];
	int matricula;
}Aluno;

//PROTOTIPOS

Aluno* __new_Aluno(char* nome, char* email, int mat);
void interfaceAluno(Lista* l, int tipo);
void interfaceBuscaAluno(Lista* l, int tipo, void(*funcao_exec)());
void cadastrarAluno(Lista* l, int tipo);
void printAluno(Aluno* a);
Aluno* __buscaNomeAluno(Aluno* aluno, char* nome);
Aluno* __buscaEmailAluno(Aluno* aluno, char* nome);
Aluno* __buscaMatriculaAluno(Aluno* aluno, int matricula);

//FUNÇÕES...

void interfaceAluno(Lista* l, int tipo){
	system("clear");
	do{
		int total_aluno = lista_cont_type(l, tipo);
		printf("\t%d alunos cadastrados!\n", total_aluno);
		printf("1 - Cadastrar Aluno\n");
		printf("2 - Listar Alunos\n");
		printf("3 - Buscar Aluno\n");
		printf("4 - Remover Aluno\n");
		printf("0 - VOLTAR AO MENU PRINCIPAL\n");
		int opt;
		scanf(" %d",&opt);
		switch(opt){
			case 0: return;
			case 1: cadastrarAluno(l, tipo);
					 break;
			case 2: if(total_aluno){
						printf("\nALUNOS\n");
						l->show(l, tipo);
					}else printf("Nenhum aluno cadastrado!\n");
					break;
			case 3: interfaceBuscaAluno(l, tipo, printAluno);
					break;
			case 4: interfaceBuscaAluno(l, tipo, l->delet);
					break;
		}
		tecleEnter();
	}while(1);
}

void interfaceBuscaAluno(Lista* l, int tipo, void(*funcao_exec)()){
	if(!lista_cont_type(l, tipo)){
		printf("Nenhum aluno cadastrado!\n");
		return;
	}
	printf("Escolha a opção para fazer a busca\n");
	printf("1 - Por nome\n");
	printf("2 - Por email\n");
	printf("3 - Por matricula\n");
	int opt;
	scanf(" %d", &opt);
	int encontrou = 0;
	switch(opt){
		case 1: printf("Digite o nome do aluno: ");
				char nome[100];
				scanf(" %[^\n]s", nome);
				encontrou = l->exec(l, tipo, __buscaNomeAluno, funcao_exec, nome);
				break;
		case 2: printf("Digite o email do aluno: ");
				char email[100];
				scanf(" %[^\n]s", email);
				encontrou = l->exec(l, tipo, __buscaEmailAluno, funcao_exec, email);
				break;
		case 3: printf("Digite a mátricula: ");
				int matricula;
				scanf(" %d", &matricula);
				encontrou = l->exec(l, tipo, __buscaMatriculaAluno, funcao_exec, matricula);
				break;
	}
	if(!encontrou)
		printf("Aluno não encontrado!\n");
	else if(funcao_exec == l->delet)
		printf("Aluno removido....\n");
}

//métodos privados
Aluno* __new_Aluno(char* nome, char* email, int mat){
	Aluno* a = malloc(sizeof(Aluno));
	strcpy(a->nome,nome);
	strcpy(a->email,email);
	a->matricula = mat;
	return a;
}

Aluno* __buscaNomeAluno(Aluno* aluno, char* nome){
	if(!strcmp(aluno->nome, nome))
		return aluno;
	return NULL;
}

Aluno* __buscaEmailAluno(Aluno* aluno, char* nome){
	if(!strcmp(aluno->email, nome))
		return aluno;
	return NULL;
}

Aluno* __buscaMatriculaAluno(Aluno* aluno, int matricula){
	if(aluno->matricula == matricula)
		return aluno;
	return NULL;
}

//métodos públicos
void cadastrarAluno(Lista* l, int tipo){
	printf("Qual nome do Aluno: ");
	char nome[100];
	scanf(" %[^\n]s",nome);
	//do{
	printf("Qual o E-mail do Aluno: ");
	char email[100];
	scanf(" %[^\n]s",email);
	//}while(!validaEmail(email));	
	printf("Qual o Número de Matrícula ");
	int mat;
	scanf(" %d",&mat);
	//tudo acima tem q garantir que os dados são validos.
	Aluno* novo = __new_Aluno(nome,email,mat);
	Object* objAluno = object_create(novo);
	objAluno->print = printAluno;
	objAluno->type = tipo;
	l->insert(l,objAluno);
}

void printAluno(Aluno* a){
	printf("Nome do Aluno: %s\n",a->nome);
	printf("Email do Aluno: %s\n",a->email);
	printf("Matricula do Aluno: %d\n\n",a->matricula);
}
