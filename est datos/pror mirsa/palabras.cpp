#include <iostream>
#include <string>

using namespace std;

int cant_pal(string palabra) {
    int n = palabra.length();
    int num_palabras = 0;

    if(palabra.empty()){
        return 0;
    }

    for (int i = 1; i < n; i++) {
        if (palabra[i] == ' ') {
            num_palabras++;
        }
    }
}


int main() {
    string palabra;
    cout << "Ingrese una palabra: ";
    getline(cin, palabra);

    cout << "La cantidad de palabras es: " << cant_pal(palabra) << endl;

    return 0;
}
