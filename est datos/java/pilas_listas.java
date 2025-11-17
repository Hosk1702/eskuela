class Nodo {
    int data;
    Nodo siguiente;

    public Nodo(int data) {
        this.data = data;
        this.siguiente = null;
    }
}

public class PilaConLista {
    private Nodo top;

    public PilaConLista() {
        this.top = null;
    }

    public boolean isEmpty() {
        return top == null;
    }

    public void push(int item) {
        Nodo puntero = new Nodo(item);
        puntero.siguiente = top;
        top = puntero;
    }

    public int pop() {
        if (isEmpty()) {
            System.out.println("Stack Underflow");
            return -1; 
        }

        Nodo puntero = top;
        int item = puntero.data;
        top = top.siguiente;
        return item;
    }

    public int peek() {
        if (isEmpty()) {
            System.out.println("Stack is empty");
            return -1; 
        }
        return top.data;
    }
}

public class Main {
    public static void main(String[] args) {
        PilaConLista pila = new PilaConLista();
        
        pila.push(10);
        pila.push(20);
        pila.push(30);

        System.out.println("Elemento superior: " + pila.peek());
        System.out.println("Extrae el elemento: " + pila.pop());
        System.out.println("Elemento superior despues de pop: " + pila.peek());

        System.out.println("Extrae el elemento: " + pila.pop());
        System.out.println("Extrae el elemento: " + pila.pop());
        System.out.println("Extrae el elemento: " + pila.pop()); 
    }
}