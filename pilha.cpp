#include <iostream>
#include <string.h>
using namespace std;
#define MAX 50
typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
}REGISTRO;

typedef struct{
    REGISTRO a[MAX];
    int nroElem;
}PILHA;

void inicializarPilhaEstatica(PILHA *pilha){
	pilha->nroElem = 0;
	cout << "Pilha Inicializada\n";
}

void exibir(PILHA pilha){
	int i = 0;
	cout << "\nPilha: [";
	while(i < pilha.nroElem){
		cout << pilha.a[i].chave;
		i++;
		if(i < pilha.nroElem)
			cout << ", ";
	}
	cout << "] <-- topo\n";
}

int empilha(int ch, PILHA *pilha){
	if(pilha->nroElem == MAX){
		cout << "\nPilha Cheia.";
		return false;
	}
	pilha->a[pilha->nroElem].chave = ch;
	pilha->nroElem++;
	cout<<"\nEmpilhado: " << ch;
	return ch;
}

int desempilha(PILHA *pilha){
	if(pilha->nroElem > 0){
		int ch = pilha->a[pilha->nroElem-1].chave;
		pilha->nroElem--;
		cout<<"\nRemovido: "<<ch;
		return ch;
	}
	else{
		cout << "Pilha Vazia\n";
		return false;
	}
}

void esvazia(PILHA *pilha){
	inicializarPilhaEstatica(pilha);
}

void printTopo(PILHA pilha){
	if(pilha.nroElem > 1)
		cout << "Elemento no topo: " << pilha.a[pilha.nroElem-1].chave << "\n";
	else
		cout << "Pilha Vazia\n";
}

int parenteses(string expr){
	PILHA pilha;
	inicializarPilhaEstatica(&pilha);
	int i;
	for (i=0; i< expr.size(); i++){
		if(expr[i] == '(')
			empilha(expr[i], &pilha);
		if (expr[i] == ')')
			if(pilha.nroElem == 0)
				return false;
			else desempilha(&pilha);
	}
	if(pilha.nroElem > 0)
		return false;
	return true;
}

int main(){
	PILHA pilha;
	string expr;
	cout << "Digite uma expressao com parenteses: ";
	cin >> expr;
	if (parenteses(expr))
		cout << "\nParenteses Corretos\n";
	else{
		cout << "\nParenteses Incorretos\n";
	}
	return 0;
}