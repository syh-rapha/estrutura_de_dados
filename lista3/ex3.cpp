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
}SCROLL;

void inicializar(SCROLL *sc){
    sc->inicio = 0;
    sc->fim = 0;
    sc->nroElem = 0;
    cout<< "\nScroll Inicializado\n";
}

int estaCheia(SCROLL sc){
    if(sc.fim == MAX)
        return true;
    return false;
}

void exibir(SCROLL sc){
    int i;
    cout << "Inicio ->[";
    for(i=sc.inicio; i < sc.fim; i++){
        cout << sc.a[i].chave;
        if((i+1) < sc.fim)
            cout << "," << " ";
    }
    cout << "]<-fim\n";
}

int inserir(TIPOCHAVE ch, SCROLL *sc){
    if(estaCheia(*sc)){
        cout << "\nSCROLL CHEIO";
        return false;
    }else{
        
        sc->a[sc->fim].chave = ch;
        sc->fim++;
        sc->nroElem++;
    }
    return true;
}

void remover(SCROLL *sc, int local){
    TIPOCHAVE val;
    if(sc->nroElem > 1){
        if(local == 0){
            sc->inicio++;
        }else if(local == 1){
            sc->fim--;
        }
    }else{
        sc->inicio = 0;
        sc->fim = 0;
    }
    if(sc->nroElem != 0)
        sc->nroElem--;
}

int main(){
    SCROLL scroll;
    inicializar(&scroll);
    inserir(50, &scroll);
    exibir(scroll);
    remover(&scroll, 1);
    exibir(scroll);
    return 0;
}