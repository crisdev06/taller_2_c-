#include<iostream>
#include "System.h"
using namespace std;

int main() {
    System system;
    int opc;
    do {
        system.Menu();
        cout << "Selecciona una opción: ";
        cin >> opc;

        switch (opc) {
        case 1:
            system.opcion1();
            break;
        case 2:
            system.opcion2();
            break;
        case 3:
            system.opcion3();
            break;
        case 4:
            system.opcion4();
            break;
        case 5:
            system.opcion5();
            break;
        case 6:
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "Opción no válida. Inténtalo de nuevo." << endl;
            break;
        }
    } while (opc != 6);

    return 0;
}
