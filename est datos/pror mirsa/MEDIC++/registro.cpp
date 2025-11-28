#include "registro.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <limits>

using namespace std;

// Archivos para cada tipo
const string ARCHIVO_PACIENTES = "./registros/pacientes.txt";
const string ARCHIVO_MEDICOS = "./registros/medicos.txt";
const string ARCHIVO_EMPLEADOS = "./registros/empleados.txt";

void inicializarEntorno() {
    // En Windows mkdir funciona bien, en Linux/Mac seria mkdir -p registros
    system("mkdir registros");
}

// ==========================================
//              LOGICA PACIENTES
// ==========================================

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

vector<Pacientes> cargarPacientes() {
    vector<Pacientes> lista;
    ifstream archivo(ARCHIVO_PACIENTES.c_str());
    if (!archivo.is_open()) return lista;

    string linea;
    while (getline(archivo, linea)) {
        if (!linea.empty()) lista.push_back(lineaAPaciente(linea));
    }
    archivo.close();
    return lista;
}

void guardarPacientes(const vector<Pacientes>& lista) {
    ofstream archivo(ARCHIVO_PACIENTES.c_str(), ios::trunc);
    if (archivo.is_open()) {
        for (size_t i = 0; i < lista.size(); i++) {
            archivo << lista[i].nombre << "|" << lista[i].sexo << "|"
                    << lista[i].edad << "|" << lista[i].peso << "|"
                    << lista[i].est << "\n";
        }
        archivo.close();
    }
}

void registrarPaciente() {
    Pacientes p;
    cout << "\n== INGRESAR PACIENTE ==\n";
    cin.ignore();
    cout << "Nombre: "; getline(cin, p.nombre);
    cout << "Sexo: "; cin >> p.sexo;
    cout << "Edad: "; cin >> p.edad;
    cout << "Peso: "; cin >> p.peso;
    cout << "Estatura: "; cin >> p.est;

    ofstream archivo(ARCHIVO_PACIENTES.c_str(), ios::app);
    if (archivo.is_open()) {
        archivo << p.nombre << "|" << p.sexo << "|" << p.edad << "|"
                << p.peso << "|" << p.est << "\n";
        archivo.close();
        cout << "Paciente registrado con exito.\n";
    }
}

void buscarPaciente() {
    ifstream archivo(ARCHIVO_PACIENTES.c_str());
    if (!archivo.is_open()) { cout << "No hay registros.\n"; return; }

    cin.ignore();
    string buscado;
    cout << "\nNombre a buscar: "; getline(cin, buscado);

    string linea;
    bool encontrado = false;
    while (getline(archivo, linea)) {
        if (linea.empty()) continue;
        Pacientes p = lineaAPaciente(linea);
        if (p.nombre == buscado) {
            cout << "\n--- Paciente Encontrado ---\n";
            cout << "Nombre: " << p.nombre << "\nSexo: " << p.sexo
                 << "\nEdad: " << p.edad << "\n---------------------------\n";
            encontrado = true;
        }
    }
    if (!encontrado) cout << "No se encontro a " << buscado << endl;
    archivo.close();
}

void modificarPaciente() {
    vector<Pacientes> todos = cargarPacientes();
    if (todos.empty()) { cout << "No hay registros.\n"; return; }

    cin.ignore();
    string buscado;
    cout << "\nNombre a modificar: "; getline(cin, buscado);

    bool encontrado = false;
    for (size_t i = 0; i < todos.size(); i++) {
        if (todos[i].nombre == buscado) {
            encontrado = true;
            cout << "Ingrese nuevos datos (Nombre actual: " << todos[i].nombre << "): ";
            getline(cin, todos[i].nombre);
            cout << "Nuevo Sexo: "; cin >> todos[i].sexo;
            cout << "Nueva Edad: "; cin >> todos[i].edad;
            cout << "Nuevo Peso: "; cin >> todos[i].peso;
            cout << "Nueva Estatura: "; cin >> todos[i].est;
            cin.ignore();
            break;
        }
    }

    if (encontrado) {
        guardarPacientes(todos);
        cout << "Paciente actualizado.\n";
    } else {
        cout << "Paciente no encontrado.\n";
    }
}

