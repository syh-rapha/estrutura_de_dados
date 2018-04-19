#include <iostream>
#include <cstring>
using namespace std;
#define MAX 50
typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
}REGISTRO;

typedef struct{
    REGISTRO a[MAX];
    int inicio, fim, nroElem;
}FILA_CIRCULAR;

void inicializar(FILA_CIRCULAR *fi){
    fi->inicio = 0;
    fi->fim = 0;
    fi->nroElem = 0;
    cout<< "\nFila Inicializada\n";
}

int estaCheia(FILA_CIRCULAR fi){
    if(fi.nroElem == MAX - 1)
        return true;
    return false;
}

int passo(int ponto){
	return (ponto + 1) % (MAX);
}

void exibir(FILA_CIRCULAR fi){
	int i,k;
	cout << "\nFila: inicio --> [";
	i = fi.inicio;
	for(k=0; k<fi.nroElem; k++){
		cout << fi.a[i].chave;
		i = passo(i);
		if(i != fi.fim)
			cout << ", ";
	}
	cout << "] <-- fim";
}

TIPOCHAVE inserir(int ch, FILA_CIRCULAR *fi){
    if(estaCheia(*fi)){
        cout << "\nFILA CHEIA";
        return false;
    }else{
        fi->a[fi->fim].chave = ch;
        fi->fim = passo(fi->fim);
        fi->nroElem++;
        return ch;
    }
}

TIPOCHAVE remover(FILA_CIRCULAR *fi){
    TIPOCHAVE val;
    val = fi->a[fi->inicio].chave;
    if(fi->nroElem == 0){
    	cout << "Fila Vazia";
    	return false;
    }
    else{
    	fi->inicio = passo(fi->inicio);
    	fi->nroElem--;
    }
    cout<<"\nRemovido: " << val;
    return val;
}

int retornaPosicao(TIPOCHAVE valor, FILA_CIRCULAR fi){
	int inicio, i, posicao;
	inicio = fi.inicio;
	posicao = 1;
	for(i=0; i<fi.nroElem; i++){
		if(fi.a[inicio].chave == valor)
			return posicao;
		posicao++;
		inicio = passo(inicio);
	}
	return false;
}

int main(){
    FILA_CIRCULAR fila;
    int x;
    inicializar(&fila);
    inserir(10, &fila);
    inserir(20, &fila);
    inserir(30, &fila);
    x = retornaPosicao(20, fila);
    cout << "O elemento esta na ordem: " << x << "\n";

    return 0;
}
