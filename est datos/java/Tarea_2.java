public class Tarea_2 {
    public static void main(String[] args) {
        //arreglo de objetos de la clase Libro
        Libro[] blibiotequita = {
            new Libro("Naruto", "Masashi Kishimoto"), // Crear un objeto Libro con título y autor
            new Libro("One Piece", "Eiichiro Oda"),
            new Libro("Death Note", "Tsugumi Ohba")
        };
        // Mostrar la información de cada libro en la biblioteca
        for (Libro Libro : blibiotequita){
            Libro.mostrar();
        }
    }

    // Definición de la clase Libro
    static class Libro {
        private String titulo; // Atributo para el título del libro
        private String autor; // Atributo para el autor del libro

        public Libro(String titulo, String autor) {// Constructor para inicializar los atributos
            this.titulo = titulo; // Inicializa el título
            this.autor = autor; // Inicializa el autor
        }

        public void mostrar() { // Método para mostrar la información del libro
            System.out.println("Título: " + titulo + ", Autor: " + autor);// Imprime el título y el autor del libro
        }


    }
    }
