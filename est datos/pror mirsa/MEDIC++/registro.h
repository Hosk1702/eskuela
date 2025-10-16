#ifndef REGISTRO_H_INCLUDED
#define REGISTRO_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Pacientes {
    string nombre;
    int edad;
    float estatura;
    float peso;
    char genero;
    string dianostico;
};

void registrar(vector<Pacientes>& lista){
        Pacientes nuevo_paciente;

        cout << "Ingrese el nombre del paciente: \n";
        getline(cin, nuevo_paciente.nombre);



        lista.push_back(nuevo_paciente);

    }

#endif // REGISTRO_H_INCLUDED
