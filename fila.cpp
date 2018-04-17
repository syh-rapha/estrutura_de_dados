#include <iostream>
#include <cstring>
using namespace std;
#define MAX 50
typedef string TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
}REGISTRO;

typedef struct{
    REGISTRO a[MAX];
    int inicio, fim, nroElem;
}FILA;

void inicializar(FILA *fi){
    fi->inicio = 0;
    fi->fim = 0;
    fi->nroElem = 0;
    cout<< "\nFila Inicializada\n";
}

int estaCheia(FILA fi){
    if(fi.fim == MAX)
        return true;
    return false;
}

void exibir(FILA fi){
    int i;
    cout << "Inicio ->[";
    for(i=fi.inicio; i < fi.fim; i++){
        cout << fi.a[i].chave;
        if((i+1) < fi.fim)
            cout << "," << " ";
    }
    cout << "]<-Fim";
}

int inserir(TIPOCHAVE ch, FILA *fi){
    if(estaCheia(*fi)){
        cout << "\nFILA CHEIA";
        return false;
    }else{
        fi->a[fi->fim].chave = ch;
        fi->fim++;
        fi->nroElem++;
        return true;
    }
}

TIPOCHAVE primeiroElem(FILA fi){
    if(fi.nroElem > 0)
        return fi.a[fi.inicio].chave;
    return false;
}

TIPOCHAVE remover(FILA *fi){
    TIPOCHAVE val;
    val = fi->a[fi->inicio].chave;
    if(fi->nroElem > 1){
        fi->inicio++;
    }else{
        fi->inicio = 0;
        fi->fim = 0;
    }
    fi->nroElem--;
    return val;
}

int menorMaior(TIPOCHAVE *menor, TIPOCHAVE *maior, FILA fi){
    int i;
    if(fi.nroElem == 0){
        cout << "\nFILA VAZIA";
        return false;
    }else{
        *menor = *maior = fi.a[fi.inicio].chave;
        for(i=fi.inicio; i<fi.fim; i++){
            if(fi.a[i].chave > (*maior))
                *maior = fi.a[i].chave;
            if(fi.a[i].chave < (*menor))
                *menor = fi.a[i].chave;
        }
    }
    return true;
}

int ehCrescente(FILA fi){
    int i;
    if(fi.nroElem == 0 || fi.nroElem == 1)
        return true;
    for(i=fi.inicio; i < fi.fim-1; i++){
        if(fi.a[i].chave < fi.a[i+1].chave)
            continue;
        else return false;
    }
    return true;
}

int povoar(FILA *fi){
    int i = 0;
    char aux[40];
    cout <<"\nDigite Enter para sair\n";
    while(true){
        cout << "Insira o nome " << i+1 << ": ";
        cin.getline(aux, 40);
        if(strlen(aux) == 0)
            return true;
        inserir(aux, fi);
        i++;
    }

}

int main(){
    FILA fila;
    inicializar(&fila);
    /**inserir(100, &fila);
    inserir(20, &fila);
    inserir(30, &fila);
    inserir(400, &fila);
    inserir(500, &fila);
    exibir(fila);
    TIPOCHAVE menor, maior;
    if(menorMaior(&menor, &maior, fila)){
        cout << "\nMenor: " << menor;
        cout << "\nMaior: " << maior;
    }
    if(ehCrescente(fila))
        cout << "\nA fila esta em ordem crescente\n";
    else
        cout << "\nA fila nao esta em ordem crescente\n";**/
    povoar(&fila);
    exibir(fila);

    return 0;
}
