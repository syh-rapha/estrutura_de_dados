#include <iostream>
#include <bits/stdc++.h>
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

int altura(NO* no){
    if(!no)
        return 0;
    int h_esq = altura(no->esq);
    int h_dir = altura(no->dir);
    if(h_dir > h_esq)
        return ++h_dir;
    return ++h_esq;
}

bool verificaAVL(NO* no){
    int alt_dir, alt_esq;
    alt_dir = altura(no->dir);
    alt_esq = altura(no->esq);
    if((alt_dir - alt_esq) > 1 || (alt_dir - alt_esq) < -1)
        return false;
    if(no->dir)
        verificaAVL(no->dir);
    if(no->esq)
        verificaAVL(no->esq);
    return true;
}

NO* rotacaoDir(NO* pai){
    NO* filho = pai->esq;
    pai->esq = filho->dir;
    filho->dir = pai;
    pai = filho;
    return pai;
}

NO* rotacaoEsq(NO* pai){
    NO* filho = pai->dir;
    pai->dir = filho->esq;
    filho->esq = pai;
    pai = filho;
    return pai;
}

NO* balancear(NO* no){
    int alt_dir, alt_esq, fb;
    alt_dir = altura(no->dir);
    alt_esq = altura(no->esq);
    fb = alt_dir-alt_esq;
    if(fb >= 2){
        if(fb <= -1){
            no->dir = rotacaoDir(no->dir);
        }
        no = rotacaoEsq(no);
    }else if(fb <= -2){
        if(fb >= 1){
            no->esq = rotacaoEsq(no->esq);
        }
        no = rotacaoDir(no);
    }
    return no;
}

NO* toAVL(NO* no){
    if(no){
        no->dir = toAVL(no->dir);
        if(!verificaAVL(no))
            no = balancear(no);
        no->esq = toAVL(no->esq);
    }
}

int main(){
    bool x;
    ARVORE arv;
    inicializar(arv);
    insereRaiz(10, arv);
    insereEsquerda(10, 20, arv);
    insereDireita(10, 90, arv);
    insereEsquerda(20, 30, arv);
    insereEsquerda(30, 40, arv);
    x = verificaAVL(arv.raiz);
    if(!x)
        cout << "Nao eh AVL";
    else
        cout << "Eh AVL";
    toAVL(arv.raiz);
    x = verificaAVL(arv.raiz);
    if(!x)
        cout << "\nNao eh AVL";
    else
        cout << "\nEh AVL";
    return 0;
}