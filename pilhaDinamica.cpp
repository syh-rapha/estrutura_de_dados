#include <iostream>
#include <stdlib.h>
using namespace std;
typedef int TIPOCHAVE;
typedef int TIPOINFO;

typedef struct{
	TIPOINFO info;
	TIPOCHAVE chave;
}TIPOITEM;

typedef struct estrutura{
	TIPOITEM item;
	struct estrutura *prox;
}NO;

typedef struct{
	NO *topo;
}PILHA;

void inicializar(PILHA *pi){
	pi->topo = NULL;
}

void mostrar(PILHA pi){
	NO *p = pi.topo;
	cout << "\nTopo-->[";
	while(p){
		cout << p->item.chave << "/" << p->item.info;
		p = p->prox;
		if(p)
			cout << ", ";
	}
	cout << "]";
}

int procurar(int chave, PILHA pi){
	NO *p = pi.topo;
	while(p){
		if(p->item.chave == chave)
			return true;
		p = p->prox;
	}
	return false;
}

bool empilhar(TIPOCHAVE ch, int dado, PILHA *pi){
	if(procurar(ch, *pi)){
		cout << "\nChave ja existente.";
		return false;
	}
	NO *novo = (NO*)malloc(sizeof(NO));
	novo->item.chave = ch;
	novo->item.info = dado;
	novo->prox = pi->topo;
	pi->topo = novo;
	cout << "\nEmpilhado: " << ch;
	return true;
		
}

NO* primeiroElem(PILHA pi){
	if(pi.topo){
		cout <<"\nPrimeiro: " << pi.topo->item.chave << "/" << pi.topo->item.info;
		return pi.topo;
	}
	cout << "\nPilha Vazia\n";	
	return NULL;
}

NO* ultimoElem(PILHA pi){
	NO *p = pi.topo;
	if(!p){
		cout << "\nPilha Vazia !";
		return NULL;
	}
	
	while(p->prox){
			p = p->prox;
	}
	cout << "\nUltimo: " << p->item.chave << "/" << p->item.info;
	return p;
}
int tamanho(PILHA pi){
	int count = 0;
	NO *p = pi.topo;
	
	while(p){
		count++;
		p = p->prox;
	}
	return count;	
}

TIPOITEM desempilhar(PILHA *pi){
	NO *elem;
	elem = pi->topo;
	if(!elem)
		cout << "\nPilha vazia.";
	else{
		pi->topo = elem->prox;
		elem->prox = NULL;
		cout << "\nDesempilhado: " << elem->item.chave << "/" << elem->item.info;
		TIPOITEM car = elem->item;
		free(elem);
		return car;
	}
}

void esvaziar(PILHA *pi){
	while(pi->topo)
		desempilhar(pi);
}

int main(){
	PILHA pilha;
	inicializar(&pilha);
	empilhar(10, 100, &pilha);
	empilhar(20, 200, &pilha);
	mostrar(pilha);
	primeiroElem(pilha);
	ultimoElem(pilha);
	cout << "\nTamanho da pilha: " << tamanho(pilha);
	desempilhar(&pilha);
	mostrar(pilha);
	esvaziar(&pilha);
	mostrar(pilha);
	return 0;
}
