#include <iostream>
#include "funciones.h"

using namespace std;

int main() {
    inicializarEntorno();

    string rol = login();
    bool salir = false;
    int opcion;

    do {
        system("cls");
        cout << "\n";
        imprimirCentrado("==========================================");
        string titulo = "SISTEMA TIENDITA++ (" + rol + ")";
        imprimirCentrado(titulo);
        imprimirCentrado("==========================================");

        if (rol == "admin") {
            imprimirCentrado("1. Gestionar Inventario");
            imprimirCentrado("2. Registrar Venta");
            imprimirCentrado("3. Reporte de Ventas");
            imprimirCentrado("4. Salir");

            opcion = leerEntero("\n>> Opcion: ");
            switch (opcion) {
                case 1: menuRegistrarProducto(); break;
                case 2: registrarVenta(); break;
                case 3: verVentasDia(); break;
                case 4: salir = true; break;
                default: cout << "Opcion invalida.\n"; system("pause"); break;
            }
        } else {
            imprimirCentrado("1. Registrar Venta");
            imprimirCentrado("2. Salir");

            opcion = leerEntero("\n>> Opcion: ");
            switch (opcion) {
                case 1: registrarVenta(); break;
                case 2: salir = true; break;
                default: cout << "Opcion invalida.\n"; system("pause"); break;
            }
        }

    } while (!salir);

    cout << "\n";
    imprimirCentrado("Saliendo del sistema...");
    return 0;
}
