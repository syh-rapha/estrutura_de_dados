#include <iostream>
#define n 5

using namespace std;

typedef struct data{
	int dia;
	int mes;
	int ano;
}dataFormat;

int compararDatas(dataFormat data_1, dataFormat data_2){
	if(data_1.ano >= data_2.ano)
		if(data_1.mes >= data_2.mes || data_1.ano > data_2.ano)
			if(data_1.dia >= data_2.dia || data_1.mes > data_2.mes || data_1.ano > data_2.ano)
				return 1;	
	return 0;
}

void insertion(dataFormat maiorHoje[], dataFormat menorHoje[], int tamMaior, int tamMenor){
	int i, indiceInserir;
	dataFormat valorAtual;
	for(i=1; i<tamMaior; i++){
		valorAtual = maiorHoje[i];
		indiceInserir = i;
		while(indiceInserir > 0 && compararDatas(maiorHoje[indiceInserir-1], valorAtual)){
			indiceInserir--;
			maiorHoje[indiceInserir+1] = maiorHoje[indiceInserir];
		}
		maiorHoje[indiceInserir] = valorAtual;
	}

	for(i=1; i<tamMenor; i++){
		valorAtual = menorHoje[i];
		indiceInserir = i;
		while(indiceInserir > 0 && compararDatas(valorAtual, menorHoje[indiceInserir-1])){
			indiceInserir--;
			menorHoje[indiceInserir+1] = menorHoje[indiceInserir];
		}
		menorHoje[indiceInserir] = valorAtual;
	}
	
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
		if(compararDatas(v[i], hoje)){
			maiorHoje[k] = v[i];
			k++;
		}else{
			menorHoje[j] = v[i];
			j++;
		}						
	}
	
	insertion(maiorHoje, menorHoje, k, j);

	cout << "Data maiores ou iguais que a de hoje em ordem crescente !\n";
	for(i=0; i < k; i++)
		cout << maiorHoje[i].dia << "/" << maiorHoje[i].mes << "/" << maiorHoje[i].ano << "\n";

	cout << "Data menores que a de hoje em ordem decrescente !\n";
	for(i=0; i < j; i++)
		cout << menorHoje[i].dia << "/" << menorHoje[i].mes << "/" << menorHoje[i].ano << "\n";
		
	return 0;
}
