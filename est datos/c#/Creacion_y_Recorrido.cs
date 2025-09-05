using System;
using System.Runtime.InteropServices;
class program {
    static void Main(string[] args)
    {
        int tam;

        Console.WriteLine("Ingrese el tamaño del arreglo:");
        tam = int.Parse(Console.ReadLine());

        int[] arreglo = new int[tam];

        Console.WriteLine("Ingrese los elementos del arreglo:");

        for (int i = 0; i < tam; i++)
        {
            Console.Write($"Elemento {i + 1}: ");
            arreglo[i] = int.Parse(Console.ReadLine());

        }

        Console.WriteLine("Los elementos del arreglo son:");

        for (int i = 0; i < tam; i++) { 
            Console.WriteLine("Elemento # " + (i+1) + ": " + arreglo[i]);

        }
    }
}