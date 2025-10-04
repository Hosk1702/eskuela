using System;

public class heapsort
{
   
    void Heapify(int[] arr, int n, int i)
    {
        int masGrande = i;          // Inicialmente, asumimos que la raíz es el más grande
        int izquierda = 2 * i + 1;  // Índice del hijo izquierdo
        int derecha = 2 * i + 2;    // Índice del hijo derecho

        // Si el hijo izquierdo existe y es mayor que el más grande hasta ahora
        if (izquierda < n && arr[izquierda] > arr[masGrande])
        {
            masGrande = izquierda;
        }

        // Si el hijo derecho existe y es mayor que el más grande hasta ahora
        if (derecha < n && arr[derecha] > arr[masGrande])
        {
            masGrande = derecha;
        }

        // Si el más grande no es la raíz, intercambiamos y seguimos ajustando recursivamente
        if (masGrande != i)
        {
            // Intercambio (Swap) manual
            int temp = arr[i];
            arr[i] = arr[masGrande];
            arr[masGrande] = temp;

            // Llamada recursiva
            Heapify(arr, n, masGrande);
        }
    }

  
    void Heapsort(int[] arr)
    {
        int n = arr.Length;

        // Paso 1: Construir un Max Heap
        // Itera desde el último nodo no hoja hacia la raíz
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            Heapify(arr, n, i);
        }

        // Paso 2: Extraer elementos uno por uno del heap
        for (int i = n - 1; i > 0; i--)
        {
            // Mover la raíz (el elemento más grande) al final del array
            // Intercambio de arr[0] con arr[i]
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            // Llamar a Heapify en el heap reducido (el tamaño es 'i')
            Heapify(arr, i, 0);
        }
    }

    // Método auxiliar para imprimir el array
    void ImprimirArray(int[] arr)
    {
        Console.Write("[");
        for (int i = 0; i < arr.Length; i++)
        {
            Console.Write(arr[i]);
            if (i < arr.Length - 1)
            {
                Console.Write(", ");
            }
        }
        Console.Write("]");
    }

    // Bloque principal (el punto de entrada de la aplicación)
    public static void Main(string[] args)
    {
        int[] lista = { 12, 11, 13, 5, 6, 7 };
        
        // Creamos una instancia para llamar a los métodos

        Console.Write("Array antes del ordenamiento: ");
        ImprimirArray(lista);
        Console.WriteLine();

        Heapsort(lista);

        Console.Write("\nArray despues del ordenamiento: ");
        ImprimirArray(lista);
        Console.WriteLine();
    }
}