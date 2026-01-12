#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <limits>

using namespace std;

int pedirOpcion(int min, int max) {
    int opcion;
    while (true) {
        cout << "Seleccione una opcion: ";
        if (cin >> opcion) {
            if (opcion >= min && opcion <= max) {
                return opcion;
            } else {
                cout << "Opcion fuera de rango." << endl;
            }
        } else {
            cout << "Entrada invalida." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

#endif