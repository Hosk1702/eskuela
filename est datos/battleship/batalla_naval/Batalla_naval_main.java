package batalla_naval;
import java.util.Scanner;

public class Batalla_naval_main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.println("==================================================");
        System.out.println("             BIENVENIDO A BATALLA NAVAL           ");
        System.out.println("==================================================");
        
        System.out.println("Seleccione el modo de juego:");
        System.out.println("1 - Jugador vs Computadora (PvC)");
        System.out.println("2 - Jugador vs Jugador (PvP)");
        System.out.print("Ingrese 1 o 2: ");
        int modo = 0;
        if (sc.hasNextInt()) {
            modo = sc.nextInt();
        }

        if (modo == 1) {
            jugarPVC();
        } else if (modo == 2) {
            jugarPVP();
        } else {
            System.out.println("Modo no válido. Terminando el programa.");
        }
       
    }

       
    public static void jugarPVC() {
        System.out.println("\n--- MODO JUGADOR VS COMPUTADORA ---");
        Jugador j1 = new Jugador();
        Computadora c = new Computadora();

        System.out.println("Bienvenido al juego batalla naval!. Estaras jugando contra la computadora.");
        
        
        System.out.println("\n[TURNO DE JUGADOR 1: COLOCACIÓN DE BARCOS]");
        j1.posionamiento_de_piezas();
        
        
        c.comp_armado();

        System.out.println("\n==================================================");
        System.out.println("             ¡INICIA LA BATALLA!                  ");
        System.out.println("==================================================");

        
        while (!j1.buscar_ganador(c) && !c.buscar_ganadorC(j1)) {
            
            System.out.println("\n--- TURNO: JUGADOR 1 (Tú) ---");
            Coordenadas ataque_a_comp = j1.ataque_del_jugador();
            j1.fuego_ataque_JB(c, ataque_a_comp);
            
            
            System.out.println("\nTU TABLERO DE ATAQUE (OPONENTE - Computadora): ");
            j1.tab.imprimir_tabB(); 

            if (j1.buscar_ganador(c)) break;

           
            System.out.println("\n--- TURNO: COMPUTADORA ---");
            Coordenadas ataque_a_j = c.obt_predict_coord(j1);
            c.fuego_ataque_JA(j1, ataque_a_j);

            
            System.out.println("\nTU TABLERO DE BARCOS (ATAQUES RECIBIDOS): ");
            j1.tab.imprimir_tabA(); 
        }

        System.out.println("\n==================================================");
        if(j1.buscar_ganador(c)){ 
            System.out.println("JUEGO TERMINADO! FELICIDADES HAS GANADO!!");
        } else {
            System.out.println("JUEGO TERMINADO! HAS PERDIDO MEJOR SUERTE LA PROXIMA!");
        }
        System.out.println("==================================================");
    }

     public static void jugarPVP() {
        System.out.println("\n--- MODO JUGADOR VS JUGADOR ---");
        
        
        Jugador j1 = new Jugador(); 
        Jugador j2 = new Jugador(); 

       
        System.out.println("\n[TURNO DE JUGADOR 1: COLOCACIÓN DE BARCOS]");
        j1.posionamiento_de_piezas();
        
        System.out.println("\n[TURNO DE JUGADOR 2: COLOCACIÓN DE BARCOS]");
        j2.posionamiento_de_piezas(); 

        System.out.println("\n==================================================");
        System.out.println("             ¡INICIA LA BATALLA!                  ");
        System.out.println("==================================================");

        while (!j1.buscar_ganador(j2) && !j2.buscar_ganador(j1)) {
            
            System.out.println("\n--- TURNO: JUGADOR 1 (Ataca a Jugador 2) ---");
            Coordenadas ataque_a_j2 = j1.ataque_del_jugador();
            
            
            j1.fuego_ataque_JB_PVP(j2, ataque_a_j2); 
            
            System.out.println("\nTABLERO DE ATAQUE DE JUGADOR 1: ");
            j1.tab.imprimir_tabB(); 
            
            System.out.println("\nBARCOS DE JUGADOR 2 (ATAQUES RECIBIDOS): ");
            j2.tab.imprimir_tabA(); 
            
            if (j1.buscar_ganador(j2)) break;
            
           
            System.out.println("\n--- TURNO: JUGADOR 2 (Ataca a Jugador 1) ---");
            Coordenadas ataque_a_j1 = j2.ataque_del_jugador();
            
            j2.fuego_ataque_JB_PVP(j1, ataque_a_j1); 

            System.out.println("\nTABLERO DE ATAQUE DE JUGADOR 2: ");
            j2.tab.imprimir_tabB(); 

            System.out.println("\nBARCOS DE JUGADOR 1 (ATAQUES RECIBIDOS): ");
            j1.tab.imprimir_tabA(); 
            
            if (j2.buscar_ganador(j1)) break;
        }
        
        System.out.println("\n==================================================");
        if(j1.buscar_ganador(j2)){
            System.out.println("JUEGO TERMINADO! FELICIDADES JUGADOR 1 HAS GANADO!!");
        } else if (j2.buscar_ganador(j1)) {
            System.out.println("JUEGO TERMINADO! FELICIDADES JUGADOR 2 HAS GANADO!!");
        }
        System.out.println("==================================================");
    }
}