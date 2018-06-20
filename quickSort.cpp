#include <iostream>
using namespace std;

int gerarPivo(int v[], int esquerda, int direita){
	int aux, passos, IPO;
	IPO = esquerda;
	
	for(passos = esquerda+1; passos < direita; passos++){
		if(v[esquerda] > v[passos]){
			IPO++;
			aux  = v[passos];
			v[passos] = v[IPO];
			v[IPO] = aux; 
		}
	}
	aux = v[esquerda];
	v[esquerda] = v[IPO];
	v[IPO] = aux;
	return IPO;
}

void quickSort(int v[], int esquerda, int direita){
	int IPO;
		
	if(direita > esquerda){
		IPO = gerarPivo(v, esquerda, direita);
		quickSort(v, esquerda, IPO-1);
		quickSort(v, IPO+1, direita);
	}
}

int main(){
	int v[6] = {6, 2, 1 ,5, 4, 10}, i;
	quickSort(v, 0, 5);
	for(i = 0; i<6; i++){
		cout << v[i] <<  " ";
	}
	
	return 0;
}
