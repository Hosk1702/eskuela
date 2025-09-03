import java.util.Scanner;

public class Insertar {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int arr[] = {231,23,32,12,32};
        

        System.out.println("Ingrese el numero a insertar:");
        int dato = sc.nextInt();
        sc.nextLine();

        System.out.println("Ingrese la posicion para insertar el numero:");
        int pos = sc.nextInt();
        sc.nextLine();

        for (int i = (arr.length-1) ; i >= (pos-1) ; i--){
            arr[i] = arr[i-1];
        } 
        arr[pos-1] = dato;

        System.out.println("Los valores del nuevo arreglo son:");
        for (int i = 0 ; i < arr.length ; i++){
            System.out.println("El valor de la posicion " + (i+1) + " es: " + arr[i]);
        }

        sc.close();
    }
    
}
