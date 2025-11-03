#include <iostream>
#include <string>

using namespace std;

int cant_pal(string palabra) {
    int n = palabra.length();
    int num_palabras = 1;

    if(palabra.empty()){
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (palabra[i] == ' ' && islower(palabra[i - 1]) && islower(palabra[i + 1])) {
            num_palabras++;
        }
    }

    return num_palabras;
}

int getletter (string palabra, char letra){
    int num {0};

    if(palabra.empty()){
        return 0;
    }


    for (char c : palabra) {
        if (c == letra) {
            num++;
        }
    }
    
    return num;

}

int main() {
    string palabra;
    char letra;
    cout << "Ingrese una string: \n";
    getline(cin, palabra);

    cout << "Ingrese una letra: \n";
    cin >> letra;

    cout << "La cantidad de palabras es: " << cant_pal(palabra) << endl;
    cout << "La cantidad de veces que aparece la letra " << letra << " es: " << getletter(palabra, letra) << endl;
    

    return 0;
}
