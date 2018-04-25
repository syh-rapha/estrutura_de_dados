#include <iostream>
#include <cstring>
using namespace std;
#define MAX 50
typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
}REGISTRO;

typedef struct{
    REGISTRO a[MAX];
    int inicio, fim, nroElem;
}DEQUE;

void inicializar(DEQUE *de){
    de->inicio = 0;
    de->fim = 0;
    de->nroElem = 0;
    cout<< "\nDeque Inicializado\n";
}

int estaCheia(DEQUE de){
    if(de.fim == MAX)
        return true;
    return false;
}

void exibir(DEQUE de){
    int i;
    cout << "Inicio ->[";
    for(i=de.inicio; i < de.fim; i++){
        cout << de.a[i].chave;
        if((i+1) < de.fim)
            cout << "," << " ";
    }
    cout << "]<-fim\n";
}

void mover(DEQUE *de){
    int i, j;
    for(i=0; i < de->nroElem;  i++){
        j = de->fim - i;
        de->a[j] = de->a[j-1];
    }
}

int inserir(TIPOCHAVE ch, DEQUE *de, int local){
    if(estaCheia(*de)){
        cout << "\nDEQUE CHEIO";
        return false;
    }else{
        if(local == 0){
            if(de->inicio == 0){
                mover(de);
                de->fim++;
                de->a[de->inicio].chave = ch;
            }else{
                de->inicio--;
                de->a[de->inicio].chave = ch;
            }
        }else if(local == 1){
            de->a[de->fim].chave = ch;
            de->fim++;
        }
        de->nroElem++;
    }
    return true;
}

void remover(DEQUE *de, int local){
    if(de->nroElem > 1){
        if(local == 0){
            de->inicio++;
        }else if(local == 1){
            de->fim--;
        }
    }else{
        de->inicio = 0;
        de->fim = 0;
    }
    if(de->nroElem != 0)
        de->nroElem--;
}

int main(){
    DEQUE deque;
    inicializar(&deque);
    inserir(50, &deque, 0);
    exibir(deque);
    remover(&deque, 0);
    exibir(deque);
    return 0;
}
