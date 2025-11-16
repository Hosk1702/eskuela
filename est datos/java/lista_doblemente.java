import java.util.Scanner;

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

// Clase para la Lista Doblemente Enlazada
class ListaDobleEnlazada {
    Nodo head;
    Scanner scanner; // Para leer la entrada del usuario

    public ListaDobleEnlazada(Scanner scanner) {
        this.head = null;
        this.scanner = scanner;
    }

    public void begininsert() {
        System.out.println("\nIngrese valor\n");
        int item = scanner.nextInt();
        Nodo puntero = new Nodo(item);

        puntero.siguiente = head;
        puntero.anterior = null;
        if (head != null) {
            head.anterior = puntero;
        }
        head = puntero;
        System.out.println("\nNodo insertado");
    }

    public void lastinsert() {
        System.out.println("\nIngrese valor?\n");
        int item = scanner.nextInt();
        Nodo puntero = new Nodo(item);

        if (head == null) {
            puntero.siguiente = null;
            puntero.anterior = null;
            head = puntero;
            System.out.println("\nNodo insertado");
        } else {
            Nodo temp = head;
            while (temp.siguiente != null) {
                temp = temp.siguiente;
            }
            temp.siguiente = puntero;
            puntero.anterior = temp;
            puntero.siguiente = null;
            System.out.println("\nNodo insertado");
        }
    }

    public void randominsert() {
        System.out.println("\nIntroduzca el valor del elemento");
        int item = scanner.nextInt();
        Nodo puntero = new Nodo(item);

        System.out.println("\nIntroduce la ubicación (índice 0) después de la cual deseas insertar ");
        int loc = scanner.nextInt();
        Nodo temp = head;

        for (int i = 0; i < loc; i++) {
            if (temp == null) {
                System.out.println("\nNo se puede insertar (ubicación fuera de rango)");
                return;
            }
            temp = temp.siguiente;
        }

        if (temp == null) { // Caso especial si loc=0 y lista vacía
             if (head == null) {
                 head = puntero;
                 System.out.println("\nNodo insertado (en cabeza)");
                 return;
             }
             System.out.println("\nNo se puede insertar (ubicación fuera de rango)");
             return;
        }


        puntero.siguiente = temp.siguiente;
        puntero.anterior = temp;
        if (temp.siguiente != null) {
            temp.siguiente.anterior = puntero;
        }
        temp.siguiente = puntero;
        System.out.println("\nNodo insertado");
    }

    public void begin_delete() {
        if (head == null) {
            System.out.println("\nLa lista está vacía\n");
        } else {
            Nodo puntero = head;
            head = puntero.siguiente;
            if (head != null) {
                head.anterior = null;
            }
            // El recolector de basura de Java se encarga de 'puntero'
            System.out.println("\nNodo eliminado desde el principio ...\n");
        }
    }

    public void last_delete() {
        if (head == null) {
            System.out.println("\nLa lista está vacía");
        } else if (head.siguiente == null) {
            head = null;
            System.out.println("\nSolo se eliminó un nodo de la lista ...\n");
        } else {
            Nodo puntero = head;
            while (puntero.siguiente != null) {
                puntero = puntero.siguiente;
            }
            puntero.anterior.siguiente = null;
            System.out.println("\nNodo eliminado del último ...\n");
        }
    }

    public void random_delete() {
        System.out.println("\nIntroduzca la ubicación (índice 0) del nodo a eliminar.\n");
        int loc = scanner.nextInt();
        
        if(loc == 0){
            begin_delete();
            return;
        }

        Nodo puntero = head;
        for (int i = 0; i < loc; i++) {
            if (puntero == null) {
                System.out.println("\nNo se puede eliminar (ubicación fuera de rango)");
                return;
            }
            puntero = puntero.siguiente;
        }

        if (puntero == null) {
            System.out.println("\nNo se puede eliminar (ubicación fuera de rango)");
            return;
        }

        // puntero es el nodo a eliminar
        puntero.anterior.siguiente = puntero.siguiente;
        if (puntero.siguiente != null) {
            puntero.siguiente.anterior = puntero.anterior;
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

        while (puntero != null) {
            if (puntero.data == item) {
                System.out.println("Elemento encontrado en la ubicación " + (i + 1));
                flag = true;
                break;
            }
            i++;
            puntero = puntero.siguiente;
        }

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
            while (puntero != null) {
                System.out.println(puntero.data);
                puntero = puntero.siguiente;
            }
        }
    }
}

// Clase principal para ejecutar el menú
public class lista_doblemente {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ListaDobleEnlazada lista = new ListaDobleEnlazada(scanner);
        int choice = 0;

        while (choice != 9) {
            System.out.println("\n\n*********Menú principal*********\n");
            System.out.println("\nElige una opción de la siguiente lista ...\n");
            System.out.println("===============================================\n");
            System.out.println("\n1. Insertar al principio\n2. Insertar al final\n3. Insertar en ubicación\n4. Eliminar del principio\n" +
                               "5. Eliminar desde el último\n6. Eliminar nodo en ubicación especificada\n7. Buscar un elemento\n8. Mostrar\n9. Salir\n");
            System.out.println("\nIngrese su opción?\n");
            
            try {
                choice = scanner.nextInt();
            } catch (Exception e) {
                System.out.println("Entrada inválida. Intente de nuevo.");
                scanner.next(); // Limpia el buffer de entrada
                choice = 0; // Fuerza el default
                continue;
            }


            switch (choice) {
                case 1:
                    lista.begininsert();
                    break;
                case 2:
                    lista.lastinsert();
                    break;
                case 3:
                    lista.randominsert();
                    break;
                case 4:
                    lista.begin_delete();
                    break;
                case 5:
                    lista.last_delete();
                    break;
                case 6:
                    lista.random_delete();
                    break;
                case 7:
                    lista.search();
                    break;
                case 8:
                    lista.display();
                    break;
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