#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int arr[10];
    int ac{0};
    for(int i=0 ; i < 10; i++){
        cout << "Ingrese el dato para la posicion (" << (i+1) << "): \n";
        int num;
        cin >> num;
        if(num < 0){
            break;
        }
        arr[i] = num;
        ac++;
    }

    cout << "Su arreglo es: ";
    cout << "[";
    for(int i= 0; i<ac ; i++){
        cout << arr[i];
        if(i<ac-1){
            cout << ",";
        }
    }
    cout << "]";
    return 0;
}
