#ifndef REGISTRO_H
#define REGISTRO_H

#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

struct Pacientes {
    string nombre;
    string sexo;
    int edad;
    float peso;
    float est;
};

// --- Declaraciones de Funciones (Prototipos) ---
void registrar(vector<Pacientes> &lista);
void buscar(const vector<Pacientes> &lista);
void modificar(vector<Pacientes> &lista);
void eliminar(vector<Pacientes> &lista);
int encontrarPaciente(const vector<Pacientes> &lista, const string &nombre); // Función de ayuda

#endif // REGISTRO_H
