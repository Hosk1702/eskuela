#include <iostream>
#define MAX 100

using namespace std;

int stack[MAX];
int top = -1;

void push(int item){
    if(top == MAX -1){
        cout << "Stack Overflow \n";
        return;
    }

    stack[++top] = item;

}

int pop(){
    if(top == -1){
        cout << "Stack Underflow \n";
        return -1;
    }

    return stack[top--];
}

int peek(){
    if(top == -1){
        cout << "Stack is empty \n";
        return -1;
    }

    return stack[top];
}

bool isEmpty(){
    return top == -1;
}

bool isfull(){
    return top == MAX -1;
}

int main(){
    push(10);
    push(20);
    push(30);

    cout << "Elemento superior: " << peek() << endl;
    cout << "Extra el elemento: " << pop() << endl;
    cout << "Elemento superior despues de pop: " << peek() << endl;

    return 0;

}