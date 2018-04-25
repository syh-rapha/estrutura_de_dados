#include <iostream>
#define MAX 50
using namespace std;

typedef int TIPOINFO;
typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
    TIPOINFO info;
    int prox;
}REGISTRO;

typedef struct{
    REGISTRO A[MAX];
    int inicio, dispo;
    int nroElem;
}LISTA_LIGADA_CIRCULAR;

void inicializar(LISTA_LIGADA_CIRCULAR *lista){
    lista->dispo = 0;
    lista->inicio = -1;
    lista->nroElem = 0;
    int i;
    for(i=0; i<MAX; i++)
        lista->A[i].prox = i + 1;
    lista->A[MAX-1].prox = 0;
}

void exibir(LISTA_LIGADA_CIRCULAR lista){
    int i = lista.inicio;

    if(lista.nroElem != 0)
        cout << "Inicio -->[";
    else return;

    while(i != -1){
        cout << lista.A[i].chave << " - " << lista.A[i].info;
        i = lista.A[i].prox;
        if(i != -1)
            cout << ", ";
    }
    cout << "]<-- Fim\n";
}

int obterNo(LISTA_LIGADA_CIRCULAR *lista){
    int no = lista->dispo;
    if(no > -1 && lista->nroElem < MAX)
        lista->dispo = lista->A[no].prox;
    return no;
}

int inserirNoInicio(TIPOCHAVE ch, TIPOINFO info, LISTA_LIGADA_CIRCULAR *lista){
    int i;
    if(lista->dispo < 0)
        return false;
    i = obterNo(lista);
    lista->A[i].chave = ch;
    lista->A[i].info = info;
    if(lista->inicio < 0)
        lista->A[i].prox = 0;
    else
        lista->A[i].prox = lista->inicio;
    lista->inicio = i;
    lista->nroElem++;
    return true;

}

int buscaSeqOrd(int ch, LISTA_LIGADA_CIRCULAR lista, int *ant){
    int i = lista.inicio;
    *ant = -1;
    while(i != -1 && (lista.A[i].chave < ch)){
        *ant = i;
        i = lista.A[i].prox;
    }
    if((i != -1) && lista.A[i].chave == ch)
        return i;
    return -1;
}


void devolverNo(LISTA_LIGADA_CIRCULAR *lista, int j){
    lista->A[j].prox = lista->dispo;
    lista->dispo = j;
}

int excluirElem(TIPOCHAVE ch, LISTA_LIGADA_CIRCULAR *lista){
    int ant, ret;
    ret = buscaSeqOrd(ch,*lista, &ant);
    if(ret == -1)
        return false;
    else{
        if(ant == -1){
                lista->inicio = lista->A[ret].prox;
        }else{
            lista->A[ant].prox = lista->A[i].prox;
        }
    }
    devolverNo(lista, ret);
    lista->nroElem--;
    return true;
}

int main(){
    LISTA_LIGADA_CIRCULAR lista;
    int ant, x;
    inicializar(&lista);
    return 0;

}
