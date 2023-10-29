#pragma once
#include <iostream>
using namespace std;

class AdyacencyMatrix {
public:
    AdyacencyMatrix(int numNodos); // Constructor
    ~AdyacencyMatrix(); // Destructor
    void minRout();
    void emergencyRout();
    void addNode();
    void addEdge(int nodoOrigen, int nodoDestino);
    void delteNode(int nodo);
    void delteEdge(int nodo1,int nodo2 );
    bool existsEdge();
    void dijkstra(int start);
    void floydWarshall();
    void printMatrix();
    

private:
    int numNodos;
    int** matrix;
    const int max = 26;

};
