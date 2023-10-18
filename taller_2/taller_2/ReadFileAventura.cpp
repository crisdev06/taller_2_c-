#include "ReadFileAventura.h"
#include <iostream>
#include <fstream>

using namespace std;

ReadFileAventura::ReadFileAventura(string& name) : name(name) {}

bool ReadFileAventura::read() {
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
