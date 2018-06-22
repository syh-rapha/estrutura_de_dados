#include <iostream>
#include <cstdlib>
using namespace std;

typedef int TIPOCHAVE;

//INICIO LISTA
typedef struct estrutura1{
    TIPOCHAVE chave;
    struct estrutura1 *prox;
}NO1;

typedef struct{
    NO1 *inicio;
}LISTA;

void inicializarLista(LISTA *li){
    li->inicio = NULL;
}

void mostrarLista(LISTA li){
    NO1 *p = li.inicio;
    cout << "\nInicio->[";
    while(p){
        cout << p->chave;
        p = p->prox;
        if(p)
            cout << ", ";
    }
    cout << "]\n";
}
NO1* ultimoElementoLista(LISTA li){
    NO1 *p = li.inicio;
    if(p)
        while(p->prox)
            p = p->prox;
    return p;
}

void inserirNoFim(int chave, LISTA *li){
    NO1 *novoNo = (NO1*)malloc(sizeof(NO1));
    NO1 *ant = ultimoElementoLista(*li);
    novoNo->chave = chave;
    novoNo->prox = NULL;
    if(!ant)
        li->inicio = novoNo;
    else{
        ant->prox = novoNo;
    }
}
//FIM LISTA

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

void gerarLista(NO *no, LISTA *lista, TIPOCHAVE valor){
    if(!no){
        lista->inicio = NULL;
       return;
    }
    inserirNoFim(no->chave, lista);
    if(valor > no->chave)
        gerarLista(no->dir, lista, valor);
    else if (valor < no->chave)
        gerarLista(no->esq, lista, valor);
}

int main(){
    ARVORE a;
    LISTA lista;
    inicializarLista(&lista);
    inicializar(a);
    inserir(10, a);
    inserir(15, a);
    inserir(5, a);
    inserir(30, a);
    inserir(40, a);
    mostrar(a.raiz);
    gerarLista(a.raiz, &lista, 10);
    mostrarLista(lista);
    return 0;
}


