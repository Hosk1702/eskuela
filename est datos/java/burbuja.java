import java.util.Scanner;
import java.util.Random;

public class burbuja{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Random rand = new Random();

        System.out.println("Ingrese el tamaño del arreglo: ");
        int tam = sc.nextInt();

        int[] arr = new int[tam];

        for (int i=0 ; i < tam ; i++){
            int rnd = rand.nextInt(100);
            arr[i] = rnd; 
        }
        System.out.println("Los valores del arreglo son:");
        for (int i = 0 ; i<tam ; i++){
            System.out.println("El valor de la posicion " + (i+1) + " es: " + arr[i]);
        }

        boolean swapped;
        do{
            swapped = false;
            for (int i=0 ; i < tam-1 ; i++){
                if (arr[i] > arr[i+1]){
                    int aux = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1] = aux;
                    swapped = true;
                }
            }
        } while (swapped==true);

        System.out.println("Los valores del arreglo ordenados son:");
        for (int i = 0 ; i<tam ; i++){
            System.out.println("El valor de la posicion " + (i+1) + " es: " + arr[i]);
        }

        sc.close();
    }


}