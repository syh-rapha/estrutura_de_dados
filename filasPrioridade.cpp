#include <iostream>
#include <stdlib.h>
using namespace std;

typedef int TIPOINFO;

typedef struct estrutura{
    TIPOINFO info;
    int prioridade;
    struct estrutura *prox;
}NO;

typedef struct{
    NO *inicio, *fim;
}FILA_P;

void inicializar(FILA_P *fi){
    fi->inicio = NULL;
    fi->fim = NULL;
    cout << "\nFila inicializada.\n";
}

void mostrar(FILA_P fi){
    NO *p = fi.inicio;
    cout << "\nInicio -->[";
    while(p){
        cout << p->info << " - " << p->prioridade;
        p = p->prox;
        if(p)
            cout << ", ";
    }
    cout << "] <--fim\n";
}

void inserir(TIPOINFO novaInfo, int novaPriori, FILA_P *fi){
    NO *novo;
    novo = (NO*)malloc(sizeof(NO));
    novo->info = novaInfo;
    novo->prioridade = novaPriori;
    novo->prox = NULL;

    if(!(fi->inicio))
        fi->inicio = novo;
    else
        fi->fim->prox = novo;
    fi->fim = novo;
    cout << "\nInserido " << novaInfo;
}

int alterarPrioridade(FILA_P *fi, TIPOINFO info, int priori){
    NO *p = fi->inicio;

    while(p){
        if(p->info == info) {
            p->prioridade = priori;
            return true;
        }
        p = p->prox;
    }
    return false;
}

NO *maiorPrioridade(FILA_P fi, NO* *antMaior){
    NO *p = fi.inicio, *maior = fi.inicio;
    *antMaior = NULL;
    if(!p)
        return NULL;

    while(p->prox){
        if(maior->prioridade < p->prox->prioridade){
            maior = p->prox;
            *antMaior = p;
        }

        p = p->prox;
    }
    return maior;
}

int remover(FILA_P *fi){
    NO *p = fi->inicio, *ant;
    TIPOINFO val;

    if(!p)
        return false;
    if(fi->inicio == fi->fim){
        val = p->info;
        fi->fim = NULL;
        fi->inicio = NULL;
        free(p);
        return val;
    }else{
        p = maiorPrioridade(*fi, &ant);
        val = p->info;
        if(p == fi->inicio){
            fi->inicio = fi->inicio->prox;
        }else if(p == fi->fim){
            fi->fim = ant;
            ant->prox = p->prox;
        }else{
            ant->prox = p->prox;
        }
        p->prox = NULL;
        free(p);
        return val;
    }
}

int main(){
    FILA_P fila;
    inicializar(&fila);
    inserir(20, 2, &fila);
    inserir(30, 1, &fila);
    inserir(40, 3, &fila);
    remover(&fila);
    mostrar(fila);
    return 0;
}