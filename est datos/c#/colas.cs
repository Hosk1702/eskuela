using System;

class Program {
    static int MAXSIZE = 5;
    static int[] queue = new int[MAXSIZE];
    static int front = -1, rear = -1;

    static void Insertar() {
        Console.Write("\nIngrese el elemento: ");
        // En C# es necesario convertir la entrada de string a int
        if (int.TryParse(Console.ReadLine(), out int elemento)) {
            if (rear == MAXSIZE - 1) {
                Console.WriteLine("\nDESBORDAMIENTO (OVERFLOW)");
                return;
            }

            if (front == -1 && rear == -1) {
                front = rear = 0;
            } else {
                rear++;
            }
            queue[rear] = elemento;
            Console.WriteLine("\nElemento insertado correctamente.");
        } else {
            Console.WriteLine("\nEntrada no válida.");
        }
    }

    static void Eliminar() {
        if (front == -1 || front > rear) {
            Console.WriteLine("\nSUBDESBORDAMIENTO (UNDERFLOW)");
            return;
        }

        int elemento = queue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
        Console.WriteLine("\nElemento eliminado: " + elemento);
    }

    static void Mostrar() {
        if (rear == -1 || front == -1 || front > rear) {
            Console.WriteLine("\nLa cola está vacía.");
        } else {
            Console.WriteLine("\nElementos en la cola:");
            for (int i = front; i <= rear; i++) {
                Console.WriteLine(queue[i]);
            }
        }
    }

    static void Main(string[] args) {
        int opcion = 0;

        while (opcion != 4) {
            Console.WriteLine("\n**************** MENÚ PRINCIPAL ****************");
            Console.WriteLine("================================================");
            Console.WriteLine("1. Insertar un elemento");
            Console.WriteLine("2. Eliminar un elemento");
            Console.WriteLine("3. Mostrar la cola");
            Console.WriteLine("4. Salir");
            Console.Write("Ingrese su opción: ");

            // Lectura segura de la opción
            string input = Console.ReadLine();
            if (!int.TryParse(input, out opcion)) {
                opcion = 0; // Forzar default en switch
            }

            switch (opcion) {
                case 1:
                    Insertar();
                    break;
                case 2:
                    Eliminar();
                    break;
                case 3:
                    Mostrar();
                    break;
                case 4:
                    Console.WriteLine("\nSaliendo del programa...");
                    break;
                default:
                    Console.WriteLine("\nOpción inválida. Intente nuevamente.");
                    break;
            }
        }
    }
}