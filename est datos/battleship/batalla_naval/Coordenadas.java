package batalla_naval;

public class Coordenadas{
    
    private int xcoord;
    private int ycoord;

    public Coordenadas(){
        xcoord = 1;
        ycoord = 1;
    }

    public Coordenadas(int x, int y){
        xcoord = x;
        ycoord = y;
    }

    public int conseguir_X(){
        return xcoord;
    }

    public int conseguir_Y(){
        return ycoord;
    }

    public String toString(){
        return "(" + xcoord + "," + ycoord + ")"; 
    }
}
