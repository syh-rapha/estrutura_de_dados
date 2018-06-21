#include <iostream>
#include <cstdlib>

using namespace std;

typedef int TIPOCHAVE;

typedef struct estrutura{
	TIPOCHAVE chave;
	struct estrutura *esq;
	struct estrutura *dir;
}NO;

typedef struct{
	NO* raiz;
}ARVORE;

void inicializar(ARVORE &a){
	a.raiz = NULL;
}

void mostrar(){
	
}

NO *inserirNO(NO *no, TIPOCHAVE valor){
	if(no){
		no = (NO*)malloc(sizeof(NO));
		no->chave = valor;
		no->esq = no->dir = NULL;
	}
	else if(valor< no->chave){
		no->esq = inserirNO(no->esq, valor);
	}
	else if(valor > no->chave){
		no->dir = inserirNO(no->dir, valor);
	}
	return no;
}

void inserir(TIPOCHAVE ch, ARVORE &a){
	a.raiz = inserirNO(a.raiz, ch);
}

void inserirNaoRec(TIPOCHAVE valor, ARVORE &a){
	NO *no;
	if(!a.raiz){
		a.raiz = (NO*)malloc(sizeof(NO));
		a.raiz->chave = valor;
		a.raiz->esq = a.raiz->dir = NULL;
	}
	else{
		no = a.raiz;
		while(1){
			if(no->chave == valor) 
				return;
			if(valor < no->chave){
				if(!no->esq){
					no->esq = (NO*)malloc(sizeof(NO));
					no->esq->chave = valor;
					no->esq->dir = no->esq->esq = NULL;
					break;
				}
				no = no->esq;
			}else if(valor > no->chave){
				if(!no->dir){
					no->dir = (NO*)malloc(sizeof(NO));
					no->dir->chave = valor;
					no->dir->dir = no->dir->esq = NULL;
					break;
				}
				no = no->dir;
			}
		}
	}
}

NO* buscaNoNaoRec(NO* no, TIPOCHAVE chave){
	if(!no)
		return NULL;
	while(1){
		if(no->chave == chave)
			return no;
		if(chave < no->chave){
			if(no->esq)
				no = no->esq;
			else return NULL;
		}else if(chave > no->chave){
			if(no->dir)
				no = no->dir;
			else return NULL;
		}
	}
}

NO* buscaNoRec(NO* no, TIPOCHAVE chave){
	if(!no)
		return NULL;
	if(no->chave == chave)
		return no;
	if(chave < no->chave)
		return buscaNoRec(no->esq, chave);
	else
		return buscaNoRec(no->dir, chave);
}

TIPOCHAVE minimo(NO* no){
	if(!no)
		return false;
	if(no->esq)
		return minimo(no->esq);	
	return no->chave;
}

TIPOCHAVE maximo(NO* no){
	if(!no)
		return false;
	if(no->dir)
		return maximo(no->dir);	
	return no->chave;
}	

void copiaParaVetorInOrdem(NO *no, int v[], int &i){
	
	if(no){
		copiaParaVetorInOrdem(no->esq, v, i);
		v[i] = no->chave;
		i++;
		copiaParaVetorInOrdem(no->dir, v, i);
	}
}

int main(){
	ARVORE a;
	TIPOCHAVE x;
	inicializar(a);
	inserirNaoRec(10, a);
	inserirNaoRec(15, a);
	inserirNaoRec(5, a);
	inserirNaoRec(30, a);
	inserirNaoRec(40, a);
	int vet[5], k=0;
	copiaParaVetorInOrdem(a.raiz, vet, k);
	for(int i=0; i<5; i++)
		cout << " " << vet[i];	
	return 0; 
}
