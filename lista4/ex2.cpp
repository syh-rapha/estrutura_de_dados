#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

typedef struct{
    char nome[50];
    int idade;
}PESSOA;

typedef struct estrutura{
    PESSOA pessoa;
    struct estrutura *prox;
}NO;

typedef struct{
    NO *inicio, *fim;
}FILA;

typedef struct{
    FILA fila_normal, fila_idosos;
}BANCO;

void inicializar(BANCO *ba){
    ba->fila_normal.inicio = NULL;
    ba->fila_idosos.inicio = NULL;
    ba->fila_normal.fim = NULL;
    ba->fila_idosos.fim = NULL;
}

void entrarNaFila(PESSOA pessoa, BANCO *ba){
    NO *novo;
    novo = (NO*)malloc(sizeof(NO));
    strcpy(novo->pessoa.nome, pessoa.nome);
    novo->pessoa.idade = pessoa.idade;
    novo->prox = NULL;

    if(pessoa.idade < 60) {
        !(ba->fila_normal.inicio) ? ba->fila_normal.inicio = novo : ba->fila_normal.fim->prox = novo;
        ba->fila_normal.fim = novo;
    }else{
        !(ba->fila_idosos.inicio) ? ba->fila_idosos.inicio = novo : ba->fila_idosos.fim->prox = novo;
        ba->fila_idosos.fim = novo;
    }
    cout << pessoa.nome << " entrou na fila !" << endl;
}

void atenderPessoa(BANCO *ba){
    NO *p;
    char val[50];
    if(!(ba->fila_idosos.inicio)) {
        if (!(ba->fila_normal.inicio)){
            cout << "Nao existe ninguem em ambas as filas !" << endl;
        }else{
            p = ba->fila_normal.inicio;
            if(ba->fila_normal.inicio == ba->fila_normal.fim)
                ba->fila_normal.fim = NULL;
            ba->fila_normal.inicio = ba->fila_normal.inicio->prox;
            strcpy(val, p->pessoa.nome);
            free(p);
            cout << val << " foi atendido(a)" << endl;
        }
    }else{
        p = ba->fila_idosos.inicio;
        if(ba->fila_idosos.inicio == ba->fila_idosos.fim)
            ba->fila_idosos.fim = NULL;
        ba->fila_idosos.inicio = ba->fila_idosos.inicio->prox;
        strcpy(val, p->pessoa.nome);
        free(p);
        cout << val << " foi atendido(a)" << endl;
    }
}

int main(){
    BANCO banco;
    PESSOA pessoa;
    inicializar(&banco);
    pessoa.idade = 25;
    strcpy(pessoa.nome, "Camila Bravo");
    entrarNaFila(pessoa, &banco);
    pessoa.idade = 61;
    strcpy(pessoa.nome, "Joao Romao");
    entrarNaFila(pessoa, &banco);
    atenderPessoa(&banco);
    return 0;
}