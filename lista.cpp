#include<iostream>
using namespace std;
#define MAX 50
#define TRUE 1
#define FALSE 0
typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
}REGISTRO;

typedef struct{
    REGISTRO a[MAX];
    int nroElem;
}LISTA;

void inicializar(LISTA *lista){
    lista -> nroElem = 0;
}

int tamanho(LISTA lista){
    return lista.nroElem;
}

void exibir(LISTA lista){
    int i;

    cout << "Lista ->";
    for(i=0; i < lista.nroElem; i++)
        cout << " ", lista.a[i].chave;
}

int inserirElem(TIPOCHAVE ch, int i, LISTA *lista){
    int k;

    if(lista->nroElem >= MAX || i < 0 || i > lista->nroElem)
        return FALSE;

    if((lista->nroElem > 0) && (i < lista->nroElem))
        for(k = lista->nroElem; k >= (i+1); k--)
            lista->a[k] = lista->a[k-1];

    lista->a[i].chave = ch;
    lista->nroElem++;
    cout<<"\nInserido"<<ch;
    return TRUE;
}

int main(){


    return 0;
}
