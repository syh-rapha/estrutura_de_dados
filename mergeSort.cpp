#include<iostream>
using namespace std;

void mergeSort(int vet[], int ini, int fim){
	int meio;
	if(ini == fim)
		return;
		
	meio = (ini+fim)/2;
	mergeSort(vet, ini, meio);
	mergeSort(vet, meio+1, fim);
	intercala(v, ini, meio+1, fim);	
}

void intercala(int v[], int ini, int meio, int fim){
	int nroElem, i, j, qtdeInseridos = 0, aux = 0;
	int vetAux[nroElem] = {0};
	nroElem = (fim - inicio) + 1;
	
	i = ini;
	j = meio;
	while(i < meio && j <= fim){
		if(vet[i] <= vet[j]){
			vetAux[qtdeInseridos] = vet[i];
			i++;
		}else{
			vetAux[qtdeInseridos] = vet[j];
			j++;
		}	
		qtdeInseridos++;
	}
	
	while( i < meio){
		vetAux[qtdeInseridos] = vet[i];
		i++;
		qtdeInseridos++;
	}
	
	while(j <= fim){
		vetAux[qtdeInseridos] = vet[j];
		j++;
		qtdeInseridos++;
	}
	
	for(i=ini; i<=fim; i++){
		vet[i] = vetAux[aux];
		aux++;
	}
	
	
}

int main(){
	
}

