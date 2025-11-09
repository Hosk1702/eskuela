using System;

public class Nodo
{
    public int data;
    public Nodo siguiente;

    public Nodo(int d)
    {
        data = d;
        siguiente = null;
    }
}

public class listas
{
    static Nodo head;

    public static void Main(string[] args)
    {
        int choice = 0;
        while (choice != 9)
        {
            Console.WriteLine("\n\n*********Menú principal*********\n");
            Console.WriteLine("\nElige una opción de la siguiente lista ...\n");
            Console.WriteLine("===============================================\n");
            Console.WriteLine("\n1. Insertar al principio\n2. Insertar al final\n3. Insertar \n4. Eliminar del principio\n"
                     + "5. Eliminar desde el último\n6. Eliminar nodo después de la ubicación especificada\n7. Buscar un elemento\n8. Mostrar\n9. Salir\n");
            Console.WriteLine("\nIngrese su opción?\n");
            choice = int.Parse(Console.ReadLine());

            switch (choice)
            {
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
                    Environment.Exit(0);
                    break;
                default:
                    Console.WriteLine("Introduzca una opción válida..");
                    break;
            }
        }
    }

    static void begininsert()
    {
        int item;
        Console.WriteLine("\nIngrese valor\n");
        item = int.Parse(Console.ReadLine());
        Nodo puntero = new Nodo(item);

        puntero.siguiente = head;
        head = puntero;
        Console.WriteLine("\nNodo insertado");
    }

    static void lastinsert()
    {
        Nodo puntero, temp;
        int item;
        Console.WriteLine("\nIngrese valor?\n");
        item = int.Parse(Console.ReadLine());
        puntero = new Nodo(item);

        if (head == null)
        {
            puntero.siguiente = null;
            head = puntero;
            Console.WriteLine("\nNodo insertado");
        }
        else
        {
            temp = head;
            while (temp.siguiente != null)
            {
                temp = temp.siguiente;
            }
            temp.siguiente = puntero;
            puntero.siguiente = null;
            Console.WriteLine("\nNodo insertado");
        }
    }

    static void randominsert()
    {
        int i, loc, item;
        Nodo puntero, temp;
        
        Console.WriteLine("\nIntroduzca el valor del elemento");
        item = int.Parse(Console.ReadLine());
        puntero = new Nodo(item);

        Console.WriteLine("\nIntroduce la ubicación después de la cual deseas insertar ");
        loc = int.Parse(Console.ReadLine());
        
        temp = head;
        for (i = 0; i < loc; i++)
        {
            temp = temp.siguiente;
            if (temp == null)
            {
                Console.WriteLine("\nNo se puede insertar\n");
                return;
            }
        }
        puntero.siguiente = temp.siguiente;
        temp.siguiente = puntero;
        Console.WriteLine("\nNodo insertado");
    }

    static void begin_delete()
    {
        Nodo puntero;
        if (head == null)
        {
            Console.WriteLine("\nLa lista está vacía\n");
        }
        else
        {
            puntero = head;
            head = puntero.siguiente;
            // El recolector de basura se encarga de 'delete'
            Console.WriteLine("\nNodo eliminado desde el principio ...\n");
        }
    }

    static void last_delete()
    {
        Nodo puntero, ptr1 = null;
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
            puntero = head;
            while (puntero.siguiente != null)
            {
                ptr1 = puntero;
                puntero = puntero.siguiente;
            }
            ptr1.siguiente = null;
            Console.WriteLine("\nNodo eliminado del último ...\n");
        }
    }

    static void random_delete()
    {
        Nodo puntero, ptr1 = null;
        int loc, i;
        Console.WriteLine("\nIntroduzca la ubicación del nodo después del cual desea realizar la eliminación.\n");
        loc = int.Parse(Console.ReadLine());
        puntero = head;
        for (i = 0; i < loc; i++)
        {
            ptr1 = puntero;
            puntero = puntero.siguiente;
            if (puntero == null)
            {
                Console.WriteLine("\nNo se puede eliminar");
                return;
            }
        }
        ptr1.siguiente = puntero.siguiente;
        Console.WriteLine("\nNodo eliminado " + (loc + 1));
    }

    static void search()
    {
        Nodo puntero;
        int item, i = 0;
        int flag = 0; // Se inicializa para evitar error
        puntero = head;
        if (puntero == null)
        {
            Console.WriteLine("\nLista vacía\n");
        }
        else
        {
            Console.WriteLine("\nIntroduce el elemento que deseas buscar?\n");
            item = int.Parse(Console.ReadLine());
            while (puntero != null)
            {
                if (puntero.data == item)
                {
                    Console.WriteLine("Elemento encontrado en la ubicación " + (i + 1));
                    flag = 0;
                }
                else
                {
                    flag = 1;
                }
                i++;
                puntero = puntero.siguiente;
            }
            if (flag == 1)
            {
                Console.WriteLine("Elemento no encontrado\n");
            }
        }
    }

    static void display()
    {
        Nodo puntero;
        puntero = head;
        if (puntero == null)
        {
            Console.WriteLine("Nada que imprimir");
        }
        else
        {
            Console.WriteLine("\nimprimiendo valores . . . .\n");
            while (puntero != null)
            {
                Console.WriteLine("\n" + puntero.data);
                puntero = puntero.siguiente;
            }
        }
    }
}