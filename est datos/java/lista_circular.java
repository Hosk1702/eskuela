import java.util.Scanner;

// Clase para el Nodo
class Nodo {
    int data;
    Nodo siguiente;

    public Nodo(int data) {
        this.data = data;
        this.siguiente = null;
    }
}

// Clase para la Lista Circular
class ListaCircular {
    Nodo head;
    Nodo tail;
    Scanner scanner;

    public ListaCircular(Scanner scanner) {
        this.head = null;
        this.tail = null;
        this.scanner = scanner;
    }

    public void begininsert() {
        System.out.println("\nIngrese valor\n");
        int item = scanner.nextInt();
        Nodo puntero = new Nodo(item);

        if (head == null) {
            head = puntero;
            tail = puntero;
            puntero.siguiente = head;
        } else {
            puntero.siguiente = head;
            head = puntero;
            tail.siguiente = head;
        }
        System.out.println("\nNodo insertado");
    }

    public void lastinsert() {
        System.out.println("\nIngrese valor?\n");
        int item = scanner.nextInt();
        Nodo puntero = new Nodo(item);

        if (head == null) {
            head = puntero;
            tail = puntero;
            puntero.siguiente = head;
        } else {
            puntero.siguiente = head;
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

        System.out.println("\nIntroduzca el valor del elemento");
        int item = scanner.nextInt();
        Nodo puntero = new Nodo(item);

        System.out.println("\nIntroduce la ubicación (índice 0) después de la cual deseas insertar ");
        int loc = scanner.nextInt();
        Nodo temp = head;

        for (int i = 0; i < loc; i++) {
            temp = temp.siguiente;
            if (temp == head) {
                System.out.println("\nNo se puede insertar (ubicación fuera de rango)");
                return;
            }
        }

        puntero.siguiente = temp.siguiente;
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
            tail.siguiente = head;
            // El recolector de basura de Java se encarga de 'puntero'
            System.out.println("\nNodo eliminado desde el principio ...\n");
        }
    }

    public void last_delete() {
        if (head == null) {
            System.out.println("\nLa lista está vacía");
        } else if (head == tail) { // Solo un nodo (Corrección de lógica)
            head = null;
            tail = null;
            System.out.println("\nSolo se eliminó un nodo de la lista ...\n");
        } else {
            Nodo puntero = head;
            Nodo ptr1 = null;
            while (puntero.siguiente != head) {
                ptr1 = puntero;
                puntero = puntero.siguiente;
            }
            // puntero es el tail, ptr1 es el anterior
            ptr1.siguiente = head;
            tail = ptr1;
            System.out.println("\nNodo eliminado del último ...\n");
        }
    }

    public void random_delete() {
        System.out.println("\nIntroduzca la ubicación (índice 0) del nodo a eliminar.\n");
        int loc = scanner.nextInt();

        if (head == null) {
            System.out.println("\nLa lista está vacía");
            return;
        }

        if (loc == 0) {
            begin_delete();
            return;
        }

        Nodo puntero = head;
        Nodo ptr1 = null;

        for (int i = 0; i < loc; i++) {
            if (puntero.siguiente == head && i < loc - 1) {
                 System.out.println("\nNo se puede eliminar (ubicación fuera de rango)");
                 return;
            }
            ptr1 = puntero;
            puntero = puntero.siguiente;
            
            // Si da la vuelta completa sin terminar el 'for'
            if (puntero == head && i < loc -1){
                 System.out.println("\nNo se puede eliminar (ubicación fuera de rango)");
                 return;
            }
        }
        
        // puntero es el nodo a eliminar, ptr1 es el anterior
        ptr1.siguiente = puntero.siguiente;
        if (puntero == tail) { // Corrección: Checar si el nodo eliminado era el tail
            tail = ptr1;
        }
        System.out.println("\nNodo eliminado " + loc);
    }

    public void search() {
        if (head == null) {
            System.out.println("\nLista vacía\n");
            return;
        }

        System.out.println("\nIntroduce el elemento que deseas buscar?\n");
        int item = scanner.nextInt();
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
public class lista_circular {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ListaCircular lista = new ListaCircular(scanner);
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
            } catch (Exception e) {
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