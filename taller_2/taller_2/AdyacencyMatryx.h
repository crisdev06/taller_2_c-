#pragma once
#include <iostream>
using namespace std;

class AdyacencyMatrix {
public:
    AdyacencyMatrix(int numNodos); // Constructor
    ~AdyacencyMatrix(); // Destructor
    void minRout();
    void emergencyRout();

    void addNode(int nodoOrigen, int nodoDestino);
    void addEdge(int nodoOrigen, int nodoDestino);
    void delteNode(int nodoOrigen, int nodoDestino);
    void delteEdge(int nodoOrigen, int nodoDestino);
    bool existsEdge(int nodoOrigen, int nodoDestino);
    void dijkstra(int start);
    void floydWarshall();
    void printMatrix();

private:
    int numNodos;
    int** matrix;
    const int max = 26;

};
