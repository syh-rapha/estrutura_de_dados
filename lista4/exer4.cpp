#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#define pollingDelay 8000
using namespace std;
int identificacao = 0, semCommbustivel = 0, tempoMedioPouso = 0, tempoMedioDecolagem = 0, numPouso = 0, numDec = 0;

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
        cout << p->ID << " / " << p->combustivel;
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

NO* remover(FILA *fi){
    NO *p;
    p = fi->inicio;
    if(!p)
        return NULL;
    if(fi->inicio == fi->fim)
        fi->fim = NULL;
    fi->inicio = fi->inicio->prox;
    return p;
}

void inserir(NO *novo, FILA *fi){
    if(!(fi->inicio))
        fi->inicio = novo;
    else
        fi->fim->prox = novo;
    novo->prox = NULL;
    fi->fim = novo;
}

void preencheFilasPouso(FILA filasPouso[], int qtdAvioes){
    int i, indiceFila, combustivel, id;
    for(i=0; i<qtdAvioes; i++){
        NO *novo;
        novo = (NO*)malloc(sizeof(NO));
        indiceFila = verificaMaiorMenor(filasPouso, 4, 1);
        combustivel = randomize(20) + 1;
        id = gerarID();
        novo->combustivel = novo->horaDecolagem = combustivel;
        novo->ID = id;
        inserir(novo, &filasPouso[indiceFila]);
    }
}

void preencheFilasDecolagem(FILA filasDecolagem[], int qtdAvioes){
    int i, indiceFila, id;
    for(i=0; i<qtdAvioes; i++){
        NO *novo;
        novo = (NO*)malloc(sizeof(NO));
        indiceFila = verificaMaiorMenor(filasDecolagem, 3, 1);
        id = gerarID();
        novo->horaChegada = 0;
        novo->ID = id;
        inserir(novo, &filasDecolagem[indiceFila]);
    }
}

void priorizaEmergencia(FILA *filaPouso){
    NO *p = filaPouso->inicio, *aux;

    if(p->combustivel == 1)
        return;
    while(true){
            aux = remover(filaPouso);
            inserir(aux, filaPouso);
            if(filaPouso->inicio->combustivel == 1)
                return;
    }
}

void verificaEmergencia(FILA filasPouso[]){
    int i;
    NO *p;
    for(i=0; i<4; i++){
        p = filasPouso[i].inicio;
        while(p){
            if(p->combustivel == 1)
                priorizaEmergencia(&filasPouso[i]);
            p = p->prox;
        }
    }
}

void realizarPousosDecolagens(FILA filasPouso[], FILA filasDecolagem[]){
    int contadorPouDec = 0, i, aux, aux2, indiceAux;
    NO *p;
    verificaEmergencia(filasPouso);
    for(i=0; i<4; i++){
        p = filasPouso[i].inicio;
        if(p){
            if(p->combustivel == 1) {
                aux = filasPouso[i].inicio->horaDecolagem - filasPouso[i].inicio->combustivel;
                remover(&filasPouso[i]);
                tempoMedioPouso += aux;
                semCommbustivel++;
                numPouso++;
                contadorPouDec++;
            }
        }
    }
    if(contadorPouDec < 3){
        if(contadorPouDec == 0){
            indiceAux = verificaMaiorMenor(filasDecolagem, 3, 0);
            if(filasDecolagem[indiceAux].inicio) {
                tempoMedioDecolagem += filasDecolagem[indiceAux].inicio->horaChegada;
                remover(&filasDecolagem[indiceAux]);
                numDec++;
                contadorPouDec++;
            }
        }
    }
    for(i=contadorPouDec; i<3; i++){
        int flag;
        aux2 = randomize(2);
            if(aux2){
                flag = 0;
                indiceAux = verificaMaiorMenor(filasDecolagem, 3, 0);
                if(filasDecolagem[indiceAux].inicio) {
                    tempoMedioDecolagem += filasDecolagem[indiceAux].inicio->horaChegada;
                    remover(&filasDecolagem[indiceAux]);
                    numDec++;
                }else{
                    flag = 1;
                }
            }else if(!aux2 || flag){
                indiceAux = verificaMaiorMenor(filasPouso, 4, 0);
                if(filasPouso[indiceAux].inicio) {
                    aux = filasPouso[indiceAux].inicio->horaDecolagem - filasPouso[indiceAux].inicio->combustivel;
                    remover(&filasPouso[indiceAux]);
                    tempoMedioPouso += aux;
                    numPouso++;
                }
            }
    }
}

void atualizaCombustivel(FILA filasPouso[]){
    int i;
    NO *p;
    for(i=0; i<4; i++){
        p = filasPouso[i].inicio;
        while(p){
            p->combustivel--;
            p = p->prox;
        }
    }
}

void atualizaHoraDecolagem(FILA filasDecolagem[]){
    int i;
    NO *p;
    for(i=0; i<3; i++){
        while(p){
            p->horaDecolagem++;
            p = p->prox;
        }
    }
}
int main(){
    FILA filasPouso[4], filasDecolagem[3];
    int i, numAvioesDecolagem, numAvioesPouso;
    for(i=0; i<4; i++)
        inicializar(&filasPouso[i]);
    for(i=0; i<3; i++)
        inicializar(&filasDecolagem[i]);

    while(true){
        numAvioesPouso = randomize(4);
        numAvioesDecolagem = randomize(4);
        preencheFilasPouso(filasPouso, numAvioesPouso);
        preencheFilasDecolagem(filasDecolagem, numAvioesDecolagem);
        cout << "\n######### FILAS DE POUSO ANTES ##########" << endl;
        for(i=0; i<4; i++){
            mostrar(filasPouso[i]);
            cout << "Fila " << i+1 << " antes !";
        }
        cout << "\n#########################################";
        cout << "\n######### FILAS DE DECOLAGEM ANTES ##########" << endl;
        for(i=0; i<3; i++){
            mostrar(filasDecolagem[i]);
            cout << "Fila " << i+1 << " antes !";
        }
        cout << "\n#########################################";
        realizarPousosDecolagens(filasPouso, filasDecolagem);
        cout << "\n######### FILAS DE POUSO DEPOIS ##########" << endl;
        for(i=0; i<4; i++){
            mostrar(filasPouso[i]);
            cout << "Fila " << i+1 << " depois !";
        }
        cout << "\n#########################################";
        cout << "\n######### FILAS DE DECOLAGEM DEPOIS ##########" << endl;
        for(i=0; i<3; i++){
            mostrar(filasDecolagem[i]);
            cout << "Fila " << i+1 << " antes !";
        }
        cout << "\n#########################################\n";
        if(numDec)
            cout << "Tempo medio de tempo para decolagem: " << tempoMedioDecolagem/numDec << endl;
        if(numPouso)
            cout << "Tempo medio de tempo para pouso: " << tempoMedioPouso/numPouso << endl;
        cout << "Numero de avioes que pousaram sem combustivel: " << semCommbustivel << endl;
        atualizaCombustivel(filasPouso);
        atualizaHoraDecolagem(filasDecolagem);
        delay();
        if(_kbhit())
            break;
    }
    return 0;
}