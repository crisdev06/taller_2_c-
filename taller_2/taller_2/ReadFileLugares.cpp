#include "ReadFileLugares.h"
#include <iostream>
#include <fstream>
#include <stdexcept> 
#include "Place.h"


using namespace std;

ReadFileLugares::ReadFileLugares(string& name) : name(name) {}

list<Place> ReadFileLugares::read() {
    ifstream archivo(name);
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            size_t pos = linea.find(",");
            size_t pos2 = linea.find(",", pos + 1);
            string nameNode = linea.substr(0,pos);
            string name = linea.substr(pos + 1, pos2 - pos - 1);
            
           
            string stateString = linea.substr(pos2 + 1);

            if (stateString=="Estable")
            {
                bool state = true;
                Place p = Place(nameNode, name, state);
                continue;

            }           
            bool state = false;
            Place p = Place(nameNode, name, state);
            places.push_back(p);

        }
        archivo.close();
        return places; // Lectura exitosa
    }
    else {
        throw std::runtime_error("No se pudo abrir el archivo.");
        
        
    }
}
