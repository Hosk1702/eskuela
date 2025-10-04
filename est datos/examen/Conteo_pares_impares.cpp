#include<iostream>
#include <limits>

using namespace std;

int main(int argc, char const *argv[])
{
    int arr[9];
    int par{0}, impar{0};
    for(int i = 0; i < 10 ; i++){
        int dato{0};
        cout << "Ingrese el valor para la posicion " << (i+1) <<": \n";
        cin >> dato;
        if (cin.fail()){
            i--;
            cout << "Error ingrese un numero entero \n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //limpia la entrada del cin
            continue;
        } else {
            arr[i] = dato;

        }
    }

    for (int i = 0 ; i < 10 ; i++){
        int mod{0};
        mod = arr[i] % 2;
        if (mod == 1){
            impar +=1;
        } else {
            par += 1;
        }
    }

    cout << "Total de numeros pares: " << par << '\n';
    cout << "Total de numeros impares: " << impar << '\n';


    return 0;
}
