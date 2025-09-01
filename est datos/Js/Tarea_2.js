class Libro {
    constructor(titulo, autor) {
        this.titulo = titulo;
        this.autor = autor;
    }

    mostrar() {
        console.log(`Título: ${this.titulo}, Autor: ${this.autor}`);
    }
}

// Crear un arreglo de libros
const biblioteca = [
    new Libro("Cien años de soledad", "Gabriel García Márquez"),
    new Libro("El principito", "Antoine de Saint-Exupéry"),
    new Libro("Berserk", "Kentaro Miura")
];

// Usar los métodos de cada objeto
for (const libro of biblioteca) {
    libro.mostrar();
}