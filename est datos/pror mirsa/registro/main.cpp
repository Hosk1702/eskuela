#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void obtenerDatos(string& usuario, string& contrasena, string& confirmacion) {
    cout << "--- Creación de Cuenta ---" << endl;

    cout << "Introduce tu nombre de usuario: ";
    getline(cin, usuario);

    cout << "Introduce tu contraseña: ";
    getline(cin, contrasena);

    cout << "Confirma tu contraseña: ";
    getline(cin, confirmacion);
}

string verificarSeguridad(string contrasena) {

    int longitud = contrasena.length();

    bool tieneNum = false;
    bool tieneMin = false;
    bool tieneMay = false;
    bool tieneEsp = false;

    bool soloNumeros = true;
    bool soloMinusculas = true;

    if (longitud == 0) {
        return "Inválida (vacía)";
    }

    for (char c : contrasena) {

        if (isdigit(c)) {
            tieneNum = true;
        } else if (islower(c)) {
            tieneMin = true;
        } else if (isupper(c)) {
            tieneMay = true;
        } else if (ispunct(c)) {
            tieneEsp = true;
        }

        if (!isdigit(c)) {
            soloNumeros = false;
        }
        if (!islower(c)) {
            soloMinusculas = false;
        }
    }

    if (longitud >= 8 && tieneNum && tieneMin && tieneMay && tieneEsp) {
        return "Alto";
    }

    bool tieneLetras = tieneMin || tieneMay;
    if (tieneNum && tieneLetras && tieneEsp) {
        return "Medio";
    }

    if (soloNumeros || soloMinusculas) {
        return "Bajo";
    }

    return "Bajo";
}


int main() {
    string nombreUsuario;
    string contrasena;
    string confirmacionContrasena;

    obtenerDatos(nombreUsuario, contrasena, confirmacionContrasena);

    cout << "\n--- Verificación ---" << endl;

    if (contrasena != confirmacionContrasena) {
        cout << "Error: Las contraseñas no coinciden." << endl;
        return 1;
    }

    cout << "¡Contraseñas coinciden!" << endl;

    string nivel = verificarSeguridad(contrasena);

    cout << "Hola, " << nombreUsuario << "." << endl;
    cout << "Tu contraseña tiene un nivel de seguridad: " << nivel << endl;

    return 0;
}
