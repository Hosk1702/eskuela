#include <iostream>
#include <cstdlib> 

using namespace std;


struct nodo {
    int data;
    struct nodo *siguiente;
};


struct nodo *top = NULL;


bool isEmpty(){
    return top == NULL;
}


void push(int item){
    
    struct nodo *puntero = new nodo();
    
    
    if (!puntero) {
        cout << "Stack Overflow (Heap memory full)\n";
        return;
    }

    
    puntero->data = item;
    puntero->siguiente = top; 
    
    
    top = puntero;
}


int pop(){
   
    if (isEmpty()) {
        cout << "Stack Underflow \n";
        return -1; 
    }

    
    struct nodo *puntero = top;
    
    int item = puntero->data;

    
    top = top->siguiente;


    delete puntero;

    return item;
}


int peek(){
   
    if (isEmpty()) {
        cout << "Stack is empty \n";
        return -1; 
    }

    return top->data;
}

int main(){
    push(10);
    push(20);
    push(30);

    cout << "Elemento superior: " << peek() << endl;
    cout << "Extrae el elemento: " << pop() << endl;
    cout << "Elemento superior despues de pop: " << peek() << endl;


    cout << "Extrae el elemento: " << pop() << endl;
    cout << "Extrae el elemento: " << pop() << endl;
    cout << "Extrae el elemento: " << pop() << endl; 

    return 0;
}