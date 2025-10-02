public class MergeSort {
    
    void merge(int a[], int l, int m, int r) {
        int a1 = m - l + 1; // tamaño del primer sub array (Left)
        int a2 = r - m;     // tamaño del segundo sub array (Right)

        // Crear arrays temporales
        int L[] = new int[a1];
        int R[] = new int[a2];

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
            if (L[i] <= R[j]) { // comparar los elementos
                a[k] = L[i];    // copiar el elemento más pequeño
                i++;
            } else {            
                a[k] = R[j];    
                j++;      
            }
            k++; 
        }

        // copiar los elementos restantes de L[] en caso de haber alguno
        while (i < a1) {
            a[k] = L[i]; 
            i++;
            k++;
        }

        // copiar los elementos restantes de R[] en caso de haber alguno
        while (j < a2) { 
            a[k] = R[j]; 
            j++;
            k++;
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

    // Código para probar la funcionalidad de mergesort
    public static void main(String args[]) {
        // Definimos el array
        int a[] = {39, 28, 44, 11, 53, 21, 1, 5, 12, 3};
        int s = a.length;
        
        // Creamos una instancia de la clase para poder llamar a los métodos
        MergeSort ob = new MergeSort();

        System.out.println("Antes de ordenar el arreglo:");
        for (int j = 0; j < s; j++) {
            System.out.print(a[j] + " ");
        }
        System.out.println();

        // Llamar a mergesort
        ob.mergesort(a, 0, s - 1);

        System.out.println("Despues de ordenar el arreglo:");
        for (int j = 0; j < s; j++) {
            System.out.print(a[j] + " ");
        }
        System.out.println();
    }
}