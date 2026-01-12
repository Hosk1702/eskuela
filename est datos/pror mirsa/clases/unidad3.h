#ifndef UNIDAD3_H
#define UNIDAD3_H

#include <iostream>
#include <string>
#include <vector>
#include "registro.h" // Para MEDIC++
#include "examen.h"   // Para el Examen de Películas

using namespace std;

struct Paciente {
    string nombre;
    string ap1;
    string ap2;
    float estatura; 
    float peso;
    double imc;
};

class Unidad3 { 
public:
    void mostrarMenu();

private:
    void ejecutarMedic(); // Lógica de MEDIC++
    
    // Actividades
    void act1();
    void act2();
    float pedirFloat(string mensaje);
    void llenarDatos(Paciente* p);
    void calcular(Paciente* p);
    void mostrar(Paciente* p);
};

#endif // UNIDAD3_H