#include <iostream>
#include <stdlib.h>
using namespace std;

typedef int TIPOCHAVE;

typedef struct estrutura{
	TIPOCHAVE chave;
	int info;
	estrutura *prox;
}NO;

typedef struct{
	NO *inicio;
	NO *sentinela;
}LISTA;

void inicializar(LISTA *li){
	li->sentinela = (NO*)malloc(sizeof(NO));
	li->inicio = li->sentinela;
}

void mostrar(LISTA li){ //antiga
	NO *p = li.inicio;
	cout << "\nInicio->[";
	while(p != li.sentinela){
		cout << p->chave << " - " <<p->info;
		p = p->prox;
		if(p != li.sentinela)
			cout << ", ";
	}
	cout << "]\n";
}

NO* ultimoElemento(LISTA li){
	NO *p = li.inicio;
	if(p == li.sentinela){
		cout << "\nLista Vazia.\n";
		return NULL;
	}
	while(p->prox != li.sentinela){
		p = p->prox;
		cout << "\nUltimo: " << p->chave << "/" << p->info;
		return p;
	}
}

NO* enesimoElemento(LISTA li, int n){
	NO *p = li.inicio;
	int i = 1;
	if(p == li.sentinela){
		cout << "\nLista Vazia.";
		return NULL;
	}	
	while(p->prox != li.sentinela && i < n){
		p = p->prox;
		i++;
	}
	if(i != n){
		cout << "\nNao encontrado";
		return NULL;
	}	
	cout << "\nEnesimo: " << p->chave << "/" << p->info;
	return p;
}

int quantidadeElementos(LISTA li){
	NO *p = li.inicio;
	int count = 0;
	while(p != li.sentinela){
		count++;
		p = p->prox;
	}	
	return count;
}

NO* buscaSeqOrd(TIPOCHAVE ch, LISTA li, NO **ant){
	NO *p = li.inicio;
	*ant = NULL;
	li.sentinela->chave = ch;
	while(p){
		*ant = p;
		p = p->prox;
	}
	if(p != li.sentinela && p->chave == ch)
			return p;
	return NULL;
}

int inserirElemListaOrd(TIPOCHAVE ch, int novaInfo, LISTA *li){
	NO *novo;
	NO *ant;
	novo = buscaSeqOrd(ch, *li, &ant);
	if(novo){
		cout << "\nCHAVE " << ch << "JA EXISTENTE.";
		return false;
	}
	novo = (NO*)malloc(sizeof(NO));
	novo->chave = ch;
	novo->info = novaInfo;

	if(li->inicio == li->sentinela){
		li->inicio = novo;
		novo->prox = li->sentinela;
	}else{
		if(ant == NULL){
			novo->prox = li->inicio;
			li->inicio = novo;
		}else{
			novo->prox = ant->prox;
			ant->prox = novo;
		}
	}
	return true;
}

int excluirElemento(LISTA *li, TIPOCHAVE ch){
	No *ant, *p;
	p = buscaSeqOrd(ch, *li, &ant);
	if(!p){
		cout << "\nElemento nao se encontra na lista.\n";
		return false;
	}else if(!ant){
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
	inserirElemListaOrd(100, 1, &lista);
	inserirElemListaOrd(50, 11, &lista);
	inserirElemListaOrd(150, 2, &lista);
	mostrar(lista);
	return 0;
}
