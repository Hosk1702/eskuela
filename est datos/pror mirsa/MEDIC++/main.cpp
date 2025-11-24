#include <iostream>
#include <limits>
#include "registro.h"

using namespace std;

int main() {
    // Prepara la carpeta
    inicializarEntorno();

    bool valid = true;
    int opcion;

    cout << "\t"<<"==========================\n";
    cout << "\t"<< "  BIENVENIDO A MEDIC++ >>\n";
    cout << "\t" << "==========================\n";

    do {
        cout << "\n1. Registrar\n2. Buscar\n3. Modificar\n4. Eliminar\n5. Salir\nOpcion: ";
        
        // Validación básica de entrada
        while (!(cin >> opcion) || opcion < 1 || opcion > 5) {
            cout << "Opcion invalida. Intente de nuevo: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (opcion) {
            case 1: registrar(); break;
            case 2: buscar(); break;
            case 3: modificar(); break;
            case 4: eliminar(); break;
            case 5: valid = false; break;
        }
    } while (valid);

    return 0;
}