using System;
using System.Linq; 

public class RadixSort
{
    static void CountingSort(int[] arr, int exp1)
    {
        int n = arr.Length;
        int[] output = new int[n]; 
        int[] count = new int[10]; 

        for (int i = 0; i < n; i++)
        {
            int index = arr[i] / exp1;
            count[index % 10]++;
        }

        for (int i = 1; i < 10; i++)
        {
            count[i] += count[i - 1];
        }

        for (int i = n - 1; i >= 0; i--)
        {
            int index = arr[i] / exp1;
            output[count[index % 10] - 1] = arr[i];
            count[index % 10]--;
        }

        for (int i = 0; i < n; i++)
        {
            arr[i] = output[i];
        }
    }

    static void RadixSortAlgorithm(int[] arr)
    {
        if (arr.Length == 0) return;

        int max1 = arr.Max();

        for (int exp = 1; max1 / exp > 0; exp *= 10)
        {
            CountingSort(arr, exp);
        }
    }

    public static void Main(string[] args)
    {
        int[] arr = { 10, 34, 21, 45, 78, 12, 90, 34 };
        Console.WriteLine("Antes de ordenar: [" + string.Join(", ", arr) + "]");
        RadixSortAlgorithm(arr); 
        Console.WriteLine("Despues de ordenar: [" + string.Join(", ", arr) + "]");
    }
}