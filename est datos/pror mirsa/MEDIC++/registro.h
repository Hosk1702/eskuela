#ifndef REGISTRO_H
#define REGISTRO_H

#include <string>
using namespace std;

// Estructura original
struct Pacientes {
    string nombre;
    string sexo;
    int edad;
    float peso;
    float est;
};

// Nueva estructura para Médicos
struct Medicos {
    string nombre;
    string especialidad;
    string telefono;
};

// Nueva estructura para Empleados
struct Empleados {
    string nombre;
    string cargo;
    float salario;
};

void inicializarEntorno();

// Menús principales para cada categoría
void menuPacientes();
void menuMedicos();
void menuEmpleados();

#endif // REGISTRO_H
