#ifndef unidad2_H
#define unidad2_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include <cctype>    
#include <regex>
using namespace std;

class unidad2 {

public:
    void Menu_unidad_2();;

private:
    void act1();
    string a1_ver_datos(string contrasena);
    void a1_obt_datos(string& nombre, string& contrasena, string& confirmacion);
    void act2();
    int a2_cant_pal(string palabra);
    int a2_getletter(string palabra, char letra);
    int a2_numletters(string palabra);
    void act3();
    bool a3_contiene_numero(const string& str);
    vector<string> a3_encontrarSubcadenas(const string& text, const vector<string>& wordsToFind);
};

#endif // unidad2_H