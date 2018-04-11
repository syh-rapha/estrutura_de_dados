#include<iostream>
using namespace std;
#define MAX 50

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

int inserirElem(TIPOCHAVE ch, int i, LISTA *lista){
    int k;

    if(lista->nroElem >= MAX || i < 0 || i > lista->nroElem)
        return false;

    if((lista->nroElem > 0) && (i < lista->nroElem))
        for(k = lista->nroElem; k >= (i+1); k--)
            lista->a[k] = lista->a[k-1];

    lista->a[i].chave = ch;
    lista->nroElem++;
    return true;
}

int insereNoFim(TIPOCHAVE ch, LISTA *lista){
    return inserirElem(ch, lista->nroElem, lista);
}

void copia(LISTA lista, LISTA *lista2){
    for(int i = 0; i < lista.nroElem; i++)
        insereNoFim(lista.a[i].chave, lista2);
}

int buscaSeq(TIPOCHAVE ch, LISTA lista){
    int i;
    for(i=0; i<lista.nroElem; i++)
        if(lista.a[i].chave == ch)
            return i;
    return -1;
}

void copiaNaoRepet(LISTA lista, LISTA *lista3){
    int i, j=0;
    if(lista.nroElem > 0)
        for(i = 0; i<lista.nroElem; i++)
            if(buscaSeq(lista.a[i].chave, *lista3) == -1)
                insereNoFim(lista.a[i].chave, lista3);
}

void copiaInverte(LISTA lista1, LISTA *lista2){
    int i, k=0;
    for(i=lista1.nroElem-1; i >= 0; i--){
        inserirElem(lista1.a[i].chave, k, lista2);
        k++;
    }
}

void inverte(LISTA *lista){
    int i, j, aux;
    for(i=0, j=lista->nroElem-1; i<=j; i++, j--){
        aux = lista->a[i].chave;
        lista->a[i].chave = lista->a[j].chave;
        lista->a[j].chave = aux;
    }
}

void concatenar(LISTA lista1, LISTA lista2, LISTA *lista3){
    int i;
    for(i=0; i<lista1.nroElem; i++)
        insereNoFim(lista1.a[i].chave, lista3);
    for(i=0; i<lista2.nroElem; i++)
        insereNoFim(lista2.a[i].chave, lista3);
}

void exibir(LISTA lista){
    int i;

    cout << "\nLista ->";
    for(i=0; i < lista.nroElem; i++)
        cout << " " << lista.a[i].chave;
    cout << "\n";
}


int main(){
	LISTA L1, L2, L3, L4, L5;
	inicializar(&L1);
	inicializar(&L2);
	inicializar(&L3);
	inicializar(&L4);
	inicializar(&L5);
	insereNoFim(10, &L1);
	insereNoFim(20, &L1);
	insereNoFim(15, &L1);
	insereNoFim(20, &L1);
	copia(L1, &L2); //Resolve exercicio 1
	exibir(L2);
	copiaNaoRepet(L1, &L3); //Resolve exercicio 2
	exibir(L3);
	copiaInverte(L1, &L4); //Resolve exercicio 3
	exibir(L4);
	inverte(&L1); //Resolve exercicio 4
	exibir(L1);
	concatenar(L2, L4, &L5); //Resolve exercicio 5
	exibir(L5);

	return 0;
}