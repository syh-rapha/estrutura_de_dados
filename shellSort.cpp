#include <iostream>

using namespace std;

#define n 10

void mostrar(int v[]){
	int i;
	cout << endl << "[";
	for(i=0; i < n; i++){
		cout <<v[i];
		if(i < n-1)
			cout << ", ";
	}
	cout << "]" << endl;
}

void shellSort(int vetor[]){
	int i, j, valor, h = 1;
	while(h < n)
		h = (3*h) + 1;
	while(h > 1){
		h /= 3;
		for(i = h; i<n; i++){
			valor = vetor[i];
			j = i - h;
			while(j >= 0 && valor < vetor[j]){
				vetor[j + h] = vetor[j];
				 j -= h;
			}
			vetor[j + h] = valor;
		}
	}
}

int main(){
	int v[n] = {3, 6, 2, 1, 5, 9, 4, 8, 7, 0};
	mostrar(v);
	shellSort(v);
	mostrar(v);
	return 0;
}
