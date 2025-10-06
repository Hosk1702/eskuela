package batalla_naval;
import java.util.Scanner;
public class Jugador {
    Tablero tab = new Tablero();
    Scanner sc = new Scanner(System.in);

    public Jugador(){
        tab.inictabA();
        tab.inictabB();
    }

    public char obtener_dir(){
        System.out.println("En que direccion te gustaria colocarlo: ");
        System.out.println("Ingresa 'u' para arriba, 'd' para abajo, 'r' para derecha, 'l' para izquierda");
        char dir = sc.next().charAt(0);

        return dir;
    }


    public int obtener_X(){
        System.out.println("Ingresa la coordenada X, donde lo quieres colocar: ");
        int xcord = sc.nextInt();

        return xcord;
    }

      public int obtener_Y(){
        System.out.println("Ingresa la coordenada Y, donde lo quieres colocar: ");
        int ycord = sc.nextInt();

        return ycord;
    }



    public void posionamiento_de_piezas(){
        System.out.println("Es tiempo de colocar tus barcos!");
        tab.imprimir_tabA();

        //colocar portaviones
        System.out.println("El primer barco es un Portaviones. Mide 5 casillas");
        char dir = obtener_dir();
        int xcord = obtener_X();
        int ycord = obtener_Y();

        Coordenadas crd = new Coordenadas(xcord,ycord);

        Ship portaviones = new Ship('P', dir, crd);

        while(tab.posicion_valida(crd, portaviones == false)){
            System.out.println("Posicion invalida, por favor ingresa una posicion valida");
            int nuevax = obtener_X();
            int nuevay = obtener_Y();
            crd = new Coordenadas(nuevax,nuevay);
            portaviones = new Ship('P', dir, crd);
        }

        tab.colocar_barcos(crd, portaviones);
        tab.imprimir_tabA();

        //colocar Acorazado
        System.out.println("El primer barco es un Acorazado. Mide 4 casillas");
        char dir = obtener_dir();

        int xcord = obtener_X();
        int ycord = obtener_Y();

        Coordenadas crd = new Coordenadas(xcord,ycord);

        Ship acorazado = new Ship('A', dir, crd);

        while(tab.posicion_valida(crd, portaviones == false)){
            System.out.println("Posicion invalida, por favor ingresa una posicion valida");
            int nuevax = obtener_X();
            int nuevay = obtener_Y();
            crd = new Coordenadas(nuevax,nuevay);
            acorazado = new Ship('A', dir, crd);
        }
        tab.colocar_barcos(crd, acorazado);
        tab.imprimir_tabA();

         //colocar crucero
        System.out.println("El tercer barco es un Crucero. Mide 3 casillas");
        char dir = obtener_dir();

        int xcord = obtener_X();
        int ycord = obtener_Y();

        Coordenadas crd = new Coordenadas(xcord,ycord);

        Ship crucero = new Ship('C', dir, crd);

        while(tab.posicion_valida(crd, portaviones == false)){
            System.out.println("Posicion invalida, por favor ingresa una posicion valida");
            int nuevax = obtener_X();
            int nuevay = obtener_Y();
            crd = new Coordenadas(nuevax,nuevay);
            crucero = new Ship('C', dir, crd);
        }
        tab.colocar_barcos(crd, crucero);
        tab.imprimir_tabA();
        
        //colocar submarino
        System.out.println("El cuarto barco es un Submarino. Mide 3 casillas");
        char dir = obtener_dir();

        int xcord = obtener_X();
        int ycord = obtener_Y();

        Coordenadas crd = new Coordenadas(xcord,ycord);

        Ship crucero = new Ship('S', dir, crd);

        while(tab.posicion_valida(crd, portaviones == false)){
            System.out.println("Posicion invalida, por favor ingresa una posicion valida");
            int nuevax = obtener_X();
            int nuevay = obtener_Y();
            crd = new Coordenadas(nuevax,nuevay);
            crucero = new Ship('S', dir, crd);
        }
        tab.colocar_barcos(crd, crucero);
        tab.imprimir_tabA();

        //colocar destructor
        System.out.println("El cuarto barco es un Destructor. Mide 2 casillas");
        char dir = obtener_dir();

        int xcord = obtener_X();
        int ycord = obtener_Y();

        Coordenadas crd = new Coordenadas(xcord,ycord);

        Ship crucero = new Ship('D', dir, crd);

        while(tab.posicion_valida(crd, portaviones == false)){
            System.out.println("Posicion invalida, por favor ingresa una posicion valida");
            int nuevax = obtener_X();;
            int nuevay = obtener_Y();;
            crd = new Coordenadas(nuevax,nuevay);
            crucero = new Ship('D', dir, crd);
        }
        tab.colocar_barcos(crd, crucero);
        tab.imprimir_tabA();
    }

    public Coordenadas ataque_del_jugador(){
        System.out.println("Ingresa la coordenada X donde quieres atacar al oponente: ");
        int atqX = sc.nextInt();
        System.out.println("Ingresa la coordenada Y donde quieres atacar al oponente: ");
        int atqY = sc.nextInt();
        
        Coordenadas ataque = new Coordenadas(atqX, atqY);

        while(tab.valid_ataque(ataque) == false){
            System.out.println("Posicion invalida por favor intente de nuevo.");
            System.out.println("Ingresa la coordenada X donde quieres atacar al oponente: ");
            int newatqX = sc.nextInt();
            System.out.println("Ingresa la coordenada Y donde quieres atacar al oponente: ");
            int newatqY = sc.nextInt();

            ataque = new Coordenadas(newatqX, newatqY);
        }

        return ataque;
    }

    public void fuego_ataque_JB(Computer comp, Coordenadas ataque){
        tab.imprimir_resul(tab.resultJBGF(ataque, comp));
    }

    public void imprimir_tab(char[][] tablero){
         for (int i = 0; i < tablero.length ; i++){
            System.out.print(i + "| ");
            for (int j =0 ; j < tablero[0].length; j++){
                System.out.print(tablero[i][j] + " | ");
            }
            System.out.println();
            System.out.println("------------------------------------------");
        }
    }

    public boolean buscar_ganador(Computer c){
        for(int i = 1; i<c.obt_tabA().length;i++){
            for (int j=1; j < c.obt_tabA()[0].length; i++){
                if(c.obt_tabA()[i][j] != ' ' && c.obt_tabA()[i][j] != 'H'){
                    return false;
                }
            }
        }
    }

    public char[][] obt_tabA(){
        return tab.obt_tabA();
    }
    public char[][] obt_tabB(){
        return tab.obt_tabB();
    }
}
