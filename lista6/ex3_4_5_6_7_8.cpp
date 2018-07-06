#include <iostream>
#include <cstdlib>
#define MAX 50
#define n 6

using namespace std;
typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
    int prox;
} REGISTRO;

typedef struct{
    REGISTRO A[MAX];
    int inicio, dispo;
    int nroElem;
}LISTA;

void inicializarLista(LISTA *lista){
    lista->dispo = 0;
    lista->inicio = -1;
    lista->nroElem = 0;
    int i;
    for(i=0; i<MAX; i++)
        lista->A[i].prox = i + 1;
    lista->A[MAX-1].prox = -1;
}

void exibirLista(LISTA lista){
    int i = lista.inicio;

    if(lista.nroElem != 0)
        cout << "Inicio -->[";
    else return;

    while(i != -1){
        cout << lista.A[i].chave;
        i = lista.A[i].prox;
        if(i != -1)
            cout << ", ";
    }
    cout << "]<-- Fim\n";
}

int obterNo(LISTA *lista){
    int no = lista->dispo;
    if(no > -1)
        lista->dispo = lista->A[no].prox;
    return no;
}

int inserirNoInicio(TIPOCHAVE ch, LISTA *lista){
    int i;
    if(lista->dispo < 0)
        return false;
    i = obterNo(lista);
    lista->A[i].chave = ch;
    if(lista->inicio < 0)
        lista->A[i].prox = -1;
    else
        lista->A[i].prox = lista->inicio;
    lista->inicio = i;
    lista->nroElem++;
    return true;
}
// ARVORE
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

void listaParaArvore(LISTA lista, ARVORE &a){
    int i;
    for(i=0; i<lista.nroElem; i++)
        inserir(a, lista.A[i].chave);
}

void vetorParaArvore(int vetor[], ARVORE &a){
    int i;
    for(i=0; i<n; i++)
        inserir(a, vetor[i]);
}

void ordenaVetor(NO *no, int v[], int &i){

    if(no){
        ordenaVetor(no->esq, v, i);
        v[i] = no->chave;
        i++;
        ordenaVetor(no->dir, v, i);
    }
}

void gerarArvore(NO *no, ARVORE &a2, TIPOCHAVE chave){
    if(!no){
        a2.raiz = NULL;
        return;
    }
    inserir(a2, no->chave);
    if(chave > no->chave)
        gerarArvore(no->dir, a2, chave);

    else if (chave < no->chave)
        gerarArvore(no->esq, a2, chave);
}

void removeArvore(NO* no, ARVORE &a){
    if(no){
        removeArvore(no->dir, a);
        remover(a, no->chave);
        removeArvore(no->esq, a);
    }
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
    inserir(uniao, mediaGeral/2);
}

bool buscaChave(NO* no, TIPOCHAVE chave){
    if(!no)
        return false;
    if(chave < no->chave)
        buscaChave(no->esq, chave);
    else if(chave > no->chave);
        buscaChave(no->dir, chave);
    return true;
}

void gerarInterseccao(NO* no1, NO* raiz2, ARVORE &inter){
    bool flag;
    if(no1){
        gerarInterseccao(no1->esq, raiz2, inter);
        flag = buscaChave(raiz2, no1->chave);
        if(flag)
            inserir(inter, no1->chave);
        gerarInterseccao(no1->dir, raiz2, inter);
    }
}

int main(){
    LISTA lista;
    ARVORE arv, arv2, arv3, arv4, inter;
    int vetor[n] = {3, 5, 10, 2, 1, 13}, i = 0, soma = 0, cont = 0, media;
    inicializarLista(&lista);
    inicializar(arv); inicializar(arv2); inicializar(arv3); inicializar(arv4); inicializar(inter); // inicializa arvores
    inserirNoInicio(20, &lista); inserirNoInicio(10, &lista); // preenche lista
    inserir(arv, 10); inserir(arv, 15); inserir(arv, 20); inserir(arv, 30); // preenche arv
    remover(arv, 20); // resolve ex3
    listaParaArvore(lista, arv2); // resolve ex4
    mostrar(arv.raiz); cout << endl; exibirLista(lista); cout << endl; mostrar(arv2.raiz);
    vetorParaArvore(vetor, arv3);
    ordenaVetor(arv3.raiz, vetor, i); // resolve ex5
    cout << endl;
    for(i=0; i<n; i++){ // confirma se vetor foi ordenado corretamente
        cout << vetor[i] << "\t";
    }
    gerarArvore(arv.raiz, arv4, 30); // resolve ex6
    if(arv4.raiz)
        removeArvore(arv4.raiz, arv); // resolve ex6
    cout << endl;
    mostrar(arv4.raiz);
    cout << endl;
    mostrar(arv.raiz);
    mediaNos(arv.raiz, soma, cont); // resolve ex7
    if(cont)
        media = soma/cont; // resolve ex7
    criarRaizUniao(arv.raiz, arv2.raiz, inter); // resolve ex8
    gerarInterseccao(arv.raiz, arv2.raiz, inter); // resolve ex8
    cout << endl;
    mostrar(inter.raiz);
    return 0;
}