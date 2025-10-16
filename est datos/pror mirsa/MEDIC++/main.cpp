#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include "registro.h"
using namespace std;



int main(int argc, char const *argv[])
{
    vector<Pacientes> Lista_pacientes;
    bool valid = true;
    cout << "==============================\n";
    cout << "    BIENVENIDO A MEDIC++      \n";
    cout << "==============================\n";
    do{
    cout << "Que desea hacer hoy?\n";
    cout << "1. Ingresar datos de un paciente\n" << "2. Buscar un paciente\n" << "3. Modificar datos de un paciente \n" << "4. Eliminar datos de un paciente\n" << "5. Salir\n";
    int opcion;
    cin >> opcion;

    if (cin.fail()) {
        cout << "Error: Entrada invalida. Por favor ingrese una opcion valida.\n";
        valid = false;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else if(opcion < 1 || opcion > 5) {
        cout << "Error: Opcion fuera de rango. Por favor ingrese una opcion valida.\n";
        valid = false;
    } else {
        switch (opcion){
        case 1:
            registrar(Lista_pacientes);
            cout << Lista_pacientes[0].nombre;
        default:
            cout << "Gracias por usar el programa!!";
        }

    }
    }while(valid == false);


    return 0;
}
