using System;
class Libro
{
    private string title;
    private string author;

    public Libro(string title, string author){
        this.title = title;
        this.author = author;
    }

    public void enseñar(){
        Console.WriteLine($"Título: {this.title}, Autor: {this.author}");
    }
    
};

class Program
{
    static void Main(string[] args)
    { 
        Libro[] biblioteca = new Libro[]
        {
            new Libro("Cien años de soledad", "Gabriel García Márquez"),
            new Libro("El principito", "Antoine de Saint-Exupéry"),
            new Libro("Berserk", "Kentaro Miura")
        };

        foreach (var libro in biblioteca)
        {
            libro.enseñar();
        }
    }

 };