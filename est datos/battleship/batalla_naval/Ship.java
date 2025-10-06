package batalla_naval;

public class Ship {
    private int tam;
    private char letra;
    private char direccion;
    public Coordenadas coord;

    public barco(char let, char dir, Coordenadas crd){
        switch (let) {
            case 'P':
                tam = 5; 
                break;
            case 'A':
                tam = 4;
                break;
            case 'C' || 'S':
                tam = 3;
                break;
            default:
                tam = 2;
                break;
        }
    }

    public int obt_tam(){
        return tam;
    }

    public char obt_letra(){
        return letra;
    }

    public char obt_dir(){
        return direccion;
    }

    public Coordenadas obt_coord(){
        return coord;
    }
}
