#include <iostream>
#include <string>
using namespace std;

// Definición de la clase Libro
class Libro {
//inicializamos variables en private
    private:
 string titulo;
 string autor;
//métodos en public
 public:
 //constructor
 Libro(string t, string a) : titulo(t), autor(a) {}
    //método para mostrar información del libro
void libritos() {
    cout << "Titulo: " << titulo << ", Autor: " << autor << endl;
}

};

int main() {
    //Crear un arreglo de libritos
    Libro blibliotequita[] = {
        Libro("Berserk", "Kentaro Miura"),
        Libro("EL niño y la garza", "Ghibli"),
        Libro("Cien años de soledad", "Gabriel García Márquez")
    };

    int tam = sizeof(blibliotequita) / sizeof(blibliotequita[0]);

    for (int i = 0; i< tam ; i++){
        blibliotequita[i].libritos();
    };

    return 0;
};