void eliminarPaciente() {
    vector<Pacientes> todos = cargarPacientes();
    if (todos.empty()) { cout << "No hay registros.\n"; return; }

    cin.ignore();
    string buscado;
    cout << "\nNombre a eliminar: "; getline(cin, buscado);

    bool encontrado = false;
    for (size_t i = 0; i < todos.size(); i++) {
        if (todos[i].nombre == buscado) {
            todos.erase(todos.begin() + i);
            encontrado = true;
            break;
        }
    }

    if (encontrado) {
        guardarPacientes(todos);
        cout << "Paciente eliminado.\n";
    } else {
        cout << "Paciente no encontrado.\n";
    }
}

void menuPacientes() {
    bool volver = false;
    int op;
    do {
        cout << "\n--- GESTION DE PACIENTES ---\n";
        cout << "1. Registrar\n2. Buscar\n3. Modificar\n4. Eliminar\n5. Volver al menu principal\nOpcion: ";
        while (!(cin >> op) || op < 1 || op > 5) {
            cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Intente de nuevo: ";
        }
        switch(op) {
            case 1: registrarPaciente(); break;
            case 2: buscarPaciente(); break;
            case 3: modificarPaciente(); break;
            case 4: eliminarPaciente(); break;
            case 5: volver = true; break;
        }
    } while (!volver);
}


// ==========================================
//              LOGICA MEDICOS
// ==========================================

Medicos lineaAMedico(string linea) {
    Medicos m;
    stringstream ss(linea);
    getline(ss, m.nombre, '|');
    getline(ss, m.especialidad, '|');
    getline(ss, m.telefono, '|');
    return m;
}

vector<Medicos> cargarMedicos() {
    vector<Medicos> lista;
    ifstream archivo(ARCHIVO_MEDICOS.c_str());
    if (!archivo.is_open()) return lista;
    string linea;
    while (getline(archivo, linea)) {
        if (!linea.empty()) lista.push_back(lineaAMedico(linea));
    }
    archivo.close();
    return lista;
}

void guardarMedicos(const vector<Medicos>& lista) {
    ofstream archivo(ARCHIVO_MEDICOS.c_str(), ios::trunc);
    if (archivo.is_open()) {
        for (size_t i = 0; i < lista.size(); i++) {
            archivo << lista[i].nombre << "|" << lista[i].especialidad << "|"
                    << lista[i].telefono << "\n";
        }
        archivo.close();
    }
}

void registrarMedico() {
    Medicos m;
    cout << "\n== REGISTRAR MEDICO ==\n";
    cin.ignore();
    cout << "Nombre: "; getline(cin, m.nombre);
    cout << "Especialidad: "; getline(cin, m.especialidad);
    cout << "Telefono: "; getline(cin, m.telefono);

    ofstream archivo(ARCHIVO_MEDICOS.c_str(), ios::app);
    if (archivo.is_open()) {
        archivo << m.nombre << "|" << m.especialidad << "|" << m.telefono << "\n";
        archivo.close();
        cout << "Medico registrado con exito.\n";
    } else {
        cout << "Error al abrir archivo de medicos.\n";
    }
}

void buscarMedico() {
    ifstream archivo(ARCHIVO_MEDICOS.c_str());
    if (!archivo.is_open()) { cout << "No hay medicos registrados.\n"; return; }

    cin.ignore();
    string buscado;
    cout << "\nNombre del medico a buscar: "; getline(cin, buscado);

    string linea;
    bool encontrado = false;
    while (getline(archivo, linea)) {
        if (linea.empty()) continue;
        Medicos m = lineaAMedico(linea);
        if (m.nombre == buscado) {
            cout << "\n--- Medico Encontrado ---\n";
            cout << "Nombre: " << m.nombre << "\nEspecialidad: " << m.especialidad
                 << "\nTelefono: " << m.telefono << "\n-------------------------\n";
            encontrado = true;
        }
    }
    if (!encontrado) cout << "No se encontro a " << buscado << endl;
    archivo.close();
}

