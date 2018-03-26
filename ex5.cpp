#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#define qtdCartelas 15
using namespace std;

int randomize(){
	return ((rand() % 99) + 1);
}

void insertionCrescente(int v[], int tam){
	int i, valorAtual, indiceInserir;
	for(i=1; i < tam; i++){
		valorAtual = v[i];
		indiceInserir = i;
		while(indiceInserir > 0 && valorAtual < v[indiceInserir-1]){
			indiceInserir--;
			v[indiceInserir+1] = v[indiceInserir];
		}
		v[indiceInserir] = valorAtual;
	}
}

void gerarCartela(int v[], int qtdNumeros, int numCartelas){
	int m, i, j, flag, k = 1;
	
	for(m=0; m < numCartelas; i++){
		v[0] = randomize();
		for(i = 1; i < qtdNumeros; i++){
			do{
				v[i] = randomize();
				flag = 0;
				for(j=0; j<k; j++)
					if(v[j] == v[i])
						flag = 1;			
			}while(flag);
			k++;
		}
		insertionCrescente(v, qtdNumeros);
	}
}

int main(){
	int v[qtdCartelas];
	srand (time(NULL));
	gerarCartela(v, 10, qtdCartelas);
	return 0;
}
