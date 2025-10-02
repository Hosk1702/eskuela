#include <iostream>

using namespace std;

void merge(int a[], int l, int m, int r) {
    int a1 = m - l + 1; // tamaño del primer sub array
    int a2 = r - m;     // tamaño del segundo sub array

    int L[a1]; 
    int R[a2];

    // copiar los datos a los arrays temporales L y R
    for (int i = 0; i < a1; i++) {
        L[i] = a[l + i];
    }
    for (int j = 0; j < a2; j++) {
        R[j] = a[m + 1 + j];
    }

    int i = 0; // indice del primer sub array (L)
    int j = 0; // indice del segundo sub array (R)
    int k = l; // indice inicial del subarray mezclado (a)

    // recorrer ambos arrays y mezclar
    while (i < a1 && j < a2) {
        if (L[i] <= R[j]) { 
            a[k] = L[i]; 
            i = i + 1; 
        } else {            
            a[k] = R[j];    
            j = j + 1;      
        }
        k = k + 1; 
    }

    // copiar los elementos restantes de L[] en caso de haber alguno
    while (i < a1) {
        a[k] = L[i]; 
        i = i + 1;
        k = k + 1;
    }

    // copiar los elementos restantes de R[] en caso de haber alguno
    while (j < a2) { 
        a[k] = R[j]; 
        j = j + 1;
        k = k + 1;
    }
}

void mergesort(int a[], int l, int r) {
    if (l < r) {
        // calcular el punto medio para evitar desbordamiento
        int m = l + (r - l) / 2;

        // ordenar la primera y segunda mitad del arreglo
        mergesort(a, l, m);
        mergesort(a, m + 1, r);

        // mezclar las dos mitades
        merge(a, l, m, r); 
    }
}

// Codigo para probar la funcionalidad de mergesort
int main() {
    // Definimos el array estático y su tamaño.
    int a[] = {39, 28, 44, 11, 53, 21, 1, 5, 12, 3};
    // Calcular el tamaño: (tamaño total en bytes / tamaño de un elemento)
    int s = sizeof(a) / sizeof(a[0]); 

    cout << "Antes de ordenar el arreglo: " << endl;
    for (int j = 0; j < s; j++) {
        cout << a[j] << " ";
    }
    cout << endl;

    // Llamar a mergesort
    mergesort(a, 0, s - 1);

    cout << "Despues de ordenar el arreglo: " << endl;
    for (int j = 0; j < s; j++) {
        cout << a[j] << " ";
    }
    cout << endl;

    return 0;
}