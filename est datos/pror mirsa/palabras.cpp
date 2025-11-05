#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int cant_pal(string palabra) {
    int n = palabra.length();
    int num_palabras = 0;
    bool pal = true;
    if(palabra.empty()){
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (isspace(palabra[i])) {
            pal = true;
        } else {
            if (pal == true) {
                num_palabras++;
                pal = false;
            }   
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

int num_letters(string palabra){
    int n = palabra.length();
    int num_letras = 0;

    for (int i = 0; i < n; i++) {
        if (isalpha(palabra[i])) {
            num_letras++;
        }
    }

    return num_letras;
}

int main() {
    string palabra;
    char letra;
    cout << "Ingrese una string: \n";
    getline(cin, palabra);

    cout << "Ingrese una letra: \n";
    cin >> letra;

    cout << "La cantidad de palabras es: " << cant_pal(palabra) << endl;
    cout << "La cantidad de letras es: " << num_letters(palabra) << endl;
    cout << "La cantidad de veces que aparece la letra " << letra << " es: " << getletter(palabra, letra) << endl;
    

    return 0;
}
