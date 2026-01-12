#include "unidad3.h"
#include "utils.h" // Para usar tu validación pedirOpcion
#include <iostream>
#include <limits>
#include <cstdlib>

using namespace std;

void Unidad3::mostrarMenu() {
    int opcion;
    do {
        system("cls");
        cout << "\n========================================" << endl;
        cout << "            MENU UNIDAD 3              " << endl;
        cout << "========================================" << endl;
        cout << "1. PROYECTO: Sistema MEDIC++" << endl;
        cout << "2. Actividad 1: Examen Peliculas" << endl; // <--- Opción actualizada
        cout << "0. Regresar al Menu Principal" << endl;
        cout << "========================================" << endl;
        
        // Usamos tu función de validación si está disponible, o cin directo
        cout << "Seleccione una opcion: ";
        while (!(cin >> opcion)) {
            cin.clear(); cin.ignore(10000, '\n');
            cout << "Ingrese numero valido: ";
        }

        switch (opcion) {
            case 1: ejecutarMedic(); break;
            case 2: act1(); break; 
            case 0: break;
            default: cout << "Opcion invalida." << endl; system("pause"); break;
        }
    } while (opcion != 0);
}
// AQUÍ CONECTAMOS EL EXAMEN DE PELÍCULAS A LA ACTIVIDAD 1
void Unidad3::act1() {
    // Llamamos a la función principal que definimos en examen.h / examen.cpp
    menuPeliculas(); 
}

// ==========================================================
// INTEGRACIÓN DE MEDIC++ (Ya la tenías, se mantiene igual)
// ==========================================================
void Unidad3::ejecutarMedic() {
    inicializarEntorno(); // Crea carpetas si es necesario

    bool salirMedic = false;
    int opcion;

    do {
        system("cls");
        cout << "\t" << "===============================\n";
        cout << "\t" << "   SISTEMA INTEGRAL MEDIC++    \n";
        cout << "\t" << "===============================\n";
        cout << "\nSeleccione una opcion:\n";
        cout << "1. Gestionar Pacientes\n";
        cout << "2. Gestionar Medicos\n";
        cout << "3. Gestionar Empleados\n";
        cout << "4. Regresar al Menu Unidad 3\n";
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
            case 4: salirMedic = true; break;
        }

    } while (!salirMedic);
}

float Unidad3::pedirFloat(string mensaje) {
    float valor;
    while (true) {
        cout << mensaje;
        if (cin >> valor) {
            return valor;
        } else {
            cout << "   [!] Error: Ingrese solo numeros.\n";
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
    }
}


void Unidad3::llenarDatos(Paciente* p) {
    cout << "\n--- INGRESO DE DATOS ---\n";
    cout << "Ingrese primer nombre: ";
    cin >> p->nombre; 
    
    cout << "Ingrese primer apellido: ";
    cin >> p->ap1;
    
    cout << "Ingrese segundo apellido: ";
    cin >> p->ap2;

    p->estatura = pedirFloat("Ingrese estatura (mts, ej: 1.76): ");
    p->peso = pedirFloat("Ingrese peso (kg, ej: 85.5): ");
}

void Unidad3::calcular(Paciente* p) {
    if (p->estatura > 0) {
        p->imc = p->peso / (p->estatura * p->estatura);
    } else {
        p->imc = 0;
    }
}

void Unidad3::mostrar(Paciente* p) {
    cout << "\n------------------------------\n";
    cout << "FICHA DE: " << p->nombre << " " << p->ap1 << " " << p->ap2 << "\n";
    cout << "IMC: " << p->imc << "\n";
    
    cout << "DIAGNOSTICO: ";
    if (p->imc < 18.5) {
        cout << "Bajo peso\n";
    } else if (p->imc >= 18.5 && p->imc < 25) {
        cout << "Peso normal\n";
    } else if (p->imc >= 25 && p->imc < 30) {
        cout << "Sobrepeso\n";
    } else {
        cout << "Obesidad\n";
    }
    cout << "------------------------------\n";
}

void Unidad3::act2() {
    int opcion = 1;

    do {
        system("cls"); 
        cout << "=== CALCULADORA IMC (Punteros) ===\n";

        Paciente* actual = new Paciente;

        llenarDatos(actual);
        calcular(actual);
        mostrar(actual);

        delete actual;

        cout << "\n¿Desea hacer otra consulta? (1.SI / 2.NO): ";
        while (!(cin >> opcion) || (opcion != 1 && opcion != 2)) {
            cout << "Opcion invalida. Ingrese 1 o 2: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    } while (opcion == 1);

}