#include "funciones.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <iomanip>

using namespace std;

const string Archivo_productos = "./registros/productos.txt";
const string Archivo_tickets = "./registros/tickets.txt";
const string Archivo_usuarios = "./registros/usuarios.txt";

// --- UTILIDADES VISUALES ---
void inicializarEntorno() {
    system("mkdir registros 2> NUL || mkdir -p registros");
}

void pausarYLimpiar() {
    cout << "\n";
    system("pause");
}

// Imprime texto centrado con salto de linea al final
void imprimirCentrado(string texto) {
    int anchoConsola = 80;
    int longitudTexto = texto.length();
    int padding = (anchoConsola - longitudTexto) / 2;

    if(padding > 0) {
        cout << string(padding, ' ');
    }
    cout << texto << endl;
}

// NUEVO: Imprime texto centrado SIN salto (para inputs)
void imprimirPromptCentrado(string texto) {
    int anchoConsola = 80;
    // Si el texto empieza con \n, lo imprimimos antes y ajustamos
    if(!texto.empty() && texto[0] == '\n') {
        cout << "\n";
        texto.erase(0, 1);
    }

    int longitudTexto = texto.length();
    int padding = (anchoConsola - longitudTexto) / 2;

    if(padding > 0) cout << string(padding, ' ');
    cout << texto;
}

void encabezado(string titulo) {
    system("cls");
    cout << "\n";
    imprimirCentrado("==========================================");
    imprimirCentrado(titulo);
    imprimirCentrado("==========================================");
    cout << "\n";
}

// --- LOGICA DE ARCHIVOS CON PUNTEROS ---

producto* lineaAproducto(string linea) {
    producto* p = new producto;
    stringstream ss(linea);
    string segmento;

    getline(ss, p->nombre, '|');

    getline(ss, segmento, '|');
    p->precio = segmento.empty() ? 0 : stof(segmento);

    getline(ss, segmento, '|');
    p->cantidad = segmento.empty() ? 0 : stof(segmento);

    return p;
}

vector<producto*> cargarProductos() {
    vector<producto*> lista;
    ifstream archivo(Archivo_productos.c_str());
    if (!archivo.is_open()) return lista;

    string linea;
    while (getline(archivo, linea)) {
        if (!linea.empty()) {
            lista.push_back(lineaAproducto(linea));
        }
    }
    archivo.close();
    return lista;
}

void guardarProductos(const vector<producto*>& lista) {
    ofstream archivo(Archivo_productos.c_str(), ios::trunc);
    if (archivo.is_open()) {
        for (size_t i = 0; i < lista.size(); i++) {
            archivo << lista[i]->nombre << "|"
                    << lista[i]->precio << "|"
                    << lista[i]->cantidad << "\n";
        }
        archivo.close();
    }
}

void liberarMemoria(vector<producto*>& lista) {
    for(size_t i = 0; i < lista.size(); i++) {
        delete lista[i];
    }
    lista.clear();
}

// --- FUNCIONES DE PRODUCTOS ---

void registrarProducto() {
    encabezado("REGISTRAR NUEVO PRODUCTO");

    producto* p = new producto;
    string temp;

    // Usamos el prompt centrado
    imprimirPromptCentrado(">> Nombre del producto: ");
    getline(cin, p->nombre);

    imprimirPromptCentrado(">> Precio unitario: $");
    getline(cin, temp);
    p->precio = temp.empty() ? 0 : stof(temp);

    imprimirPromptCentrado(">> Cantidad inicial: ");
    getline(cin, temp);
    p->cantidad = temp.empty() ? 0 : stof(temp);

    ofstream archivo(Archivo_productos.c_str(), ios::app);
    if (archivo.is_open()) {
        archivo << p->nombre << "|" << p->precio << "|" << p->cantidad << "\n";
        archivo.close();
        cout << "\n";
        imprimirCentrado("[!] Producto registrado exitosamente.");
    }

    delete p;
    pausarYLimpiar();
}

void desplegarProductos() {
    encabezado("INVENTARIO ACTUAL");
    vector<producto*> todos = cargarProductos();

    if (todos.empty()) {
        imprimirCentrado("El inventario esta vacio.");
        pausarYLimpiar();
        return;
    }

    string paddingTabla = "               ";

    cout << paddingTabla << left << setw(20) << "NOMBRE"
         << setw(10) << "PRECIO"
         << setw(10) << "STOCK" << endl;
    cout << paddingTabla << "------------------------------------------\n";

    for (size_t i = 0; i < todos.size(); i++) {
        cout << paddingTabla << left << setw(20) << todos[i]->nombre
             << "$" << setw(9) << todos[i]->precio
             << setw(10) << todos[i]->cantidad << endl;
    }

    liberarMemoria(todos);
    pausarYLimpiar();
}

