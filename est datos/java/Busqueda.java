import java.util.Scanner;
import java.util.Random;

public class Busqueda {
    public static int buscar(int arr[], int dato, int tam){
        for (int i =0; i<tam ; i++){
            if (arr[i] == dato){
                return i;
            }
            
        }
        return -1;
    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Random random = new Random();
        int j = 1;


        System.out.println("Ingrese el tamaño del arreglo:");
        int tam= sc.nextInt();
        sc.nextLine();

        int[] arr = new int[tam];

        for (int i=0 ; i < tam ; i++){
            int rnd = random.nextInt(100);
            arr[i] = rnd; 
        }

System.out.println("Los valores del arreglo son:");
        for (int i = 0 ; i<tam ; i++){
            System.out.println("El valor de la posicion " + (i+1) + " es: " + arr[i]);
        }

        do {
            System.out.println("Ingrese el numero a buscar en el arreglo:");
            int dato = sc.nextInt();
            sc.nextLine();
            int resul = buscar(arr, dato, tam);
            


            if (resul != -1){
                System.out.println("El numero " + dato + " se encuentra en la posicion " + (resul+1) + " del arreglo.");
            } else {
                System.out.println("El numero " + dato + " no se encuentra en el arreglo.");
            }
            System.out.println("Desea buscar otro numero? (1=SI / 0=NO)");
            j = sc.nextInt();
            sc.nextLine();
            
        } while (j==1); 
       
        sc.close();
    }
}
