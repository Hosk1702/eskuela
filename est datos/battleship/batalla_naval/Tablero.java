package batalla_naval;

public class Tablero {
    

    private char[][] tabA = new char[10][10];
    private char[][] tabB = new char[10][10];

    private int numPortavionesJA = 0;
    private int numAcorazadoJA = 0;
    private int numCruceroJA = 0;
    private int numSubmarinoJA = 0;
    private int numDesctructorJA = 0;

    private int numPortavionesJB = 0;
    private int numAcorazadoJB = 0;
    private int numCruceroJB = 0;
    private int numSubmarinoJB = 0;
    private int numDesctructorJB = 0;

    public Tablero(){
        inictabA();
        inictabB();
    }
    
    public void inictabA(){
        tabA[0][0] = ' ';
        int num = 1;
        for (int i = 48; i <=57; i++){
            tabA[num][0] = (char) i;
            num ++;
        }

        num = 1;
        for (int i = 48; i <=57; i++){
            tabA[0][num] = (char) i;
            num ++ ;
        }

        for (int i = 0; i < tabA.length ; i++){
            for (int j =0 ; j < tabA[0].length; j++){
                tabA[i][j] = ' ';
            }         
            }
    }   

    public void inictabB(){
        tabB[0][0] = ' ';
        int num = 1;
        for (int i = 48; i <=57; i++){
            tabB[num][0] = (char) i;
            num ++ ;
        }

        num = 1;
        for (int i = 48; i <=57; i++){
            tabB[0][num] = (char) i;
            num ++;
        }

        for (int i = 0; i < tabB.length ; i++){
            for (int j =0 ; j < tabB[0].length; j++){
                tabB[i][j] = ' ';
            }         
            }
    }   

    public boolean posicion_valida(Coordenadas crd, Ship b){
        int xcord = crd.conseguir_X();
        int ycord = crd.conseguir_Y();

        if (xcord < 1 || xcord >= tabA[0].length){
            return false;
        }
        if (ycord < 1 || ycord >= tabA.length){
            return false;
        }

        if (b.obt_dir() == 'u'){
            if(ycord - (b.obt_tam() + 1) < 1){
                return false;
            }

            for(int i = ycord ; i > ycord - b.obt_tam(); i--){
                if(tabA[i][xcord] != ' '){
                    return false;
                }
            }
        } else if(b.obt_dir() == 'd'){
            if(ycord + (b.obt_tam() + 1) >= tabA.length){
                return false;
            }

            for(int i = ycord ; i <= ycord + (b.obt_tam() - 1); i++){
                if(tabA[i][xcord] != ' '){
                    return false;
                }
            }
        } else if(b.obt_dir() == 'r'){
            if(xcord + (b.obt_tam() - 1) >= tabA[0].length){
                return false;
            }

            for(int i = xcord ; i <= xcord - (b.obt_tam() - 1); i++){
                if(tabA[ycord][i] != ' '){
                    return false;
                }
            }
        } else if(b.obt_dir() == 'l'){
            if(xcord - (b.obt_tam() + 1) < 1){
                return false;
            }

            for(int i = xcord ; i > xcord - (b.obt_tam()); i--){
                if(tabA[ycord][i] != ' '){
                    return false;
                }
            }
        }
        
        return true;   
    }

    public boolean valid_ataque(Coordenadas crd){
        int xcord = crd.conseguir_X() + 1;
        int ycord = crd.conseguir_Y() + 1;

        if(xcord < 1 || xcord >= tabA[0].length){
            return false;
        }
        
        if(ycord < 1 || ycord >= tabA.length){
            return false;
        }

        return true;
    }

    public char resultJBGF(Coordenadas crd, Computadora oponente ){
        int xcord = crd.conseguir_X() + 1;
        int ycord = crd.conseguir_Y() + 1;

        if(oponente.obt_tabA()[ycord][xcord] == 'P'){
            numPortavionesJB++;
            if (numPortavionesJB == 5){
                System.out.println("Has hundido el portaviones de tu oponente!");
            }
        }else if(oponente.obt_tabA()[ycord][xcord] == 'A'){
            numAcorazadoJB++;
            if (numAcorazadoJB == 4){
                System.out.println("Has hundido el acorazado de tu oponente!");
            }
        }else if(oponente.obt_tabA()[ycord][xcord] == 'C'){
            numCruceroJB++;
            if (numCruceroJB == 3){
                System.out.println("Has hundido el crucero de tu oponente!");
            }
        }else if(oponente.obt_tabA()[ycord][xcord] == 'S'){
            numSubmarinoJB++;
            if (numSubmarinoJB == 3){
                System.out.println("Has hundido el submarino de tu oponente!");
            }
        }else if(oponente.obt_tabA()[ycord][xcord] == 'D'){
            numDesctructorJB++;
            if (numDesctructorJB == 2){
                System.out.println("Has hundido el destructor de tu oponente!");
            }
        }

        if(oponente.obt_tabA()[ycord][xcord] != ' '){
            this.obt_tabB()[ycord][xcord] = 'H';
            oponente.obt_tabA()[ycord][xcord] = 'X';
            return 'H';
        }
    }

