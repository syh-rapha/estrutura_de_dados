#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 79691

typedef struct estrutura{
    char palavra[30];
    int frequenciaPalavra;
    struct estrutura *prox;
}NO;

typedef struct{
    NO *inicio;
}TAB_HASH;

TAB_HASH tabelaHash[TAM];

void inicializar(TAB_HASH *tabela){
    tabela->inicio = NULL;
}

void inicializarTabelaHash(TAB_HASH tabelas[]){
    int i;
    for(i=0; i<TAM; i++)
        inicializar(&tabelas[i]);
}

void imprimeHash(TAB_HASH tabelas[]){
    int i;
	printf("\n");
    for(i=0; i<TAM; i++){
        printf("Indice %d : [", i);
        NO* p = tabelas[i].inicio;
        while(p != NULL){
            printf("%s", p->palavra);
            p = p->prox;
            if(p)
                printf(", ");
        }
        printf("] \n");
    }
    printf("\n");
}

NO* buscaSeq(char palavra[], TAB_HASH tabela, NO **ant){
    NO *p = tabela.inicio;
    *ant = NULL;
    while(p){
        if(!strcmp(p->palavra, palavra))
            return p;
        *ant = p;
        p = p->prox;
    }
    return NULL;
}

int hash_String(unsigned char *palavra){
    unsigned long hash = 5381;
    int c;

    while (c = *palavra++)
        hash = ((hash << 5) + hash) + c;

    return hash % TAM;
}

void inserirTabelaOrdenada(char palavra[], int hash){
    NO *novo;
    NO *ant;
    novo = buscaSeq(palavra, tabelaHash[hash], &ant);
    if(novo){
        novo->frequenciaPalavra++;
        return;
    }
    
    novo = (NO*)malloc(sizeof(NO));
    strcpy(novo->palavra, palavra);
	novo->frequenciaPalavra = 1;
	
    if(!tabelaHash[hash].inicio){
        tabelaHash[hash].inicio = novo;
        novo->prox = NULL;
    }else if(!ant){
        novo->prox = tabelaHash[hash].inicio;
        tabelaHash[hash].inicio = novo;
    }else{
        novo->prox = ant->prox;
        ant->prox = novo;
    }
}

void extrai_Palavras(char linha[]){
	char *pch;
	int hash;
	pch = strtok (linha," \n");
	while (pch != NULL){
		hash = hash_String(pch);
		inserirTabelaOrdenada(pch, hash);
		pch = strtok (NULL, " \n");		
	}
}

int le_Arquivo(){
	char arquivo[30], linha[255];
	printf("\nInsira o nome do arquivo: ");
	fflush(stdin);
	scanf("%[^\n]s", arquivo);
	FILE *arq;
	arq = fopen(arquivo, "r");
	if(arq == NULL){
		printf("\nFalha na leitura do arquivo\n");
		return 0;
	}
	while(fgets(linha, 255, arq) != NULL)
		extrai_Palavras(linha);
	fclose(arq);
	return 1;
}

void consultar_Palavra(){
	char palavra[30];
	int hash;
	NO *ant, *p;
	printf("\nDigite a palavra que deseja consultar: ");
	fflush(stdin);
	scanf("%[^\n]s", palavra);
	hash = hash_String(palavra);
	p = buscaSeq(palavra, tabelaHash[hash], &ant);
	if(p)
		printf("\nPalavra: %s // Frequencia: %d\n\n", p->palavra, p->frequenciaPalavra);
	else
		printf("A palavra nao esta armazenada na tabela hash !\n");
}

int presente_ListaMaior(NO palavrasFrequentes[], NO* p, int tamanho){
	int i;
	for(i=0; i<tamanho; i++)
		if(!strcmp(palavrasFrequentes[i].palavra, p->palavra))
			return 1;
	return 0;	
}

void percorre_Compara(NO palavrasFrequentes[], int indice, int tamanho){
	int i, maior = 0;
	NO *noMaior;
	for(i=0; i<TAM; i++){
        NO* p = tabelaHash[i].inicio;
        while(p != NULL){
        	if(p->frequenciaPalavra > maior && !presente_ListaMaior(palavrasFrequentes, p, tamanho)){
        		maior = p->frequenciaPalavra;
				noMaior = p;
			}
            p = p->prox;
        }
    }
    strcpy(palavrasFrequentes[indice].palavra, noMaior->palavra);
	palavrasFrequentes[indice].frequenciaPalavra = noMaior->frequenciaPalavra;
}

void exibe_PalavrasFrequentes(){
	int nFrequencia, i;
	printf("Digite o numero de palavras com maior frequencia que deseja encontrar: ");
	scanf("%d", &nFrequencia);
	NO palavrasFrequentes[nFrequencia];
	
	for(i=0; i<nFrequencia; i++)
		percorre_Compara(palavrasFrequentes, i, nFrequencia);
	
	printf("\n%d palavras de maior frequencia", nFrequencia);
	for(i=0; i<nFrequencia; i++)
		printf("\nPalavra: %s // Frequencia: %d", palavrasFrequentes[i].palavra, palavrasFrequentes[i].frequenciaPalavra);	
	printf("\n");
}


int main(){
	int opcao;
	inicializarTabelaHash(tabelaHash);
	do{
		printf("MENU DE OPCOES\n\n");
		printf("[1] Armazenar palavras\n");
		printf("[2] Consultar palavras\n");
		printf("[3] Exibir palavras frequentes\n");
		printf("[0] Sair\n");
		printf("Digite uma opcao: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				le_Arquivo();
				break;
			case 2:
				consultar_Palavra();
				break;
			case 3:
				exibe_PalavrasFrequentes();
				break;
			case 0:
				printf("\nEncerrando o programa !");
				break;
			default:
				printf("\nOpcao Invalida !\n");
		}
	}while(opcao);

	return 0;	
}
