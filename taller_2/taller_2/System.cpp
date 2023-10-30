#include "System.h"
#include "ReadFileLugares.h"
#include "ReadFileAventura.h"
#include "AdyacencyMatrix.h"
#include "Place.h"
#include <iostream>
#include<List>

using namespace std;

string nameA= "Aventura.txt";
string nameL= "lugares.txt";
ReadFileLugares readFileP(nameL);
ReadFileAventura readFileA(nameA);
list<Place> places = readFileP.read();
list<AdyacencyMatrix> matrix = readFileA.read();
AdyacencyMatrix adyMatrix = matrix.front();





void System::opcion1()
{
    int nodeOrigin;
    cout << "Ingrese el origen:";
    cin >> nodeOrigin;
    adyMatrix.dijkstra(nodeOrigin);
}

void System::opcion2()
{
    adyMatrix.floydWarshall();
}

void System::opcion3()
{
    int opc;
    do {
        cout << "1. Agregar Nodo." << endl;
        cout << "2. Agregar Arista." << endl;
        cout << "3. Salir." << endl;
        cout << "Selecciona una opción: ";
        cin >> opc;

        switch (opc) {
        case 1:
            cout << "Se agrego un nuevo nodo.";
            adyMatrix.addNode();
            break;
        case 2:

            cout << "Ingrese el nodo de inicio y el de fin: ";
            int nodeOrigin ;
            cout << "Origen (1,2,3,4,5,6): ";
            cin >> nodeOrigin;
            int nodeEnd;
            cout << "Fin (1,2,3,4,5,6): ";
            cin >> nodeEnd;
            int weight;
            cout << "Ingrese el peso de la arista: ";
            cin >> weight;
            adyMatrix.addEdge(nodeOrigin-1,nodeEnd-1, weight);

            break;
        case 3:
            cout << "Volviendo al menu principal";
            break;
        default:
            cout << "Opción no válida. Inténtalo de nuevo." << endl;
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
        cout << "Selecciona una opción: ";
        cin >> opc;

        switch (opc) {
        case 1:
            int node;
            cout << "que nodo desea eliminar?";
            cin >> node;
            if (node>0 && node <26) {
                adyMatrix.deleteNode(node);
            }
            else {
                cout << "ingrese un valor correcto.";
            }
            
            break;
        case 2:
            cout << "que arista desea eliminar?";
            int node1;
            cout << "nodo 1:";
            cin >> node1;
            int node2;
            cout << "nodo 2:";
            cin >> node2;

            adyMatrix.deleteEdge(node1, node2);
            break;
        case 3:
            cout << "Volviendo al menu principal";
            break;
        default:
            cout << "Opción no válida. Inténtalo de nuevo." << endl;
            break;
        }
    } while (opc != 3);
}

void System::opcion5()
{
    adyMatrix.printMatrix();
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
        cout << "Selecciona una opción: ";
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
            cout << "Adios..." << endl;
            break;
        default:
            cout << "Opción no válida. Inténtalo de nuevo." << endl;
            break;
        }
    } while (opc != 6);
}

