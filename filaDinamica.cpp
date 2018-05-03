#include <iostream>
#include <stdlib.h>
#include <malloc.h>
using namespace std;

typedef int TIPOINFO;

typedef struct estrutura{
	TIPOINFO info;
	struct estrutura *prox;
}NO;

typedef struct{
	NO *inicio, *fim;
}FILA;

void inicializar(FILA *fi){
	fi->inicio = NULL;
	fi->fim = NULL;
	cout << "\nFila inicializada.\n";
}

void mostrar(FILA fi){
	NO *p = fi.inicio;
	cout << "\nInicio -->[";
	while(p){
		cout << p->info;
		p = p->prox;
		if(p)
			cout << ", ";
	}
	cout << "] <--fim\n";
}
void inserir(TIPOINFO dado, FILA *fi){
	NO *novo;
	novo = (NO*)malloc(sizeof(NO));
	novo->info = dado;
	novo->prox = NULL;
	
	if(!(fi->inicio))
		fi->inicio = novo;
	else
		fi->fim->prox = novo;
	fi->fim = novo;
	cout << "\nInserido " << dado;
}

NO *primeiroElem(FILA fi){	
	return fi.inicio;
}

int tamanho(FILA fi){
	NO *p = fi.inicio;
	int count = 0;
	while(p){
		count++;
		p = p->prox;
	}
	return count;
}

TIPOINFO remover(FILA *fi){
	NO *p;
	TIPOINFO val;
	p = fi->inicio;
	if(!p)
		return false;
	if(fi->inicio == fi->fim)
		fi->fim = NULL;
	fi->inicio = fi->inicio->prox;
	val = p->info;
	free(p);
	return val;
}

void esvaziar(FILA *fi){
	while(fi->inicio){
		remover(fi);
	}
}

int ehCrescente(FILA fi){
	NO *p1, *p2;
	p1 = fi.inicio;
	p2 = fi.inicio->prox;
	
	while(p2){
		if(p1->info > p2->info)
			return false;
		p1 = p2;
		p2 = p2->prox;
	}
	return true;
}

void inverte(FILA *fi){
	
	NO *p1, *p2;
	int tamanho, metade, i, j;
	TIPOINFO aux;
	p1 = fi->inicio;
	p2 = fi->fim;
	tamanho = tamanho(*fi);
	metade = tamanho/2;
	
	for(i=1; i<=metade; i++){
		aux = p1->info;
		p1->info = p2->info;
		p2->info = aux;
		p1 = p1->prox;
		for(j=0; j<tamanho-i; j++)
			p2 = p2->prox;
	}
	
}

void inverte2(FILA *fi){
	
}

int main(){
	FILA fila;
	inicializar(&fila);
	inserir(400, &fila);
	inserir(200, &fila);
	inserir(300, &fila);
	mostrar(fila);
	if(ehCrescente(fila))
		cout << "\nEh crescente !";
	else
		cout << "\nNao eh crescente !";
	return 0;
}
