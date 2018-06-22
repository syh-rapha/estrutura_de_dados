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

void bubbleSort(LISTA *lista){
    int i, j, k, trocou, aux;
    k = lista->nroElem - 1;
    while(1){
        trocou = 0;
        i=lista->inicio;
        for(j=0; j<k; j++){
            if(lista->A[i].chave > lista->A[lista->A[i].prox].chave){
            trocou = 1;
            aux = lista->A[i].chave;
            lista->A[i].chave = lista->A[lista->A[i].prox].chave;
            lista->A[lista->A[i].prox].chave = aux;
            aux = lista->A[i].info;
            lista->A[i].info = lista->A[lista->A[i].prox].info;
            lista->A[lista->A[i].prox].info = aux;
            }
            i=lista->A[i].prox;
        }
        k--;
        if(!trocou) return;
    }
}

int buscaSeqOrd(int ch, LISTA lista, int *ant){
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

int inserirOrdenado(TIPOCHAVE ch, TIPOINFO info, LISTA *lista){
    int ant, i;
    i = buscaSeqOrd(ch, *lista, &ant);
    if((lista->dispo < 0) || (i != -1))
        return false;
    i = obterNo(lista);
    lista->A[i].chave = ch;
    lista->A[i].info = info;
    if(lista->inicio < 0){
        lista->inicio = i;
        lista->A[i].prox = -1;
    }else{
        if(ant < 0){
            lista->A[i].prox = lista->inicio;
            lista->inicio = i;
        }else{
            lista->A[i].prox = lista->A[ant].prox;
            lista->A[ant].prox = i;
        }
    }
    lista->nroElem++;
    return true;
}

void devolverNo(LISTA *lista, int j){
    lista->A[j].prox = lista->dispo;
    lista->dispo = j;
}

int excluirElem(TIPOCHAVE ch, LISTA *lista){
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
    LISTA lista;
    int ant, x;
    inicializar(&lista);
    inserirNoInicio(60, 666, &lista);
    inserirNoInicio(50, 555, &lista);
    inserirNoInicio(40, 333, &lista);
    inserirNoInicio(30, 444, &lista);
    inserirNoInicio(20, 111, &lista);
    inserirNoInicio(10, 777, &lista);
    exibir(lista);
    inserirOrdenado(52, 222, &lista);
    exibir(lista);
    cout<< ant;
    return 0;

}
