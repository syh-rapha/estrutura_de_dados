#include<iostream>
using namespace std;
#define MAX 50

typedef struct{
    int elem;
    int count;
}RegistroNovo;

typedef struct{
    RegistroNovo a[MAX];
    int nroElem;
}ListaNova;

void inicializar(ListaNova *lista){
	int i;
    lista -> nroElem = 0;
    for (i=0; i<MAX; i++)
    	lista->a[i].count = 0;
}

int atualizaCount(int elemento, ListaNova *lista){
    int i, j = 0;
    for(i=0; i<lista->nroElem; i++)
        if(lista->a[i].elem == elemento){
    		lista->a[i].count++;
    		j++;
        }
    return j;
}

int inserirElem(int elemento, int i, ListaNova *lista){
    int k;

    if(lista->nroElem >= MAX || i < 0 || i > lista->nroElem)
        return false;

    if((lista->nroElem > 0) && (i < lista->nroElem))
        for(k = lista->nroElem; k >= (i+1); k--)
            lista->a[k] = lista->a[k-1];

    lista->a[i].elem = elemento;
    lista->a[i].count = atualizaCount(lista->a[i].elem, lista) + 1;
    lista->nroElem++;
    return true;
}

int insereNoFim(int elemento, ListaNova *lista){
    return inserirElem(elemento, lista->nroElem, lista);
}


int buscaSeq(int elemento, ListaNova lista){
    int i;
    for(i=0; i < lista.nroElem; i++)
        if(lista.a[i].elem == elemento){
    		return i;
        }
        return -1;
}

void copiaNaoRepet(ListaNova lista, ListaNova *listaNaoRepeat){
    int i, j=0;
    if(lista.nroElem > 0)
        for(i = 0; i<lista.nroElem; i++)
            if(buscaSeq(lista.a[i].elem, *listaNaoRepeat) == -1)
                insereNoFim(lista.a[i].elem, listaNaoRepeat);
}

void exibir (ListaNova lista){
	int i;
	cout << "\n";
	for(i=0; i < lista.nroElem; i++)
		cout << "|" << lista.a[i].elem;
	cout <<"\n---------------\n";
	for(i=0; i < lista.nroElem; i++)
		cout << "|" << lista.a[i].count << " ";
	cout << "\n";
}

int calculaFrequenciaMaior(ListaNova lista){
	int maior, i;
	if(lista.nroElem > 0)
		maior = lista.a[0].count;
	else return -1;
	for(i=1; i<lista.nroElem; i++)
		if(maior < lista.a[i].count)
			maior = lista.a[i].count;
	return maior;
}

int calculaFrequenciaMenor(ListaNova lista){
	int menor, i;
	if(lista.nroElem > 0){
		menor = lista.a[0].count;
	}else return -1;
	for(i=1; i<lista.nroElem; i++)
		if(menor > lista.a[i].count)
			menor = lista.a[i].count;
	return menor;
}



int main(){
	ListaNova L1, L2;
	int i;
	inicializar(&L1);
	inicializar(&L2);
	insereNoFim(10, &L1);
	insereNoFim(20, &L1);
	insereNoFim(15, &L1);
	insereNoFim(20, &L1);
	exibir(L1);
	copiaNaoRepet(L1, &L2); //Resolve exercicio 6
	exibir(L2);
	cout << "\nElementos com maior repeticao -> ";
	for(i=0; i < L1.nroElem; i++){
		int maior;
		maior = calculaFrequenciaMaior(L1); //Resolve exercicio 7
		if(maior == L1.a[i].count)
			cout << " " << L1.a[i].elem;
	}
	cout << "\nElementos com menor repeticao ->";
	for(i=0; i< L1.nroElem ; i++){
		int menor;
		menor = calculaFrequenciaMenor(L1); //Resolve exercicio 7
		if(menor == L1.a[i].count)
			cout << " " << L1.a[i].elem;
	}
	return 0;
}