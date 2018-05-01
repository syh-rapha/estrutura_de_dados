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

int comparaListas(LISTA_LIGADA_CIRCULAR lista1, LISTA_LIGADA_CIRCULAR lista2){
	int count = 0, j, i, prox1, prox2;
	if(lista1.nroElem == 0 && lista2.nroElem == 0)
		return true;
	prox1 = lista1.inicio;
	for(i=0; i<lista1.nroElem; i++){
		prox2 = lista2.inicio;
		for(j=0; j<lista2.nroElem; j++){
			if(lista1.A[prox1].chave == lista2.A[prox2].chave){
				count++;
				break;
			}
			prox2 = lista2.A[prox2].prox;
		}
		prox1 = lista1.A[prox1].prox;
	}
	if(count == lista1.nroElem && count == lista2.nroElem)
		return true;
	else return false;
}

int main(){
    LISTA_LIGADA_CIRCULAR lista, lista2;
    int x;
    inicializar(&lista);
    inicializar(&lista2);
    inserirNoInicio(70, 100, &lista);
    inserirNoInicio(30, 200, &lista);
    inserirNoInicio(90, 300, &lista);
    inserirNoInicio(70, 300, &lista2);
    inserirNoInicio(50, 300, &lista2);
    inserirNoInicio(90, 300, &lista2);
    exibir(lista);
    for(x=0; x<3; x++)
    	cout << "Valor da chave na posicao " << x << ": " << lista.A[x].chave << " | Proximo elemento --> " << lista.A[x].prox << "\n";
    if(comparaListas(lista, lista2))
    	cout << "Listas sao iguais !\n";
    else cout << "Listas nao sao iguais !\n";
    return 0;
}
