#include <iostream>
#include <string>
#define n 15
using namespace std;

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

void classificaVetor(int mat[2][n], int v[]){
	int i, j=0, k, encontrou;
	for(i=0; i<n; i++)
		mat[1][i] = 0;
	
	mat[0][0] = v[0];
	mat[1][0]++;
	
	for(i=1; i<n; i++){
		encontrou = 0;
		for(k=0; k<=j; k++){
			if(v[i] == mat[0][k]){
				encontrou = 1;
				mat[1][k]++;
			}
		}
		if(!encontrou){
			j++;
			mat[0][j] = v[i];
			mat[1][j]++;
			}		
		}		
		
	//for(i=0; i<=j; i++)
	//	cout << "Numero: " << mat[0][i] << " Quantidade de vezes: " << mat[1][i] << "\n";
}

int main(){
	int v[n] = {9, 3, 3, 3, 7, 2, 7, 9, 3, 2, 3, 9, 5, 2, 9}, aux[2][n];
	classificaVetor(aux, v);
	
	
}
