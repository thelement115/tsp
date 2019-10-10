#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>

using namespace std;

void leer(vector <vector<pair<double,double>>> &grafo);
void addEdge(vector <vector<pair<double,double>>> &grafo, int u, double v);
vector <vector<pair<double,double>>> llenar(vector <vector<pair<double,double>>> adj, int V);
vector<pair<double,double>> leeraux(ifstream &fe);
void llenargrafo(vector <vector<pair<double,double>>> &grafo, vector<pair<double,double>> nodos);