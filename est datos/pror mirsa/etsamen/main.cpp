#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <limits>
#include <string>

using namespace std;

struct pelicula {
    string titulo;
    string director;
    float duracion;
    int anho;
    float calificacion;
};

const string ARCHIVO_PELICULAS = "./registros/peliculas.txt";

void inicializarEntorno() {
    system("mkdir registros");
}

pelicula lineaApelicula(string linea) {
    pelicula p;
    stringstream ss(linea);
    string segmento;

    getline(ss, p.titulo, '|');
    getline(ss, p.director, '|');

    getline(ss, segmento, '|');
    p.duracion = segmento.empty() ? 0 : stof(segmento);

    getline(ss, segmento, '|');
    p.anho = segmento.empty() ? 0 : stoi(segmento);

    getline(ss, segmento, '|');
    p.calificacion = segmento.empty() ? 0 : stof(segmento);

    return p;
}

vector<pelicula> cargarPeliculas() {
    vector<pelicula> lista;
    ifstream archivo(ARCHIVO_PELICULAS.c_str());
    if (!archivo.is_open()) return lista;

    string linea;
    while (getline(archivo, linea)) {
        if (!linea.empty()) lista.push_back(lineaApelicula(linea));
    }
    archivo.close();
    return lista;
}

void guardarPeliculas(const vector<pelicula>& lista) {
    ofstream archivo(ARCHIVO_PELICULAS.c_str(), ios::trunc);
    if (archivo.is_open()) {
        for (size_t i = 0; i < lista.size(); i++) {
            archivo << lista[i].titulo << "|" << lista[i].director << "|"
                    << lista[i].duracion << "|" << lista[i].anho << "|"
                    << lista[i].calificacion << "\n";
        }
        archivo.close();
    }
}

void registrarPelicula() {
    pelicula p;
    string temp;
    cout << "\n== INGRESAR PELICULA ==\n";
    cin.ignore();

    cout << "Titulo: ";
    getline(cin, p.titulo);

    cout << "Director: ";
    getline(cin, p.director);

    cout << "Duracion: ";
    getline(cin, temp);
    p.duracion = temp.empty() ? 0 : stof(temp);

    cout << "Anio: ";
    getline(cin, temp);
    p.anho = temp.empty() ? 0 : stoi(temp);

    cout << "Calificacion: ";
    getline(cin, temp);
    p.calificacion = temp.empty() ? 0 : stof(temp);

    ofstream archivo(ARCHIVO_PELICULAS.c_str(), ios::app);
    if (archivo.is_open()) {
        archivo << p.titulo << "|" << p.director << "|" << p.duracion << "|"
                << p.anho << "|" << p.calificacion << "\n";
        archivo.close();
        cout << "Pelicula registrada con exito.\n";
    }
}

void buscarPelicula() {
    ifstream archivo(ARCHIVO_PELICULAS.c_str());
    if (!archivo.is_open()) { cout << "No hay registros.\n"; return; }

    cin.ignore();
    string buscado;
    cout << "\nPelicula a buscar: "; getline(cin, buscado);

    string linea;
    bool encontrado = false;
    while (getline(archivo, linea)) {
        if (linea.empty()) continue;
        pelicula p = lineaApelicula(linea);
        if (p.titulo == buscado) {
            cout << "\n--- Pelicula Encontrada ---\n";
            cout << "Titulo: " << p.titulo << "\nDirector: " << p.director
                 << "\nDuracion: " << p.duracion << "\nAnio: " << p.anho
                 << "\nCalificacion: " << p.calificacion << "\n---------------------------\n";
            encontrado = true;
        }
    }
    if (!encontrado) cout << "No se encontro a " << buscado << endl;
    archivo.close();
}

void modificarPelicula() {
    vector<pelicula> todos = cargarPeliculas();
    if (todos.empty()) { cout << "No hay registros.\n"; return; }

    cin.ignore();
    string buscado;
    cout << "\nTitulo a modificar: "; getline(cin, buscado);

    bool encontrado = false;
    for (size_t i = 0; i < todos.size(); i++) {
        if (todos[i].titulo == buscado) {
            encontrado = true;
            string entrada;
            cout << "Ingrese nuevos datos (Presione Enter para dejar el valor actual)\n";

            cout << "Nuevo Titulo (Actual: " << todos[i].titulo << "): ";
            getline(cin, entrada);
            if (!entrada.empty()) todos[i].titulo = entrada;

            cout << "Nuevo Director (Actual: " << todos[i].director << "): ";
            getline(cin, entrada);
            if (!entrada.empty()) todos[i].director = entrada;

            cout << "Nueva Duracion (Actual: " << todos[i].duracion << "): ";
            getline(cin, entrada);
            if (!entrada.empty()) todos[i].duracion = stof(entrada);

            cout << "Nuevo Anio (Actual: " << todos[i].anho << "): ";
            getline(cin, entrada);
            if (!entrada.empty()) todos[i].anho = stoi(entrada);

            cout << "Nueva Calificacion (Actual: " << todos[i].calificacion << "): ";
            getline(cin, entrada);
            if (!entrada.empty()) todos[i].calificacion = stof(entrada);
            break;
        }
    }

    if (encontrado) {
        guardarPeliculas(todos);
        cout << "Pelicula actualizada.\n";
    } else {
        cout << "Pelicula no encontrada.\n";
    }
}

void eliminarPelicula() {
    vector<pelicula> todos = cargarPeliculas();
    if (todos.empty()) { cout << "No hay registros.\n"; return; }

    cin.ignore();
    string buscado;
    cout << "\nTitulo a eliminar: "; getline(cin, buscado);

    bool encontrado = false;
    for (size_t i = 0; i < todos.size(); i++) {
        if (todos[i].titulo == buscado) {
            todos.erase(todos.begin() + i);
            encontrado = true;
            break;
        }
    }

    if (encontrado) {
        guardarPeliculas(todos);
        cout << "Pelicula eliminada.\n";
    } else {
        cout << "Pelicula no encontrada.\n";
    }
}

int main() {
    inicializarEntorno();

    bool salir = false;
    int opcion;

    do {
        cout << "\t" << "===============================\n";
        cout << "\t" << "           PELICULAS           \n";
        cout << "\t" << "===============================\n";
        cout << "\nSeleccione una opcion:\n";
        cout << "1. Anadir\n";
        cout << "2. Leer \n";
        cout << "3. Modificar\n";
        cout << "4. Borrar\n";
        cout << "5. Salir\n";
        cout << "Opcion: ";

        while (!(cin >> opcion) || opcion < 1 || opcion > 5) {
            cout << "Opcion invalida. Intente de nuevo: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    switch(opcion) {
        case 1: registrarPelicula(); break;
        case 2: buscarPelicula(); break;
        case 3: modificarPelicula(); break;
        case 4: eliminarPelicula(); break;
        case 5: salir = true; break;
    }

    } while (!salir);

    cout << "Saliendo del programa..";

    return 0;
}
