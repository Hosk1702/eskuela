import java.util.Scanner;

public class ColaLista {
    
    static class Node {
        int data;
        Node next;
        Node(int d) { data = d; next = null; }
    }

    static Node front = null;
    static Node rear = null;
    static Scanner sc = new Scanner(System.in);

    static void insertar() {
        System.out.print("\nIngrese el elemento: ");
        int val = sc.nextInt();
        Node newNode = new Node(val);

        if (front == null) {
            front = rear = newNode;
        } else {
            rear.next = newNode;
            rear = newNode;
        }
        System.out.println("\nElemento insertado correctamente.");
    }

    static void eliminar() {
        if (front == null) {
            System.out.println("\nSUBDESBORDAMIENTO (La cola esta vacia)");
            return;
        }
        System.out.println("\nElemento eliminado: " + front.data);
        if (front == rear) {
            front = rear = null;
        } else {
            front = front.next;
        }
    }

    static void mostrar() {
        if (front == null) {
            System.out.println("\nLa cola está vacía.");
        } else {
            Node temp = front;
            System.out.println("\nElementos en la cola:");
            while (temp != null) {
                System.out.println(temp.data);
                temp = temp.next;
            }
        }
    }

    public static void main(String[] args) {
        int opcion = 0;
        while (opcion != 4) {
            System.out.println("\n*** MENÚ COLA (LISTA ENLAZADA) ***");
            System.out.println("1. Insertar\n2. Eliminar\n3. Mostrar\n4. Salir");
            System.out.print("Opción: ");
            opcion = sc.nextInt();
            switch (opcion) {
                case 1: insertar(); break;
                case 2: eliminar(); break;
                case 3: mostrar(); break;
                case 4: System.out.println("Saliendo..."); break;
            }
        }
    }
}