#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include <cctype>    

using namespace std;

vector<string> encontrarSubcadenas(const string& text, const vector<string>& wordsToFind) {
    
    vector<string> encontradas;
    
    for (const string& palabra : wordsToFind) {
        
        if (text.find(palabra) != string::npos) {
            encontradas.push_back(palabra);
        }
    }
    
    return encontradas;
}

int main() {
    vector<string> palabras_invalidas = {
        "whatsapp", "wa.me", "contáctame", "contactar", "contacto",
        "email", "correo", "arroba", "@", "gmail", "hotmail", "outlook",
        "punto com", ".com", "punto mx", ".mx", "punto edu", ".edu",
        "localizarme", "teléfono", "celular", "llámame", "llamar", "mi numero",
        "ig", "instagram", "facebook", "fb", "telegram", "trato por fuera",
        "sesenta", "ochenta" 
    };

    string mensaje;
    cout << "Escribe tu mensaje para Mercado Libre:" << endl;
    getline(cin, mensaje); 

    transform(mensaje.begin(), mensaje.end(), mensaje.begin(), ::tolower);

    vector<string> violaciones = encontrarSubcadenas(mensaje, palabras_invalidas);

    cout << "\n--- Resultado de la Validación ---" << endl;

    if (!violaciones.empty()) {
        cout << "MENSAJE INVÁLIDO: Viola las políticas de comunicación." << endl;
        cout << "Indicios detectados:" << endl;
        
        for (const string& palabra : violaciones) {
            cout << "- " << palabra << endl;
        }
    } else {
        cout << "Mensaje Válido." << endl;
    }

    return 0;
}