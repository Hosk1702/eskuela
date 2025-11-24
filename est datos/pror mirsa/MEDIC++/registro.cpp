#include "registro.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>    
#include <cstdlib>   

using namespace std;

const string ARCHIVO = "./registros/pacientes.txt";


void inicializarEntorno() {
    system("mkdir registros"); 
}

Pacientes lineaAPaciente(string linea) {
    Pacientes p;
    stringstream ss(linea);
    string segmento;

    getline(ss, p.nombre, '|');
    getline(ss, p.sexo, '|');
    
    getline(ss, segmento, '|');
    p.edad = segmento.empty() ? 0 : stoi(segmento);
    
    getline(ss, segmento, '|');
    p.peso = segmento.empty() ? 0 : stof(segmento);
    
    getline(ss, segmento, '|');
    p.est = segmento.empty() ? 0 : stof(segmento);

    return p;
}

// Carga todo el archivo a memoria RAM para poder editarlo
vector<Pacientes> cargarDatosEnMemoria() {
    vector<Pacientes> lista;
    ifstream archivo(ARCHIVO.c_str());
    if (!archivo.is_open()) return lista;

    string linea;
    while (getline(archivo, linea)) {
        if (!linea.empty()) {
            lista.push_back(lineaAPaciente(linea));
        }
    }
    archivo.close();
    return lista;
}

// Sobrescribe el archivo original con la lista actualizada
void guardarDatosEnArchivo(const vector<Pacientes>& lista) {
    // ios::trunc BORRA el contenido del archivo para escribir lo nuevo
    ofstream archivo(ARCHIVO.c_str(), ios::trunc); 
    if (archivo.is_open()) {
        for (size_t i = 0; i < lista.size(); i++) {
            archivo << lista[i].nombre << "|" 
                    << lista[i].sexo << "|" 
                    << lista[i].edad << "|" 
                    << lista[i].peso << "|" 
                    << lista[i].est << "\n";
        }
        archivo.close();
    }
}

// --- Funciones Principales ---

void registrar() {
    Pacientes p;
    cout << "\n== INGRESAR PACIENTE ==\n";
    cin.ignore(); 

    cout << "Nombre: "; getline(cin, p.nombre);
    cout << "Sexo: "; cin >> p.sexo;
    cout << "Edad: "; cin >> p.edad;
    cout << "Peso: "; cin >> p.peso;
    cout << "Estatura: "; cin >> p.est;

    // Para registrar solo añadimos al final (ios::app), no hace falta reescribir todo
    ofstream archivo(ARCHIVO.c_str(), ios::app);
    if (archivo.is_open()) {
        archivo << p.nombre << "|" << p.sexo << "|" << p.edad << "|" 
                << p.peso << "|" << p.est << "\n";
        archivo.close();
        cout << "Paciente registrado con exito.\n";
    } else {
        cout << "Error: No se pudo abrir el archivo.\n";
    }
}

void buscar() {
    // Para buscar no necesitamos cargar todo, leemos linea por linea (más eficiente)
    ifstream archivo(ARCHIVO.c_str());
    if (!archivo.is_open()) {
        cout << "No hay registros.\n";
        return;
    }

    cin.ignore();
    string buscado;
    cout << "\nNombre a buscar: "; getline(cin, buscado);

    string linea;
    bool encontrado = false;
    while (getline(archivo, linea)) {
        if (linea.empty()) continue;
        Pacientes p = lineaAPaciente(linea);
        
        if (p.nombre == buscado) {
            cout << "\n--- Encontrado ---\n";
            cout << "Nombre: " << p.nombre << "\nSexo: " << p.sexo 
                 << "\nEdad: " << p.edad << "\nPeso: " << p.peso 
                 << "\nEstatura: " << p.est << "\n------------------\n";
            encontrado = true;
        }
    }
    archivo.close();
    if (!encontrado) cout << "No se encontro a " << buscado << endl;
}

void modificar() {
    // 1. Cargamos todo a memoria
    vector<Pacientes> todos = cargarDatosEnMemoria();
    if (todos.empty()) {
        cout << "No hay registros para modificar.\n";
        return;
    }

    cin.ignore();
    string buscado;
    cout << "\nNombre a modificar: "; getline(cin, buscado);

    bool encontrado = false;

    // 2. Modificamos en memoria
    for (size_t i = 0; i < todos.size(); i++) {
        if (todos[i].nombre == buscado) {
            encontrado = true;
            cout << "Paciente encontrado. Ingrese nuevos datos:\n";
            
            cout << "Nuevo Nombre (" << todos[i].nombre << "): "; 
            getline(cin, todos[i].nombre);
            
            cout << "Nuevo Sexo (" << todos[i].sexo << "): "; 
            cin >> todos[i].sexo;
            
            cout << "Nueva Edad (" << todos[i].edad << "): "; 
            cin >> todos[i].edad;
            
            cout << "Nuevo Peso (" << todos[i].peso << "): "; 
            cin >> todos[i].peso;
            
            cout << "Nueva Estatura (" << todos[i].est << "): "; 
            cin >> todos[i].est;
            cin.ignore(); 

            cout << "¡Datos modificados en memoria!\n";
            break; // Salimos del ciclo, ya encontramos al paciente
        }
    }

    // 3. Si hubo cambios, sobrescribimos el archivo original
    if (encontrado) {
        guardarDatosEnArchivo(todos);
        cout << "Archivo actualizado correctamente.\n";
    } else {
        cout << "No se encontro el paciente.\n";
    }
}

void eliminar() {
    // 1. Cargamos todo a memoria
    vector<Pacientes> todos = cargarDatosEnMemoria();
    if (todos.empty()) {
        cout << "No hay registros para eliminar.\n";
        return;
    }

    cin.ignore();
    string buscado;
    cout << "\nNombre a eliminar: "; getline(cin, buscado);

    bool encontrado = false;
    
    // 2. Busamos y eliminamos de la memoria
    for (size_t i = 0; i < todos.size(); i++) {
        if (todos[i].nombre == buscado) {
            // .erase elimina el elemento del vector
            todos.erase(todos.begin() + i);
            encontrado = true;
            cout << "Paciente eliminado de la memoria.\n";
            break; 
        }
    }

    // 3. Sobrescribimos el archivo con los que quedaron
    if (encontrado) {
        guardarDatosEnArchivo(todos);
        cout << "Archivo actualizado (registro borrado).\n";
    } else {
        cout << "No se encontro el paciente.\n";
    }
}