void buscarProducto() {
    encabezado("BUSQUEDA DE PRODUCTO");
    vector<producto*> todos = cargarProductos();
    if (todos.empty()) { imprimirCentrado("No hay productos registrados."); pausarYLimpiar(); return; }

    string buscado;
    imprimirPromptCentrado(">> Ingrese nombre a buscar: ");
    getline(cin, buscado);

    bool encontrado = false;
    cout << "\n";
    imprimirCentrado("RESULTADOS:");

    for(const auto& p : todos) {
        if (p->nombre == buscado) {
            imprimirCentrado("---------------------------");
            cout << "               Nombre:   " << p->nombre << "\n";
            cout << "               Precio:   $" << p->precio << "\n";
            cout << "               Stock:    " << p->cantidad << "\n";
            imprimirCentrado("---------------------------");
            encontrado = true;
        }
    }

    if (!encontrado) imprimirCentrado("[!] Producto no encontrado.");

    liberarMemoria(todos);
    pausarYLimpiar();
}

void modificarProducto() {
    encabezado("MODIFICAR PRODUCTO");
    vector<producto*> todos = cargarProductos();
    if (todos.empty()) { imprimirCentrado("Inventario vacio."); pausarYLimpiar(); return; }

    string buscado;
    imprimirPromptCentrado(">> Producto a modificar: ");
    getline(cin, buscado);

    bool encontrado = false;
    for (size_t i = 0; i < todos.size(); i++) {
        if (todos[i]->nombre == buscado) {
            encontrado = true;
            string entrada;
            cout << "\n";
            imprimirCentrado("--- Editando: " + todos[i]->nombre + " ---");
            imprimirCentrado("(Presione Enter para no cambiar el valor)");
            cout << "\n";

            imprimirPromptCentrado("Nuevo Nombre: ");
            getline(cin, entrada);
            if (!entrada.empty()) todos[i]->nombre = entrada;

            imprimirPromptCentrado("Nuevo Precio: ");
            getline(cin, entrada);
            if (!entrada.empty()) todos[i]->precio = stof(entrada);

            imprimirPromptCentrado("Nuevo Stock:  ");
            getline(cin, entrada);
            if (!entrada.empty()) todos[i]->cantidad = stof(entrada);
            break;
        }
    }

    if (encontrado) {
        guardarProductos(todos);
        imprimirCentrado("[!] Producto actualizado.");
    } else {
        imprimirCentrado("[!] Producto no encontrado.");
    }

    liberarMemoria(todos);
    pausarYLimpiar();
}

void eliminarProducto() {
    encabezado("ELIMINAR PRODUCTO");
    vector<producto*> todos = cargarProductos();
    if (todos.empty()) { imprimirCentrado("Inventario vacio."); pausarYLimpiar(); return; }

    string buscado;
    imprimirPromptCentrado(">> Producto a eliminar: ");
    getline(cin, buscado);

    bool encontrado = false;
    for (size_t i = 0; i < todos.size(); i++) {
        if (todos[i]->nombre == buscado) {
            delete todos[i];
            todos.erase(todos.begin() + i);
            encontrado = true;
            break;
        }
    }

    if (encontrado) {
        guardarProductos(todos);
        imprimirCentrado("[!] Producto eliminado del sistema.");
    } else {
        imprimirCentrado("[!] No se encontro el producto.");
    }

    liberarMemoria(todos);
    pausarYLimpiar();
}

void menuRegistrarProducto() {
    bool volver = false;
    int op;
    do {
        system("cls");
        cout << "\n";
        imprimirCentrado("==========================================");
        imprimirCentrado("         GESTION DE INVENTARIO            ");
        imprimirCentrado("==========================================");
        imprimirCentrado("1. Ver Inventario Completo");
        imprimirCentrado("2. Registrar Nuevo");
        imprimirCentrado("3. Buscar");
        imprimirCentrado("4. Modificar");
        imprimirCentrado("5. Eliminar");
        imprimirCentrado("6. Volver al Menu Principal");

        // Ahora el input también estará centrado
        op = leerEntero("\n>> Opcion: ");

        switch(op) {
            case 1: desplegarProductos(); break;
            case 2: registrarProducto(); break;
            case 3: buscarProducto(); break;
            case 4: modificarProducto(); break;
            case 5: eliminarProducto(); break;
            case 6: volver = true; break;
            default: cout << ">> Opcion invalida.\n"; system("pause"); break;
        }
    } while (!volver);
}

// --- GESTION DE VENTAS ---

