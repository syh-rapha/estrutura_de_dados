#include <iostream>
#include <string.h>
using namespace std;
#define MAX 50
typedef char TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
}REGISTRO;

typedef struct{
    REGISTRO a[MAX];
    int nroElem;
}PILHA;

typedef struct{
    float capacidade;
    float peso;
}CAMINHAO;

typedef struct{
    float peso_caixa;
}CAIXA;

typedef struct{
    CAIXA a[MAX];
    int nroElem;
}PILHA_CAIXA;

void inicializarPilhaEstatica(PILHA *pilha){
	pilha->nroElem = 0;
	cout << "Pilha Inicializada\n";
}

void inicializarPilhaCaixa(PILHA_CAIXA *pilha){
	pilha->nroElem = 0;
	cout << "Pilha Inicializada\n";
}

int empilhaCaixa(float ch, PILHA_CAIXA *pilha){
	if(pilha->nroElem == MAX){
		cout << "\nPilha Cheia.";
		return false;
	}
	pilha->a[pilha->nroElem].peso_caixa = ch;
	pilha->nroElem++;
	cout<<"\nEmpilhado: " << ch;
	return ch;
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

int palindromo(string palavra){
    int i, j, tamanho;
    PILHA pilha;
	inicializarPilhaEstatica(&pilha);
    tamanho = palavra.size()/2;
    for(i=0, j=palavra.size()-1; i<j; i++, j--){
        empilha(palavra[i], &pilha);
            if(palavra[j] == pilha.a[pilha.nroElem-1].chave){
                desempilha(&pilha);

            }else{
                return false;
            }
    }
    return true;
}


int desempilhaCaixa(PILHA_CAIXA *pilha){
	if(pilha->nroElem > 0){
		float ch = pilha->a[pilha->nroElem-1].peso_caixa;
		pilha->nroElem--;
		cout<<"\nRemovido: "<<ch;
		return ch;
	}
	else{
		return -1;
	}
}

int palindromo2(string palavra){
    int i, j, tamanho;
    PILHA pilha;
	inicializarPilhaEstatica(&pilha);
    for(i=0; i<palavra.size(); i++)
        empilha(palavra[i], &pilha);
    for(i=0; i<palavra.size(); i++)
        if(pilha.a[pilha.nroElem-1].chave == palavra[i])
            desempilha(&pilha);
        else return false;
    return true;
}

void inicializarCaminhao(CAMINHAO *caminhao, float capacidade){
    caminhao->capacidade = capacidade;
    caminhao->peso = 0;
}

int carregar(PILHA_CAIXA caixa, CAMINHAO *caminhao){
    int i;
    for(i=0; i<caixa.nroElem; i++){
        if((caixa.a[i].peso_caixa + caminhao->peso) <= caminhao->capacidade)
            caminhao->peso += caixa.a[i].peso_caixa;
        else{
            cout << "\nCaminhao Carregado\n";
            return false;
        }
    }
    cout << "\nCaminhao ainda possui espaco\n";
    return true;
}

int descarregar(CAMINHAO *caminhao, PILHA_CAIXA *caixa){
    float aux;
    aux = desempilhaCaixa(caixa);
    if(aux != -1 && (caminhao->peso - aux >= caminhao->capacidade))
        caminhao->peso -= aux;
        return aux;

    cout << "Caminhao Descarregado\n";
    return false;
}


int main(){
	PILHA pilha;
	PILHA_CAIXA caixa;
	CAMINHAO caminhao;
	string expr, palavra;
	inicializarPilhaCaixa(&caixa);
	empilhaCaixa(256, &caixa);
    empilhaCaixa(302, &caixa);
    inicializarCaminhao(&caminhao, 6500.0);
    carregar(caixa, &caminhao);
    descarregar(&caminhao, &caixa);

	/**cout << "Digite uma expressao com parenteses: ";
	cin >> expr;
	if (parenteses(expr))
		cout << "\nParenteses Corretos\n";
	else{
		cout << "\nParenteses Incorretos\n";
	}**/
	/**cout << "Insira uma palavra: ";
	cin >> palavra;
	if(palindromo(palavra))
        cout << "\nEh um palindromo\n";
    else
        cout << "\nNao eh um palindromo\n";
    if(palindromo2(palavra))
        cout << "\nEh um palindromo\n";
    else
        cout << "\nNao eh um palindromo\n";**/


	return 0;
}


