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
        return false;

    if((lista->nroElem > 0) && (i < lista->nroElem))
        for(k = lista->nroElem; k >= (i+1); k--)
            lista->a[k] = lista->a[k-1];

    lista->a[i].chave = ch;
    lista->nroElem++;
    //cout<<"\nInserido"<<ch;
    return true;
}

int insereNoFim(TIPOCHAVE ch, LISTA *lista){
    return inserirElem(ch, lista->nroElem, lista);
}

int inserirElemListaOrd(TIPOCHAVE ch, LISTA *lista){
    int i = 0;
    if(lista->nroElem >= MAX)
        return false;
    while(i < lista->nroElem && lista->a[i].chave < ch)
        i++;
    if(lista->a[i].chave == ch)
        return false;
    return inserirElem(ch, i, lista);
}

TIPOCHAVE primeiroElem(LISTA lista){
    if(lista.nroElem > 0)
        return lista.a[0].chave;
    return false;
}

TIPOCHAVE ultimoElem(LISTA lista){
    if(lista.nroElem > 0)
        return lista.a[lista.nroElem - 1].chave;
    return false;

}

int buscaSeq(TIPOCHAVE ch, LISTA lista){
    int i;
    for(i=0; i<lista.nroElem; i++)
        if(lista.a[i].chave == ch)
            return i;
    return -1;
}

int buscaBin(TIPOCHAVE ch, LISTA lista){
    int inicio, fim;
}

void copiaNaoRepet(LISTA lista, LISTA *lista3){
    int i, j=0;
    if(lista.nroElem > 0)
        for(i = 0; i<lista.nroElem; i++)
            if(buscaSeq(lista.a[i].chave, *lista3) == -1)
                insereNoFim(lista.a[i].chave, lista3);
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
    LISTA listaEstatica, lista2, lista3;
    inicializar(&listaEstatica);
    inicializar(&lista2);
    inicializar(&lista3);
    inserirElem(10, 0, &listaEstatica);
    insereNoFim(25, &listaEstatica);
    insereNoFim(2, &listaEstatica);
    insereNoFim(5, &listaEstatica);
    insereNoFim(10, &listaEstatica);
    exibir(listaEstatica);
    copiaNaoRepet(listaEstatica, &lista3);
    exibir(lista3);
    //copiaInverte(listaEstatica, &lista2);
    //copia(listaEstatica, &lista2);
    //exibir(lista2);
    return 0;
}
