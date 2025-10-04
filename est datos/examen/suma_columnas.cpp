#include <iostream>
#include <limits>
using namespace std;


int main(int argc, char const *argv[])
{
    int matriz[3][3];
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++)
        {
            matriz[i][j] = 0;
        }
    }

    int sumac1{0};
    int sumac2{0};
    int sumac3{0};

    for (int i = 0; i < 3; i++){
         for (int  j = 0; j < 3; j++){
            int dato{0};
            cout << "Ingrese un valor para la posicion " << (i+1) << "," << (j+1) << ": \n";
            cin >> dato;
            if (cin.fail()){
            cout << "Error ingrese un numero entero \n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //limpia la entrada del cin
            continue;
            } else {
            matriz[i][j] = dato;}
        }
    }

     for (int i = 0; i < 3; i++){
         
        sumac1 = sumac1 + matriz[i][0];
            
        sumac2 = sumac2 + matriz[i][1];
            
        sumac3 = sumac3 + matriz[i][2];
            
    }

    cout << "El resultado de la suma de la columna 1 es: " << sumac1 << '\n';
    cout << "El resultado de la suma de la columna 2 es: " << sumac2 << '\n';
    cout << "El resultado de la suma de la columna 3 es: " << sumac3 << '\n';

    return 0;
}