void modificarMedico() {
    vector<Medicos> todos = cargarMedicos();
    if (todos.empty()) { cout << "No hay medicos para modificar.\n"; return; }

    cin.ignore();
    string buscado;
    cout << "\nNombre del medico a modificar: "; getline(cin, buscado);

    bool encontrado = false;
    for (size_t i = 0; i < todos.size(); i++) {
        if (todos[i].nombre == buscado) {
            encontrado = true;
            cout << "Ingrese nuevos datos:\n";
            cout << "Nuevo Nombre (" << todos[i].nombre << "): "; getline(cin, todos[i].nombre);
            cout << "Nueva Especialidad (" << todos[i].especialidad << "): "; getline(cin, todos[i].especialidad);
            cout << "Nuevo Telefono (" << todos[i].telefono << "): "; getline(cin, todos[i].telefono);
            break;
        }
    }

    if (encontrado) {
        guardarMedicos(todos);
        cout << "Medico actualizado.\n";
    } else {
        cout << "Medico no encontrado.\n";
    }
}

void eliminarMedico() {
    vector<Medicos> todos = cargarMedicos();
    if (todos.empty()) { cout << "No hay medicos para eliminar.\n"; return; }

    cin.ignore();
    string buscado;
    cout << "\nNombre del medico a eliminar: "; getline(cin, buscado);

    bool encontrado = false;
    for (size_t i = 0; i < todos.size(); i++) {
        if (todos[i].nombre == buscado) {
            todos.erase(todos.begin() + i);
            encontrado = true;
            break;
        }
    }

    if (encontrado) {
        guardarMedicos(todos);
        cout << "Medico eliminado.\n";
    } else {
        cout << "Medico no encontrado.\n";
    }
}

void menuMedicos() {
    bool volver = false;
    int op;
    do {
        cout << "\n--- GESTION DE MEDICOS ---\n";
        cout << "1. Registrar\n2. Buscar\n3. Modificar\n4. Eliminar\n5. Volver al menu principal\nOpcion: ";
        while (!(cin >> op) || op < 1 || op > 5) {
            cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Intente de nuevo: ";
        }
        switch(op) {
            case 1: registrarMedico(); break;
            case 2: buscarMedico(); break;
            case 3: modificarMedico(); break;
            case 4: eliminarMedico(); break;
            case 5: volver = true; break;
        }
    } while (!volver);
}


// ==========================================
//              LOGICA EMPLEADOS
// ==========================================

Empleados lineaAEmpleado(string linea) {
    Empleados e;
    stringstream ss(linea);
    string segmento;

    getline(ss, e.nombre, '|');
    getline(ss, e.cargo, '|');

    getline(ss, segmento, '|');
    e.salario = segmento.empty() ? 0.0f : stof(segmento);

    return e;
}

vector<Empleados> cargarEmpleados() {
    vector<Empleados> lista;
    ifstream archivo(ARCHIVO_EMPLEADOS.c_str());
    if (!archivo.is_open()) return lista;
    string linea;
    while (getline(archivo, linea)) {
        if (!linea.empty()) lista.push_back(lineaAEmpleado(linea));
    }
    archivo.close();
    return lista;
}

void guardarEmpleados(const vector<Empleados>& lista) {
    ofstream archivo(ARCHIVO_EMPLEADOS.c_str(), ios::trunc);
    if (archivo.is_open()) {
        for (size_t i = 0; i < lista.size(); i++) {
            archivo << lista[i].nombre << "|" << lista[i].cargo << "|"
                    << lista[i].salario << "\n";
        }
        archivo.close();
    }
}

