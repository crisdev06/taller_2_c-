#pragma once
#include <iostream>
using namespace std;

class AdyacencyMatrix {
public:
    AdyacencyMatrix(int numNodos); // Constructor
    ~AdyacencyMatrix(); // Destructor
    void addNode();
    void addEdge(int nodoOrigen, int nodoDestino, int weight);
    void deleteNode(int nodo);
    void deleteEdge(int nodo1,int nodo2 );
    bool existsEdge(int nodeOrigin, int nodeEnd);
    void dijkstra(int start);
    void floydWarshall();
    void printMatrix();
    

private:
    int numNodos;
    int** matrix;
    const int max = 26;

};
