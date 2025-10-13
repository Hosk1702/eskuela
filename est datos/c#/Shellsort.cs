using System;

public class Shellsort
{
    public static void Display(int[] arr)
    {
        foreach (int i in arr)
        {
            Console.Write(i + " ");
        }
        Console.WriteLine();
    }

    public int Sort(int[] arr)
    {
        int size = arr.Length;
        int gapsize = size / 2;

        while (gapsize > 0)
        {
            for (int j = gapsize; j < size; j++)
            {
                int temp = arr[j];
                int k = j;

                while (k >= gapsize && arr[k - gapsize] > temp)
                {
                    arr[k] = arr[k - gapsize];
                    k -= gapsize;
                }
                arr[k] = temp;
            }
            gapsize = gapsize / 2;
        }
        return 0;
    }

    public static void Main(string[] args)
    {
        int[] arr = { 12, 34, 54, 2, 3 };
        Console.WriteLine("Arreglo antes del ordenamiento:");
        Shellsort.Display(arr);

        Shellsort obj = new Shellsort();
        obj.Sort(arr);

        Console.WriteLine("Array after sorting:");
        Shellsort.Display(arr);
    }
}