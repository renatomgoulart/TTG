#ifndef LIBGAME_H
#define LIBGAME_H

#ifndef IOSTREAM
#include <iostream>
using namespace std;
#endif

#include "libGraph.h"

void insereLocalJogo(DirectedGraph &grafo){
    string aux;

    grafo.printList();

    cout<<"\nDigite o nome do local que deseja inserir: ";

    cin.sync();
    getline(cin, aux, '\n');

    if(grafo.index(aux) == -1){
        grafo.insertString(aux);
        cout<< "*   Local inserido"<<endl;
    }
    else{
        cout<<"Erro este local ja foi inserido"<<endl;
    }
    system("pause");
}

void insereTempo(DirectedGraph &grafo){
    string aux, aux2, escolha;
    float time;

    grafo.printList();

    cout<<"\nDigite os locais para inserir o tempo\n";
    
    cout<<"Local 1: ";
    fflush(stdin);
    getline(cin, aux, '\n');

    if(!grafo.rewindInsert(aux))
        return;

    cout<<"Local 2: ";
    fflush(stdin);
    getline(cin, aux2, '\n');

    if(!grafo.rewindInsert(aux2))
        return;

    if(grafo.vertice(grafo.index(aux), grafo.index(aux2)) > 0.0){
        cout<<"Tempo ja existe, deseja atualizar?\n"
            <<"tempo atual: "<<grafo.vertice(grafo.index(aux), grafo.index(aux2))<<endl
            <<"sim ou nao?\n";
            cin >> escolha;
            if(escolha == "sim"){
                cout<<"Digite o tempo: ";
                cin >> time;
                grafo.insertTime(time, grafo.index(aux), grafo.index(aux2));
                cout<<"Tempo inserido com sucesso\n";
            }
            else
                return;
    }
    else{
        cout<<"Digite o tempo: ";
        cin >> time;
        grafo.insertTime(time, grafo.index(aux), grafo.index(aux2));
        cout<< "Tempo inserido com sucesso\n";
    }
    system("pause");
}

void listaLocaisDestino(){

}

void listaLocaisOrigem(){

}

//n sei se deu bom pois existe uma funcao chamada hasMoviment que nao sei qual devo substituir no jogo
void atualizaTempo(DirectedGraph &grafo){
    string aux, aux2, escolha;
    float time;

    grafo.printList();

    cout<<"Digite o primeiro local: ";
    fflush(stdin);
    getline(cin, aux, '\n');

    cout<< "Digite o segundo local: ";
    fflush(stdin);
    getline(cin, aux2, '\n');

    cout<<"Digite o tempo: ";
    cin >> time;

    if(grafo.index(aux) == -1 || grafo.index(aux2) == -1){
        cout<< "\n\nAlguns locais nao estao presentes\n"
            <<"Deseja inserir-los na lista? (sim-nao)\n";
        if(grafo.index(aux) == -1)
            cout<<" *  "<<aux<<endl;
        if(grafo.index(aux2) == -1)
            cout<<" *  "<<aux<<endl;
        cin>>escolha;

    if(escolha == "sim"){
        if(grafo.index(aux) == -1)
            grafo.insertString(aux);
        if(grafo.index(aux2) == -1)
            grafo.insertString(aux2);
    }else{
        return;
    }
//linha abaixo|
//            V
    if(!grafo.(grafo.index(aux(aux), grafo.index(aux2))){
        cout<< "\nNao existe tempo registrado entre os dois locais"
            << "\nDeseja criar um novo? (sim - nao)s\n";
        cin >> escolha;
        if(escolha == "sim"){
            grafo.insertTime(tempo, grafo.index(aux), grafo.index(aux2));
            cout<<"\t\t**Tempo Atualizado**"<<endl;
            system("pause");
            return;
        }else{
            return;
        }
    grafo.insertTime(time, grafo.index(aux), grafo.index(aux2));
    cout<<"\t\t**Tempo Atualizado**"<<endl;
    system("pause");    

}

void removeLocal(DirectedGraph &grafo){
    string excluir;

    grafo.printList();

    cout<< "Digite o local a ser excluida: ";
    fflush(stdin);
    getline(cin, excluir, '\n');
    // cin >> excluir;

    if(!grafo.rewindInsert(excluir))
        return;

    grafo.deleteItem(excluir);
    
    cout<< "Item excluido\n";
    system("pause");

}

void calculaTemposLocais(DirectedGraph &grafo){
     return grafo.sum();
}

#endif