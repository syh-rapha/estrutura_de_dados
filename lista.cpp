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

    cout << "\nLista ->";
    for(i=0; i < lista.nroElem; i++)
        cout << " " << lista.a[i].chave;
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
    //cout<<"\nInserido"<<ch;
    return TRUE;
}

int insereNoFim(TIPOCHAVE ch, LISTA *lista){
    return inserirElem(ch, lista->nroElem, lista);
}

void copiaInverte(LISTA lista1, LISTA *lista2){
    int tam1, i, k=0;
    tam1 = tamanho(lista1);
    tam1--;
    for(i=tam1; i >= 0; i--){
        inserirElem(lista1.a[i].chave, k, lista2);
        k++;
    }
}

void copia(LISTA lista, LISTA *lista2){
    for(int i = 0; i < lista.nroElem; i++)
        insereNoFim(lista.a[i].chave, lista2);
}

void insertionCrescente(LISTA *lista){
	int i, valorAtual, indiceInserir;
	for(i=1; i<lista->nroElem; i++){
		valorAtual = lista->a[i].chave;
		indiceInserir = i;
		while(indiceInserir > 0 && valorAtual < lista->a[indiceInserir-1].chave){
			indiceInserir--;
			lista->a[indiceInserir+1].chave = lista->a[indiceInserir].chave;
		}
		lista->a[indiceInserir].chave = valorAtual;
	}
}

int main(){
    LISTA listaEstatica, lista2;
    inicializar(&listaEstatica);
    inicializar(&lista2);
    inserirElem(10, 0, &listaEstatica);
    insereNoFim(25, &listaEstatica);
    insereNoFim(2, &listaEstatica);
    insereNoFim(5, &listaEstatica);
    exibir(listaEstatica);
    insertionCrescente(&listaEstatica);
    exibir(listaEstatica);
    //copiaInverte(listaEstatica, &lista2);
    //copia(listaEstatica, &lista2);
    //exibir(lista2);
    return 0;
}
