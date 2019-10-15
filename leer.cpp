#include <iostream>
#include <fstream>
#include "leer.h"
#include <vector>
#include <utility> 
#include <string>
#include <stdlib.h>
#include <math.h>
using namespace std;

void leer(vector <vector<pair<double,double> > > &grafo){
    char cadena[128];
    vector <pair<double,double> > nodos;
    int n;
    ifstream fe("tc2c320s24cf0.txt");
    fe.getline(cadena, 128);
    string x = cadena;
    // obtengo la cantidad de nodos
    x = x.substr(4,6);
    n = atoi(x.c_str());
    nodos = leeraux(fe);
    // lleno el grafo con los nodos
    grafo = llenar(grafo,n);
    llenargrafo(grafo,nodos);
    fe.close();
}

void llenargrafo(vector <vector<pair<double,double> > > &grafo, vector<pair<double,double> > nodos){
    for(int i = 0; i < grafo.size(); ++i){
        pair <double,double> nodo1 = nodos.at(i);
        int x1 = nodo1.first;
        int y1 = nodo1.second;
        for(int j =0; j< nodos.size(); j++){
            pair<double,double> nodo2 = nodos.at(j);
            double x2 = nodo2.first;
            double y2 = nodo2.second;
            double x = x2-x1;
            double y = y2-y1;
            double distancia = sqrt((x*x)+(y*y));
            pair<double,double> nodofinal;
            nodofinal.first = j;
            nodofinal.second = distancia;
            grafo.at(i).push_back(nodofinal);
        }
    }
}

vector<pair<double,double> > leeraux(ifstream &fe){
    string lectura;
    vector<pair<double,double> > nodos;
    double objetivo,peso;
    fe >> lectura;
    while(!fe.eof()){
        fe >> lectura;
        fe >> lectura;
        double x = atof(lectura.c_str());
        fe >> lectura;
        double y = atof(lectura.c_str());
        fe >> lectura;
        fe >> lectura;
        pair <double,double> aux;
        aux.first = x;
        aux.second = y;
        nodos.push_back(aux);
    }
    return nodos;
}

void addEdge(vector <vector<pair<double,double> > > &grafo, int u, double v) { 
    pair <int,int> newedge;
    newedge.first = v;
    newedge.second = 5;
    grafo.at(u).push_back(newedge);
}


vector <vector<pair<double,double> > > llenar(vector <vector<pair<double,double> > > adj, int V){
    vector<pair<double,double> > nuevo;
    for(short i= 0; i < V ; ++i){
        adj.push_back(nuevo);
    }
    return adj;
}
