#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void obtenerDatos(string& usuario, string& contrasena, string& confirmacion) {
    cout << "--- Creaci�n de Cuenta ---" << endl;

    cout << "Introduce tu nombre de usuario: ";
    getline(cin, usuario);

    cout << "Introduce tu contrase�a: ";
    getline(cin, contrasena);

    cout << "Confirma tu contrase�a: ";
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
        return "Inv�lida (vac�a)";
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

    cout << "\n--- Verificaci�n ---" << endl;

    if (contrasena != confirmacionContrasena) {
        cout << "Error: Las contrase�as no coinciden." << endl;
        return 1;
    }

    cout << "�Contrase�as coinciden!" << endl;

    string nivel = verificarSeguridad(contrasena);

    cout << "Hola, " << nombreUsuario << "." << endl;
    cout << "Tu contrase�a tiene un nivel de seguridad: " << nivel << endl;

    return 0;
}
