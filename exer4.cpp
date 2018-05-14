#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#define pollingDelay 5000
using namespace std;
int identificacao = 0;

typedef struct estrutura{
    int ID;
    int horaChegada, horaDecolagem, combustivel;
    struct estrutura *prox;
}NO;

typedef struct{
    NO *inicio, *fim;
}FILA;

void inicializar(FILA *fi){
    fi->inicio = NULL;
    fi->fim = NULL;
}
int gerarID(){
    identificacao += 2;
    return identificacao;
}
int randomize(int limite){
    srand(time(NULL));
    return rand() % limite;
}
void delay(){
    #ifdef _WIN32
        Sleep(pollingDelay);
    #else
        usleep(pollingDelay*1000);  /* sleep for 100 milliSeconds */
    #endif
}

void mostrar(FILA fi){
    NO *p = fi.inicio;
    cout << "\nInicio -->[";
    while(p){
        cout << p->ID;
        p = p->prox;
        if(p)
            cout << ", ";
    }
    cout << "] <--fim\n";
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

int verificaMaiorMenor(FILA filas[], int qtdFilas, int opcao){
    int comp[qtdFilas], i, menor, indiceMenor, maior, indiceMaior;

    for(i=0; i<qtdFilas; i++)
        comp[i] = tamanho(filas[i]);
    maior = menor = comp[0];
    indiceMaior = indiceMenor = 0;
    for(i=0; i<qtdFilas; i++) {
        if (menor > comp[i]){
            menor = comp[i];
            indiceMenor = i;
        }
        if(maior < comp[i]){
            maior = comp[i];
            indiceMaior = i;
        }
    }
    if(opcao)
        return indiceMenor;
    else return indiceMaior;
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
    val = p->horaDecolagem;
    free(p);
    return val;
}

void inserir(int id, int varTempo, FILA *fi){
    NO *novo;
    novo = (NO*)malloc(sizeof(NO));
    novo->ID = id;
    novo->combustivel = novo->horaChegada = novo->horaDecolagem = varTempo;
    novo->prox = NULL;

    if(!(fi->inicio))
        fi->inicio = novo;
    else
        fi->fim->prox = novo;
    fi->fim = novo;
}

void preencheFilasPouso(FILA filasPouso[], int qtdAvioes){
    int i, indiceFila, combustivel, id;
    for(i=0; i<qtdAvioes; i++){
        indiceFila = verificaMaiorMenor(filasPouso, 4, 1);
        combustivel = randomize(21);
        id = gerarID();
        inserir(id, combustivel, &filasPouso[indiceFila]);
    }
}

void preencheFilasDecolagem(FILA filasDecolagem[], int qtdAvioes){
    int i, indiceFila, id;
    for(i=0; i<qtdAvioes; i++){
        indiceFila = verificaMaiorMenor(filasDecolagem, 3, 1);
        id = gerarID();
        inserir(id, 0, &filasDecolagem[indiceFila]);
    }
}

void verificaPousoEmergencial(FILA filasPouso[]){
    int i, aux;
    NO *p;
    for(i=0; i<4; i++){
        p = filasPouso[i].inicio;
        while(p){
            if(p->combustivel == 1 && p != filasPouso[i].inicio){
                while(1){
                    aux = remover(&filasPouso[i]);

                }
            }
            p = p->prox;
        }
    }

}

void realizarPousosDecolagens(FILA filasPouso[], FILA filasDecolagem[]){
    verificaPousoEmergencial();
}

int main(){
    FILA filasPouso[4], filasDecolagem[3];
    int i, numAvioesDecolagem, numAvioesPouso;
    for(i=0; i<4; i++)
        inicializar(&filasPouso[i]);
    for(i=0; i<3; i++)
        inicializar(&filasDecolagem[i]);

    while(1){
        numAvioesPouso = randomize(4);
        numAvioesDecolagem = randomize(4);
        preencheFilasPouso(filasPouso, numAvioesPouso);
        preencheFilasDecolagem(filasDecolagem, numAvioesDecolagem);




        delay();
        if(_kbhit())
            break;
    }

    return 0;
}