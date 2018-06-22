#include <iostream>
#include <cstdlib>

using namespace std;

typedef int TIPOCHAVE;

typedef struct estrutura{
    TIPOCHAVE chave;
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
        cout << r->chave;
        mostrar(r->dir);
        cout << " ]";
    }
}

NO *inserirNO(NO *no, TIPOCHAVE valor){
    if(!no){
        no = (NO*)malloc(sizeof(NO));
        no->chave = valor;
        no->esq = no->dir = NULL;
    }
    else if(valor < no->chave){
        no->esq = inserirNO(no->esq, valor);
    }
    else if(valor > no->chave){
        no->dir = inserirNO(no->dir, valor);
    }
    return no;
}

void inserir(TIPOCHAVE ch, ARVORE &a){
    a.raiz = inserirNO(a.raiz, ch);
}

void mediaNos(NO* no, int &soma, int &cont){
    if(no){
        mediaNos(no->dir, soma, cont);
        soma += no->chave;
        cont++;
        mediaNos(no->esq, soma, cont);
    }
}

void criarRaizUniao(NO* raiz1, NO* raiz2, ARVORE &uniao){
    int soma1, cont1, soma2, cont2, mediaGeral;
    soma1 = soma2 = cont1 = cont2 = mediaGeral = 0;
    mediaNos(raiz1, soma1, cont1);
    mediaNos(raiz2, soma2, cont2);
    if(cont1)
        mediaGeral += (soma1/cont1);
    if(cont2)
        mediaGeral += (soma2/cont2);
    inserir(mediaGeral/2, uniao);
}

void copiaArv(NO* no, ARVORE &uniao){
    if(no){
        copiaArv(no->dir, uniao);
        inserir(no->chave, uniao);
        copiaArv(no->esq, uniao);
    }
}

void unirArvores(NO* raiz1, NO* raiz2, ARVORE &uniao){
    criarRaizUniao(raiz1, raiz2, uniao);
    copiaArv(raiz1, uniao);
    copiaArv(raiz2, uniao);
}

int main(){
    ARVORE a, b, uniao;
    int soma = 0, cont = 0;
    inicializar(a);
    inicializar(b);
    inicializar(uniao);
    inserir(10, a);
    inserir(9, a);
    inserir(8, a);
    inserir(20, b);
    inserir(15, b);
    inserir(7, b);
    inserir(21, b);
    mediaNos(a.raiz, soma, cont);
    if(cont)
        cout << "\nA media dos nos eh: " << soma/cont << "\n";
    else
        cout << "\nArvore vazia\n";
    mostrar(a.raiz);
    cout << "\n";
    mostrar(b.raiz);
    unirArvores(a.raiz, b.raiz, uniao);
    cout << "\n";
    mostrar(uniao.raiz);
    return 0;
}


