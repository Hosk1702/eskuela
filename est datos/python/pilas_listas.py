class Nodo:
    def __init__(self, data):
        self.data = data
        self.siguiente = None

class PilaConLista:
    
    def __init__(self):
        self.top = None

    def isEmpty(self):
        return self.top is None

    def push(self, item):
        puntero = Nodo(item)
        puntero.siguiente = self.top
        self.top = puntero

    def pop(self):
        if self.isEmpty():
            print("Stack Underflow")
            return -1

        puntero = self.top
        item = puntero.data
        self.top = self.top.siguiente
        return item

    def peek(self):
        if self.isEmpty():
            print("Stack is empty")
            return -1
        return self.top.data

if __name__ == "__main__":
    pila = PilaConLista()
    
    pila.push(10)
    pila.push(20)
    pila.push(30)

    print(f"Elemento superior: {pila.peek()}")
    print(f"Extrae el elemento: {pila.pop()}")
    print(f"Elemento superior despues de pop: {pila.peek()}")

    print(f"Extrae el elemento: {pila.pop()}")
    print(f"Extrae el elemento: {pila.pop()}")
    print(f"Extrae el elemento: {pila.pop()}")