void registrarVenta() {
    encabezado("NUEVA VENTA");

    vector<producto*> inventario = cargarProductos();
    if (inventario.empty()) {
        imprimirCentrado("No hay productos para vender.");
        pausarYLimpiar();
        return;
    }

    string padding = "               ";
    cout << padding << left << setw(20) << "PRODUCTO" << "PRECIO" << endl;
    cout << padding << "----------------------------\n";
    for(const auto& p : inventario) {
        if(p->cantidad > 0)
            cout << padding << left << setw(20) << p->nombre << "$" << p->precio << endl;
    }
    cout << padding << "----------------------------\n";

    string busqueda;
    cout << "\n";
    imprimirPromptCentrado(">> Nombre del producto a vender: ");
    getline(cin, busqueda);

    int idx = -1;
    for(size_t i = 0; i < inventario.size(); i++) {
        if(inventario[i]->nombre == busqueda) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        imprimirCentrado("[!] Error: Producto no existe.");
        liberarMemoria(inventario);
        pausarYLimpiar();
        return;
    }

    // Input centrado para cantidad
    int cantidad = leerEntero(">> Cantidad a vender: ");

    while (cantidad <= 0 || cantidad > inventario[idx]->cantidad) {
        imprimirCentrado(">> Cantidad invalida o insuficiente.");
        cantidad = leerEntero(">> Cantidad a vender: ");
    }

    float total = cantidad * inventario[idx]->precio;
    inventario[idx]->cantidad -= cantidad;

    guardarProductos(inventario);

    ofstream tickets(Archivo_tickets.c_str(), ios::app);
    if(tickets.is_open()) {
        tickets << inventario[idx]->nombre << "|"
                << cantidad << "|"
                << total << "\n";
        tickets.close();
    }

    cout << "\n";
    imprimirCentrado("--- TICKET DE VENTA ---");
    cout << "               Producto:  " << inventario[idx]->nombre << endl;
    cout << "               Cantidad:  " << cantidad << endl;
    cout << "               TOTAL:     $" << total << endl;
    imprimirCentrado("-----------------------");
    imprimirCentrado("[!] Venta registrada correctamente.");

    liberarMemoria(inventario);
    pausarYLimpiar();
}

void verVentasDia() {
    encabezado("REPORTE DE VENTAS");

    ifstream archivo(Archivo_tickets.c_str());
    if (!archivo.is_open()) {
        imprimirCentrado("No hay ventas registradas aun.");
        pausarYLimpiar();
        return;
    }

    string linea;
    float granTotal = 0;
    string padding = "               ";

    cout << padding << left << setw(20) << "PRODUCTO"
         << setw(10) << "CANT."
         << setw(10) << "TOTAL" << endl;
    cout << padding << "------------------------------------------\n";

    while (getline(archivo, linea)) {
        if (linea.empty()) continue;
        stringstream ss(linea);
        string nom, cStr, tStr;

        getline(ss, nom, '|');
        getline(ss, cStr, '|');
        getline(ss, tStr, '|');

        float tVal = stof(tStr);
        granTotal += tVal;

        cout << padding << left << setw(20) << nom
             << setw(10) << cStr
             << "$" << tVal << endl;
    }
    archivo.close();

    cout << padding << "------------------------------------------\n";
    cout << padding << right << setw(30) << "TOTAL RECAUDADO: $" << granTotal << endl;
    cout << padding << "------------------------------------------\n";

    pausarYLimpiar();
}

// --- GESTION DE USUARIOS ---
void crearUsuariosDefault() {
    ifstream check(Archivo_usuarios.c_str());
    if (!check.is_open()) {
        ofstream archivo(Archivo_usuarios.c_str());
        archivo << "admin|admin123|admin\n";
        archivo << "vendedor|123|empleado\n";
        archivo.close();
    }
}

string login() {
    crearUsuariosDefault();
    string u, p;
    while(true) {
        encabezado("INICIO DE SESION");

        imprimirPromptCentrado(">> Usuario: ");
        getline(cin, u);

        imprimirPromptCentrado(">> Password: ");
        getline(cin, p);

        ifstream archivo(Archivo_usuarios.c_str());
        string linea;
        bool acceso = false;
        string rol = "";

        while(getline(archivo, linea)) {
            if (linea.empty()) continue;
            stringstream ss(linea);
            string uFile, pFile, rFile;
            getline(ss, uFile, '|');
            getline(ss, pFile, '|');
            getline(ss, rFile);
            if (!rFile.empty() && rFile[rFile.length()-1] == '\r') rFile.erase(rFile.length()-1);

            if(u == uFile && p == pFile) {
                acceso = true;
                rol = rFile;
                break;
            }
        }
        archivo.close();

        if(acceso) {
            cout << "\n";
            imprimirCentrado("[!] Bienvenido " + u);
            pausarYLimpiar();
            return rol;
        } else {
            cout << "\n";
            imprimirCentrado("[!] Usuario o clave incorrectos.");
            pausarYLimpiar();
        }
    }
}

// FUNCION ARREGLADA: Ahora centra el prompt de entrada
int leerEntero(string mensaje) {
    int numero;
    string entrada;
    while (true) {
        imprimirPromptCentrado(mensaje); // <--- AQUI ESTA LA MAGIA

        getline(cin, entrada);
        if (entrada.empty()) continue;
        try {
            size_t procesados;
            numero = stoi(entrada, &procesados);
            if (procesados != entrada.length()) throw invalid_argument("");
            return numero;
        } catch (...) {
            imprimirCentrado(">> Entrada invalida.");
        }
    }
}
