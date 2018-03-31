#include <iostream>
#include <cstdlib>
#include <ctime>
#define qtdCartelas 1000
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

void insertionCrescenteVetorLista(LISTA *bingo, int indice){
	int valorAtual, indiceInserir;
	for(int i = 1; i < 10; i++){
		valorAtual = bingo->a[indice].cartela[i];
		indiceInserir = i;
		while(indiceInserir > 0 && valorAtual < bingo->a[indice].cartela[indiceInserir-1]){
			indiceInserir--;
			bingo->a[indice].cartela[indiceInserir+1] = bingo->a[indice].cartela[indiceInserir];
		}
		bingo->a[indice].cartela[indiceInserir] = valorAtual;
	}
}

void insertionCrescenteVetor(int *v){
	int valorAtual, indiceInserir;
	for(int i = 1; i < 5; i++){
		valorAtual = v[i];
		indiceInserir = i;
		while(indiceInserir > 0 && valorAtual < v[indiceInserir-1]){
			indiceInserir--;
			v[indiceInserir+1] = v[indiceInserir];
		}
		v[indiceInserir] = valorAtual;
	}
}

void insertionCrescenteLista(LISTA *bingo, LISTA *lista_auxiliar){
	int indiceInserir;
	for(int i = 1; i < qtdCartelas; i++){
		lista_auxiliar->a[0] = bingo->a[i];
		indiceInserir = i;
		while(indiceInserir > 0 && lista_auxiliar->a[0].cartela[0] < bingo->a[indiceInserir-1].cartela[0]){
			indiceInserir--;
			bingo->a[indiceInserir+1] = bingo->a[indiceInserir];
		}
		bingo->a[indiceInserir] = lista_auxiliar->a[0];
	}
}

void gerarCartela(LISTA *bingo){
	int flag;
	
	for(int m = 0; m < qtdCartelas; m++){
		bingo->a[m].cartela[0] = randomize();
		for(int i = 1; i < 10; i++){
			do{
				bingo->a[m].cartela[i] = randomize();
				flag = 0;
				for(int j=0; j<i; j++)
					if(bingo->a[m].cartela[j] == bingo->a[m].cartela[i])
						flag = 1;			
			}while(flag);
		}
		bingo->nroElem++;
		insertionCrescenteVetorLista(bingo, m);
	}
}
void gerarCartelaGanhadora(int *v){
	v[0] = randomize();
	int flag;
	for(int i = 1; i < 5; i++){
		do{
			flag = 0;
			v[i] = randomize();
			for(int j=0; j<i; j++)
				if(v[j] == v[i])
					flag = 1;
		}while(flag);
	}
	insertionCrescenteVetor(v);
}

int verificaGanhador(LISTA *bingo, int *v){
	int i, contador;
	for(i=0; i<qtdCartelas; i++){
		contador = 0;
		for(int j=0; j<10; j++){
			for(int k=0; k<5; k++){
				if(v[k] == bingo->a[i].cartela[j]){
					contador++;
					if(contador == 5)
						return i;
				}
			}
		}
	}
	return qtdCartelas+1;
}

int main(){
	LISTA bingo, lista_auxiliar;
	int resultado, cartelaPremiada[5], i, k;
	srand (time(NULL));
	inicializar(&lista_auxiliar);
	inicializar(&bingo);
	gerarCartela(&bingo);
	insertionCrescenteLista(&bingo, &lista_auxiliar);
	gerarCartelaGanhadora(cartelaPremiada);
	resultado = verificaGanhador(&bingo, cartelaPremiada);

	for(i=0; i<qtdCartelas; i++){
		for(k=0; k<10; k++)
			cout << " " << bingo.a[i].cartela[k];
	cout << "\n";
	}
	
	if(resultado < qtdCartelas){
		cout << "\nCartela Vencedora ->";
		for(i=0; i<10; i++)
			cout << " " << bingo.a[resultado].cartela[i];
		cout << "\nCartela Sorteada ->";
		for(i=0; i<5; i++)
			cout << " " << cartelaPremiada[i];
		cout << "\n";
	}else cout << "\nNao houve cartela vencedora\n";
	return 0;
}