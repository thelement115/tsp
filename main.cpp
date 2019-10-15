#include "main.h"
#include <iostream>
#include "leer.h"
#include <fstream>
#include <vector>
#include <utility> 
#include <ctime>
using namespace std;

vector <pair<vector<int>,int> > vect;

int main(){
    unsigned t0, t1;
    vector <vector<pair<double,double> > > grafo;
    leer(grafo);
    vector<int> visitados;
    pair<vector<int>,int> control;
    control.first = visitados;
    control.second = 0;
    //printGraph(grafo);
    t0=clock();
    mejorcamino(grafo,control,-1,0,true);
    t1=clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << vect.size() << endl;
    cout << time << endl;
    return 0;
}

void mejorcamino(vector <vector<pair<double,double> > > grafo, pair<vector<int>,int> control, int nodoact, int distot, bool primera){
    //cout << "nodoact: " << nodoact << endl;
    vector <int> visitados = control.first;
    control.second = control.second + distot;
    visitados.push_back(nodoact);
    control.first = visitados;
    if(isdone(grafo.size(), visitados)){
        vect.push_back(control);
        //cout << "retorno" << endl;
        return;
    }else{
        if(primera){ 
//pragma omp parallel for 
            for(int i=0; i < grafo.size(); ++i){
                mejorcamino(grafo,control,i,0,false);
            }
        }else{
            vector <pair<double,double> > nodo = grafo.at(nodoact);
            for(int i = 0; i < nodo.size(); ++i){
                if(!contains(i,visitados) && nodoact!=i){
                    //cout << "se fue al nodo: " << i << endl;
                    int distancia = nodo.at(i).first;
                    mejorcamino(grafo,control,i,distancia,false);
                }
            }
        }
    }
    return;
}

bool isdone(int n, vector<int> vec){
    return n == (vec.size()-1);
}

bool contains (int x, vector<int> vec){
    for(int i = 1; i < vec.size(); i++){
        if(x == vec.at(i)){
            return true;
        }
    }
    return false;
}


void printGraph(vector <vector<pair<double,double> > > adj) 
{ 
    for (int v = 0; v < adj.size(); ++v) 
    { 
        vector <pair<double,double> > aux = adj.at(v);
        cout << "\n Adjacency list of vertex "
             << v << "\n head "; 
        for (int i = 0; i <aux.size(); i++ ){
            pair <int,int> alv = aux.at(i);
            cout << "numeros:"
            << alv.first
            << "con peso"
            << alv.second << endl;
        } 
        printf("\n"); 
    } 
}  
