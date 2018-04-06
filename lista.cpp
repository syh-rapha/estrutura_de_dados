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
    int inicio = 0, fim = lista.nroElem, meio;

    while(inicio < fim-1){
        meio = (inicio+fim)/2;
        if(ch > lista.a[meio].chave)
            inicio = meio;
        else if(ch < lista.a[meio].chave)
            fim = meio;
        else return meio;
    }
    return -1;
}

int excluirElem(TIPOCHAVE ch, LISTA *lista){
    int iEx = buscaBin(ch, *lista), i;
    if(iEx == -1)
        return iEx;
    for(i = iEx; i < lista->nroElem; i++)
        lista->a[i].chave = lista->a[i+1].chave;

    lista->nroElem--;
    return true;
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
void destruir(LISTA *lista){
    inicializar(lista);
}
int excluirUltimo(LISTA *lista){
    int x = lista->a[lista->nroElem-1].chave;
    if(lista->nroElem == 0)
        return -1;
    lista->nroElem--;
    //excluirElem(lista->a[lista->nroElem-1].chave, lista);
    return x;
}

void inverte2(LISTA *lista){
    int i, valor, n=lista->nroElem;
    cout << "\n Numero de Elementos -> " << lista->nroElem;
    for(i=0; i<n; i++){
        //cout<<"\nnelem: "<<lista->nroElem;
        cout<<"\ni = "<<i;
        valor = excluirUltimo(lista);
        inserirElem(valor, i, lista);
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

int main(){
    LISTA listaEstatica, lista2, lista3;
    inicializar(&listaEstatica);
    inicializar(&lista2);
    inicializar(&lista3);
    inserirElem(2, 0, &listaEstatica);
    insereNoFim(5, &listaEstatica);
    insereNoFim(10, &listaEstatica);
    insereNoFim(25, &listaEstatica);
    insereNoFim(12, &lista2);
    insereNoFim(15, &lista2);
    concatenar(listaEstatica, lista2, &lista3);
    exibir(lista3);
    inverte2(&listaEstatica);
    exibir(listaEstatica);
    return 0;
}
