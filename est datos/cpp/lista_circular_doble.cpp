#include <iostream>
#include <cstdlib>
using namespace std;

struct nodo {
    int data;
    struct nodo *siguiente;
    struct nodo *anterior;
};

struct nodo *head;
struct nodo *tail;

void begininsert();
void lastinsert();
void randominsert();
void begin_delete();
void last_delete();
void random_delete();
void display();
void search();

int main() {
    int choice = 0;
    while (choice != 9) {
        cout << "\n\n*********Menú principal*********\n";
        cout << "\nElige una opción de la siguiente lista ...\n";
        cout << "===============================================\n";
        cout << "\n1. Insertar al principio\n2. Insertar al final\n3. Insertar \n4. Eliminar del principio\n"
             << "5. Eliminar desde el último\n6. Eliminar nodo después de la ubicación especificada\n7. Buscar un elemento\n8. Mostrar\n9. Salir\n";
        cout << "\nIngrese su opción?\n";
        cin >> choice;
        switch (choice) {
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
                exit(0);
                break;
            default:
                cout << "Introduzca una opción válida..";
        }
    }
    return 0;
}

void begininsert() {
    struct nodo *puntero;
    int item;
    puntero = (struct nodo *)malloc(sizeof(struct nodo *));
    if (puntero == NULL) {
        cout << "\nOVERFLOW";
    } 

    cout << "\nIngrese valor\n";
    cin >> item;
    puntero->data = item;
    if(head == NULL)
    {
        head = puntero;
        tail = puntero;
        puntero->siguiente = head;
        puntero->anterior = tail;
    } else {
        puntero->siguiente = head;
        puntero->anterior = tail;
        head->anterior = puntero;
        head = puntero;
        tail->siguiente = head;
    }
    cout << "\nNodo insertado";
}

void lastinsert() {
    struct nodo *puntero, *temp;
    int item;
    puntero = (struct nodo *)malloc(sizeof(struct nodo));
    if (puntero == NULL) {
        cout << "\nOVERFLOW";
    } 

    cout << "\nIngrese valor?\n";
    cin >> item;
    puntero->data = item;
    if (head == NULL) {
        head = puntero;
        tail = puntero;
        puntero->siguiente = head;
        puntero->anterior = tail;
    } else {
        puntero->siguiente = head;
        puntero->anterior = tail;
        head->anterior = puntero;
        tail->siguiente = puntero;
        tail = puntero;
    }
    cout << "\nNodo insertado";
}

void randominsert() {
    int i, loc, item;
    struct nodo *puntero, *temp;
    puntero = (struct nodo *)malloc(sizeof(struct nodo));
    if (puntero == NULL) {
        cout << "\nOVERFLOW";
        return;
    } 
    if(head == NULL){
        begininsert();
        return;
    }
    
    cout << "\nIntroduzca el valor del elemento";
    cin >> item;
    puntero->data = item;
    cout << "\nIntroduce la ubicación después de la cual deseas insertar ";
    cin >> loc;
    temp = head;
    for (i = 0; i < loc; i++) {

        if (temp == head && i <loc-1) {
            cout << "\nNo se puede insertar\n";
            return;
        }
        temp = temp->siguiente;
    }
    puntero->siguiente = temp->siguiente;
    puntero->anterior = temp;
    temp->siguiente->anterior = puntero;
    temp->siguiente = puntero;
    if(temp == tail){
        tail = puntero;
    }
    cout << "\nNodo insertado";
    
}

void begin_delete() {
    struct nodo *puntero;
    if (head == NULL) {
        cout << "\nLa lista está vacía\n";
    }else if(head == tail){
        delete head;
        head = NULL;
        tail = NULL;
        cout << "\nSolo se eliminó un nodo de la lista ...\n";

    } else {
        puntero = head;
        head = puntero->siguiente;
        if(head != NULL){
        head->anterior = tail;
        tail->siguiente = head;
        }
        delete puntero;
        cout << "\nNodo eliminado desde el principio ...\n";
    }
}

void last_delete() {
    struct nodo *puntero, *ptr1;
    if (head == NULL) {
        cout << "\nLa lista está vacía";
    } else if (head->siguiente == tail) {
        puntero = head;
        head = NULL;
        tail = NULL;
        delete puntero;
        cout << "\nSolo se eliminó un nodo de la lista ...\n";
    } else {
        puntero = tail;
        tail = puntero->anterior;
        tail->siguiente = head;
        head->anterior = tail;
        delete puntero;
        cout << "\nNodo eliminado del último ...\n";
    }
}

void random_delete() {
    struct nodo *puntero, *ptr1;
    int loc, i;
    cout << "\nIntroduzca la ubicación del nodo después del cual desea realizar la eliminación.\n";
    cin >> loc;
    puntero = head;

    if(loc ==0 ){
        begin_delete();
        return;
    }

    for (i = 0; i < loc; i++) {
        
        if (puntero == NULL) {
        cout << "\nNo se puede eliminar (lista vacía o loc inválida)";
        return;
        }

        if (puntero == head && i > 0) {
            cout << "\nNo se puede eliminar";
            return;
        }

        ptr1 = puntero;
        puntero = puntero->siguiente;
    }
    ptr1->siguiente = puntero->siguiente;
    puntero->siguiente->anterior = ptr1;
    if(puntero->siguiente == head){
        tail= ptr1;
    }
    delete puntero;
    cout << "\nNodo eliminado " << loc ;
}

void search() {
    struct nodo *puntero;
    int item, i = 0;
    int flag;
    puntero = head;
    if (puntero == NULL) {
        cout << "\nLista vacía\n";
    } else {
        cout << "\nIntroduce el elemento que deseas buscar?\n";
        cin >> item;
        do{
            if (puntero->data == item) {
                cout << "Elemento encontrado en la ubicación " << i + 1;
                flag = 0;
                return;
            } else {
                flag = 1;
            }
            i++;
            puntero = puntero->siguiente;
        }while (puntero != head);
        if (flag == 1) {
            cout << "Elemento no encontrado\n";
        }
    }
}

void display() {
    struct nodo *puntero;
    puntero = head;
    if (puntero == NULL) {
        cout << "Nada que imprimir";
    } else {
        cout << "\nimprimiendo valores . . . .\n";
        do{
            cout << "\n" << puntero->data;
            puntero = puntero->siguiente;
        }while (puntero != head);
    }
}