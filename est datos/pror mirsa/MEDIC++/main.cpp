#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include "registro.h" // Este ya incluye todo lo necesario

using namespace std;

int main(int argc, char const *argv[])
{
    vector<Pacientes> Lista_pacientes;
    bool valid = true;
    int opcion;

    cout << "\t"<<"==========================\n";
    cout << "\t"<< "  BIENVENIDO A MEDIC++ >>\n";
    cout << "\t" << "==========================\n";

    do {
        cout << "\nMenu Principal:\n";
        cout << "Que deseas hacer hoy?\n";
        cout << "\t" << "1. Ingresar datos de un paciente\n";
        cout << "\t" << "2. Buscar un paciente\n";
        cout << "\t" << "3. Modificar datos de un paciente\n";
        cout << "\t" << "4. Eliminar datos de un paciente\n";
        cout << "\t" << "5. Salir\n";
        cout << "Opcion: ";

        // Bucle de validación mejorado
        while (!(cin >> opcion) || opcion < 1 || opcion > 5) {
            if (cin.fail()) {
                cout << "Error: Entrada invalida. Por favor ingrese una opcion valida (1-5).\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                cout << "Error: Opcion fuera de rango. Por favor ingrese una opcion valida (1-5).\n";
            }
            cout << "Opcion: ";
        }

        switch (opcion) {
            case 1:
                registrar(Lista_pacientes);
                break;
            case 2:
                buscar(Lista_pacientes);
                break;
            case 3:
                modificar(Lista_pacientes);
                break;
            case 4:
                eliminar(Lista_pacientes);
                break;
            case 5:
                cout << "\nGracias por usar MEDIC++. Adios!\n";
                valid = false; // Termina el bucle do-while
                break;
        }
    } while (valid);

    return 0;
}
