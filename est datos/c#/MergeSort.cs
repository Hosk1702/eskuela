using System;
using System.Linq; // Necesario para la función String.Join

public class MergeSort
{
    void Merge(int[] a, int l, int m, int r)
    {
        int a1 = m - l + 1; // tamaño del primer sub array (Left)
        int a2 = r - m;     // tamaño del segundo sub array (Right)

        // Crear arrays temporales
        int[] L = new int[a1];
        int[] R = new int[a2];

        // copiar los datos a los arrays temporales L y R
        for (int i = 0; i < a1; i++)
        {
            L[i] = a[l + i];
        }
        for (int j = 0; j < a2; j++)
        {
            R[j] = a[m + 1 + j];
        }

        int i = 0; // indice del primer sub array (L)
        int j = 0; // indice del segundo sub array (R)
        int k = l; // indice inicial del subarray mezclado (a)

        // recorrer ambos arrays y mezclar
        while (i < a1 && j < a2)
        {
            if (L[i] <= R[j])
            { // comparar los elementos
                a[k] = L[i];    // copiar el elemento más pequeño
                i++;
            }
            else
            {
                a[k] = R[j];
                j++;
            }
            k++;
        }

        // copiar los elementos restantes de L[] en caso de haber alguno
        while (i < a1)
        {
            a[k] = L[i];
            i++;
            k++;
        }

        // copiar los elementos restantes de R[] en caso de haber alguno
        while (j < a2)
        {
            a[k] = R[j];
            j++;
            k++;
        }
    }

    public void Mergesort(int[] a, int l, int r)
    {
        if (l < r)
        {
            // calcular el punto medio para evitar desbordamiento
            int m = l + (r - l) / 2;

            // ordenar la primera y segunda mitad del arreglo
            Mergesort(a, l, m);
            Mergesort(a, m + 1, r);

            // mezclar las dos mitades
            Merge(a, l, m, r);
        }
    }

    // Código para probar la funcionalidad de mergesort
    public static void Main(string[] args)
    {
        // Definimos el array
        int[] a = {39, 28, 44, 11, 53, 21, 1, 5, 12, 3};
        int s = a.Length;

        // Imprimir array antes de ordenar
        Console.WriteLine("Antes de ordenar el arreglo:");
        Console.WriteLine(string.Join(" ", a));

        // Llamar a mergesort
        ob.Mergesort(a, 0, s - 1);

        // Imprimir array después de ordenar
        Console.WriteLine("\nDespues de ordenar el arreglo:");
        Console.WriteLine(string.Join(" ", a));
    }
}