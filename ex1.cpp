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
    FILA fila;
}BANCO;

void inicializar(BANCO *ba){
    ba->fila.inicio = NULL;
    ba->fila.fim = NULL;
}

void entrarNaFila(PESSOA pessoa, BANCO *ba){
    NO *novo;
    novo = (NO*)malloc(sizeof(NO));
    strcpy(novo->pessoa.nome, pessoa.nome);
    novo->pessoa.idade = pessoa.idade;
    novo->prox = NULL;

   !(ba->fila.inicio) ? ba->fila.inicio = novo : ba->fila.fim->prox = novo;

    ba->fila.fim = novo;

    cout << pessoa.nome << " entrou na fila !" << endl;
}

void atenderPessoa(BANCO *ba){
    NO *p;
    char val[50];
    p = ba->fila.inicio;
    if(!p) {
        cout << "Nao tem ninguem na fila !";
        return;
    }
    if(ba->fila.inicio == ba->fila.fim)
        ba->fila.fim = NULL;
    ba->fila.inicio = ba->fila.inicio->prox;
    strcpy(val, p->pessoa.nome);
    free(p);
    cout << val << " foi atendido(a)" << endl;
}
int main(){
    BANCO banco;
    PESSOA pessoa;
    inicializar(&banco);
    pessoa.idade = 25;
    strcpy(pessoa.nome, "Camila Bravo");
    entrarNaFila(pessoa, &banco);
    pessoa.idade = 29;
    strcpy(pessoa.nome, "Joao Romao");
    entrarNaFila(pessoa, &banco);
    atenderPessoa(&banco);
    atenderPessoa(&banco);
    atenderPessoa(&banco);
    return 0;
}



