#ifndef LIBGRAPH_H
#define LIBGRAPH_H

#ifndef IOSTREAM
#include <iostream>
using namespace std;
#endif

#define MAXTAM 100

// General Graph Class
class Graph {
    protected: // ---------------------------------------------
        // vertices of the graph
        float connections[MAXTAM][MAXTAM];
        // number of inserted nodes
        int count;
        // names of the nodes
        string names[MAXTAM];

        // ----------------------------------------------------

        int deleteString(string aux){
            int position = index(aux);
            names[index(aux)] = "-1";
            return position;
        }

    public: // ------------------------------------------------
        // "starts" the variables (gives them 0 as value)
        void start(){
            int i, j;

            count = 0;

            for(i=0; i<MAXTAM; i++)
                for(j=0; j<MAXTAM; j++)
                    connections[i][j] = 0.0;
        }

        // search for the position of the string in the string array
        // Returns:
        // [0, count] -> if present
        // -1 -> if not present
        int index(string search){
            int i;
            for(i=0; i<count; i++){
                if(names[i] == search){
                    return i;
                }
            }
            return -1;
        }

        // insert aux in the string array
        // (!) aux must not be in array
        void insertString(string aux){
            if(index("-1") != -1){
                names[index("-1")] = aux;
                return;
            }

            names[count] = aux;
            count++;
        }

        // repeats insert until the string is inside names array
        bool rewindInsert(string &aux){
            string escolha;
            while(index(aux) == -1){
                cout<< "Erro: Nome nao encontrado\n"
                    << "      deseja digitar novamente (sim ou nao): ";
                cin >> escolha;
                if(escolha == "sim"){
                    cout<< "Digite o nome: ";
                    fflush(stdin);
                    getline(cin, aux, '\n');
                }
                else{
                    return false;
                }
            }
            return true;
        }

        // prints the strings inside the string array
        void printList(){
            if(count == 0){
                cout<< "Nenhum item inserido" <<endl;
            } else {
                int i;
                cout<<"\nItens inseridos:\n";
                for(i=0; i<count; i++){
                    if(names[i] != "-1")
                        cout<<" *    " << names[i] <<endl;
                } 
            }
            cout<< "\n";
        }

        float vertice(int index1, int index2){
            return connections[index1][index2];
        }

};

class NonDirectedGraph : public Graph {
    public: // ------------------------------------------------
        // insert a vertice
        // (!) overwrite previous moviment
        void insertMoviment(float aux, int index, int index2){
            connections[index][index2] = aux;
            connections[index2][index] = aux;
        }

        void print(int index){
            int i;
            for(i=0; i<count; i++){
                if(connections[index][i] > 0.0){
                    cout<< names[i] <<"\t"
                        << connections[index][i] <<"\n";
                }
            }
        }

        bool hasMoviment(int index1, int index2){ // correct some lines
            if(connections[index1][index2] > 0 && connections[index2][index1] > 0){
                return true;
            } else if(connections[index1][index2] != connections[index2][index1]){
                cout<< "ERROR: Graph desynchronized\n";
            }
            return false;
        }

        void deleteItem(string aux){
            int pos = deleteString(aux), i;

            for(i=0; i<count; i++){
                connections[pos][i] = -1;
                connections[i][pos] = -1;
            }
        }

        float sum(){
            float result = 0;
            int i, j;

            for(i=0; i<count; i++){
                for(j=0; j<i; j++){
                    if(connections[i][j] > 0){
                        result += connections[i][j];
                    }
                }
            }
            return result;
        }
};

class DirectedGraph : public Graph {
    public: // ------------------------------------------------
        // insert a vertice
        // (!) overwrite previous moviment
        void insertTime(float aux, int origin, int destination){
            connections[origin][destination] = aux; // (?)
        }

        bool hasTime(int index1, int index2){

        }
};


#endif