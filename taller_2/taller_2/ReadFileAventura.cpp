#include "ReadFileAventura.h"
#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

ReadFileAventura::ReadFileAventura(string& name) : name(name) {}

string ReadFileAventura::trimCpp(const string& line) {

    std::string result = line;
    size_t start = 0, end = result.length() - 1;

    // Eliminar espacios en blanco al principio de la cadena
    while (start <= end && std::isspace(result[start])) {
        ++start;
    }
    // Eliminar espacios en blanco al final de la cadena
    while (end >= start && std::isspace(result[end])) {
        --end;
    }
    // Extraer la subcadena sin espacios en blanco
    return result.substr(start, end - start + 1);
}


bool ReadFileAventura::read() {
    ifstream archivo(name);
    if (archivo.is_open()) {
        string linea;
        

        while (getline(archivo, linea)) {
            string lineWithoutSpace = trimCpp(linea);

        }
        archivo.close();
        return true; // Lectura exitosa
    }
    else {
        cout << "No se pudo abrir el archivo." << endl;
        return false; // Error al abrir el archivo
    }
}



