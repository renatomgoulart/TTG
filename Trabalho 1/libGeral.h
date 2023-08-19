#include <iostream>
#include <string>

#define MAXTAM 100

using namespace std;

int menuPrincipal(void){ // funcionando
    printf("\t\t\tMENU DE OPCOES\n\n");
    printf("1. Modulo da logistica (grafo nao direcionado)\n");
    printf("2. Modulo de Jogo (grafo direcionado)\n");
    printf("3. Sair do programa\n\n");

    printf("Escolha a opcao desejada: ");
    int opcao;
    cin >> opcao;
    return opcao;
}

int menuLogistica(void){
    printf("\t\t\tMENU DE LOGISTICA\n\n");
    printf("1. Inserir filial\n");

    printf("Escolha a opcao desejada: ");
    int opcao;
    cin >> opcao;
    return opcao;
}

void inicializaGrafo(float matriz[MAXTAM][MAXTAM]){ // funcionando
    int i, j;
    for(i = 0;i < MAXTAM; i++)
        for(j = 0;j < MAXTAM; j++)
            matriz[i][j] = 0.0;
}

void printGrafo(float matriz[MAXTAM][MAXTAM]){ // funcionando
    int i, j;
    for(i = 0;i < MAXTAM; i++)
        for(j = 0;j < MAXTAM; j++)
            printf("i: %d e j: %d = matriz: %.2f\n", i, j, matriz[i][j]);
}