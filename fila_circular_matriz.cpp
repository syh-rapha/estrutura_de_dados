#include <iostream>
#include <cstring>
using namespace std;
#define DIM 3
typedef float TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
}REGISTRO;

typedef struct{
    REGISTRO a[DIM][DIM];
    int inicio_i, inicio_j, fim_i, fim_j, nroElem;
}FILA_CIRCULAR;

void inicializar(FILA_CIRCULAR *fi){
    fi->inicio_i = 0;
    fi->fim_i = 0;
    fi->inicio_j = 0;
    fi->fim_j = 0;
    fi->nroElem = 0;
    cout<< "\nFila Inicializada\n";
}

void passo(int *i, int *j){
	if(*j + 1 == DIM){
		if(*i + 1 == DIM)
			*j = (*j + 1)%DIM;
		*i = (i + 1)%DIM;
	}else
		*j = (*j + 1)%DIM;
}

int estaCheia(FILA_CIRCULAR fi){
    if(fi.nroElem == (DIM*DIM)-1)
        return true;
    return false;
}

void exibir(FILA_CIRCULAR fi){
	int i, j, k;
	cout << "\nFila: inicio --> [";
	i = fi.inicio_i;
	j = fi.inicio_j;
	for(k=0; k<fi.nroElem; k++){
		cout << fi.a[i][j].chave;
		passo(&i, &j);
		if(k<fi.nroElem - 1) 
			cout << ", ";
	}
	cout << "] <-- fim";
}

int main(){
    FILA_CIRCULAR fila;
    int x;
    inicializar(&fila);

    return 0;
}

