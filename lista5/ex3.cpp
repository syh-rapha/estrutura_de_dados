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
    if(!no){
        no = (NO*)malloc(sizeof(NO));
        no->chave = valor;
        no->esq = no->dir = NULL;
    }
    else if(valor < no->chave){
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

bool verificaLista(NO* no){
    if(!no)
        return true;
    if((no->dir && !no->esq) || (!no->dir && !no->esq))
        return verificaLista(no->dir);
    else if(no->esq && !no->dir)
        return verificaLista(no->esq);
    return false;
}

int main(){
    ARVORE a;
    bool x;
    inicializar(a);
    inserir(10, a);
    inserir(9, a);
    inserir(8, a);
    mostrar(a.raiz);
    x = verificaLista(a.raiz);
    if(x)
        cout << "\nTem a estrutura de lista !";
    else
        cout << "\nNao tem a estrutura de lista !";
    return 0;
}


