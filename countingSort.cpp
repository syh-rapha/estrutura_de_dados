#include <iostream>
using namespace std;

int maior(int vetor[], int n){
	int maior = vetor[0], i;
	for(i=1; i<n; i++){
		if(vetor[i] > maior){
			maior = vetor[i];
		}
	}
	return maior;
}

void countingSort(int vetor[], int exp, int n){
	int i, vetSaida[n], aux;
	//max = maior(vetor, n);
	int vetCont[10] = {0};
	
	for(i=0; i<n; i++)
		vetCont[(vetor[i]/exp) % 10]++;
		
	for(i=1; i<10; i++)
		vetCont[i] += vetCont[i-1];
		
	for(i=n-1; i>=0; i--){
		aux = --vetCont[vetor[i]];
		vetSaida[aux] = vetor[i];
	}
		
	for(i=0; i<n; i++){
		cout << vetSaida[i] << " ";
	}	
}

void radixSort(int vetor[], int n){
	int max = maior(vetor, n), i;
	
	for(exp=1; (max/exp)>0; exp*=10){
		countingSort(vetor, exp);
	}
	
}

int main(){
	int vetor[6] = {3, 4, 7, 9, 0, 3};
	countingSort(vetor, 6);
	return 0;
}
