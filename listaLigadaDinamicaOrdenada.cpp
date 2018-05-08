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
}LISTA;

void inicializar(LISTA *li){
	li->inicio = NULL;
}

void mostrar(LISTA li){ //antiga
	NO *p = li.inicio;
	cout << "\nInicio->[";
	while(p){
		cout << p->chave << " - " <<p->info;
		p = p->prox;
		if(p)
			cout << ", ";
	}
	cout << "]\n";
}

NO* buscaSeqOrd(TIPOCHAVE ch, LISTA li, NO **ant){
	NO *p = li.inicio;
	*ant = NULL;
	while(p){
		if(p->chave >= ch)
			break;
		*ant = p;
		p = p->prox;
	}
	if(p)
		if(p->chave == ch)
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

	if(!li->inicio){
		li->inicio = novo;
		novo->prox = NULL;
	}else if(!ant){
		novo->prox = li->inicio;
		li->inicio = novo;
	}else{
		novo->prox = ant->prox;
		ant->prox = novo;
	}
	return true;
}

int quantidadeElementos(LISTA li){
	NO *p = li.inicio;
	int count = 0;
	while(p){
		count++;
		p = p->prox;
	}	
	return count;
}
NO* primeiroElemento(LISTA li){
	NO *p = li.inicio;
	if(!p)
		cout << "\nLista Vazia.\n";
	return p;
}

NO* ultimoElemento(LISTA li){
	NO *p = li.inicio;
	if(!p){
		cout << "\nLista Vazia.\n";
		return p;
	}
	while(p){
		if(!p->prox)
			return p;
		p = p->prox;
	}
}
NO* enesimoElemento(LISTA li, int n){
	NO *p = li.inicio;
	int count = 0, tam, i;
	if(!p){
		cout << "\nLista Vazia.";
		return NULL;
	}	
	tam = quantidadeElementos(li);
	if(n <= tam){
		for(i=1; i<n; i++)
			p = p->prox;
		return p;
	}else{
		cout << "\nNao ha elemento em tal posicao.\n";
		return NULL;
	}	
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
	NO *enesimo;
	inicializar(&lista);
	inserirElemListaOrd(100, 1, &lista);
	inserirElemListaOrd(50, 11, &lista);
	inserirElemListaOrd(150, 2, &lista);
	inserirElemListaOrd(130, 3, &lista);
	inserirElemListaOrd(125, 2, &lista);
	mostrar(lista);
	enesimo = enesimoElemento(lista, 1);
	cout << "\nEnesimo elemento: " << enesimo->chave;
	return 0;
}
