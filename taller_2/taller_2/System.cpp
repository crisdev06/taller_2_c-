#include "System.h"
#include "ReadFileLugares.h"
#include "ReadFileAventura.h"
#include "AdyacencyMatrix.h"
#include "Place.h"
#include <iostream>
#include<List>

using namespace std;

string name;
ReadFileLugares readFileP(name);
ReadFileAventura readFileA(name);
list<Place> places = readFileP.read();
list<AdyacencyMatrix> matrix = readFileA.read();
AdyacencyMatrix adyMatrix = matrix.front();



void System::opcion1()
{
    cout << "estoy en la opcion 1" << endl;
}

void System::opcion2()
{
    cout << "estoy en la opcion 2" << endl;
}

void System::opcion3()
{
    int opc;
    do {
        cout << "1. Agregar Nodo." << endl;
        cout << "2. Agregar Arista." << endl;
        cout << "3. Salir." << endl;
        cout << "Selecciona una opci�n: ";
        cin >> opc;

        switch (opc) {
        case 1:
            adyMatrix.addNode();
            break;
        case 2:
            int nodeOrigin;
            int nodeEnd;
            adyMatrix.addEdge(nodeOrigin,nodeEnd);
            break;
        case 3:
            cout << "Volviendo al menu principal";
            break;
        default:
            cout << "Opci�n no v�lida. Int�ntalo de nuevo." << endl;
            break;
        }
    } while (opc != 3);
}

void System::opcion4()
{
    int opc;
    do {
        cout << "1. Eliminar Nodo." << endl;
        cout << "2. Eliminar Arista." << endl;
        cout << "3. Salir." << endl;
        cout << "Selecciona una opci�n: ";
        cin >> opc;

        switch (opc) {
        case 1:
            int node;
            adyMatrix.delteNode(node);
            break;
        case 2:
            int node1;
            int node2;           
            adyMatrix.delteEdge(node1, node2);
            break;
        case 3:
            cout << "Volviendo al menu principal";
            break;
        default:
            cout << "Opci�n no v�lida. Int�ntalo de nuevo." << endl;
            break;
        }
    } while (opc != 3);
}

void System::opcion5()
{
    cout << "estoy en la opcion 5" << endl;
}

void System::opcion6()
{
    cout << "estoy en la opcion 6 " << endl;
}

void System::Menu() {
    cout << "1. Calcular ruta minima." << endl;
    cout << "2. Conocer una ruta de emergencia." << endl;
    cout << "3. Agregar" << endl;
    cout << "4. Eliminar" << endl;
    cout << "5. Visualizar el grafo" << endl;
    cout << "6. Salir" << endl;
    int opc;
    do {
        cout << "Selecciona una opci�n: ";
        cin >> opc;

        switch (opc) {
        case 1:
            opcion1();
            break;
        case 2:
            opcion2();
            break;
        case 3:
            opcion3();
            break;
        case 4:
            opcion4();
            break;
        case 5:
            opcion5();
            break;
        case 6:
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "Opci�n no v�lida. Int�ntalo de nuevo." << endl;
            break;
        }
    } while (opc != 6);
}

