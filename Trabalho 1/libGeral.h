#include <iostream>
#include <string>
#include <cstdlib>

#define MAXTAM 100

using namespace std;

// Menu -------------------------------------------------------

int menuPrincipal(void){ // funcionando
    system("cls");
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
    system("cls");
    printf("\t\t\tMENU DE LOGISTICA\n\n");
    printf("1. Inserir filial\n");
    printf("2. Inserir movimentacao\n");
    printf("3. Lista de filial proximas\n");
    printf("4. Atualizar a movimentacao\n");
    printf("5. Exclui filial\n");
    printf("0. Sair do menu\n\n");

    printf("Escolha a opcao desejada: ");
    int opcao;
    cin >> opcao;
    return opcao;
}

// Grafo ------------------------------------------------------

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

// Strings ----------------------------------------------------

// returna:
// True = nao estiver presente
// False = estiver presente
bool buscaString(string arr[MAXTAM], int &counter, string search){
    int i;

    for( i=0; i<counter; i++){
        if(arr[i] == search){
            return false;
        }
    }
    return true;
}

void printStrings(string arr[MAXTAM], int numFiliais){
    if(numFiliais == 0){
        cout<< "Nenhum item inserido" <<endl;
    } else {
        int i;
        cout<<"\nItens inseridas:\n";
        for(i=0; i<numFiliais; i++){
            if(arr[i] != "-1")
                cout<<" *    " << arr[i] <<endl;
        } 
    }
    cout<< "\n";
}

// retorna index da string
int buscaIndex(string arr[MAXTAM], int counter, string search){
    int i;
    for(i=0; i<counter; i++){
        if(arr[i] == search){
            return i;
        }
    }
    return -1;
}

// insere uma string em um arr
// (!) aux nao pode estar no arr
void insertString(string arr[MAXTAM], int &counter, string aux){
    int i;

    for(i=0; i<counter; i++){
        if(arr[i] == "-1"){
            arr[i] == aux;
            return;
        }
    }

    arr[counter] = aux;
    counter++; 
}

void fillMatrix(float mat[MAXTAM][MAXTAM], int x, int y, int counter){
    int i;
    if(x == -1){
        for(i=0; i< counter; i++){
            mat[i][y] = -1.0; // tbo
        }
    }
    if(y == -1){
        for(i=0; i< counter; i++){
            mat[x][i] = -1.0;
        }
    }
}