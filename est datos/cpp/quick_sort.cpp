#include <iostream>

using namespace std;
void imprimir(int arr[], int tam){
    for(int i = 0; i < tam; i++){
        cout << " " << arr[i];
    }
    cout << '\n';
}
void cambiar(int (&arr)[], int j, int k){
    swap(arr[j],arr[k]);
}

int particion(int (&arr)[],int l, int h){
    int pivote = arr[h];

    int j=l-1;

    for (int k= l; k < h; k++){
        if (arr[k] <= pivote){
            j+=1;
            cambiar(arr,j,k);
        }
    }
    cambiar(arr,j+1,h);
    return j+1;
}

void quicksort(int (&arr)[],int l,int h){
    if(l<h){
        int pivote = particion(arr,l,h);

        quicksort(arr,l,pivote-1);
        quicksort(arr,pivote+1,h);
        
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {10,7,9,8,1,5};
    int tam = sizeof(arr) / sizeof(arr[0]);

    cout << "Arreglo antes del ordenamiento: \n";
    imprimir(arr, tam);
    quicksort(arr,0,tam-1);
    cout << "Arreglo despues del ordenamiento: \n";
    imprimir(arr,tam);
    return 0;
}
