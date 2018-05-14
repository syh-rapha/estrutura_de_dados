#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct estrutura{
    int valor;
    struct estrutura *prox;
}NO;

typedef struct{
    NO *inicio, *fim;
}FILA;

void inicializar(FILA *fi){
    fi->inicio = NULL;
    fi->fim = NULL;
}

int tamanho(FILA fi){
    NO *p = fi.inicio;
    int count = 0;
    while(p){
        count++;
        p = p->prox;
    }
    return count;
}

void mostrar(FILA fi){
    NO *p = fi.inicio;
    cout << "\nInicio -->[";
    while(p){
        cout << p->valor;
        p = p->prox;
        if(p)
            cout << ", ";
    }
    cout << "] <--fim\n";
}

void inserir(int chave, FILA *fi){
    NO *novo;
    novo = (NO*)malloc(sizeof(NO));
    novo->valor = chave;
    novo->prox = NULL;

    if(!(fi->inicio))
        fi->inicio = novo;
    else
        fi->fim->prox = novo;
    fi->fim = novo;
}

int remover(FILA *fi){
    NO *p;
    int val;
    p = fi->inicio;
    if(!p)
        return false;
    if(fi->inicio == fi->fim)
        fi->fim = NULL;
    fi->inicio = fi->inicio->prox;
    val = p->valor;
    free(p);
    return val;
}

void esvaziaParcialmente(FILA *fi_1, int chave){
    int aux, i, tam, flag = 1;
    tam = tamanho(*fi_1);
    aux = remover(fi_1);
    for(i=0; i<tam; i++){
        if(chave < aux && flag == 1) {
            inserir(chave, fi_1);
            flag = 0;
        }else{
            inserir(aux, fi_1);
            aux = remover(fi_1);
        }
    }
    inserir(aux, fi_1);
}
void copia(FILA fila1, FILA *fila2){
    NO *p = fila1.inicio;
    int i, tam, aux;
    tam = tamanho(fila1);
    for(i=0; i<tam; i++){
        aux = p->valor;
        inserir(aux, fila2);
        p = p->prox;
    }
}

void uniao(FILA fi_1, FILA fi_2, FILA *fi_3, FILA *fi_4){
    NO *p1, *p2 = fi_2.inicio;
    copia(fi_1, fi_3);
    p1 = fi_3->inicio;
    int i, tam, flag;
    tam = tamanho(fi_2);
    for(i=0; i<tam; i++){
        flag = 1;
        while(flag){
            if(p2->valor < p1->valor) {
                esvaziaParcialmente(fi_3, p2->valor);
                flag = 0;
            }else if (p2->valor == p1->valor){
                flag = 0;
            }
            p1 = p1->prox;
        }
        p1 = fi_3->inicio;
        p2 = p2->prox;
    }
    mostrar(*fi_3);
    cout << "Uniao das duas filas" << endl;
    p2 = fi_2.inicio;
    p1 = fi_1.inicio;
    for(i=0; i<tam; i++){
        flag = 1;
        while(flag){
            if(p2->valor < p1->valor) {
                flag = 0;
            }else if (p2->valor == p1->valor){
                inserir(p2->valor, fi_4);
                flag = 0;
            }
            p1 = p1->prox;
        }
        p1 = fi_1.inicio;
        p2 = p2->prox;
    }
    mostrar(*fi_4);
    cout << "Intersecao das duas filas" << endl;
}

int main(){
    FILA fila1, fila2, fila3, fila4;
    inicializar(&fila1);
    inicializar(&fila2);
    inicializar(&fila3);
    inicializar(&fila4);
    inserir(1, &fila1);
    inserir(2, &fila1);
    inserir(4, &fila1);
    inserir(6, &fila1);
    inserir(7, &fila1);
    inserir(0, &fila2);
    inserir(3, &fila2);
    inserir(4, &fila2);
    inserir(5, &fila2);
    mostrar(fila1);
    mostrar(fila2);
    uniao(fila1, fila2, &fila3, &fila4);

    return 0;
}

