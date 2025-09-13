using System;
using System.ComponentModel.Design;
class Program{
    static void Main(string[] args)
    {
        Console.WriteLine("Ingrese el tamaño del arreglo:");
        int tam = int.Parse(Console.ReadLine());

        int[] arr = new int[tam];

        for (int i = 0; i < tam; i++) {
            arr[i] = new Random().Next(1, 100);
        }

        Console.WriteLine("Arreglo original: " + string.Join(", ", arr));

        bool swapped = true;

        do {
            swapped = false;
            for (int i = 0; i < tam - 1; i++) {
                if (arr[i] > arr[i + 1]) {
                    int temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                    swapped = true;
                }
            }


        } while (swapped == true);

        Console.WriteLine("Arreglo ordenado: " + string.Join(", ", arr));

    }
}