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

void AdyacencyMatrix::addNode() {
    int newNumNodos = numNodos + 1;

    // Reasignar memoria para la nueva fila y columna
    matrix = (int**)realloc(matrix, newNumNodos * sizeof(int*));
    for (int i = 0; i < newNumNodos; ++i) {
        matrix[i] = (int*)realloc(matrix[i], newNumNodos * sizeof(int));
    }

    // Inicializar las nuevas conexiones a 0
    for (int i = 0; i < newNumNodos; ++i) {
        matrix[i][newNumNodos - 1] = 0;
        matrix[newNumNodos - 1][i] = 0;
    }

    numNodos = newNumNodos;
    std::cout << "Nodo agregado. Total de nodos ahora: " << numNodos << std::endl;
}


AdyacencyMatrix::~AdyacencyMatrix() {

    for (int i = 0; i < numNodos; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}



void AdyacencyMatrix::addEdge(int nodoOrigin, int nodoEnd, int weight) {
   
    if (nodoOrigin >= 0 && nodoOrigin < numNodos && nodoEnd >= 0 && nodoEnd < numNodos && weight > 0) {
        matrix[nodoOrigin][nodoEnd] = weight;
        std::cout << "Arista agregada entre los nodos " << nodoOrigin << " y " << nodoEnd << " con peso " << weight << std::endl;
    }
    else {
        std::cout << "No se pudo agregar la arista. Nodos inválidos o peso no válido." << std::endl;
    }
}

void AdyacencyMatrix::deleteEdge(int node1, int node2) {
    if (node1 >= 0 && node1 < numNodos && node2 >= 0 && node2 < numNodos && matrix[node1][node2] > 0) {
        matrix[node1][node2] = 0;
        std::cout << "Arista eliminada entre los nodos " << node1 << " y " << node2 << std::endl;
    }
    else {
        std::cout << "No se pudo eliminar la arista. Nodos inválidos o arista no existente." << std::endl;
    }

}


void AdyacencyMatrix::deleteNode(int node) {

    if (node >= 0 && node < numNodos) {
        free(matrix[node]);

        // Reorganizar la matriz
        for (int i = node; i < numNodos - 1; ++i) {
            matrix[i] = matrix[i + 1];
        }

        numNodos--;
        matrix = (int**)realloc(matrix, numNodos * sizeof(int*));
    }
    else {
        std::cout << "No se pudo eliminar el nodo. Nodo inválido." << std::endl;
    }

}

bool AdyacencyMatrix::existsEdge(int nodeOrigin, int nodeEnd) {
    if (nodeOrigin >= 0 && nodeOrigin < numNodos && nodeEnd >= 0 && nodeEnd < numNodos) {
        return matrix[nodeOrigin][nodeEnd] != 0;
    }
    else {
        std::cout << "Nodos inválidos." << std::endl;
        return false;
    }
}

void AdyacencyMatrix::printMatrix() {

    for (int i = 0; i < numNodos; ++i) {
        for (int j = 0; j < numNodos; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}



void AdyacencyMatrix::dijkstra(int start) {

    std::vector<int> distancia(numNodos, INT_MAX);
    distancia[start] = 0;

    std::vector<bool> visitado(numNodos, false);

    for (int count = 0; count < numNodos - 1; ++count) {
        int nodoActual = -1;
        for (int i = 0; i < numNodos; ++i) {
            if (!visitado[i] && (nodoActual == -1 || distancia[i] < distancia[nodoActual])) {
                nodoActual = i;
            }
        }

        if (distancia[nodoActual] == INT_MAX) {
            // El nodo actual no está conectado con otros nodos
            break;
        }

        visitado[nodoActual] = true;

        for (int i = 0; i < numNodos; ++i) {
            if (!visitado[i] && matrix[nodoActual][i] != 0 && distancia[nodoActual] + matrix[nodoActual][i] < distancia[i]) {
                distancia[i] = distancia[nodoActual] + matrix[nodoActual][i];
            }
        }
    }

    // Imprimir las distancias desde el nodo de inicio a todos los nodos
    std::cout << "Distancias desde el nodo " << start << ":\n";
    for (int i = 0; i < numNodos; ++i) {
        std::cout << "Nodo " << i << ": " << distancia[i] << "\n";
    }
}

void AdyacencyMatrix::floydWarshall() {
    // Inicializar la matriz de distancias con los valores de la matriz de adyacencia
    std::vector<std::vector<int>> distancia(numNodos, std::vector<int>(numNodos));
    for (int i = 0; i < numNodos; ++i) {
        for (int j = 0; j < numNodos; ++j) {
            distancia[i][j] = matrix[i][j];
        }
    }

    // Calcular las distancias mínimas utilizando el algoritmo de Floyd-Warshall
    for (int k = 0; k < numNodos; ++k) {
        for (int i = 0; i < numNodos; ++i) {
            for (int j = 0; j < numNodos; ++j) {
                // Si el nodo k mejora el camino de i a j, actualizar la distancia
                if (distancia[i][k] != 0 && distancia[k][j] != 0 &&
                    (distancia[i][j] == 0 || distancia[i][k] + distancia[k][j] < distancia[i][j])) {
                    distancia[i][j] = distancia[i][k] + distancia[k][j];
                }
            }
        }
    }

    // Imprimir las distancias mínimas
    std::cout << "Matriz de distancias mínimas (Floyd-Warshall):\n";
    for (int i = 0; i < numNodos; ++i) {
        for (int j = 0; j < numNodos; ++j) {
            std::cout << distancia[i][j] << "\t";
        }
        std::cout << std::endl;
    }

}
