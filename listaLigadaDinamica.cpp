#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct estrutura{
	int info;
	struct estrutura *prox;
}NO;

typedef struct{
	NO *inicio;
}LISTA;

void inicializar(LISTA *li){
	li->inicio = NULL;
}

void mostrar(LISTA li){
	NO *p = li.inicio;
	cout << "\nInicio->[";
	while(p){
		cout << p->info;
		p = p->prox;
		if(p)
			cout << ", ";
	}
	cout << "]\n";
}

NO* ultimoElemento(LISTA li){
	NO *p = li.inicio;
	if(p)
		while(p->prox)
			p = p->prox;
	return p;
}

NO* buscaSeq(int info, LISTA li, NO **ant){
	NO *p = li.inicio;
	*ant = NULL;
	while(p){
		if(p->info == info)
			return p;
		*ant = p;
		p = p->prox;
	}
	return NULL;
}

void inserirNoFim(int info, LISTA *li){
	NO *novoNo = (NO*)malloc(sizeof(NO));
	NO *ant = ultimoElemento(*li);
	novoNo->info = info;
	novoNo->prox = NULL;
	if(!ant)
		li->inicio = novoNo;
	else{
		ant->prox = novoNo;
	}
}

void inserirNoInicio(int info, LISTA *li){
	NO *novoNo = (NO*)malloc(sizeof(NO));
	novoNo->info = info;
	novoNo->prox = li->inicio;
	li->inicio = novoNo;
}

int excluirElem(int info, LISTA *li){
	NO *p, *ant;
	p = buscaSeq(info, *li, &ant);

	if(!p)
		return false;
	if(!ant){
		li->inicio = p->prox;
	}else{
		ant->prox = p->prox;
	}
	p->prox = NULL;
	free(p);
	return true;
}

int main(){
	LISTA lista;
	inicializar(&lista);
	inserirNoFim(111, &lista);
	inserirNoFim(222, &lista);
	inserirNoFim(333, &lista);
	mostrar(lista);
	inserirNoInicio(400, &lista);
	mostrar(lista);
	return 0;
}