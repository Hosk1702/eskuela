using System;
using System.ComponentModel.Design;
class Program{
    static void seleccion(ref int[] arr)
    {
        for (int i = 0; i < arr.Length; i++)
        {
            int peque = i;

            for (int j = 0; j < arr.Length; j++) {
                if (arr[peque] > arr[j]) {
                    peque = j;
                }
            }
            int temp = arr[peque];
            arr[peque] = arr[i];
            arr[i] = temp;
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
            seleccion(ref arr);
            Console.WriteLine("Arreglo ordenado: \n");
            imprimir(arr);
 
    }
}

