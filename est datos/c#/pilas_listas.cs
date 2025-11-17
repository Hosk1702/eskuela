using System;

public class Nodo
{
    public int data;
    public Nodo siguiente;

    public Nodo(int data)
    {
        this.data = data;
        this.siguiente = null;
    }
}

public class PilaConLista
{
    private Nodo top;

    public PilaConLista()
    {
        this.top = null;
    }

    public bool IsEmpty()
    {
        return top == null;
    }

    public void Push(int item)
    {
        Nodo puntero = new Nodo(item);
        puntero.siguiente = top; 
        top = puntero;
    }

    public int Pop()
    {
        if (IsEmpty())
        {
            Console.WriteLine("Stack Underflow");
            return -1; 
        }

        Nodo puntero = top;
        int item = puntero.data;
        top = top.siguiente;
        return item;
    }

    public int Peek()
    {
        if (IsEmpty())
        {
            Console.WriteLine("Stack is empty");
            return -1; 
        }
        return top.data;
    }
}

public class Program
{
    public static void Main(string[] args)
    {
        PilaConLista pila = new PilaConLista();
        
        pila.Push(10);
        pila.Push(20);
        pila.Push(30);

        Console.WriteLine($"Elemento superior: {pila.Peek()}");
        Console.WriteLine($"Extrae el elemento: {pila.Pop()}");
        Console.WriteLine($"Elemento superior despues de pop: {pila.Peek()}");

        Console.WriteLine($"Extrae el elemento: {pila.Pop()}");
        Console.WriteLine($"Extrae el elemento: {pila.Pop()}");
        Console.WriteLine($"Extrae el elemento: {pila.Pop()}"); 
    }
}