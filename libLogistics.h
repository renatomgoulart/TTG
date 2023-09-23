#ifndef LIBLOGISTICS_H
#define LIBLOGISTICS_H

#ifndef IOSTREAM
#include <iostream>
using namespace std;
#endif

#include "libGraph.h"

void insereFilial(NonDirectedGraph &test){
    string auxiliar; 

    test.printList();

    cout<<"\nDigite o nome da filial a ser inserida: ";

    // fflush(stdin);
    cin.sync();
    getline(cin, auxiliar, '\n'); // https://www.geeksforgeeks.org/clearing-the-input-buffer-in-cc/
    // cin >> auxiliar;
    // cout<< auxiliar <<endl;

    if(test.index(auxiliar) == -1){
        test.insertString(auxiliar);
        cout<< " *    Nome inserido" <<endl;
    }
    else{
        cout<< "Erro: Nome ja inserido" <<endl;
    }

    system("pause");
}

void insereMovimentacao(NonDirectedGraph &test){
    string aux, aux2, escolha;
    float mov;

    test.printList();

    cout<<"\nDigite as filiais para inserir a movimentacao\n";
    cout<< "Filial 1: ";
    fflush(stdin);
    getline(cin, aux, '\n');
    // cin >> aux;
    if(!test.rewindInsert(aux))
        return;
    
    cout<< "Filial 2: ";
    fflush(stdin);
    getline(cin, aux2, '\n');
    // cin >> aux2;
    if(!test.rewindInsert(aux2))
        return;

    if(test.vertice(test.index(aux), test.index(aux2)) > 0.0){
        cout<< "Movimentacao ja existe, deseja atualizar?\n"
            << "Movimentacao atual: " << test.vertice(test.index(aux), test.index(aux2)) <<endl
            << "sim ou nao?\n"; 
        cin >> escolha;
        if(escolha == "sim"){
            cout<< "Digite a movimentacao: ";
            cin >> mov;
            test.insertMoviment(mov, test.index(aux), test.index(aux2));
            cout<< "Movimentacao inserida com sucesso\n";
        }
        else
            return;
    }
    else{
        cout<< "Digite a movimentacao: ";
        cin >> mov;
        test.insertMoviment(mov, test.index(aux), test.index(aux2));
        cout<< "Movimentacao inserida com sucesso\n";
    }
    system("pause");
}

void listaFiliaisProximas(NonDirectedGraph &test){
    string auxiliar;

    test.printList();

    cout<< "Digite o nome da filial a ser procurada:" <<endl;
    fflush(stdin);
    getline(cin, auxiliar, '\n');
    // cin >> auxiliar;
    if(!test.rewindInsert(auxiliar))
        return;

    cout<< "Lista de filiais proximas a "<< auxiliar <<":\n";
    test.print(test.index(auxiliar));

    system("pause");
}

void atualizaMovimentacao(NonDirectedGraph &test){
    string aux, aux2, escolha;
    float movimento;
    
    test.printList();

    cout<< "Digite o nome da primeira filial: ";
    fflush(stdin);
    getline(cin, aux, '\n');
    // cin >> aux;

    cout<< "Digite o nome da segunda filial: ";
    fflush(stdin);
    getline(cin, aux2, '\n');
    // cin >> aux2;

    cout<<"Digite uma movimentacao: ";
    cin >> movimento;

    // check se aux e aux2 estao presentes no arr
    // opcao para inserir os dois e a movimentacao
    if(test.index(aux) == -1 || test.index(aux2) == -1){
        cout<< "\n\nAlgumas filiais digitadas nao estao presentes\n"
            << "Deseja inseri-las na lista? (sim - nao)\n"
            << "Strings ausentes:\n";
        if(test.index(aux) == -1)
            cout<<" *   "<<aux<<endl;
        if(test.index(aux2) == -1)
            cout<<" *   "<<aux2<<endl;
        cin>>escolha;

        if(escolha == "sim"){
            if(test.index(aux) == -1)
                test.insertString(aux);
            if(test.index(aux2) == -1)
                test.insertString(aux2);
        }else{
            return;
        }
    }

    // se movimentacao n estiver presente
    if(!test.hasMoviment(test.index(aux), test.index(aux2))){
        cout<< "\nNao existe movimentacao entre as duas cidades"
            << "\nDeseja criar uma nova? (sim - nao)s\n";
        cin >> escolha;
        if(escolha == "sim"){
            test.insertMoviment(movimento, test.index(aux), test.index(aux2));
            cout<<"\t\t**Movimento Atualizado**"<<endl;
            system("pause");
            return;
        }else{
            return;
        }
    }

    // att movimentacao
    test.insertMoviment(movimento, test.index(aux), test.index(aux2));
    cout<<"\t\t**Movimento Atualizado**"<<endl;
    system("pause");
}

void removeFilial(NonDirectedGraph &test){
    string excluir;

    test.printList();

    cout<< "Digite a filial a ser excluida: ";
    fflush(stdin);
    getline(cin, excluir, '\n');
    // cin >> excluir;

    if(!test.rewindInsert(excluir))
        return;

    test.deleteItem(excluir);
    
    cout<< "Item excluido\n";
    system("pause");
}

float calculaCustoFiliais(NonDirectedGraph test){
    return test.sum();
}

#endif