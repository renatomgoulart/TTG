#include "libGeral.h"

bool buscaString(string nomeFilial[MAXTAM], int &contadorFiliais){
    
}

void insereFilial(string nomeFilial[MAXTAM], int &contadorFiliais){
    int i;
    string auxiliar; 
    bool inserido = false;

    while(!inserido){
        printf("Digite o nome da filial: ");
        getline(cin, auxiliar);

    for(i=0; i < contadorFiliais; i++){
        if( auxiliar == contadorFiliais){
            printf("Erro: Nome já inserido\n");
        }
    }  
    }



    
}