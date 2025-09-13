#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "De que tamaño desea su arreglo? " << endl;
    int tamaño;
    cin >> tamaño;

    int arr[tamaño];

    for (int i = 0 ; i<tamaño ; i++){
        arr[i] = rand() % 50;
    }

    cout << "El arreglo desordenado es: " << endl;
    for (int i = 0 ; i<tamaño ; i++){
        cout << arr[i] << " ";
    }

   bool swaped;
   do{
        swaped = false;
        for (int j = 0 ; j < tamaño - 1; j++){
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swaped = true;
                
            }
        }
        if (swaped == false){
            break;
        }
    }while (swaped == true);
    
    cout << "\nEl arreglo ordenado es: " << endl;
    for (int i = 0 ; i<tamaño ; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
