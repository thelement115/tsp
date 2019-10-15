#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#include <utility> 

void printGraph(vector <vector<pair<double,double> > > adj);
bool contains (int x, vector<int> vec);
void mejorcamino(vector <vector<pair<double,double> > > grafo);
bool isdone(int n, vector<int> vec);
void mejorcamino(vector <vector<pair<double,double> > > grafo, pair<vector<int>,int> control, int nodoact, int distot, bool primera);
