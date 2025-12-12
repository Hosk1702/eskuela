#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <limits>
#include <string>

using namespace std;

struct empresa {
    string nombre;
    string sector;
    string pais;
    int anio;
    int empleados;
};

const string arch_empresa = "./registros/empresas.txt";

void inicializar() {

    system("mkdir registros 2> nul");
}


int stringToIntSeguro(string s) {
    if (s.empty()) return 0;
    try {
        return stoi(s);
    } catch (const std::invalid_argument& e) {
        return 0;
    } catch (const std::out_of_range& e) {
        return 0;
    }
}

empresa lineaAempresa(string linea) {
    empresa e;
    stringstream ss(linea);
    string segmento;



    getline(ss, e.nombre, '|');
    getline(ss, e.sector, '|');


    getline(ss, segmento, '|');
    e.empleados = stringToIntSeguro(segmento);


    getline(ss, segmento, '|');
    e.anio = stringToIntSeguro(segmento);


    getline(ss, e.pais, '|');

    return e;
}

vector<empresa> cargarEmpresas() {
    vector<empresa> lista;
    ifstream archivo(arch_empresa.c_str());
    if (!archivo.is_open()) return lista;

    string linea;
    while (getline(archivo, linea)) {
        if (!linea.empty()) lista.push_back(lineaAempresa(linea));
    }
    archivo.close();
    return lista;
}

void guardarEmpresas(const vector<empresa>& lista) {
    ofstream archivo(arch_empresa.c_str(), ios::trunc);
    if (archivo.is_open()) {
        for (size_t i = 0; i < lista.size(); i++) {

            archivo << lista[i].nombre << "|"
                    << lista[i].sector << "|"
                    << lista[i].empleados << "|"
                    << lista[i].anio << "|"
                    << lista[i].pais << "\n";
        }
        archivo.close();
    }
}

void registrarEmpresa() {
    empresa e;
    string temp;
    cout << "\n== INGRESAR EMPRESA ==\n";


    cout << "Nombre: ";
    getline(cin, e.nombre);

    cout << "Sector: ";
    getline(cin, e.sector);

    cout << "Empleados: ";
    getline(cin, temp);
    e.empleados = stringToIntSeguro(temp);

    cout << "Año: ";
    getline(cin, temp);
    e.anio = stringToIntSeguro(temp);

    cout << "Pais: ";
    getline(cin, e.pais);


    ofstream archivo(arch_empresa.c_str(), ios::app);
    if (archivo.is_open()) {
        archivo << e.nombre << "|" << e.sector << "|" << e.empleados << "|"
                << e.anio << "|" << e.pais << "\n";
        archivo.close();
        cout << "Empresa registrada con exito.\n";
    } else {
        cout << "Error al abrir el archivo para guardar.\n";
    }
}

void buscarEmpresa() {
    ifstream archivo(arch_empresa.c_str());
    if (!archivo.is_open()) { cout << "No hay registros.\n"; return; }


    string buscado;
    cout << "\nEmpresa a buscar: ";
    getline(cin, buscado);

    string linea;
    bool encontrado = false;
    while (getline(archivo, linea)) {
        if (linea.empty()) continue;
        empresa e = lineaAempresa(linea);
        if (e.nombre == buscado) {
            cout << "\n--- Empresa Encontrada ---\n";
            cout << "Nombre: " << e.nombre
                 << "\nSector: " << e.sector
                 << "\nEmpleados: " << e.empleados
                 << "\nAño de fundacion: " << e.anio
                 << "\nPais: " << e.pais << "\n---------------------------\n";
            encontrado = true;
        }
    }
    if (!encontrado) cout << "No se encontro a " << buscado << endl;
    archivo.close();
}

void modificarEmpresa() {
    vector<empresa> todos = cargarEmpresas();
    if (todos.empty()) { cout << "No hay registros.\n"; return; }

    string buscado;
    cout << "\nEmpresa a modificar: ";
    getline(cin, buscado);

    bool encontrado = false;
    for (size_t i = 0; i < todos.size(); i++) {
        if (todos[i].nombre == buscado) {
            encontrado = true;
            string entrada;
            cout << "Ingrese nuevos datos (Presione Enter para mantener el valor actual)\n";

            cout << "Nuevo Nombre (Actual: " << todos[i].nombre << "): ";
            getline(cin, entrada);
            if (!entrada.empty()) todos[i].nombre = entrada;

            cout << "Nuevo Sector (Actual: " << todos[i].sector << "): ";
            getline(cin, entrada);
            if (!entrada.empty()) todos[i].sector = entrada;

            cout << "Nuevos Empleados (Actual: " << todos[i].empleados << "): ";
            getline(cin, entrada);
            if (!entrada.empty()) todos[i].empleados = stringToIntSeguro(entrada);

            cout << "Nuevo Año de fundacion (Actual: " << todos[i].anio << "): ";
            getline(cin, entrada);
            if (!entrada.empty()) todos[i].anio = stringToIntSeguro(entrada);

            cout << "Nuevo Pais (Actual: " << todos[i].pais << "): ";
            getline(cin, entrada);
            if (!entrada.empty()) todos[i].pais = entrada;
            break;
        }
    }

    if (encontrado) {
        guardarEmpresas(todos);
        cout << "Empresa actualizada.\n";
    } else {
        cout << "Empresa no encontrada.\n";
    }
}

void eliminarEmpresa() {
    vector<empresa> todos = cargarEmpresas();
    if (todos.empty()) { cout << "No hay registros.\n"; return; }

    string buscado;
    cout << "\nEmpresa a eliminar: ";
    getline(cin, buscado);

    bool encontrado = false;
    for (size_t i = 0; i < todos.size(); i++) {
        if (todos[i].nombre == buscado) {
            todos.erase(todos.begin() + i);
            encontrado = true;
            break;
        }
    }
    if (encontrado) {
        guardarEmpresas(todos);
        cout << "Empresa eliminada.\n";
    } else {
        cout << "Empresa no encontrada.\n";
    }
}

int main() {
    inicializar();

    bool salir = false;
    int opcion;

    do {
        cout << "\n\t" << "===============================\n";
        cout << "\t" << "          EMPRESAAAAAS          \n";
        cout << "\t" << "===============================\n";
        cout << "Seleccione una opcion:\n";
        cout << "1. Añadir\n";
        cout << "2. Leer \n";
        cout << "3. Modificar\n";
        cout << "4. Borrar\n";
        cout << "5. Salir\n";
        cout << "Opcion: ";

        if (!(cin >> opcion)) {
            cout << "Entrada invalida. Por favor ingrese un numero.\n";
            cin.clear(); // Limpiar estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Vaciar buffer
            continue;
        }


        cin.ignore();

        switch(opcion) {
            case 1: registrarEmpresa(); break;
            case 2: buscarEmpresa(); break;
            case 3: modificarEmpresa(); break;
            case 4: eliminarEmpresa(); break;
            case 5: salir = true; break;
            default: cout << "Opcion invalida (1-5).\n";
        }

    } while (!salir);

    cout << "Saliendo del programa..\n";

    return 0;
}
