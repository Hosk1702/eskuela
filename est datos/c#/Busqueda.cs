using System;
using System.ComponentModel.Design;
class Program{
    static int buscar(int[] arr, int dato, int tam)
    {
        for (int i = 0; i < tam; i++) {
            if (arr[i] == dato) {
                return (i);
            }
        }
        return (-1);
    }
    static void Main(string[] args)
    {
        int tam;

        Console.WriteLine("Ingrese el tamaño del arreglo:");
        tam = Convert.ToInt32(Console.ReadLine());

        int[] arr = new int[tam];

        for (int i = 0; i < tam; i++)
        {
            arr[i] = new Random().Next(1, 100);
        }

        Console.WriteLine("Arreglo generado con numeros random entre 1 y 100:");
        
        int j;

        do
        {
            Console.WriteLine("Ingrese el dato que desea buscar dentro del arreglo:");
            int dato = Convert.ToInt32(Console.ReadLine());

            int resul = buscar(arr, dato, tam);

            if (resul != -1)
            {
                Console.WriteLine("El dato se encuentra en la posicion: " + resul);

            }
            else {
                Console.WriteLine("El dato no se encuentra en el arreglo");
            }

            Console.WriteLine("Desea buscar otro numero? (1: si / 2: no)");
            j = Convert.ToInt32(Console.ReadLine());

        } while (j == 1);

    }
}