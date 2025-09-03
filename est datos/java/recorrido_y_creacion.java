import java.util.Scanner;

public class recorrido_y_creacion {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Ingrese el tamaño del arreglo:");
        int tam = sc.nextInt();
        sc.nextLine();

        int[] arr = new int[tam];

        System.out.println("Vamos a llenar el arreglo:");

        for (int i = 0 ; i<tam ; i++){
            System.out.println("Ingrese el numero para la posicion " + (i+1) + ":");
            arr[i] = sc.nextInt();
            sc.nextLine();
        }

        System.out.println("Los valores del arreglo son:");
        for (int i = 0 ; i<tam ; i++){
            System.out.println("El valor de la posicion " + (i+1) + " es: " + arr[i]);
        }


sc.close();

    }
}
