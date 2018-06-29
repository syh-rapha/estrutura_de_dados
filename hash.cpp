#include <iostream>
#include <stdlib.h>
#define TAM 10
using namespace std;

typedef struct estrutura{
    int info;
    struct estrutura *prox;
}NO;

typedef struct{
    NO *inicio;
}LISTA;

typedef LISTA TAB_HASH[TAM];

void inicializar(LISTA *li){
    li->inicio = NULL;
}

NO* ultimoElemento(LISTA li){
    NO *p = li.inicio;
    if(p)
        while(p->prox)
            p = p->prox;
    return p;
}

NO* buscaSeq(int info, LISTA li, NO **ant){
    NO *p = li.inicio;
    *ant = NULL;
    while(p){
        if(p->info == info)
            return p;
        *ant = p;
        p = p->prox;
    }
    return NULL;
}

int inserirElemListaOrd(int dado, LISTA *li){
    NO *novo;
    NO *ant;
    novo = buscaSeq(dado, *li, &ant);
    if(novo){
        cout << "\nCHAVE " << dado << "JA EXISTENTE.";
        return false;
    }
    novo = (NO*)malloc(sizeof(NO));
    novo->info = dado;

    if(!li->inicio){
        li->inicio = novo;
        novo->prox = NULL;
    }else if(!ant){
        novo->prox = li->inicio;
        li->inicio = novo;
    }else{
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    return true;
}

bool excluirElem(int info, LISTA *li){
    NO *p, *ant;
    p = buscaSeq(info, *li, &ant);

    if(!p)
        return false;
    if(!ant){
        li->inicio = p->prox;
    }else{
        ant->prox = p->prox;
    }
    p->prox = NULL;
    free(p);
    return true;
}

void inicializarHash(TAB_HASH tab){
    int i;
    for(i=0; i<TAM; i++)
        inicializar(&tab[i]);
}

int funcaoHash(int chave){
    return chave % TAM;
}

void inserir(int dado, TAB_HASH tab){
    int indice = funcaoHash(dado);
    LISTA *li = &tab[indice];
    if(!inserirElemListaOrd(dado, li))
        cout << "Inserir " << dado << " FALHOU." << endl;
    else
        cout << "Inserido " << dado << endl;
}

void imprimeHash(TAB_HASH tab){
    int i;
    cout << endl;
    for(i=0; i<TAM; i++){
        cout << "Indice " << i << ": [";
        NO* p = tab[i].inicio;
        while(p != NULL){
            cout << p->info;
            p = p->prox;
            if(p)
                cout << ", ";
        }
        cout << "]" << endl;
    }
    cout << endl;
}

void remover(int dado, TAB_HASH tab){
    int indice = funcaoHash(dado);
    LISTA *li = &tab[indice];
    if(!excluirElem(dado, li))
        cout << "Remocao de " << dado << " FALHOU." << endl;
}

int main(){
    TAB_HASH tab;
    inicializarHash(tab);
    inserir(10, tab);
    inserir(2, tab);
    inserir(42, tab);
    inserir(41, tab);
    inserir(70, tab);
    inserir(88, tab);
    inserir(7, tab);
    inserir(2, tab);
    inserir(789, tab);
    inserir(123, tab);
    inserir(27, tab);
    inserir(423, tab);
    inserir(15, tab);
    inserir(20, tab);
    imprimeHash(tab);
    remover(123, tab);
    remover(70, tab);
    remover(42, tab);
    imprimeHash(tab);
    return 0;
}