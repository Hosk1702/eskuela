#ifndef funciones_h
#define funciones_h

#include <string>
#include <vector>

using namespace std;

struct producto {
    string nombre;
    float precio;
    float cantidad;
};

// Configuración inicial y Utilidades Visuales
void inicializarEntorno();
void pausarYLimpiar();
void imprimirCentrado(string texto);
int leerEntero(string mensaje);

// Gestión de Productos
void menuRegistrarProducto();
vector<producto*> cargarProductos();
void guardarProductos(const vector<producto*>& lista);
void liberarMemoria(vector<producto*>& lista);

// Gestión de Ventas
void registrarVenta();
void verVentasDia();

// Gestión de Usuarios
string login();

#endif // funciones_h
