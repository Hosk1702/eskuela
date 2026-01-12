#include <iostream>
#include <string>
#include <limits> 

using namespace std;

struct Paciente {
    string nombre;
    string ap1;
    string ap2;
    float estatura; 
    float peso;
    double imc;
};

float pedirFloat(string mensaje) {
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


void llenarDatos(Paciente* p) {
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

void calcular(Paciente* p) {
    if (p->estatura > 0) {
        p->imc = p->peso / (p->estatura * p->estatura);
    } else {
        p->imc = 0;
    }
}

void mostrar(Paciente* p) {
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

int act2() {
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