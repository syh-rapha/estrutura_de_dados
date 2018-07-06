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
    return pai;
}

NO* rotacaoEsq(NO* pai){
    NO* filho = pai->dir;
    pai->dir = filho->esq;
    filho->esq = pai;
    pai = filho;
    pai->esq = calculaAlturaFB(pai->esq);
    pai = calculaAlturaFB(pai);
    return pai;
}

NO* balancear(NO* no){
    if(no->fb == 2){
        if(no->dir->fb == -1){
            no->dir = rotacaoDir(no->dir);
        }
        no = rotacaoEsq(no);
    }else if(no->fb == -2){
            if(no->esq->fb == 1){
                no->esq = rotacaoEsq(no->esq);
            }
            no = rotacaoDir(no);
    }
    return no;
}

NO* inserirNO(NO* no, TIPOCHAVE valor){
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
    else return no;
    no = calculaAlturaFB(no);

    if(no->fb == 2 || no->fb == -2)
        no = balancear(no);
    return no;
}

void inserir(ARVORE &a, TIPOCHAVE ch){
    a.raiz = inserirNO(a.raiz, ch);
}

NO *antecessor(NO *no, NO *noAnt){
    if (noAnt->dir)
        noAnt->dir = antecessor(no, noAnt->dir);
    else {
        no->chave = noAnt->chave;
        noAnt = noAnt->esq;
    }
    if(noAnt){
        noAnt = calculaAlturaFB(noAnt);
        if(noAnt->fb == 2 || noAnt->fb == -2){
            noAnt = balancear(noAnt);
        }
    }
    return noAnt;
}

NO *removeNo(NO *no, TIPOCHAVE chave){
    if (!no){
        return NULL;
    }
    if (chave < no->chave)
        no->esq = removeNo(no->esq, chave);
    else if (no->chave < chave)
        no->dir = removeNo(no->dir, chave);
    else
        if (!no->dir && !no->esq)
            no = NULL;
        else
            if (!no->dir)
                no = no->esq;
            else if(!no->esq)
                no = no->dir;
            else
            no->esq = antecessor(no, no->esq);
    if(no){
        no = calculaAlturaFB(no);
        if(no->fb == 2 || no->fb == -2)
            no = balancear(no);
    }
    return no;
}

void remover(ARVORE &a, TIPOCHAVE chave){
    a.raiz = removeNo(a.raiz, chave);
}

int main(){
    ARVORE arv;
    inicializar(arv);
    inserir(arv, 10);
    inserir(arv, 20);
    inserir(arv, 30);
    inserir(arv, 40);
    mostrar(arv.raiz);

    return 0;
}