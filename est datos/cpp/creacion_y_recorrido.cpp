#include <iostream>


using namespace std;

int main(int argc, char const *argv[])
{
    int tamaño;
    cout << "De que tamaño desea su arreglo? " << endl;
    cin >> tamaño;
    cin.ignore(); // Limpiar el buffer de entrada

    int arr[tamaño];

    cout << "Vamos a llenar el arreglo" << endl;
for (int i = 0; i< tamaño ; i++){
    cout << "Ingrese el elemento # " << (i+1) << ":" << endl;
    cin >> arr[i];
}

cout << "Los elementos del arreglo son: " << endl;

for (int i =0; i< tamaño ; i++){
    cout << "Elemento #" << (i+1) << ": " << arr[i] << endl;
}


    return 0;
}
