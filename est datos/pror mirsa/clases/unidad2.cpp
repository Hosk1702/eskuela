#include "unidad2.h"
#include "utils.h"
#include <iostream>
#include <cctype>
#include <limits>
#include <string>
#include <cstdlib>

using namespace std;

void unidad2::Menu_unidad_2(){
        int opcion{0};
    do{
        system("cls"); // Limpia pantalla
        cout << "\n========================================" << endl;
        cout << "            MENU UNIDAD 1              " << endl;
        cout << "========================================" << endl;
        cout << "1. Practica No. 1" << endl;
        cout << "2. Practica No. 2" << endl;
        cout << "3. Actividad No. 3" << endl;
        cout << "0. Regresar al Menu Principal" << endl;
        cout << "========================================" << endl;
        opcion = pedirOpcion(0,7);

        switch (opcion)
        {
        case 1:
            act1();
            break;
        case 2:
            act2();
            break;
        case 3:
            act3();
            break;
        default:
            break;
        }


    }while (opcion != 0);
}

void unidad2::a1_obt_datos(string& usuario, string& contrasena, string& confirmacion) {
    cout << "--- Creación de Cuenta ---" << endl;

    cout << "Introduce tu nombre de usuario: ";
    getline(cin, usuario);

    cout << "Introduce tu contraseña: ";
    getline(cin, contrasena);

    cout << "Confirma tu contraseña: ";
    getline(cin, confirmacion);
}

string unidad2::a1_ver_datos(string contrasena) {

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


void unidad2::act1() {
    string nombreUsuario;
    string contrasena;
    string confirmacionContrasena;

    a1_obt_datos(nombreUsuario, contrasena, confirmacionContrasena);

    cout << "\n--- Verificación ---" << endl;

    if (contrasena != confirmacionContrasena) {
        cout << "Error: Las contraseñas no coinciden." << endl;
        system("pause");
        return;
    }

    cout << "¡Contraseñas coinciden!" << endl;

    string nivel = a1_ver_datos(contrasena);

    cout << "Hola, " << nombreUsuario << "." << endl;
    cout << "Tu contraseña tiene un nivel de seguridad: " << nivel << endl;
    system("pause");
}

int unidad2::a2_cant_pal(string palabra) {
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

int unidad2::a2_getletter (string palabra, char letra){
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

int unidad2::a2_numletters(string palabra){
    int n = palabra.length();
    int num_letras = 0;

    for (int i = 0; i < n; i++) {
        if (isalpha(palabra[i])) {
            num_letras++;
        }
    }

    return num_letras;
}

void unidad2::act2() {
    string palabra;
    char letra;
    cout << "Ingrese una string: \n";
    getline(cin, palabra);

    cout << "Ingrese una letra: \n";
    cin >> letra;

    cout << "La cantidad de palabras es: " << a2_cant_pal(palabra) << endl;
    cout << "La cantidad de letras es: " << a2_numletters(palabra) << endl;
    cout << "La cantidad de veces que aparece la letra " << letra << " es: " << a2_getletter(palabra, letra) << endl;
    
    system("pause");
}

vector<string> a3_encontrarSubcadenas(const string& text, const vector<string>& wordsToFind) {
    
    vector<string> encontradas;
    
    for (const string& palabra : wordsToFind) {
        
        if (text.find(palabra) != string::npos) {
            encontradas.push_back(palabra);
        }
    }
    
    return encontradas;
}

bool unidad2::a3_contiene_numero(const string& str) {

    string num = regex_replace(str, regex(R"(\D)"), "");

    return regex_search(num, regex("\\d{5}"));
}

void unidad2::act3() {
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

    vector<string> palabras_proh = a3_encontrarSubcadenas(mensaje, palabras_invalidas);

    cout << "\n--- Resultado de la Validación ---" << endl;

    if (!palabras_proh.empty() ) {
        cout << "MENSAJE INVÁLIDO: Viola las políticas de comunicación." << endl;
        cout << "Indicios detectados:" << endl;
        
        for (const string& palabra : palabras_proh) {
            cout << "- " << palabra << endl;
        }
    }else if (a3_contiene_numero(mensaje))
    {
        cout << "MENSAJE INVÁLIDO: Viola las políticas de comunicación." << endl;
        cout << "Indicios detectados:" << endl << "- Contiene número de teléfono.";
    } 
    else {
        cout << "Mensaje Valido." << endl;
    }
    system("pause");
}



