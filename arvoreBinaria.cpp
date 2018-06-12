//
// Created by Franco on 6/11/2018.
//

#include <iostream>
using namespace std;

typedef int TIPOCHAVE;

typedef struct estrutura{
    TIPOCHAVE chave;
    struct estrutura *esq;
    struct estrutura *dir;
}NO;

typedef struct{
    NO *raiz;
}ARVORE;

void mostrar(NO* r){
    if(r){
        cout << "[ ";
        mostrar(r->esq);
        cout << r->chave;
        mostrar(r->dir);
        cout << " ]";
    }
}

void inicializar(ARVORE &a){
    a.raiz = NULL;
}

bool estaVazia(ARVORE a){
    if(a.raiz != NULL)
        return true;
    return false;
}

void insereRaiz(TIPOCHAVE chave, ARVORE &a){
    if(a.raiz != NULL){
        cout << "Erro: raiz já existe !" << endl;
        return;
    }
    a.raiz = (NO*)malloc(sizeof(NO));
    a.raiz->chave = chave;
    a.raiz->esq = NULL;
    a.raiz->dir = NULL;
    cout << "Insercao efetuada na raiz !"<<endl;
}

NO* buscaNo(NO* no, TIPOCHAVE chave){
    if(!no)
        return NULL;
    if(no->chave == chave)
        return no;
    NO *noAux = buscaNo(no->esq, chave);
    if(noAux)
        return noAux;
    return buscaNo(no->dir, chave);
}

void insereEsquerda(TIPOCHAVE chaveBusca, TIPOCHAVE chave, ARVORE &a){
    NO *pai = buscaNo(a.raiz, chaveBusca);
    if(!pai){
        cout << "Chave inexistente." << endl;
        return;
    }
    if(pai->esq){
        cout << "Local ocupado." << endl;
        return;
    }
    pai->esq = (NO*)malloc(sizeof(NO));
    pai->esq->chave = chave;
    pai->esq->esq = NULL;
    pai->esq->dir = NULL;
    cout << "Insercao efetura a esquerda." << endl;
}

void insereDireita(TIPOCHAVE chaveBusca, TIPOCHAVE chave, ARVORE &a){
    NO *pai = buscaNo(a.raiz, chaveBusca);
    if(!pai){
        cout << "Chave inexistente." << endl;
        return;
    }
    if(pai->dir){
        cout << "Local ocupado." << endl;
        return;
    }
    pai->dir = (NO*)malloc(sizeof(NO));
    pai->dir->chave = chave;
    pai->dir->esq = NULL;
    pai->dir->dir = NULL;
    cout << "Insercao efetura a direita." << endl;
}

int conta(NO* no){

    if(!no)
        return 0;
    int k = 1;
    k = k + conta(no->esq);
    k = k + conta(no->dir);
    return k;
}

int altura(NO* no){
    if(!no)
        return 0;
    int h_esq = altura(no->esq);
    int h_dir = altura(no->dir);
    if(h_dir > h_esq)
        return ++h_dir;
    return ++h_esq;
}

int contFolhas(NO *no){
    if(!no)
        return 0;
    if(!no->esq && !no->dir)
        return 1;
    int cont1 = contFolhas(no->esq);
    int cont2 = contFolhas(no->dir);
    return cont1 + cont2;
}

int main(){
    ARVORE arv;
    inicializar(arv);
    insereRaiz(10, arv);
    insereEsquerda(10, 20, arv);
    insereDireita(10, 40, arv);
    insereEsquerda(20, 30, arv);
    mostrar(arv.raiz);
    cout << "\n" << conta(arv.raiz);
    cout << "\n" << altura(arv.raiz);
    return 0;
}