import java.util.Scanner;
public class matrices {
public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    System.out.println("Ingrese el numero de filas:");
    int filas = sc.nextInt();
    System.out.println("Ingrese el numero de columnas:");
    int columnas = sc.nextInt();
    sc.nextLine();

    int[][] matriz = new int[filas][columnas];

    System.out.println("Vamos a llenar la matriz:");

    for (int i = 0 ; i < filas ; i++){
        for (int j = 0 ; j < columnas ; j++){
            System.out.println("Ingrese un valor entero para la posicion [" + (i+1) + "][" + (j+1) + "]:");
            int dato = sc.nextInt();
            matriz[i][j] = dato;
        } 
    }

    int option;

    do {
        System.out.println("De que manera quiere ver la matriz? (1: filas, 2: columnas)");
        option = sc.nextInt();
        
        
        if (option == 1){
            System.out.println("La matriz por filas es:");
            for (int i = 0 ; i < filas ; i++){
                for (int j = 0 ; j < columnas ; j++){
                    System.out.print(matriz[i][j] + " ");
                }
                System.out.println();
            }
         } else if (option == 2){
                System.out.println("La matriz por columnas es:");
                for (int j = 0 ; j < columnas ; j++){
                    for (int i = 0 ; i < filas ; i++){
                        System.out.print(matriz[i][j] + " ");
                    }
                    System.out.println();
                }
            } else {
                System.out.println("Opcion no valida.");
            }

        }while(option != 1 && option != 2);
        System.out.println("Gracias por usar el programa.");
    sc.close();

}
}