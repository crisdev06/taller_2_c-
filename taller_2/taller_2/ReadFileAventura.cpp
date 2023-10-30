#include "ReadFileAventura.h"
#include "AdyacencyMatrix.h"
#include <iostream>
#include <fstream>
#include <cctype>
#include <list>
#include <stdexcept>
#include <string>
#include <vector>
#include <sstream> 

using namespace std;

ReadFileAventura::ReadFileAventura(string& name) : name(name) {}


string ReadFileAventura::trimCpp(const string& line) {
    std::string result;
    bool prevSpace = true; // Flag para indicar si el carácter anterior era un espacio en blanco

    for (char ch : line) {
        if (!isspace(ch)) {
            // Si el carácter no es un espacio en blanco, añadirlo a la subcadena resultante
            result.push_back(ch);
            prevSpace = false; // Resetear el flag
        }
        else {
            // Si el carácter es un espacio en blanco, añadirlo solo si el carácter anterior no fue un espacio en blanco
            if (!prevSpace) {
                result.push_back(ch);
            }
            prevSpace = true; // Establecer el flag
        }
    }

    return result;
}
list<AdyacencyMatrix> ReadFileAventura::read() {
    ifstream archivo(name);
    if (!archivo.is_open()) {
        throw runtime_error("No se pudo abrir el archivo.");
    }

    string line;
    list<AdyacencyMatrix> matrices; // Lista de matrices de adyacencia
    vector<string> nodos;
    vector<vector<int>> distancias;

    // Leer la primera línea que contiene los nombres de los nodos de destino
    if (getline(archivo, line)) {
        istringstream ss(trimCpp(line)); // Utilizar trimCpp para eliminar espacios en blanco
        string nodo;
        while (ss >> nodo) {
            nodos.push_back(nodo);
        }
    }
    else {
        throw runtime_error("El archivo está vacío o mal formateado.");
    }

    // Leer las líneas subsiguientes
    while (getline(archivo, line)) {
        istringstream ss(trimCpp(line)); // Utilizar trimCpp para eliminar espacios en blanco
        string origen;
        ss >> origen; // Leer el nodo de origen

        // Leer las distancias separadas por comas
        vector<int> distanciaNodo;
        int distancia;
        while (ss >> distancia) {
            distanciaNodo.push_back(distancia);
        }

        distancias.push_back(distanciaNodo);
    }

    archivo.close(); // Cerrar el archivo después de leerlo

    // Verificar que el número de nodos sea igual al número de distancias
    if (nodos.size() != distancias.size()) {
        throw runtime_error("El archivo tiene un formato incorrecto.");
    }

    // Ahora, puedes construir matrices de adyacencia y agregarlas a la lista
    try {
        for (size_t i = 0; i < nodos.size(); ++i) {
            AdyacencyMatrix matriz(nodos.size());
            for (size_t j = 0; j < nodos.size(); ++j) {
                if (j < distancias[i].size()) {
                    matriz.addEdge(i, j, distancias[i][j]);
                }
                else {
                    throw runtime_error("El archivo tiene un formato incorrecto. Faltan distancias.");
                }
            }
            matrices.push_back(matriz);
        }
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return matrices;
}
