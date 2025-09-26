import java.util.Scanner;

public class battleship {
    public static String[][]  limpiar_arr(){
        String[][] arr = new String[10][10];
          for (int i = 0; i < 10 ; i++){
            for (int j =0 ; j < 10; j++){
                arr[i][j] = " ";
            }         
        }

        return arr;
    }


    public static void imprimir(String[][] arr){
        for (int i = 0; i < 10 ; i++){
            System.out.print(i + "| ");
            for (int j =0 ; j < 10; j++){
                System.out.print(arr[i][j] + " | ");
            }
            System.out.println();
            System.out.println("------------------------------------------");
        }

    }

    public static String[][] insertar(String[][] arr, int pos, Scanner sc, String jugador){
        int fila,columna;
        boolean colocado = true;
        do{
        System.out.println("Ingrese la fila de inicio (0-9):");
        fila = sc.nextInt();
        System.out.println("Ingrese la columna de inicio (0-9):");
        columna = sc.nextInt();

        if (pos == 1){
            for (int i = 0; i < 4 ; i++){
            arr[fila][columna + i] = jugador;
            colocado = true;
            }
        }else if (pos == 2){
            for (int i = 0; i < 4 ; i++){
            arr[fila+i][columna] = jugador;
            colocado = true;
            }
        }else{
            colocado = false;
        }
        
        if (!colocado){
            System.out.println("Inserte otra posicion no es posible colocar el barco");
        }
        }while(!colocado);
        return arr;
    }



    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[][] arr = limpiar_arr(); 

        imprimir(arr);
        String jugador = "X";
        int turno = 1 ;
        do{
            jugador += 1;
            if (turno % 2 == 1){
                jugador = "X";
            }else {
                jugador = "O";
            }

            System.out.println("Es turno del jugador " + jugador + ":");
            System.out.println("De que manera desea poner su barco (4 piezas) (Horizontal. 1; Vertical. 2)");
            int pos = sc.nextInt();

            arr = insertar(arr, pos, sc,jugador);
            imprimir(arr);
        }while(true);

    }


}

