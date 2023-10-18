#include "ReadFileLugares.h"
#include <iostream>
#include <fstream>

using namespace std;

ReadFileLugares::ReadFileLugares(string& name) : name(name) {}

bool ReadFileLugares::read() {
    ifstream archivo(name);
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }
        archivo.close();
        return true; // Lectura exitosa
    }
    else {
        cout << "No se pudo abrir el archivo." << endl;
        return false; // Error al abrir el archivo
    }
}
