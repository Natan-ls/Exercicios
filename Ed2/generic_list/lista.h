#define Class typedef 

struct Object{
	int type;
	void* item;
	struct Object* prox;
	struct Object* ant;
	void(*print)();
}
Class Object;

struct Lista{
	Object* inicio;
	Object* fim;
	void(*show)();
	void(*insert)();
	void*(*search)();
	void(*delet)();
	int(*exec)();
}
Class Lista;

//PROTÓTIPOS
Object* object_create(void* item);
Lista* lista_create();
void lista_insert(Lista* l, Object* obj);
void lista_show(Lista* l, int type);
void* __lista_search(Lista* l, void*(*search)(), int type, void* item);
void lista_delete(Lista* l, Object* obj);
int lista_exec(Lista* l, int type, void*(*function_cmp)(), void(*function_exec)(), void* item);
int lista_cont_type(Lista* l, int type);
void tecleEnter();

//MÉTODOS CONSTRUTORES...
Object* object_create(void* item){
	Object* novo = malloc(sizeof(Object));
	novo->ant = NULL;
	novo->prox = NULL;
	novo->item = item;
	return novo;
}

Lista* lista_create(){
	Lista* nova = malloc(sizeof(Lista));
	nova->inicio = NULL;
	nova->fim = NULL;
	nova->show = lista_show;
	nova->insert = lista_insert;
	nova->delet = lista_delete;
	nova->exec = lista_exec;
	return nova;
}

//MÉTODOS DE MANIPULAÇÃO...

//Métodos privados
void* __lista_search(Lista* l, void*(*search)(), int type, void* item){
	Object* obj = l->inicio;
	while(obj){
		if(obj->type == type){
			void* objAlvo = search(obj->item, item);
			if(objAlvo)
				return obj;
		}
		obj = obj->prox;
	}
	return NULL;
}

//Métodos públicos
void lista_insert(Lista* l, Object* obj){
	if(!l){
		printf("Essa lista não foi inicializada. Execute: lista_create()!");
		return;
	}
	
	if(!l->inicio){
		l->inicio = l->fim = obj;
		return;
	}
	l->fim->prox = obj;
	obj->ant = l->fim;
	l->fim = obj;
}

void lista_show(Lista* l, int type){
	int total_type = 0;
	Object* obj = l->inicio;
	while(obj){
		if(!type){
			obj->print(obj->item);
			total_type++;
		}
		else{
			if(type == obj->type){
				obj->print(obj->item);
				total_type++;
			}
		}
		obj = obj->prox;
	}
	if(!total_type)
		printf("Essa lista está vazia!\n");
}

int lista_exec(Lista* l, int type, void*(*function_cmp)(), void(*function_exec)(), void* item){
	Object* obj = __lista_search(l, function_cmp, type, item);
	if(obj){
		if(function_exec == obj->print)
			obj->print(obj->item);
		else if(function_exec == l->delet)
			l->delet(l, obj);
		return 1;
	}
	return 0;
}

int lista_cont_type(Lista* l, int type){
	int cont_type = 0;
	Object* obj = l->inicio;
	while(obj){
		if(obj->type == type)
			cont_type++;
		obj = obj->prox;
	}
	return cont_type;
}

void lista_delete(Lista* l, Object* obj){
	if(!obj)
		return;

	if(l->inicio == obj){
		l->inicio = obj->prox;
		if(l->inicio)
			l->inicio->ant = NULL;
		else
			l->fim = NULL;
	} else {
		Object* objAnterior = obj->ant;
		objAnterior->prox = obj->prox;
		if(obj->prox)
			obj->prox->ant = objAnterior;
		else
			l->fim = objAnterior;
	}
	free(obj);
}

void tecleEnter(){
	printf("\nClique enter para voltar ao menu...");
	setbuf(stdin, NULL);
	getchar();
	system("clear");
}
