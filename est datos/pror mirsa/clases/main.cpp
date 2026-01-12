#include <iostream>
#include <cstdlib>
#include "utils.h"
#include "unidad1.h"
#include "unidad2.h"
#include "unidad3.h"

using namespace std;

int main() {
    unidad1 u1;
    unidad2 u2;
    Unidad3 u3;
    int opcion;

    do {
        system("cls");
        cout << "========================================" << endl;
        cout << "        SISTEMA DE PRACTICAS CPP        " << endl;
        cout << "========================================" << endl;
        cout << "1. Unidad 1" << endl;
        cout << "2. Unidad 2" << endl;
        cout << "3. Unidad 3" << endl;
        cout << "0. Salir" << endl;
        cout << "========================================" << endl;

        opcion = pedirOpcion(0, 3);

        switch (opcion) {
            case 1: u1.Menu_unidad_1(); break;
            case 2: u2.Menu_unidad_2(); break;
            case 3: u3.mostrarMenu(); break;
            case 0: cout << "Saliendo del sistema..." << endl; break;
        }

    } while (opcion != 0);

    return 0;
}