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

void copiaParaVetorInOrdem(NO *no, int v[], int &i){

    if(no){
        copiaParaVetorInOrdem(no->dir, v, i);
        v[i] = no->chave;
        i++;
        copiaParaVetorInOrdem(no->esq, v, i);
    }
}

int main(){
    ARVORE a;
    TIPOCHAVE x;
    inicializar(a);
    inserir(10, a);
    inserir(15, a);
    inserir(5, a);
    inserir(30, a);
    inserir(40, a);
    mostrar(a.raiz);
    int vet[5], k=0;
    copiaParaVetorInOrdem(a.raiz, vet, k);
    cout << "\n";
    for(int i=0; i<5; i++)
        cout << " " << vet[i];
    return 0;
}


