#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
int N = 5;

void maxHeapify(int vetor[], int i, int n){
    int esq, dir, maior, temp;
    esq = 2*i + 1;
    dir = 2*i + 2;
    maior = i;
    if(esq < n && vetor[esq] > vetor[i])
        maior = esq;
    if(dir < n && vetor[dir] > vetor[maior])
        maior = dir;
    if(maior != i) {
        temp = vetor[i];
        vetor[i] = vetor[maior];
        vetor[maior] = temp;
        if((2*maior + 1) < n)
            maxHeapify(vetor, maior, n);
    }
}
void buildMaxHeap(int vetor[]){
    int i, tam;
    tam = floor(N/2);
    for(i = tam ; i>=0; i--)
        maxHeapify(vetor, i, N);
}
void heapSort(int vetor[]){
    int i, temp;
    buildMaxHeap(vetor);
    for(i=N-1; i >= 1; i--){
        temp = vetor[i];
        vetor[i] = vetor[0];
        vetor[0] = temp;
        maxHeapify(vetor, 0, i-1);
    }
}

int main(){
    int vetor[5];
    vetor[0] = 5;
    vetor[1] = 0;
    vetor[2] = 1;
    vetor[3] = 45;
    vetor[4] = 25;
    heapSort(vetor);
    for(int i = 0; i<5; i++)
        cout << vetor[i] << " ";

    return 0;
}