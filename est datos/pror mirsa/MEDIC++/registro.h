#ifndef REGISTRO_H
#define REGISTRO_H

#include <string>
using namespace std;

struct Pacientes {
    string nombre;
    string sexo;
    int edad;
    float peso;
    float est;
};

void inicializarEntorno();
void registrar();
void buscar();
void modificar();
void eliminar();

#endif // REGISTRO_H