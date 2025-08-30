#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int tamaño;

    cout << "De que tamaño desea su arreglo?";
    cin >> tamaño;

    int arr[tamaño];

    cout << "Vamos a llenar el arreglo";
    for (int i=0 ; i<tamaño ; i++){
        cout << "Ingrese el elemento # " << i+1 << ":";
        cin >> arr[i];
    }

    for (int i=0 ; i< tamaño ; i++){
        cout << arr[i];
    }

    return 0;
}