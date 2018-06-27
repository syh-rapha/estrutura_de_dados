#include <iostream>
#include <cstdlib>

using namespace std;

typedef int TIPOCHAVE;

typedef struct estrutura{
    TIPOCHAVE chave;
    int altura, fb;
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
        cout << r->chave << ", A = " << r->altura << ", FB = " << r->fb;
        mostrar(r->dir);
        cout << " ]";
    }
}

void mostrarNo(NO* no){
    if(no)
        cout << "" << no->chave << ", A = " << no->altura << ", FB = " << no->fb;
}

NO* calculaAlturaFB(NO* no){
    int altEsq, altDir;

    if(!no->esq)
        altEsq = 0;
    else
        altEsq = no->esq->altura;

    if(!no->dir)
        altDir = 0;
    else
        altDir = no->dir->altura;

    if(altDir > altEsq)
        no->altura = altDir + 1;
    else
        no->altura = altEsq + 1;

    no->fb = altDir - altEsq;
    return no;
}

NO* rotacaoDir(NO* pai){
    NO* filho = pai->esq;
    pai->esq = filho->dir;
    filho->dir = pai;
    pai = filho;
    pai->dir = calculaAlturaFB(pai->dir);
    pai = calculaAlturaFB(pai);
    return no;
}

NO* rotacaoEsq(NO* pai){
    NO* filho = pai->dir;
    pai->dir = filho->esq;
    filho->esq = pai;
    pai = filho;
    pai->esq = calculaAlturaFB(pai->esq);
    pai = calculaAlturaFB(pai);
    return no;
}

int main(){

    return 0;
}