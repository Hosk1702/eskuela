#include "registro.h"
#include <iostream>
#include <string>
#include <vector>
#include <limits>


using namespace std;

/**
 * Pide los datos de un nuevo paciente y lo añade al vector.
 */
void registrar(vector<Pacientes> &lista) {
    Pacientes nuevoPaciente;

    cout << "\n== 1. Ingresar Nuevo Paciente ==\n";

    // Limpia el buffer de cin antes de usar getline
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Nombre: ";
    getline(cin, nuevoPaciente.nombre);

    cout << "Sexo: ";
    cin >> nuevoPaciente.sexo;

    cout << "Edad: ";
    while (!(cin >> nuevoPaciente.edad) || nuevoPaciente.edad <= 0) {
        cout << "Entrada invalida. Introduce un numero valido para la edad: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Peso: ";
    while (!(cin >> nuevoPaciente.peso) || nuevoPaciente.peso <= 0) {
        cout << "Entrada invalida. Introduce un numero valido para la edad: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Estatura: ";
    while (!(cin >> nuevoPaciente.est) || nuevoPaciente.est <= 0) {
        cout << "Entrada invalida. Introduce un numero valido para la edad: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    lista.push_back(nuevoPaciente);
    cout << "\n¡Paciente " << nuevoPaciente.nombre << " registrado con exito!\n";
}

/**
 * Busca un paciente por nombre y muestra sus datos.
 */
void buscar(const vector<Pacientes> &lista) {
    if (lista.empty()) {
        cout << "\nNo hay pacientes registrados.\n";
        return;
    }

    cout << "\n== 2. Buscar Paciente ==\n";
    cout << "Ingresa el nombre completo del paciente a buscar: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string nombreBusqueda;
    getline(cin, nombreBusqueda);

    int indice = encontrarPaciente(lista, nombreBusqueda);

    if (indice != -1) {
        const Pacientes &paciente = lista[indice]; // Usamos const & para no copiar
        cout << "\n--- Paciente Encontrado ---\n";
        cout << "Nombre: " << paciente.nombre << "\n";
        cout << "Sexo: " << paciente.sexo << "\n";
        cout << "Edad: " << paciente.edad << "\n";
        cout << "Peso: " << paciente.peso << "\n";
        cout << "Estatura: " << paciente.est << "\n";
        cout << "---------------------------\n";
    } else {
        cout << "\nNo se encontro ningun paciente con el nombre: " << nombreBusqueda << "\n";
    }
}

/**
 * Busca un paciente por nombre y permite modificar sus datos.
 */
void modificar(vector<Pacientes> &lista) {
    if (lista.empty()) {
        cout << "\nNo hay pacientes para modificar.\n";
        return;
    }

    cout << "\n== 3. Modificar Paciente ==\n";
    cout << "Ingresa el nombre completo del paciente a modificar: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string nombreBusqueda;
    getline(cin, nombreBusqueda);

    int indice = encontrarPaciente(lista, nombreBusqueda);

    if (indice != -1) {
        Pacientes &paciente = lista[indice]; // Referencia para modificar

        cout << "Paciente encontrado (" << paciente.nombre << "). Ingresa los nuevos datos (deja en blanco para no cambiar):\n";

        string nuevoNombre;
        cout << "Nuevo Nombre: ";
        getline(cin, nuevoNombre);
        if (!nuevoNombre.empty()) {
            paciente.nombre = nuevoNombre;
        }

        string nuevoSexo;
        cout << "Nuevo Sexo: ";
        getline(cin, nuevoSexo);
        if (!nuevoSexo.empty()) {
            paciente.sexo = nuevoSexo;
        }

        string nuevaEdadStr;
        int nuevaEdad;
        cout << "Nueva Edad: ";
        getline(cin, nuevaEdadStr);
        if (!nuevaEdadStr.empty()) {
            // Validamos que la nueva edad sea un número
            try {
                nuevaEdad = stoi(nuevaEdadStr); // stoi = string to integer
                if (nuevaEdad > 0) {
                    paciente.edad = nuevaEdad;
                } else {
                    cout << "La edad debe ser un numero positivo. Edad no actualizada.\n";
                }
            } catch (...) {
                cout << "Entrada invalida. Edad no actualizada.\n";
            }
        }

        string nuevoPesoStr;
        int nuevoPeso;
        cout << "Nuevo Peso: ";
        getline(cin, nuevoPesoStr);
        if (!nuevoPesoStr.empty()) {
            // Validamos que el nuevo peso sea un número
            try {
                nuevoPeso = stoi(nuevoPesoStr); // stoi = string to integer
                if (nuevoPeso > 0) {
                    paciente.peso = nuevoPeso;
                } else {
                    cout << "El Peso debe ser un numero positivo. Peso no actualizado.\n";
                }
            } catch (...) {
                cout << "Entrada invalida. Peso no actualizado.\n";
            }
        }

        string nuevaEstStr;
        int nuevaEst;
        cout << "Nueva Estatura: ";
        getline(cin, nuevaEstStr);
        if (!nuevaEstStr.empty()) {
            // Validamos que la nueva estatura sea un número
            try {
                nuevaEst = stoi(nuevaEstStr); // stoi = string to integer
                if (nuevaEst > 0) {
                    paciente.est = nuevaEst;
                } else {
                    cout << "La estatura debe ser un numero positivo. Estatura no actualizada.\n";
                }
            } catch (...) {
                cout << "Entrada invalida. Estatura no actualizada.\n";
            }
        }

        cout << "\n¡Datos actualizados para " << paciente.nombre << "!\n";

    } else {
        cout << "\nNo se encontro ningun paciente con el nombre: " << nombreBusqueda << "\n";
    }
}

/**
 * Busca un paciente por nombre y lo elimina del vector.
 */
void eliminar(vector<Pacientes> &lista) {
    if (lista.empty()) {
        cout << "\nNo hay pacientes para eliminar.\n";
        return;
    }

    cout << "\n== 4. Eliminar Paciente ==\n";
    cout << "Ingresa el nombre completo del paciente a eliminar: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string nombreBusqueda;
    getline(cin, nombreBusqueda);

    int indice = encontrarPaciente(lista, nombreBusqueda);

    if (indice != -1) {
        string nombreEliminado = lista[indice].nombre;
        // .erase necesita un "iterador", .begin() + indice nos da eso.
        lista.erase(lista.begin() + indice);
        cout << "\n¡Paciente " << nombreEliminado << " eliminado con exito!\n";
    } else {
        cout << "\nNo se encontro ningun paciente con el nombre: " << nombreBusqueda << "\n";
    }
}


/**
 * Función de ayuda para buscar un paciente.
 * Devuelve el índice (posición) del paciente en el vector.
 * Devuelve -1 si no se encuentra.
 */
int encontrarPaciente(const vector<Pacientes> &lista, const string &nombre) {
    for (size_t i = 0; i < lista.size(); ++i) {
        // Comparamos ignorando mayúsculas/minúsculas (opcional, pero útil)
        // Para hacerlo simple, aquí comparamos directo:
        if (lista[i].nombre == nombre) {
            return i; // Devuelve el índice
        }
    }
    return -1; // No encontrado
}
