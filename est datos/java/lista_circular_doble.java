import java.util.Scanner;
import java.util.InputMismatchException;

// Clase para el Nodo
class Nodo {
    int data;
    Nodo siguiente;
    Nodo anterior;

    public Nodo(int data) {
        this.data = data;
        this.siguiente = null;
        this.anterior = null;
    }
}

// Clase para la Lista Circular
class ListaDobleCircular {
    Nodo head;
    Nodo tail;
    Scanner scanner;

    public ListaDobleCircular(Scanner scanner) {
        this.head = null;
        this.tail = null;
        this.scanner = scanner;
    }
    
    private int leerEntero(String mensaje) {
        while (true) {
            try {
                System.out.println(mensaje);
                return scanner.nextInt();
            } catch (InputMismatchException e) {
                System.out.println("Entrada inválida. Por favor, ingrese un número.");
                scanner.next(); // Limpia el buffer
            }
        }
    }

    public void begininsert() {
        int item = leerEntero("\nIngrese valor\n");
        Nodo puntero = new Nodo(item);

        if (head == null) {
            head = puntero;
            tail = puntero;
            puntero.siguiente = head;
            puntero.anterior = tail;
        } else {
            puntero.siguiente = head;
            puntero.anterior = tail;
            head.anterior = puntero;
            head = puntero;
            tail.siguiente = head;
        }
        System.out.println("\nNodo insertado");
    }

    public void lastinsert() {
        int item = leerEntero("\nIngrese valor?\n");
        Nodo puntero = new Nodo(item);

        if (head == null) {
            head = puntero;
            tail = puntero;
            puntero.siguiente = head;
            puntero.anterior = tail;
        } else {
            puntero.siguiente = head;
            puntero.anterior = tail;
            head.anterior = puntero;
            tail.siguiente = puntero;
            tail = puntero;
        }
        System.out.println("\nNodo insertado");
    }

    public void randominsert() {
        if (head == null) {
            System.out.println("Lista vacía, insertando al principio.");
            begininsert();
            return;
        }

        int item = leerEntero("\nIntroduzca el valor del elemento");
        int loc = leerEntero("\nIntroduce la ubicación (índice 0) después de la cual deseas insertar ");
        Nodo puntero = new Nodo(item);
        Nodo temp = head;

        for (int i = 0; i < loc; i++) {
            temp = temp.siguiente;
            if (temp == head && i < loc - 1) { // Verificación de vuelta
                System.out.println("\nNo se puede insertar (ubicación fuera de rango)");
                return;
            }
        }

        puntero.siguiente = temp.siguiente;
        puntero.anterior = temp;
        temp.siguiente.anterior = puntero;
        temp.siguiente = puntero;
        
        if (temp == tail) {
            tail = puntero;
        }
        System.out.println("\nNodo insertado");
    }

    public void begin_delete() {
        if (head == null) {
            System.out.println("\nLa lista está vacía\n");
        } else if (head == tail) { // Solo un nodo
            head = null;
            tail = null;
            System.out.println("\nSolo se eliminó un nodo de la lista ...\n");
        } else {
            Nodo puntero = head;
            head = puntero.siguiente;
            head.anterior = tail;
            tail.siguiente = head;
            System.out.println("\nNodo eliminado desde el principio ...\n");
        }
    }

    public void last_delete() {
        if (head == null) {
            System.out.println("\nLa lista está vacía");
        } else if (head == tail) { // Solo un nodo (Lógica corregida)
            head = null;
            tail = null;
            System.out.println("\nSolo se eliminó un nodo de la lista ...\n");
        } else {
            Nodo puntero = tail;
            tail = puntero.anterior;
            tail.siguiente = head;
            head.anterior = tail;
            System.out.println("\nNodo eliminado del último ...\n");
        }
    }

    public void random_delete() {
        // Asumiré "Eliminar EN la ubicación loc"
        int loc = leerEntero("\nIntroduzca la ubicación (índice 0) del nodo a eliminar.\n");

        if (head == null) {
            System.out.println("\nLa lista está vacía");
            return;
        }

        if (loc == 0) {
            begin_delete();
            return;
        }

        Nodo puntero = head;
        for (int i = 0; i < loc; i++) {
            puntero = puntero.siguiente;
            if (puntero == head) {
                 System.out.println("\nNo se puede eliminar (ubicación fuera de rango)");
                 return;
            }
        }
        
        // puntero es el nodo a eliminar
        puntero.anterior.siguiente = puntero.siguiente;
        puntero.siguiente.anterior = puntero.anterior;

        if (puntero == tail) { // Lógica corregida
            tail = puntero.anterior;
        }
        System.out.println("\nNodo eliminado " + loc);
    }

    public void search() {
        if (head == null) {
            System.out.println("\nLista vacía\n");
            return;
        }

        int item = leerEntero("\nIntroduce el elemento que deseas buscar?\n");
        int i = 0;
        boolean flag = false;
        Nodo puntero = head;

        do {
            if (puntero.data == item) {
                System.out.println("Elemento encontrado en la ubicación " + (i + 1));
                flag = true;
                break;
            }
            i++;
            puntero = puntero.siguiente;
        } while (puntero != head);

        if (!flag) {
            System.out.println("Elemento no encontrado\n");
        }
    }

    public void display() {
        Nodo puntero = head;
        if (puntero == null) {
            System.out.println("Nada que imprimir");
        } else {
            System.out.println("\nimprimiendo valores . . . .\n");
            do {
                System.out.println(puntero.data);
                puntero = puntero.siguiente;
            } while (puntero != head);
        }
    }
}

// Clase principal para ejecutar el menú
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ListaDobleCircular lista = new ListaDobleCircular(scanner);
        int choice = 0;

        while (choice != 9) {
            System.out.println("\n\n*********Menú principal*********\n");
            System.out.println("\nElige una opción de la siguiente lista ...\n");
            System.out.println("===============================================\n");
            System.out.println("\n1. Insertar al principio\n2. Insertar al final\n3. Insertar \n4. Eliminar del principio\n" +
                               "5. Eliminar desde el último\n6. Eliminar nodo en ubicación especificada\n7. Buscar un elemento\n8. Mostrar\n9. Salir\n");
            System.out.println("\nIngrese su opción?\n");
            
            try {
                choice = scanner.nextInt();
            } catch (InputMismatchException e) {
                System.out.println("Entrada inválida. Intente de nuevo.");
                scanner.next(); // Limpia el buffer
                choice = 0;
                continue;
            }

            switch (choice) {
                case 1: lista.begininsert(); break;
                case 2: lista.lastinsert(); break;
                case 3: lista.randominsert(); break;
                case 4: lista.begin_delete(); break;
                case 5: lista.last_delete(); break;
                case 6: lista.random_delete(); break;
                case 7: lista.search(); break;
                case 8: lista.display(); break;
                case 9:
                    System.out.println("Saliendo...");
                    System.exit(0);
                    break;
                default:
                    System.out.println("Introduzca una opción válida..");
            }
        }
        scanner.close();
    }
}