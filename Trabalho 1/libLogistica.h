#include "libGeral.h"

bool repetirInserir(string arr[MAXTAM], int numFiliais, string &aux){
    string escolha;
    while(buscaString(arr, numFiliais, aux)){
        cout<< "Erro: Nome nao encontrado\n"
            << "      deseja digitar novamente (sim ou nao): ";
        cin >> escolha;
        if(escolha == "sim"){
            cout<< "Digite o nome: ";
            cin >> aux;
        }
        else{
            return false;
        }
    }
    return true;
}

// *******************************************************************************************

void insereFilial(string nomeFilial[MAXTAM], int &contadorFiliais){
    string auxiliar; 

    printStrings(nomeFilial, contadorFiliais);

    cout<<"\nDigite o nome da filial a ser inserida: ";
    cin >> auxiliar; // mudar para getline ?

    if(buscaString(nomeFilial, contadorFiliais, auxiliar)){
        insertString(nomeFilial, contadorFiliais, auxiliar);
        cout<< " *    Nome inserido" <<endl;
    }
    else{
        cout<< "Erro: Nome ja inserido" <<endl;
    }
    system("pause");
}

void insereMovimentacao(float log[MAXTAM][MAXTAM], string arr[MAXTAM], int &numFiliais){
    string aux, aux2, escolha;
    int index, index2;

    printStrings(arr, numFiliais);

    cout<<"\nDigite as filiais para inserir a movimentacao\n";
    cout<< "Filial 1: ";
    cin >> aux;
    if(!repetirInserir(arr, numFiliais, aux))
        return;
    
    cout<< "Filial 2: ";
    cin >> aux2;
    if(!repetirInserir(arr, numFiliais, aux2))
        return;

    index = buscaIndex(arr, numFiliais, aux);
    index2 = buscaIndex(arr, numFiliais, aux2);

    if(log[index][index2] != 0.0){
        cout<< "Movimentacao ja existe, deseja atualizar?\n"
            << "sim ou não?\n"; 
        cin >> escolha;
        if(escolha == "sim"){
            cout<< "Digite a movimentacao: ";
            cin >> log[index][index2];
            cout<< "Movimentacao inserida com sucesso\n";
        }
        else
            return;
    }
    else{
        cout<< "Digite a movimentacao: ";
        cin >> log[index][index2];
        log[index2][index] = log[index][index2];
        cout<< "Movimentacao inserida com sucesso\n";
    }
    system("pause");
}

void listaFiliaisProximas(string nomeFilial[MAXTAM], float log[MAXTAM][MAXTAM], int numFiliais){
    string auxiliar;
    int index, i;

    cout<< "Digite o nome da filial a ser procurada:" <<endl;
    cin >> auxiliar;
    if(!repetirInserir(nomeFilial, numFiliais, auxiliar))
        return;

    index = buscaIndex(nomeFilial, numFiliais, auxiliar);

    cout<< "Lista de filiais proximas a "<< nomeFilial[index] <<":\n";
    for(i=0; i<numFiliais; i++){
        if(log[index][i] > 0.0){
            cout<< nomeFilial[i] <<"\t"
                << log[index][i] <<"\n";
        }
    }

    system("pause");
}

void atualizaMovimentacao(string nomeFiliais[MAXTAM], int &contador, float log[MAXTAM][MAXTAM]){
    string aux, aux2, escolha;
    float movimento;
    
    printStrings(nomeFiliais, contador);

    cout<< "Digite o nome da primeira filial: ";
    cin >> aux;

    cout<< "Digite o nome da segunda filial: ";
    cin >> aux2;

    cout<<"Digite uma movimentacao: ";
    cin >> movimento;


    // check se aux e aux2 estao presentes no arr
    // opcao para inserir os dois e a movimentacao
    if(buscaString(nomeFiliais, contador, aux) || buscaString(nomeFiliais, contador, aux2)){
        cout<< "\n\nAlgumas filiais digitadas nao estao presentes\n"
            << "Deseja inseri-las na lista? (sim - nao)\n"
            << "Strings ausentes:\n";
        if(buscaString(nomeFiliais, contador, aux))
            cout<<" *   "<<aux<<endl;
        if (buscaString(nomeFiliais, contador, aux2))
            cout<<" *   "<<aux2<<endl;
        cin>>escolha;

        if(escolha == "sim"){
            if(buscaString(nomeFiliais, contador, aux))
                insertString(nomeFiliais, contador, aux);
            if (buscaString(nomeFiliais, contador, aux2))
                insertString(nomeFiliais, contador, aux2);
        }else{
            return;
        }
    }

    // se movimentacao n estiver presente
    if(log[buscaIndex(nomeFiliais, contador, aux)][buscaIndex(nomeFiliais, contador, aux2)] == 0.0){
        cout<< "\nNao existe movimentacao entre as duas cidades"
            << "\nDeseja criar uma nova? (sim - nao)s\n";
        cin >> escolha;
        if(escolha == "sim"){
            log[buscaIndex(nomeFiliais, contador, aux)][buscaIndex(nomeFiliais, contador, aux2)] = movimento;
            cout<<"\t\t**Movimento Atualizado**"<<endl;
            system("pause");
            return;
        }else{
            return;
        }
    }

    // att movimentacao
    log[buscaIndex(nomeFiliais, contador, aux)][buscaIndex(nomeFiliais, contador, aux2)] = movimento;
    log[buscaIndex(nomeFiliais, contador, aux2)][buscaIndex(nomeFiliais, contador, aux)] = movimento;
    cout<<"\t\t**Movimento Atualizado**"<<endl;
    system("pause");
}

void removeFilial(string nomeFiliais[MAXTAM], int &contador, float log[MAXTAM][MAXTAM]){
    string excluir;
    int aux;

    printStrings(nomeFiliais, contador);

    cout<< "Digite a filial a ser excluida: ";
    cin >> excluir;

    if(!repetirInserir(nomeFiliais, contador, excluir))
        return;

    aux = buscaIndex(nomeFiliais, contador, excluir);
    nomeFiliais[aux] = "-1";
    fillMatrix(log, -1, aux, contador);
    fillMatrix(log, aux, -1, contador);

}