#include "libJogo.h"

int main(){
    float logistica[MAXTAM][MAXTAM], jogo[MAXTAM][MAXTAM];
    int filiais = 0, pontos = 0;
    string filiaisNomes[MAXTAM], filiaisPontos[MAXTAM];

    inicializaGrafo(logistica);
    inicializaGrafo(jogo);

    switch(menuPrincipal()){
        case 1:
            
            break;
        case 2:
            
            break;
        default:
            return 0;
    }

}