import java.util.Scanner;

class Nodo {
    int data;
    Nodo siguiente;

    public Nodo(int d) {
        data = d;
        siguiente = null;
    }
}

public class Listas {
    static Nodo head;
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int choice = 0;
        while (choice != 9) {
            System.out.println("\n\n*********Menú principal*********\n");
            System.out.println("\nElige una opción de la siguiente lista ...\n");
            System.out.println("===============================================\n");
            System.out.println("\n1. Insertar al principio\n2. Insertar al final\n3. Insertar \n4. Eliminar del principio\n"
                    + "5. Eliminar desde el último\n6. Eliminar nodo después de la ubicación especificada\n7. Buscar un elemento\n8. Mostrar\n9. Salir\n");
            System.out.println("\nIngrese su opción?\n");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    begininsert();
                    break;
                case 2:
                    lastinsert();
                    break;
                case 3:
                    randominsert();
                    break;
                case 4:
                    begin_delete();
                    break;
                case 5:
                    last_delete();
                    break;
                case 6:
                    random_delete();
                    break;
                case 7:
                    search();
                    break;
                case 8:
                    display();
                    break;
                case 9:
                    System.exit(0);
                    break;
                default:
                    System.out.println("Introduzca una opción válida..");
            }
        }
    }

    static void begininsert() {
        int item;
        System.out.println("\nIngrese valor\n");
        item = scanner.nextInt();
        Nodo puntero = new Nodo(item);

        puntero.siguiente = head;
        head = puntero;
        System.out.println("\nNodo insertado");
    }

    static void lastinsert() {
        Nodo puntero, temp;
        int item;
        System.out.println("\nIngrese valor?\n");
        item = scanner.nextInt();
        puntero = new Nodo(item);

        if (head == null) {
            puntero.siguiente = null;
            head = puntero;
            System.out.println("\nNodo insertado");
        } else {
            temp = head;
            while (temp.siguiente != null) {
                temp = temp.siguiente;
            }
            temp.siguiente = puntero;
            puntero.siguiente = null;
            System.out.println("\nNodo insertado");
        }
    }

    static void randominsert() {
        int i, loc, item;
        Nodo puntero, temp;
        
        System.out.println("\nIntroduzca el valor del elemento");
        item = scanner.nextInt();
        puntero = new Nodo(item);

        System.out.println("\nIntroduce la ubicación después de la cual deseas insertar ");
        loc = scanner.nextInt();
        
        temp = head;
        for (i = 0; i < loc; i++) {
            temp = temp.siguiente;
            if (temp == null) {
                System.out.println("\nNo se puede insertar\n");
                return;
            }
        }
        puntero.siguiente = temp.siguiente;
        temp.siguiente = puntero;
        System.out.println("\nNodo insertado");
    }

    static void begin_delete() {
        Nodo puntero;
        if (head == null) {
            System.out.println("\nLa lista está vacía\n");
        } else {
            puntero = head;
            head = puntero.siguiente;
            // El recolector de basura se encarga de 'delete'
            System.out.println("\nNodo eliminado desde el principio ...\n");
        }
    }

    static void last_delete() {
        Nodo puntero, ptr1 = null;
        if (head == null) {
            System.out.println("\nLa lista está vacía");
        } else if (head.siguiente == null) {
            head = null;
            System.out.println("\nSolo se eliminó un nodo de la lista ...\n");
        } else {
            puntero = head;
            while (puntero.siguiente != null) {
                ptr1 = puntero;
                puntero = puntero.siguiente;
            }
            ptr1.siguiente = null;
            System.out.println("\nNodo eliminado del último ...\n");
        }
    }

    static void random_delete() {
        Nodo puntero, ptr1 = null;
        int loc, i;
        System.out.println("\nIntroduzca la ubicación del nodo después del cual desea realizar la eliminación.\n");
        loc = scanner.nextInt();
        puntero = head;
        for (i = 0; i < loc; i++) {
            ptr1 = puntero;
            puntero = puntero.siguiente;
            if (puntero == null) {
                System.out.println("\nNo se puede eliminar");
                return;
            }
        }
        ptr1.siguiente = puntero.siguiente;
        System.out.println("\nNodo eliminado " + (loc + 1));
    }

    static void search() {
        Nodo puntero;
        int item, i = 0;
        int flag = 0;
        puntero = head;
        if (puntero == null) {
            System.out.println("\nLista vacía\n");
        } else {
            System.out.println("\nIntroduce el elemento que deseas buscar?\n");
            item = scanner.nextInt();
            while (puntero != null) {
                if (puntero.data == item) {
                    System.out.println("Elemento encontrado en la ubicación " + (i + 1));
                    flag = 0;
                } else {
                    flag = 1;
                }
                i++;
                puntero = puntero.siguiente;
            }
            if (flag == 1) {
                System.out.println("Elemento no encontrado\n");
            }
        }
    }

    static void display() {
        Nodo puntero;
        puntero = head;
        if (puntero == null) {
            System.out.println("Nada que imprimir");
        } else {
            System.out.println("\nimprimiendo valores . . . .\n");
            while (puntero != null) {
                System.out.println("\n" + puntero.data);
                puntero = puntero.siguiente;
            }
        }
    }
}