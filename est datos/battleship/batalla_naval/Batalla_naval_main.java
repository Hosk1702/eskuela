package batalla_naval;

public class Batalla_naval_main {
    public static void main(String[] args) {
        Jugador j1 = new Jugador();
        Computadora c = new Computadora();

        System.out.println("Bienvenido al juego batalla naval!. Estaras jugando contra la computadora.");
        j1.posionamiento_de_piezas();
        c.comp_armado();

        while (!j1.buscar_ganador(c) && !c.buscar_ganadorC(j1)) {
            Coordenadas ataque_a_comp = j1.ataque_del_jugador();
            j1.fuego_ataque_JB(c, ataque_a_comp);

            Coordenadas ataque_a_j = c.obt_predict_coord(j1);
            c.fuego_ataque_JA(j1, ataque_a_j);

            System.out.println("TABLERO A: ");
            j1.imprimir_tab(j1.obt_tabA());
            
            System.out.println("TABLERO B: ");
            j1.imprimir_tab(j1.obt_tabB());
        }

        if(j1.buscar_ganador(c)){
            System.out.println("JUEGO TERMINADO! FELICIDADES HAS GANADO!!");
        } else {
            System.out.println("JUEGO TERMINADO! HAS PERDIDO MEJOR SUERTE LA PROXIMA!");
        }
    }
}
