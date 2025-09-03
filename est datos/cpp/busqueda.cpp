#include <iostream>
using namespace std;

int buscar(int arr[], int tam, int dato) {
for (int i = 0 ; i<tam ; i++){
    if (arr[i] == dato)
    {
        return i;
    }
}
return -1;
}


int main(int argc, char const *argv[])
{
    int tam, dato, j;
    cout << "De que tamaño desea su arreglo?" << endl;
    cin >> tam;

    cout << "Se lleno el arreglo con numeros random desde 1 hasta 100" << endl;

    int arr[tam];

    for (int i = 0; i< tam ; i++){
        arr[i] = rand() % 100 + 1;
    }


    do
    {
        
    cout << "Ingrese el numero que desea buscar dentro del arreglo: " << endl;
    cin >> dato;

    int position = buscar(arr, tam, dato);

         if (position != -1){
        cout << "El numero " << dato << " se encuentra en la posicion " << (position+1) << " del arreglo." << endl;
    } else{
        cout << "El numero " << dato << " no se encuentra en el arreglo." << endl;
    }

    
    cout << "Desea buscar otro numero? (1 para si, 0 para no)" << endl;
    cin >> j;

    } while (j == 1);
    
    cout << "Gracias por participar!" << endl;

    return 0;
}


