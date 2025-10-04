#include <iostream>

using namespace std;

int leernumero(int &x){
    
    cout << "Por favor ingrese un numero: ";
    cin >> x;

    return x;
}

void escribir_respuesta(int x){
    cout << "La suma es: " << x;

}
int main(int argc, char const *argv[])
{
    int x{0};
   
    x = x + leernumero(x);
    escribir_respuesta(x);
    return 0;
}
