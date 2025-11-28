import java.util.Scanner;

public class ColaArray {
    static final int MAXSIZE = 5;
    static int[] queue = new int[MAXSIZE];
    static int front = -1;
    static int rear = -1;
    static Scanner sc = new Scanner(System.in);

    static void insertar() {
        System.out.print("\nIngrese el elemento: ");
        int elemento = sc.nextInt();
        
        if (rear == MAXSIZE - 1) {
            System.out.println("\nDESBORDAMIENTO (OVERFLOW)");
            return;
        }
        
        if (front == -1 && rear == -1) {
            front = 0;
            rear = 0;
        } else {
            rear++;
        }
        queue[rear] = elemento;
        System.out.println("\nElemento insertado correctamente.");
    }

    static void eliminar() {
        if (front == -1 || front > rear) {
            System.out.println("\nSUBDESBORDAMIENTO (UNDERFLOW)");
            return;
        }
        
        int elemento = queue[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
        System.out.println("\nElemento eliminado: " + elemento);
    }

    static void mostrar() {
        if (rear == -1 || front == -1 || front > rear) {
            System.out.println("\nLa cola está vacía.");
        } else {
            System.out.println("\nElementos en la cola:");
            for (int i = front; i <= rear; i++) {
                System.out.println(queue[i]);
            }
        }
    }

    public static void main(String[] args) {
        int opcion = 0;
        while (opcion != 4) {
            System.out.println("\n**************** MENÚ PRINCIPAL ****************");
            System.out.println("================================================");
            System.out.println("1. Insertar un elemento");
            System.out.println("2. Eliminar un elemento");
            System.out.println("3. Mostrar la cola");
            System.out.println("4. Salir");
            System.out.print("Ingrese su opción: ");
            
            opcion = sc.nextInt();

            switch (opcion) {
                case 1: insertar(); break;
                case 2: eliminar(); break;
                case 3: mostrar(); break;
                case 4: System.out.println("\nSaliendo del programa..."); break;
                default: System.out.println("\nOpción inválida. Intente nuevamente.");
            }
        }
        sc.close();
    }
}