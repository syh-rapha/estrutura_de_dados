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

void mostrar(NO* r){
    if(r){
        cout << "[ ";
        mostrar(r->esq);
        cout << r->chave;
        mostrar(r->dir);
        cout << " ]";
    }
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

NO* antecessor(NO* no, NO* noAnt){
	if(noAnt->dir)
		noAnt->dir = antecessor(no, noAnt->dir);
	else{
		no->chave = noAnt->chave;
		noAnt = noAnt->esq;
	}
	return noAnt;
}

NO* removeNo(NO* no, TIPOCHAVE chave){
	if(!no){
		return NULL;
	}
	if(chave < no->chave)
		no->esq = removeNo(no->esq, chave);
	else if(chave > no->chave)
		no->dir = removeNo(no->dir, chave);
	else if(chave == no->chave){
		if(!no->dir){
			no = no->esq;
		}else if(!no->esq){
			no = no->dir;
		}else if(no->dir && no->esq){
			no->esq = antecessor(no, no->esq);
		}
	}
	return no;
}

void remover(TIPOCHAVE chave, ARVORE &a){
	a.raiz = removeNo(a.raiz, chave);	
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

TIPOCHAVE buscaProxInOrdem(NO* no, TIPOCHAVE ch){
	if(no){
		buscaProxInOrdem(no->esq, ch);
		if(no->esq && no->esq->chave < ch)
				return no->chave;
		if(no->dir && no->dir->chave > ch)
				return no->chave;
		buscaProxInOrdem(no->dir, ch);
	}	
}

int main(){
	ARVORE a;
	TIPOCHAVE x;
	inicializar(a);
	inserirNaoRec(50, a);
	inserirNaoRec(30, a);
	inserirNaoRec(70, a);
	inserirNaoRec(75, a);
	inserirNaoRec(65, a);

	mostrar(a.raiz);	
	x = buscaProxInOrdem(a.raiz, 70);
	cout << "\n" << x << "\n";
	remover(50, a);
	mostrar(a.raiz);
	return 0; 
}
