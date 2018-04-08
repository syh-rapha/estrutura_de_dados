#include <iostream>
#include <string>
#define n 20
using namespace std;

int encontraFrequencia(int matriz[][n], int x, int qtd){
	int i;
	for(i=0; i<qtd; i++)
		if(matriz[0][i] == x)
			return matriz[1][i];
}

void bubbleDecrescenteFrequencia(int matriz[][n], int v[], int j){
	int i, aux, k = n, trocou, x, y;
	while(1){
		trocou = 0;
		for(i=0; i<(k-1); i++){
			x = encontraFrequencia(matriz, v[i], j);
			y = encontraFrequencia(matriz, v[i+1], j);
			if(x < y || (x == y && v[i] < v[i+1])){
				trocou = 1;
				aux = v[i];
				v[i] = v[i+1];
				v[i+1] = aux;
			}
		}
		k--;
		if(!trocou)
			return;
	}
}

int classificaVetor(int mat[2][n], int v[]){
	int i, j=1, k, encontrou;
	for(i=0; i<n; i++)
		mat[1][i] = 0;
	
	mat[0][0] = v[0];
	mat[1][0]++;
	
	for(i=1; i<n; i++){
		encontrou = 0;
		for(k=0; k<j; k++){
			if(v[i] == mat[0][k]){
				encontrou = 1;
				mat[1][k]++;
			}
		}
		if(!encontrou){
			mat[0][j] = v[i];
			mat[1][j]++;
			j++;
		}		
	}		
	return j;
}

int main(){
	int v[n] = {9, 3, 3, 3, 7, 11, 2, 7, 9, 4, 2, 3, 11, 9, 5, 2, 9, 7, 2, 11}, matriz[2][n], qtdNumeros, i;
	qtdNumeros = classificaVetor(matriz, v);
	bubbleDecrescenteFrequencia(matriz, v, qtdNumeros);

	for(i = 0; i < n; i++)
		cout << " " << v[i];
	cout << "\n";
}