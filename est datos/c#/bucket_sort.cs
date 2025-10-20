using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
    // Función de ordenamiento por inserción
    public static void InsertionSort(List<float> bukt)
    {
        for (int j = 1; j < bukt.Count; j++) // Iterar desde el segundo elemento
        {
            float val = bukt[j]; // Elemento actual a insertar
            int k = j - 1; // Índice del elemento anterior
            // Mover elementos mayores hacia la derecha
            while (k >= 0 && bukt[k] > val)
            {
                bukt[k + 1] = bukt[k]; // Desplazar elemento
                k -= 1; // Mover al siguiente elemento a la izquierda
            }
            bukt[k + 1] = val; // Insertar el elemento en su posición correcta
        }
    }

    // Función principal de ordenamiento bucket
    public static void BucketSort(List<float> inputArr)
    {
        int s = inputArr.Count; // Número de buckets
        // Crear lista de buckets vacíos
        List<List<float>> bucketArr = new List<List<float>>(s);
        for (int i = 0; i < s; i++)
        {
            bucketArr.Add(new List<float>());
        }

        // Colocar cada elemento en su bucket correspondiente
        foreach (float j in inputArr) // Iterar sobre cada elemento del arreglo
        {
            int bi = (int)(s * j); // Índice del bucket
            // Asegurar que el índice no se salga (en caso de que j sea 1.0)
            if (bi == s)
            {
                bi = s - 1;
            }
            bucketArr[bi].Add(j); // Añadir elemento al bucket
        }

        // Ordenar cada bucket individualmente
        foreach (var bukt in bucketArr) // Iterar sobre cada bucket
        {
            InsertionSort(bukt); // Ordenar el bucket
        }

        // Concatenar todos los buckets ordenados en el arreglo original
        int idx = 0; // Índice para el arreglo original
        foreach (var bukt in bucketArr) // Iterar sobre cada bucket
        {
            foreach (float j in bukt) // Iterar sobre cada elemento del bucket
            {
                inputArr[idx] = j; // Colocar elemento en el arreglo original
                idx += 1; // Mover al siguiente índice
            }
        }
    }

    // Ejemplo de uso
    public static void Main(string[] args)
    {
        List<float> inputArr = new List<float> 
        { 
            0.77f, 0.16f, 0.38f, 0.25f, 0.71f, 0.93f, 0.22f, 0.11f, 0.24f, 0.67f 
        };

        Console.WriteLine("Arreglo antes de ordenar:");
        Console.WriteLine(string.Join(", ", inputArr));

        BucketSort(inputArr);

        Console.WriteLine("Arreglo después de ordenar:");
        Console.WriteLine(string.Join(", ", inputArr));
    }
}