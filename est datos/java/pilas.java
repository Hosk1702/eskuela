// Archivo: Pila.java
public class Pila {
    private static final int MAX = 100;
    private int[] stack;
    private int top;

    public Pila() {
        stack = new int[MAX];
        top = -1;
    }

    public void push(int item) {
        if (isFull()) {
            System.out.println("Stack Overflow");
            return;
        }
        stack[++top] = item;
    }

    public int pop() {
        if (isEmpty()) {
            System.out.println("Stack Underflow");
            return -1; // Coincidiendo con la lógica de C++
        }
        return stack[top--];
    }

    public int peek() {
        if (isEmpty()) {
            System.out.println("Stack is empty");
            return -1; // Coincidiendo con la lógica de C++
        }
        return stack[top];
    }

    public boolean isEmpty() {
        return top == -1;
    }

    public boolean isFull() { // Nota: Nombres de función en Java suelen usar camelCase
        return top == MAX - 1;
    }
}

// Archivo: Main.java
public class Main {
    public static void main(String[] args) {
        Pila pila = new Pila();
        pila.push(10);
        pila.push(20);
        pila.push(30);

        System.out.println("Elemento superior: " + pila.peek());
        System.out.println("Extrae el elemento: " + pila.pop());
        System.out.println("Elemento superior despues de pop: " + pila.peek());
    }
}