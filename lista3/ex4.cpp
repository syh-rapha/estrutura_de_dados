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
    lista->A[MAX-1].prox = -1;
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


int main(){
    LISTA_LIGADA_CIRCULAR lista;
    int ant, x;
    inicializar(&lista);
    inserirNoInicio(50, 100, &lista);
    inserirNoInicio(70, 200, &lista);
    inserirNoInicio(90, 300, &lista);
    for(x=0; x<3; x++)
    	printf("Valor da chave na posicao %d: %d | Proximo elemento --> %d\n", x, lista.A[x].chave, lista.A[x].prox);
    return 0;

}
