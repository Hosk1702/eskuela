#include <iostream>
#include <utility>

using namespace std;

void imprimir(int arr[]){
    for (int i= 0; i < 5; i++){
        cout << arr[i] << " ";
    }
}

void seleccion(int (&arr)[]){
    for( int i = 0; i < 5; i++){
        int peque = i;

        for (int j= i+1; j < 5; j++){
            if (arr[peque] > arr[j]){
                peque = j;
            }
        }
        swap(arr[i], arr[peque]);
        imprimir(arr);
        cout << '\n'; 
    }

}




int main(int argc, char const *argv[])
{
    int arr[] = {34,76,3,23,6};

    cout << "Arreglo sin ordenar: \n";
    imprimir(arr);
    seleccion(arr);
    cout << "\nArreglo ordenado: \n";
    imprimir(arr);
    return 0;
}