    public char resultJAGF(Coordenadas crd, Jugador oponente){
        int xcord = crd.conseguir_X() + 1;
        int ycord = crd.conseguir_Y() + 1;

        if(oponente.obt_tabA()[ycord][xcord] == 'P'){
            numPortavionesJA++;
            if (numPortavionesJA == 5){
                System.out.println("Tu oponente ha hundido tu portaviones!");
            }
        }else if(oponente.obt_tabA()[ycord][xcord] == 'A'){
            numAcorazadoJA++;
            if (numAcorazadoJA == 4){
                System.out.println("Tu oponente ha hundido tu acorazado!");
            }
        }else if(oponente.obt_tabA()[ycord][xcord] == 'C'){
            numCruceroJA++;
            if (numCruceroJA == 3){
                System.out.println("Tu oponente ha hundido tu crucero!");
            }
        }else if(oponente.obt_tabA()[ycord][xcord] == 'S'){
            numSubmarinoJA++;
            if (numSubmarinoJA == 3){
                System.out.println("Tu oponente ha hundido tu submarino!");
            }
        }else if(oponente.obt_tabA()[ycord][xcord] == 'D'){
            numDesctructorJA++;
            if (numDesctructorJA == 2){
                System.out.println("Tu oponente ha hundido tu destructor!");
            }
        }

        if(oponente.obt_tabA()[ycord][xcord] != ' '){
            oponente.obt_tabA()[ycord][xcord] = 'X';
            this.obt_tabB()[ycord][xcord] = 'H';
            return 'H';
        }else {
            this.obt_tabB()[ycord][xcord] = 'M';
            return 'M';
        }
    }

    public void imprimir_resul(char resul){
        if(resul == 'M'){
            System.out.println("Mala suerte!. Has fallado!");
        } else {
            System.out.println("Buen tiro!. Has golpeado un barco enemigo!");
        }
    }

    public void colocar_barcos(Coordenadas crd, Ship b){
        int xcord = crd.conseguir_X() + 1;
        int ycord = crd.conseguir_Y() + 1;

        tabA[ycord][xcord] = b.obt_letra();

        if(b.obt_dir() == 'u'){
            for(int i = ycord; i >= ycord - (b.obt_tam() - 1); i--){
                tabA[i][xcord] = b.obt_letra();
            }
        }else if(b.obt_dir() == 'd'){
            for(int i = ycord; i <= ycord + (b.obt_tam() - 1); i++){
                tabA[i][xcord] = b.obt_letra();
            }
        }else if(b.obt_dir() == 'r'){
            for(int i = xcord; i <= xcord + (b.obt_tam() - 1); i++){
                tabA[ycord][i] = b.obt_letra();
            }
        }else if(b.obt_dir() == 'l'){
            for(int i = xcord; i >= xcord - (b.obt_tam() - 1); i--){
                tabA[ycord][i] = b.obt_letra();
            }
        }
    }

    public char[][] obt_tabA(){
        return tabA;
    }
    public char[][] obt_tabB(){
        return tabB;
    }

    public void imprimir_tabA(){
        for (int i = 0; i < tabA.length ; i++){
            System.out.print(i + "| ");
            for (int j =0 ; j < tabA[0].length; j++){
                System.out.print(tabA[i][j] + " | ");
            }
            System.out.println();
            System.out.println("------------------------------------------");
        }
    }

    public void imprimir_tabB(){
        for (int i = 0; i < tabB.length ; i++){
            System.out.print(i + "| ");
            for (int j =0 ; j < tabB[0].length; j++){
                System.out.print(tabB[i][j] + " | ");
            }
            System.out.println();
            System.out.println("------------------------------------------");
        }
    }
}
