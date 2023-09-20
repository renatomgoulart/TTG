#include "libJogo.h"

int main(){
    float logistica[MAXTAM][MAXTAM], jogo[MAXTAM][MAXTAM];
    int filiais = 0, pontos = 0;
    string filiaisNomes[MAXTAM], filiaisPontos[MAXTAM];

    inicializaGrafo(logistica);
    inicializaGrafo(jogo);

    bool lmao = true;

    while(lmao){
        switch(menuPrincipal()){
            case 1:
                while(lmao){
                    switch(menuLogistica()){
                        case 1:
                            insereFilial(filiaisNomes, filiais);
                            break;
                        case 2:
                            insereMovimentacao(logistica, filiaisNomes, filiais);
                            break;
                        case 3:
                            listaFiliaisProximas(filiaisNomes, logistica,filiais);
                            break;
                        case 4:
                            atualizaMovimentacao(filiaisNomes, filiais, logistica); 
                            break;
                        case 5:
                            removeFilial(filiaisNomes, filiais, logistica);
                            break;
                        default:
                            lmao = true;
                    }
                    break;
                }
                
                break;
            case 2:
                
                break;
            default:
                return 0;
        }
    }
    

}