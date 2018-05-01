#include <iostream>
#include <string.h>
#define MAX 50
using namespace std;

typedef string TIPOINFO;
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
    lista->A[MAX-1].prox = -1;
}

void exibir(LISTA_LIGADA_CIRCULAR lista){
    int i, prox1 = lista.inicio;

    if(lista.nroElem != 0)
        cout << "Inicio -->[";
    else return;

    for(i=0; i<lista.nroElem; i++){
        cout << lista.A[i].chave << " - " << lista.A[i].info;
        prox1 = lista.A[prox1].prox;
        if(prox1 != lista.inicio)
            cout << ", ";
    }
    cout << "]<-- Fim\n";
}

int obterNo(LISTA_LIGADA_CIRCULAR *lista){
    int no = lista->dispo;
    if(no > -1)
        lista->dispo = lista->A[no].prox;
    return no;
}

int recuperaUltimo(LISTA_LIGADA_CIRCULAR lista, int inicio){
	int i;
	for(i=0; i<lista.nroElem; i++)
		if(lista.A[i].prox == inicio)
			return i;
}
int inserirNoInicio(TIPOCHAVE ch, TIPOINFO info, LISTA_LIGADA_CIRCULAR *lista){
    int i, x;
    if(lista->dispo < 0)
        return false;
    i = obterNo(lista);
    lista->A[i].chave = ch;
    lista->A[i].info = info;
    if(lista->inicio < 0)
        lista->A[i].prox = 0;
    else{
    	lista->A[i].prox = lista->inicio;
    }
    x = recuperaUltimo(*lista, lista->inicio);
    lista->inicio = i;
    lista->A[x].prox = lista->inicio;
    lista->nroElem++;
    return true;
}

int merge(LISTA_LIGADA_CIRCULAR *lista, LISTA_LIGADA_CIRCULAR lista2){
    int i, prox1 = lista2.inicio;
    if((lista2.nroElem + lista->nroElem) > MAX)
        return false;
    for(i=0; i<lista2.nroElem; i++){
        inserirNoInicio(lista2.A[prox1].chave, lista2.A[prox1].info, lista);
        prox1 = lista2.A[prox1].prox;
    }
    return true;
}

int main(){
    LISTA_LIGADA_CIRCULAR lista, lista2, lista3;
    int ant, x;
    inicializar(&lista);
    inicializar(&lista2);
    inserirNoInicio(10, "joao", &lista);
    inserirNoInicio(20, "pedro", &lista2);
    inserirNoInicio(15, "gabriel", &lista2);
    exibir(lista);
    merge(&lista, lista2);
    exibir(lista);
    return 0;
}
