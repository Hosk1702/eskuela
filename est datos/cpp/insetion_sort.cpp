#include <iostream>

using namespace std;
void insercion(int (&arr)[]){
    for (int i = 1 ; i < 5 ; i++){
        int temp = arr[i];
        int j = i-1;
        while (j>=0 && temp < arr[j]){
            arr[j+1] = arr[j];
            j= j-1;
        }
        arr[j+1] = temp;
    }


}

void imprimir(int arr[]){
    for (int i= 0; i < 5; i++){
        cout << arr[i] << " ";
    }
}


int main(int argc, char const *argv[])
{
    int arr[] = {34,76,3,23,6};

    cout << "Arreglo sin ordenar: \n";
    imprimir(arr);
    insercion(arr);
    cout << "\nArreglo ordenado: \n";
    imprimir(arr);
    return 0;
}
