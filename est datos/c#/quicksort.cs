using System;
using System.ComponentModel.Design;
class Program{
    static void cambiar(ref int[] arr, int j, int k) {
        int temp = arr[j];
        arr[j] = arr[k];
        arr[k] = temp;
    }
    static int particion(ref int[] arr,int l, int h)
    {
        int pivote = arr[h];
        int j = l - 1;
        for (int k = 0; k < h; k++)
        {
            if (arr[k] <= pivote) {
                j += 1;
                cambiar(ref arr, j, k);
            }
        }
        cambiar(ref arr, j+1, h);
        return j+1;
    }

    static void quicksort(ref int[] arr, int l, int h) {
        if (l < h) { 
            int pivote = particion(ref arr, l, h);

            quicksort(ref arr, l, pivote-1);
            quicksort(ref arr, pivote + 1, h);

        }
    }


    static void imprimir(int[] arr, int tam)
    {
        for (int i = 0; i < 5; i++)
        {
            Console.WriteLine(arr[i] + string.Join(","));
        }
    }

    static void Main(string[] args)
    {
            int[] arr = {10,7,9,8,1,5};
            int tam = arr.Length;
            Console.WriteLine("Arreglo sin ordenar: \n");
            imprimir(arr,tam);
            quicksort(ref arr, 0, tam);
            Console.WriteLine("Arreglo ordenado: \n");
            imprimir(arr,tam);
 
    }
}

