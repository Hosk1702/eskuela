#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node *front = NULL;
Node *rear = NULL;

void insertar() {
    int val;
    cout << "\nIngrese el elemento: ";
    cin >> val;

    Node *newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << "\nElemento insertado correctamente.\n";
}

void eliminar() {
    if (front == NULL) {
        cout << "\nSUBDESBORDAMIENTO (La cola esta vacia)\n";
        return;
    }
    
    Node *temp = front;
    cout << "\nElemento eliminado: " << front->data << "\n";
    
    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
    }
    delete temp; // Liberar memoria en C++
}

void mostrar() {
    if (front == NULL) {
        cout << "\nLa cola está vacía.\n";
    } else {
        Node *temp = front;
        cout << "\nElementos en la cola:\n";
        while (temp != NULL) {
            cout << temp->data << "\n";
            temp = temp->next;
        }
    }
}

int main() {
    int opcion = 0;
    while (opcion != 4) {
        cout << "\n*** MENÚ COLA (LISTA ENLAZADA) ***\n";
        cout << "1. Insertar\n2. Eliminar\n3. Mostrar\n4. Salir\n";
        cout << "Ingrese opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: insertar(); break;
            case 2: eliminar(); break;
            case 3: mostrar(); break;
            case 4: cout << "Saliendo...\n"; break;
            default: cout << "Opción inválida.\n";
        }
    }
    return 0;
}