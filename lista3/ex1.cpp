#include <iostream>
#define MAX 50
using namespace std;

typedef int TIPOINFO;
typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
    TIPOINFO info;
    int prox;
} REGISTRO;

typedef struct{
    REGISTRO A[MAX];
    int inicio, dispo;
    int nroElem;
}LISTA;

void inicializar(LISTA *lista){
    lista->dispo = 0;
    lista->inicio = -1;
    lista->nroElem = 0;
    int i;
    for(i=0; i<MAX; i++)
        lista->A[i].prox = i + 1;
    lista->A[MAX-1].prox = -1;
}

void exibir(LISTA lista){
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

int obterNo(LISTA *lista){
    int no = lista->dispo;
    if(no > -1)
        lista->dispo = lista->A[no].prox;
    return no;
}

int inserirNoInicio(TIPOCHAVE ch, TIPOINFO info, LISTA *lista){
    int i;
    if(lista->dispo < 0)
        return false;
    i = obterNo(lista);
    lista->A[i].chave = ch;
    lista->A[i].info = info;
    if(lista->inicio < 0)
        lista->A[i].prox = -1;
    else
        lista->A[i].prox = lista->inicio;
    lista->inicio = i;
    lista->nroElem++;
    return true;

}

void inserirDif(int i, TIPOCHAVE ch, TIPOINFO info, LISTA *lista){
    int j;
    j = obterNo(lista);
    if(lista->nroElem > 0){
        lista->A[j].prox = lista->A[i].prox;
        lista->A[j].chave = lista->A[i].chave;
        lista->A[j].info = lista->A[i].info;
        lista->A[i].prox = j;
        lista->A[i].chave = ch;
        lista->A[i].info = info;
    }else return;

}

int main(){
    LISTA lista;
    int ant, x;
    inicializar(&lista);
    inserirNoInicio(10, 20, &lista);
    exibir(lista);
    inserirDif(0, 20, 30, &lista);
    exibir(lista);
    inserirDif(7, 50, 60, &lista);
    exibir(lista);
    return 0;

}