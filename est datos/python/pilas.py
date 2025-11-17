class Pila:
    def __init__(self):
        self.MAX = 100
        # Pre-asignamos la lista para simular el arreglo de C++
        self.stack = [0] * self.MAX 
        self.top = -1

    def push(self, item):
        if self.isfull():
            print("Stack Overflow")
            return
        self.top += 1
        self.stack[self.top] = item

    def pop(self):
        if self.isEmpty():
            print("Stack Underflow")
            return -1  # Coincidiendo con la lógica de C++
        
        # Guardamos el valor y luego decrementamos
        item = self.stack[self.top]
        self.top -= 1
        return item

    def peek(self):
        if self.isEmpty():
            print("Stack is empty")
            return -1  # Coincidiendo con la lógica de C++
        return self.stack[self.top]

    def isEmpty(self):
        return self.top == -1

    def isfull(self): # Mantenemos el nombre original
        return self.top == self.MAX - 1

# --- Main ---
if __name__ == "__main__":
    pila = Pila()
    pila.push(10)
    pila.push(20)
    pila.push(30)

    print(f"Elemento superior: {pila.peek()}")
    print(f"Extrae el elemento: {pila.pop()}")
    print(f"Elemento superior despues de pop: {pila.peek()}")