using System;

// Clase para el Nodo
public class Nodo
{
    public int data;
    public Nodo siguiente;
    public Nodo anterior;

    public Nodo(int data)
    {
        this.data = data;
        this.siguiente = null;
        this.anterior = null;
    }
}

// Clase para la Lista Circular
public class ListaDobleCircular
{
    public Nodo head;
    public Nodo tail;

    public ListaDobleCircular()
    {
        this.head = null;
        this.tail = null;
    }

    // Método para leer un entero de forma segura
    private int LeerEntero(string mensaje)
    {
        while (true)
        {
            Console.WriteLine(mensaje);
            try
            {
                return Convert.ToInt32(Console.ReadLine());
            }
            catch (FormatException)
            {
                Console.WriteLine("Entrada inválida. Por favor, ingrese un número.");
            }
        }
    }

    public void begininsert()
    {
        int item = LeerEntero("\nIngrese valor\n");
        Nodo puntero = new Nodo(item);

        if (head == null)
        {
            head = puntero;
            tail = puntero;
            puntero.siguiente = head;
            puntero.anterior = tail;
        }
        else
        {
            puntero.siguiente = head;
            puntero.anterior = tail;
            head.anterior = puntero;
            head = puntero;
            tail.siguiente = head;
        }
        Console.WriteLine("\nNodo insertado");
    }

    public void lastinsert()
    {
        int item = LeerEntero("\nIngrese valor?\n");
        Nodo puntero = new Nodo(item);

        if (head == null)
        {
            head = puntero;
            tail = puntero;
            puntero.siguiente = head;
            puntero.anterior = tail;
        }
        else
        {
            puntero.siguiente = head;
            puntero.anterior = tail;
            head.anterior = puntero;
            tail.siguiente = puntero;
            tail = puntero;
        }
        Console.WriteLine("\nNodo insertado");
    }

    public void randominsert()
    {
        if (head == null)
        {
            Console.WriteLine("Lista vacía, insertando al principio.");
            begininsert();
            return;
        }
        
        int item = LeerEntero("\nIntroduzca el valor del elemento");
        // Inserta DESPUÉS de la ubicación (índice 0)
        int loc = LeerEntero("\nIntroduce la ubicación (índice 0) después de la cual deseas insertar ");
        Nodo puntero = new Nodo(item);
        Nodo temp = head;

        for (int i = 0; i < loc; i++)
        {
            temp = temp.siguiente;
            if (temp == head && i < loc - 1) // Verificación de vuelta
            {
                Console.WriteLine("\nNo se puede insertar (ubicación fuera de rango)");
                return;
            }
        }

        puntero.siguiente = temp.siguiente;
        puntero.anterior = temp;
        temp.siguiente.anterior = puntero;
        temp.siguiente = puntero;
        
        if (temp == tail)
        {
            tail = puntero;
        }
        Console.WriteLine("\nNodo insertado");
    }

    public void begin_delete()
    {
        if (head == null)
        {
            Console.WriteLine("\nLa lista está vacía\n");
        }
        else if (head == tail) // Solo un nodo
        {
            head = null;
            tail = null;
            Console.WriteLine("\nSolo se eliminó un nodo de la lista ...\n");
        }
        else
        {
            Nodo puntero = head;
            head = puntero.siguiente;
            head.anterior = tail;
            tail.siguiente = head;
            Console.WriteLine("\nNodo eliminado desde el principio ...\n");
        }
    }

    public void last_delete()
    {
        if (head == null)
        {
            Console.WriteLine("\nLa lista está vacía");
        }
        else if (head == tail) // Solo un nodo (Lógica corregida)
        {
            head = null;
            tail = null;
            Console.WriteLine("\nSolo se eliminó un nodo de la lista ...\n");
        }
        else
        {
            Nodo puntero = tail;
            tail = puntero.anterior;
            tail.siguiente = head;
            head.anterior = tail;
            Console.WriteLine("\nNodo eliminado del último ...\n");
        }
    }

    public void random_delete()
    {
        // Asumiré "Eliminar EN la ubicación loc"
        int loc = LeerEntero("\nIntroduzca la ubicación (índice 0) del nodo a eliminar.\n");
        
        if (head == null)
        {
            Console.WriteLine("\nLa lista está vacía");
            return;
        }

        if (loc == 0)
        {
            begin_delete();
            return;
        }

        Nodo puntero = head;
        for (int i = 0; i < loc; i++)
        {
            puntero = puntero.siguiente;
            if (puntero == head)
            {
                 Console.WriteLine("\nNo se puede eliminar (ubicación fuera de rango)");
                 return;
            }
        }
        
        // puntero es el nodo a eliminar
        puntero.anterior.siguiente = puntero.siguiente;
        puntero.siguiente.anterior = puntero.anterior;

        if (puntero == tail) // Lógica corregida
        {
            tail = puntero.anterior;
        }
        Console.WriteLine("\nNodo eliminado " + loc);
    }

    public void search()
    {
        if (head == null)
        {
            Console.WriteLine("\nLista vacía\n");
            return;
        }

        int item = LeerEntero("\nIntroduce el elemento que deseas buscar?\n");
        int i = 0;
        bool flag = false;
        Nodo puntero = head;

        do
        {
            if (puntero.data == item)
            {
                Console.WriteLine("Elemento encontrado en la ubicación " + (i + 1));
                flag = true;
                break;
            }
            i++;
            puntero = puntero.siguiente;
        } while (puntero != head);

        if (!flag)
        {
            Console.WriteLine("Elemento no encontrado\n");
        }
    }

    public void display()
    {
        Nodo puntero = head;
        if (puntero == null)
        {
            Console.WriteLine("Nada que imprimir");
        }
        else
        {
            Console.WriteLine("\nimprimiendo valores . . . .\n");
            do
            {
                Console.WriteLine(puntero.data);
                puntero = puntero.siguiente;
            } while (puntero != head);
        }
    }
}

// Clase principal para ejecutar el menú
class Program
{
    static void Main(string[] args)
    {
        ListaDobleCircular lista = new ListaDobleCircular();
        int choice = 0;

        while (choice != 9)
        {
            Console.WriteLine("\n\n*********Menú principal*********\n");
            Console.WriteLine("\nElige una opción de la siguiente lista ...\n");
            Console.WriteLine("===============================================\n");
            Console.WriteLine("\n1. Insertar al principio\n2. Insertar al final\n3. Insertar \n4. Eliminar del principio\n" +
                               "5. Eliminar desde el último\n6. Eliminar nodo en ubicación especificada\n7. Buscar un elemento\n8. Mostrar\n9. Salir\n");
            
            try
            {
                choice = Convert.ToInt32(Console.ReadLine());
            }
            catch (Exception)
            {
                Console.WriteLine("Introduzca una opción válida..");
                choice = 0; // Fuerza el default
                continue;
            }

            switch (choice)
            {
                case 1: lista.begininsert(); break;
                case 2: lista.lastinsert(); break;
                case 3: lista.randominsert(); break;
                case 4: lista.begin_delete(); break;
                case 5: lista.last_delete(); break;
                case 6: lista.random_delete(); break;
                case 7: lista.search(); break;
                case 8: lista.display(); break;
                case 9:
                    Console.WriteLine("Saliendo...");
                    Environment.Exit(0);
                    break;
                default:
                    Console.WriteLine("Introduzca una opción válida..");
                    break;
            }
        }
    }
}