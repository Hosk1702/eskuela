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
        Ship portaviones = new Ship('P',direccion,crd);
        while (!tab.posicion_valida(crd, portaviones)) {
            crd = randomCoordenadas();
            portaviones = new Ship('P', direccion, crd);
        }

        tab.colocar_barcos(crd, portaviones);

        direccion = randomDireccion();
        crd = randomCoordenadas();
        Ship acorazado = new Ship('A',direccion,crd);
        while (!tab.posicion_valida(crd, acorazado)) {
            crd = randomCoordenadas();
            acorazado = new Ship('A',direccion,crd);
        }
        
        tab.colocar_barcos(crd, acorazado);
    
        direccion = randomDireccion();
        crd = randomCoordenadas();
        Ship crucero = new Ship('C',direccion,crd);
        while (!tab.posicion_valida(crd, crucero)) {
            crd = randomCoordenadas();
            crucero = new Ship('C',direccion,crd);
        }

        tab.colocar_barcos(crd, crucero);
        
        direccion = randomDireccion();
        crd = randomCoordenadas();
        Ship crucero2 = new Ship('C',direccion,crd);
        while (!tab.posicion_valida(crd, crucero2)) {
            direccion = randomDireccion(); // También es bueno cambiar la dirección aleatoriamente
            crd = randomCoordenadas();
            crucero2 = new Ship('C',direccion,crd);
        }
        tab.colocar_barcos(crd, crucero2);
        
        direccion = randomDireccion();
        crd = randomCoordenadas();
        Ship submarino = new Ship('S',direccion,crd);
        while (tab.posicion_valida(crd, submarino) == false) {
            crd = randomCoordenadas();
            submarino = new Ship('S',direccion,crd);
        }

        tab.colocar_barcos(crd, submarino);

        direccion = randomDireccion();
        crd = randomCoordenadas();
        Ship submarino2 = new Ship('S',direccion,crd);
        while (tab.posicion_valida(crd, submarino2) == false) { 
            direccion = randomDireccion();
            crd = randomCoordenadas();
            submarino2 = new Ship('S',direccion,crd);
        }
        
        tab.colocar_barcos(crd, submarino2);

        direccion = randomDireccion();
        crd = randomCoordenadas();
        Ship destructor = new Ship('D',direccion,crd);
        while (tab.posicion_valida(crd, destructor) == false) {
            crd = randomCoordenadas();
            destructor = new Ship('D',direccion,crd);
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
                int rnd  = (int)(Math.random() * obtenido.size()); 

                while (!tab.valid_ataque(obtenido.get(rnd)) || tab.obt_tabB()[obtenido.get(rnd).conseguir_Y()][obtenido.get(rnd).conseguir_X()] != ' ') {
                    rnd  = (int)(Math.random() * obtenido.size()); 
                }

                cord.add(obtenido.get(rnd));
                return obtenido.get(rnd);
            }
        }

        c = randomCoordenadas();
        while (!tab.valid_ataque(c) || tab.obt_tabB()[c.conseguir_Y()][c.conseguir_X()] != ' ') {
            c = randomCoordenadas();          
        }

        cord.add(c);
        return c;
    }

    public ArrayList<Coordenadas> elegir_adyacente(Coordenadas crd) {
        ArrayList<Coordenadas> adyacentes = new ArrayList<>();
        int x = crd.conseguir_X();
        int y = crd.conseguir_Y();

       
        int[][] movimientos = { {0,1}, {0,-1}, {1,0}, {-1,0} };

        for (int[] mov : movimientos) {
            int nx = x + mov[0];
            int ny = y + mov[1];
            
            if (nx >= 1 && nx < 10 && ny >= 1 && ny < 10) {
            adyacentes.add(new Coordenadas(nx, ny));
            }
        }
        return adyacentes;  
    }

    public boolean buscar_ganadorC(Jugador j){
        for (int i = 1; i < j.obt_tabA().length; i++){
            for (int k = 1; k < j.obt_tabA()[0].length; k++){
                if(j.obt_tabA()[i][k] != ' ' && j.obt_tabA()[i][k] != 'X'){
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
        int num1 = (int)(Math.random() * 10) + 1;
        int num2 = (int)(Math.random() * 10) + 1;

        return new Coordenadas(num1,num2);
    }

    public char[][] obt_tabA(){
        return tab.obt_tabA();
    }
    public char[][] obt_tabB(){
        return tab.obt_tabB();
    }
}
