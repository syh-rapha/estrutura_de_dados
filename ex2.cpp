#include <iostream>
#include <string>
#define n 4
using namespace std;

typedef struct dados{
	int idade;
	string nome;
}cadastro;

void selectionCrescente(cadastro v[]){
	int i, j, k, mini, trocou = 1;
	cadastro aux;
		
		for(i=0; i<(n-1); i++){
			trocou = 0;	
			mini = i;
			for(j=(i+1); j<n; j++){
				if(v[j].idade < v[mini].idade){
					mini = j;
					trocou = 1;
				}
			}
					
			aux = v[mini];
			v[mini] = v[i];
			v[i] = aux;
				
			cout << "\n";
			cout << "Repeticao Numero: " << i+1 << "\n";
			for(k=0; k<n; k++)
				cout <<"Idade: " << v[k].idade << " Nome: "<< v[k].nome << "\n";
			if(trocou == 0)
				return;
		}	
}

int main(){
	int i;
	cadastro v[n] = {{15, "Ana"}, {15, "Beatriz"},  {14, "Luisa"}, {17, "Karen"}};
	cout << "Vetor com idades desordenadas !" << "\n";
	for(i=0; i<n; i++)
		cout <<"Idade: " << v[i].idade << " Nome: "<< v[i].nome << "\n";
	cout << "------------------------------------------";	
	selectionCrescente(v);
	cout <<"\nEstabilidade Violada !\n";
	return 0;
}
