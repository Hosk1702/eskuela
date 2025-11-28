using System;

class Program {
    
    class Node {
        public int data;
        public Node next;
        public Node(int d) { data = d; next = null; }
    }

    static Node front = null;
    static Node rear = null;

    static void Insertar() {
        Console.Write("\nIngrese el elemento: ");
        if (int.TryParse(Console.ReadLine(), out int val)) {
            Node newNode = new Node(val);

            if (front == null) {
                front = rear = newNode;
            } else {
                rear.next = newNode;
                rear = newNode;
            }
            Console.WriteLine("\nElemento insertado correctamente.");
        }
    }

    static void Eliminar() {
        if (front == null) {
            Console.WriteLine("\nSUBDESBORDAMIENTO (La cola esta vacia)");
            return;
        }

        Console.WriteLine("\nElemento eliminado: " + front.data);

        if (front == rear) {
            front = rear = null;
        } else {
            front = front.next;
        }
    }

    static void Mostrar() {
        if (front == null) {
            Console.WriteLine("\nLa cola está vacía.");
        } else {
            Node temp = front;
            Console.WriteLine("\nElementos en la cola:");
            while (temp != null) {
                Console.WriteLine(temp.data);
                temp = temp.next;
            }
        }
    }

    static void Main(string[] args) {
        int opcion = 0;
        while (opcion != 4) {
            Console.WriteLine("\n*** MENÚ COLA (LISTA ENLAZADA) ***");
            Console.WriteLine("1. Insertar\n2. Eliminar\n3. Mostrar\n4. Salir");
            Console.Write("Opción: ");
            
            if (!int.TryParse(Console.ReadLine(), out opcion)) opcion = 0;

            switch (opcion) {
                case 1: Insertar(); break;
                case 2: Eliminar(); break;
                case 3: Mostrar(); break;
                case 4: Console.WriteLine("Saliendo..."); break;
                default: Console.WriteLine("Opción inválida."); break;
            }
        }
    }
}