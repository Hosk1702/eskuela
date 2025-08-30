#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int tamaño;

    cout << "De que tamaño desea su arreglo? endl";
    cin >> tamaño;
    cin.ignore(); // Limpiar el buffer de entrada

    vector<string> arr(tamaño);

    cout << "Vamos a llenar el arreglo" << "\n\n";

    for (int i=0 ; i<tamaño ; i++){
        cout << "Ingrese el elemento # " << i+1 << ":" << endl;
        getline(cin >> ws, arr[i]);
    }

    for (int i=0 ; i< tamaño ; i++){
        cout << arr[i] << endl;
        cout << endl;
    }

    return 0;
}