#include <iostream>
#include <limits>
#include "registro.h"

using namespace std;

int main() {
    // Crea la carpeta 'registros' si no existe
    inicializarEntorno();

    bool salir = false;
    int opcion;

    do {
        cout << "\t" << "===============================\n";
        cout << "\t" << "   SISTEMA INTEGRAL MEDIC++    \n";
        cout << "\t" << "===============================\n";
        cout << "\nSeleccione una opcion:\n";
        cout << "1. Gestionar Pacientes\n";
        cout << "2. Gestionar Medicos\n";
        cout << "3. Gestionar Empleados\n";
        cout << "4. Salir\n";
        cout << "Opcion: ";

        while (!(cin >> opcion) || opcion < 1 || opcion > 4) {
            cout << "Opcion invalida. Intente de nuevo: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (opcion) {
            case 1: menuPacientes(); break;
            case 2: menuMedicos(); break;
            case 3: menuEmpleados(); break;
            case 4: salir = true; break;
        }

    } while (!salir);

    cout << "Saliendo del sistema...\n";
    return 0;
}
