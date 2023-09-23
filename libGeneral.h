#ifndef LIBGENERAL_H
#define LIBGENERAL_H

#ifndef IOSTREAM
#include <iostream>
using namespace std;
#endif

#include "libGraph.h"

int menuPrincipal(void){ // funcionando
    system("cls");
    cout<< "\t\t\tMENU DE OPCOES\n\n"
        << "1. Modulo da logistica (grafo nao direcionado)\n"
        << "2. Modulo de Jogo (grafo direcionado)\n"
        << "3. Sair do programa\n\n"

        << "Escolha a opcao desejada: ";

    int opcao;
    cin >> opcao;
    
    return opcao;
}

int menuLogistica(void){
    system("cls");
    cout<< "\t\t\tMENU DE LOGISTICA\n\n"
        << "1. Inserir filial\n"
        << "2. Inserir movimentacao\n"
        << "3. Lista de filial proximas\n"
        << "4. Atualizar a movimentacao\n"
        << "5. Exclui filial\n"
        << "6. Soma dos custos de movimentacao\n"
        << "0. Sair do menu\n\n"

        << "Escolha a opcao desejada: ";

    int opcao;
    cin >> opcao;

    return opcao;
}

int menuGame(void){
    system("cls");
    cout<< "\t\t\tMENU DE LOGISTICA\n\n"
        << "1. Inserir local\n"
        << "2. Inserir tempo\n"
        << "3. Lista de locais proximos\n" // (?)
        << "4. Atualizar o tempo\n"
        << "5. Exclui local\n"
        << "0. Sair do menu\n\n"

        << "Escolha a opcao desejada: ";

    int opcao;
    cin >> opcao;

    return opcao;
}

#endif