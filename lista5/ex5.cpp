#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

typedef struct{
    char nome[50];
    char sexo;
    int idade;
}PESSOA;

typedef struct estrutura{
    PESSOA pessoa;
    struct estrutura *esq;
    struct estrutura *dir;
}NO;

typedef struct{
    NO* raiz;
}ARVORE;

void inicializar(ARVORE &a){
    a.raiz = NULL;
}

void mostrar(NO* r){
    if(r){
        cout << "[ ";
        mostrar(r->esq);
        cout << r->pessoa.idade << "-" << r->pessoa.nome << "-" << r->pessoa.sexo;
        mostrar(r->dir);
        cout << " ]";
    }
}

NO *inserirNO(NO *no, PESSOA pessoa){
    if(!no){
        no = (NO*)malloc(sizeof(NO));
        no->pessoa.idade = pessoa.idade;
        no->pessoa.sexo = pessoa.sexo;
        strcpy(no->pessoa.nome, pessoa.nome);
        no->esq = no->dir = NULL;
    }
    else if(pessoa.idade < no->pessoa.idade){
        no->esq = inserirNO(no->esq, pessoa);
    }
    else if(pessoa.idade > no->pessoa.idade){
        no->dir = inserirNO(no->dir, pessoa);
    }
    return no;
}

void inserir(PESSOA pessoa, ARVORE &a){
    a.raiz = inserirNO(a.raiz, pessoa);
}

void contaHeM(int &homens, int &mulheres, NO* no){

    if(no){
        contaHeM(homens, mulheres, no->esq);
        if(no->pessoa.sexo == 'M')
            homens++;
        else mulheres++;
        contaHeM(homens, mulheres, no->dir);
    }
}

void mostraDadosMaior(int idade, NO* no){
    if(no){
        mostraDadosMaior(idade, no->esq);
        if(no->pessoa.idade >= idade){
            cout << "\n" << no->pessoa.idade << "-" << no->pessoa.nome << "-" << no->pessoa.sexo << "\n";
        }
        mostraDadosMaior(idade, no->dir);
    }
}

void preencheAux(PESSOA &pessoa, char nome[], char sexo, int idade){
    pessoa.sexo = sexo;
    strcpy(pessoa.nome, nome);
    pessoa.idade = idade;
}

int main(){
    ARVORE a;
    inicializar(a);
    int homens = 0, mulheres = 0;
    PESSOA aux;
    preencheAux(aux, "Joao", 'M', 20);
    inserir(aux, a);
    preencheAux(aux, "Maria", 'F', 15);
    inserir(aux, a);
    preencheAux(aux, "Pedro", 'M', 17);
    inserir(aux, a);
    preencheAux(aux, "Paulo", 'M', 21);
    inserir(aux, a);
    mostrar(a.raiz);
    contaHeM(homens, mulheres, a.raiz);
    cout << "\nQuantidade de homens: " << homens << "\n";
    cout << "\nQuantidade de mulheres: " << mulheres << "\n";
    mostraDadosMaior(17, a.raiz);
    return 0;
}


