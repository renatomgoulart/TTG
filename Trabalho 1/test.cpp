#include "libJogo.h"

int main(){
    float logistica[MAXTAM][MAXTAM], jogo[MAXTAM][MAXTAM];
    int filiais = 0, pontos = 0;
    string filiaisNomes[MAXTAM], filiaisPontos[MAXTAM];

    inicializaGrafo(logistica);

    insereFilial(filiaisNomes, filiais);
    
    insereFilial(filiaisNomes, filiais);

    insereMovimentacao(logistica, filiaisNomes, filiais);

    insereMovimentacao(logistica, filiaisNomes, filiais);
}