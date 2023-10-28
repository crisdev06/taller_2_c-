#include "AdyacencyMatrix.h"
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;


AdyacencyMatrix::AdyacencyMatrix(int numNodos) : numNodos(numNodos){




    matrix = (int**)malloc(numNodos * sizeof(int*));
    for (int i = 0; i < numNodos; ++i) {
        matrix[i] = (int*)malloc(numNodos * sizeof(int));
        for (int j = 0; j < numNodos; ++j) {
            matrix[i][j] = 0;
        }
    }
    
}

AdyacencyMatrix::~AdyacencyMatrix() {

    for (int i = 0; i < numNodos; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

void AdyacencyMatrix::addEdge(int nodeOrigen, int nodeDestino) {


    
}

void AdyacencyMatrix::delteEdge(int node1, int node2) {


}


void AdyacencyMatrix::delteNode(int node) {

    if (node>= 0) {
        free(matrix[node]);
    }
    for (int i = 0; i < numNodos- 1; i++) {
        matrix[i] = matrix[i + 1];
    }

    free(matrix[numNodos - 1]);

    numNodos--;
    numNodos -= numNodos;

    matrix = (int**)realloc(matrix, numNodos * sizeof(int));
    for (int i = 0; i < numNodos; i++) {
        matrix[i] = (int*)realloc(matrix[i], numNodos * sizeof(int));
    }

}

bool AdyacencyMatrix::existsEdge() {

}

void AdyacencyMatrix::printMatrix() {

    for (int i = 0; i < 26; i++) {
        for (int j = 0;j<26;j++) {
            cout << matrix[i][j] << "";
        }
    }
}



void AdyacencyMatrix::dijkstra(int start) {
    //todo: 
    /*vector<int> distancia(numNodos, INT_MAX);
    distancia[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int nodoActual = pq.top().second;
        int pesoActual = pq.top().first;
        pq.pop();

        for (const Arista& arista : listaAdyacencia[nodoActual]) { 
            int nodoDestino = arista.destino;
            int pesoArista = arista.peso;

            if (pesoActual + pesoArista < distancia[nodoDestino]) {
                distancia[nodoDestino] = pesoActual + pesoArista;
                pq.push(make_pair(distancia[nodoDestino], nodoDestino));
            }
        }
    }

    // Imprimir las distancias desde el nodo origen a todos los nodos
    cout << "Distancias desde el nodo " << nodoOrigen << ":\n";
    for (int i = 0; i < numNodos; ++i) {
        cout << "Nodo " << i << ": " << distancia[i] << "\n";
    }*/

}

void AdyacencyMatrix::floydWarshall() {
/*void floydWarshall(vector<vector<int>>& grafo, int numVertices) {
    // Matriz de distancias m�s cortas
    vector<vector<int>> distancia(numVertices, vector<int>(numVertices, INF));

    // Inicializar la diagonal con ceros
    for (int i = 0; i < numVertices; ++i) {
        distancia[i][i] = 0;
    }

    // Inicializar la matriz de distancias con los valores del grafo
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            if (grafo[i][j] != 0) {
                distancia[i][j] = grafo[i][j];
            }
        }
    }

    // Calcular las distancias m�s cortas
    for (int k = 0; k < numVertices; ++k) {
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                // Si el v�rtice k mejora el camino de i a j, actualizar la distancia
                if (distancia[i][k] != INF && distancia[k][j] != INF && distancia[i][k] + distancia[k][j] < distancia[i][j]) {
                    distancia[i][j] = distancia[i][k] + distancia[k][j];
                }
            }
        }
    }

    // Imprimir las distancias m�s cortas
    cout << "Matriz de distancias m�s cortas:" << endl;
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            if (distancia[i][j] == INF) {
                cout << "INF\t";
            } else {
                cout << distancia[i][j] << "\t";
            }
        }
        cout << endl;
    }
}*/

}
