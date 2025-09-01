class Libro:
    def __init__(self, titulo, autor):
        self.titulo = titulo
        self.autor = autor

    def mostrar(self):
        print(f"Título: {self.titulo}, Autor: {self.autor}")

        
# Crear una lista (arreglo) de libros
biblioteca = [
    Libro("Cien años de soledad", "Gabriel García Márquez"),
    Libro("El principito", "Antoine de Saint-Exupéry"),
    Libro("Berserk", "Kentaro Miura")
]

# Usar los métodos de cada objeto
for libro in biblioteca:
    libro.mostrar()