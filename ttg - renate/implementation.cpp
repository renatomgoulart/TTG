#include "libGraph.h"
#include "libGeneral.h"
#include "libLogistics.h"
#include "libGame.h"

int main(){
    NonDirectedGraph logistica;
    DirectedGraph jogo;

    logistica.start();
    jogo.start();
    
    bool lmao = true;

    while(lmao){
        switch(menuPrincipal()){
            case 1:
                while(lmao){
                    switch(menuLogistica()){
                        case 1:
                            insereFilial(logistica);
                            break;
                        case 2:
                            insereMovimentacao(logistica);
                            break;
                        case 3:
                            listaFiliaisProximas(logistica);
                            break;
                        case 4:
                            atualizaMovimentacao(logistica); 
                            break;
                        case 5:
                            removeFilial(logistica);
                            break;
                        case 6:
                            cout<< "Custo de movimentacao: "<< calculaCustoFiliais(logistica)<<endl;
                            system("pause");
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