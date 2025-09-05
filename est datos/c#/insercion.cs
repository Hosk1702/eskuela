    using System;
using System.ComponentModel.Design;
class Program{
    static void Main(string[] args)
    {
        int[] arr = [123,31,2,21,423,56];
        
        Console.WriteLine("Se tiene el arreglo: " + string.Join(",",arr));

        Console.WriteLine("Ingrese el dato que desea insertar:");
        int dato = Convert.ToInt32(Console.ReadLine());
        Console.WriteLine("Ingrese la posicion en la que desea insertar el dato:");
        int pos = Convert.ToInt32(Console.ReadLine());

        for (int i = arr.Length - 1; i >= pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos-1] = dato;

        Console.WriteLine("El nuevo arreglo es: \n" + string.Join(",",arr));



    }
}