#include <iostream>

void bubbleCrescente(int v[]){
	int i, k=n, aux, trocou;
	while(1){
		trocou = 0;
		cout << "\nRepete " << n-k+1 << ": ";
		for(i=0; i<(k-1); i++){
			if(v[i] > v[i+1]){
				trocou = 1;
				aux = v[i];
				v[i] = v[i+1];
				v[i+1] = aux;
			}
		}
		for(i=0; i<n; ++i)
			cout <<" "<< v[i];
		k--;
		if(!trocou)
			return;
	}
}

void selectionCrescente(int v[]){
	int i, j, k, aux, mini;
	for(i=0; i<(n-1); i++){
		mini = i;
		for(j=i+1; j<n; j++)
			if(v[j] < v[mini])
				mini = j;
		aux = v[mini];
		v[mini] = v[i];
		v[i] = aux;
		cout << "\n";
		for(k=0; k<n; k++)
			cout <<" " <<v[k];
	}
}

void insertionCrescente(int v[]){
	int i, valorAtual, indiceInserir;
	for(i=1; i<n; i++){
		valorAtual = v[i];
		indiceInserir = i;
		while(indiceInserir > 0 && valorAtual < v[indiceInserir-1]){
			indiceInserir--;
			v[indiceInserir+1] = v[indiceInserir];
		}
		v[indiceInserir] = valorAtual;
	}
}


