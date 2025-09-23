using System;
using System.ComponentModel.Design;
class Program{
    static void insercion(ref int[] arr)
    {
        for (int i = 0; i < 5; i++)
        {
            int temp = arr[i];
            int j = i - 1;

            while (j >= 0 && temp < arr[j])
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = temp;
        }
    }

    static void imprimir(int[] arr)
    {
        for (int i = 0; i < 5; i++)
        {
            Console.WriteLine(arr[i] + string.Join(","));
        }
    }

    static void Main(string[] args)
    {
            int[] arr = {34,76,3,23,6};
            Console.WriteLine("Arreglo sin ordenar: \n");
            imprimir(arr);
            insercion(ref arr);
            Console.WriteLine("Arreglo ordenado: \n");
            imprimir(arr);
 
    }
}