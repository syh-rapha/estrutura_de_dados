#include <iostream>
#include <cstdlib>
#include <ctime>
#define qtdCartelas 15
#define TRUE 1
#define FALSE 0
using namespace std;

typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
    int cartela[10];
}REGISTRO;

typedef struct{
    REGISTRO a[qtdCartelas];
    int nroElem;
}LISTA;

void inicializar(LISTA *lista){
    lista -> nroElem = 0;
}

int randomize(){
	return ((rand() % 99) + 1);
}

void insertionCrescente(LISTA *bingo, int indice){
	int i, valorAtual, indiceInserir;
	for(i=1; i < 10; i++){
		valorAtual = bingo->a[indice].cartela[i];
		indiceInserir = i;
		while(indiceInserir > 0 && valorAtual < bingo->a[indice].cartela[indiceInserir-1]){
			indiceInserir--;
			bingo->a[indice].cartela[indiceInserir+1] = bingo->a[indice].cartela[indiceInserir];
		}
		bingo->a[indice].cartela[indiceInserir] = valorAtual;
	}
}

void gerarCartela(LISTA *bingo){
	int m, i, j, flag, k, cartela_auxiliar[10];
	
	for(m=0; m < qtdCartelas; m++){
		k = 1;
		bingo->a[m].cartela[0] = randomize();
		for(i = 1; i < 10; i++){
			do{
				bingo->a[m].cartela[i] = randomize();
				flag = 0;
				for(j=0; j<k; j++)
					if(bingo->a[m].cartela[j] == bingo->a[m].cartela[i])
						flag = 1;			
			}while(flag);
			k++;
		}
		bingo->nroElem++;
		insertionCrescente(bingo, m);
	}
}

int main(){
	LISTA bingo;
	int i, j;
	srand (time(NULL));
	inicializar(&bingo);
	gerarCartela(&bingo);
	for(j=0; j<qtdCartelas; j++){
		for(i=0; i<10; i++){
			cout << " " << bingo.a[j].cartela[i];
		}
		cout << "\n";
	}
	return 0;
}
