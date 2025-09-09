using System;
using System.ComponentModel.Design;
class Program{
    static void Main(string[] args)
    {
        Console.WriteLine("Ingrese el numero de filas:");
        int filas = int.Parse(Console.ReadLine());
        Console.WriteLine("Ingrese el numero de columnas:");
        int columnas = int.Parse(Console.ReadLine());

        int[,] matriz = new int[filas, columnas];

        Console.WriteLine("Ingrese los elementos de la matriz:");
        for (int i  = 0; i  < filas; i ++)
        {
            for (int j = 0; j < columnas; j++)
            {
                Console.Write($"Ingrese el elemento par la posicion [{i},{j}]: ");
                matriz[i, j] = int.Parse(Console.ReadLine());
            }
        }
        int opcion;
        do
        {
            Console.WriteLine("De que manera desea recorrer la matriz:");
            Console.WriteLine("1. Por filas y columnas");
            Console.WriteLine("2. Por columnas y filas");
            opcion = int.Parse(Console.ReadLine());

            if (opcion == 1)
            {
                Console.WriteLine("Recorrido por filas y columnas:");
                for (int i = 0; i < filas; i++)
                {
                    for (int j = 0; j < columnas; j++)
                    {
                        Console.WriteLine(matriz[i, j]);
                    }
                    Console.WriteLine('\n');
                }
            }
            else if (opcion == 2)
            {
                Console.WriteLine("Recorrido por columas y filas:");
                for (int i = 0; i < columnas; i++)
                {
                    for (int j = 0; j < filas; j++)
                    {
                        Console.WriteLine(matriz[j, i]);
                    }
                    Console.WriteLine('\n');
                }
            }
            else { 
                Console.WriteLine("Ingresa una opcion valida!!");
            }

        } while (opcion != 1 && opcion != 2);
        

        

    }
}