import java.util.Scanner;
//Revisado 26/09/25 centro de computo
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

    public static String[][] insertar(String[][] arr, Scanner sc, String jugador,int size){
        int fila,columna;
        boolean colocado = true;
        do{
        System.out.println("Ingrese la fila de inicio (0-9):");
        fila = sc.nextInt();
        System.out.println("Ingrese la columna de inicio (0-9):");
        columna = sc.nextInt();
        System.out.println("De que manera desea poner su barco(Horizontal. 1; Vertical. 2)");
            int pos = sc.nextInt();

        if (pos == 1){
            if (columna+pos > 10 && fila+pos >10){
                colocado = false;
            }else{
            for (int i = 0; i < size ; i++){
            arr[fila][columna + i] = jugador;
            colocado = true;
            }
            }
        }else if (pos == 2){
            if (columna+pos > 10 && fila+pos >10){
                colocado = false;
            }else{
            for (int i = 0; i < size ; i++){
            arr[fila+i][columna] = jugador;
            colocado = true;
            }
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
    
    public static int tamaño(int size){
        switch (size){
            case 1:
                return 2;
            case 2:
                return 3;
            case 3:
                return 3;
            case 4:
                return 4;
            case 5:
                return 5;
        }
        return 0;
        
    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[][] arr = limpiar_arr(); 
        int size;
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
            System.out.println("Que barco desea colocar?");
            System.out.println("1.Destructor(2 Size), 2.Submarino(3 Size), 3.Cruzero(3 size), 4.Acorazado(4.size), 5.Portaviones (5 size)");
            size = sc.nextInt();
            size = tamaño(size);
            

            arr = insertar(arr, sc,jugador,size);
            imprimir(arr);
        }while(true);

    }


}
