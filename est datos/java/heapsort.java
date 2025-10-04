public class heapsort {

    public static void heapify(int arr[], int n, int i) {
        int masGrande = i;          // Inicialmente, asumimos que la raíz es el más grande
        int izquierda = 2 * i + 1;  // Índice del hijo izquierdo
        int derecha = 2 * i + 2;    // Índice del hijo derecho

        // Si el hijo izquierdo existe y es mayor que el más grande hasta ahora
        if (izquierda < n && arr[izquierda] > arr[masGrande]) {
            masGrande = izquierda;
        }

        // Si el hijo derecho existe y es mayor que el más grande hasta ahora
        if (derecha < n && arr[derecha] > arr[masGrande]) {
            masGrande = derecha;
        }

        // Si el más grande no es la raíz, intercambiamos y seguimos ajustando recursivamente
        if (masGrande != i) {
            // Intercambio (Swap) manual
            int temp = arr[i];
            arr[i] = arr[masGrande];
            arr[masGrande] = temp;

            // Llamada recursiva para hacer heapify en el subárbol afectado
            heapify(arr, n, masGrande);
        }
    }


    public static void heap_sort(int arr[]) {
        int n = arr.length;

        // Paso 1: Construir un heap máximo (Reorganizar el array)
        // El bucle va desde el último nodo no hoja (n/2 - 1) hasta el 0 (la raíz)
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        // Paso 2: Extraer elementos uno por uno del heap
        for (int i = n - 1; i > 0; i--) {
            // Mover la raíz (el elemento más grande) al final del array
            // Intercambio (Swap) manual de arr[0] con arr[i]
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            // Llamar a heapify en el heap reducido (el tamaño es 'i')
            heapify(arr, i, 0);
        }
    }


    public static void imprimirArray(int arr[]) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]);
            if (i < arr.length - 1) {
                System.out.print(", ");
            }
        }
    }

    // Bloque principal (equivalente a 'if __name__ == "__main__":')
    public static void main(String args[]) {
        int lista[] = {12, 11, 13, 5, 6, 7};

        System.out.print("Array antes del ordenamiento: ");
        imprimirArray(lista);
        System.out.println();

        heap_sort(lista);

        System.out.print("\nArray despues del ordenamiento: ");
        imprimirArray(lista);
        System.out.println();
    }
}