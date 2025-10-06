package batalla_naval;
import java.net.JarURLConnection;
import java.util.ArrayList;
public class Computadora {
    Tablero tab = new Tablero();
    ArrayList<Coordenadas> cord = new ArrayList<Coordenadas>();
    ArrayList<Coordenadas> obtenido = new ArrayList<Coordenadas>();

    public Computadora(){
        tab.inictabA();
        tab.inictabB();
    }
    
    public void comp_armado(){
        char direccion = randomDireccion();
        Coordenadas crd = randomCoordenadas();
        Ship portaviones = new Ship('P',crd,direccion);
        while (tab.posicion_valida(crd, portaviones) == false) {
            crd = randomCoordenadas();
        }

        tab.colocar_barcos(crd, portaviones);

        direccion = randomDireccion();
        crd = randomCoordenadas();
        Ship acorazado = new Ship('A',crd,direccion);
        while (tab.posicion_valida(crd, acorazado) == false) {
            crd = randomCoordenadas();
        }
        
        tab.colocar_barcos(crd, acorazado);
    
        direccion = randomDireccion();
        crd = randomCoordenadas();
        Ship crucero = new Ship('C',crd,direccion);
        while (tab.posicion_valida(crd, crucero) == false) {
            crd = randomCoordenadas();
        }

        tab.colocar_barcos(crd, crucero);

        direccion = randomDireccion();
        crd = randomCoordenadas();
        Ship submarino = new Ship('S',crd,direccion);
        while (tab.posicion_valida(crd, submarino) == false) {
            crd = randomCoordenadas();
        }

        tab.colocar_barcos(crd, submarino);

        direccion = randomDireccion();
        crd = randomCoordenadas();
        Ship destructor = new Ship('D',crd,direccion);
        while (tab.posicion_valida(crd, destructor) == false) {
            crd = randomCoordenadas();
        }

        tab.colocar_barcos(crd, destructor);

        System.out.println("La computadora ha terminado de colocar sus barcos.");
        System.out.println("X. Señala donde la computadora ha atacado.");

    }

    public void fuego_ataque_JA(Jugador j, Coordenadas atq){
        imprimir_resul(tab.resultJAGF(atq, j));
    }

    public void imprimir_resul(char resul){
        if (resul == 'H'){
            System.out.println("La computadora ha golpeado uno de tus barcos!.");
        } else {
            System.out.println("La computadora ha fallado!.");
        }
    }

    public Coordenadas obt_predict_coord(Jugador j){
        Coordenadas c = randomCoordenadas();

        if(cord.size() >= 1){
            c = cord.get(cord.size() - 1);

            if(tab.resultJAGF(c, j) == 'H'){
                obtenido = elegir_adyacente(c);
                int rnd  = (int)(Math.randon() * obtenido.size() + 1); 

                while (!tab.valid_ataque(obtenido.get(rnd-1) || tab.inictabB()[obtenido.get(rnd - 1).obtener_Y() + 1][obtenido.get(rnd - 1).obtener_X() + 1] != ' ')) {
                    rnd  = (int)(Math.randon() * obtenido.size() + 1); 
                }

                cord.add(obtenido.get(rnd - 1));
                return obtenido.get(rnd - 1);
            }
        }

        c = randomCoordenadas();
        while (!tab.valid_ataque(c) || tab.obt_tabB()[c.obtener_Y() + 1][c.obtener_X() + 1]) {
            c = randomCoordenadas();          
        }

        cord.add(c);
        return c;
    }

    public ArrayList<Coordenadas> elegir_adyacente(Coordenadas crd) {
        ArrayList<Coordenadas> adyacentes = new ArrayList<>();
        int x = crd.conseguir_X();
        int y = crd.conseguir_Y();

        // Movimientos: arriba, abajo, izquierda, derecha
        int[][] movimientos = { {0,1}, {0,-1}, {1,0}, {-1,0} };

        for (int[] mov : movimientos) {
            int nx = x + mov[0];
            int ny = y + mov[1];
            // Verifica que esté dentro del tablero 10x10
            if (nx >= 0 && nx < 10 && ny >= 0 && ny < 10) {
            adyacentes.add(new Coordenadas(nx, ny));
            }
        }
        return adyacentes;  
    }

    public boolean buscar_ganadorC(Jugador j){
        for (int i = 1; i < j.obt_tabA().length; i++){
            for (int j = 1; j < j.obt_tabA[0].length; i++){
                if(j.obt_tabA[i][j] != ' ' || tab.obt_tabB()[i][j] != 'H'){
                    return false;
                }
            }
        }
        return true;
    }

    public char randomDireccion(){
        int dirnum = (int)(Math.random() * 4) + 1;
        switch (dirnum) {
            case 1:
                return 'u';            
            case 2:
                return 'd';
            case 3: 
                return 'r';
            default:
                return 'l';
        }
    }

    public Coordenadas randomCoordenadas(){
        int num1 = (int)(Math.random() * 10);
        int num2 = (int)(Math.random() * 10);

        return new Coordenadas(num1,num2);
    }

    public char[][] obt_tabA(){
        return tab.obt_tabA();
    }
    public char[][] obt_tabB(){
        return tab.obt_tabB();
    }
}
