package batalla_naval;

public class Coordenadas{
    
    private int xcoord;
    private int ycoord;

    public coordenada(){
        xcoord = 1;
        ycoord = 1;
    }

    public coordenada(int x, int y){
        xcoord = x;
        ycoord = y;
    }

    public conseguir_X(){
        return xcoord;
    }
    
    public conseguir_Y(){
        return ycoord;
    }

    public String toString(){
        return "(" + xcoord + "," + ycoord + ")"; 
    }
}
