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
    }else{
        cout << "Arvore Vazia !";
    }
}

void inicializar(ARVORE &a){
    a.raiz = NULL;
}

bool estaVazia(ARVORE a){
    if(a.raiz != NULL)
        return false;
    return true;
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

int nivelNo(TIPOCHAVE chave, NO* no, int niv){
    if(!no)
        return -1;
    if(no->chave==chave)
        return niv;
    int nivEsq = nivelNo(chave, no->esq, niv+1);
    if(nivEsq != -1)
        return nivEsq;
    int nivDir = nivelNo(chave, no->dir, niv+1);
    if(nivDir != -1)
        return nivDir;
    return -1;
}

int nivel(TIPOCHAVE chave, ARVORE &a){
    if(estaVazia(a)){
        cout << "Arvore vazia." << endl;
        return -1;
    }
    return nivelNo(chave, a.raiz, 0);
}

void percurssoPreOrdem(NO* no){
    if(no){
        cout << no->chave << endl;
        percurssoPreOrdem(no->esq);
        percurssoPreOrdem(no->dir);
    }
}

void percurssoInOrdem(NO *no){
    if(no){
        percurssoInOrdem(no->esq);
        cout << no->chave << endl;
        percurssoInOrdem(no->dir);
    }
}

void percurssoPosOrdem(NO *no){
    if(no){
        percurssoPosOrdem(no->esq);
        percurssoPosOrdem(no->dir);
        cout << no->chave << endl;
    }
}

bool estaPresente(NO *no, TIPOCHAVE valor){
    if(!no)
        return false;
    bool achou = false;
    achou = estaPresente(no->esq, valor);
    if(!achou)
        achou = estaPresente(no->dir, valor);
    if(no->chave == valor)
        return true;
}

NO* tornarVazio(NO* no){
    if(!no)
        return NULL;
    no->esq = tornarVazio(no->esq);
    no->dir = tornarVazio(no->dir);
    free(no);
    return NULL;
}

void mostraFolhas(NO* no){
    if(no){
        if(!no->dir && !no->esq)
            cout << no->chave << endl;
        mostraFolhas(no->esq);
        mostraFolhas(no->dir);
    }
}

int main(){
    bool x;
    ARVORE arv;
    inicializar(arv);
    insereRaiz(10, arv);
    insereEsquerda(10, 20, arv);
    insereDireita(10, 40, arv);
    insereEsquerda(20, 30, arv);
    mostraFolhas(arv.raiz);
}