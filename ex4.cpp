#include <iostream>
#include <string>
#define n 5

using namespace std;

typedef struct data{
	int dia;
	int mes;
	int ano;
}dataFormat;

void insertion(dataFormat maiorHoje[], int tamMaior){
	int i, indiceInserir;
	dataFormat valorAtual;
	for(i=1; i<tamMaior; i++){
		valorAtual = maiorHoje[i];
		indiceInserir = i;
		while(indiceInserir > 0 && valorAtual.dia < maiorHoje[indiceInserir-1].dia){
			indiceInserir--;
			maiorHoje[indiceInserir+1] = maiorHoje[indiceInserir];
		}
		maiorHoje[indiceInserir] = valorAtual;
	}
	
	for(i=1; i<tamMaior; i++){
		valorAtual = maiorHoje[i];
		indiceInserir = i;
		while(indiceInserir > 0 && valorAtual.mes < maiorHoje[indiceInserir-1].mes){
			indiceInserir--;
			maiorHoje[indiceInserir+1] = maiorHoje[indiceInserir];
		}
		maiorHoje[indiceInserir] = valorAtual;
	}
	
	for(i=1; i<tamMaior; i++){
		valorAtual = maiorHoje[i];
		indiceInserir = i;
		while(indiceInserir > 0 && valorAtual.ano < maiorHoje[indiceInserir-1].ano){
			indiceInserir--;
			maiorHoje[indiceInserir+1] = maiorHoje[indiceInserir];
		}
		maiorHoje[indiceInserir] = valorAtual;
	}
	
	cout << "Data maiores que a de hoje em ordem crescente !\n";
	for(i=0; i < tamMaior; i++)
		cout << maiorHoje[i].dia << "/" << maiorHoje[i].mes << "/" << maiorHoje[i].ano << "\n";
}


int main(){
	int i, k = 0, j = 0;
	dataFormat v[n], maiorHoje[n], menorHoje[n], hoje;
	
	cout << "Insira a data de hoje\n";
	cout << "Dia: ";
	cin >> hoje.dia;
	cout << "Mes: ";
	cin >> hoje.mes;
	cout << "Ano: ";
	cin >> hoje.ano;
	
	for(i=0; i<n; i++){
		cout << "Data " << i+1 <<"\n";
		cout << "Insira o dia: ";
		cin >> v[i].dia;
		cout << "Insira o mes: ";
		cin >> v[i].mes;
		cout << "Insira o ano: ";
		cin >> v[i].ano;
	}
	
	for(i=0; i<n; i++){
		if(v[i].ano >= hoje.ano)
			if(v[i].mes >= hoje.mes || v[i].ano > hoje.ano)
				if(v[i].dia >= hoje.dia || v[i].mes > hoje.mes || v[i].ano > hoje.ano){
					maiorHoje[k] = v[i];
					k++;
				}
		else{
			menorHoje[j] = v[i];
			j++;
		}						
	}
	
	insertion(maiorHoje, k);
		
	return 0;
}
