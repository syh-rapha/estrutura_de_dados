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

typedef struct{
    REGISTRO A[MAX];
    int inicio, dispo;
    int nroElem;
}LISTA;

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
void inicializarL(LISTA *lista){
    lista->dispo = 0;
    lista->inicio = -1;
    lista->nroElem = 0;
    int i;
    for(i=0; i<MAX; i++)
        lista->A[i].prox = i + 1;
    lista->A[MAX-1].prox = -1;
}

void exibirL(LISTA lista){
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

int obterNoL(LISTA *lista){
    int no = lista->dispo;
    if(no > -1)
        lista->dispo = lista->A[no].prox;
    return no;
}

int inserirNoInicioL(TIPOCHAVE ch, TIPOINFO info, LISTA *lista){
    int i;
    if(lista->dispo < 0)
        return false;
    i = obterNoL(lista);
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
int menor(LISTA_LIGADA_CIRCULAR lista){
    int i, menor, indice, prox1 = lista.inicio;
    menor = lista.A[prox1].chave;
    indice = prox1;
    for(i=0; i<lista.nroElem; i++){
        if(lista.A[prox1].chave < menor){
            menor = lista.A[prox1].chave;
            indice = prox1;
        }
    }
    return indice;
}

int converte(LISTA_LIGADA_CIRCULAR lista, LISTA *lista2, int P){
    int indiceMenor, i, prox1;
    if(lista.nroElem == 0)
        return false;
    indiceMenor = menor(lista);
    for(i=0; i<lista.nroElem; i++){
        if(P == indiceMenor)
            cout << "";
        else
            inserirNoInicioL(lista.A[P].chave, lista.A[P].info, lista2);
        P = lista.A[P].prox;
    }
    inserirNoInicioL(lista.A[indiceMenor].chave, lista.A[indiceMenor].info, lista2);
    P = lista2->inicio;
    for(i=0; i < lista2->nroElem-1; i++)
        P = lista2->A[P].prox;
    return P;
}

int main(){
    LISTA_LIGADA_CIRCULAR lista;
    LISTA lista2;
    int P, x;
    inicializar(&lista);
    inicializarL(&lista2);
    inserirNoInicio(70, 100, &lista);
    inserirNoInicio(30, 200, &lista);
    inserirNoInicio(50, 200, &lista);
    inserirNoInicio(20, 200, &lista);
    P = converte(lista, &lista2, 2);
    cout << "Cabeca da lista: --> " << P << "\n";
    exibirL(lista2);
    return 0;
}
