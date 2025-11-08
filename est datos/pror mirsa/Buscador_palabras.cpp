#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include <cctype>    
#include <regex>


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

bool contiene_numero(const string& str) {

    string num = regex_replace(str, regex(R"(\D)"), "");

    return regex_search(num, regex("\\d{5}"));
}

int main() {
    vector<string> palabras_invalidas = {
        "whatsapp", "wa.me", "contáctame", "contactar", "contacto",
        "email", "correo", "arroba", "@", "gmail", "hotmail", "outlook",
        "punto com", ".com", "punto mx", ".mx", "punto edu", ".edu",
        "localizarme", "teléfono", "celular", "llámame", "llamar", "mi numero",
        "ig", "instagram", "facebook", "fb", "telegram", "trato por fuera",
        "sesenta", "ochenta", "llamame", "mensaje privado", "mp", "seis", "siete", "ocho", "nueve", "cero", "uno", "dos",
    };

    string mensaje;
    cout << "Escribe tu mensaje para Mercado Libre:" << endl;
    getline(cin, mensaje); 

    transform(mensaje.begin(), mensaje.end(), mensaje.begin(), ::tolower);

    vector<string> palabras_proh = encontrarSubcadenas(mensaje, palabras_invalidas);

    cout << "\n--- Resultado de la Validación ---" << endl;

    if (!palabras_proh.empty() ) {
        cout << "MENSAJE INVÁLIDO: Viola las políticas de comunicación." << endl;
        cout << "Indicios detectados:" << endl;
        
        for (const string& palabra : palabras_proh) {
            cout << "- " << palabra << endl;
        }
    }else if (contiene_numero(mensaje))
    {
        cout << "MENSAJE INVÁLIDO: Viola las políticas de comunicación." << endl;
        cout << "Indicios detectados:" << endl << "- Contiene número de teléfono.";
    } 
    else {
        cout << "Mensaje Valido." << endl;
    }

    return 0;
}