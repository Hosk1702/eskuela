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

// Clase para la Lista Doblemente Enlazada
public class ListaDobleEnlazada
{
    public Nodo head;

    public ListaDobleEnlazada()
    {
        this.head = null;
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
            catch (OverflowException)
            {
                 Console.WriteLine("Número demasiado grande. Intente de nuevo.");
            }
        }
    }


    public void begininsert()
    {
        int item = LeerEntero("\nIngrese valor\n");
        Nodo puntero = new Nodo(item);
        // En C#, 'new' lanzará una OutOfMemoryException si falla, similar a OVERFLOW

        puntero.siguiente = head;
        puntero.anterior = null;
        if (head != null)
        {
            head.anterior = puntero;
        }
        head = puntero;
        Console.WriteLine("\nNodo insertado");
    }

    public void lastinsert()
    {
        int item = LeerEntero("\nIngrese valor?\n");
        Nodo puntero = new Nodo(item);

        if (head == null)
        {
            puntero.siguiente = null;
            puntero.anterior = null;
            head = puntero;
            Console.WriteLine("\nNodo insertado");
        }
        else
        {
            Nodo temp = head;
            while (temp.siguiente != null)
            {
                temp = temp.siguiente;
            }
            temp.siguiente = puntero;
            puntero.anterior = temp;
            puntero.siguiente = null;
            Console.WriteLine("\nNodo insertado");
        }
    }

    public void randominsert()
    {
        int item = LeerEntero("\nIntroduzca el valor del elemento");
        int loc = LeerEntero("\nIntroduce la ubicación (índice 0) después de la cual deseas insertar ");
        Nodo puntero = new Nodo(item);
        
        Nodo temp = head;

        for (int i = 0; i < loc; i++)
        {
            if (temp == null)
            {
                Console.WriteLine("\nNo se puede insertar (ubicación fuera de rango)");
                return;
            }
            temp = temp.siguiente;
        }

        if (temp == null) // Caso especial si loc=0 y lista vacía
        {
             if (head == null) {
                 head = puntero;
                 Console.WriteLine("\nNodo insertado (en cabeza)");
                 return;
             }
             Console.WriteLine("\nNo se puede insertar (ubicación fuera de rango)");
             return;
        }

        puntero.siguiente = temp.siguiente;
        puntero.anterior = temp;
        if (temp.siguiente != null)
        {
            temp.siguiente.anterior = puntero;
        }
        temp.siguiente = puntero;
        Console.WriteLine("\nNodo insertado");
    }

    public void begin_delete()
    {
        if (head == null)
        {
            Console.WriteLine("\nLa lista está vacía\n");
        }
        else
        {
            Nodo puntero = head;
            head = puntero.siguiente;
            if (head != null)
            {
                head.anterior = null;
            }
            // El recolector de basura de C# se encarga de 'puntero'
            Console.WriteLine("\nNodo eliminado desde el principio ...\n");
        }
    }

    public void last_delete()
    {
        if (head == null)
        {
            Console.WriteLine("\nLa lista está vacía");
        }
        else if (head.siguiente == null)
        {
            head = null;
            Console.WriteLine("\nSolo se eliminó un nodo de la lista ...\n");
        }
        else
        {
            Nodo puntero = head;
            while (puntero.siguiente != null)
            {
                puntero = puntero.siguiente;
            }
            puntero.anterior.siguiente = null;
            Console.WriteLine("\nNodo eliminado del último ...\n");
        }
    }

    public void random_delete()
    {
        int loc = LeerEntero("\nIntroduzca la ubicación (índice 0) del nodo a eliminar.\n");

        if(loc == 0){
            begin_delete();
            return;
        }

        Nodo puntero = head;
        for (int i = 0; i < loc; i++)
        {
            if (puntero == null)
            {
                Console.WriteLine("\nNo se puede eliminar (ubicación fuera de rango)");
                return;
            }
            puntero = puntero.siguiente;
        }

        if (puntero == null)
        {
            Console.WriteLine("\nNo se puede eliminar (ubicación fuera de rango)");
            return;
        }

        // puntero es el nodo a eliminar
        puntero.anterior.siguiente = puntero.siguiente;
        if (puntero.siguiente != null)
        {
            puntero.siguiente.anterior = puntero.anterior;
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

        while (puntero != null)
        {
            if (puntero.data == item)
            {
                Console.WriteLine("Elemento encontrado en la ubicación " + (i + 1));
                flag = true;
                break;
            }
            i++;
            puntero = puntero.siguiente;
        }

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
            while (puntero != null)
            {
                Console.WriteLine(puntero.data);
                puntero = puntero.siguiente;
            }
        }
    }
}

// Clase principal para ejecutar el menú
class lista_doblemente
{
    static void Main(string[] args)
    {
        ListaDobleEnlazada lista = new ListaDobleEnlazada();
        int choice = 0;

        while (choice != 9)
        {
            Console.WriteLine("\n\n*********Menú principal*********\n");
            Console.WriteLine("\nElige una opción de la siguiente lista ...\n");
            Console.WriteLine("===============================================\n");
            Console.WriteLine("\n1. Insertar al principio\n2. Insertar al final\n3. Insertar en ubicación\n4. Eliminar del principio\n" +
                               "5. Eliminar desde el último\n6. Eliminar nodo en ubicación especificada\n7. Buscar un elemento\n8. Mostrar\n9. Salir\n");
            Console.WriteLine("\nIngrese su opción?\n");

            try
            {
                choice = Convert.ToInt32(Console.ReadLine());
            }
            catch (Exception)
            {
                choice = 0; // Fuerza el default
            }

            switch (choice)
            {
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