void registrarEmpleado() {
    Empleados e;
    cout << "\n== REGISTRAR EMPLEADO ==\n";
    cin.ignore();
    cout << "Nombre: "; getline(cin, e.nombre);
    cout << "Cargo/Puesto: "; getline(cin, e.cargo);
    cout << "Salario: "; cin >> e.salario;

    ofstream archivo(ARCHIVO_EMPLEADOS.c_str(), ios::app);
    if (archivo.is_open()) {
        archivo << e.nombre << "|" << e.cargo << "|" << e.salario << "\n";
        archivo.close();
        cout << "Empleado registrado con exito.\n";
    } else {
        cout << "Error al abrir archivo de empleados.\n";
    }
}

void buscarEmpleado() {
    ifstream archivo(ARCHIVO_EMPLEADOS.c_str());
    if (!archivo.is_open()) { cout << "No hay empleados registrados.\n"; return; }

    cin.ignore();
    string buscado;
    cout << "\nNombre del empleado a buscar: "; getline(cin, buscado);

    string linea;
    bool encontrado = false;
    while (getline(archivo, linea)) {
        if (linea.empty()) continue;
        Empleados e = lineaAEmpleado(linea);
        if (e.nombre == buscado) {
            cout << "\n--- Empleado Encontrado ---\n";
            cout << "Nombre: " << e.nombre << "\nCargo: " << e.cargo
                 << "\nSalario: $" << e.salario << "\n---------------------------\n";
            encontrado = true;
        }
    }
    if (!encontrado) cout << "No se encontro a " << buscado << endl;
    archivo.close();
}

void modificarEmpleado() {
    vector<Empleados> todos = cargarEmpleados();
    if (todos.empty()) { cout << "No hay empleados para modificar.\n"; return; }

    cin.ignore();
    string buscado;
    cout << "\nNombre del empleado a modificar: "; getline(cin, buscado);

    bool encontrado = false;
    for (size_t i = 0; i < todos.size(); i++) {
        if (todos[i].nombre == buscado) {
            encontrado = true;
            cout << "Ingrese nuevos datos:\n";
            cout << "Nuevo Nombre (" << todos[i].nombre << "): "; getline(cin, todos[i].nombre);
            cout << "Nuevo Cargo (" << todos[i].cargo << "): "; getline(cin, todos[i].cargo);
            cout << "Nuevo Salario (" << todos[i].salario << "): "; cin >> todos[i].salario;
            cin.ignore();
            break;
        }
    }

    if (encontrado) {
        guardarEmpleados(todos);
        cout << "Empleado actualizado.\n";
    } else {
        cout << "Empleado no encontrado.\n";
    }
}

void eliminarEmpleado() {
    vector<Empleados> todos = cargarEmpleados();
    if (todos.empty()) { cout << "No hay empleados para eliminar.\n"; return; }

    cin.ignore();
    string buscado;
    cout << "\nNombre del empleado a eliminar: "; getline(cin, buscado);

    bool encontrado = false;
    for (size_t i = 0; i < todos.size(); i++) {
        if (todos[i].nombre == buscado) {
            todos.erase(todos.begin() + i);
            encontrado = true;
            break;
        }
    }

    if (encontrado) {
        guardarEmpleados(todos);
        cout << "Empleado eliminado.\n";
    } else {
        cout << "Empleado no encontrado.\n";
    }
}

void menuEmpleados() {
    bool volver = false;
    int op;
    do {
        cout << "\n--- GESTION DE EMPLEADOS ---\n";
        cout << "1. Registrar\n2. Buscar\n3. Modificar\n4. Eliminar\n5. Volver al menu principal\nOpcion: ";
        while (!(cin >> op) || op < 1 || op > 5) {
            cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Intente de nuevo: ";
        }
        switch(op) {
            case 1: registrarEmpleado(); break;
            case 2: buscarEmpleado(); break;
            case 3: modificarEmpleado(); break;
            case 4: eliminarEmpleado(); break;
            case 5: volver = true; break;
        }
    } while (!volver);
}
