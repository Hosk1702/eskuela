package batalla_naval;

public class Tablero {
    
    private char[][] tabA = new char[11][11]; 
    private char[][] tabB = new char[11][11]; 

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
        // Etiqueta 1 a 9
        for (int i = 49; i <=57; i++){
            tabA[num][0] = (char) i;
            tabA[0][num] = (char) i;
            num ++;
        }
        tabA[10][0] = '0'; 
        tabA[0][10] = '0'; 

        for (int i = 1; i < tabA.length ; i++){ 
            for (int j =1 ; j < tabA[0].length; j++){ 
                tabA[i][j] = ' ';
            }         
            }
    }   

    public void inictabB(){
        tabB[0][0] = ' ';
        int num = 1;
        for (int i = 49; i <=57; i++){
            tabB[num][0] = (char) i;
            tabB[0][num] = (char) i;
            num ++;
        }
        tabB[10][0] = '0'; 
        tabB[0][10] = '0'; 

        for (int i = 1; i < tabB.length ; i++){ 
            for (int j =1 ; j < tabB[0].length; j++){ 
                tabB[i][j] = ' ';
            }         
            }
    }   

   

    public boolean posicion_valida(Coordenadas crd, Ship b){
        int xcord = crd.conseguir_X();
        int ycord = crd.conseguir_Y();

        if (xcord < 1 || xcord > 10){ 
            return false;
        }
        if (ycord < 1 || ycord > 10){ 
            return false;
        }

       

        if (b.obt_dir() == 'u'){
            if(ycord - (b.obt_tam() - 1) < 1){
                return false;
            }
           
            for(int i = ycord ; i >= ycord - (b.obt_tam() - 1); i--){
                if(tabA[i][xcord] != ' '){
                    return false;
                }
            }
        } else if(b.obt_dir() == 'd'){ 
            if(ycord + (b.obt_tam() - 1) > 10){ 
                return false;
            }
           
            for(int i = ycord ; i <= ycord + (b.obt_tam() - 1); i++){
                if(tabA[i][xcord] != ' '){
                    return false;
                }
            }
        } else if(b.obt_dir() == 'r'){ 
            if(xcord + (b.obt_tam() - 1) > 10){ 
                return false;
            }
            for(int i = xcord ; i <= xcord + (b.obt_tam() - 1); i++){
                if(tabA[ycord][i] != ' '){
                    return false;
                }
            }
        } else if(b.obt_dir() == 'l'){ 
            
            if(xcord - (b.obt_tam() - 1) < 1){
                return false;
            }
            
            for(int i = xcord ; i >= xcord - (b.obt_tam() - 1); i--){
                if(tabA[ycord][i] != ' '){
                    return false;
                }
            }
        }
        
        return true;   
    }

    public boolean valid_ataque(Coordenadas crd){
        int xcord = crd.conseguir_X();
        int ycord = crd.conseguir_Y()   ;

        if(xcord < 1 || xcord > 10){
            return false;
        }
        
        if(ycord < 1 || ycord > 10){
            return false;
        }

        return true;
    }

    public char resultJBGF(Coordenadas crd, Computadora oponente ){
        int xcord = crd.conseguir_X();
        int ycord = crd.conseguir_Y();

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
            if (numCruceroJB == 3){
                System.out.println("Has hundido los cruceros de tu oponente!");
            }else if(numCruceroJB == 6){
                System.out.println("Has hundido todos los cruceros de tu oponente!");
            }
        }else if(oponente.obt_tabA()[ycord][xcord] == 'S'){
            numSubmarinoJB++;
            if (numSubmarinoJB == 3){
                System.out.println("Has hundido los submarinos de tu oponente!");
            }else if(numSubmarinoJB == 6){
                System.out.println("Has hundido todos los submarinos de tu oponente!");
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
        }else {
            this.obt_tabB()[ycord][xcord] = 'M';
            return 'M';
        }
    }

    public char resultJBGF(Coordenadas crd, Jugador oponente ){
        int xcord = crd.conseguir_X();
        int ycord = crd.conseguir_Y();

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
            if (numCruceroJB == 3){
                System.out.println("Has hundido los cruceros de tu oponente!");
            }else if(numCruceroJB == 6){
                System.out.println("Has hundido todos los cruceros de tu oponente!");
            }
        }else if(oponente.obt_tabA()[ycord][xcord] == 'S'){
            numSubmarinoJB++;
            if (numSubmarinoJB == 3){
                System.out.println("Has hundido los submarinos de tu oponente!");
            }else if(numSubmarinoJB == 6){
                System.out.println("Has hundido todos los submarinos de tu oponente!");
            }
        }else if(oponente.obt_tabA()[ycord][xcord] == 'D'){
            numDesctructorJB++;
            if (numDesctructorJB == 2){
                System.out.println("Has hundido el destructor de tu oponente!");
            }
        }

        char targetChar = oponente.obt_tabA()[ycord][xcord];

        if (targetChar == 'P' || targetChar == 'A' || targetChar == 'C' || targetChar == 'S' || targetChar == 'D') {
            this.obt_tabB()[ycord][xcord] = 'H';
            oponente.obt_tabA()[ycord][xcord] = 'X'; 
            return 'H';
        } else {
            if (targetChar == ' ') { 
                this.obt_tabB()[ycord][xcord] = 'M';
                oponente.obt_tabA()[ycord][xcord] = 'M'; 
            }
            return 'M';
        }
    }

    public char resultJAGF(Coordenadas crd, Jugador oponente){
        int xcord = crd.conseguir_X();
        int ycord = crd.conseguir_Y();


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
                System.out.println("Tu oponente ha hundido uno de tus cruceros!");
            }else if(numCruceroJA == 6){
                System.out.println("Tu oponente ha hundido todos tus cruceros");
            }
        }else if(oponente.obt_tabA()[ycord][xcord] == 'S'){
            numSubmarinoJA++;
            if (numSubmarinoJA == 3){ 
                System.out.println("Tu oponente ha hundido uno de tus submarinos!");
            }else if(numSubmarinoJA == 6){
                System.out.println("Tu oponente ha hundido todos tus submarinos");
            }
        }else if(oponente.obt_tabA()[ycord][xcord] == 'D'){
            numDesctructorJA++;
            if (numDesctructorJA == 2){
                System.out.println("Tu oponente ha hundido tu destructor!");
            }
        }
        
        char targetChar = oponente.obt_tabA()[ycord][xcord];

        
        if (targetChar == 'P' || targetChar == 'A' || targetChar == 'C' || targetChar == 'S' || targetChar == 'D') {
            oponente.obt_tabA()[ycord][xcord] = 'X'; 
            this.obt_tabB()[ycord][xcord] = 'H'; 
            return 'H';
        } else {
            if (targetChar == ' ') { 
                oponente.obt_tabA()[ycord][xcord] = 'M'; 
                this.obt_tabB()[ycord][xcord] = 'M'; 
            }
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
        int xcord = crd.conseguir_X();
        int ycord = crd.conseguir_Y();

        
        tabA[ycord][xcord] = b.obt_letra();

       
        if(b.obt_dir() == 'u'){
            for(int i = ycord - 1; i >= ycord - (b.obt_tam() - 1); i--){
                tabA[i][xcord] = b.obt_letra();
            }
        }else if(b.obt_dir() == 'd'){
            for(int i = ycord + 1; i <= ycord + (b.obt_tam() - 1); i++){
                tabA[i][xcord] = b.obt_letra();
            }
        }else if(b.obt_dir() == 'r'){
            for(int i = xcord + 1; i <= xcord + (b.obt_tam() - 1); i++){
                tabA[ycord][i] = b.obt_letra();
            }
        }else if(b.obt_dir() == 'l'){
            for(int i = xcord - 1; i >= xcord - (b.obt_tam() - 1); i--){
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
        System.out.print("   ");
        
        for (int j = 1; j < tabA[0].length - 1; j++){ 
            System.out.print("| " + tabA[0][j] + " "); 
        }
        System.out.print("| 10");
        System.out.println("|"); 
        
        System.out.println("-------------------------------------------"); 


        
        for (int i = 1; i < tabA.length ; i++){ 
            if(i < 10) { 
                System.out.print(tabA[i][0] + "  |"); 
            } else {
                System.out.print("10 |");
            }
            for (int j = 1 ; j < tabA[0].length; j++){ 
                System.out.print(" " + tabA[i][j] + " |");
            }
            System.out.println();
            System.out.println("-------------------------------------------");
        }
    }

   
    
    public void imprimir_tabB(){
        System.out.print("   "); 
        for (int j = 1; j < tabB[0].length - 1; j++){ 
            System.out.print("| " + tabB[0][j] + " "); 
        }
        System.out.print("| 10");
        System.out.println("|"); 
        System.out.println("-------------------------------------------");

        for (int i = 1; i < tabB.length ; i++){ 
            if(i < 10) { 
                System.out.print(tabB[i][0] + "  |"); 
            } else {
                System.out.print("10 |"); 
            }
            for (int j = 1 ; j < tabB[0].length; j++){ 
                System.out.print(" " + tabB[i][j] + " |");
            }
            System.out.println();
            System.out.println("-------------------------------------------");
        }
    }
}