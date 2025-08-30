import java.util.Scanner;
public class Tarea_1{
    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
        
    System.out.println("Ingrese el tamaño del arreglo:");
    int tam = sc.nextInt();
    sc.nextLine(); 
    
    String[] array = new String[tam];

    for (int i=0 ;  i < tam ; i++){
        System.out.println("ingrese el valor de la posicion " + (i+1) + ":");
        array[i] = sc.nextLine();
    }

    System.out.println("Los valores del arreglo son:");
    for (int i = 0 ; i < tam ; i++){
        System.out.println("El valor de la posicion " + (i+1) + " es: " + array[i]);
    }


}
}