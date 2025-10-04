#include <iostream>

using namespace std;


void heapify(int arr[], int n, int i) {
    int mas_grande = i;
    int izquierda = 2 * i + 1; // índice del hijo izquierdo
    int derecha = 2 * i + 2;   // índice del hijo derecho

    // Si el hijo izquierdo existe y es mayor que el actual 'más grande'
    if (izquierda < n && arr[izquierda] > arr[mas_grande]) {
        mas_grande = izquierda;
    }

    // Si el hijo derecho existe y es mayor que el actual 'más grande'
    if (derecha < n && arr[derecha] > arr[mas_grande]) {
        mas_grande = derecha;
    }

    // Si el mayor no es la raíz, se intercambia y se ajusta recursivamente
    if (mas_grande != i) {
        // Intercambio manual (simulando arr[i], arr[mas_grande] = arr[mas_grande], arr[i])
        int temp = arr[i];
        arr[i] = arr[mas_grande];
        arr[mas_grande] = temp;

        heapify(arr, n, mas_grande);
    }
}

void heapsort(int arr[], int n) {
    // Paso 1: Construir un heap máximo
    // Itera desde el último nodo no hoja hacia la raíz (n/2 - 1 hasta 0)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Paso 2: Extraer elementos uno por uno del heap
    for (int i = n - 1; i > 0; i--) {
        // Mover la raíz (el elemento más grande) al final del array
        // Intercambio manual: arr[0] con arr[i]
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Llamar a heapify en el heap reducido (el tamaño es 'i')
        heapify(arr, i, 0);
    }
}

void imprimir_array(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
}

// Función principal
int main() {
    // Definición de un array de estilo C
    int lista[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(lista) / sizeof(lista[0]); // Calcular el tamaño del array

    cout << "Array antes del ordenamiento: ";
    imprimir_array(lista, n);
    cout << endl;

    heapsort(lista, n);

    cout << "\nArray despues del ordenamiento: ";
    imprimir_array(lista, n);
    cout << endl;

    return 0;
}